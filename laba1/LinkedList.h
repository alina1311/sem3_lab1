#pragma once

#include <iostream>

template <class T>
class LinkedList
{
public:

    LinkedList() : head(nullptr), tail(nullptr), count(0)
    {

    }

    ~LinkedList()
    {
        ListNode<T>* ptr = head;
        while (ptr != nullptr)
        {
            ListNode<T>* next = ptr->next;
            delete ptr;
            ptr = next;
        }
    }

    LinkedList(T* items, int count)
    {
        for (int i = 0; i < count; i++)
        {
            T value = *(items + i);

            prepend(value);
        }
    }

    LinkedList(int count)
    {
        for (int i = 0; i < count; i++)
        {
            T value = T();

            prepend(value);
        }
    }

    LinkedList(const LinkedList& list)
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->count = 0;

        ListNode<T>* ptr = list.head;
        while (ptr != nullptr)
        {
            prepend(ptr->data);
            ptr = ptr->next;
        }
    }

public:
    T getFirst()
    {
        if (count == 0)
        {
            throw std::out_of_range("list is empty");
        }

        return head->data;
    }

    T getLast()
    {
        if (count == 0)
        {
            throw std::out_of_range("list is empty");
        }

        return tail->data;
    }

    T get(int index)
    {
        if (index >= count)
        {
            throw std::out_of_range("index out of range");
        }

        ListNode<T>* ptr = head;
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->next;
        }

        return ptr->data;
    }

    void set(const T& item, int index) {
        if (index < 0 || index >= this->count)
        {
            std::cout << ("Index is out of range");
        }

        ListNode<T>* node = this->head;
        for (int i = 0; i < index; i++)
        {
            node = node->next;
        }
        node->data = item;
    }

    LinkedList<T>* getSubList(int startIndex, int endIndex)
    {
        if (startIndex >= count || endIndex >= count || startIndex > endIndex)
        {
            throw std::out_of_range("index out of range");
        }

        LinkedList<T>* newList = new LinkedList<T>();

        auto ptr = head;
        for (int i = 0; i < startIndex; i++)
        {
            ptr = ptr->next;
        }

        for (int i = startIndex; i <= endIndex; i++)
        {
            newList->prepend(ptr->data);

            ptr = ptr->next;
        }

        return newList;
    }

    int getLength()
    {
        return count;
    }

    void append(T value)
    {
        ListNode<T>* node = new ListNode<T>();
        node->data = value;
        node->prev = nullptr;

        if (node != nullptr)
        {
            node->next = head;
            head->prev = node;
            head = node;
        }
        else
        {
            head = tail = node;
        }

        count++;
    }

    void prepend(T value)
    {
        ListNode<T>* node = new ListNode<T>();
        node->data = value;
        node->next = nullptr;

        if (tail != nullptr)
        {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        else
        {
            head = tail = node;
        }

        count++;
    }

    void insertAt(T value, int index)
    {
        if (index > count)
        {
            throw std::out_of_range("Index is out of range");
        }

        if (index == 0)
        {
            append(value);
        }
        else if (index == count - 1)
        {
            prepend(value);
        }
        else
        {
            ListNode<T>* ptr = new ListNode<T>();
            ptr->data = value;

            ListNode<T>* node = this->head;
            for (int i = 0; i < index; i++)
            {
                node = node->next;
            }

            ptr->prev = node->prev;
            node->prev->next = ptr;

            ptr->next = node;
            node->prev = ptr;

            count++;
        }
    }

    LinkedList<T>* concat(LinkedList<T>* list)
    {
        LinkedList<T>* newList = new LinkedList<T>();

        {
            ListNode<T>* node = head;
            for (int i = 0; i < count; i++)
            {
                newList->prepend(node->data);
                node = node->next;
            }
        }

        {
            ListNode<T>* node = list->head;
            for (int k = 0; k < list->count; k++)
            {
                newList->prepend(node->data);
                node = node->next;
            }
        }

        return newList;
    }

private:

    template <class U>
    struct ListNode
    {
    public:
        ListNode() : next(nullptr), prev(nullptr), data(U())
        {

        }

        ~ListNode() = default;

    public:

        U data;

        ListNode* next;

        ListNode* prev;
    };

private:

    ListNode<T>* head = nullptr;
    ListNode<T>* tail = nullptr;
    int count = 0;


};
