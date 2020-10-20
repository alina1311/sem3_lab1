#include <complex.h>
#include "Sorter.h"
#include <cstdlib>
#include <ctime>
#include "ArraySequence.h"
#include "Tests.h"


template <class T>
void PrintSequence(ArraySequence<T>* seq)
{
    int size = seq->getLength();
    for (int i = 0; i < size; i++)
    {
        std::cout << seq->get(i) << ' ';
    }
    std::cout << std::endl;
}


void showMenu()
{
    std::cout << ("==============================================\n");
    std::cout << ("Application menu:") << std::endl;
    std::cout << ("1 - automatic sorting check") << std::endl;
    std::cout << ("2 - manual sorting check") << std::endl;
    std::cout << ("3 - comparison of sorting algorithms") << std::endl;
    std::cout << ("4 - Tests") << std::endl;
    std::cout << ("0 - Exit") << std::endl;
    std::cout << ("==============================================\n");
}

//==================================================================================================//

void processAutomaticCheck()
{
    ArraySequence<int>* seq;
    int size;
    std::cout << ("Enter count of elements: ");
    std::cin >> size;
    seq = new ArraySequence<int>(size);
    for (int i = 0; i < size; i++)
    {
        seq->set(rand(), i);
    }

    std::cout << ("Choose a sorting algorithm:") << std::endl;
    std::cout << ("1 - Bubble Sort") << std::endl;
    std::cout << ("2 - Shell Sort") << std::endl;
    std::cout << ("3 - Quick Sort") << std::endl;

    int choice = 0;
    std::cin >> choice;
    if (choice < 1 || choice > 3)
    {
        std::cout << ("Incorrect command selection") << std::endl;
    }
    else
    {
       // std::cout << ("Sequence: ");
       // PrintSequence(seq);
       // std::cout << std::endl;

        if (choice == 1)
        {
            BubbleSort(seq);

            //std::cout << ("Sorted sequence: ");
            //PrintSequence(seq);
            //std::cout << std::endl;

            if (CorrectSorted(seq) == true)
            {
                std::cout << ("Correct") << std::endl;
            }
            else
            {
                std::cout << ("Incorrect") << std::endl;
            }
        }


        if (choice == 2)
        {
            ShellSort(seq);

            //std::cout << ("Sorted sequence: ");
            //PrintSequence(seq);
            //std::cout << std::endl;

            if (CorrectSorted(seq) == true)
            {
                std::cout << ("Correct") << std::endl;
            }
            else
            {
                std::cout << ("Incorrect") << std::endl;
            }
        }

        if (choice == 3)
        {
            QuickSort(seq);

            //std::cout << ("Sorted sequence: ");
            //PrintSequence(seq);
            //std::cout << std::endl;

            if (CorrectSorted(seq) == true)
            {
                std::cout << ("Correct") << std::endl;
            }
            else
            {
                std::cout << ("Incorrect") << std::endl;
            }
        }
    }
}

void processManualCheck()
{
    std::cout << ("Choose a sorting algorithm:") << std::endl;
    std::cout << ("1 - Bubble Sort") << std::endl;
    std::cout << ("2 - Shell Sort") << std::endl;
    std::cout << ("3 - Quick Sort") << std::endl;

    int choice = 0;
    std::cin >> choice;
    if (choice < 1 || choice > 3)
    {
        std::cout << ("Incorrect command selection") << std::endl;
    }
    else
    {

        ArraySequence<int>* seq;
        ArraySequence<int>* CorrectSeq;
        int size;
        std::cout << ("Enter count of elements: ");
        std::cin >> size;

        seq = new ArraySequence<int>(size);
        CorrectSeq = new ArraySequence<int>(size);

        std::cout << ("Enter elements: ") << std::endl;
        for (int i = 0; i < size; i++)
        {
            int elem;
            std::cin >> elem;
            seq->set(elem, i);
        }
        std::cout << ("Enter correct sequence: ") << std::endl;
        for (int i = 0; i < size; i++)
        {
            int elem;
            std::cin >> elem;
            CorrectSeq->set(elem, i);
        }

        std::cout << ("Sequence: ");
        PrintSequence(seq);
        std::cout << std::endl;

        if (choice == 1)
        {
            BubbleSort(seq);
            std::cout << ("Sorted sequence: ");
            PrintSequence(seq);
            std::cout << std::endl;
            std::cout << ("Correct sorted sequence: ");
            PrintSequence(CorrectSeq);
            std::cout << std::endl;

            int k = 0;
            while (k < size)
            {
                if (seq->get(k) == CorrectSeq->get(k))
                {
                    k++;
                }
                else
                {
                    std::cout << ("Incorrect") << std::endl;
                    break;
                }
            }
            std::cout << ("Correct") << std::endl;
        }

        if (choice == 2)
        {
            ShellSort(seq);
            std::cout << ("Sorted sequence: ");
            PrintSequence(seq);
            std::cout << std::endl;
            std::cout << ("Correct sorted sequence: ");
            PrintSequence(CorrectSeq);
            std::cout << std::endl;

            int k = 0;
            while (k < size)
            {
                if (seq->get(k) == CorrectSeq->get(k))
                {
                    k++;
                }
                else
                {
                    std::cout << ("Incorrect") << std::endl;
                    break;
                }
            }
            std::cout << ("Correct") << std::endl;
        }

        if (choice == 3)
        {
            QuickSort(seq);
            std::cout << ("Sorted sequence: ");
            PrintSequence(seq);
            std::cout << std::endl;
            std::cout << ("Correct sorted sequence: ");
            PrintSequence(CorrectSeq);
            std::cout << std::endl;

            int k = 0;
            while (k < size)
            {
                if (seq->get(k) == CorrectSeq->get(k))
                {
                    k++;
                }
                else
                {
                    std::cout << ("Incorrect") << std::endl;
                    break;
                }
            }
            std::cout << ("Correct") << std::endl;
        }
    }
}

