//Sarnesh Arulnathan
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

#include "heap.h"
#include "util.h"




using namespace std;

int main () {

  char c; 
  int n = 0;
  int f = 0;

  int number;
   


  HEAP *heap;
  
 
  ElementT element;
  ifstream inFile;
  ofstream outFile;
  
  heap = NULL;
  

   
  while(1){
  
  c = nextCommand(&n, &f);
  
  	switch(c) {
  		case 's': 
  		case 'S': //forces the program to exit
  			exit(0);
  			
  		case 'c': 
  		case 'C': //creates a heap with capacity of user input
  			heap = heapInit(n);
  			break;

  		case 'r': 
  		case 'R': //opens HEAPinput to read and stores the integers in it in an ELEMENT
  			inFile.open("HEAPinput.txt");
  			
  			if(!inFile.is_open()) {
  				cout << "Error: cannot open file for reading" << endl;
				break;
  			
			  } else {
			  	inFile >> n;
			  	if((heap == NULL) ||( heap->capacity < n)){
			  		cout << "Error: heap overflow\n";				
				} else {
					for(int j = 1 ; j <=n; j++){	
						inFile>>number;
						element = (ElementT) malloc(sizeof(ELEMENT)); //dynamic allocation
						element->key=number;
						heap->H[j] = element;
						heap->size++;
					}
				}	
		         }
       			buildHeap(heap, f); //calls function to build a min heap on the array H			
			inFile.close();     //closes the file reader
			break; 

		case 'i': 
  		case 'I': //inserts an element in space pointed to by key 
			if((heap == NULL) ||( heap->capacity == heap->size)){
			  	cout << "Error: heap is NULL or full" << endl;				
			} else {
				element = (ElementT) malloc(sizeof(ELEMENT));
				element->key=n;
				Insert(heap, element);
			}
			break;

		case 'k': 
  		case 'K': //decreases the key of heap->H[index]  
			if((heap == NULL) ||(n < f) || (n > heap->size)){
			  	cout << "Error: invalid call to DecreaseKey" << endl;				
			} else {
				DecreaseKey(heap, n, f);
			}
			break;

		case 'd':
		case 'D': //removes the min number in the heap
			if (heap == NULL || heap->size == 0){
			cout << "Error: heap is NULL or empty" << endl;
			break;
			}
			ExtractMin(heap, f);		
			break; 	
			  
		case 'p': 
  		case 'P': //prints out the heap
  			if(heap == NULL){
  				cout << "Error: cannot print\n";
			}
			heapPrint(heap);
			break;
			
		case 'w': 
  		case 'W': //writes into the HEAPoutput file
  			outFile.open("HEAPoutput.txt");
  			
  			if(outFile.fail() || heap == NULL ) {
  				cout << "Error: cannot write" << endl;
  				break;
  			}
			
			outFile << heap->size << endl;
			
			for (int j = 1; j <= heap->size; j++){
				outFile << heap->H[j]->key << endl;
			} 
			
			outFile.close(); //closes file reader
			break;			
			
  			
	}
  
}
}
