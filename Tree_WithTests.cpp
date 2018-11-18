// Tree_WithTests.cpp
// Final (GROUP) Project
// Last Updated:	11/17/2018
// Contributors:
// Jacob Tuttle		-	Project Leader	(Recursion/Code-Gluer)
// Jeremiah Vaskis	-	Project Member	(Class/Vector Work)
// Spencer Romberg	-	Project Member	(I/O & UI Work)

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <math.h> 
using std::pow;

// Implement an STD::Vector that will be used as
// a linear representation of a tree.
//
// The vector will be contained in the main() function
// of the program, but provide a set of functions as described below.
//
//	void expand(Vector<DataEntry> &data);
//
// This method should take the vector and duplicate the size.
// For the sake of implementation, assume that the vector is already
// full and that the only operation that must be performed is adding
// empty data elements so that the list doubles in size.

// This Class is ONLY FOR TESTING, see posted DataEntry cpp file for
// actual class implementation
class TestClass {
public:
	// Set Function
	void setEvent(string s) {
		// Only stores the first 1024 characters of string input
		Event = s.substr(0, 1024);
	}

	// Print function
	void print() {
		cout << endl << "Event: " << Event << endl;
	}
	
	// Empty function
	bool is_empty() {
		if (Event == "") {
			return true;
		}
		else {
			return false;
		}
	}

	// Default constructor
	TestClass() = default;
private:

	// Variable
	string Event = "";
};


void expand(vector<TestClass> &data) {
	// NOTE: DOES NOT care about indexing values but size
	// instead, as such the first Node WILL BE at index 0,
	// the second at 1, third at 2 and so on.

	// Without using this variable the for-loop freaks out
	int size = data.size();

	// Expands the given vector with a default (empty) Node
	// a specific number of times (current vector size + 1)
	// This will also work on a newly created
	for (int i = 0; i <= size; i++) {
		data.push_back(TestClass());
	}
}


bool is_full(vector<TestClass> &data) {
	// My best attempt to detect if the tree is full
	// by checking the last element using the "is_empty" function
	// which is USER MADE.  just check
	// "if (!Event == "")" and if so then it has been filled
	if (data.size() == 0) {
		return true;
	}
	else if (data.back().is_empty()) {
		return false;
	}
	else if (!(data.back().is_empty())) {
		return true;
	}
}

int main() {

	// Initial Example of expansion

	vector<TestClass> A;	// Create vector that takes TestClass elements
	cout << "A: Intialization Node Number:\t" << A.size() << endl;
	
	// Example of logical expansion of a binary tree level by level
	// by executing the "expand" function
	// In this case there IS NO CHECK if the last element of the tree
	// is empty or not, the above fuctions "is_empty" and "is_full"
	// are templates of functions that could be used to intelligently
	// trigger the use of the "expand" function ONLY when needed.
	
	// Creating a tree with 5 Total Levels
	for (int i = 1; i <= 5; i++) {
		cout << endl;
		cout << "A: Total Nodes Before expand:\t" << A.size() << endl;
		expand(A);
		cout << "A: Total Nodes After  expand:\t" << A.size() << endl;
		cout << "A: Total Nodes Added:\t\t" << pow(2, i-1) << endl;
	}


	// Example of intelligent expansion by detecting empty or full

	TestClass b;			// Create dummy TestClass element
	vector<TestClass> B;	// Create vector that takes TestClass elements
	cout << endl << "B: Intialization Node Number:\t" << B.size() << endl << endl;

	// Check if Tree B has NO NODES
	if (B.size()==0) {
		cout << "B: Total Nodes Before expand:\t" << B.size() << endl;
		expand(B);
		cout << "B: Total Nodes After  expand:\t" << B.size() << endl;
	}

	// Check if Tree Root is empty (Should be)
	if (B[0].is_empty()) {
		cout << endl << "B[0] is empty" << endl;
	}
	else {
		cout << endl << "B[0] is NOT empty" << endl;
	}

	// Check if Tree is full
	if (is_full(B)) {
		cout << "Tree is FULL" << endl;
		cout << "B: Total Nodes Before expand:\t" << B.size() << endl;
		expand(B);
		cout << "B: Total Nodes After  expand:\t" << B.size() << endl;
	}
	else {
		cout << endl << "Tree is NOT FULL" << endl;
	}

	// Put somthing into Tree Root (which since it is the only thing
	// that means the tree should be full now)
	b.setEvent("Trololololol");
	B[0] = b;

	// Check if Tree Root is empty again (Shouldn't be)
	if (B[0].is_empty()) {
		cout << endl << "B[0] is empty" << endl;
	}
	else {
		cout << endl << "B[0] is NOT empty" << endl << endl;
	}

	// Check if Tree is full
	if (is_full(B)) {
		cout << "Tree is FULL" << endl;
		cout << "B: Total Nodes Before expand:\t" << B.size() << endl;
		expand(B);
		cout << "B: Total Nodes After  expand:\t" << B.size() << endl;
	}
	else {
		cout << endl << "Tree is NOT FULL" << endl;
	}


	cout << endl;
	
	system("pause");
	return 0;
}