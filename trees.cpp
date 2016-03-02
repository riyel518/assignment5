#include <iostream>
#include <fstream>
#include <string>
#include "trees.h"
#include <iomanip>
using namespace std;


void userMenu(trees& containers){

 btnode* insertNode;
 btnode* nodePosition;
 bool found;

 int insertValue,
	 deletedValue,
	 targetValue;

 char selected;

 do{        cout << endl;
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
						InOrdeDisplay(nodePosition, 0);
				}

				else{

						cout << "The value cannot be found " << endl;

				}

				break;

				default:

				cout << "The program will now end" << endl;

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


   do{
          cout << "Enter the file name: ";
          cin >> fileName;
          inputData.open(fileName.c_str());
         // inputData.seekg(0 , ios::end);

         // if(inputData.tellg() == 0){

            //  return false;

       //   }



     }while(!inputData.is_open());

      inputData >> insertData;

      insertNode = CreateNode(insertData);

      InsertNode(containers, insertNode);


       while(!inputData.eof()){

             inputData >> insertData;
             insertNode = CreateNode(insertData);
			 InsertNode(containers, insertNode);

          }

       inputData.close();

       return true;


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
           }

           else{

              current = current->right;
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

btnode *current;
btnode *trailCurrent;
bool found = false;

if(IsEmpty(containers)){

  cout << "Cannot delete on the empty tree" << endl;

} // end of if statement

else{
       current = containers.root;
       trailCurrent = containers.root;

       while(current != NULL && !found){

           if(current->data == targetValue){

               found = true;

           } // end of else statment

          else{

                trailCurrent = current;

                if (current->data > targetValue){

                    current = current->left;

                }// end if

                else{
                      current = current->right;

                } // end of else

          } //ed of else

       }// while loop

if(current == NULL){

   cout << "The delete item is not in the tree. " << endl;

}

else if (found){

  if(current == containers.root){
    deleteFromTree(containers.root);
  }
  else if(trailCurrent->data > targetValue){
    deleteFromTree(trailCurrent->left);
  }
  else{
    deleteFromTree(trailCurrent->right);
  }

  } // end of else if

} // end of function;

}
/**************************************************************
FUNCTION: deleteFromTree
DESCRIPTION: succesfully delete selected node from the tree
INPUT: N/A
OUTPUT: N/A
CALLS TO: N/A
implement: Chris Francisco
**************************************************************/

void deleteFromTree(btnode* deletedNode){

  btnode* current;
  btnode* trailCurrent;
  btnode* temp;

  if(deletedNode == NULL){
     cout << "Error: The node to be deleted is NULL." << endl;
  }

  else if (deletedNode->left == NULL & deletedNode->right == NULL){
     temp = deletedNode;
     deletedNode = NULL;
     delete temp;
  }

  else if (deletedNode->left == NULL){
      temp = deletedNode;
      deletedNode = temp->right;
      delete temp;
  }
  else if(deletedNode->right == NULL){
     temp = deletedNode;
     deletedNode = temp->left;
     delete temp;
  }

  else{

      current = deletedNode->left;
      trailCurrent = NULL;

      while(current->right != NULL){
        trailCurrent = current;
        current = current->right;

      }// end while loop

      deletedNode->data = current->data;

      if (trailCurrent == NULL){
          deletedNode->left = current->left;
      }
      else{
        trailCurrent->right = current->left;
      }

      delete current;

  } // end of else

} // end of function


/**************************************************************
FUNCTION: InOrdeDisplay
DESCRIPTION: displays all integers in the list in sorted order, using a
recursive, in-order traversal.
INPUT: N/A
OUTPUT: N/A
CALLS TO: N/A
implement: Chris Francisco
**************************************************************/

void InOrdeDisplay(btnode *noded, int counter){




   if (noded != NULL){

      counter ++;
      InOrdeDisplay(noded->left,  counter);

      if(counter != DISPLAY_LINE){

      cout << setw(TAB) << noded->data << " ";

     }

     else{
        
        cout << setw(TAB) << noded->data << " ";
     	cout << endl;
     	counter = 0;

     }


      InOrdeDisplay(noded->right,  counter);
   }



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

void FreeNodes(btnode *nodeToFree, btnode *nodeRetain){

btnode *temp;

  temp = nodeToFree;
  nodeToFree = nodeRetain;
  delete temp;

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

        destroy(treetoDestroy.root);
}

/**************************************************************
FUNCTION: destroy
DESCRIPTION: recursively destroy every single node in the tree
INPUT: N/A
OUTPUT: N/A
CALLS TO: N/A
implement: Chris Francisco
**************************************************************/

void destroy(btnode *toDestroy){

      if(toDestroy != NULL){

          destroy(toDestroy->left);
          destroy(toDestroy->right);
          delete toDestroy;
          toDestroy = NULL;

      }
}
