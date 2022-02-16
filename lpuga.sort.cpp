//Luis Puga
// November 21, 2021
// This Program .reads the file of unsorted numbers, displays them, sorts, displays them, and saves sorted list into new file

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

const int NUMTOTAL = 12;

void welcome();// Program title

void sort(int*);//Sort Array

void swap(int& a, int& b);// Swap

int main() {

	ifstream inputFile;
	int number;

	welcome();// Program title


	inputFile.open("test.txt");

	//Before Sort
	cout << "Before Sort" << endl;
	
	int* NumList = new int[NUMTOTAL];

	for (int i = 0; i < NUMTOTAL; ++i)
	{
		inputFile >> *(NumList + i);
	}
	
	for (int i = 0; i < NUMTOTAL; ++i)
	{
		cout << setw(12) << "Number " << i+1 << " = " << *(NumList + i) << endl;
	}
	

	

	//After Sort

	sort(NumList);//Sort Array

	cout << "\nAfter Sort" << endl;
	for (int count = 0; count < NUMTOTAL
		; count++)
	{
		cout << setw(12) << "Number " << count + 1 << " = " << *(NumList + count) << endl;
	}
	
	//Write into new file and submit
	//Open The File
	ofstream outputFile;

	outputFile.open("output.txt");
	if (outputFile.is_open())
	{
		
		for (int count = 0; count < NUMTOTAL; count++)
			outputFile << *(NumList + count) << endl;
		
		outputFile.close();
	}
	else cout << "Unable to open file";
	


	inputFile.close();
	return 0;
}

// Program title
void welcome() {

	cout << "CE - Sort\n";
	cout << "Copyright 2021 - Howard Community College All Rights Reserved; Unauthorized duplication prohibited.\n\n";
	cout << right << setw(5) << "             Welcome to CMSY-141 File Sorting Program" << right << endl;

}

void sort(int* NumList) {//Sort Array
	int maxElement;
	int index;
	for (maxElement = 0; maxElement < NUMTOTAL; maxElement++)
	{
		for (index = 0; index < (NUMTOTAL - 1); index++)
		{
			if (NumList[index] > NumList[index + 1])
			{
				swap(NumList[index], NumList[index + 1]);
			}
		}
	}
}

void swap(int& a, int& b) { // Swap
	int temp = a;
	a = b;
	b = temp;
}

