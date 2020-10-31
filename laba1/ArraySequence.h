#pragma once

#include "Sequence.h"
#include "DynamicArray.h"

template<class T>
class ArraySequence : public Sequence<T>
{
public:

    ArraySequence()
    {
        array = new DynamicArray<T>();
    }

    ArraySequence(const ArraySequence& sequence)
    {
        array = new DynamicArray<T>(sequence.array);
    }

    ArraySequence(int size) 
    {
        this->array = new DynamicArray<T>(size);
        this->size = size;
    }

    ArraySequence(T* items, int count)
    {
        array = new DynamicArray<T>(items, count);
    }

    virtual ~ArraySequence()
    {
        delete array;
    }

public:

    virtual T getFirst() override
    {
        return array->get(0);
    }

    virtual T getLast() override
    {
        return array->get(array->getLength() - 1);
    }

    virtual T get(int index) override
    {
        return array->get(index);
    }

    virtual void set(const T& item, int index) override 
    {
        this->array->set(item, index);
    }

    virtual int getLength() override
    {
        return array->getLength();
    }

    virtual ArraySequence<T>* getSubsequence(int startIndex, int endIndex) override
    {
        DynamicArray<T>* newArray = new DynamicArray<T>(endIndex - startIndex + 1);

        for (int i = startIndex; i <= endIndex; i++)
        {
            newArray->set(array->get(i), i - startIndex);
        }

        ArraySequence<T>* newSequence = new ArraySequence<T>();
        newSequence->array = newArray;

        return newSequence;
    }

    virtual void append(T value) override
    {
        DynamicArray<T>* newArray = new DynamicArray<T>(array->getLength() + 1);

        newArray->set(value, 0);

        for (int i = 0; i < array->getLength(); i++)
        {
            newArray->set(array->get(i), i + 1);
        }

        array = newArray;
    }

    virtual void prepend(T value) override
    {
        array->resize(array->getLength() + 1);

        array->set(value, array->getLength() - 1);
    }

    virtual void insertAt(T value, int index) override
    {
        DynamicArray<T>* newArray = new DynamicArray<T>(array->getLength() + 1);

        for (int i = 0; i < index; i++)
        {
            newArray->set(array->get(i), i);
        }

        newArray->set(value, index);

        for (int i = index + 1; i < newArray->getLength(); i++)
        {
            newArray->set(array->get(i - 1), i);
        }

        array = newArray;
    }


    virtual ArraySequence<T>* concat(Sequence<T>* sequence) override
    {
        DynamicArray<T>* newArray = new DynamicArray<T>(array->getLength() + sequence->getLength());

        for (int i = 0; i < array->getLength(); i++)
        {
            newArray->set(array->get(i), i);
        }

        for (int k = 0; k < sequence->getLength(); k++)
        {
            newArray->set(sequence->get(k), array->getLength() + k);
        }

        ArraySequence<T>* newSequence = new ArraySequence<T>();
        newSequence->array = newArray;

        return newSequence;
    }

private:
    DynamicArray<T>* array;
};
