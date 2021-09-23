#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <conio.h>

using namespace std;

//Function prototypes
int checkInput(int, string, int, int);						//For checking input errors
bool retreiveFromFile(string, ifstream &, string);			//For reading files
string getName(int, char);									//This will be used to get the name of the student via index number
string getCourseTitle(string);								//This will deliver the course title
string getMarks(int, string, char);							//Getting the marks of a specific course
string toString(int);										//Convert an integer to string
int toInt(string);											//COnvert a string to integer
string gradeMark(double);									//It is used to determine the grade mark
int getSum(int, bool = false);								//This function would be used to remotely make sums
double getAverage(int, int = 2);							//This is used to get the average mark
void summary();
double count_students(string = "", bool = false, bool = false);


int main()
{
	//Creating variables
	int option;
	//Creating variables for the files
	ifstream studRead, enrolRead, courseRead;
	ofstream studWrite, enrolWrite, courseWrite;

	//Creating the main menu
main_menu: {
	cout << "MAIN MENU" << endl;
	cout << "=========" << endl;

	cout << "1. Manage Student Records\n"
		<< "2. Manage Enrolment Records\n"
		<< "3. Generate Student Reports\n"
		<< "4. Generate Course Summaries\n"
		<< "5. Exit\n\n"
		<< "================================\n\n";
	}

		   //Accepting user's option
		   option = checkInput(option, "Option: ", 1, 5);

		   switch (option)
		   {
		   case 1: {
			   system("cls");

			   //creating a local variable
			   int local_option;

			   cout << "MANAGE STUDENTS RECORDS SUB-MENU\n"
				   << "================================\n\n";

			   cout << "1. Add New Student Record\n"
				   << "2. View Student Records\n"
				   << "3. Return to Main Menu\n\n"
				   << "=============================\n\n";

			   local_option = checkInput(local_option, "Option: ", 1, 3);

			   switch (local_option)
			   {
			   case 1: {
				   system("cls");

				   cout << "ADDING A NEW STUDENT\n";
				   cout << "====================\n\n";
				   //seeding a real-time number
				   srand(time(0));

				   //Creating some local variables
				   int stud_id; string sname, fname;

				   //You can change this to your liking, but I will automatically
				   //generate the student's id
				   cout << "It is to be noted that the student's id is automatically generated\n\n";
				   cout << "Please enter the new student's required details below\n\n";

				   //Generating the student's id
				   int multiplier = 1 + rand() % 9;
				   stud_id = (123456 * multiplier) + (rand() % 1000000);
				   if (stud_id >= 1000000) {
					   stud_id -= multiplier * 123456;
				   }

				   //User data entry by user
				   cout << "Student ID:  " << stud_id << endl;
				   cout << "Surname: "; cin >> sname;
				   cout << "Firstname: "; cin >> fname;

				   //Changing the names into capital letters
				   for (int i = 0; i < sname.length(); i++) {
					   sname[i] = toupper(sname[i]);
				   }
				   for (int i = 0; i < fname.length(); i++) {
					   fname[i] = toupper(fname[i]);
				   }

				   //Preparing the file for storage
				   studWrite.open("students.txt", ios::app);

				   //Writing the data into the file
				   studWrite << left << setw(9) << stud_id;
				   studWrite << left << setw(16) << sname;
				   studWrite << left << fname << endl;

				   //closing the opened file to save memory
				   studWrite.close();
				   break;
			   }

			   case 2: {
				   system("cls");

				   cout << "STUDENT RECORDS\n"
					   << "===============\n\n";

				   //Using our created function to retreive info from the file
				   retreiveFromFile("students.txt", studRead, "txt");

				   //If using the function seems to be a bit too wayward, you can
				   //write the whole thing here as I writing below and clean the
				   //function I have written above
				   /*
					   studRead.open("students.txt");

					   //A string variable to print the data from the file
					   string data;

					   //Printing data from the file using a simple while loop
					   while(getline(studRead,data)){
						   cout << data << endl;
					   }

					   //Close the file to save memory
					   studRead.close()
				   */
				   break;
			   }
			   case 3:
				   system("cls");

				   goto main_menu;
			   }
			   break;
		   }

		   case 2: {
			   system("cls");

			   //Creating a local variable
			   int local_option;

			   cout << "MANAGE ENROLMENT RECORDS SUB-MENU\n"
				   << "=================================\n\n";

			   cout << "1. Add New Enrolment Record\n"
				   << "2. View Enrolment Records\n"
				   << "3. Return to MAIN MENU\n\n"
				   << "=================================\n\n";

			   local_option = checkInput(local_option, "Option: ", 1, 3);

			   switch (local_option)
			   {
			   case 1: {
				   system("cls");

				   //Declaring necessary variables to be used
				   string course_code; int stud_id, exam_mark, final_mark; float ca_mark;

				   cout << "ADDING NEW ENROLMENT DATA\n";
				   cout << "=========================\n\n";

				   cout << "Please enter the required information below to enrol a new member\n\n";
				   cout << "Course Code: "; cin >> course_code;
				   cout << "Student ID: "; cin >> stud_id;
				   cout << "CA Mark: "; cin >> ca_mark;
				   cout << "Exam Score: "; cin >> exam_mark;
				   cout << "Final Score: "; cin >> final_mark;

				   //Preparing the file for writing
				   enrolWrite.open("enrolment.txt", ios::app);

				   //Writing into the prepared file
				   enrolWrite << left << setw(9) << course_code;
				   enrolWrite << left << setw(9) << stud_id;
				   enrolWrite << left << setw(8) << ca_mark;
				   enrolWrite << left << setw(7) << exam_mark;
				   enrolWrite << left << final_mark << endl;

				   //Closing file to save memory
				   enrolWrite.close();
				   break;
			   }

			   case 2: {
				   system("cls");

				   cout << "ENROLMENT RECORDS\n";
				   cout << "=================\n\n";

				   //using our created function to show all the records
				   retreiveFromFile("enrolment.txt", enrolRead, "txt");

				   //In case the function seems to much, you can use the normal
				   //method as I showed in the previous menu context
				   break;
			   }

			   case 3:
				   system("cls");

				   goto main_menu;
			   }

			   break;
		   }

		   case 3: {
			   int stud_id; string string_student_id;

			   cout << "\n\nPlease enter the student's id below\n";
			   stud_id = checkInput(stud_id, "Student ID: ", 100000, 999999);

			   //For comparison sake, the student id would be converted to string
			   string_student_id = toString(stud_id);

			   system("cls");

			   cout << "----------------------------------------------------------------\n";
			   cout << "Student ID: " << stud_id << endl;
			   cout << "Surname   : " << getName(stud_id, 's') << endl;
			   cout << "Firstname : " << getName(stud_id, 'f') << endl;
			   cout << "===================================================================================\n";

			   //Displaying the courses of the individual
			   cout << left << setw(9) << "CID";
			   cout << left << setw(45) << "TITLE";
			   cout << left << setw(9) << "CA";
			   cout << left << setw(7) << "EXAM";
			   cout << left << setw(8) << "FINAL";
			   cout << left << "GRADE\n";
			   cout << "===================================================================================\n\n";

			   //Open the file with the marks
			   enrolRead.open("enrolment.txt");

			   //Check for the file's availability
			   if (!enrolRead) {
				   cout << "\nenrolment.txt was not found in this directory\n";
				   cout << "Check the directory to see if the file is already created.\n";
				   goto main_menu;
			   }

			   //Making variables ready to accept data
			   string data; int row_counter = 0, counter = 0; string course_code;
			   string exam_mark, final_mark, ca_mark;

			   //These variables are for holding the overall averages
			   int ca_total = 0, exam_total = 0, final_total = 0, active_rows = 0;
			   double average_ca, average_exam, average_final, average;

			   //Search through the results and deliver the needed information
			   while (enrolRead >> data) {
				   //storing the course code
				   if (row_counter % 5 == 0) {
					   course_code = data;
				   }

				   //Print out information if there is a match
				   if (string_student_id == data) {
					   cout << left << setw(9) << course_code;
					   cout << left << setw(45) << getCourseTitle(course_code);

					   //Move to the next column
					   counter++;

					   //check active rows
					   active_rows++;
				   }
				   else if (counter == 1) {
					   ca_mark = getMarks(stud_id, course_code, 'c');
					   cout << left << setw(9) << ca_mark;

					   //calculate the sum
					   getSum(toInt(ca_mark));

					   //Move to the next column
					   counter++;

					   //calculate this column
					   int c = toInt(ca_mark);

					   ca_total += c;
				   }
				   else if (counter == 2) {
					   exam_mark = getMarks(stud_id, course_code, 'e');
					   cout << left << setw(7) << exam_mark;

					   //calculate the sum and average
					   average = getAverage(getSum(toInt(exam_mark)));

					   //reset the sum function
					   getSum(0, true);

					   //move to the next column
					   counter++;

					   //calculate this column
					   int c = toInt(exam_mark);

					   exam_total += c;
				   }
				   else if (counter == 3) {
					   final_mark = getMarks(stud_id, course_code, 'f');
					   cout << left << setw(8) << final_mark;

					   cout << left << gradeMark(average) << endl;

					   //reset the counter;
					   counter = 0;

					   //calculate this column
					   int c = toInt(final_mark);

					   final_total += c;
				   }

				   row_counter++;
			   }

			   //Getting the average
			   average_ca = getAverage(ca_total, active_rows);
			   average_exam = getAverage(exam_total, active_rows);
			   average_final = getAverage(final_total, active_rows);

			   //The overall stretch
			   cout << "\n===================================================================================\n";
			   cout << left << setw(54) << "OVERALL AVERAGE";
			   cout << left << setw(9) << average_ca;
			   cout << left << setw(7) << average_exam;
			   cout << left << setw(8) << average_final;
			   cout << left << gradeMark(getAverage(average_ca + average_exam));
			   cout << "\n===================================================================================\n";
			   break;
		   }

		   case 4: {
			   system("cls");

			   cout << "GENERATE SUMMARY STATISTICS\n";
			   cout << "===========================\n\n";

			   cout << "================================================================================================\n";
			   cout << setw(9) << left << "CID";
			   cout << setw(45) << left << "TITLE";
			   cout << setw(25) << left << "NUMBER OF STUDENTS";
			   cout << left << "COURSE AVERAGE\n";
			   cout << "================================================================================================\n\n";
			   summary();
			   break;
		   }

		   case 5:
			   cout << "\n\nHope to see you again! Bye :)\n"; exit(1);
		   }

		   //Making way for the user to reperform the program
		   cout << "\n\nPress <y> to  go to the main menu or any other key to exit\n";

		   if (getch() == 'y') {
			   system("cls");
			   goto main_menu;
		   }
		   else {
			   cout << "\n\nHope to see you again! Bye :)\n"; exit(1);
		   }

		   return 0;
}

