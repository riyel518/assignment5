#ifndef TREES_H_INCLUDED
#define TREES_H_INCLUDED
#include <fstream>
#include <string>

//node structure for binary trees

const int NO_FILE = 0;
const int DISPLAY_LINE = 10;
const int TAB = 3;
struct btnode{

     int data;
     btnode *left;
     btnode *right;

};

// the tree structure of binay trees
struct trees {

     btnode *root;
     int count;

};

//Function Prototype

void userMenu(trees& containers);

bool checkFile (trees& containers);

trees CreateTree();

bool IsEmpty(trees containers);

btnode* CreateNode(int payload);

void InsertNode(trees& containers, btnode* nodes);

btnode* FindNode(trees containers, bool& found, int targetValue);

void DeleteNode(trees& containers, int targetValue);

void deleteFromTree(btnode* deletedNode);

void InOrdeDisplay(btnode *noded, int counter);

void FreeNodes(btnode *nodeToFree, btnode *nodeRetain);

void DestroyTree(trees& treetoDestroy);

void destroy(btnode *toDestroy);


#endif
