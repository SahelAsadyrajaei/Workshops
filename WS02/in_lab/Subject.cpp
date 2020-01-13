#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Subject.h"
#include "utils.h"


using namespace std;

namespace sdds {

	// function overload- validating subject name 
	Subject sbj;
	void read(char* subject) {
		cout << "Enter subject name: ";
		read(subject, 70, "Name is too long, only 70 characters allowed!\nRedo Entry: ");
	}
	// function overload- validating section number 
	void read(int& sectionNumbers) {
		cout << "Enter number of sections: ";
		read(sectionNumbers, 1, 10, "Invalid Number of sections, 1<=ENTRY<=10\nRedo Entry: ");

	}
	// function overload- validating number of students in each section 
	void read(int student[], int secNumber) {
		cout << "Enter the number of students in each one of the " << secNumber << " sections:" << endl;
		for (int i = 0; i < secNumber; i++)
		{
			cout << "" << i + 1 << ": ";
			read(student[i], 5, 35, "Invalid Number of students, 5<=ENTRY<=35\nRedo Entry: ");
		}

	}
	// calling above functions and allocating memory dynamically based on user input values
	void read(Subject& sampleSubject) {
		char name[71];
		read(name);
		sampleSubject.m_subjectName = new char[strlen(name) + 1];
		strcpy(sampleSubject.m_subjectName, name);

		sampleSubject.m_noOfSections = new int;
		read(*sampleSubject.m_noOfSections);


		sampleSubject.m_noOfStdsInSecs = new int[*sampleSubject.m_noOfSections];
		read(sampleSubject.m_noOfStdsInSecs, *sampleSubject.m_noOfSections);


	}
	// retrieving and printing values that has been stored in array 
	int report(const Subject& sub) {
		int totalStudent = 0;
		for (int i = 0; i < *sub.m_noOfSections; i++)
		{
			if (i + 1 == *sub.m_noOfSections)
				cout << sub.m_noOfStdsInSecs[i] << endl;
			else
				cout << sub.m_noOfStdsInSecs[i] << ",";

			totalStudent += sub.m_noOfStdsInSecs[i];
		}


		cout << sub.m_subjectName << ": " << totalStudent << endl;
		return totalStudent;
	}
	//deallocating dynamic memory
	void freeMem(Subject& sub) {
		delete sub.m_noOfSections;
		delete[] sub.m_noOfStdsInSecs;
		delete[] sub.m_subjectName;

	}

}