void processComparing()
{
    std::cout << ("Choose a comparing algorithms:") << std::endl;
    std::cout << ("1 - Bubble Sort") << std::endl;
    std::cout << ("2 - Shell Sort") << std::endl;
    std::cout << ("3 - Quick Sort") << std::endl;

    int choice1 = 0;
    std::cin >> choice1;
    int choice2 = 0;
    std::cin >> choice2;
    if (choice1 < 1 || choice1 > 3 || choice2 < 1 || choice2 > 3)
    {
        std::cout << ("Incorrect command selection") << std::endl;
    }
    else
    {
        ArraySequence<int>* seq;
        int size;
        std::cout << ("Enter count of elements: ");
        std::cin >> size;
        seq = new ArraySequence<int>(size);
        for (int i = 0; i < size; i++)
        {
            seq->set(rand(), i);
        }

        //std::cout << ("Sequence: ");
        //PrintSequence(seq);
        //std::cout << std::endl;

        if (choice1 == 1 && choice2 == 2) 
        {
            double time1 = Timing(seq, BubbleSort);
            double time2 = Timing(seq, ShellSort);
            std::cout << ("Time spent on Bubble sort: ") << time1 << std::endl;
            std::cout << ("Time spent on Shell sort: ") << time2 << std::endl;
            if (time1 < time2)
            {
                std::cout << ("Bubble sorting is more efficient") << std::endl;
            }
            else
            {
                std::cout << ("Shell sorting is more efficient") << std::endl;
            }
        }
        if (choice2 == 1 && choice1 == 2)
        {
            double time2 = Timing(seq, BubbleSort);
            double time1 = Timing(seq, ShellSort);
            std::cout << ("Time spent on Bubble sort: ") << time2 << std::endl;
            std::cout << ("Time spent on Shell sort: ") << time1 << std::endl;
            if (time2 < time1)
            {
                std::cout << ("Bubble sorting is more efficient") << std::endl;
            }
            else
            {
                std::cout << ("Shell sorting is more efficient") << std::endl;
            }
        }

        if (choice1 == 2 && choice2 == 3)
        {
            double time1 = Timing(seq, ShellSort);
            double time2 = Timing(seq, QuickSort);
            std::cout << ("Time spent on Shell sort: ") << time1 << std::endl;
            std::cout << ("Time spent on Quick sort: ") << time2 << std::endl;
            if (time1 < time2)
            {
                std::cout << ("Shel sorting is more efficient") << std::endl;
            }
            else
            {
                std::cout << ("Quick sorting is more efficient") << std::endl;
            }
        }
        if (choice2 == 2 && choice1 == 3)
        {
            double time2 = Timing(seq, ShellSort);
            double time1 = Timing(seq, QuickSort);
            std::cout << ("Time spent on Shell sort: ") << time2 << std::endl;
            std::cout << ("Time spent on Quick sort: ") << time1 << std::endl;
            if (time2 < time1)
            {
                std::cout << ("Shel sorting is more efficient") << std::endl;
            }
            else
            {
                std::cout << ("Quick sorting is more efficient") << std::endl;
            }
        }

        if (choice1 == 1 && choice2 == 3)
        {
            double time1 = Timing(seq, BubbleSort);
            double time2 = Timing(seq, QuickSort);
            std::cout << ("Time spent on Bubble sort: ") << time1 << std::endl;
            std::cout << ("Time spent on Quick sort: ") << time2 << std::endl;
            if (time1 < time2)
            {
                std::cout << ("Bubble sorting is more efficient") << std::endl;
            }
            else
            {
                std::cout << ("Quick sorting is more efficient") << std::endl;
            }
        }
        if (choice2 == 1 && choice1 == 3)
        {
            double time2 = Timing(seq, BubbleSort);
            double time1 = Timing(seq, QuickSort);
            std::cout << ("Time spent on Bubble sort: ") << time2 << std::endl;
            std::cout << ("Time spent on Quick sort: ") << time1 << std::endl;
            if (time2 < time1)
            {
                std::cout << ("Bubble sorting is more efficient") << std::endl;
            }
            else
            {
                std::cout << ("Quick sorting is more efficient") << std::endl;
            }
        }
    }
}

int main()
{
    std::cout << "Hello!" << std::endl;
    while (true)
    {
        showMenu();
        int currentAction = 0;
        std::cin >> currentAction;

        if (currentAction == 0)
        {
            std::cout << ("See you!\n");
            break;
        }
        else if (4 < currentAction )
        {
            std::cout << ("Incorrect command") << std::endl;
        }
        else if (currentAction == 1)
        {
            processAutomaticCheck();
        }
        else if (currentAction == 2)
        {
            processManualCheck();
        }
        else if (currentAction == 3)
        {
            processComparing();
        }
        else if (currentAction == 4)
        {
            tests();
        }
    }
    return 0;
}