//Defining functions
int checkInput(int value, string someText, int min, int max) {
	//Initialize the value to 0
	value = 0;

	//The string below would be used to check if there are any errors in the input value
	string checkValue;

	//Displaying the text to show and receive input from user
start: {
	cout << someText;
	cin >> checkValue;
	}

	   //The boolean below would be used to detect error
	   bool errorFound = false;

	   //Checking for anything not a number in the value	
	   for (int i = 0; i < checkValue.length(); i++) {
		   if (!isdigit(checkValue[i])) {
			   errorFound = true;
			   break;
		   }
	   }

	   if (errorFound) {
		   cout << "\nInvalid input found! Enter a valid number\n";
		   goto start;
	   }

	   //If the value is found to be purely made of numbers, then it should proceed to the other error checkings
	   stringstream tempInt(checkValue);
	   tempInt >> value;

	   //Preventing 0 as an answer
	   while (value < min || value > max) {
		   cout << "\nInvalid input found! Please enter a valid input of range "
			   << min << " and " << max << "\n";
		   goto start;
	   }

	   //return the value of the user if there is no error
	   return value;
}

/*
	//In case the above is quite too complicated, you can use this
	//The previous one checks the errors by characters but this one
	//prevents the user from continuing with the programme if it is found
	//that the user starts without a number
	//Values that do not start with an alphabet are accepted, and the first
	//numbers encountered are seen as the original answer and the rest are ignored.
	//In case this is used, add cin.clear() to the next line of the options = checkInput()
	//line. This is to prevent an error in an input buffer from moving into the next buffer

	int checkInput(int value, string someText, int min, int max){
		start:{
			cout << someText;
		}

		while(!(cin >> value) || value < min || value > max){
			cout << "\nInvalid input identified! Please enter a valid value\n";
			cin.clear();
			cin.ignore(123, '\n');
			goto start;
		}

		return value;
*/

