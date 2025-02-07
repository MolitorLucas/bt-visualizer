#ifndef BLACKBOARD_H
#define BLACKBOARD_H

#include<unordered_map>
#include<QString>
#include<memory>
#include<any>


namespace BT {
class Blackboard {
public:

    template <typename T>
    void set(const QString& key, const T& value);

    template<typename T>
    T* get(const QString& key);
private:
    std::unordered_map<QString, std::any> data;
};
}

#endif
