#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <string>

#include "heap.h"

using namespace std;

int counter;

HEAP *heapInit(int capacity){
	HEAP *heap;
	heap = (HEAP *)calloc(1, sizeof(HEAP)); //dynamic allocation
	heap->capacity = capacity;
	heap->size = 0;
	heap->H = (ElementT *)calloc(capacity+1, sizeof(ElementT)); //dynamic allocation
	return heap;
}

void heapPrint(HEAP *heap){
        cout << "capacity=" << heap->capacity << ", size=" << heap->size << endl;
        for(int i = 1; i <= heap->size; i++){
                if(i < heap->size){
                	cout << heap->H[i]->key << ", ";
                } else {
                        cout << heap->H[i]->key << endl;
                }
        }
		
}


void buildHeap(HEAP *heap, int  f){
	for (int i = heap->size / 2; i>=1; i--){
		minHeapify(heap, i);
		
	}
	if (f == 1){
		cout << "Number of Heapify calls: " << counter << endl;
	}

}

int parent(int i) 
{
	return (i-1)/2;
}

int Left(int i){
	return 2*i;	
}

int Right(int i){
	return 2*i + 1;
}

void minHeapify(HEAP *heap, int i) {
	int l = Left(i);
	int r = Right(i);
	int smallest;
	   
	if(l <= heap->size && heap->H[l]->key < heap->H[i]->key){
	smallest = l; 
	} else {
	smallest = i;
	}

	if(r <= heap->size && heap->H[r]->key < heap->H[smallest]->key){
	smallest = r;
	}
	
	if(smallest != i){
	swap(heap->H[smallest]-> key, heap->H[i]->key);
	minHeapify(heap, smallest);
	}
	counter++;
	
	
}	

int ExtractMin(HEAP *heap, int f){
	counter = 0;
	int min = heap->H[1]->key;
	heap->H[1] = heap->H[heap->size];
	heap->size--;
	minHeapify(heap, 1);
	cout << "Deleted key: " << min << endl;
	if (f == 1){
	cout << "Number of Heapify calls: " << counter << endl;
	}
	return min;
}

void Insert(HEAP *heap, ElementT element){
	heap->size++;
	int i = heap->size;
	heap->H[i] = element;
	buildHeap(heap, 0);
}

void DecreaseKey(HEAP *heap, int n, int f){
	heap->H[n]->key = f;
	buildHeap(heap,0);
}



	

		




 
