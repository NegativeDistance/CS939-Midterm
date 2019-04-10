#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class Employee
{
	int emp_ID, emp_age, emp_dept_ID;
	double emp_salary;
	string emp_name;

public:
	Employee()
	{
		emp_ID = -1;
		emp_age = -1;
		emp_dept_ID = -1;
		emp_salary = -1;
		emp_name = "null";
	}

	Employee(int ID, int age, int dept_ID, double salary, string name)
	{
		emp_ID = ID;
		emp_age = age;
		emp_dept_ID = dept_ID;
		emp_salary = salary;
		emp_name = name;
	}

	void set_ID(int ID)
	{
		emp_ID = ID;
	}

	int get_ID()
	{
		int ID = emp_ID;
		return ID;
	}

	void set_name(string name)
	{
		emp_name = name;
	}

	string get_name()
	{
		string name = emp_name;
		return name;
	}

	void set_salary(double salary)
	{
		emp_salary = salary;
	}

	double get_salary()
	{
		double salary = emp_salary;
		return salary;
	}

	void set_age(int age)
	{
		emp_age = age;
	}

	int get_age()
	{
		int age = emp_age;
		return age;
	}
	
	void set_dept_ID(int dept_ID)
	{
		emp_dept_ID = dept_ID;
	}

	int get_dept_ID()
	{
		int ID = emp_dept_ID;
		return ID;
	}
};

class Department
{
	int dept_ID;
	string dept_name;
	string dept_head_name;

public:
	Department()
	{
		dept_ID = -1;
		dept_name = "null";
		dept_head_name = "null";
	}

	Department(int ID, string name, string head)
	{
		dept_ID = ID;
		dept_name = name;
		dept_head_name = head;
	}

	void set_ID(int ID)
	{
		dept_ID = ID;
	}

	int get_ID()
	{
		int ID = dept_ID;
		return ID;
	}

	void set_name(string name)
	{
		dept_name = name;
	}

	string get_name()
	{
		string name = dept_name;
		return name;
	}

	void set_head(string name)
	{
		dept_head_name = name;
	}

	string get_head()
	{
		string head = dept_head_name;
		return head;
	}
};

int menu();
int search_dept(Department [], int num_elem, int value);
int search_emp(Employee [], int num_elem, int value);

void create_dept(Department [], int size);
void create_emp(Employee [], Department [], int size, int dept_size);
void write_out(Employee [], Department[], int emp_size, int dept_size);
void write_in(Employee [], Department [], int emp_size, int dept_size);
void salary_report(Employee [], Department [], int emp_size, int dept_size);

int main()
{
	bool run = 1;
	int choice;
	const int EMP_SIZE = 5;
	const int DEPT_SIZE = 3;
	Employee emp_list[EMP_SIZE];
	Department dept_list[DEPT_SIZE];

	do
	{
		choice = menu();

		if (choice == 1)
			create_dept(dept_list, DEPT_SIZE);
		else if (choice == 2)
			create_emp(emp_list, dept_list, EMP_SIZE, DEPT_SIZE);
		else if (choice == 3)
			write_out(emp_list, dept_list, EMP_SIZE, DEPT_SIZE);
		else if (choice == 4)
			write_in(emp_list, dept_list, EMP_SIZE, DEPT_SIZE);
		else if (choice == 5)
			salary_report(emp_list, dept_list, EMP_SIZE, DEPT_SIZE);
		else if (choice == 6)
		{
			cout << "Thank you, goodbye.";

				run = false;
		}

	} while (run == true);

	return 0;
}

int menu()
{
	int choice;

	cout << "1. Create Department\n";
	cout << "2. Create Employee\n";
	cout << "3. Write Out Data File\n";
	cout << "4. Read In Data File\n";
	cout << "5. Display Salary Report\n";
	cout << "6. -- Quit -- \n";
	cout << "Please make a selection : ";
	cin >> choice;

	while (choice > 6 || choice < 1)
	{
		cout << "Please enter a valid choice (1 - 6): ";
		cin >> choice;
	}

	return choice;
}

int search_dept(Department list[], int num_elem, int value) //search (1)input array by (2)the number of elements for (3)the value
{
	int index = 0;  //subscript to search array
	int position = -1; //record position of search value
	bool found = 0;  //flag if value is found

	while (index < num_elem && !found) //while the array subscript is less than (2)the elements and found is not true
	{
		if (list[index].get_ID() == value) //if the value is found
		{
			found = true; //flag as true
			position = index; //record the position
		}
		index++; //search next element
	}
	return position; // return found position or -1
}

void create_dept(Department dept_list[], int size)
{
	int dept_ID;
	string dept_name, dept_head_name;
	int search_value;
	static int pos = size - size;  //sets array position to 0
	
	if (pos < size) //if the array position is less than the array size it accept data. If the position is equal to array size then array is full
	{
		cout << "Please Enter Department Details:\n";
		cout << "Department ID : ";
		cin >> dept_ID;
		search_value = search_dept(dept_list, size, dept_ID); //searches array to see if ID already exists

		if (search_value < 0) //if the search returns -1 then the ID is not found and will add it to the array
		{
			dept_list[pos].set_ID(dept_ID);

			cout << "Department Name : ";
			cin >> dept_name;
			dept_list[pos].set_name(dept_name);

			cout << "Head of Department : ";
			cin >> dept_head_name;
			dept_list[pos].set_head(dept_head_name);

			pos++; //increase array position by 1
		}
		else
			cout << "Value must be unique!\n";
	}
	else
		cout << endl << "The array is full, you can not add any more Departments.\n";
}

