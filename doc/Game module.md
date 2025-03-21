# Game Module
The interface with all the functions to implement to develop your game

```Cpp
class IGameModule {
    public:
        void Start() = 0;
        void End() = 0;
        void Update(float deltaTime) = 0;
        WindowClass GetWindow() = 0;
        std::vector<IDrawable> GetIDrawables() = 0;
        std::vector<SoundClass> GetSounds() = 0;
        void Event(EventClass event) = 0;
}
```
#### `void Start()`
Cette fonction est appelé au début du lancement du jeu et de la fenetre 
Peut etre utilisé pour instancier tout les élements du jeux
#### `void End()`
Cette fonction est appelé à la fermeture du jeu
#### `bool Update(float deltaTime)`
Cette fonction est appelé une fois par image, deltaTime contient le temps depuis le derniere update
Cette fonction a une valeur de renvoie:
- **false** : rien ne se passe
- **true** : ferme le jeu (fin, défaite ... ?)
#### `WindowClass GetWindow()`
Cette fonction est appelé pour créer la fenetre et permet au core de récuperer une [WindowClass](<Data structures.md>) pour créer la fenetre selon les parametres
- Il doit donc renvoyer la WindowClass
#### `std::vector<IDrawable> GetIDrawables()`
Cette fonction est appelé chaque frame et récupère tout les [IDrawables](<Data structures.md>) du jeu a afficher
Ils seront affiché dans l'ordre du vector (le premier de la liste sera affiché en 1er)
#### `std::vector<SoundClass> GetSounds()`
Cette fonction est appelé chaque frame et récupère tout les [SoundClass](<Data structures.md>) du jeu à jouer / stopper / ...
- En fonction des parametres il stoppera les sons existant, jouera des nouveaux sons etc
#### `bool Event(EventClass event)`
Appelé à chaque evenement reçu avec en parametre un [EventClass](<Data structures.md>) qui contient les informations sur l'évenement recu et les données

Cette fonction a une valeur de renvoie:
- **false** : rien ne se passe
- **true** : ferme le jeu (fin, défaite ... ?)