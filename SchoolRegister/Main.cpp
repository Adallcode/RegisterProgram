#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>

#include "Register.h"

using namespace std;


void CreateNewRegister(fstream& file);
void EliminateRegister(fstream& file);
void ShowRegister(fstream& file);
void ModifyRegister(fstream& file);
void Option();
void PrintRegister(const Register& reg);
void ModificationOption();


int main(int arcg, char **arcv)
{
	
	/*/With this code just create 100 register in binary
	//This code was already executed to create a file
	ofstream WriteOnFile("File.dat", ios::out | ios::binary);

	if (!WriteOnFile)
	{
		cout << "The register could not be open.\n";
		exit(1);
	}

	Register Temp;

	for (int i = 0; i < 100; i++)
		WriteOnFile.write(reinterpret_cast<const char *>(&Temp), sizeof(Register) );*/



	fstream File("File.dat", ios::in | ios::out | ios::binary);

	if (!File)
	{
		cout << "The register could not be open.\n";
		exit(1);
	}

	//Store the option
	int option;

	Option();
	cin >> option;

	while (option != 5)
	{
		switch (option)
		{
		case 1:
			CreateNewRegister(File);
			break;

		case 2:
			EliminateRegister(File);
			break;
		
		case 3:
			ModifyRegister(File);
			break;

		case 4:
			ShowRegister(File);
			break;

		default:
			cout << "\nNot correct option.\n";
			break;
		}

		cout << endl;

		Option();
		cin >> option;

	}

	cout << "\nProgram end.\n";

	return 0;
}

void CreateNewRegister(fstream & file)
{
	int id;

	cout << "\nChoose a ID from 1 to 100 to create a new register:  ";
	cin >> id;

	if (id > 0 && id <= 100)
	{
		//If the id chosen is not 0 then create the register otherwise the register already exist
		Register newRegister;

		file.seekg(sizeof(Register) * (id - 1));
		file.read(reinterpret_cast<char *>(&newRegister), sizeof(Register));

		if (newRegister.StudentID() == 0)
		{
			string name, lastName;
			int english;
			int spanish;
			int german;

			cin.ignore();
			cout << "\nEnter your name: ";
			getline(cin, name);

			cout << "\nEnter your last name: ";
			getline(cin, lastName);

			cout << "\nEnter the English qualification: ";
			cin >> english;

			cout << "\nEnter the Spanish qualification: ";
			cin >> spanish;

			cout << "\nEnter the German qualification: ";
			cin >> german;


			newRegister.SetStudentID(id);
			newRegister.SetName(name);
			newRegister.SetLastName(lastName);
			newRegister.SetEnglishQualification(english);
			newRegister.SetSpanish(spanish);
			newRegister.SetGerman(german);


			//Now add this new register in the correct place
			file.seekp(sizeof(Register) * (id - 1));
			file.write(reinterpret_cast<const char *>(&newRegister), sizeof(Register));

			cout << "\nThe register was successfully created.\n";

			PrintRegister(newRegister);
		}
		else
		{
			cout << "\nThe register with ID: " << id << " already exist.\n";
		}

	}
	else
	{
		cout << "\nThe ID: " << id << " is out of range.\n";
	}
}

void EliminateRegister(fstream & file)
{
	int id;

	cout << "\nEnter the ID of the register to eliminate:  ";
	cin >> id;

	if (id > 0 && id <= 100)
	{
		Register newRegister;

		file.seekg(sizeof(Register) * (id - 1));
		file.read(reinterpret_cast<char *>(&newRegister), sizeof(Register));

		//If this register exist than the student id is > 0
		if (newRegister.StudentID() > 0)
		{
			Register temp;

			file.seekp(sizeof(Register) * (id - 1));
			file.write(reinterpret_cast<const char *>(&temp), sizeof(Register));
			

			cout << "\nThe register with ID: " << id << " was eliminated.\n";
		}
		else
		{
			cout << "\nThe register with ID: " << id << " does not exist.\n";
		}
	}
	else
	{
		cout << "\nID: " << id << " out of range.\n";
	}
}

