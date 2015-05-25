#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//using namespace std;
using std::cout;
using std::cin;
using std::endl;

struct Score
{
	int mid_term;
	int final_score;
	int total_score;
	int cat_one_score;
	int cat_two_score;
};

struct Student
{
	int student_id;
	std::string name;
	std::string sex;
	Score score;

	void save(std::ofstream& fout) const
	{
		fout << "Student Records" << endl;
		fout << "===============" << endl;
		fout << "Student_id :" << student_id << endl;
		fout << "Student name : " << name << endl;
		fout << "Student gender : " << sex << endl;
		fout << "Student cat one score : " << score.cat_one_score << endl;
		fout << "Student cat two score : " << score.cat_two_score << endl;
		fout << "Student mid term score : " << score.mid_term << endl;
		fout << "Student final score : " << score.final_score << endl;
		fout << "Student total score : " << score.total_score << endl;
		fout << endl;
		fout << endl;
	}

};



void add_student(std::vector<Student*>& std_db);
void delete_student(std::vector<Student*>& std_db);
void update_student(std::vector<Student*>& std_db);
void view_all_student_records(std::vector<Student*>& std_db);
void get_student_score(std::vector<Student*>& std_db);
void get_average_score(std::vector<Student*>& std_db);
void get_student_min_total_score(std::vector<Student*>& std_db); 
void get_student_max_total_score(std::vector<Student*>& std_db); 
void find_student_by_id(std::vector<Student*>& std_db);
void sort_by_total_score(std::vector<Student*>& std_db);
void save_all_student_records(std::vector<Student*>& std_db);


int main()
{
	//a way to store students
	std::vector<Student*> student_db;

	bool done = false;
	int choice = 0;
	char confirm = 'q';

	while (!done)
	{
		cout << " =========================== " << endl;
		cout << "        MENU                 " << endl;
		cout << " =========================== " << endl;

		cout << "Choose operation for records " << endl;
		cout << "1) Add student records " << endl;
		cout << "2) Delete student records " << endl;
		cout << "3) Update student records " << endl;
		cout << "4) View all student records " << endl;
		cout << "5) View a student scores " << endl;
		cout << "6) Calculate average score of student selected " << endl;
		cout << "7) Show student who gets the max total score " << endl;
		cout << "8) Show student who gets min total score " << endl;
		cout << "9) Find student by Id" << endl;
		cout << "10) sort records by total scores " << endl;
		cout << "11) Save all student records " << endl;
		cout << "12) Exit the program " << endl;

		cout << "Enter your choice " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			//adding a student
			cout << "Adding a student " << endl;
			add_student(student_db);

			cout << "Current student count: " << endl;
			cout << student_db.size() << endl;

			break;
		case 2:
			cout << "Delete student record: " << endl;
			if (student_db.size() > 0)
			{
				delete_student(student_db);
			}
			else
			{
				cout << "No records in student database " << endl;
			}

			break;
		case 3:
			cout << "Updating student record " << endl;
			if (student_db.size() == 0)
			{
				cout << "No records in student database" << endl;
			}
			else
			{
				update_student(student_db);
			}
			break;
		case 4:
			cout << " Viewing all student records " << endl;
			if (student_db.size() > 0)
			{
				view_all_student_records(student_db);
			}
			else
			{
				cout << "No records in student database " << endl;
			}
			break;
		case 5:
			cout << "Viewing a students scores " << endl;
			if (student_db.size() > 0)
			{
				get_student_score(student_db);
			}
			else
			{
				cout << "No records in student database " << endl;
			}

			break;
		case 6:
			cout << "Calculate average score of student selected " << endl;
			if (student_db.size() > 0)
			{
				get_average_score(student_db);
			}
			else
			{
				cout << "No records in student database " << endl;
			}

			break;
		case 7:
			cout << " Show student who gets the max total score  " << endl;
			if (student_db.size() > 0)
			{
				get_student_max_total_score(student_db);
			}
			else
			{
				cout << "No records in student database " << endl;
			}

			break;
		case 8:
			cout << "Show student who gets the min total score " << endl;
			if (student_db.size() > 0)
			{
				get_student_min_total_score(student_db);
			}
			else
			{
				cout << "No records in student database " << endl;
			}

			break;
		case 9:
			cout << "Find student by Id " << endl;
			if (student_db.size() > 0)
			{
				find_student_by_id(student_db);
			}
			else
			{
				cout << "No records in student database " << endl;
			}

			break;
		case 10:
			cout << "sort records by total scores  " << endl;
			if (student_db.size() > 0)
			{
				sort_by_total_score(student_db);
			}
			else
			{
				cout << "No records in student database " << endl;
			}

			break;
		case 11:
			cout << "saving all student data records to a file " << endl;
			if (student_db.size() > 0)
			{
				save_all_student_records(student_db);
			}
			else
			{
				cout << "No records in student database " << endl;
			}
			break;
		case 12:
			cout << "quitting the program " << endl;
			done = true;
			break;
		default:
			cout << "menu choice does not exist" << endl;
			break;
		}

		cout << "Do you wish to continue using the student records program? " << endl;
		cout << "(y)es or (n)o " << endl;
		cin >> confirm;
		if (confirm == 'n' || confirm == 'N')
		{
			done = true;
		}

	}

	for (size_t i = 0; i < student_db.size(); ++i)
	{
		delete student_db[i];
	}




}

