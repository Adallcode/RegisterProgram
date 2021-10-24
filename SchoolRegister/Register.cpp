#include "Register.h"

Register::Register(int id, const string & name, const string & lastName, int english, 
	int spanish, int german)
	:mStudentID(id),
	mEnglishQualification(english),
	mSpanish(spanish),
	mGerman(german)
{
	SetName(name);
	SetLastName(lastName);
}

void Register::SetName(const string & name)
{
	const char * temp = name.data();

	size_t size = name.size();

	size = (size < 16) ? size : 15;

	for (size_t i = 0; i < size; i++)
		mName[i] = temp[i];

	//Just add the null caracter at the end
	mName[size] = '\0';
}

void Register::SetLastName(const string & lastName)
{
	const char * temp = lastName.data();

	size_t size = lastName.size();

	size = (size < 16) ? size : 15;

	for (size_t i = 0; i < size; i++)
		mLastName[i] = temp[i];

	//Just add the null caracter at the end
	mLastName[size] = '\0';
}
