#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void BubbleSort(vector<long long>& elements);

void SelectionSort(vector<long long>& elements);

void InsertionSort(vector<long long>& elements);

void QuickSort(vector<long long>& elements, long long left, long long right);

void Shift(vector<long long>& elements, long long left, long long right);
void CreateHeap(vector<long long>& elements);
void HeapSort(vector<long long>& elements);

void Merge(vector<long long>& elements, long long left, long long middle, long long right);
void MergeSort(vector<long long>& elements, long long left, long long right);
