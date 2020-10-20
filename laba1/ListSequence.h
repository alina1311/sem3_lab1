#pragma once

#include "Sequence.h"
#include "LinkedList.h"

template<class T>
class ListSequence : public Sequence<T>
{
public:

    ListSequence()
    {
        list = new LinkedList<T>();
    }

    ListSequence(const ListSequence& sequence)
    {
        list = new LinkedList<T>(*sequence.list);
    }

    ListSequence(T* items, int count)
    {
        list = new LinkedList<T>(items, count);
    }

    virtual ~ListSequence()
    {
        delete list;
    }

public:

    virtual T getFirst() override
    {
        return list->getFirst();
    }

    virtual T getLast() override
    {
        return list->getLast();
    }

    virtual T get(int index) override
    {
        return list->get(index);
    }

    virtual int getLength() override
    {
        return list->getLength();
    }

    virtual Sequence<T>* getSubsequence(int startIndex, int endIndex) override
    {
        LinkedList<T>* subList = list->getSubList(startIndex, endIndex);

        Sequence<T>* newSequence = new ListSequence<T>();
        for (int i = 0; i < subList->getLength(); i++)
        {
            newSequence->prepend(subList->get(i));
        }

        return newSequence;
    }
    ////////////////////
    virtual void set(const T& item, int index) override 
    {
        this->list->set(item, index);
    }
    ////////////////////
    virtual void append(T value) override
    {
        list->append(value);
    }

    virtual void prepend(T value) override
    {
        list->prepend(value);
    }

    virtual void insertAt(T value, int index) override
    {
        list->insertAt(value, index);
    }

    virtual Sequence<T>* concat(Sequence<T>* sequence) override
    {
        Sequence<T>* newSequence = new ListSequence<T>();

        for (int i = 0; i < getLength(); i++)
        {
            newSequence->prepend(get(i));
        }

        for (int k = 0; k < sequence->getLength(); k++)
        {
            newSequence->prepend(sequence->get(k));
        }

        return newSequence;
    }

private:

    LinkedList<T>* list;
};
