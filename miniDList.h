/* Rachel Prusacki, 10/21/2020
 * COSC220
 * miniDList header file
 */

#ifndef MINIDLIST_H
#define MINIDLIST_H

using namespace std;

template <class DataType>  
class miniDList{ 
  private: 
	struct DNode{ // doubly linked list node 
		DataType data; //  data stored in node    
		DNode* next; //  next node in list    
		DNode* prev; //  previous node  in list 

		DNode() { //Constructor
			next = this;
			prev = this;
		}
		DNode(DataType d) { //Constructor with type
			data = d;
			next = this;
			prev = this;
		}
	}; 
		 
	DNode* header; // list sentinels 
	DNode* trailer;
	int listsize; //size of list
		  
  public: 

	miniDList(); //Constructor
	miniDList(const miniDList& l); // Copy constructor 
	~miniDList(); // Destructor 
	const DataType& front() const;      // get front element 
	const DataType& back() const;       // get back element 
	void removeFront(); // Remove & return the front  
	void removeBack();             // Remove & return the back  
	void addFront(const DataType& e);       // Add to the front  
	void addBack(const DataType& e);           // Add to the back 
	int size() const; // Returns the number of elements in list 
	bool contains(const DataType& e);   // Tests for membership 
	void display() const; // Prints the elements of list 
	miniDList<DataType>& operator=(const miniDList<DataType>& l);   
	//Overloaded assignment 
	
	//Bonus:
	friend ostream& operator << (ostream& os, const miniDList<DataType>& l) {
		DNode *curr = l.header;
		if (l.header == nullptr)
			os << "List is empty\n";
		else {
			while (curr != nullptr) {
			  os << curr -> data << ", ";
			  curr = curr -> next;
			}
			os << "\n";
		}
		return os;
	}

	DataType operator [] (int x);
	void sort();

  protected:                          //local utilities 
	void add(DNode * v, const DataType& e); //insert new node  before  v 
	void remove(DNode* v);     //remove node v 
}; 

#include "miniDList.cpp"    //for template instantiation

#endif //MINIDLIST_H
