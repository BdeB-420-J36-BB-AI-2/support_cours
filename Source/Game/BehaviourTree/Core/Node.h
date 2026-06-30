#pragma once

namespace BehaviourTree
{
    class blackBoard;

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
        virtual NodeState tick(BlackBoard& bb) = 0;

    protected:
        Node() = default;
    };
}
