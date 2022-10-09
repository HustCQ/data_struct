//
// Created by chenqiang on 2022/10/9.
//
#include "list.h"
#include <iostream>

template<class T>
List<T>::List() {
    head = tail = new Node<T>();
    len= 0;
}

template<class T>
List<T>::~List() {
    while (head->next != nullptr) {
        Node<T> *p = head->next;
        head->next = p->next;
        delete p;
    }
    delete head;
}

template<class T>
Node<T> *List<T>::first() {
    return head->next == nullptr ? nullptr : head->next;
}

template<class T>
Node<T> *List<T>::last() {
    return tail == head ? nullptr : tail;
}

template<class T>
int List<T>::size() const {
    return len;
}

template<class T>
bool List<T>::empty() const {
    return head->next == nullptr;
}

template<class T>
bool List<T>::isFirst(Node<T> *p) const {
    return p != nullptr && head->next == p;
}

template<class T>
bool List<T>::isLast(Node<T> *p) const {
    return p != nullptr && p == head->next;
}

template<class T>
Node<T> *List<T>::find(const T &val) const {
    Node<T> *p = head->next;
    while (p != nullptr && p->val != val) p = p->next;
    return p;
}

template<class T>
bool List<T>::find(Node<T> *p) const {
    Node<T> *q = head->next;
    while (q != p) q = q->next;
    return q != nullptr;
}

template<class T>
void List<T>::insert(Node<T> *prev, Node<T> *elem) {
    if (elem == nullptr) return;
    elem->next = prev->next;
    prev->next = elem;
    ++len;
}

template<class T>
void List<T>::insertHead(const T &val) {
    Node<T> *p = new Node<T>(val);
    p->next = head->next;
    head->next = p;
    if (head == tail) tail = p;
    ++len;
}

template<class T>
void List<T>::insertTail(const T &val) {
    Node<T> *p = new Node<T>(val);
    p->next = tail->next;
    tail->next = p;
    tail = p;
    ++len;
}

template<class T>
void List<T>::del(Node<T> *p) {
    if (p == nullptr) return;
    if (p == head->next) delHead();
    if (p == tail) delTail();

    Node<T> *q = findPrevious(p);
    q->next = p->next;
    delete p;

    --len;
}

template<class T>
void List<T>::delHead() {
    if (head->next == nullptr) return;
    Node<T> *p = head->next;
    head->next = p->next;
    delete p;

    --len;
}

template<class T>
void List<T>::delTail() {
    if (head->next == nullptr) return;

    Node<T> *p = findPrevious(tail);
    p->next = tail->next;
    delete tail;
    tail = p;

    --len;
}

template<class T>
Node<T>* List<T>::findPrevious(Node<T> *p) const {
    Node<T> *q = head;
    while (q != nullptr && q->next != p) q = q->next;
    return q;
}

template<class T>
void List<T>::print() const {
    Node<T> *p = head->next;
    while (p) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
}
