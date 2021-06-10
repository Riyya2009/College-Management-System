//============================================================================
// Name        : Honors.cpp
// Author      : Riyya Ahmed
// Version     : Eclipse
// Copyright   :
// Description : College Management system
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;
#include <fstream>
#include <vector>

class Person {
private:
	string name;
	int SSN;
public:
	Person(){name = " ";SSN = 0;};
	Person(string n, int s){name = n;SSN = s;};
	void setName(string a){name = a;};
	void setSSN(int s){SSN = s;};
	string getName(){return name;};
	int getSSN(){return SSN;};
	void print()
	{cout << "Name is: " << name << endl;cout << "SSN is: " << SSN << endl;}
};

class Employee : public Person
{
private:
	double salary;
	string field;  //describes what sector the employees and staff belong to in the college
public:
	Employee() : Person()
	{salary = 0.0;field = " ";}
	Employee(string , int , double , string ) ;
	void setSalary(double s){salary = s;};
	void setField(string f){field = f;};
	float getSalary(){return salary;};
	string getField(){return field;};
	void print()
	{Person::print(); cout << "Salary: $" << salary << endl;cout << "Field is: " << field<< endl;}
};

class Student : public Person
{
private:
	double GPA;
	string major;
public:
	Student() : Person(){GPA = 0.0;major = " ";};
	Student(string n, int s, double g, string m);
	void setGPA(double g){GPA = g;};
	void setMajor(string m){major = m;};
	double getGPA(){return GPA;};
	string getMajor(){return major;};
	void print()
	{Person::print(); cout << "GPA: " << GPA <<endl;cout << "Major is: "<< major<< endl;}
};

class Grad :public Student
{
private:
	string goal;
	int year; //>4
public:
	Grad() : Student()
	{goal = ""; year = 5;}
	Grad(string n, int s,double gpa,string m,int y,string g) ;
	void setGoal(string g){goal = g;};
	string getGoal(){return goal;};
	void setYear(int y){year = y;};
	int getYear(){return year;};
	void print();

};

class Professor :public Employee
{
private:
	string status;
	int year;
public:
	Professor() : Employee()
	{status = " ";year =0;}
	Professor(string n,int s,double sal ,string f,string st, int y);
	void setStatus(string s){status = s;};
	string getStatus(){return status;};
	void setYear(int y){year = y;};
	int getYear(){return year;};
	void print();
};

class Staff :public Employee
{
private:
	string status;
	char gender;
public:
	Staff() : Employee()
	{status = " "; gender ='m';}
	Staff(string n,int s,double sal ,string f,string st, char g);
	void setStatus(string s){status = s;};
	string getStatus(){return status;};
	void setGender(char g){gender =g;};
	char getGender(){return gender;};
	void print();
};

class Undergrad :public Student
{
private:
	int year;
	bool transfer; // y/n apply for transfer
public:
	Undergrad() : Student()
	{year = 0; transfer = false;}
	Undergrad(string n, int s,double gpa,string m, int y,bool t);
	void setYear(int y){year =y;};
	int getYear(){return year;};
	void setTransfer(bool t){transfer = t;};
	bool getTransfer(){return transfer;};
	void print();
};

Undergrad::Undergrad(string n, int s,double gpa,string m, int y,bool t) : Student(n,s,gpa,m)
{
	if (y >0)year = y;
	else
		year = 2;
	if (t == true or t == false) transfer = t;
	else
		transfer = false;
}

//print(): prints private members of class
//Arguments: none | Returns: none
void Undergrad::print()
{	Student::print();
		cout << "Year is: " << year << endl;
		cout << "Applied for Transfer? : " ;
		if (transfer == true or transfer == 'T' or transfer == 't') cout << "Yes\n";
		else
			cout << "No\n";
}

Student::Student(string n, int s, double g, string m) : Person(n,s)
{
	if (g >0 )GPA = g;
	else
		GPA= 3.0;
	if (m != " " )major = m;
	else
		major = "Psychology";
};

