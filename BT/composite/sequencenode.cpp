#include "sequencenode.h"

namespace BT {

TickReturn SequenceNode::tick(Blackboard& blackboard) {
    for(Node* child : children){
        TickReturn childTick = child->tick(blackboard);
        if(childTick != TickReturn::SUCCESS){
            return childTick;
        }
    }
    return TickReturn::SUCCESS;
}

} // namespace BT
