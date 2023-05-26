#include "../include/Game.h"

Game::Game(std::string path)
{
	player = new Player(3, 5);
	maps = new Map[rooms];
	if (!(MapLoader::GetInstance()->LoadMaps(maps, path, player)))
	{
		std::cout << "Error moading maps";
		running = false;
	}
	else
		std::cout << "Map loading was successful";
	currentMap = CLASS;
	running = true;
    playSelected = true;
}

Game::~Game()
{
	delete[] maps;
	delete player;
}

void Game::Start()
{
	currentMap = CLASS;
    currentState = GameState::SplashScreen;
}

void Game::Update()
{
        switch (currentState) {

            //////SPLASHSCREEN//////
            case GameState::SplashScreen:
                break;

            //////MAINMENU//////
            case GameState::MainMenu:
              
                if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState(VK_DOWN))
                {
                    playSelected = !playSelected;
                }
                
                if (GetAsyncKeyState(VK_SPACE))
                {
                    if (playSelected)
                        currentState = GameState::Game;
                    else
                        exit(3);
                }

                break;

            //////GAME//////
            case GameState::Game:
                player->Update();
                currentMap = maps[currentMap].Update();



                currentState = GameState::GameOver;
                break;

            //////GAMEOVER//////
            case GameState::GameOver:
                break;

        }
}

void Game::Draw()
{
    system("CLS");

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
                if (playSelected) {
                    std::cout << "-> Play\n";
                    std::cout << "   Exit\n";

                }

                else {
                    std::cout << "   Play\n";
                    std::cout << "-> Exit\n";
                }
                
              break;

            //////GAME//////
             case GameState::Game:

                maps[currentMap].Draw();
                player->Draw();
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

Player* Game::GetPlayer()
{
	return player;
}
