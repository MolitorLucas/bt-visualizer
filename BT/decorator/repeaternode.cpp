#include "repeaternode.h"

namespace BT {

TickReturn RepeaterNode::tick(Blackboard& blackboard) {
    TickReturn childTick = this->child->tick(blackboard);
    for (int i = 1; childTick == TickReturn::SUCCESS || i >= this->repeatCounter;) {
        childTick = this->child->tick(blackboard);
        if (childTick != TickReturn::RUNNING) {
            i++;
        }
    }
    return childTick;
}

} // namespace BT
