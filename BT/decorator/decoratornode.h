#ifndef DECORATORNODE_H
#define DECORATORNODE_H

#include "../node.h"

namespace BT {

class DecoratorNode : public Node
{
protected:
    Node* child;
public:
    explicit DecoratorNode(Node* child) : child(child) {}
    virtual ~DecoratorNode() override;
};

} // namespace BT

#endif // DECORATORNODE_H
