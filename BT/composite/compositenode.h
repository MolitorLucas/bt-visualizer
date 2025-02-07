#ifndef COMPOSITENODE_H
#define COMPOSITENODE_H

#include "../node.h"
#include <vector>

namespace BT {

class CompositeNode : Node
{
protected:
    std::vector<Node*> children;
public:
    virtual ~CompositeNode() override;
    void addChild(Node* child);
};

} // namespace BT

#endif // COMPOSITENODE_H
