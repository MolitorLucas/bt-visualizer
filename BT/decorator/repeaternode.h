#ifndef REPEATERNODE_H
#define REPEATERNODE_H

#include "decoratornode.h"

namespace BT {

class RepeaterNode : public DecoratorNode
{
private:
    int repeatCounter;
public:
    explicit RepeaterNode(Node* child, const int& repeatCounter) :
        DecoratorNode(child), repeatCounter(repeatCounter) {}
    virtual tick(Blackboard& blackboard) override;
};

} // namespace BT

#endif // REPEATERNODE_H
