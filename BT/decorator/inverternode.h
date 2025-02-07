#ifndef INVERTERNODE_H
#define INVERTERNODE_H

#include "decoratornode.h"

namespace BT {

class InverterNode : public DecoratorNode
{
public:
    virtual TickReturn tick(Blackboard& blackboard) override;
};

} // namespace BT

#endif // INVERTERNODE_H