bool retreiveFromFile(string filename, ifstream &file, string filetype) {
	//Opening the file
	file.open(filename.c_str());

	//This would be used to act as the medium to display the info from the file
	string data;

	if (!file) {
		cout << "\nThe required file was not found";
		return false;
	}

	if (filetype == "txt") {
		while (getline(file, data)) {
			cout << data << endl;
		}
	}
	else if (filetype == "csv") {
		while (getline(file, data, ',')) {
			cout << data << endl;
		}
	}

	file.close();
	return true;
}

string getName(int id, char part_of_name) {
	//We will be checking the student.txt file to gain these records
	ifstream student;
	student.open("students.txt");

	if (!student) {
		//If the file is not found, the program will force shut
		cout << "\nstudents.txt was not found\n";
		exit(1);
	}

	//These two strings will be used to get the names of the respective index number
	string fname, sname, data, temp_id;

	//changing the id into string format for easy comparism
	temp_id = toString(id);

	//this variable is to help choose the right name and also to help break the loop
	int counter = 0;

	//This boolean would be used to check if there was a match or not
	bool alarm = true;

	while (student >> data) {
		//Checking for a match
		if (temp_id == data) {
			//start the counter
			counter++;
		}
		else if (counter == 1) {
			sname = data;
			counter++;
		}
		else if (counter == 2) {
			fname = data;
			alarm = false;
			break;
		}

		//The purpose of using the if else if conditions here is to help create a simple
		//logic of moving three times (signifying 3 columns) before the next line. Before
		//the next line is what I have introduced as break, and this will break the loop
	}

	if (part_of_name == 's' && !alarm) {
		return sname;
	}
	else if (part_of_name == 'f' && !alarm) {
		return fname;
	}
	else if (alarm) {
		system("cls");
		cout << "No records were found\n\n";

		//Start everything again from the main function and stop the execution
		//of this function
		main(); exit(0);
	}

	//Closing the file
	student.close();
}

