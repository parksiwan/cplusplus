#include <iostream>
#include <string>
using namespace std;

struct student {
	int grade;
	int studentID;
	string name;
};

class studentRecord {
public:
	studentRecord();
	studentRecord(int newGrade, int newID, string newName);
	int grade();
	void setGrade(int newGrade);
	int studentID();
	void setStudentID(int newID);
	string name();
	void setName(string newName);
	string letterGrade();
	bool isValidGrade(int grade);
private:
	int _grade;
	int _studentID;
	string _name;
};

bool studentRecord::isValidGrade(int grade) {
	if ((grade >= 0) && (grade <= 100))
		return true;
	else
		return false;
}

int studentRecord::studentID() {
	return _studentID;
}

int studentRecord::grade() {
	return _grade;
}

string studentRecord::name() {
	return _name;
}

void studentRecord::setGrade(int newGrade) {
	if (isValidGrade(newGrade))
		_grade = newGrade;
}

void studentRecord::setStudentID(int newID) {
	_studentID = newID;
}

void studentRecord::setName(string newName) {
	_name = newName;
}

studentRecord::studentRecord(int newGrade, int newID, string newName) {
	setGrade(newGrade);
	setStudentID(newID);
	setName(newName);
}

studentRecord::studentRecord() {
	setGrade(0);
	setStudentID(-1);
	setName("");
}

string studentRecord::letterGrade() {
	if (!isValidGrade(_grade))
		return "ERROR";

	const int NUMBER_CATEGORIES = 11;
	const string GRADE_LETTER[] = { "F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A" };
	const int LOWEST_GRADE_SCORE[] = { 0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93 };
	int category = 0;

	while (category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade)
		category++;
	return GRADE_LETTER[category - 1];
}

int main() {
	studentRecord a(23, 1001, "tom");

	cout << a.grade() << endl;
	cout << a.letterGrade() << endl;
	cout << a.studentID() << endl;
	cout << a.name() << endl;

	system("pause");
	return 0;
}
