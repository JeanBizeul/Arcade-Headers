# Display module
The interface with all the functions to implement to develop your game

> The Window will be store localy in the displayModule

```Cpp
class IDisplayModule {
    public:
	    virtual void createWindow(const Window &) = 0;
        virtual void draw(const IDrawable &) = 0;
        virtual void display(void) = 0;
        virtual void clear(void) = 0;
        virtual Event getEvent(void) = 0;
        virtual void handleSound(const Sound &) = 0;
}
```

#### `void createWindow(Window window)`

#### `void draw(IDrawable)`
Displays element on window according to [IDrawable Data Class](<Data structures.md#IDrawable>) parameters.

All element position are on the format GUI for CLI you will need to convert position.
#### `void display(void)`
Display window with all elements in it.
#### `void clear(void)`
Clear the window to prepare for the new display.
#### `EventClass getEvent(void)`
Returns the next event in the correct format from as an [Event Data Class](<Data structures.md#Event>) and **null** if none.

All element position are on the format GUI for CLI you will need to convert position.
#### `void handleSound(SoundClass)`
Play / stop / or loop the sound in parameter.

All sounds must be managed and stored by and in the display module internally.