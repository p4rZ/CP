#include <iostream> 
using namespace std; 

class Node { 
	public:
		int data; 
		Node* next; 
		Node(int data) 
		{ 
			this->data = data; 
			next = NULL; 
		} 
}; 

class LinkedList { 
	public:
		Node* head; 
		LinkedList() 
		{ 
			head = NULL; 
		} 
	
		Node* reverse(Node* node) 
		{ 
			if (node == NULL) 
				return NULL; 
			if (node->next == NULL) { 
				head = node; 
				return node; 
			} 
			Node* node1 = reverse(node->next); 
			node1->next = node; 
			node->next = NULL; 
			return node; 
		} 
	
		void print() 
		{ 
			Node* temp = head; 
			while (temp != NULL) { 
				cout << temp->data << " "; 
				temp = temp->next; 
			} 
		} 
	
		void push(int data) 
		{ 
			Node* temp = new Node(data); 
			temp->next = head; 
			head = temp; 
		} 
}; 

int main() 
{ 
	LinkedList ll; 
	for(int i=10;i>0;i--)
		ll.push(i*10);
	
	cout << "Given linked list\n"; 
	ll.print(); 

	ll.reverse(ll.head); 

	cout << "\nReversed Linked list \n"; 
	ll.print(); 
	return 0; 
} 

