# Game Module
The interface with all the functions to implement to develop your game

```Cpp
class IGameModule {
    public:
        void End() = 0;
        void Update(float deltaTime) = 0;
        WindowClass GetWindow() = 0;
        std::vector<IDrawable> GetIDrawables() = 0;
        std::vector<SoundClass> GetSounds() = 0;
        void Event(EventClass event) = 0;
}
```
#### `void End()`
This function is called when the game is closed
#### `bool Update(float deltaTime)`
This function is called once per frame, deltaTime contains the time since the last update.
This function has a return value:
- **false**: no closing events
- **true**: closes the game
#### `WindowClass GetWindow()`
This function is called to create the window and allows the core to retrieve a [WindowClass](<Data structures.md>) to create the window according to the parameters.
- It must therefore return the WindowClass
#### `std::vector<IDrawable> GetIDrawables()`
This function is called every frame and retrieves all [IDrawables](<Data structures.md>) in the set to be displayed.
They will be displayed in vector order (the first in the list will be displayed 1st)
#### `std::vector<SoundClass> GetSounds()`
This function is called every frame and retrieves all [SoundClass](<Data structures.md>) from the game to play / stop / ...
- Depending on parameters, it will stop existing sounds, play new sounds etc.
#### `bool Event(EventClass event)`
Called each time an event is received, with a parameter [EventClass](<Data structures.md>) containing information on the event received and the data.

This function has a return value:
- **false**: no closing events
- **true**: closes the game

## Positions format
Pour toutes les images il faut utiliser le format "GUI" donc 1280x720 par exemple
Vos IDisplay doivent donc gérer le formattage de ces donnés pour les transformer en versions "CLI"