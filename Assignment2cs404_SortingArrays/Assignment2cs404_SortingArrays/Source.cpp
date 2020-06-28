#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <list>
#include "Header.h"
using namespace std;


int main()
{
	vector<int> vecA, vecD, vecR;
	int numberCompare;
	numberCompare = 0;
	
	MakeVec(vecA, vecD, vecR);
	int size = vecA.size();


	//Insertion Sort

	//Acending Order
	/*print(vecA, size);
	insertionSort(vecA, numberCompare);
	cout << "\n\nInsertion Sort has been sorted\nComparisons: " << numberCompare << "\n\n";
	print(vecA, size);*/

	//Reversed Order
	/*print(vecD, size);
	insertionSort(vecD, numberCompare);
	cout << "\n\nInsertion Sort has been sorted\nComparisons: " << numberCompare << "\n\n";
	print(vecD, size);*/

	//Random Order
	/*print(vecR, size);
	insertionSort(vecR, numberCompare);
	cout << "\n\nInsertion Sort has been sorted\nComparisons: " << numberCompare << "\n\n";
	print(vecR, size);*/



	//Merge Sort

	//Acending Order
	/*print(vecA, size);
	mergeSort(vecA, numberCompare);
	cout << "\n\nMerge Sort has been sorted\nComparisons: " << numberCompare << "\n\n";
	print(vecA, size);*/

	//Reversed Order
	/*print(vecD, size);
	mergeSort(vecD, numberCompare);
	cout << "\n\nMerge Sort has been sorted\nComparisons: " << numberCompare << "\n\n";
	print(vecD, size);*/

	//Random Order
	/*print(vecR, size);
	mergeSort(vecR, numberCompare);
	cout << "\n\nMerge Sort has been sorted\nComparisons: " << numberCompare << "\n\n";
	print(vecR, size);*/



	//Heap Sort

	//Ascending Order
	/*print(vecA, size);
	heapSort(vecA, size, numberCompare);
	cout << "\n\nHeap Sort has been sorted\nComparisons: " << numberCompare << "\n\n";
	print(vecA, size);*/

	//Reversed Order
	/*print(vecD, size);
	heapSort(vecD, size, numberCompare);
	cout << "\n\nHeap Sort has been sorted\nComparisons: " << numberCompare << "\n\n";
	print(vecD, size);*/

	//Random Order
	/*print(vecR, size);
	heapSort(vecR, size, numberCompare);
	cout << "\n\nHeap Sort has been sorted\nComparisons: " << numberCompare << "\n\n";
	print(vecR, size);*/



	//Quick Sort

	//Ascending Order
	/*print(vecA, size);
	quickSort(vecA,0,size-1, numberCompare);
	cout << "\n\nQuick Sort has been sorted\nComparisons: " << numberCompare << "\n\n";
	print(vecA, size);*/

	//Reversed Order
	/*print(vecD, size);
	quickSort(vecD, 0, size - 1, numberCompare);
	cout << "\n\nQuick Sort has been sorted\nComparisons: " << numberCompare << "\n\n";
	print(vecD, size);*/

	//Random Order
	/*print(vecR, size);
	quickSort(vecR, 0, size - 1, numberCompare);
	cout << "\n\nQuick Sort has been sorted\nComparisons: " << numberCompare << "\n\n";
	print(vecR, size);*/



	//Counting Sort

	//Ascending Order
	/*print(vecA, size);
	countingSort(vecA, numberCompare);
	cout << "\n\nCounting Sort has been sorted\nComparisons: " << numberCompare << "\n\n";
	print(vecA, size);*/

	//Reversed Order
	/*print(vecD, size);
	countingSort(vecD, numberCompare);
	cout << "\n\nCounting Sort has been sorted\nComparisons: " << numberCompare << "\n\n";
	print(vecD, size);*/

	//Random Order
	/*print(vecA, size);
	countingSort(vecA, numberCompare);
	cout << "\n\nCounting Sort has been sorted\nComparisons: " << numberCompare << "\n\n";
	print(vecA, size);*/




	//Radix Sort

	//Ascending Order
	/*print(vecA, size);
	radixSort(vecA, size, numberCompare);
	cout << "\n\nRadix Sort has been sorted\nComparisons: " << numberCompare << "\n\n";
	print(vecA, size);*/

	//Reversed Order
	/*print(vecD, size);
	radixSort(vecD, size, numberCompare);
	cout << "Radix Sort has been sorted\nComparisons: " << numberCompare<<"\n\n";
	print(vecD, size);*/

	//Random Order
	/*print(vecR, size);
	radixSort(vecR, size, numberCompare);
	cout << "Radix Sort has been sorted\nComparisons: " << numberCompare << "\n\n";
	print(vecR, size);*/



	return 0;
}