Staff::Staff(string n,int s,double sal ,string f,string st, char g): Employee(n,s,sal,f)
{
	if (st != " ") status = st;
	else
		status = "Non-manager";
	if(g == 'M' or g == 'F' or g == 'm' or g == 'f') gender =g;
	else
		gender = 'F';
}
//print(): prints private members of class
//Arguments: none | Returns: none
void Staff::print()
{
		Employee::print();
		cout << "Staff Status is: "<< status << endl;
		cout << "Gender: ";
		if (gender == 'M' or gender == 'm') cout << "Male\n";
		else
			cout << "Female\n";
}

Professor::Professor(string n,int s,double sal ,string f,string st, int y): Employee(n,s,sal,f)
{
	if (st != " " )status = st;
	else
		status = "Part-Time";
	if (y > 0) year = y;
	else
		year = 2;
}

//print(): prints private members of class
//Arguments: none | Returns: none
void Professor::print()
{
	Employee::print();
	cout << "Professor Status is: "<< status << endl;
	cout << "Years worked: "<< year << endl;
}

Grad::Grad(string n, int s,double gpa,string m,int y,string g) : Student(n,s,gpa,m)
{
	if (g != " " ) goal =g;
	else
		goal = "Masters";
	if (y > 0) year = y;
	else
		year = 6;
}

//print(): prints private members of class
//Arguments: none | Returns: none
void Grad::print()
{
	Student::print();
	cout << "Goal is: " << goal << endl;
	cout << "Year is: " << year << endl;
}

Employee::Employee(string n, int s, double sal, string f):Person(n,s)
{
	if (sal > 0) salary = sal;
	else
		salary = 65000;
	if (f != " ") field = f;
	else
		field = "Councilor";
}
//function prototypes
void menu();
int submenu();
void student();
void employee();
void underGradChange(vector <Undergrad> &, int);
void filterUnderGrad(vector <Undergrad> &, int);
void gradChange(vector <Grad> &, int);
void filterGrad(vector <Grad> &, int);
void profChange(vector <Professor> &, int);
void filterProf(vector <Professor> &, int);
void staffChange(vector <Staff> &, int);
void filterStaff(vector <Staff> &, int);

