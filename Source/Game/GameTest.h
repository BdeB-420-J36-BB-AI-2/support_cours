#pragma once
#include "../Core/GameBase.h"

namespace Core
{
    class GameTest : public GameBase
    {
    public:
        GameTest();
        ~GameTest() override;

        void handleInput() override;
        void update() override;
        void render() override;
    }; 
}
