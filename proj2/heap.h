#ifndef HEAP_H
#define HEAP_H 

 
using namespace std;



typedef struct TAG_ELEMENT{
int key;

}ELEMENT;

typedef ELEMENT* ElementT;

typedef struct TAG_HEAP{
int capacity;  /* max size of the heap */
int size;      /* current size of the heap */
ElementT *H;  /* pointer to pointers to elements */
int *heap; 
}HEAP;

HEAP* heapInit(int capacity);
void heapPrint(HEAP *heap);
void buildHeap(HEAP *heap, int  f);
int Left (int i);
int Right (int i);
int parent (int i);
int ExtractMin(HEAP *heap, int f);
void minHeapify(HEAP *heap, int i);
void Insert(HEAP *heap, ElementT element);
void DecreaseKey(HEAP *heap, int n, int f);


#endif
