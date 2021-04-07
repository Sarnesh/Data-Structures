
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

#include "heap.h"
#include "util.h"



using namespace std;

int main () {

  char c; 
  int n = 0, f;
  int number;
  

  HEAP *heap;
 
  ElementT element;
  ifstream inFile;
  ofstream outFile;
  
  heap = NULL;
  

  
  while(1){
  
  c = nextCommand(&n, &f);
  
  	switch(c) {
  		case's': 
  		case'S':
  			cout << "COMMAND: " << c;
  			exit(0);
  			
  		case'c': 
  		case'C':
  			cout << "COMMAND: " << c << " " << n << "\n";
  			heap = heapInit(n);
  			break;
  			
  		case'r': 
  		case'R':
  			cout << "COMMAND: " << c << "\n";
  			inFile.open("HEAPinput.txt");
  			
  			if(inFile.fail()) {
  				cout << "Error: cannot open file for reading" << endl;
  				break;
			  } else {
			  		inFile >> n;
			  			if(heap == NULL || heap->capacity < n){
			  				cout << "Error: heap overflow\n";
			  				break;
						  }
						for(int j = 1; j <=n; j++){	
						inFile>>number;
							element = (ElementT) malloc(sizeof(ELEMENT));
							element->key=number;
							heap->H[j] = element;
							heap->size++;
						}
						
					}
				inFile.close();
			    break; 
			  
			  
			  
		case'p': 
  		case'P':
  			cout << "COMMAND: " << c << "\n";
  				if(heap == NULL){
  					cout << "Error: heap is NULL\n";
				}
			heapPrint(heap);
			break;
			
		case'w': 
  		case'W':
  			cout << "COMMAND: " << c << "\n";
  			outFile.open("HEAPoutput.txt");
  			
  			if(outFile.fail()) {
  				cout << "Error: cannot open file for writing" << endl;
  				break;
  			}
  			if(heap == NULL){
  					cout << "Error: heap is NULL\n";
  					break;
			}
			
			outFile << heap->size;
			
			for (int j = 1; j <= heap->size; j++){
				outFile << heap->H[j]->key;
			} 
			
			outFile.close();
			
			
  			
	}
  
}
}