string getCourseTitle(string course_code)
{
	//Opening the course file
	ifstream course;
	course.open("courses.csv");

	//making sure the courses.csv is in the file directory
	if (!course) {
		system("cls");
		cout << "\ncourses.csv was not found in this directory\n\n";
		main(); exit(0);
	}

	//string to retreive data into
	string data, info, word_break;

	int i = 0;

	while (getline(course, data, '\n')) {
		//break the inserted word
		stringstream s(data);

		//Check to see if there is a match
		while (getline(s, word_break, ',')) {
			if (word_break == course_code) {
				i++;
			}
			else if (i == 1) {
				return word_break;
			}
		}

	}
}

string getMarks(int id, string course_code, char type_of_test)
{
	ifstream file;
	file.open("enrolment.txt");

	//creating a variable to receive the marks from the file
	string data, ca, exam, final, temp_id;

	//A variable to count the number of rows
	int counter = 0, row_counter = 0;

	temp_id = toString(id);

	//The work of this temporal variable is that it would be used to grab
	//the course code which is the first columns and the student id is in
	//the second column
	string temp_course_code;

	while (file >> data) {
		//Whenever the reading gets to the first column, it should store the course
		//code of that row
		if (row_counter % 5 == 0) {
			temp_course_code = data;
		}

		//Preparing for the break in a row
		if (temp_id == data && course_code == temp_course_code) {
			counter++;
		}
		else if (counter == 1) {
			counter++;
			ca = data;
		}
		else if (counter == 2) {
			exam = data;
			counter++;
		}
		else if (counter == 3) {
			final = data;
			break;
		}

		row_counter++;
	}

	if (type_of_test == 'c') {
		return ca;
	}
	else if (type_of_test == 'e') {
		return exam;
	}
	else if (type_of_test == 'f') {
		return final;
	}
	else {
		system("cls");

		cout << "No data was found\n\n";

		//Stop execution of the function
		main(); exit(0);
	}
}

