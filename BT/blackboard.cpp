#include "blackboard.h"

namespace BT {
template <typename T>
void Blackboard::set(const std::string& key, const T& value) {
    data[key] = value;
}
template<typename T>
T* Blackboard::get(const std::string& key) {
    auto foundValue = data.find(key);
    if (foundValue != data.end()) {
        try {
            return std::any_cast<T>(&foundValue->second);
        }
        catch (const std::bad_any_cast&) {
            return nullptr;
        }
    }
    return nullptr;
}
}// namespace BT
