/*Rachel Prusacki, 10/21/2021
 * COSC220
 * Implementations of template functions for miniDList
 */

#include "miniDList.h"
#include <iostream>

using namespace std;

template <class DataType>
miniDList<DataType>::miniDList() { //Constructor             
	header = nullptr;
	trailer = nullptr;
	listsize = 0;

}

template <class DataType>
miniDList<DataType>::miniDList (const miniDList& l) { 
  // Copy constructor
  DNode *curr = l.header; //To move through nodes

  //Create new list
  header = new DNode;
  if (header == nullptr)
	  cout << "Error" << endl;

  //Insert values
  while (curr != trailer) {
	 add(header, curr->data);
	 curr = curr -> next;
  }
  add(header, trailer->data); //adds last element

}
	
template <class DataType>
miniDList<DataType>::~miniDList() { // Destructor
	DNode * curr = header;

	//Erase the list
	while (curr != nullptr) {
		DNode *prev = curr;
		curr = curr -> next;
		delete prev;
	}
	
	header = trailer = nullptr;
	listsize = 0;

}

template <class DataType>
const DataType& miniDList<DataType>::front() const { // get front element
	//If empty
	if (!header)
		cout << "Error" << endl;
	else //Otherwise
		return header -> data;
}

template <class DataType>
const DataType& miniDList<DataType>::back() const { // get back element
	//If empty
	if (!header || !trailer)
		cout << "Error" << endl;
	else //Otherwise
		return trailer -> data;

}
	
template <class DataType>
void miniDList<DataType>::removeFront() { // Remove & return the front
	//If list is empty
	if (!header) {
		cout << "List is empty" << endl;
		return;
	}

	else {
		header = header -> next;
		delete (header->prev);
		listsize--;
	}
}

template <class DataType>
void miniDList<DataType>::removeBack() { // Remove & return the back
	//If list is empty
	if (!header) {
		cout << "List is empty" << endl;
		return;
	}

	else {
		DNode * temp = trailer->prev;
		temp -> next = nullptr;
		delete trailer;
		trailer = temp;
		listsize--;
	}
}

template <class DataType>
void miniDList<DataType>::addFront(const DataType& e) { // Add to the front
	listsize++;
	DNode * node = new DNode(e);
	node->next = nullptr;
	node->prev = nullptr;
	
	if (header == nullptr) //if empty
		header = node;

	else if (trailer == nullptr) { //One element
		trailer = header;
		header = node;
		header -> next = trailer;
		trailer -> prev = header;
	}

	else {
		node->next = header;
		header->prev = node;
		header = node;
	}
	
}

template <class DataType>
void miniDList<DataType>::addBack(const DataType& e) { // Add to the back
	listsize++;
	DNode * node = new DNode(e);
	node->next = nullptr;
	if (header == nullptr) //Empty
		header = node;

	else if (trailer == nullptr) { //One element
		trailer = node;
		trailer -> prev = header;
		header -> next = trailer;
	}

	else { //Two or more
		trailer->next = node;
		node->prev = trailer;
		trailer = node;
	}
}

template <class DataType>
int miniDList<DataType>::size() const{ // Returns the number of elements in lis
	return listsize;

}

template <class DataType>
bool miniDList<DataType>::contains(const DataType& e) { // Tests for membership
	DNode *curr = header;

	//If empty
	if (header == nullptr)
		cout << "List is empty" << endl;

	//1 Element and first for case 3
	if (header -> data == e)
		return true;

	//Otherwise
	else {
		while (curr != nullptr) {
			if (curr -> data == e)
				return true;
			curr = curr -> next;
		}
	}

	return false;
}

template <class DataType>
void miniDList<DataType>::display() const { // Prints the elements of list
	DNode *curr = header;

	//If empty
	if (header == nullptr)
		cout << "List is empty" << endl;

	else { //Two or more
		while (curr != nullptr) {
			cout << curr -> data << ", ";
			curr = curr -> next;
		}
		cout << endl;
	}

}

template <class DataType>
miniDList<DataType>& miniDList<DataType>::operator=(const miniDList& l) { 
	//Overloaded
	DNode *curr = l.header;
	//If user assigns it to itself
	if (this == &l)
		return *this;

	//Erase current list
	
	listsize = l.listsize;
	while (header != nullptr) {
		DNode * prev = header;
		header = header -> next;
		delete prev;
	}
	header = trailer = nullptr;
	
	//Insert new elements
	while (curr != nullptr) {
		addBack(curr -> data);
		curr = curr -> next;
	}

	return *this;
}

//Bonus:
template <class DataType>
DataType miniDList<DataType>::operator[](int x) {
	DNode * curr = header;
	if (x >= listsize || x < 0) {
		cout << "Index out of bounds: ";
		return -1;
	}

	else {
		for (int i = 0; i < x; i++)
			curr = curr -> next;
		DataType t = curr -> data;
		return t;
	}
}

//Bonus:
template <class DataType>
void miniDList<DataType>::sort() {
	DNode * curr = header;
	DNode * temp;
	DataType d;

	if (header == nullptr) //if empty
		return;
	else {
		while (curr != nullptr) { //Moves through whole list
		  temp = curr -> next;
		  while (temp != nullptr) { //Moves curr
		    if (curr -> data > temp -> data) { //Moves curr to new location
		      d = curr -> data;
		      curr -> data = temp -> data;
		      temp -> data = d;
		    }
		    temp = temp -> next;
	  	  }	    
		  curr = curr -> next;
		}
	}
	//Works by swapping data instead of node position
}

//Private functions:

template <class DataType>
void miniDList<DataType>::add(DNode * v, const DataType& e) { 
	//insert new node before v
	//Create new node
	DNode *newNode = new DNode(e);

	//Insert before
	newNode->prev = v -> prev;
	newNode->next = v;
	v->prev->next = newNode;
	v->prev = newNode;
}
	
template <class DataType>
void miniDList<DataType>::remove(DNode * v) { //remove node v
	v->prev->next = v->next;
	v->next->prev = v->prev;

	delete v;
}
