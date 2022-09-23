#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<sstream>



using namespace std;

//#define PRE_RELEASE

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







}