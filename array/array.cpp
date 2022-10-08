//
// Created by chenqiang on 2022/10/8.
//
#include "array.h"
#include <stdio.h>
#include <assert.h>

template<class T>
Array<T>::Array() {
    elements = new T[DEFAULT_CAPACITY];
    size = 0;
    capacity = DEFAULT_CAPACITY;
}

template<class T>
Array<T>::Array(int capacity) {
    elements = new T[capacity];
    size = 0;
    this->capacity = capacity;
}

template<class T>
Array<T>::Array(int size, int capacity, const T &val) {
    assert(capacity < size);
    elements = new T[capacity];
    size = 0;
    capacity = capacity;

    for (int i = 0; i < size; ++i) {
        elements[i] = val;
    }
}

template<class T>
Array<T>::~Array() {
    delete [] elements;
    size = capacity = 0;
}

template<class T>
void Array<T>::add(int i, const T &val) {
    assert(i >= 0);

    bool flag = false;

    // 扩容：1、元素满 2、索引大于容量
    while (i > capacity || size == capacity) {
        capacity <<= 1;
        flag = true;
    }

    if (flag) {
        scale(capacity);
    }

    for (int j = size-1; j>= i; --j) {
        elements[j+1] = elements[j];
    }

    elements[i] = val;
    ++size;
}

template<class T>
void Array<T>::scale(int newCapacity) {
    T *tmp = new T[capacity];
    memcpy(tmp, elements, sizeof(T) * size);

    delete [] elements;
    elements = tmp;
}

template<class T>
void Array<T>::del(int i) {
    assert(i >= 0 && i < size);

    for (int j = i; j < size-1; j++) {
        elements[j] = elements[j+1];
    }
    --size;
}

template<class T>
void Array<T>::set(int i, const T &val) {
    assert(i >= 0);

    bool flag = false;

    // 扩容：1、元素满 2、索引大于容量
    while (i > capacity || size == capacity) {
        capacity <<= 1;
        flag = true;
    }

    if (flag) {
        scale(capacity);
    }

    elements[i] = val;
}

template<class T>
int Array<T>::find(const T &val) {
    for (int i = 0; i < size; ++i) if (elements[i] == val) return i;
    return -1;
}

template<class T>
const T &Array<T>::get(int i) {
    assert(i >= 0 && i < capacity);
    return elements[i];
}

template<class T>
int Array<T>::getLen() {
    return size;
}

template<class T>
int Array<T>::getCapacity() {
    return capacity;
}