#pragma once
#include "Node.h"

namespace BehaviourTree
{
    class LeafNode : public Node
    {
    public:
        virtual ~LeafNode() = default;
    protected:
        LeafNode() override = default;
    };
}