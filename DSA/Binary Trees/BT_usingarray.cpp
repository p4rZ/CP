//Array implementation of BT
//also known as sequential implementations

#include<bits/stdc++.h>
//#include "node.h"
using namespace std;

// numbering starting from 0 to n-1. 
char tree[10]; 

//		left_son=(2*p)+1
//		right_son=(2*p)+2
int root(char key) 
{ 
	if(tree[0] != '\0') 
		cout << "Tree already had root"; 
	else
		tree[0] = key; 
	return 0; 
} 

int set_left(char key, int parent) 
{ 
	if(tree[parent] == '\0') 
		cout << "\nCan't set child at "
			<< (parent * 2) + 1 
			<< " , no parent found"; 
	else
		tree[(parent * 2) + 1] = key; 
	return 0; 
} 

int set_right(char key, int parent) 
{ 
	if(tree[parent] == '\0') 
		cout << "\nCan't set child at "
			<< (parent * 2) + 2 
			<< " , no parent found"; 
	else
		tree[(parent * 2) + 2] = key; 
	return 0; 
} 

int print_tree() 
{ 
	cout << "\n"; 
	for(int i = 0; i < 10; i++) 
	{ 
		if(tree[i] != '\0') 
			cout << tree[i]; 
		else
			cout << "-"; 
	} 
	return 0; 
} 

int main() 
{ 
	root('A'); 
	//insert_left('B',0); 
	set_right('C', 0); 
	set_left('D', 1); 
	set_right('E', 1); 
	set_right('F', 2); 
	print_tree(); 
	
	return 0; 
} 

