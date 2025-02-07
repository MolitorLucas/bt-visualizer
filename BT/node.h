#ifndef NODE_H
#define NODE_H
#include "blackboard.h"
#include "tickreturn.h"

namespace BT {

class Node
{
public:
    virtual TickReturn tick(Blackboard& blackboard) = 0;
    virtual ~Node() = default;
};

} // namespace BT

#endif // NODE_H
