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

		if (c == 'I' || c == 'i'){
			cin >> *n;
			break;
		}

		if (c == 'K' || c == 'k'){
			cin >> *n;
			cin >> *f;
			break;
		}

		if (c == 'D' || c == 'd'){
		cin >> *f;
		break;
		}
		
		if (c == 'R'|| c == 'r'){
		cin >> *f;
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
