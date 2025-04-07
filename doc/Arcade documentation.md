# Arcade documentation
The Arcade project is a game engine which works with two different modules: one [Game module](<Game module.md>) and one [Display module](<Display module.md>).

Each of these modules may be swapped during runtime, when swapping a game module for another, the high scores are updated. Same when the program closes.
When switching display modules, the game must continue to run without pause, only the display method will change.

You can find documentation for each module type here:
- [Game module](<Game module.md>)
- [Display module](<Display module.md>)

The exhaustive list of all data structures used to exchange data between modules and the core can be found [here](<Data structures.md>).