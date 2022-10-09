//
// Created by chenqiang on 2022/10/9.
//

#ifndef DATA_STRUCT_LIST_H
#define DATA_STRUCT_LIST_H
#include "node.h"

template<class T>
class List {
private:
    Node<T> *head;
    Node<T> *tail;
    int len;

public:
    List();
    ~List();
    Node<T>* first();
    Node<T>* last();
    int size() const;
    bool empty() const;
    bool isFirst(Node<T>*) const;
    bool isLast(Node<T>*) const;
    Node<T> *find(const T&) const;
    bool find(Node<T> *) const;
    void insert(Node<T> *, Node<T> *);
    void insertHead(const T &);
    void insertTail(const T &);
    void del(Node<T> *);
    void delHead();
    void delTail();
    Node<T>* findPrevious(Node<T> *) const;
    void print() const;
};

#endif //DATA_STRUCT_LIST_H
