#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <ctime>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;



void MakeVec(vector<int>& vecA, vector<int>& vecD, vector<int>& vecR)
{
	srand(time(NULL));

	//Setting size to 1,000
	vecA.resize(1000);
	vecD.resize(1000);
	vecR.resize(1000);

	//Ascending order filling vector
	for (int i = 0; i < 1000; i++)
	{
		vecA[i] = i;
	}

	//Descending order
	for (int i = 0; i < 1000; i++)
	{
		vecD[i] = (1000 - i);
	}


	// Random vector order
	for (int i = 0; i < 1000; i++)
	{
		vecR[i] = (rand() % 1000);
	}

}





void insertionSort(vector <int>& num, int& numberC)
{
	//Start comparisons and at 0
	numberC = 0;
	


	int i, j, key;

	bool insertionNeeded = false;

	for (j = 1; j < num.size(); j++) 
	{
		key = num[j];
		insertionNeeded = false;
		for (i = j - 1; i >= 0; i--) 
		{
			
			if (key < num[i]) {			
				numberC++;                  //Adding one to comparison
				num[i + 1] = num[i]; // larger values move right
				insertionNeeded = true;
				
			}
			else
			{
				
				break;
			}
		}
		if (insertionNeeded)
		{
			
			num[i + 1] = key;     //Put key into its proper location
			
		}
	}

}






void merge(vector<int>& array, vector<int>& result, int lowPointer, int highPointer, int upperBound, int& numberC) {

	int j = 0;
	int lowerBound = lowPointer;
	int mid = highPointer - 1;
	int n = upperBound - lowerBound + 1; //number of items

	while (lowPointer <= mid && highPointer <= upperBound) {

		if (array[lowPointer] < array[highPointer])
		{
			result[j++] = array[lowPointer++];
			numberC++;			//Comparison added
		}
		else
		{
			result[j++] = array[highPointer++];
			numberC++;			//Comparison added
		}
	}

	while (lowPointer <= mid)
	{
		numberC++;			//Comparison added

		result[j++] = array[lowPointer++];		
		
	}

	while (highPointer <= upperBound)
	{
		numberC++;			//Comparison added

		result[j++] = array[highPointer++];		
	}
	for (j = 0; j < n; j++)
	{
		array[lowerBound + j] = result[j];		

	}
}
void mergesort(vector<int>& array, vector<int>& result, int lowerBand, int upperBand, int& numberC) {
	int midpoint;
							
	if (lowerBand < upperBand) {       
		numberC++;			//Comparison added
		midpoint = (lowerBand + upperBand) / 2;
		mergesort(array, result, lowerBand, midpoint, numberC);
		mergesort(array, result, midpoint + 1, upperBand, numberC);
		merge(array, result, lowerBand, midpoint + 1, upperBand, numberC);
	}
}
void mergeSort(vector<int>& array, int& numberC) {

	//Start comparisons at 0
	numberC = 0;
	



	vector<int> result = array;
	mergesort(array, result, 0, array.size() - 1, numberC);
}







void heapify(vector<int>& arr, int n, int i,int& numberC)
{
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest])
	{
		largest = l;
		numberC++;			//Comparison added
	}
	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest])
	{
		largest = r;
		numberC++;			//Comparison added
	}
	// If largest is not root 
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		numberC++;				//Comparison added
		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest, numberC);
	}
}
void heapSort(vector<int>& arr, int n,int& numberC)
{
	numberC = 0;

	// Build heap (rearrange array) 
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i,numberC);

	// One by one extract an element from heap 
	for (int i = n - 1; i > 0; i--)
	{
		// Move current root to end 
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap 
		heapify(arr, i, 0, numberC);
	}
}




void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition(vector<int>& arr, int low, int high, int& numberC)
{
	int pivot = arr[high]; // pivot  
	int i = (low - 1); // Index of smaller element  

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot 
		
		if (arr[j] < pivot)
		{
			numberC++;				//Comparison added
			i++; // increment index of smaller element  
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quickSort(vector<int>& arr, int low, int high,int& numberC)
{
	if (low < high)
	{
		numberC++;		//Comparison added
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high,numberC);

		// Separately sort elements before  
		// partition and after partition  
		quickSort(arr, low, pi - 1,numberC);
		quickSort(arr, pi + 1, high,numberC);
	}
}





void countingSort(vector <int>& arr, int& numberC)
{
	int max = *max_element(arr.begin(), arr.end());
	int min = *min_element(arr.begin(), arr.end());
	int range = max - min + 1;

	vector<int> count(range), output(arr.size());
	for (int i = 0; i < arr.size(); i++)
		count[arr[i] - min]++;

	for (int i = 1; i < count.size(); i++)
		count[i] += count[i - 1];

	for (int i = arr.size() - 1; i >= 0; i--)
	{
		output[count[arr[i] - min] - 1] = arr[i];
		count[arr[i] - min]--;
	}

	for (int i = 0; i < arr.size(); i++)
		arr[i] = output[i];
}






int getMax(vector<int> arr, int n,int& numberC)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > mx)
		{
			numberC++;
			mx = arr[i];
		}
	}
	return mx;
}
// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void CountSort(vector<int>& arr, int n, int exp)
{
	vector<int> output(n); // output array 
	int i, count[10] = { 0 };

	// Store count of occurrences in count[] 
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual 
	//  position of this digit in output[] 
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array 
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now 
	// contains sorted numbers according to current digit 
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}
// The main function to that sorts arr[] of size n using  
// Radix Sort 
void radixSort(vector<int>& arr, int n,int& numberC)
{
	// Find the maximum number to know number of digits 
	int m = getMax(arr, n,numberC);

	// Do counting sort for every digit. Note that instead 
	// of passing digit number, exp is passed. exp is 10^i 
	// where i is current digit number 
	for (int exp = 1; m / exp > 0; exp *= 10)
		CountSort(arr, n, exp);
}




void print(vector<int> arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}