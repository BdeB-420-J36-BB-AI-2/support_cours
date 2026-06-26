#pragma once

namespace BehaviourTree
{
    enum class NodeState
    {
        SUCCESS,
        FAILURE,
        RUNNING
    };

    class Node
    {
    public:
        virtual ~Node() = default;
        virtual NodeState tick(const BehaviourTree::BlackBoard& bb) = 0;

    protected:
        Node() = default;
    };
}
