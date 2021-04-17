#include <iostream>
#include <string>
#include <windows.h>								//Library for controling windows functions
#include <fstream>									//Library for File System control
#include "heapClass.h"

using namespace std;

void main()
{
	//Declaration of Variables
	int firstLineVariable;
	int secondLineVariable;

	heapClass heapTree1;
	heapClass heapTree2;

	//Reads in textfile and stores information into Variables
	ifstream readFile;
	readFile.open("input-q2a2.txt");
	readFile >> firstLineVariable;

	//heapClass topRankedPlayers;

	

	for (int i = 0; i < firstLineVariable; i++)
	{
		readFile >> secondLineVariable;
		heapTree1.Insert(numbersClass(secondLineVariable));
		heapTree2.beforeHeap(numbersClass(secondLineVariable));
	}


	cout << " Before Heap -->";
	heapTree2.showHeap();


	//heapifyup(heapTree1.Size() - 1);


	cout << " After Heap -->";
	heapTree1.showHeap();


	system("pause");
}