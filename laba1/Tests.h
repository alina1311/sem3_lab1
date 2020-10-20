#pragma once
#include "Sorter.h"
#include <iostream>
#include <cassert> 
#include "LinkedList.h"
#include "ListSequence.h"
#include <algorithm>



void TestArraySequence()
{
	int Arr1[] = { 1,2,3,4 };
	int Arr2[] = { 5,1,7,2,3,4,0 };
	int Arr3[] = { 2,3 };
	int Arr4[] = { 7,2,3,4 };

	ArraySequence<int> seq1(Arr1, 4);
	ArraySequence<int> seq2(Arr2, 7);
	ArraySequence<int> seq3(Arr3, 2);
	ArraySequence<int> seq4(Arr4, 4);

	assert(seq1.getFirst() == 1);
	assert(seq1.getLast() == 4);
	assert(seq1.getLength() == 4);
	assert(seq1.get(1) == 2);

	seq1.append(5);
	seq1.prepend(0);
	seq1.insertAt(7, 2);
	for (int i = 0; i < 7; i++)
	{
		assert(seq1.get(i) == seq2.get(i));
	}

}

void TestDynamicArray()
{
	int Arr1[] = { 1,2,3,4,5 };
	int Arr2[] = { 9,2,3,4,5,6 };
	int Arr3[] = { 9,2 };

	DynamicArray<int> arr1(Arr1, 5);
	DynamicArray<int> arr2(Arr2, 6);
	DynamicArray<int> arr3(Arr3, 2);

	assert(arr1.get(0) == 1);
	assert(arr1.get(3) == 4);
	assert(arr1.get(4) == 5);
	assert(arr1.getLength() == 5);

	arr1.resize(6);
	arr1.set(9, 0);
	arr1.set(6, 5);
	for (int i = 0; i < 6; i++)
	{
		assert(arr1.get(i) == arr2.get(i));
	}
	arr1.resize(2);
	for (int i = 0; i < 2; i++)
	{
		assert(arr1.get(i) == arr3.get(i));
	}
}

void TestLinkedList()
{
	int Arr1[] = { 1,2,3,6 };
	int Arr2[] = { 7,1,2,3,4,5,6,0 };
	int Arr3[] = { 7,1 };
	int Arr4[] = { 2,3,4,5 };
	int Arr5[] = { 0,1,2,3,5,0,-1 };
	int Arr6[] = { 0,1,2,3,5,0,1,2,3,5 };

	LinkedList<int> list1(Arr1, 4);
	LinkedList<int> list2(Arr2, 8);
	LinkedList<int> list3(Arr3, 2);
	LinkedList<int> list4(Arr4, 4);
	LinkedList<int> list5(Arr5, 3);
	LinkedList<int> list6(Arr6, 4);

	assert(list1.get(0) == 1);
	assert(list1.getFirst() == 1);
	assert(list1.get(2) == 3);
	assert(list1.get(3) == 6);
	assert(list1.getLast() == 6);
	assert(list1.getLength() == 4);

	list1.prepend(0);
	list1.append(7);
	list1.insertAt(4, 4);
	list1.insertAt(5, 5);
	for (int i = 0; i < 8; i++)
	{
		assert(list1.get(i) == list2.get(i));
	}

	LinkedList<int>* l2 = list1.getSubList(0, 1);
	LinkedList<int> List2 = *l2;
	for (int i = 0; i < 2; i++)
	{
		assert(List2.get(i) == list3.get(i));
	}
	LinkedList<int>* l3 = list1.getSubList(2, 5);
	LinkedList<int> List3 = *l3;
	for (int i = 0; i < 4; i++)
	{
		assert(List3.get(i) == list4.get(i));
	}
	LinkedList<int>* l4 = list1.getSubList(0, 7);
	LinkedList<int> List4 = *l4;
	for (int i = 0; i < 8; i++)
	{
		assert(List4.get(i) == list1.get(i));
	}

}

void TestListSequence()
{
	int Arr1[] = { 1,2,3,5 };
	int Arr2[] = { -1,0,1,2,3,4,5,6,7 };
	ListSequence<int> seq1(Arr1, 4);
	ListSequence<int> seq2(Arr2, 9);

	assert(seq1.get(0) == 1);
	assert(seq1.getFirst() == 1);
	assert(seq1.get(2) == 3);
	assert(seq1.get(3) == 5);
	assert(seq1.getLast() == 5);
	assert(seq1.getLength() == 4);

	seq1.prepend(6);
	seq1.append(0);
	seq1.insertAt(-1, 0);
	seq1.prepend(7);
	seq1.insertAt(4, 5);

	for (int i = 0; i < 9; i++)
	{
		assert(seq1.get(i) == seq2.get(i));
	}

}

