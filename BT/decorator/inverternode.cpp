#include "inverternode.h"

namespace BT {

TickReturn InverterNode::tick(Blackboard& blackboard) {
    TickReturn childTick = this->child->tick(blackboard);
    if(childTick == TickReturn::FAILURE)
        return TickReturn::SUCCESS;
    if(childTick == TickReturn::SUCCESS)
        return TickReturn::FAILURE;
    return childTick;
}

} // namespace BT
