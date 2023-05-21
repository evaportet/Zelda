#include "../include/Game.h"

Game::Game(std::string path)
{
	player = new Player(3, 4);
	loader = new MapLoader(path, rooms);
	maps = new Map[rooms];
	running = true;
}

Game::~Game()
{	delete[] maps;
	delete loader;
	delete player;
}

void Game::Start()
{
	if (!(loader->LoadMaps(maps))) {
		running = false;
		std::cout << "Error 404: file not found";
	}
	currentMap = CLASS;
	maps[currentMap].UpdatePlayer(player->getPos(), player->getPrevPos(), player->getDirection());
}

void Game::Update()
{
    currentState = GameState::SplashScreen;

        switch (currentState) {

            //////SPLASHSCREEN//////
            case GameState::SplashScreen:
                break;

            //////MAINMENU//////
            case GameState::MainMenu:
                int choice;
                std::cin >> choice;
           
                while (choice != 2){
                std::cin >> choice;

                    switch (choice) {
                    case 1:
                        currentState = GameState::Game;
                        break;

                    case 2:
                        std::cout << "Exiting the game...\n";
                        exit(2);
                        break;

                    default:
                        std::cout << "Invalid choice. Please try again.\n";
                        break;
                    }
                }
                break;

            //////GAME//////
            case GameState::Game:
                player->Update();
                currentMap = maps[currentMap].Update();
                maps[currentMap].UpdatePlayer(player->getPos(), player->getPrevPos(), player->getDirection());



                currentState = GameState::GameOver;
                break;

            //////GAMEOVER//////
            case GameState::GameOver:
                break;

        }
}

void Game::Draw()
{
    currentState = GameState::SplashScreen;

        switch (currentState) {

            //////SPLASHSCREEN//////
            case GameState::SplashScreen:

                //DRAW
                std::cout << "********************************************\n**** THE LEGEND OF ZELDA: CDI SUPREMACY ****\n********************************************" << std::endl;

                std::this_thread::sleep_for(std::chrono::seconds(3));
                currentState = GameState::MainMenu;
                break;

            //////MAINMENU//////
             case GameState::MainMenu:

                //DRAW
                std::cout << "***************** MAIN MENU ****************\n\n" << std::endl;
                std::cout << "1. Play\n";
                std::cout << "2. Exit\n";

                break;

            //////GAME//////
             case GameState::Game:


                player->Draw();
                maps[currentMap].Draw();
                currentState = GameState::GameOver;
                break;

            //////GAMEOVER//////
            case GameState::GameOver:
                std::cout << "********************************************\n***************** GAME OVER ****************\n********************************************" << std::endl;

                std::this_thread::sleep_for(std::chrono::seconds(5));
                exit(3);

                break;
        }
    }

void Game::FrameControl()
{
    Sleep(60);
}


