#include "conditionnode.h"

namespace BT {

ConditionNode::~ConditionNode() {
    delete &predicate;
}

TickReturn ConditionNode::tick(Blackboard& blackboard) {
    return predicate(blackboard) ? TickReturn::SUCCESS : TickReturn::FAILURE;
}

} // namespace BT
