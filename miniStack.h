/*Rachel Prusacki, 11/9/2021
 * COSC220
 * H file of template functions for miniStack
 */
#ifndef MINISTACK_H
#define MINISTACK_H
#include <string>

using namespace std;

template <class DataType> 
class miniArrStack { 
	private: 
		//For Array:
		enum {DEF_CAPACITY =100};  //default stack capacity 
		DataType* arr; // The array of items 
		int capacity; // The size of the current array 
		int top; // The location of the top element 
		int count; //size of stack
	public: 
		miniArrStack (int cap= DEF_CAPACITY); // Constructor for ArrStack
		miniArrStack(const miniArrStack &);  // Copy contstructor 
		~miniArrStack(); // Destructor 
		int size()  const; // get the number of elements in the stack 
		bool isEmpty() const; // Check if the stack is empty 
		const DataType& front() const;       //get the top emement without popping it 
		void push(const DataType&); // Pushes  an  object  onto  the  stack 
		void pop(); // Pop an object off the stack  
		void printStack() const; // Prints the stack from the top, down
		miniArrStack<DataType>& operator=(const  miniArrStack<DataType>&);  //  Assignment  operator

		//Bonus:
		friend ostream& operator << (ostream& os, const miniArrStack<DataType>& q) {
			for (int i = q.top; i >= 0; i--)
				os << q.arr[i] << ", ";
			os << "\n";

			return os;
		}
}; 

#include "miniDList.h"
template <class DataType> 
class miniListStack { 
	private: 
		//For List:
		miniDList<DataType> list; 
	public:  
		miniListStack();        // Constructor for ListStack 
		miniListStack(const miniListStack &);  // Copy contstructor 
		~miniListStack(); // Destructor 
		int size()  const; // get the number of elements in the stack 
		bool isEmpty() const; // Check if the stack is empty 
		const DataType& front() const;       //get the top emement without popping it 
		void push(const DataType&); // Pushes  an  object  onto  the  stack 
		void pop(); // Pop an object off the stack  
		void printStack() const; // Prints the stack from the top, down
		miniListStack<DataType>& operator=(const  miniListStack<DataType>&);  //  Assignment  operator

		//Bonus:
		friend ostream& operator << (ostream& os, const miniListStack<DataType>& q) {
			os << q.list;
			return os;
		}
};

#include "miniStack.cpp" //for template instantiation
#endif
