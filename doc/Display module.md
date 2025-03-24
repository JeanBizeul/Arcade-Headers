# Display module
The interface with all the functions to implement to develop your game

> The Window will be store localy in the displayModule

```Cpp
class IDisplayModule {
    public:
        void draw(IDrawable) = 0;
        void display() = 0;
        void clear() = 0;
        Event getEvent() = 0;
        void handleSound(Sound) = 0;
}
```
#### `void draw(IDrawable)`
Displays element on window according to [IDrawable](<Data structures.md>) parameters.

All element position are on the format GUI for CLI you will need to convert position.
#### `void display()`
Display window with all elements in it.
#### `void clear()`
Clear the window to prepare for the new display.
#### `EventClass getEvent()`
Returns the next event in the correct format from as an [Event Data Class](<Data structures.md>) and **null** if none.

All element position are on the format GUI for CLI you will need to convert position.
#### `void handleSound(SoundClass)`
Play / stop / or loop the sound in parameter.

All sounds must be managed and stored by and in the display module internally.