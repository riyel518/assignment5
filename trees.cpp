#include <iostream>
#include <fstream>
#include <string>
#include "trees.h"
#include <iomanip>
using namespace std;


void userMenu(trees& containers){

int displayCounter = 0;
 btnode* insertNode = NULL;
 btnode* nodePosition = NULL;
 bool found;

 int insertValue,
	 deletedValue,
	 targetValue;

 char selected;

 do{        cout << endl;
 			cout << "--------------------------------" << endl;
	        cout << "Choose on the following option: " << endl;
			cout << "I = Insert an integer" << endl;
			cout << "D = Delete an Interge" << endl;
			cout << "F = Find an Integer" << endl;
			cout << "--------------------------------" << endl << endl;
			cout << "Enter your choice or 'E' to exit: ";
			cin >> selected;

			switch (selected) {
				case 'I':

        cout << "Enter the integer to be inserted: ";
				cin >> insertValue;

				insertNode = CreateNode(insertValue);

				InsertNode(containers, insertNode);

				break;

				case 'D':

				cout << "Enter the integer to be deleted: ";
				cin >> deletedValue;
				DeleteNode(containers, deletedValue);

				break;

				case 'F':

				cout << "Enter the integer to be search: ";
				cin >> targetValue;
				
				nodePosition = FindNode(containers, found,  targetValue );
	            
				if(found){
 						cout << "Values Stored subtree with root " << nodePosition->data << " are: " << endl;
						InOrdeDisplay(nodePosition, displayCounter);
				}

				else{
                        cout << endl;
						cout << "Error: The value cannot be found!" << endl;
						break;
				}

				break;

				case 'E':
				 cout << "Exiting the program!.. " << endl;	
				
				break;
				
				default:

				cout << "Error: Invalid Input" << endl;

				break;
			}


		 }while(selected != 'E');




}

/**************************************************************
FUNCTION: CreateTree
DESCRIPTION: Allocate a binary search tree structure, and
initialize the root pointer in it  to NULL and the count to 0,
to indicate an empty tree.
INPUT: N/A
OUTPUT: N/A
CALLS TO: N/A
implement: Chris Francisco
**************************************************************/

bool checkFile (trees& containers){

    ifstream inputData;
    string fileName;
    int fileLenght;
    btnode* insertNode;
    int insertData;
    int noContent;
    noContent = 0;

   do{
          cout << "Enter the file name: ";
          cin >> fileName;
          inputData.open(fileName.c_str());
     

     }while(!inputData.is_open());

      inputData >> insertData;

      insertNode = CreateNode(insertData);

      InsertNode(containers, insertNode);


       while(!inputData.eof()){
             
             noContent++;
             inputData >> insertData;
             insertNode = CreateNode(insertData);
			 InsertNode(containers, insertNode);

          }

       inputData.close();
 
       if(noContent == 0){
       	
       	 return false;
       	
       }
      
      else{
      	
      
       return true;

     }
}


/**************************************************************
FUNCTION: CreateTree
DESCRIPTION: Allocate a binary search tree structure, and
initialize the root pointer in it  to NULL and the count to 0,
to indicate an empty tree.
INPUT: N/A
OUTPUT: N/A
CALLS TO: N/A
implement: Chris Francisco
**************************************************************/

trees CreateTree(){

    trees newtree;

    newtree.root = NULL;
    newtree.count = 0;

    return newtree;



}

/**************************************************************
FUNCTION: IsEmpty
DESCRIPTION: Check to verify if tree is empty
INPUT: N/A
OUTPUT: N/A
CALLS TO: N/A
implement: Chris Francisco
**************************************************************/

bool IsEmpty(trees containers){

   return(containers.root == NULL);

}


/**************************************************************
FUNCTION: CreateNode
DESCRIPTION: allocate and fills new node. Passes back pointer to new node,
or NULL if node could not be allocated
INPUT: N/A
OUTPUT: N/A
CALLS TO: N/A
implement: Chris Francisco
**************************************************************/

btnode* CreateNode(int payload){


      btnode *newNode = new (nothrow) btnode();

      newNode->data = payload;
      newNode->right = NULL;
      newNode->left = NULL;



      return newNode;


}

/**************************************************************
FUNCTION: InsertNode
DESCRIPTION: inserts a new node into the correct location within
a binary search tree
INPUT: N/A
OUTPUT: N/A
CALLS TO: N/A
implement: Chris Francisco
**************************************************************/

void InsertNode(trees& containers, btnode* nodes){

 btnode *current;
 btnode *trailCurrent;
 int insertItem;

 insertItem = nodes->data;  //extrct the data

 if(containers.root == NULL){

    containers.root = nodes;
	containers.count++;

 } // end of if

else{

    current = containers.root;

    while(current != NULL){

     trailCurrent = current;

        if(current->data == insertItem){

            cout << "Error: " <<insertItem<< " is found and will not insert into the tree" << endl;
            return;
        } // end of else

        else if (current->data > insertItem){

             current = current->left;
        } // end of else if

        else{

            current = current->right;
        } // end of else
    }// END OF WHILE LOOP

    if (trailCurrent->data > insertItem){
        trailCurrent->left = nodes;
        containers.count++;
    } // end of if

    else{
          trailCurrent->right = nodes;
          containers.count++;

    } // end of else


}// END OF ELSE


}// end of function

