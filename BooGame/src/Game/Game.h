#pragma once
#include "Main.h"
#include "ForClient.h"

class Game : public boo::Engine
{
public:
    Game();
    ~Game();

    void Init();
    void InitSystem();
    void InitLogger();
};

