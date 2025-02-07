#ifndef SELECTORNODE_H
#define SELECTORNODE_H

#include "compositenode.h"

namespace BT {

class SelectorNode : public CompositeNode
{
public:
    virtual TickReturn tick() override;
};

} // namespace BT

#endif // SELECTORNODE_H
