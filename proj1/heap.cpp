#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <string>

#include "heap.h"

using namespace std;

HEAP *heapInit(int capacity){
	HEAP *heap;
	heap = (HEAP *)calloc(1, sizeof(HEAP));
	heap->capacity = capacity;
	heap->size = 0;
	
	
	heap->H = (ElementT *)calloc(capacity+1, sizeof(ElementT));
	return heap;
}

void heapPrint(HEAP *heap){
        cout << "capacity=" << heap->capacity << ", size=" << heap->size << endl;
        for(int i = 1; i <= heap->size; i++){
                if(i < heap->size){
                        cout << heap->H[i]->key << ", ";
                }
                else {
                        cout << heap->H[i]->key << endl;
                }
        }


}

 
