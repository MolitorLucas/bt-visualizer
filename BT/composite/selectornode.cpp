#include "selectornode.h"

namespace BT {

TickReturn SelectorNode::tick(Blackboard& blackboard) {
    for(Node* child : this->children) {
        TickReturn childTick = child->tick(blackboard);
        if(childTick != TickReturn::FAILURE){
            return childTick;
        }
    }
    return TickReturn::FAILURE;
}

} // namespace BT
