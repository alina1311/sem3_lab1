#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>

template<class T>
class DynamicArray
{
public:

    DynamicArray()
    {
        data = nullptr;
        count = 0;
    }

    DynamicArray(int size)
    {
        data = new T[size];
        count = size;

        for (int i = 0; i < size; i++)
        {
            *(data + i) = T();
        }
    }

    DynamicArray(const DynamicArray<T>& array)
    {
        this->size = array->getLength();
        this->arr = new T[this->size];
        for (size_t i = 0; i < array->getLength(); i++)
        {
            this->set(array->get(i));
        }
    }

    DynamicArray(T* items, int size)
    {
        data = new T[size];
        count = size;

        for (int i = 0; i < size; i++)
        {
            *(data + i) = *(items + i);
        }
    }


    ~DynamicArray()
    {
        delete[] data;
    }

public:

    int getLength()
    {
        return count;
    }

    T get(int index)
    {
        if (index >= count)
        {
            throw std::out_of_range("index is out of range");
        }

        return *(data + index);
        
    }

    void set(T value, int index)
    {
        if (index >= count)
        {
            throw std::out_of_range("index is out of range");
        }

        *(data + index) = value;
    }

    void resize(int newSize)
    {
        T* temp = data;

        data = new T[newSize];

        for (int i = 0; i < std::min(count, newSize); i++)
        {
            *(data + i) = *(temp + i);
        }

        count = newSize;

        delete[] temp;
    }

private:
    T* data;

    int count;
};

