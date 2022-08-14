/* Rachel Prusacki
 * COSC220- 11/9/2021
 * Main to test Student datatype queues and stacks with arrays and lists
*/

#include <iostream>
#include <string>
#include "Student.h" //DataType

#include "miniStack.h" //Stacks
#include "miniQueue.h" //Queues

using namespace std;

int main () {
	//Test Queue- arrays
	miniArrQueue<Student> q1;
	miniArrQueue<Student> q2;
	
	//Test enqueue:
	Student s1 = Student (true);
	q1.enqueue(s1);
	cin.ignore();
	Student s2 = Student (true);
	q1.enqueue(s2);

	cout << "\nTesting Array-Queue:\n" << endl;	

	//Tests print():
	q1.printQueue();

	//Test isEmpty and size:
	if (q2.isEmpty())
		cout << "Empty: " << q2.size() << endl;

	//Tests getfront():
	cout << q1.getfront() << endl;

	//Tests dequeue and bonus:
	q1.dequeue();
	cout << q1;

	//Test Queue- lists
	cout << "\nTesting List-Queue:\n" << endl;
	miniListQueue<Student> q3;
	miniListQueue<Student> q4;

	//Test enqueue:
	q3.enqueue(s1);
	cin.ignore();
	q3.enqueue(s2);

	//Tests print():
	q3.printQueue();

	//Test isEmpty and size:
	if (q4.isEmpty())
		cout << "Empty: " << q4.size() << endl;

	//Tests getfront():
	cout << q3.getfront() << endl;

	//Tests dequeue and bonus:
	q3.dequeue();
	cout << q3;

	//Test Stack- arrays
	cout << "\nTesting Array-Stack:\n" << endl;
	//Tests constructor
	miniArrStack<Student> st1;
	miniArrStack<Student> st2;

	//Tests push and print:
	st1.push(s1);
	st1.push(s2);
	st1.printStack();

	//Tests isEmpty and size:
	if (st2.isEmpty())
		cout << "Empty: " << st2.size() << endl;

	//Tests front:
	cout << "Top: " << endl;
	cout << st1.front() << endl;

	//Tests pop and bonus:
	st1.pop();
	cout << st1;

	//Test Stack- lists
	cout << "\nTesting List-Stack:\n" << endl;
	//Tests constructor
	miniListStack<Student> ls1;
	miniListStack<Student> ls2;

	//Tests push and print:
	ls1.push(s1);
	ls1.push(s2);
	ls1.printStack();

	//Tests isEmpty and size:
	if (ls2.isEmpty())
		cout << "Empty: " << ls2.size() << endl;

	//Tests front:
	cout << "Top: " << endl;
	cout << ls1.front() << endl;

	//Tests pop and bonus:
	ls1.pop();
	cout << ls1;





	
	//YOU GOT THIS!!! Finish tests, i dont give a shit about throws,
	//type (make) to run shit, remove other test files, then you can print!

	return 0;
}