int search_emp(Employee list[], int num_elem, int value) //search (1)input array by (2)the number of elements for (3)the value
{
	int index = 0;  //subscript to search array
	int position = -1; //record position of search value
	bool found = 0;  //flag if value is found

	while (index < num_elem && !found) //while the array subscript is less than (2)the elements and found is not true
	{
		if (list[index].get_ID() == value) //if the value is found
		{
			found = true; //flag as true
			position = index; //record the position
		}
		index++; //search next element
	}
	return position; // return found position or -1
}

void create_emp(Employee emp_list[], Department dept_list[], int size, int dept_size)
{
	int emp_ID, emp_age, emp_dept_ID;
	double salary;
	string emp_name;
	int search_value;
	static int pos = size - size;

	if (pos < size) //if the array position is less than the array size it accept data. If the position is equal to array size then array is full
	{
		cout << "Please Enter Employee Details:\n";
		cout << "Employee ID : ";
		cin >> emp_ID;
		search_value = search_emp(emp_list, size, emp_ID); //searches array to see if ID already exists

		if (search_value < 0) //if the search returns -1 then the ID is not found and will add it to the array
		{
			emp_list[pos].set_ID(emp_ID);

			cout << "Employee Name :";
			cin >> emp_name;
			emp_list[pos].set_name(emp_name);

			cout << "Salary: $";
			cin >> salary;
			emp_list[pos].set_salary(salary);

			cout << "Age : ";
			cin >> emp_age;
			emp_list[pos].set_age(emp_age);

			cout << "Department ID : ";
			cin >> emp_dept_ID;
			search_value = search_dept(dept_list, dept_size, emp_dept_ID); //searches Departments to see if ID exists
			while (search_value < 0) //If search returns -1 then Department is invalid and goes in loop
			{
				cout << "Please enter a valid department ID: ";
				cin >> emp_dept_ID;
				search_value = search_dept(dept_list, dept_size, emp_dept_ID);
			}
			emp_list[pos].set_dept_ID(emp_dept_ID);

			pos++; //increase array position by 1
		}
		else
			cout << "Value must be unique!\n";
	}
	else
		cout << "The array is full, you can not add any more Employees.\n";
}

void write_out(Employee emp_list[], Department dept_list[], int emp_size, int dept_size)
{
	ofstream employee_file, department_file;

	employee_file.open("Employees.txt");
	for (int count = 0; count < emp_size; count++)
	{
		employee_file << emp_list[count].get_ID() << endl;
		employee_file << emp_list[count].get_name() << endl;
		employee_file << emp_list[count].get_salary() << endl;
		employee_file << emp_list[count].get_age() << endl;
		employee_file << emp_list[count].get_dept_ID() << endl;
	}

	employee_file.close();

	department_file.open("Departments.txt");
	for (int count = 0; count < dept_size; count++)
	{
		department_file << dept_list[count].get_ID() << endl;
		department_file << dept_list[count].get_name() << endl;
		department_file << dept_list[count].get_head() << endl;
		
	}

	department_file.close();
}

void write_in(Employee emp_list[], Department dept_list[], int emp_size, int dept_size)
{
	ifstream employee_file, department_file;

	int emp_ID, emp_age, emp_dept_ID, dept_ID;
	double emp_salary;
	string emp_name, dept_name, dept_head;

	employee_file.open("Employees.txt");
	for (int count = 0; count < emp_size; count++)
	{
		employee_file >> emp_ID;
		emp_list[count].set_ID(emp_ID);

		employee_file >> emp_name;
		emp_list[count].set_name(emp_name);

		employee_file >> emp_salary;
		emp_list[count].set_salary(emp_salary);

		employee_file >> emp_age;
		emp_list[count].set_age(emp_age);

		employee_file >> emp_dept_ID;
		emp_list[count].set_dept_ID(emp_dept_ID);
	}

	employee_file.close();

	department_file.open("Departments.txt");
	for (int count = 0; count < dept_size; count++)
	{
		department_file >> dept_ID;
		dept_list[count].set_ID(dept_ID);

		department_file >> dept_name;
		dept_list[count].set_name(dept_name);

		department_file >> dept_head;
		dept_list[count].set_head(dept_head);
	}

	department_file.close();
}

void salary_report(Employee emp_list[], Department dept_list[], int EMP_SIZE, int DEPT_SIZE)
{
	int dept_ID;
	string dept_name;
	double dept_salary;

	cout << endl << "Salary Report By Department\n";
	
	for (int count = 0; count < DEPT_SIZE; count++)
	{
		dept_salary = 0;
		dept_ID = dept_list[count].get_ID();
		dept_name = dept_list[count].get_name();

		for (int count = 0; count < EMP_SIZE; count++)
		{
			
			double emp_salary;

			if (emp_list[count].get_dept_ID() == dept_ID)
			{
				emp_salary = emp_list[count].get_salary();
				dept_salary = dept_salary + emp_salary;
			}
		}
		
		cout << endl;
		cout << "Dept         : " << dept_name << endl;
		cout << "Total Salary : $" << dept_salary << endl;
	}
}