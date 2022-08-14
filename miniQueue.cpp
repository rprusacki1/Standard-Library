/*Rachel Prusacki, 11/8/2021
 * COSC220
 * Implementations of template functions for miniQueue
 */

#include "miniQueue.h"
#include <iostream>

using namespace std;

template <class DataType>
miniArrQueue<DataType>::miniArrQueue() {
	arr = new DataType[20]; //For tests
	int capacity = 20; //For tests
	int front = 0;
	int rear = 0;
	count = 0;
}

template <class DataType>
miniArrQueue<DataType>::miniArrQueue(const miniArrQueue &r) {
	r.arr = new int [capacity];
	r.capacity = capacity;
	r.front = front;
	r.rear = rear;
	r.count = count;
}

template <class DataType>
miniArrQueue<DataType>::~miniArrQueue() {
	delete[] arr;
	capacity = 0;
	front = 0;
	rear = 0;
	count = 0;
}

template <class DataType>
int miniArrQueue<DataType>::size () const {
	return count;
}

template <class DataType>
bool miniArrQueue<DataType>:: isEmpty() const {
	if (front == 0)
		return true;
	else
		return false;
}

template <class DataType>
void miniArrQueue<DataType>::enqueue(const DataType &e) {
	if (count == capacity) {
		cout << "Queue is full." << endl;
		exit (EXIT_FAILURE);
	}

	else {
		arr[count] = e;
		count++;
	}
}

template <class DataType>
void miniArrQueue<DataType>::dequeue() {
	if (isEmpty()) {
		cout << "Queue is empty" << endl;
		exit (EXIT_FAILURE);
	}

	else {
		for (int i = 0; i < count-1; i++) {
			arr[i] = arr[i+1];
		}
		rear--;
		count--;
	}
}

template <class DataType>
const DataType& miniArrQueue<DataType>::getfront() const {
	if (isEmpty()) {
		cout << "Queue is empty, cannot return" << endl;
		exit (EXIT_FAILURE);
	}

	return arr[0];
}

template <class DataType>
void miniArrQueue<DataType>:: printQueue() const {
	for (int i = 0; i < count; i++)
		cout << arr[i] << endl;

	cout << endl;

}

template <class DataType>
miniArrQueue<DataType>& miniArrQueue<DataType>::operator=(const miniArrQueue<DataType>&r) {
	capacity = r.capacity;
	count = r.count;
	front = r.front;
	rear = r.rear;
	for (int i = 0; i < count; i++) //Goes through and matches all values
		arr[i]= r.arr[i];	
}

//Start of miniList implementation:
template <class DataType>
miniListQueue<DataType>::miniListQueue() {
	miniDList<DataType> list;
}

template <class DataType>
miniListQueue<DataType>::miniListQueue(const miniListQueue &l) {
	list.miniDList(l);
}

template <class DataType>
miniListQueue<DataType>::~miniListQueue() {
	list.~miniDList();
}

template <class DataType>
int miniListQueue<DataType>::size () const {
	return list.size();
}

template <class DataType>
bool miniListQueue<DataType>::isEmpty() const {
	if (list.size() == 0)
		return true;
	return false;
}

template <class DataType>
void miniListQueue<DataType>::enqueue(const DataType &e) {
	list.addBack(e);
}

template <class DataType>
void miniListQueue<DataType>::dequeue() {
	list.removeFront();
}

template <class DataType>
const DataType& miniListQueue<DataType>::getfront() const {
	return list.front();
}

template <class DataType>
void miniListQueue<DataType>::printQueue() const {
	list.display();
}

template <class DataType>
miniListQueue<DataType>& miniListQueue<DataType>::operator=(const miniListQueue<DataType>&r) {	
	list = r.list;
}
