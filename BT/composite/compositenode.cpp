#include "compositenode.h"
namespace BT {

CompositeNode::~CompositeNode() {
    for(Node* child : this->children) {
        delete child;
    }
}

void CompositeNode::addChild(Node *child){
    this->children.push_back(child);
}

} // namespace BT
