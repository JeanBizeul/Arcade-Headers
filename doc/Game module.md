# Game Module
The interface with all the functions to implement to develop your game

```Cpp

std::unique_ptr<IGameModule> getGameModule(void);

class IGameModule {
    public:
        virtual void start(void) = 0;
        virtual void end(void) = 0;
        virtual void update(float deltaTime) = 0;
        virtual Window getWindow(void) = 0;
        virtual std::vector<IDrawable> getDrawables(void) = 0;
        virtual std::vector<Sound> getSounds(void) = 0;
        virtual void event(const Event &) = 0;
}
```
#### `std::unique_ptr<IGameModule> getGameModule(void)`
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

## Positions format
Pour toutes les images il faut utiliser le format "GUI" donc 1280x720 par exemple
Vos IDisplay doivent donc gérer le formattage de ces donnés pour les transformer en versions "CLI"