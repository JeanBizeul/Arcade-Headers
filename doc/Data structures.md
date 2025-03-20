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
Sound file format support may very between each [Display module](<Display Module>) but `.wav` is always supported.
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