string toString(int value) {
	stringstream s;
	s << value;

	return s.str();
}

string gradeMark(double mark)
{
	if (mark >= 89.5) {
		return "A+";
	}
	else if (mark >= 84.5) {
		return "A";
	}
	else if (mark >= 79.5) {
		return "A-";
	}
	else if (mark >= 74.5) {
		return "B+";
	}
	else if (mark >= 69.5) {
		return "B";
	}
	else if (mark >= 64.5) {
		return "C+";
	}
	else if (mark >= 59.5) {
		return "C";
	}
	else if (mark >= 54.5) {
		return "D+";
	}
	else if (mark >= 49.5) {
		return "D";
	}
	else if (mark >= 44.5) {
		return "E+";
	}
	else if (mark >= 39.5) {
		return "E";
	}
	else if (mark >= 34.5) {
		return "F+";
	}
	else {
		return "F";
	}
}

int getSum(int mark, bool restart) {
	static int sum = 0;

	//Calculate the sum
	sum += mark;

	if (restart) {
		sum = 0;
	}

	return sum;
}

int toInt(string value) {
	stringstream v(value);

	int n;

	v >> n;

	return n;
}

double getAverage(int sum, int divisor)
{
	double av = sum / static_cast<float> (divisor);

	return av;
}

void summary()
{
	ifstream course;
	course.open("courses.csv");

	if (!course) {
		cout << "\nA file could not be found. Please check this directory to see if courses.csv and\n"
			<< "enrolment.txt are in this location\n";
		main(), exit(0);
	}

	string course_data, enrol_data, break_words, code;

	//Creating a pointer to be shifting through the  columns and rows
	int row_shift = 0, col_shift = 0;

	while (getline(course, course_data)) {
		stringstream s(course_data);

		while (getline(s, break_words, ',')) {
			if (col_shift % 4 == 0 && row_shift > 0) {
				cout << setw(9) << break_words;
				code = break_words;
			}
			else if (col_shift % 4 == 1 && row_shift > 0) {
				cout << left << setw(45) << break_words;
				cout << left << setw(25) << static_cast<int>(count_students(code));
				cout << left << fixed << setprecision(2) << count_students(code, true);
				cout << endl;
			}

			col_shift++;
		}

		row_shift++;
	}

	cout << "\n================================================================================================\n";
	cout << "TOTAL NUMBER OF STUDENTS: " << static_cast<int>(count_students("", false, true)) << endl;
	cout << "================================================================================================\n";

	course.close();
}

double count_students(string course_code, bool average, bool all)
{
	ifstream enrol, student;
	enrol.open("enrolment.txt");
	student.open("students.txt");

	int count_course = 0, marks = 0, col_pointer = 0, all_count = 0;
	float av;
	string data;

	//Making preparations for the marks and averages
	while (enrol >> data) {
		if (course_code == data) {
			count_course++;
			col_pointer++;
		}
		else if (col_pointer == 1) {
			col_pointer++;
		}
		else if (col_pointer == 2) {
			int newData = toInt(data);

			marks += newData;
			col_pointer++;
		}
		else if (col_pointer == 3) {
			int newData = toInt(data);

			marks += newData;

			//reset the pointer
			col_pointer = 0;
		}
	}

	//counting all students
	while (getline(student, data)) {
		all_count++;
	}

	enrol.close();

	if (average) {
		//Preventing nan or infinite division
		if (count_course == 0) {
			count_course = 1;
		}

		av = marks / static_cast<float>(count_course);
		return av;
	}
	else {
		if (all)
			return all_count;
		else
			return count_course;
	}
}

