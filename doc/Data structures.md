# Data Structures
All of the constructors listed in this files are used to build data container classes.
These classes are used to transfer data/requests between the game and display modules.
# Sound
Action to take on a sound.
```Cpp
Sound::Sound(
	std::String filePath,
	Sound::State state,
	std::String id,
	bool unique = true
);
```
#### `std::string filePath`
Path to the sound file.
Sound file format support may vary between each [Display module](<Display Module.md>) but `.wav` is always supported.
#### `Sound::State state`
State to put the sound in.
```Cpp
enum Sound::State {
	PLAY,
	STOP,
	LOOP
};
```
**PLAY** plays the sound to his end or until **STOP**.
**LOOP** plays the sound indefinitely until **STOP**.
**STOP** stops the sound with the given id.
#### `std::String id`
This id is used to select the sound instance to control.

> [!NOTE] Example
> ```cpp
> Sound("rickroll.wav", Sound::START, "funny"); // Starts playing
> Sound("rickroll.wav", Sound::STOP, "bunny");  // Nothing happens
> Sound("rickroll.wav", Sound::STOP, "funny");  // Stop playing
> ```
>
> >[!INFO] If a sound with the id "bunny" is already playing, it will stop.
#### `bool unique`
An **unique sound** with a specific id **will only be played once a time**, if you chain two START, it will play the sound only once.
A **non-unique sound** with a specific id **may be played multiple time in the same time**, STOP will stop all instances of a specific sound.
> [!WARNING] A non-unique sound that starts repeatedly can cause audio interference.

# Event

Management of in-game events (keystrokes, mouse presses, etc.)
```Cpp
Event::Event(
	enum Key::KeyCode key;
	any value;
);

enum KeyStatus {
	KEY_PRESSED,
	KEY_RELEASED
};

struct MousePos {
	int x;
	int y;
};
```
#### `enum Key key`
Represents the event received, e.g. KEY_B for pressing the B key, MOUSE_1 for the left click, etc.
#### `any value`
Represents the additional value received by the key, such as the scroll value of the scroll wheel, the position of the mouse in the event of movement, etc.
#### Values
- NONE
- KEY_A, KEY_ESC, KEY_UP, ...
	- **Value** : `Key_Statue`
- MOUSE_RIGTH, MOUSE_MIDDLE, MOUSE_4 ...
	- **Value** : `std::pair<MousePos, KeyStatue>`
- MOUSE_MOVE ...
	- **Value** : `MousePos`
- MOUSE_WHEEL
	- **Value** : `std::pair<MousePos, float delta>`

#### `enum KeyStatue`
- **KEY_PRESSED** : the key is pressed
- **KEY_RELEASED** : the key was pressed and is not anymore
#### `struct MousePos`
- **x, y** : position of the mouse on the screen
# Window
All the data for handling the window
```Cpp
WindowClass::WindowClass(
	std::pair<int, int> size,
	std::string title,
	std::string iconPath
);
```
#### `std::pair<int, int> size`
Represent the x and y size of the window for the display
#### `std::string title`
Represents the window title string
#### `std::string iconPath`
Represents the image path for the window icon

# IDrawable
The interface of all drawable content (image & text)

```Cpp
enum CLI_Color {
	CLI_BLACK,
	CLI_RED,
	CLI_GREEN,
	CLI_YELLOW,
	CLI_BLUE,
	CLI_MAGENTA,
	CLI_CYAN,
	CLI_WHITE
};

IDrawable::IDrawable(
	std::pair<float, float> scale,
	float rotation,
	std::pair<CLI_Color, CLI_Color> CLI_color,
	std::tuple<int, int, int, int> GUI_color,
	std::pair<int, int> position
);
class IDrawable{
	//std::pair<float, float> scale,
	//float rotation,
	//std::pair<CLI_Color, CLI_Color> CLI_color,
	//std::tuple<int, int, int, int> GUI_color,
	//std::pair<int, int> position
public:
    virtual std::pair<float, float> getScale(void) const = 0;
    virtual float getRotation(void) const = 0;
    virtual std::pair<CLI_Color, CLI_Color> getCLI_Color(void) const = 0;
    virtual std::tuple<int, int, int, int> getGUI_Color(void) const = 0;
    virtual std::pair<int, int> getPosition(void) const = 0;
    virtual void setScale(std::pair<float, float> scale) = 0;
    virtual void setRotation(float rotation) = 0;
    virtual void setCLI_Color(std::pair<CLI_Color, CLI_Color> CLI_Color) = 0;
    virtual void setGUI_Color(std::tuple<int, int, int, int> GUI_Color) = 0;
    virtual void setPosition(std::pair<int, int> position) = 0;
}
```
#### `std::pair<float, float> scale`
For GUI displayers, handle the scale X and Y of the content
- `<2,2>` for multiply by 2 the image size
#### `float rotation`
For GUI displayers, handle the rotation of the content
- `180` for a half-turn
#### `std::pair<CLI_Color, CLI_Color> CLI_color`
For CLI, handle the colors of the text & background from the enum CLI_Color
- The first value is for the character color
- The second value is for the background color

#### `std::tuple<int, int, int, int> GUI_color`
For GUI, handle colors in a rgba format, value between 0 and 255
- 1st value : Red
- 2nd value : Green
- 3rd value : Blue
- 4th value : Alpha

#### `std::pair<int, int> position`
Handle the position of the IDrawable in the screen for the displays

## Sprite : IDrawable
Sprite is heriting from IDrawable so benefit of all his data

```Cpp
class Sprite : public IDrawable {
	std::vector<std::string> getGUI_Textures(void) const;
    std::vector<char[2]> getCLI_Textures(void) const;
    float getAnimationTime(void) const;
	unsigned int getCurrentTexture(void) const;
    void setGUI_Textures(std::vector<std::string> GUI_Textures);
    void setCLI_Textures(std::vector<char[2]> CLI_Textures);
    void setAnimationTime(float animationTime);
	void setCurrentTexture(unsigned int currentTexture);

	// overrides de IDrawable	
}
//Variables
	//std::vector<std::string> GUI_Textures,
	//std::vector<char[2]>  CLI_Textures,
	//float animationTime,


```
#### `std::vector<std::string> GUI_Textures`
GUI_Textures is the list of all the path for the animations of the texture
- If only one texture is in the vector there will be no animation*

#### `std::vector<char[2]>  CLI_Textures`
CLI_Textures is the list of 2 charactere for the "texture" of the text format game
- Format will be like `"| "` for a wall
- If only one texture is in the vector there will be no animation

#### `float animationTime`
This will be the animation time variable, each animationTime the texture will change for the next one

## Text : IDrawable
TextClass is heriting from IDrawable so benefit of all his data

```Cpp
class Text : public IDrawable {
	std::string getFontPath(void) const;
    std::string getStr(void) const;
    void setFontPath(std::string fontPath);
    void setStr(std::string str);

	// overrides de IDrawable	
}

// Variables
	//std::string fontPath,
	//std::string str

```
#### `std::string fontPath`
For GUI, the file path to the font for the text

#### `std::string str`
The text to draw
