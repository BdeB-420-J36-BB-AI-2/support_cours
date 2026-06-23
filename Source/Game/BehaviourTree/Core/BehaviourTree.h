#pragma once
#include "Node.h"

namespace BehaviourTree
{
    class BehaviourTree
    {
    private:
        Node* _rootNode = nullptr;

    public:
        BehaviourTree() = default;
        ~BehaviourTree() = default;

        NodeState tick() const
        {
            if (_rootNode)
                return _rootNode->tick();
            return NodeState::FAILURE;
        }
    };
}