void add_student(std::vector<Student*>& std_db)
{
	Student* std = new Student();

	cout << "Enter Student details " << endl;
	cout << "Enter student id: ";
	cin >> std->student_id;
	cout << "Enter Student Name: ";
	cin >> std->name;
	cout << "Enter Student Sex: ";
	cin >> std->sex;
	cout << "Enter Student cat_one score: ";
	cin >> std->score.cat_one_score;
	cout << "Enter student cat_two score: ";
	cin >> std->score.cat_two_score;
	cout << "Enter student mid_term score: ";
	cin >> std->score.mid_term;
	cout << "Enter student final score: ";
	cin >> std->score.final_score;

	int cat_one = std->score.cat_one_score;
	int cat_two = std->score.cat_two_score;
	int mid_term = std->score.mid_term;
	int final = std->score.final_score;
	int total = cat_one + cat_two + mid_term + final;

	std->score.total_score = total;

	//add the student to the db
	std_db.push_back(std);

	//to remove check vec size // note that this is very wrong
	//delete std;
	//std = nullptr;


}

void view_all_student_records(std::vector<Student*>& std_db)
{
	for (size_t i = 0; i < std_db.size(); ++i)
	{
		cout << "Student " << i << endl;
		cout << "Name " << std_db[i]->name << endl;
		cout << "Sex " << std_db[i]->sex << endl;
		cout << "Student_ID " << std_db[i]->student_id << endl;
		cout << "CAT one score " << std_db[i]->score.cat_one_score << endl;
		cout << "CAT two score " << std_db[i]->score.cat_two_score << endl;
		cout << "Mid term score " << std_db[i]->score.mid_term << endl;
		cout << "Final score " << std_db[i]->score.final_score << endl;
		cout << "Total score " << std_db[i]->score.total_score << endl;
		cout << endl;
		cout << endl;
	}
}

void delete_student(std::vector<Student*>& std_db)
{
	int num_id = 0;
	cout << "Enter student_ID number to delete their records: " << endl;
	cin >> num_id;

	for (size_t i = 0; i < std_db.size(); ++i)
	{
		if (num_id == std_db[i]->student_id)
		{
			delete std_db[i];
			std_db.erase(std_db.begin() + i);
			break;
		}
	}
	cout << "Student record deleted " << endl;
	cout << "Student count in database " << std_db.size() << endl;
}

void update_student(std::vector<Student*>& std_db)
{
	int num_id = 0;
	char confirm_change = 'q';
	char confirm_exit = 'q';
	int update_choice = 0;
	bool update_done = false;
	cout << "Enter student id to update their records " << endl;
	cin >> num_id;
	for (size_t i = 0; i < std_db.size(); ++i)
	{
		if (num_id == std_db[i]->student_id)
		{
			//show current values
			cout << "Student record current values " << endl;
			cout << "Student name " << std_db[i]->name << endl;
			cout << "Student gender " << std_db[i]->sex << endl;
			cout << "cat one score " << std_db[i]->score.cat_one_score << endl;
			cout << "cat two score " << std_db[i]->score.cat_two_score << endl;
			cout << "mid term score " << std_db[i]->score.mid_term << endl;
			cout << "final score " << std_db[i]->score.final_score << endl;
			cout << "Total score " << std_db[i]->score.total_score << endl;
			//switch to choose attribute to change
			cout << "do you wish to change any of the records " << endl;
			cout << "(y)es or  (n)o " << endl;
			cin >> confirm_change;
			if (confirm_change == 'y' || confirm_change == 'Y')
			{
				while (!update_done)
				{
					cout << "enter a choice for the field you want to change: " << endl;
					cout << "Note you cant change the student id " << endl;
					cout << "1) Name " << endl;
					cout << "2) Sex " << endl;
					cout << "3) Cat one score " << endl;
					cout << "4) Cat two score " << endl;
					cout << "5) Mid term score " << endl;
					cout << "6) Final score " << endl;
					cin >> update_choice;

					switch (update_choice)
					{
					case 1:
						cout << "Type in new name: " << endl;
						cin >> std_db[i]->name;
						break;
					case 2:
						cout << "Type in new gender " << endl;
						cin >> std_db[i]->sex;
						break;
					case 3:
						cout << "Type new cat one score " << endl;
						cin >> std_db[i]->score.cat_one_score;
						break;
					case 4:
						cout << "Type new cat two score " << endl;
						cin >> std_db[i]->score.cat_two_score;
						break;
					case 5:
						cout << "Type new mid term score " << endl;
						cin >> std_db[i]->score.mid_term;
						break;
					case 6:
						cout << "Type new Final score " << endl;
						cin >> std_db[i]->score.final_score;
						break;
					default:
						cout << "Menu item does not exist " << endl;
						break;
					}
					cout << "Do you wish to continue changing this student's attributes: " << endl;
					cout << "(y)es or (n)o " << endl;
					cin >> confirm_exit;
					if (confirm_exit == 'n' || confirm_exit == 'N')
					{
						update_done = true;
					}
				}

			}
		}
	}
	cout << "Done updating the Students records " << endl;
}

