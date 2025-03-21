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
Sound file format support may vary between each [Display module](<Display Module>) but `.wav` is always supported.
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
EventClass::EventClass(
	enum Key key;
	any value;
);

enum KeyStatue {
	KEY_PRESSED,
	KEY_RELEASED
};

struct MousePos {
	int x,
	int y,
	bool isCLI
}
```
#### `enum Key key`
Represents the event received, e.g. KEY_B for pressing the B key, MOUSE_1 for the left click, etc.
#### `any value`
Represents the additional value received by the key, such as the scroll value of the scroll wheel, the position of the mouse in the event of movement, etc.
#### Valeurs
- NONE
- KEY_A, KEY_ESC, KEY_UP, ... 
	- **Valeur** : `Key_Statue`
- MOUSE_1, MOUSE_2, MOUSE_3 ...
	- **Valeur** : `std::pair<MousePos, KeyStatue>`
- MOUSE_MOVE ...
	- **Valeur** : `MousePos`
- MOUSE_WHEEL
	- **Valeur** : `std::pair<MousePos, float delta>`

#### `enum KeyStatue`
- **KEY_PRESSED** : the key is pressed
- **KEY_RELEASED** : the key was pressed and is not anymore
#### `struct MousePos`
- **x, y** : position of the mouse on the screen
- **isCLI** : allow to now in wich format of position handle the mouse event
	- **true** : the display is a CLI displayer
	- **false** : the display is a GUI displayer
# WindowClass
All the data for handling the window
```Cpp
WindowClass::WindowClass(
	std::pair<int, int> sizeGUI,
	std::pair<int, int> sizeCLI,
	std::string title,
	std::string pathIcon
);
```
#### `std::pair<int, int> sizeGUI`
Represent the x and y size of the window for the CLI display as *SFML* which will accept sizes like **1920x720**.
#### `std::pair<int, int> sizeCLI`
Represent the x and y size of the window for the CLI display as *ncurse* which will accept sizes like **20x20**.
#### `std::string title`
Represents the window title string
#### `std::string pathIcon`
Represents the image path for the window icon

# IDrawable
The interface of all drawable content (image & text)

```Cpp
enum CLI_Colors {
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
	std::pair<CLI_Colors, CLI_Colors> CLI_color,
	std::tuple<int, int, int, int> GUI_color,
	std::pair<int, int> positionGUI,
	std::pair<int, int> positionCLI,
);
```
#### `std::pair<float, float> scale`
For GUI displayers, handle the scale X and Y of the content
- `<2,2>` for multiply by 2 the image size
#### `float rotation`
For GUI displayers, handle the rotation of the content
- `180` for a half-turn
#### `std::pair<CLI_Colors, CLI_Colors> CLI_color`
For CLI, handle the colors of the text & background from the enum CLI_Colors
- The first value is for the character color
- The second value is for the background color

#### `std::tuple<int, int, int, int> GUI_color`
For GUI, handle colors in a rgba format, value between 0 and 255
- 1st value : Red
- 2nd value : Green
- 3rd value : Blue
- 4th value : Alpha

#### `std::pair<int, int> positionGUI`
Handle the position of the IDrawable in the screen for the **GUI** displays

#### `std::pair<int, int> positionCLI`
Handle the position of the IDrawable in the screen for the **CLI** displays

## SpriteClass : IDrawable
SpriteClass is heriting from IDrawable so benefit of all his data

```Cpp
class SpriteClass : public IDrawable;

SpriteClass::SpriteClass(
	std::vector<std::string> GUI_Textures,
	std::vector<char[2]>  CLI_Textures,
	float animationTime,
);
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

## TextClass : IDrawable
TextClass is heriting from IDrawable so benefit of all his data

```Cpp
class TextClass : public IDrawable;

TextClass::TextClass(
	std::string fontPath,
	std::string str
);
```
#### `std::string fontPath`
For GUI, the file path to the font for the text

#### `std::string str`
The text to draw
