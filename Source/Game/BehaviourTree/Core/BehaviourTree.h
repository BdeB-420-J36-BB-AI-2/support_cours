#pragma once

#include "BlackBoard.h"
#include "Node.h"

#include "../Composites.h"
#include "../DummyLeaves.h"

namespace BehaviourTree
{
    class BehaviourTree
    {
    private:
        Node* _rootNode = nullptr;
        bool _complete = false;

        BehaviorTree::BlackBoard _blackboard;

    public:
        BehaviourTree()
        {
            //TestSequence();
            //TestSelector();
            TestComposites();
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
                return _rootNode->tick(_blackboard);
            return NodeState::FAILURE;
        }

        bool isComplete()
        {
            return _complete;
        };

    private:
        // Testing case for the tree, can be replaced with a more complex tree structure
        void TestSequence()
        {
            auto sn = new Sequence();
            sn->add(new DummySuccess());
            sn->add(new DummyFail());
            sn->add(new DummySuccess());

            _rootNode = sn;
        }

        void TestSelector()
        {
            auto sn = new Selector();
            sn->add(new DummySuccess());
            sn->add(new DummyFail());
            sn->add(new DummyFail());

            _rootNode = sn;
        }

        void TestComposites()
        {
            auto sln = new Selector();
            auto sqn = new Sequence();

            sqn->add(new DummySuccess());
            sqn->add(sln);
            sqn->add(new DummySuccess());

            sln->add(new DummyFail());
            sln->add(new DummyFail());
            sln->add(new DummyFail());

            _rootNode = sqn;
        }
    };
}