void find_student_by_id(std::vector<Student*>& std_db)
{
	int num_id = 0;
	char confirm_view = 'q';
	cout << "Enter student id " << endl;
	cin >> num_id;

	for (size_t i = 0; i < std_db.size(); ++i)
	{
		if (num_id == std_db[i]->student_id)
		{
			cout << "student record found at " << i << endl;
			cout << "do you wish to view the students records " << endl;
			cout << "(y)es or (n)o " << endl;
			cin >> confirm_view;
			if (confirm_view == 'y' || confirm_view == 'Y')
			{
				cout << "Student Name " << std_db[i]->name << endl;
				cout << "Student sex " << std_db[i]->sex << endl;
				cout << "Student_ID " << std_db[i]->student_id << endl;
				cout << "CAT one score " << std_db[i]->score.cat_one_score << endl;
				cout << "CAT two score " << std_db[i]->score.cat_two_score << endl;
				cout << "Mid term score " << std_db[i]->score.mid_term << endl;
				cout << "Final score " << std_db[i]->score.final_score << endl;
				cout << "Student total score " << std_db[i]->score.total_score << endl;
			}
			break;
		}
		else
		{
			cout << "student record does not exist" << endl;
		}
	}
}

void get_student_score(std::vector<Student*>& std_db)
{
	int num_id = 0;
	cout << "Enter student id " << endl;
	cin >> num_id;

	for (size_t i = 0; i < std_db.size(); ++i)
	{
		if (num_id == std_db[i]->student_id)
		{
			cout << "Student Score records " << endl;
			cout << "Cat one score " << std_db[i]->score.cat_one_score << endl;
			cout << "Cat two score " << std_db[i]->score.cat_two_score << endl;
			cout << "Mid term score " << std_db[i]->score.mid_term << endl;
			cout << "Final Score " << std_db[i]->score.final_score << endl;
			cout << "Total Score " << std_db[i]->score.total_score << endl;
			break;
		}
		else
		{
			cout << "Student record does not exist " << endl;
		}
	}
}

void get_average_score(std::vector<Student*>& std_db)
{
	int num_id = 0;
	int average = 0;
	cout << "Enter the students id " << endl;
	cin >> num_id;

	for (size_t i = 0; i < std_db.size(); ++i)
	{
		if (num_id == std_db[i]->student_id)
		{
			cout << "The students total score is " << endl;
			cout << "Total: " << std_db[i]->score.total_score << endl;

			cout << "The average score for the student from 4 exams: " << endl;
			average = std_db[i]->score.total_score / 4;
			cout << "Average: " << average;
			break;
		}
		else
		{
			cout << "student record does not exist" << endl;
		}
	}
}

void sort_by_total_score(std::vector<Student*>& std_db)
{
	//without using std sort()
	cout << "Sorting the records by total score " << endl;
	for (size_t i = 0; i < std_db.size(); ++i)
	{
		for (size_t j = 0; i < std_db.size(); ++i)
		{
			if (std_db[i]->score.total_score < std_db[j]->score.total_score)
			{
				Student* temp = std_db[i];
				std_db[i] = std_db[j];
				std_db[j] = temp;
			}
		}
	}

	cout << "the new sorted vector " << endl;
	for (size_t i = 0; i < std_db.size(); ++i)
	{
		cout << std_db[i]->score.total_score << " ";
	}
	cout << endl;

}

void get_student_min_total_score(std::vector<Student*>& std_db)
{
	sort_by_total_score(std_db);

	cout << "The student with least total score: " << endl;
	cout << std_db.front()->name << " ";
	cout << std_db.front()->score.total_score << endl;
}

void get_student_max_total_score(std::vector<Student*>& std_db)
{
	sort_by_total_score(std_db);
	cout << "The student with max total score: " << endl;
	cout << std_db.back()->name << " ";
	cout << std_db.back()->score.total_score << endl;
}

void save_all_student_records(std::vector<Student*>& std_db)
{
	std::ofstream fout("student_data.txt");
	for (size_t i = 0; i < std_db.size(); ++i)
	{
		std_db[i]->save(fout);
	}

	fout.close();

}