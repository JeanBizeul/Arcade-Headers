# Display module
The interface with all the functions to implement to develop your game

> The Window will be store localy in the displayModule

```Cpp
class IGameModule {
    public:
        void draw(IDrawable) = 0;
        void display() = 0;
        void clear() = 0;
        EventClass getEvent() = 0;
        void handleSound(SoundClass) = 0;
}
```
#### `void draw(IDrawable)`
Displays element on window according to [IDrawable] parameters (<Data structures.md>)
#### `void display()`
Display window with all elements in it
#### `void clear()`
Clear the window to prepare for the new display
#### `EventClass getEvent()`
Returns the next event in the correct format from [EventClass](<Data structures.md>) and **null** if none
#### `void handleSound(SoundClass)`
Play / stop / or loop the sound in parameter
> The list of sounds will be stored locally in the display so that you can retrieve the current ones.