# Arcade documentation
The Arcade project is a game engine which works with two different modules: one [Game module](<Game module.md>) and one [Display module](<Display module.md>).

Each of these modules may be swapped during runtime, when swapping a game module for another, the high scores are updated. Same when the program closes.
When switching display modules, the game must continue to run without pause, only the display method will change.

While the program is running, keys are reserved by it so you can't use them in your gameModules:
- KEY_1: Go to next [Display module](<Display module.md>).
- KEY_2: Go to next [Game module](<Game module.md>).
- KEY_3: Restart actual [Game module](<Game module.md>).
- TAB: Exit the actual game and go back to the menu.
- ECHAP: Exit the program.

You can find documentation for each module type here:
- [Game module](<Game module.md>)
- [Display module](<Display module.md>)

The exhaustive list of all data structures used to exchange data between modules and the core can be found [here](<Data structures.md>).