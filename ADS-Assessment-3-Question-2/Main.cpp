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

	heapClass topRankedPlayers;

	//Reads in textfile and stores information into Variables
	ifstream readFile;
	readFile.open("input-q2a2.txtt");
	readFile >> firstLineVariable;

	for (int i = 0; i < firstLineVariable; i++)
	{
		readFile >> secondLineVariable;
		topRankedPlayers.Insert(numbersClass(22, "Goober"));
	}


	topRankedPlayers.Insert(numbersClass(22, "Goober"));
	topRankedPlayers.Insert(numbersClass(4, "Kelpy"));
	topRankedPlayers.Insert(numbersClass(24, "Octopus"));
	topRankedPlayers.Insert(numbersClass(3, "$Bling$"));
	numbersClass p1(1, "Head_Sh0t!");
	topRankedPlayers.Insert(p1);

	//NOTE doesn't really care about sorting, just min parents
	topRankedPlayers.showHeap();
	//try get top player
	numbersClass* topPlayer = topRankedPlayers.ExtractMin();
	if (topPlayer != NULL)
		cout << "Highest Rank Player: " << topPlayer->rank << " " << (*topPlayer).name << endl;
	else
		cout << "Heap must be empty!!!" << endl;

	cout << "Try deleting top player..." << endl;
	topRankedPlayers.DeleteMin();
	topPlayer = topRankedPlayers.ExtractMin();
	if (topPlayer != NULL)
		cout << "Highest Rank Player: " << topPlayer->rank << " " << (*topPlayer).name << endl;
	else
		cout << "Heap must be empty!!!" << endl;

	cout << "Try deleting top player..." << endl;


	system("pause");
}