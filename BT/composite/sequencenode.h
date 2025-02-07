#ifndef SEQUENCENODE_H
#define SEQUENCENODE_H

#include "compositenode.h"

namespace BT {

class SequenceNode : public CompositeNode
{
public:
    virtual TickReturn tick(Blackboard& blackboard) override;
};

} // namespace BT

#endif // SEQUENCENODE_H
