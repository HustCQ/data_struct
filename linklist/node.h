//
// Created by chenqiang on 2022/10/9.
//

#ifndef DATA_STRUCT_NODE_H
#define DATA_STRUCT_NODE_H

template<class T>
struct Node {
    T val;
    Node *next;
    Node() : next(nullptr) {}
    Node(const T &val) : val(val), next(nullptr) {};
};

#endif //DATA_STRUCT_NODE_H
