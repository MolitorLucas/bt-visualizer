#include "decoratornode.h"

namespace BT {

DecoratorNode::~DecoratorNode() {
    delete this->child;
}

} // namespace BT
