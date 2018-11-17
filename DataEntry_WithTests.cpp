// DataEntry_WithTests.cpp
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

// Data Storage Class #1
// Create a class to store the information relevant to the project.
// The class store a set of strings :
//
// Name the class DataEntry
//
//	ID(8 chars)
//	Parent ID(8 chars)
//	Event(1024 chars)
//	RHASH(8 chars)
//	LHASH(8 chars)
//
// In additional to the above string types, the class should
// also store two vectors LHISTH and RHISTH.
//
// Provide a general constructor for the class.
//
// Provide getters and setters for each item in the class.
// The getters and setters should be of the form :
//	void setParentId(string s);
//	string getParentId();

class DataEntry {
private:

	string ID		= "";
	string ParentID	= "";
	string Event	= ""; 
	string Rhash = "";
	string Lhash = "";
	vector<DataEntry> Lhist;
	vector<DataEntry> Rhist;

public:
	// Set Functions
	void setID(string s) {
		// Fixed length string of 8 characters (case insensitive)
		// Stores ONLY the first 8 characters
		ID = s.substr(0,8); 
	}
	void setParentID(string s) {
		// Fixed length string of 8 characters
		// Stores ONLY the first 8 characters
		ParentID = s.substr(0,8);
	}
	void setEvent(string s) {
		// Variable string length; Up to 1024 characters
		int MaxLength = 1024;
		// Stores ONLY the first MaxLength characters
		if (s.size() <= MaxLength) {	
			Event = s; 
		}
		else {
			cout << endl << endl << "Input Cut Down to " << MaxLength << " long..." << endl << endl;
			Event = s.substr(0, MaxLength);
		}
	}
	void setLhash(string s) {
		// Stores ONLY the first 8 characters
		Lhash = s.substr(0, 8);
	}
	void setRhash(string s) {
		// Stores ONLY the first 8 characters
		Rhash = s.substr(0,8);
	}
	void setLhist(DataEntry Node) {
		// Adds the particular Node to the Left History Vector
		Lhist.push_back(Node);
	}
	void setRhist(DataEntry Node) {
		// Adds the particular Node to the Right History Vector
		Rhist.push_back(Node);
	}

	// Get Functions
	string getID() {
		return ID;
	}
	string getParentID() {
		return ParentID;
	}
	string getEvent() {
		return Event;
	}
	string getLhash() {
		return Lhash;
	}
	string getRhash() {
		return Lhash;
	}
	vector<DataEntry> getLhist() {
		return Lhist;
	}
	vector<DataEntry> getRhist() {
		return Rhist;
	}

	// Print Functions
	// Prints everything BUT the history vectors
	void printTop() {
		cout << endl;
		cout << "ID:\t\t" << ID << endl;
		cout << "ParentID:\t" << ParentID << endl;
		cout << "Event:\t\t" << Event << endl;
		cout << "Lhash:\t\t" << Lhash << endl;
		cout << "Rhash:\t\t" << Lhash << endl;
	}
	// Prints Left history vector
	void printLhist() {
		cout << endl;

		if (Lhist.empty()) {
			cout << endl << "Lhist:\t\tEMPTY" << endl;
		}
		else {
			cout << "Lhist:" << endl;
			for (int i = 0; i < Lhist.size(); i++) {
				Lhist[i].printTop();
			}
		}
	}
	// Prints Right history vector
	void printRhist() {
		cout << endl;

		if (Rhist.empty()) {
			cout << endl << "Rhist is Empty" << endl;
		}
		else {
			cout << "Rhist:" << endl;
			for (int i = 0; i < Rhist.size(); i++) {
				Rhist[i].printTop();
			}
		}
	}

	// Empty?
	bool is_empty() {
		if (Event == "") {
			return true;
		}
		else {
			return false;
		}
	}

	// Constructors
	// I don't know if I have a good grasp on Constructors,
	// here is a default constructor, and some commented out code
	// for what I guess could be some other types?
	// I think how you implement you main code would determine how
	// many constructor types you would need beyond this.
	// Default:
	DataEntry() = default;
	// Event input:
	// DOES NOT update anything else, also is_empty() only checks "Event"
	// so unless you immediately set[variable name] all of the other stuff
	// then there could be a node that would not be completely initialized
	// not having ID's, Hashes, etc.
	//DataEntry(string s) {
	//	setEvent(s);
	//}
};



int main() {
	// The follow code test out the functions:
	// setID, setParentID, setEvent, setLhash, setRhash, setLhist, setRhist
	// getID, getParentID, getEvent, getLhash, getRhash, getLhist, getRhist
	// printTop, printLhist, printRhist, is_empty


	string Input = "123456789A123456789B123456789C";

	cout << endl << "Intial String: " << endl;
	cout << Input << endl << endl;


	cout << endl << "Creating New DataEntry: A" << endl;
	DataEntry A;

	cout << endl << "Is empty?: " << A.is_empty() << endl;

	cout << endl << "Printing New DataEntry Top information:" << endl;
	A.printTop();
	cout << endl << "Updating Top elements..." << endl;
	A.setID(Input);	
	A.setParentID(Input);	
	A.setEvent(Input);	
	A.setLhash(Input);
	A.setRhash(Input);
	A.printTop();

	cout << endl << "Is empty?: " << A.is_empty() << endl;

	A.printLhist();
	cout << endl << "Updating Lhist First Time..." << endl;
	A.setLhist(A);
	A.printLhist();
	cout << endl << "Updating Lhist Second Time..." << endl;
	A.setLhist(A);
	A.printLhist();

	A.printRhist();
	cout << endl << "Updating Rhist First Time..." << endl;
	A.setRhist(A);
	A.printRhist();
	cout << endl << "Updating Rhist Second Time..." << endl;
	A.setRhist(A);
	A.printRhist();

	cout << endl << "Creating New DataEntry: B" << endl;
	DataEntry(B);
	string BString = "Trololololololol";

	cout << endl << "Updating Top elements..." << endl;
	B.setID(BString);
	B.setParentID(BString);
	B.setEvent(BString);
	B.setLhash(BString);
	B.setRhash(BString);
	B.printTop();

	cout << endl << "Updating Rhist Third Time..." << endl;
	A.setRhist(B);
	A.printRhist();


	cout << endl << endl;
	system("pause");

	return 0;
}
