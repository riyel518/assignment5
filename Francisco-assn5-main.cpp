#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "trees.h"
using namespace std;

int main(){

	trees container;
	bool notEmpty;
	btnode *roots = NULL;
	int displayCounter;
	
	
	displayCounter = 0;

	container = CreateTree();
    notEmpty = checkFile (container);

	if(notEmpty){


	 roots = container.root;


	 cout << "Values stored in entire binary search tree are: " << endl;
	 InOrdeDisplay(roots, displayCounter);
     cout << endl;
		
	}

	else{

	cout << "Binary search tree is empty! " << endl;

	}

    userMenu(container);
    DestroyTree(container);
   

	return 0;
}
