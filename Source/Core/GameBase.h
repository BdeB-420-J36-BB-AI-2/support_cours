#pragma once

namespace Core
{
    class GameBase
    {
    public:
        virtual ~GameBase();

        // TODO: 
        // starting point
        void run();
        // handle input
        virtual void handleInput() = 0;
        // update
        virtual void update() = 0;
        // render
        virtual void render() = 0;

    protected:
        GameBase();
        int _loop;
    };
}
