# Game Module

The interface with all the functions to implement to develop your game

```Cpp
// Should not be in the header but as extern "C"
// std::unique_ptr<IGameModule> getGameModule(void);

class IGameModule {
    public:
        virtual ~IGameModule() = 0;
        virtual void update(float deltaTime) = 0;
        virtual Window getWindow(void) = 0;
        virtual std::vector<IDrawable> getDrawables(void) = 0;
        virtual std::vector<Sound> getSounds(void) = 0;
        virtual void event(const Event &) = 0;
        virtual std::vector<std::pair<std::string, int>> getScores(void) = 0;
}
```

### `~IGameModule()`
This a pure virtual destructor, it will be override by the current implementation, for proper destruction.
#### `extern "C" std::unique_ptr<IGameModule> getGameModule(void)`
This is the entry point which is going to be called from the core to retrieve the gameModule.
Return a std::unique_pointer to the current implementation of the gameModule.
#### `bool Update(float deltaTime)`
This function is called once per frame, deltaTime contains the time since the last update.
This function has a return value:
- **false**: no closing events.
- **true**: closes the game.
#### `WindowClass GetWindow()`
This function is called to create the window and allows the core to retrieve a [Window Data Class](<Data structures.md#Window>) to create the window according to the parameters.
It must therefore return the WindowClass.
#### `std::vector<IDrawable> GetDrawables()`
This function is called every frame and retrieves all [IDrawables Data Class](<Data structures.md#IDrawable>) in the set to be displayed.

They will be displayed in vector order. (the first in the list will be displayed 1st)
#### `std::vector<SoundClass> GetSounds()`
This function is called every frame and retrieves all [Sound Data Class](<Data structures.md#Sound>) from the game to play, stop or loop them.

Depending on parameters, it will stop already existing sounds, play new sounds etc.
#### `bool Event(EventC event)`
Called each time an event is received, with a parameter [Event Data Class](<Data structures.md#Event>) containing information on the event received and the data.

This function has a return value:
- **false**: no closing events
- **true**: closes the game

#### `void getScores(void)`
This function will get called before the core unloads the game module.

It must return a vector of all scores done in this session.

The format of the scores is the following:
```Cpp
std::pair<std::String, int> score({"Joe", 23350});
```

## Positions format
For all images, you must use the "GUI" format, such as 1280x720.
Your IDisplay must therefore handle formatting this data to transform it into "CLI" versions.