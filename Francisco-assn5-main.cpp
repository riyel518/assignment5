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

	container = CreateTree();
    notEmpty = checkFile (container);

	//if(notEmpty){


	 roots = container.root;


	 cout << "Values stored in entire binary search tree are: " << endl;
	 InOrdeDisplay(roots, 0);
     cout << endl;
     DeleteNode(container, 9);
     InOrdeDisplay(roots, 0);
		
//	}

//	else{

//	cout << "Binary search tree is empty! " << endl;

//	}

    //userMenu(container);



	return 0;
}
