// ================================================================================================
// Copyright (C) 2021 by Georgios Ioannou
//
// FILE: Ioannou_Sorting_Algorithms.cpp
// Program to test the Time Complexity of the following 6 Sorting Algortihms:
// Insertion Sort, Merge Sort, Heap Sort, Quick Sort, Randomized Quick Sort, and LSD Radix Sort.
// 
// This file implements the 6 Sorting Algorithms based on the Pseudocodes from the textbook:
// "Introduction to Algorithms, THIRD EDITION" by Cormen, Leiserson, Rivest, and Stein and 
// published by The MIT Press.
// 
// Written by: Georgios Ioannou, 2021
// ================================================================================================

#include <cstdlib>  // Provides rand() and srand() functions
#include <ctime>    // Provides time() function
#include <cmath>    // Provides floor(), pow(), and log10()  functions
#include <limits>   // Provides std::numeric_limits
#include <chrono>   // Provides high_resolution clock and duration_cast function
#include <cassert>  // Provide the macro assert function
#include <iostream> // Provides cout and endl
using namespace std;
using namespace std::chrono;

// Function Prototypes
//
void randomlyGenerateArray    (int*, int);
void randomlyGenerateAllArrays(int*, int*, int*, int*, int*, int*);
void insertionSort            (int*, int);
void mergeSort                (int*, int, int);
void merge                    (int*, int, int, int);
void heapSort                 (int*, int);
void swap                     (int&, int&);
void buildHeap                (int*, int);
void heapify                  (int*, int, int);
void quickSort                (int*, int, int);
int  partition                (int*, int, int);
void randomizedQuickSort      (int*, int, int);
int  randomizedPartition      (int*, int, int);
void lsdRadixSort             (int*, int);
int  findMaxElement           (int*, int);
void countingSort             (int*, int*, int, int);
void printTable               (int*);

