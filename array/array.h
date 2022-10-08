//
// Created by chenqiang on 2022/10/8.
//

#ifndef DATA_STRUCT_ARRAY_H
#define DATA_STRUCT_ARRAY_H

template<class T>
class Array {
private:
    T *elements;
    int size;
    int capacity;

    void scale(int);

public:
    Array();
    Array(int);
    Array(int, int, const T&);
    ~Array();

    // 增
    void add(int, const T&);
    // 删
    void del(int);
    // 改
    void set(int, const T&);
    // 查询
    int find(const T&);
    // 索引操作
    const T& get(int);
    // 获取长度
    int getLen();
    // 获取容量
    int getCapacity();
};

static int DEFAULT_CAPACITY = 8;

#endif //DATA_STRUCT_ARRAY_H