void testSortFunctions()
{
	ArraySequence<int>* arr0 = new ArraySequence<int>(0);
	BubbleSort(arr0);
	assert(arr0->getLength() == 0);
	ShellSort(arr0);
	assert(arr0->getLength() == 0);
	QuickSort(arr0);
	assert(arr0->getLength() == 0);
	delete arr0;

	ArraySequence<int>* arr1 = new ArraySequence<int>(1);
	arr1->set(3,0);

	BubbleSort(arr1);
	assert(arr1->getLength() == 1);
	assert(arr1->getFirst() == 3);
	ShellSort(arr1);
	assert(arr1->getLength() == 1);
	assert(arr1->getFirst() == 3);
	QuickSort(arr1);
	assert(arr1->getLength() == 1);
	assert(arr1->getFirst() == 3);
	delete arr1;

	ArraySequence<int>* arr2 = new ArraySequence<int>(5);
	arr2->set(6, 0);
	arr2->set(3, 1);
	arr2->set(5, 2);
	arr2->set(7, 3);
	arr2->set(4, 4);

	BubbleSort(arr2);
	assert(arr2->getLength() == 5);
	assert(arr2->get(0) == 3);
	assert(arr2->get(1) == 4);
	assert(arr2->get(2) == 5);
	assert(arr2->get(3) == 6);
	assert(arr2->get(4) == 7);
	delete arr2;

	arr2 = new ArraySequence<int>(5);
	arr2->set(1, 0);
	arr2->set(1, 1);
	arr2->set(1, 2);
	arr2->set(1, 3);
	arr2->set(1, 4);
	BubbleSort(arr2);
	assert(arr2->getLength() == 5);
	assert(arr2->get(0) == 1);
	assert(arr2->get(1) == 1);
	assert(arr2->get(2) == 1);
	assert(arr2->get(3) == 1);
	assert(arr2->get(4) == 1);
	delete arr2;


	arr2 = new ArraySequence<int>(5);
	arr2->set(6, 0);
	arr2->set(3, 1);
	arr2->set(5, 2);
	arr2->set(7, 3);
	arr2->set(4, 4);
	ShellSort(arr2);
	assert(arr2->getLength() == 5);
	assert(arr2->get(0) == 3);
	assert(arr2->get(1) == 4);
	assert(arr2->get(2) == 5);
	assert(arr2->get(3) == 6);
	assert(arr2->get(4) == 7);
	delete arr2;

	arr2 = new ArraySequence<int>(5);
	arr2->set(1, 0);
	arr2->set(1, 1);
	arr2->set(1, 2);
	arr2->set(1, 3);
	arr2->set(1, 4);
	ShellSort(arr2);
	assert(arr2->getLength() == 5);
	assert(arr2->get(0) == 1);
	assert(arr2->get(1) == 1);
	assert(arr2->get(2) == 1);
	assert(arr2->get(3) == 1);
	assert(arr2->get(4) == 1);
	delete arr2;

	arr2 = new ArraySequence<int>(5);
	arr2->set(6, 0);
	arr2->set(3, 1);
	arr2->set(5, 2);
	arr2->set(7, 3);
	arr2->set(4, 4);
	QuickSort(arr2);
	assert(arr2->getLength() == 5);
	assert(arr2->get(0) == 3);
	assert(arr2->get(1) == 4);
	assert(arr2->get(2) == 5);
	assert(arr2->get(3) == 6);
	assert(arr2->get(4) == 7);
	delete arr2;

	arr2 = new ArraySequence<int>(5);
	arr2->set(1, 0);
	arr2->set(1, 1);
	arr2->set(1, 2);
	arr2->set(1, 3);
	arr2->set(1, 4);
	QuickSort(arr2);
	assert(arr2->getLength() == 5);
	assert(arr2->get(0) == 1);
	assert(arr2->get(1) == 1);
	assert(arr2->get(2) == 1);
	assert(arr2->get(3) == 1);
	assert(arr2->get(4) == 1);
	delete arr2;
}



void tests() 
{
	TestDynamicArray();
	cout << "class DynamicArray is successfully tested" << endl;
	TestLinkedList();
	cout << "class LinkedList is successfully tested" << endl;
	TestArraySequence();
	cout << "class ArraySequence is successfully tested" << endl;
	TestListSequence();
	cout << "class ListSequence is successfully tested" << endl;
	testSortFunctions();
	cout << "Sort functions for class Sequence are successfully tested" << endl;
}