int main()
{	
	// Create 6 arrays for each input size N.
	//
	int* A = new int[10];
	int* B = new int[100];
	int* C = new int[1000];
	int* D = new int[10000];
	int* E = new int[100000];
	int* F = new int[1000000];

	// Create array to store the compiler times. 
	//
	int* compilerTime = new int[36];

	// Error checking
	//
	assert(A);
	assert(B);
	assert(C);
	assert(D);
	assert(E);
	assert(F);
	assert(compilerTime);

	// Fill arrays with random numbers.
	//
	randomlyGenerateAllArrays(A, B, C, D, E, F);

	//*********************************************************************************************
	// Sort arrays using the Insertion Sort Algorithm.
	//
	auto start = high_resolution_clock::now();
	insertionSort(A, 10);
	auto finish = high_resolution_clock::now();
	auto totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[0] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	insertionSort(B, 100);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[1] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	insertionSort(C, 1000);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[2] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	insertionSort(D, 10000);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[3] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	insertionSort(E, 100000);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[4] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	insertionSort(F, 1000000);
	finish = high_resolution_clock::now();
	auto totalElapsedTime2 = duration_cast<minutes>(finish - start);
	compilerTime[5] = totalElapsedTime2.count();
	//*********************************************************************************************

	// Fill arrays with random numbers.
	//
	randomlyGenerateAllArrays(A, B, C, D, E, F);

	//*********************************************************************************************
	// Sort arrays using the Merge Sort Algorithm.
	//
	start = high_resolution_clock::now();
	mergeSort(A, 0, 10 - 1);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[6] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	mergeSort(B, 0, 100 - 1);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[7] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	mergeSort(C, 0, 1000 - 1);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[8] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	mergeSort(D, 0, 10000 - 1);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[9] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	mergeSort(E, 0, 100000 - 1);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[10] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	mergeSort(F, 0, 1000000 - 1);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[11] = totalElapsedTime.count();
	//*********************************************************************************************

	// Fill arrays with random numbers.
	//
	randomlyGenerateAllArrays(A, B, C, D, E, F);

	//*********************************************************************************************
	// Sort arrays using the Heap Sort Algorithm.
	//
	start = high_resolution_clock::now();
	heapSort(A, 10);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[12] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	heapSort(B, 100);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[13] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	heapSort(C, 1000);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[14] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	heapSort(D, 10000);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[15] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	heapSort(E, 100000);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[16] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	heapSort(F, 1000000);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[17] = totalElapsedTime.count();
	//*********************************************************************************************

	// Fill arrays with random numbers.
	//
	randomlyGenerateAllArrays(A, B, C, D, E, F);

	//*********************************************************************************************
	// Sort arrays using the Quick Sort Algorithm.
	//
	start = high_resolution_clock::now();
	quickSort(A, 0, 10 - 1);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[18] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	quickSort(B, 0, 100 - 1);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[19] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	quickSort(C, 0, 1000 - 1);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[20] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	quickSort(D, 0, 10000 - 1);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[21] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	quickSort(E, 0, 100000 - 1);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[22] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	quickSort(F, 0, 1000000 - 1);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[23] = totalElapsedTime.count();
	//*********************************************************************************************

	// Fill arrays with random numbers.
	//
	randomlyGenerateAllArrays(A, B, C, D, E, F);

	//*********************************************************************************************
	// Sort arrays using the Randomized Quick Sort Algorithm.
	//
	start = high_resolution_clock::now();
	randomizedQuickSort(A, 0, 10 - 1);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[24] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	randomizedQuickSort(B, 0, 100 - 1);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[25] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	randomizedQuickSort(C, 0, 1000 - 1);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[26] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	randomizedQuickSort(D, 0, 10000 - 1);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[27] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	randomizedQuickSort(E, 0, 100000 - 1);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[28] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	randomizedQuickSort(F, 0, 1000000 - 1);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[29] = totalElapsedTime.count();
	//*********************************************************************************************

	// Fill arrays with random numbers.
	//
	randomlyGenerateAllArrays(A, B, C, D, E, F);
	
	//*********************************************************************************************
	// Sort arrays using the LSD Radix Sort Algorithm.
	//
	start = high_resolution_clock::now();
	lsdRadixSort(A, 10);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[30] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	lsdRadixSort(B, 100);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[31] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	lsdRadixSort(C, 1000);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[32] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	lsdRadixSort(D, 10000);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[33] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	lsdRadixSort(E, 100000);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[34] = totalElapsedTime.count();
	
	start = high_resolution_clock::now();
	lsdRadixSort(F, 1000000);
	finish = high_resolution_clock::now();
	totalElapsedTime = duration_cast<microseconds>(finish - start);
	compilerTime[35] = totalElapsedTime.count();
	//*********************************************************************************************

	// Print the table with the compiler time spent(microseconds) to sort the randomized arrays
	// using each Sorting Algorithm.
	// Exception:(When N=1000000 the compiler time for Insertion Sort is in minutes.)
	//
	printTable(compilerTime);

	// Free memory.
	//
	delete[] A;
	delete[] B;
	delete[] C;
	delete[] D;
	delete[] E;
	delete[] F;
	delete[] compilerTime;

	return 0;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// randomlyGenerateAllArrays:
//
// Precondition:  arrays with n elements.
// Postcondition: The arrays have been filled with random numbers between the range 0-10000.
//
void randomlyGenerateAllArrays(int* A, int* B, int* C, int* D, int* E, int* F)
{
	randomlyGenerateArray(A, 10);
	randomlyGenerateArray(B, 100);
	randomlyGenerateArray(C, 1000);
	randomlyGenerateArray(D, 10000);
	randomlyGenerateArray(E, 100000);
	randomlyGenerateArray(F, 1000000);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// randomlyGenerateArray:
//
// Precondition:  data is an array with n elements.
// Postcondition: The array data has been filled with random numbers between the range 0-10000.
//
void randomlyGenerateArray(int* data, int n)
{
	// Assign a huge seed value.
	//
	srand(1293810238120);

	// fill array with random numbers in the range [0,10000]
	//
	for (int i = 0; i < n; ++i) // visit all array elements
	{
		data[i] = rand() % 10001;
	}
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// insertionSort:
//
// Precondition:  data is an unsorted array with n randomly generated elements.
// Postcondition: data is a sorted array using Insertion Sort Algorithm.
//
void insertionSort(int* data, int n)
{
	int i, j, key;
	for (j = 1; j < n; ++j)
	{
		key = data[j];
		// Insert data[j] into the sorted array data[1..j-1]
		//
		i = j - 1;
		while (i >= 0 && data[i] > key)
		{
			data[i + 1] = data[i];
			i = i - 1;
		}
		data[i + 1] = key;
	}
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// mergeSort:
//
// Precondition:  data is an unsorted array with n randomly generated elements.
// Postcondition: data is a sorted array using Merge Sort Algorithm.
//
void mergeSort(int* data, int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = floor((left + right) / 2);
		mergeSort(data, left, mid); //LEFT recursion
		mergeSort(data, mid+1, right); //RIGHT recursion
		merge(data, left, mid, right);
	}
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// merge:
//
// Precondition:  merge() function takes two sorted subarrays of the original array data. 
// Postcondition: merge() fuction merges these two sorted subarays into a single sorted subarray.
//
void merge(int* data, int left, int middle, int right)
{
	int i, j;
	// Calculate the lengths of leftSubarray and rightSubarray.
	//
	int lengthLeftSubarray = middle - left + 1;
	int lenghtRightSubarray = right - middle;

	// Create the left and right subarrays with one more element. This element is the sentinel
	// value, so that when we copy all the elements of one of the subarrays back to the original
	// array data, then we will just copy/append the other subarray back to the original array data.
	//
	int* leftSubarray = new int[lengthLeftSubarray + 1];
	int* rightSubarray = new int[lenghtRightSubarray + 1];

	// Copy the subarray data[left..middle] into leftSubarray[0..lengthLeftSubarray]
	//
	for (i = 0; i < lengthLeftSubarray; ++i)
	{
		leftSubarray[i] = data[left + i];
	}

	// Copy the subarray data[middle + 1..right] into rightSubarray[0..lenghtRightSubarray]
	//
	//
	for (j = 0; j < lenghtRightSubarray; ++j)
	{
		rightSubarray[j] = data[middle + j + 1];
	}

	// Put the sentinels at the ends of the arrays leftSubarray and rightSubarray.
	//
	leftSubarray[lengthLeftSubarray] = numeric_limits<int>::max();
	rightSubarray[lenghtRightSubarray] = numeric_limits<int>::max();
	
	i = 0;
	j = 0;

	for (int k = left; k <= right; ++k)
	{
		if (leftSubarray[i] <= rightSubarray[j])
		{
			data[k] = leftSubarray[i];
			++i;
		}
		else
		{
			data[k] = rightSubarray[j];
			++j;
		}
	}
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// heapSort:
//
// Precondition:  data is an unsorted array with n randomly generated elements.
// Postcondition: data is a sorted array using Heap Sort Algorithm.
//
void heapSort(int* data, int n)
{
	buildHeap(data, n);
	for (int i = n - 1; i >= 1; --i)
	{
		swap(data[0], data[i]);
		heapify(data, i, 0);
	}
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// swap:
//
// Precondition:  val1 and val2 are two integers.
// Postcondition: val1 becomes val2 and val2 becomes val1.
//
void swap(int& val1, int& val2)
{
	int temp = val1;
	val1 = val2;
	val2 = temp;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// buildHeap:
//
// Precondition:  data is an unsorted array with n randomly generated elements.
// Postcondition: data is a Heap. None of the nodes violate the Heap property.
//                buildHeap() function makes sure that the Data Structure is a Heap.
//
void buildHeap(int* data, int n)
{
	for (int i = floor(n / 2); i >= 0; --i)
	{
		heapify(data, n, i);
	}
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// heapify:
//
// heapify() function maintains the Heap property. It makes sure that a path starting from a
// specific node up to the leaf nodes is a Heap and satisfies the Heap property.
//
void heapify(int* data, int n, int i)
{
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;
	int largest;

	if (leftChild < n && data[leftChild] > data[i])
	{
		largest = leftChild;
	}
	else
	{
		largest = i;
	}
	if (rightChild < n && data[rightChild] > data[largest])
	{
		largest = rightChild;
	}
	if (largest != i)
	{
		swap(data[i], data[largest]);
		heapify(data, n, largest);
	}
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// quickSort:
//
// Precondition:  data is an unsorted array with n randomly generated elements.
// Postcondition: data is a sorted array using Quick Sort Algorithm.
//
void quickSort(int* data, int p, int r)
{
	int q;

	if (p < r)
	{
		q = partition(data, p, r);
		quickSort(data, p, q - 1); // LEFT recursion
		quickSort(data, q + 1, r); // RIGHT recusriosn

	}
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// partition:
//
// Precondition:  partition() function takes an unsorted array with n randomly generated elements.
// Postcondition: partition() function return the index q, of the "pivot" element that separates
//                the two subarrays.
//                All values in first subarray <= All values in second subarray
// This partition() function picks the last element of data as the pivot.
//
int partition(int* data, int p, int r)
{
	int x = data[r]; // pivot is the last element of the array data
	int i = p - 1;

	for (int j = p; j <= r - 1; ++j)
	{
		if (data[j] <= x)
		{
			++i;
			swap(data[i], data[j]);
		}
	}

	swap(data[i + 1], data[r]);

	return i + 1;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// randomizedQuickSort:
//
// Precondition:  data is an unsorted array with n randomly generated elements.
// Postcondition: data is a sorted array using Randomized Quick Sort Algorithm.
//
void randomizedQuickSort(int* data, int p, int r)
{
	int q;

	if (p < r)
	{
		q = randomizedPartition(data, p, r);
		randomizedQuickSort(data, p, q - 1); // LEFT recursion
		randomizedQuickSort(data, q + 1, r); // RIGHT recusriosn
	}
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// randomizedPartition:
//
// Precondition:  randomizedPartition() function takes an unsorted array with
//                n randomly generated elements.
// Postcondition: randomizedPartition() function return the index q, of the "pivot" element that
//                separates the two subarrays.
//                All values in first subarray <= All values in second subarray
// This randomizedPartition() function picks a random element in the array data as the pivot using
// the rand() function.
//
int  randomizedPartition(int* data, int p, int r)
{
	// Calculate how many elements between the range p-r.
	//
	int range = r - p + 1;

	// Assign a random seed value.
	//
	srand(time(NULL));

	// Calculate the random index which will indicate the element that will be placed at the
	// end of the array data and will be the random pivot.
	//
	int i = (rand() % range) + p;

	// Swap the last element of array data with the element indicated by the random index.
	//
	swap(data[r], data[i]);

	return partition(data, p, r);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// lsdRadixSort:
//
// Precondition:  data is an unsorted array with n randomly generated elements.
// Postcondition: data is a sorted array using LSD Radix Sort Algorithm.
//
void lsdRadixSort(int* data, int n)
{
	// First we need to find the highest-order digit d which is found by finding the maximum element
	// of the array data and then using the formula: floor(log_10(n))+1.
	//
	int max = findMaxElement(data, n);
	int d = floor(log10(max) + 1);

	//	Create the output/resulting array.
	//
	int* resultingArray = new int[n];

	for (int i = 0; i < d; ++i)
	{
		// The variable power is used in each iteration to divide the elements.
		// Dividing by a power of 10 shifts a value right.
		// For example: 321/10^0=321
		//              321/10^1=32
		//              321/10^2=3 
		//
		int power = pow(10, i);

		// Use a stable sort to sort array data on digit i.
		//
		countingSort(data, resultingArray, power, n);
	}
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// findMaxElement:
//
// Precondition:  data is an array with n randomly generated elements.
// Postcondition: find the maximum element of the array data.
//
int findMaxElement(int* data, int n)
{
	// Assume that the maximum element is the first element.
	//
	int maxElement = data[0];

	for (int i = 1; i < n; ++i) // visit all array elements
	{
		if (data[i] > maxElement)
		{
			maxElement = data[i]; // found a greater value, therefore assign it as maxValue
		}
	}

	return maxElement;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// countingSort:
//
// Precondition:  data is an unsorted array with n randomly generated elements.
// Postcondition: data is a sorted array using Countring Sort Algorithm.
//
void countingSort(int* data, int* resultingArray, int power, int n)
{
	// Create the array that will hold the occurences.
	//
	int* C = new int[10];
	for (int i = 0; i < 10; ++i) // Initialize array C with zeros
	{
		C[i] = 0;
	}

	for (int j = 0; j < n; ++j)
	{
		++C[(data[j]/power)%10]; // Modulo(%) by a power of 10 gets the right most digits.
	}
	// C[i] now contains the number of elements equal to i.
	//
	
	for (int i = 1; i < 10; ++i) // Create cumulative array C
	{
		C[i] = C[i] + C[i - 1];
	}
	// C[i] now contains the number of elements less than or equal to i.
	//
	for (int j = n - 1; j >= 0; --j) // Initialize array C with zeros
	{
		resultingArray[C[(data[j] / power) % 10]-1] = data[j];
		--C[(data[j] / power) % 10];
	}

	// Copy the elemenets of the output/resulting array back to the original array data.
	//
	for (int i = 0; i < n; ++i)
	{
		data[i] = resultingArray[i];
	}
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// printTable:
//
// Precondition:  compilerTime is an array storing the compiler times needed
//                for each Sorting Algorithm for each different input size N.
// Postcondition: prints the table with all the compiler times in microseconds.
//                Exception:(When N=1000000 the compiler time for Insertion Sort is in minutes.)
//
void printTable(int* compilerTime)
{
	cout << "*******************************************************************************************************" << endl;
	cout << "N" << "	|Insertion Sort|" << " |Merge Sort|" << " |Heap Sort|" << " |Quick Sort|"
		<< " |Randomized Quick Sort|" << " |LSD Radix Sort|" << endl;
	cout << "*******************************************************************************************************" << endl;
	cout << "10" << "	|" << compilerTime[0] << "|" << compilerTime[6] << "|" << compilerTime[12] << "|" << compilerTime[18] << "|" << compilerTime[24] << "|" << compilerTime[30] << endl;
	cout << "100" << "	|" << compilerTime[1] << "|" << compilerTime[7] << "|" << compilerTime[13] << "|" << compilerTime[19] << "|" << compilerTime[25] << "|" << compilerTime[31] << endl;
	cout << "1000" << "	|" << compilerTime[2] << "|" << compilerTime[8] << "|" << compilerTime[14] << "|" << compilerTime[20] << "|" << compilerTime[26] << "|" << compilerTime[32] << endl;
	cout << "10000" << "	|" << compilerTime[3] << "|" << compilerTime[9] << "|" << compilerTime[15] << "|" << compilerTime[21] << "|" << compilerTime[27] << "|" << compilerTime[33] << endl;
	cout << "100000" << "	|" << compilerTime[4] << "|" << compilerTime[10] << "|" << compilerTime[16] << "|" << compilerTime[22] << "|" << compilerTime[28] << "|" << compilerTime[34] << endl;
	cout << "1000000" << "	|" << compilerTime[5] << "|" << compilerTime[11] << "|" << compilerTime[17] << "|" << compilerTime[23] << "|" << compilerTime[29] << "|" << compilerTime[35] << endl;
	cout << "*******************************************************************************************************" << endl;
}