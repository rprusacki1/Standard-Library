/*Rachel Prusacki, 11/8/2021
 * COSC220
 * Implementations of template functions for miniStack
 */

#include "miniStack.h"
#include <iostream>

using namespace std;

template <class DataType>
miniArrStack<DataType>::miniArrStack (int cap): capacity(cap) { // Constructor for ArrStack
	arr = new DataType[capacity];
	top = -1;
	count = 0;
} 

template <class DataType>
miniArrStack<DataType>::miniArrStack(const miniArrStack &r){  // Copy contstructor 
	r.arr = new DataType [capacity];
	r.capacity = capacity;
	r.top = top;
	r.count = count;
}

template <class DataType>
miniArrStack<DataType>::~miniArrStack(){ // Destructor 
	delete [] arr;
	capacity = 0;
	top = -1;
	count = 0;
}

template <class DataType>
int miniArrStack<DataType>:: size()  const{ // get the number of elements in the stack 
	return count;
}

template <class DataType>
bool miniArrStack<DataType>::isEmpty() const{ // Check if the stack is empty 
	if (top == -1)
		return true;
	else
		return false;
}

template <class DataType>
const DataType& miniArrStack<DataType>::front() const{       //get the top emement without popping it 
	if (isEmpty()) {
		cout << "Attempt to return front of empty stack" << endl;
		exit (EXIT_FAILURE);
	}
	return arr[top];
}

template <class DataType>
void miniArrStack<DataType>::push(const DataType& e){ // Pushes  an  object  onto  the  stack 
	if (count == capacity) {
		cout << "Stack is full" << endl;
		exit (EXIT_FAILURE);	
	}

	else {
		top++;
		arr[top] = e;
		count++;
	}
}

template <class DataType>
void miniArrStack<DataType>::pop(){ // Pop an object off the stack  
	if (isEmpty()) {
		cout << "Attempt to pop empty stack" << endl;
		exit (EXIT_FAILURE);
	}

	else {
		top--;
		count--;
	}
}

template <class DataType>
void miniArrStack<DataType>::printStack() const{ // Prints the stack from the top, down
	for (int i = top; i >= 0; i--)
		cout << arr[i] << ", ";
	cout << endl;
}

template <class DataType>
miniArrStack<DataType>& miniArrStack<DataType>::operator=(const miniArrStack<DataType> &r){  //  Assignment  operator
	capacity = r.capacity;
	count = r.count;
	top = r.top;
	for (int i = 0; i < count; i++)
		arr[i] = r.arr[i];

}

//Start of List:
template <class DataType>
miniListStack<DataType>::miniListStack(){        // Constructor for ListStack 
	miniDList<DataType> list;
}

template <class DataType>
miniListStack<DataType>::miniListStack(const miniListStack &l){  // Copy contstructor 
	list.miniDList(l);
}

template <class DataType>
miniListStack<DataType>::~miniListStack(){ // Destructor 
	list.~miniDList();

}

template <class DataType>
int miniListStack<DataType>::size()  const{ // get the number of elements in the stack 
	return list.size();
}

template <class DataType>
bool miniListStack<DataType>::isEmpty() const{ // Check if the stack is empty 
	if (list.size()==0)
		return true;
	return false;
}

template <class DataType>
const DataType& miniListStack<DataType>::front() const {       //get the top emement without popping it	
	return list.back();
}

template <class DataType>
void miniListStack<DataType>::push(const DataType &e){ // Pushes  an  object  onto  the  stack 
	list.addFront(e);
}

template <class DataType>
void miniListStack<DataType>::pop(){ // Pop an object off the stack  
	list.removeBack();
}

template <class DataType>
void miniListStack<DataType>::printStack() const{ // Prints the stack from the top, down
	list.display();
}

template <class DataType>
miniListStack<DataType>& miniListStack<DataType>::operator=(const miniListStack<DataType> &r){  //  Assignment  operator
	list = r.list;
}
