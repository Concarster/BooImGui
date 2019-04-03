#include "Game.h"
#include "LayerList.h"

Game::Game()
{
    Init();
}

Game::~Game()
{
}

void Game::Init()
{
    InitSystem();
}

void Game::InitSystem()
{
    InitLogger();
    //PushLayer(new ImgLayer());
    //PushLayer(new KeyCodeLayer());
    PushLayer(new MathLayer());
    PushOverLay(new boo::ImGuiLayer());
}

void Game::InitLogger()
{
    BOO_ENGINE_INFO("Welcome To BooEr Engine!");
    BOO_ENGINE_WARN("Initializing BooEr Logger!");
    BOO_ENGINE_TRACE("BooEr Logger Initialized!");
    BOO_CLIENT_WARN("Initializing Client Logger!");
    BOO_CLIENT_TRACE("Client Logger Initialized!");
}

boo::Engine* boo::Generate()
{
    return new Game();
}

