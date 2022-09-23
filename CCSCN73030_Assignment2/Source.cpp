// Project V : Assignment 2
// Arun Kumar Thulaseedharan Pillai

// Header Files
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<sstream>

using namespace std;

// Defining PRE_RELEASE compiler Directive
#define PRE_RELEASE

// Creating Structure Student
typedef struct STUDENT_DATA {
	string FName;
	string LName;

	//Added Email ID for PRE_RELEASE functionality
#ifdef PRE_RELEASE
	string Email;
#endif // RELEASE

}Student;		// Defined as Student


// Vector Function to take in Filename and add Students through above struct to vector
std::vector<Student> ReadData(string Filename) {

	ifstream DataFile(Filename);	// Setting up File IO
	string line;
	Student S1;		// Struct Studnent Created

	vector<Student> Vec_Data;	// Initialiaing Loading vector as Vec_Data

	//checking to see if the file can be opened
	if (DataFile.is_open())		
	{
		// Till the last line, reading file
		while (getline(DataFile, line)) 
		{

			istringstream Data(line);	// Container Created to load line

			getline(Data, line, ',');	// Loading Coma Seperated values into Struct
			S1.LName = line;

			getline(Data, line, ',');
			S1.FName = line;

			// Case Created for PRE_RELEASE Email ID Load
#ifdef PRE_RELEASE
			getline(Data, line, ',');
			S1.Email = line;
#endif // RELEASE

			// Pusing Struct Student to Vector
			Vec_Data.push_back(S1);
		}
	}
	return Vec_Data;
}

int main() {

	// Status Message for Pre_Release Mode & Standard Mode
#ifdef PRE_RELEASE
	cout << "Pre Release Mode Running\n";
#else 
	cout << "Standard Mode Running\n";
#endif

	// Declaring Vector 
	vector<STUDENT_DATA> Vec_Data;

	Vec_Data
#ifdef PRE_RELEASE	// Pre_Release Condition
		= ReadData("StudentData_Emails.txt");

#else				// Standard Condition
		= ReadData("StudentData.txt");
#endif

#ifdef _DEBUG	// Standard Condition for printing
	for (int i = 0; i < Vec_Data.size(); i++)
	{
		cout << "Name : " << Vec_Data[i].FName << " " << Vec_Data[i].LName;

#ifdef PRE_RELEASE// Pre_Release Condition for printing
		cout << "\tEmail: " << Vec_Data[i].Email;
#endif
		cout << endl;
	}
#endif

// End

}