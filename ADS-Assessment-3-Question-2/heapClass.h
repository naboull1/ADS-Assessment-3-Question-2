#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include "numbersClass.h"

using namespace std;

class heapClass
{
public:
	vector<numbersClass> heap;
	int leftChildIndex(int parent);
	int rightChildIndex(int parent);
	int parentIndex(int child);

	void heapifyup(int index);
	void heapifydown(int index);

	void Insert(numbersClass element);
	void DeleteMin();
	numbersClass* ExtractMin();
	void showHeap();
	int Size();

};