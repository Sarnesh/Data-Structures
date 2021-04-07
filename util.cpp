#include <iostream>
#include "util.h"

using namespace std;

int nextCommand(int *n, int *f){
	char c;
	

	
	while(1) {
		cin >> c;
	
		if (c == ' '|| c == '\t'|| c == '\n'){
			continue;
		}
	
		if (c == 'S'|| c == 's'){
		break;
		}
		
		if (c == 'C' || c == 'c'){
			cin >> *n;
			break;
		}
		
		if (c == 'R'|| c == 'r'){
		break;
		}
		
		if (c == 'P'|| c == 'p'){
		break;
		}
		
		if (c == 'W'|| c == 'w'){
		break;
		}
	}
	return c;
}
