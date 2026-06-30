#pragma once
#include "../../Core/Globals.h"
#include "Core/BlackBoard.h"
#include "Core/CompositeNode.h"

namespace BehaviourTree
{
    class Sequence : public CompositeNode
    {
    public:
        NodeState tick( BlackBoard& bb) override
        {
            Core::log("Sequence:");
            for (const auto node : _nodes)
            {
                NodeState state = node->tick(bb);
                if (state != NodeState::SUCCESS)
                    return state;
            }
            return NodeState::SUCCESS;
        }
    };

    class Selector : public CompositeNode
    {
    public:
        NodeState tick( BlackBoard& bb) override
        {
            Core::log("Selector:");
            for (auto node : _nodes)
            {
                NodeState state = node->tick(bb);
                if (state != NodeState::FAILURE)
                    return state;
            }
            return NodeState::FAILURE;
        }
    };
}