/**************************************************************
FUNCTION: FindNode
DESCRIPTION: searches for a value within a binary search tree.
INPUT: N/A
OUTPUT: N/A
CALLS TO: N/A
implement: Chris Francisco
**************************************************************/

btnode* FindNode(trees containers, bool& found, int targetValue){

 btnode* foundNode = NULL;
 btnode* current;
 found = false;

if(IsEmpty(containers)){

  cout << "Cannot search on the empty tree" << endl;

} // end of if statement

else{
       current = containers.root;

       while(current != NULL && !found){

           if(current->data == targetValue){

               found = true;
               foundNode = current;
           }

           else if (current->data > targetValue){

                current = current->left;
                foundNode = current;
           }

           else{

              current = current->right;
              foundNode = current;
           }

       }// while loop

     
      
  } // end of else

return foundNode;

} // end of search function






/**************************************************************
FUNCTION: DeleteNode
DESCRIPTION: deletes a node from the binary search tree.
INPUT: N/A
OUTPUT: N/A
CALLS TO: N/A
implement: Chris Francisco
**************************************************************/

void DeleteNode(trees& containers, int targetValue){

bool isFound;

btnode *deleteTemp = NULL;
btnode *foundTemp;
btnode *current = NULL;
btnode *trailCurrent;



if(containers.root == NULL){

    cout << "Cannot delete on the empty tree" << endl;

}

else{

foundTemp  = FindNode(containers, isFound, targetValue);

if(isFound){

     if ((foundTemp->left == NULL) && (foundTemp->right == NULL) ){
		  
		
             delete foundTemp;
             foundTemp = NULL;
          
     } // end else

    else if (foundTemp->left == NULL) {

          
		   deleteTemp = foundTemp;
           foundTemp = foundTemp->right;    
           delete deleteTemp;
           deleteTemp = NULL;
           


    } // end of else if

    else if (foundTemp-> right == NULL){

		
 		   deleteTemp = foundTemp;
           foundTemp = foundTemp->left;       
           delete deleteTemp;
           deleteTemp = NULL;
      


    } // end of else if

    else{
    	
    	
    	
    	     current = foundTemp->left;
    	     trailCurrent = NULL;
    	     
    	     while(current->right != NULL){
    	     	  
    	     	 trailCurrent = current;
    	     	 current = current->right;
    	     	
    	     } // end while
    	     
    	     foundTemp->data = current->data;
    	     
    	     if(trailCurrent == NULL){
    	     	
    	     	foundTemp->left = current->left;
    	     	
    	     }
    	     
    	     else{
    	     	
    	     	trailCurrent->right = current->left;
    	     }
			
			FreeNodes(current); 
			delete current;
			current = NULL;
			
    } // end of else 
}

else{

    cout << "Msg: The delete item is not in the tree!" << endl;

    }

  }

}

/**************************************************************
FUNCTION: InOrdeDisplay
DESCRIPTION: displays all integers in the list in sorted order, using a
recursive, in-order traversal.
INPUT: N/A
OUTPUT: N/A
CALLS TO: N/A
implement: Chris Francisco
**************************************************************/

void InOrdeDisplay(btnode *noded, int& counter){
 


 		if(noded != NULL){
 			
 			InOrdeDisplay(noded->left, counter);
 			
 			if(counter < DISPLAY_LINE){
 			
 			
 			cout << setw(TAB) << noded->data << " ";
 			counter++;
 			
 		    }
 		   
 		    else{
 		    
 		      
 		      cout << setw(TAB) << noded->data << " ";
			  cout << endl;	
 		      counter = 0;
 		    
 	      	}
 			
 			InOrdeDisplay(noded->right, counter);
 		
 			
 		}



  
  }
  






/**************************************************************
FUNCTION: DestroyTree
DESCRIPTION: deallocate all dynamic memory allocated for the
binary search tree
INPUT: N/A
OUTPUT: N/A
CALLS TO: destroy()
implement: Chris Francisco
**************************************************************/

void DestroyTree(trees& treetoDestroy){

        FreeNodes(treetoDestroy.root);
        
}

/**************************************************************
FUNCTION: FreeNodes
DESCRIPTION: recursively deallocates all dynamic memory allocated
to nodes in the binary search tree
INPUT: N/A
OUTPUT: N/A
CALLS TO: N/A
implement: Chris Francisco
**************************************************************/

void FreeNodes(btnode *toDestroy){

      if(toDestroy != NULL){
         
          
          FreeNodes(toDestroy->left);
          FreeNodes(toDestroy->right);
          delete toDestroy;
          toDestroy = NULL;

      }
}
