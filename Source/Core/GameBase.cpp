#include "GameBase.h"

namespace Core
{
    GameBase::GameBase() = default;

    GameBase::~GameBase() = default;

    void GameBase::run()
    {
        while (_loop)
        {
            handleInput();
            update();
            render();
        }
    }
}
