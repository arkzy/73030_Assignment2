#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<sstream>



using namespace std;

#define PRE_RELEASE

typedef struct STUDENT_DATA {
	string FName;
	string LName;
#ifdef PRE_RELEASE
	string Email;
#endif // RELEASE


}Student;



std::vector<Student> ReadData(string Filename) {

	ifstream DataFile(Filename);
	string line;
	Student S1;

	vector<Student> Vec_Data;

	if (DataFile.is_open())
	{

		while (getline(DataFile, line)) {

			istringstream Data(line);

			getline(Data, line, ',');
			S1.LName = line;

			getline(Data, line, ',');
			S1.FName = line;

#ifdef PRE_RELEASE
			getline(Data, line, ',');
			S1.Email = line;
#endif // RELEASE

			Vec_Data.push_back(S1);
		}

		/*for (int i = 0; i < Vec_Data.size(); i++) {
			cout << "Name : " << Vec_Data[i].FName << " " << Vec_Data[i].LName << endl;
		}*/
	}
	return Vec_Data;
}

int main() {

#ifdef PRE_RELEASE
	cout << "Pre Release Mode Running\n";
#else 
	cout << "Standard Mode Running\n";
#endif
	vector<STUDENT_DATA> Vec_Data;
	Vec_Data
#ifdef PRE_RELEASE
		= ReadData("C:\\Users\\arunp\\source\\repos\\CSCN73030_Lab2\\Resource Files\\StudentData_Emails.txt");

#else
		= ReadData("C:\\Users\\arunp\\source\\repos\\CSCN73030_Lab2\\Resource Files\\StudentData.txt");
#endif

#ifdef _DEBUG
	for (int i = 0; i < Vec_Data.size(); i++)
	{
		cout << "Name : " << Vec_Data[i].FName << " " << Vec_Data[i].LName;
#ifdef PRE_RELEASE
		cout << "\tEmail: " << Vec_Data[i].Email;
#endif
		cout << endl;
	}
#endif





}