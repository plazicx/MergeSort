// MergeSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <array>
#include <cstdlib>

void ispisi(int arr[], int n) {
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
		
	}
	std::cout << std::endl;
}
void QuickSort(int arr[], int l, int r)
{
	if (l < r){
		int count_L = 0;
		int count_R = 0;
		int * L = new int[r - l];
		int * R = new int[r - l];
		int pivot = arr[r];
		for (int i = l; i < r; ++i) {
			if (arr[i] < pivot) {
				L[count_L++] = arr[i];
			}
			else {
				R[count_R++] = arr[i];
			}
		}
		int k = l;
		int i, j;
		//ispisi(L,count_L);
		//ispisi(R,count_R);
		for (i = 0; i<count_L;++i) {
			//std::cout << i << " " << k << std::endl;
			arr[k] = L[i];
			k++;
		}
		
		arr[k] = pivot;
		k++;

		for (j = 0; j<count_R;++j) {
			arr[k] = R[j];
			k++;
		}
		delete[] L;
		delete[] R;

		QuickSort(arr, l, l + count_L-1); // has to be -1 for the pivot!
		QuickSort(arr, l + count_L + 1, r); // has to be +1 for the pivot!
	}
}


void Merge(int arr[], int l, int m, int r)
{
	//std::cout << "Merge sort called with " << l << " " << m << " " << r << std::endl;
	int n1 = m - l + 1;
	int n2 = r - m;
	
	int *L = new int[n1];
	int *R = new int[n2];
	int i, j, k;

	for (i=0;i<n1;++i)
	{
		L[i] = arr[l+i];
	}

	for (i = 0; i < n2; ++i) {
		R[i] = arr[m+i+1];
	}

	k = l;
	i = 0;
	j = 0;
	while (i < n1 && j < n2) {
		if (L[i] < R[j]) {
			arr[k] = L[i];
			++i;
			++k;
		}
		else {
			arr[k] = R[j];
			++j;
			++k;
		}
	}

	for (i; i < n1; ++i) {
		arr[k] = L[i];
		++k;
	}
	for (j; j < n2; ++j) {
		arr[k] = R[j];
		++k;
	}

	delete[] L;
	delete[] R;

}

void MergeSort(int arr[], int l, int r) 
{
	int m;
	if (l < r)
	{
		m = l + (r - l) / 2;
		MergeSort(arr, l,  m);
		MergeSort(arr, m + 1, r);

		Merge(arr, l, m, r);
	}
}


void Heapify(int arr[], int size, int node) {
	int child_1 = 2 * node + 1;
	int child_2 = 2 * node + 2;
	int swap_1 = 0;
	int swap_2 = 0;
	if (child_1<size && arr[child_1]>arr[node]) {
		int tmp = arr[node];
		arr[node] = arr[child_1];
		arr[child_1] = tmp;
		swap_1 = 1;
	}
	if (child_2<size && arr[child_2]>arr[node]) {
		if (swap_1 == 1) {
			int tmp = arr[node];
			arr[node] = arr[child_1];
			arr[child_1] = tmp;
			swap_1 = 0;
			tmp = arr[node];
			arr[node] = arr[child_2];
			arr[child_2] = tmp;
			swap_2 = 1;
		}
		else { // had a bug this was missing
			int tmp = arr[node];
			arr[node] = arr[child_2];
			arr[child_2] = tmp;
			swap_2 = 1;
		}
	}
	if (swap_1 == 1) {
		Heapify(arr, size, child_1);
	}
	if (swap_2 == 1) {
		Heapify(arr, size, child_2);
	}
}

void MaxHeap(int arr[], int size) {
	for (int i = size-1; i > -1; --i) {
		Heapify(arr, size, i);
	}
	
}
void draw_tree(int arr[], int size)
{
	std::cout << "Draw tree!!!! ----------------------" << std::endl;
	int count = 1;
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
		if ((i+2)%count == 0) {
			std::cout << std::endl;
			count*=2;
		}
		
	}
	std::cout << "-------------------------------------------" << std::endl;
}

void HeapSort(int arr[], int size) {
	//draw_tree(arr, size);
	MaxHeap(arr, size);
	//draw_tree(arr, size);
	int curr_size = size;
	for (int i = 0; i<size; ++i) {
		Heapify(arr, curr_size, 0);
		//std::cout << "curr_size " << curr_size << std::endl;
		int tmp = arr[0];
		arr[0] = arr[curr_size-1]; // curr_size i size - but the index of the last element of the array is curr_size - 1
		arr[curr_size-1] = tmp;
		--curr_size;
	}
}

int main()
{
	int n = 21;
	
	
	//int * arr0 = new int[n] { 41, 467, 334, 500, 169, 724, 478, 358, 962, 464, 705 };
	
	int * arr0 = new int[n];
	if (1) {
		
		for (int i = 0; i < n; ++i)
		{
			arr0[i] = rand() % 1000;
		}
	}
	

	int * arr = new int[n];

	for (int j = 0; j < 3; ++j) {
		
		
		for (int i = 0; i < n; ++i) {
			arr[i] = arr0[i];
		}

		std::cout << " Unsorted array ----------------------- " << std::endl;
		for (int i = 0; i < n; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;

		if (j == 0) {
			std::cout << "Merge sort -----------------------------------" << std::endl;
			MergeSort(arr, 0, n-1);
		}
		if (j==1){
			std::cout << "Quick sort -----------------------------------" << std::endl;
			QuickSort(arr, 0, n-1);
		}
		if (j == 2) {
			std::cout << "Heap sort -----------------------------------" << std::endl;
			HeapSort(arr, n);
		}

		//std::cout << "Hello World!\n";
		for (int i = 0; i < n; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}
	delete[] arr;
	delete[] arr0;
} 
//simple change 
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
