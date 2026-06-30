#include "GameTest.h"

#include <raylib.h>

#include "BehaviourTree/Builders.h"
#include "BehaviourTree/Core/BehaviourTree.h"

#include "GameConfig.h"

namespace Game
{
    GameTest::GameTest() :
        _player(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2)
    {
        InitWindow(720, 480, "GameTest");
        SetTargetFPS(30);

        _tree = BehaviourTree::Builders::TestRunningNode();
        _loop = true;
    }

    GameTest::~GameTest()
    {
        delete _tree;
        _tree = nullptr;
        CloseWindow();
    }

    void GameTest::handleInput()
    {
       // Mouse
       if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
           _player.setPosition(GetMouseX(), GetMouseY());

       // Direction pressed
       auto directionPressed = IsKeyDown(KEY_LEFT)
           || IsKeyDown(KEY_RIGHT)
           || IsKeyDown(KEY_DOWN)
           || IsKeyDown(KEY_UP)
           || IsKeyDown(KEY_SPACE);

       if (directionPressed)
           _player.setDirection(
               IsKeyDown(KEY_LEFT),
               IsKeyDown(KEY_RIGHT),
               IsKeyDown(KEY_DOWN),
               (IsKeyDown(KEY_UP) || IsKeyDown(KEY_SPACE))
           );
       else
           _player.resetDirection();

       int key = GetKeyPressed();
       switch (key)
       {
       case KEY_ESCAPE:
           _loop = false;
           break;
       }
    }

    void GameTest::update()
    {
        if (!_tree->isComplete())
            _tree->tick();

        // Physics
        _player.update();
    }

    void GameTest::render()
    {
        BeginDrawing();
        {
            ClearBackground(BLANK);
            _player.render();
            DrawFPS(20, 20);
        }
        EndDrawing();
    }
}
