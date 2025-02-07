#ifndef CONDITIONNODE_H
#define CONDITIONNODE_H

#include "node.h"

namespace BT {

class ConditionNode : public Node
{
public:
    using Predicate = std::function<bool(Blackboard&)>;
    explicit ConditionNode(Predicate predicate) : predicate(predicate) {}
    virtual TickReturn tick(Blackboard& blackboard) override;
    virtual ~ConditionNode() override;
private:
    Predicate predicate;
};

} // namespace BT

#endif // CONDITIONNODE_H
