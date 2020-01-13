#ifndef SDDS_SUBJECT_H__
#define SDDS_SUBJECT_H__
namespace sdds {
	//create stucture for subject 
	//Struct memebers are pointers for dynamic memory allocation
	struct Subject
	{
		int* m_noOfSections;
		int* m_noOfStdsInSecs;
		char* m_subjectName;
	};
	//function prototypes
	// function overload for read function with different signature
	void read(char*);
	void read(int&);
	void read(int[], int);
	void read(Subject&);
	// prints the value of array elements in struct that has been filled 
	int report(const Subject&);
	// dynamic memory deallocation
	void freeMem(Subject&);
}

#endif