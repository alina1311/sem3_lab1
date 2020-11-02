#pragma once

#include "Sequence.h"
#include "ArraySequence.h"
#include <ctime>

using namespace std;

template <class T>
void BubbleSort(Sequence<T>* seq)
{
    if (seq->getLength() <= 1) return;
    int size = seq->getLength();
    for (int i = 0; i < size-1; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (seq->get(j-1) > seq->get(j))
            {
                T tmp = seq->get(j-1);
                seq->set(seq->get(j), j-1);
                seq->set(tmp, j);
            }
        }
    }
}

template <class T>
void ShellSort(Sequence<T>* seq)
{
    int size = seq->getLength();
    int increment = 3;
    while (increment > 0)
    {
        for (int i = 0; i < size; i++)
        {
            int j = i;
            int tmp = seq->get(i);
            while ((j >= increment) && (seq->get(j - increment) > tmp))
            {
                seq->set(seq->get(j - increment), j);
                j = j - increment;
            }
            seq->set(tmp, j);
        }
        if (increment > 1)
        {
            increment = increment / 2;
        }
        else if (increment == 1)
        {
            break;
        }
    }
}


template <class T>
void _QuickSort_(Sequence<T>* seq, int left, int right)
{
    int pivot = seq->get((left + right)/2);
    int i = left;
    int j = right;
    int tmp;
    while (i <= j)
    {
        while (seq->get(i) < pivot)
        {
            i++;
        }
        while (seq->get(j) > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            tmp = seq->get(i);
            seq->set(seq->get(j), i);
            seq->set(tmp, j);
            i++;
            j--;
        }
    }
    if (j > left)
    {
        _QuickSort_(seq, left, j);
    }
    if (i < right)
    {
        _QuickSort_(seq, i, right);
    }
}

template <class T>
void QuickSort(Sequence<T>* seq)
{
    if (seq->getLength() <= 1)
    {
        return;
    }
    else
    {
        int size = seq->getLength();
        _QuickSort_(seq, 0, size - 1);
    }
}




template <class T>
double Timing(Sequence<T>* seq, void (*sort)(Sequence<T>* seq))
{
    clock_t startTime = clock();
    sort(seq);
    clock_t endTime = clock();
    double time = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    return time;
}

template <class T>
bool CheckIsSorted(Sequence<T>* seq)
{
    int size = seq->getLength();
    int i = 1;
    while ( i <= size - 1)
    {
        if (seq->get(i) >= seq->get(i - 1))
        {
            i++;
        }
        else
        {
            return false;
        }
    }
    return true;
}
