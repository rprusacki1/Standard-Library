#ifndef MINIQUEUE_H
#define MINIQUEUE_H

using namespace std;

template <class DataType>
class miniArrQueue {
	private:
		//For Array:
		DataType *arr; //array of items
		int capacity; //Size
		int front; //location of front
		int rear; //location of end
		int count; //size of queue

	public:
		miniArrQueue(); //constructor
		miniArrQueue(const miniArrQueue &); //copy
		~miniArrQueue(); //destructor
		int size () const; //return size
		bool isEmpty() const; //Check if empty
		void enqueue(const DataType &e);//Add to end
		void dequeue(); //Remove front
		const DataType& getfront() const; //returns front
		void printQueue () const; //Print from front to rear
		miniArrQueue<DataType>& operator=(const miniArrQueue<DataType>&);
		// Assignment operator
		
		//Bonus:
		friend ostream& operator << (ostream& os, const miniArrQueue<DataType>& q) {
			for (int i = 0; i < q.count; i++)
				os << q.arr[i] << "\n";
			os << "\n";

			return os;
		}
};
#include "miniDList.h"
template <class DataType>
class miniListQueue {
	private:
		//For lists:
		miniDList<DataType> list;

	public:
		miniListQueue(); //constructor
		miniListQueue(const miniListQueue &); //copy
		~miniListQueue(); //destructor
		int size () const; //return size
		bool isEmpty() const; //Check if empty
		void enqueue(const DataType &e);//Add to end
		void dequeue(); //Remove front
		const DataType& getfront() const; //returns front
		void printQueue () const; //Print from front to rear
		miniListQueue<DataType>& operator=(const miniListQueue<DataType>&);
		//Assignment operator
		//Bonus:
		friend ostream& operator << (ostream& os, const miniListQueue<DataType>& q) {
			os << q.list << "\n";
			return os;
		}
};

#include "miniQueue.cpp"

#endif