int main() {
	//initializations
	string name,field,status,major,goal;
	int year,SSN, choice, choice2, input, input1;
	double salary;
	char gender, yesNo;
	bool transfer;
	ifstream fin("inputs.txt");

	//obj declaration
	vector <Professor> prof1;
	vector <Staff> staff1;
	vector <Undergrad> under1;
	vector <Grad> grad1;
	vector <Employee> employee1;
	vector <Student> stud1;

	//external file data read into obj
	while(fin >> name)
	{
		fin >> SSN >> salary;
		//if student
		if (salary <= 4.00)
		{
			fin >>major >> year;
			if(year > 4) //grad student
			{
				fin >> goal;
				Grad stud2(name,SSN, salary, major,year, goal);
				grad1.push_back(stud2);
			}
			else //undergrad student
			{
				fin >> transfer;
				Undergrad stud3(name,SSN, salary,major,year,transfer);
				under1.push_back(stud3);
			}
		}
		else
		{
			fin >> field;
			fin >> status;
			if(status != "Manager" and status != "Non-manager") //professor
			{
				fin >> year;
				Professor prof(name,SSN, salary, field , status,year);
				prof1.push_back(prof);
				//prof.print();
			}
			else // if staff
			{
				fin >> gender;
				Staff prof2(name,SSN, salary, field , status,gender);
				staff1.push_back(prof2);
			}
		}
	}

	//display menu
	do
	{
		menu();
		cin >> choice;

		//IVL FOR OPTION
		while(choice <0 or choice >3)
		{
			cout << "Error! Enter between 1-3 only!\n";
			cin >> choice;
		}
		switch(choice)
		{
			case 1 : student();
					cin >> choice2;
					//IVL FOR OPTION2
					while(choice2 <0 or choice2 >3)
					{
						cout << "Error! Enter between 1-3 only!\n";
						cin >> choice2;
					}
					if (choice2 == 1)
					{
						input1 = submenu();
						if (input1 == 1) filterUnderGrad(under1,input1);
						else if (input1 == 2)
						{
							cout << "\n\tDisplaying UnderGrad students: \n";
							for (long long unsigned int i =0; i < under1.size() ; i++)
							{
								under1[i].print();
								cout << endl;
							}
						}

						cout << "\nDo you want to make any changes? Y/N?\n";
						cin >> yesNo;
						yesNo = toupper(yesNo);
						//IVL for YESNO
						while(yesNo != 'Y' and yesNo != 'N')
						{
							cout << "Error! Enter Y/N only!";
							cin >> yesNo;
							yesNo = toupper(yesNo);
						}
						if (yesNo == 'Y')
						{
							for (long long unsigned int i =0; i < under1.size() ; i++)
							{
								cout << i+1 << ". " << under1[i].getName();
								cout << endl;
							}
							cout << "Which student's data would you like to make changes in?\n";
							cin >> input;
							while(input < 0 or input > under1.size())
							{
								cout << "Error! Enter the right member number to proceed.\n";
								cin >> input;
							}
							underGradChange(under1,input);
						}
						else
							break;
					}
					else if(choice2 == 2)
					{
						input1 = submenu();
						if (input1 == 1) filterGrad(grad1,input1);
						else if (input1 == 2)
						{
							cout << "\n\tDisplaying Grad students: \n";
							for (long long unsigned int i =0; i < grad1.size() ; i++)
							{
								grad1[i].print();
								cout << endl;
							}
						}

						cout << "\nDo you want to make any changes? Y/N?\n";
						cin >> yesNo;
						yesNo = toupper(yesNo);
						//IVL for YESNO
						while(yesNo != 'Y' and yesNo != 'N')
						{
							cout << "Error! Enter Y/N only!";
							cin >> yesNo;
							yesNo = toupper(yesNo);
						}
						if (yesNo == 'Y')
						{
							for (long long unsigned int i =0; i < grad1.size() ; i++)
							{
								cout << i+1 << ". " << grad1[i].getName();
								cout << endl;
							}
							cout << "Which student's data would you like to make changes in?\n";
							cin >> input;
							while(input < 0 or input > grad1.size())
							{
								cout << "Error! Enter the right member number to proceed.\n";
								cin >> input;
							}
							gradChange(grad1,input);
						}
						else
							break;
					}
					else
					{
						cout << "\n\tDisplaying Grad students: \n";
						for (long long unsigned int i =0; i < grad1.size() ; i++)
						{
							grad1[i].print();
							cout << endl;
						}

						cout << "\n\tDisplaying UnderGrad students: \n";
						for (long long unsigned int i =0; i < under1.size() ; i++)
						{
							under1[i].print();
							cout << endl;
						}
					}

					break;
			case 2 :
					employee();
					cin >> choice2;
					//IVL FOR OPTION2
					while(choice2 <0 or choice2 >4)
					{
						cout << "Error! Enter between 1-4 only!\n";
						cin >> choice2;
					}

					if (choice2 == 1)
					{
						input1 = submenu();
						if (input1 == 1) filterProf(prof1,input1);
						else if (input1 == 2)
						{
							cout << "\n\tDisplaying Professors: \n";
							for (long long unsigned int i =0; i < prof1.size() ; i++)
							{
								prof1[i].print();
								cout << endl;
							}
						}
						cout << "\nDo you want to make any changes? Y/N?\n";
						cin >> yesNo;
						yesNo = toupper(yesNo);
						//IVL for YESNO
						while(yesNo != 'Y' and yesNo != 'N')
						{
							cout << "Error! Enter Y/N only!";
							cin >> yesNo;
							yesNo = toupper(yesNo);
						}
						if (yesNo == 'Y')
						{
							for (long long unsigned int i =0; i < prof1.size() ; i++)
							{
								cout << i+1 << ". " << prof1[i].getName();
								cout << endl;
							}
							cout << "Which Professor's data would you like to make changes in?\n";
							cin >> input;
							while(input < 0 or input > prof1.size())
							{
								cout << "Error! Enter the right member number to proceed.\n";
								cin >> input;
							}
							profChange(prof1,input);
						}
						else
							break;
					}
					else if(choice2 == 2)
					{
						input1 = submenu();
						if (input1 == 1) filterStaff(staff1,input1);
						else if (input1 == 2)
						{
							cout << "\n\tDisplaying Staff: \n";
							for (long long unsigned int i =0; i < staff1.size() ; i++)
							{
								staff1[i].print();
								cout << endl;
							}
						}

						cout << "\nDo you want to make any changes? Y/N?\n";
						cin >> yesNo;
						yesNo = toupper(yesNo);
						//IVL for YESNO
						while(yesNo != 'Y' and yesNo != 'N')
						{
							cout << "Error! Enter Y/N only!";
							cin >> yesNo;
							yesNo = toupper(yesNo);
						}
						if (yesNo == 'Y')
						{
							for (long long unsigned int i =0; i < staff1.size() ; i++)
							{
								cout << i+1 << ". " << staff1[i].getName();
								cout << endl;
							}
							cout << "Which staff's data would you like to make changes in?\n";
							cin >> input;
							while(input < 0 or input > staff1.size())
							{
								cout << "Error! Enter the right member number to proceed.\n";
								cin >> input;
							}
							staffChange(staff1,input);
						}
						else
							break;
					}
					else
					{
						cout << "\n\tDisplaying Professors: \n";
						for (long long unsigned int i =0; i < prof1.size() ; i++)
						{
							prof1[i].print();
							cout << endl;
						}
						cout << "\n\tDisplaying Staff: \n";
						for (long long unsigned int i =0; i < staff1.size() ; i++)
						{
							staff1[i].print();
							cout << endl;
						}
					}
					break;
		}
	} while(choice != 3);
	cout << "\n\t***Program Ending!! Have a good day!!***";
	fin.close();
	return 0;
}

