#include "SortAlgorithm.h"

// ---------------------------------
// BUBBLE SORT

void BubbleSort(vector<long long>& elements) {
    for(long long i = 0; i < elements.size() - 1; i++) {
        for(long long j = elements.size() - 1; j > i; j--) {
            if(elements[j] < elements[j - 1]) {
                swap(elements[j], elements[j - 1]);
            }
        }
    }
}

// ---------------------------------
//SELECTION SORT

void SelectionSort(vector<long long>& elements) {
    for(long long i = 0; i < elements.size() - 1; i++) {
        long long key = i;
        for(long long j = i + 1; j < elements.size(); j++) {
            if(elements[j] < elements[key]) {
                key = j;
            }
        }
        swap(elements[i], elements[key]);
    }
}

// ---------------------------------
// INSERTION SORT

void InsertionSort(vector<long long>& elements) {
    for(long long i = 1; i < elements.size(); i++) {
        long long j = i,
                  tmp = elements[i];

        while(j > 0 && tmp < elements[j - 1]) {
            elements[j] = elements[j - 1];
            j--;
        }

        elements[j] = tmp;
    }
}

// ---------------------------------
//QUICK SORT

void QuickSort(vector<long long>& elements, long long left, long long right) {
    long long i = left,
        j = right,
        key = elements[(left + right) / 2];

    while(i < j) {
        while(elements[i] < key) { i++; }
        while(elements[j] > key) { j--; }
        if(i <= j) {
            swap(elements[i], elements[j]);
            i++;
            j--;
        }
    }

    if(left < j) {
        QuickSort(elements, left, j);
    }
    if(i < right) {
        QuickSort(elements, i, right);
    }
}

// ---------------------------------
// HEAP SORT

void Shift(vector<long long>& elements, long long left, long long right) {
    long long i = left,
        j = 2*i + 1,
        key = elements[i];

    while(j <= right) {
        if(j < right) { if(elements[j] < elements[j + 1])  j++;  }

        if(elements[j] <= key) { return; }
        else {
            elements[i] = elements[j];
            elements[j] = key;
            i = j;
            j = 2*i + 1;
            key = elements[i];
        }
    }
}

void CreateHeap(vector<long long>& elements) {
    long long left = elements.size()/2 - 1;

    while(left >= 0) {
        Shift(elements, left, elements.size() - 1);
        left--;
    }
}

void HeapSort(vector<long long>& elements) {
    CreateHeap(elements);
    long long right = elements.size() - 1;

    while(right > 0) {
        swap(elements[0], elements[right]);
        right--;
        if(right > 0) {
            Shift(elements, 0, right);
        }
    }
}

// ---------------------------------
// MERGE SORT

void Merge(vector<long long>& elements, long long low, long long middle, long long high){
    long long size = elements.size();
    long long temp[size];
    for(long long i = low; i <= high; i++){
        temp[i] = elements[i];
    }
    long long i = low,
        j = middle + 1,
        k = low;

    while(i <= middle && j <= high){
        if(temp[i] <= temp[j]){
            elements[k] = temp[i];
            i++;
        }
        else {
            elements[k] = temp[j];
            j++;
        }
        k++;
    }
    while(i <= middle){
        elements[k] = temp[i];
        k++;
        i++;
    }
}

void MergeSort(vector<long long>& elements, long long low, long long high){
    if(low < high){
        long long middle = (low + high)/2;
        MergeSort(elements, low, middle);
        MergeSort(elements, middle + 1, high);
        Merge(elements, low, middle, high);
    }
}
