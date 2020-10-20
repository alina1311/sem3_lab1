#pragma once

#include <iostream>

template<class T>
class Sequence
{
protected:
    int size = 0;
public:

    virtual T getFirst() = 0;

    virtual T getLast() = 0;

    virtual T get(int index) = 0;

    virtual void set(const T& item, int index) = 0;

    virtual int getLength() = 0;

    virtual Sequence<T>* getSubsequence(int startIndex, int endIndex) = 0;

    virtual void append(T value) = 0;

    virtual void prepend(T value) = 0;

    virtual void insertAt(T value, int index) = 0;

    virtual Sequence<T>* concat(Sequence<T>* sequence) = 0;

public:

    virtual ~Sequence() = default;
};