//menu(): display menu
//Arguments: none | Returns: none
void menu()
{
	cout << "\t\t\t*****Welcome*****\n";
	cout << "Select an option from below: \n";
	cout << "(1) Show Students\n";
	cout << "(2) Show Employees \n";
	cout << "(3) Exit \n";
}

//submenu(): display submenu
//Arguments: none | Returns: none
int submenu()
{
	int input;
	cout << "How would you like the records to be displayed? Select one from below: \n";
	cout << "(1) Filtered option (2) View all\n";
	cin >> input;
	while(input < 1 or input >2)
	{
		cout << "Error! Enter 1/2 only!\n";
		cin >> input;
	}
	return input;
}

//student(): display students menu
//Arguments: none | Returns: none
void student()
{
	cout << "\n\t\t***Welcome to Student menu!***\n";
	cout << "Select one from below: \n";
	cout << "(1) View Undergrad students\n";
	cout << "(2) View Grad students\n";
	cout << "(3) View Both students\n";
	//cout << "(4) End Program \n";
}

//employee(): display employees menu
//Arguments: none | Returns: none
void employee()
{
	cout << "\n\t\t***Welcome to Employee menu!***\n";
	cout << "Select one from below: \n";
	cout << "(1) View Professors\n";
	cout << "(2) View Staff\n";
	cout << "(3) View Both \n";
}

