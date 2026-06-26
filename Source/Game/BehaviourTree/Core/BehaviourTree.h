#pragma once

#include "BlackBoard.h"
#include "Node.h"

namespace BehaviourTree
{
    class BehaviourTree
    {
    private:
        Node* _rootNode = nullptr;
        bool _complete = false;

        BlackBoard _blackboard;

    public:
        BehaviourTree() = default;

        ~BehaviourTree()
        {
            delete _rootNode;
            _rootNode = nullptr;
        }

        void setRootNode(Node* rootNode)
        {
            _rootNode = rootNode;
        }

        NodeState tick()
        {
            _complete = true;
            if (_rootNode)
                return _rootNode->tick(_blackboard);
            return NodeState::FAILURE;
        }

        bool isComplete() const
        {
            return _complete;
        };

    };
}