void ShowRegister(fstream& file)
{
	int id;

	cout << "\nEnter the register ID :  ";
	cin >> id;

	if (id > 0 && id <= 100)
	{
		//If the id chosen is not 0 then create the register otherwise the register already exist
		Register Temp;

		file.seekg(sizeof(Register) * (id - 1));
		file.read(reinterpret_cast<char *>(&Temp), sizeof(Register));

		if (Temp.StudentID() != 0)
		{
			PrintRegister(Temp);
		}
		else
		{
			cout << "\nThe register with ID: " << id << " does not exist.\n";
		}

	}
	else
	{
		cout << "\nThe ID: " << id << " is out of range.\n";
	}
}

void ModifyRegister(fstream & file)
{
	int id;

	cout << "\nEnter the Register ID to modify it: ";
	cin >> id;

	//First verify if the ID is in range
	if (id > 0 && id <= 100)
	{
		//The register exist if the Student ID is not 0
		Register Temp;

		//Put the pointer at the begin of this amount of bytes and than read
		file.seekg(sizeof(Register) * (id - 1));
		file.read(reinterpret_cast<char *>(&Temp), sizeof(Register));

		if (Temp.StudentID() != 0)
		{
			int option;

			ModificationOption();
			cin >> option;

			while (option != 6)
			{
				switch (option)
				{
				case 1:
				{
					cout << "\nCurrent Name: " << Temp.Name() << endl;

					string name;

					cin.ignore();
					cout << "\nWrite the new Name: ";
					getline(cin, name);

					Temp.SetName(name);
					break;
				}

				case 2:
				{
					cout << "\nCurrent Last Name: " << Temp.LastName() << endl;

					string lastName;

					cin.ignore();
					cout << "\nWrite the new Last Name: ";
					getline(cin, lastName);

					Temp.SetLastName(lastName);
					break;
				}

				case 3:
				{
					cout << "\nCurrent English qualification: " << Temp.EnglishQualification() << endl;

					int english;

					cout << "\nEnter the new English qualification: ";
					cin >> english;

					Temp.SetEnglishQualification(english);
					break;
				}

				case 4:
				{
					cout << "\nCurrent Spanish qualification: " << Temp.Spanish() << endl;

					int spanish;

					cout << "\nEnter the new Spanish qualification: ";
					cin >> spanish;

					Temp.SetSpanish(spanish);
					break;
				}

				case 5:
				{
					cout << "\nCurrent German qualification: " << Temp.German() << endl;

					int german;

					cout << "\nEnter the new German qualification: ";
					cin >> german;

					Temp.SetGerman(german);
					break;
				}

				default:
					cout << "\nOption is not correct.\n";
					break;

				}//End the switch

				//Now write the modified data
				file.seekp(sizeof(Register) * (id - 1));
				file.write(reinterpret_cast<const char *>(&Temp), sizeof(Register));

				cout << endl;

				ModificationOption();
				cin >> option;

			}//End the while
		}
		else
		{
			cout << "\nRegister with ID: " << id << " does not exist.\n";
		}

	}
	else
	{
		cout << "\nID: " << id << " out of range.\n";
	}
}

void Option()
{
	cout << "Options.\n"
		<< "1. Create a new Register.\n"
		<< "2. Eliminate a Register.\n"
		<< "3. Modify a Register.\n"
		<< "4. Show Register.\n"
		<< "5. End the program.\n"
		<< "Please enter your option: ";
}

void PrintRegister(const Register & reg)
{
	cout << endl;

	cout << right << setw(25) << "Register";

	cout << endl << endl;


	cout << left << setw(16) << "Name" << setw(16) << "Last Name" << setw(5) << "ID" << setw(9) << "English"
		<< setw(9) << "Spanish" << setw(8) << "German" << endl;

	cout << left << setw(16) << reg.Name() << setw(16) << reg.LastName() << setw(5) << reg.StudentID()
		<< setw(9) << reg.EnglishQualification() << setw(9) << reg.Spanish()
		<< setw(8) << reg.German() << endl;
}

void ModificationOption()
{
	cout << "\nModification Options.\n"
		<< "1. Modify name.\n"
		<< "2. Modify last name.\n"
		<< "3. Modify English.\n"
		<< "4. Modify Spanish.\n"
		<< "5. Modify German.\n"
		<< "6. Quit Modification.\n"
		<< "Please enter your option: ";
}