//filterUnderGrad: filters undergrads menu
//Arguments: v(vector <Undergrad> &), c(int)| Returns: none
void filterUnderGrad(vector <Undergrad> &v, int c)
{

	int input, s,y, num3;
	vector <int> index;
	string n,m;
	float g;
	char t;
	bool found = false, temp = false;
	cout << "How would you like to filter your options? Select one from below: \n";
	cout << "(1)Name, (2) SSN, (3) GPA, (4) Major, (5) Year (6) Transfer\n";
	cin >> input;
	while(input < 0 or input > 6)
	{
		cout << "Error! Enter the right member number to proceed.\n";
		cin >> input;
	}
	if(input == 1)
	{
		cout << "What name are you searching for? (First letter should be uppercase) \n";
		cin.ignore();
		getline(cin,n);
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getName() == n)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
	else if(input == 2)
	{
		cout << "Which SSN are you searching for? \n";
		cin >> s;
		while(s <0 )
		{
			cout <<"Error! Enter a valid 9 digits!!";
			cin >> s;
		}
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getSSN() == s)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
	else if(input == 3)
	{
		cout << "What GPA for students you searching for? \n";
		cin >> g;
		while(g <0 or g >4.00)
		{
			cout <<"Error! Enter between 1.00 to 4.00 only!";
			cin >> g;
		}
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getGPA() == g)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
	else if (input == 4)
	{
		cout << "What Major are you searching for? (First letter should be uppercase)\n";
		cin.ignore();
		getline(cin,m);
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getMajor() == m)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
	else if(input == 5)
	{
		cout << "Which year students are you searching for? \n";
		cin >> y;
		while(y <0 or y >4)
		{
			cout <<"Error! Enter between 1-4 only!";
			cin >> y;
		}
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getYear() == y)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
	else
	{
		cout << "Are you looking for students who applied to transfer? T/F ?\n";
		cin >> t;
		t = toupper(t);
		while(t != 'T' and t != 'F')
		{
			cout << "Error! Enter T/F only!\n";
			cin >> t;
			t = toupper(t);
		}
		if (t == 'T') temp = true;
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getTransfer() == 1)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
}

