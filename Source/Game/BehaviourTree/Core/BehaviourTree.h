#pragma once

#include "Node.h"
#include <../Source/Core/Globals.h>

#include "../Composites.h"
#include "../DummyLeaves.h"

namespace BehaviourTree
{
    class BehaviourTree
    {
    private:
        Node* _rootNode = nullptr;
        bool _complete = false;

    public:
        BehaviourTree()
        {
            TestTree();
        };

        ~BehaviourTree()
        {
            delete _rootNode;
            _rootNode = nullptr;
        }

        NodeState tick()
        {
            _complete = true;
            if (_rootNode)
                return _rootNode->tick();
            return NodeState::FAILURE;
        }

        bool isComplete()
        {
            return _complete;
        };

    private:
        // Testing case for the tree, can be replaced with a more complex tree structure
        void TestTree()
        {
            auto sn = new Sequence();
            sn->add(new DummySuccess());
            sn->add(new DummySuccess());
            sn->add(new DummySuccess());

            _rootNode = sn;
        }
    };
}
