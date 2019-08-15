#include <iostream>
#include <string>
#include <cctype>
using namespace std;


class student
{
	private:
		char* name;
		double gpa;
	public:
		student(char* newname=NULL, double g = 0)
		{
			name = new char[100];
			name=newname;
			gpa = g;
		}
		~student()
		{
			delete [] name;
		}
		void setname(char* x)
		{
			name = x;
		}
		void setgpa(double y)
		{
			gpa = y;
		}
		string getname()
		{
			string nam = name;
			return nam;
		}
		double getgpa()
		{
			double gp = gpa;
			return gp;
		}

};
void input(student *p, int size);
int main()
{
	student *p;
	int size;
	cout << "What would you like the size of your array to be?" << endl;
	cin >> size;
	p = new student[size];
	input(p, size);

	char ans=' ';
	while (ans != 'N' || 'n')
	{
		
		size = 0;
		cout << "\nWould you like to make another array? Enter y for yes or n for no." << endl;
		cin >> ans;
		while (ans != 'y' && ans != 'Y' && ans != 'N'&& ans != 'n')
		{
			cout << "Sorry invalid input, enter y for yes or n for no to answer the question. Try again." << endl;
			cin >> ans;
			cout << endl;
		}
		if (ans == 'n' || ans == 'N')
		{
			break;
		}
		cout << "What would you like the size of your new array to be?" << endl;
		cin >> size;
		p = new student[size];
		input(p, size);
		//delete p;
	}
	cout << "Exiting..." << endl;
	//system("pause");
	return 0;
}

void input(student *p, int size)
{
	char* names;
	double gpa;
	for (int i = 0; i<size; i++)
	{
		names = new char[100];
		cout << "Insert student name: ";
		cin >> names;
		cout << "Insert student gpa: ";
		cin >> gpa;
		while (gpa<0 || gpa>4.0)
		{
			cout << "Invalid GPA input. This school is on a 4.0 scale. Try again." << endl;
			cin >> gpa;
		}
		p[i].setname(names);
		p[i].setgpa(gpa);
	}
	//print array of students
	double sum = 0;
	for (int o = 0; o<size; o++)
	{
		cout << "The student named " << p[o].getname() << " has a gpa of " << p[o].getgpa() << endl;
		sum = sum + p[o].getgpa();
	}
	double avg;
	avg = sum / size;
	cout << "The average gpa of all your students is " << avg << endl;
}