//underGradChange: allows change to Grads members
//Arguments: v(vector <Grad> &), c(int)| Returns: none
void underGradChange(vector <Undergrad> &v, int c)
{
	int input,s, y, num3;
	string name, m;
	double g;
	char t;
	bool found = false;
	cout << "Which member do you want to make changes in?\n";
	cout << "Select one: \n";
	//string n, int s,double gpa,string m, int y,bool t
	cout << "(1)Name, (2) SSN, (3) GPA, (4) Major, (5) Year (6) Transfer\n";
	cin >> input;
	while(input < 0 or input > 6)
	{
		cout << "Error! Enter the right member number to proceed.\n";
		cin >> input;
	}
	if (input == 1)
	{
		cout << "Enter New Name with hyphens in between first and last: (First letter should be uppercase)";
		cin >> name;
		v[c-1].setName(name);
	}
	else if (input == 2)
	{
		cout << "Enter New SSN: ";
		cin >> s;
		while(s <0 )
		{
			cout <<"Error! Enter a valid 9 digits!!";
			cin >> s;
		}
		v[c-1].setSSN(s);
	}
	else if (input == 3)
	{
		cout << "Enter New GPA: ";
		cin >> g;
		while(g <0 or g >4.00)
		{
			cout <<"Error! Enter between 1.00 to 4.00 only!";
			cin >> g;
		}
		v[c-1].setGPA(g);
	}
	else if (input == 4)
	{
		cout << "Enter New Major: (First letter should be uppercase)";
		getline(cin,m);
		v[c-1].setMajor(m);
	}
	else if (input == 5)
	{
		cout << "Enter New Year: ";
		cin >> y;
		v[c-1].setYear(y);
	}
	else
	{
		cout << "Enter if student is transferring? T/F: ";
		cin >> t;
		t = toupper(t);
		while(t != 'T' and t != 'F')
		{
			cout << "Error! Enter T/F only!\n";
			cin >> t;
			t = toupper(t);
		}
		v[c-1].setTransfer(t);
	}
	cout << "**New changes made!!**\n";
	v[c-1].print();
}
//filterGrad: filters Grads menu
//Arguments: v(vector <Grad> &), c(int)| Returns: none
void filterGrad(vector <Grad> &v, int c)
{
	int input, s,y, num3;
	string n,m,g1;
	vector <int> index;
	float g;
	char t;
	bool found;
	cout << "How would you like to filter your options? Select one from below: \n";
	cout << "(1)Name, (2) SSN, (3) GPA, (4) Major, (5) Goal (6) Year\n";
	cin >> input;
	while(input < 0 or input > 6)
	{
		cout << "Error! Enter the right member number to proceed.\n";
		cin >> input;
	}
	if(input == 1)
	{
		cout << "What name are you searching for? (First letter should be uppercase)\n";
		cin.ignore();
		getline(cin,n);
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getName() == n)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
	else if(input == 2)
	{
		cout << "Which SSN are you searching for? \n";
		cin >> s;
		while(s <0 )
		{
			cout <<"Error! Enter a valid 9 digits!!";
			cin >> s;
		}
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getSSN() == s)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
	else if(input == 3)
	{
		cout << "What GPA for students you searching for? \n";
		cin >> g;
		while(g <0 or g >4.00)
		{
			cout <<"Error! Enter between 1.00 to 4.00 only!";
			cin >> g;
		}
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getGPA() == g)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
	else if (input == 4)
	{
		cout << "What Major are you searching for? (First letter should be uppercase)\n";
		cin.ignore();
		getline(cin,m);
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getMajor() == m)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
	else if(input == 5)
	{
		cout << "What student's goals are you searching for? (First letter should be uppercase)\n";
		cin >> g1;
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getGoal() == g1)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
	else
	{
		cout << "Which year students are you searching for?\n";
		cin >> y;
		while(y <0 or y >4)
		{
			cout <<"Error! Enter between 1-4 only!";
			cin >> y;
		}
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getYear() == y)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
}
//gradChange: changes Grads members
//Arguments: v(vector <Grad> &), c(int)| Returns: none
void gradChange(vector <Grad> &v, int c)
{
	int input,s, t;
	string name, y,m;
	float g;

	cout << "Which member do you want to make changes in?\n";
	cout << "Select one: \n";
	//string n, int s,double gpa,string m, int y,bool t
	cout << "(1)Name, (2) SSN, (3) GPA, (4) Major, (5) Goal (6) Year\n";
	cin >> input;
	while(input < 0 or input > 6)
	{
		cout << "Error! Enter the right member number to proceed.\n";
		cin >> input;
	}
	if (input == 1)
	{
		cout << "Enter New Name with hyphens in between first and last: (First letter should be uppercase)";
		cin >> name;
		v[c-1].setName(name);
	}
	else if (input == 2)
	{
		cout << "Enter New SSN: ";
		cin >> s;
		while(s <0 )
		{
			cout <<"Error! Enter a valid 9 digits!!";
			cin >> s;
		}
		v[c-1].setSSN(s);
	}
	else if (input == 3)
	{
		cout << "Enter New GPA: ";
		cin >> g;while(g <0 or g >4.00)
		{
			cout <<"Error! Enter between 1.00 to 4.00 only!";
			cin >> g;
		}

		v[c-1].setGPA(g);
	}
	else if (input == 4)
	{
		cout << "Enter New Major: ";
		getline(cin ,m);
		v[c-1].setMajor(m);
	}
	else if (input == 5)
	{
		cout << "Enter New Goal: (First letter should be uppercase)";
		getline(cin ,y);
		v[c-1].setGoal(y);
	}
	else
	{
		cout << "Enter New Year: ";
		cin >> t;
		while(t <1 or t >4 )
		{
			cout << "Error! Enter between 1-4\n";
			cin >> t;
		}
		v[c-1].setYear(t);
	}
	cout << "**New changes made!!**\n";
	v[c-1].print();
}
//filterStaff: filters staff members
//Arguments: v(vector <Grad> &), c(int)| Returns: none
void filterStaff(vector <Staff> &v, int c)
{
	int input,s, num3;
	double l;
	string n, y,m,f,t;
	vector <int> index;
	char g;
	bool found = true;

	cout << "How would you like to filter your options? Select one from below: \n";
	cout << "(1)Name, (2) SSN, (3) Salary, (4) Field, (5) Status (6) Gender\n";
	cin >> input;
	while(input < 0 or input > 6)
	{
		cout << "Error! Enter the right member number to proceed.\n";
		cin >> input;
	}
	if(input == 1)
	{
		cout << "What name are you searching for? (First letter should be uppercase)\n";
		cin.ignore();
		getline(cin,n);
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getName() == n)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
	else if(input == 2)
	{
		cout << "Which SSN are you searching for? \n";
		cin >> s;
		while(s <0 )
		{
			cout <<"Error! Enter a valid 9 digits!!";
			cin >> s;
		}
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getSSN() == s)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
	else if(input == 3)
	{
		cout << "What salary are you searching for? \n";
		cin >> l;
		while(l <0 )
		{
			cout <<"Error! Enter positive digits!!";
			cin >> l;
		}
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getSalary() == l)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
	else if(input == 4)
	{
		cout << "Which field are you searching for? (First letter should be uppercase)\n";
		cin.ignore();
		getline(cin,f);
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getField() == f)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
	else if (input == 5)
	{
		cout << "Enter New Status: (First letter should be uppercase)";
		cin.ignore();
		getline(cin, t);
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getStatus() == t)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
	else
	{
		cout << "Enter New Gender: M/F";
		cin >> g;
		g = toupper(g);
		while(g != 'M' and g != 'F')
		{
			cout << "Error! Enter M/F only!\n";
			cin >> g;
			g = toupper(g);
		}
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getGender() == g)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
}
//staffChange: changes staff members
//Arguments: v(vector <Grad> &), c(int)| Returns: none
void staffChange(vector <Staff> &v, int c)
{
	int input,s, num3;
	string name, y,m;
	bool t, found  = false;
	char gen;
	double g;

	cout << "Which member do you want to make changes in?\n";
	cout << "Select one: \n";
	//string n, int s,double gpa,string m, int y,bool t
	cout << "(1)Name, (2) SSN, (3) Salary, (4) Field, (5) Status (6) Gender\n";
	cin >> input;
	while(input < 0 or input > 6)
	{
		cout << "Error! Enter the right member number to proceed.\n";
		cin >> input;
	}
	if (input == 1)
	{
		cout << "Enter New Name with hyphens in between first and last: (First letter should be uppercase)";
		cin >> name;
		v[c-1].setName(name);
	}
	else if (input == 2)
	{
		cout << "Enter New SSN: ";
		cin >> s;
		while(s <0 )
		{
			cout <<"Error! Enter a valid 9 digits!!";
			cin >> s;
		}
		v[c-1].setSSN(s);
	}
	else if (input == 3)
	{
		cout << "Enter New Salary: ";
		cin >> g;
		v[c-1].setSalary(g);
	}
	else if (input == 4)
	{
		cout << "Enter New Field: (First letter should be uppercase)";
		cin.ignore();
		getline(cin ,m);
		v[c-1].setField(m);
	}
	else if (input == 5)
	{
		cout << "Enter New Status: (First letter should be uppercase)";
		cin.ignore();
		getline(cin, y);
		v[c-1].setStatus(y);
	}
	else
	{
		cout << "Enter New Gender: M/F";
		cin >> gen;
		gen = toupper(gen);
		while(gen != 'M' and gen != 'F')
		{
			cout << "Error! Enter M/F only!\n";
			//cin.ignore();
			cin >> gen;
			gen = toupper(gen);
		}
		v[c-1].setGender(gen);
	}
	cout << "**New changes made!!**\n";
	v[c-1].print();
}
//filterProf: filters professors members
//Arguments: v(vector <Grad> &), c(int)| Returns: none
void filterProf(vector <Professor> &v, int c)
{
	int input,s,y, num3;
	double l;
	string n,m,f,t;
	char g;
	vector <int> index;
	bool found = false;

	cout << "How would you like to filter your options? Select one from below: \n";
	cout << "(1)Name, (2) SSN, (3) Salary, (4) Field, (5) Status (6) Year\n";
	cin >> input;
	while(input < 0 or input > 6)
	{
		cout << "Error! Enter the right member number to proceed.\n";
		cin >> input;
	}
	if(input == 1)
	{
		cout << "What name are you searching for? (First letter should be uppercase)\n";
		cin.ignore();
		getline(cin,n);
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getName() == n)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
	else if(input == 2)
	{
		cout << "Which SSN are you searching for? \n";
		cin >> s;
		while(s <0 )
		{
			cout <<"Error! Enter a valid 9 digits!!";
			cin >> s;
		}
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getSSN() == s)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
	else if(input == 3)
	{
		cout << "What salary are you searching for? \n";
		cin >> l;
		while(l <0 )
		{
			cout <<"Error! Enter positive digits!!";
			cin >> l;
		}
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getSalary() == l)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
	else if(input == 4)
	{
		cout << "Which field are you searching for? (First letter should be uppercase)\n";
		cin.ignore();
		getline(cin,f);
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getField() == f)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
	else if (input == 5)
	{
		cout << "Enter New Status: (First letter should be uppercase)";
		cin.ignore();
		getline(cin, t);
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getStatus() == t)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
	else
	{
		cout << "Which year staff are you searching for? \n";
		cin >> y;
		while(y <0 )
		{
			cout <<"Error! Enter positive number only only!";
			cin >> y;
		}
		for(int i =0;i<v.size();i++)
		{
			if (v[i].getYear() == y)
			{
				found = true;
				index.push_back(i);
			}
		}
		if (found)
		{
			cout << "Record found!\n";
			for(int j =0; j<index.size();j++)
			{
				v[index[j]].print();
				cout << endl;
			}
			index.clear();
		}
		else
			cout << "Record doesn't exist!\n";
	}
}
//profChange: changes professors members
//Arguments: v(vector <Grad> &), c(int)| Returns: none
void profChange(vector <Professor> &v, int c)
{
	int input,s, t;
	string name, y,m;
	double g;

	cout << "Which member do you want to make changes in?\n";
	cout << "Select one: \n";
	//string n, int s,double gpa,string m, int y,bool t
	cout << "(1)Name, (2) SSN, (3) Salary, (4) Field, (5) Status (6) Year\n";
	cin >> input;
	while(input < 0 or input > 6)
	{
		cout << "Error! Enter the right member number to proceed.\n";
		cin >> input;
	}
	if (input == 1)
	{
		cout << "Enter New Name with hyphens in between first and last: (First letter should be uppercase)";
		cin >> name;
		v[c-1].setName(name);
	}
	else if (input == 2)
	{
		cout << "Enter New SSN: ";
		cin >> s;
		while(s <0 )
		{
			cout <<"Error! Enter a valid 9 digits!!";
			cin >> s;
		}
		v[c-1].setSSN(s);
	}
	else if (input == 3)
	{
		cout << "Enter New Salary: ";
		cin >> g;
		v[c-1].setSalary(g);
	}
	else if (input == 4)
	{
		cout << "Enter New Field: (First letter should be uppercase)";
		cin.ignore();
		getline(cin ,m);
		v[c-1].setField(m);
	}
	else if (input == 5)
	{
		cout << "Enter New Status : (First letter should be uppercase)";
		cin.ignore();
		getline(cin, y);
		v[c-1].setStatus(y);
	}
	else
	{
		cout << "Enter New Year: ";
		cin >> t;
		while(t <1  )
		{
			cout << "Error! Enter a positive number\n";
			cin >> t;
		}
		v[c-1].setYear(t);
	}
	cout << "**New changes made!!**\n";
	v[c-1].print();
}
