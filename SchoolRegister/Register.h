#pragma once

#include <string>

using namespace std;


class Register
{
public:
	Register(int id = 0, const string& name = "", const string& lastName = "", int english = 0,
		int spanish = 0, int german = 0);


	//Some overloader operators

	
	friend bool operator==(const Register& a, const Register& b)
	{
		//If the student id are iqual than are the same register
		return (a.StudentID() == b.StudentID());
	}

	Register & operator=(const Register& reg)
	{
		//Avoid to add the same object therefore just return itself
		if (*this == reg)
			return *this;

		*this = reg;

		return *this;
	}


	//Student id
	void SetStudentID(int id) { mStudentID = id; }
	int StudentID()const { return mStudentID; }

	//Name and last name
	void SetName(const string& name);
	void SetLastName(const string& lastName);

	string Name()const { return mName; }
	string LastName()const { return mLastName; }

	//Qualifications
	void SetEnglishQualification(int english) { mEnglishQualification = english; }
	int EnglishQualification()const { return mEnglishQualification; }

	void SetSpanish(int spanish) { mSpanish = spanish; }
	int Spanish()const { return mSpanish; }

	void SetGerman(int german) { mGerman = german; }
	int German()const { return mGerman; }

private:
	int mStudentID;

	char mName[15];
	char mLastName[15];

	//Qualifications
	int mEnglishQualification;
	int mSpanish;
	int mGerman;
};

