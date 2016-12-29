/******************************************************************************
Filename:				Answer.cpp
Version:				2.0
Author:					Lucas Pazelo Vargas de Oliveira
Student No:				040 799 663
Course Name/Number:		C++ CST8219
Lab Sect:				302
Assignment #:			2
Assignment name:		ExamTemplate in C++ with Overloaded Operators
Due Date:				March 15                                      
Submission Date:		March 15
Professor:				Andrew Tyler                                           
Purpose:				Uses the overloaded constructor to create an instance
						of an Answer and override operand<<() function.
******************************************************************************/ 
#include <iostream>
using namespace std;

#include "Answer.h"
#include "string.h"

/**************************************************************************
Function name:		Answer
Purpose:			Constructor of Answer
In parameters:		char*, bool
Out parameters:		none
Version:			1.0
Author:				Lucas Pazelo Vargas de Oliveira
**************************************************************************/
Answer::Answer(char* answer, bool correct)
{
	if(answer != NULL)
	{
		aText = new char[100];
		strcpy(aText, answer);
		b_correct = correct;
	}
	else
	{
		aText = answer;
		b_correct = correct;
	}
};

/**************************************************************************
Function name:		Answer
Purpose:			Copy Constructor of Answer
In parameters:		Answer&
Out parameters:		none
Version:			1.0
Author:				Lucas Pazelo Vargas de Oliveira
**************************************************************************/
Answer::Answer(Answer& answer)
{
	if(this != &answer)
	{
		aText = new char[100];
		strcpy(aText, answer.aText);
		b_correct = answer.b_correct;
	}
};

/**************************************************************************
Function name:		~Answer
Purpose:			Destructor of Answer::aText
In parameters:		none
Out parameters:		none
Version:			2.0
Author:				Lucas Pazelo Vargas de Oliveira
**************************************************************************/
Answer::~Answer()
{
	delete aText;
};

/**************************************************************************
Function name:		operand=
Purpose:			Copy all the fields in the answer passing as parameter
					to another Answer instance
In parameters:		Answer&
Out parameters:		Answer&
Version:			1.0
Author:				Lucas Pazelo Vargas de Oliveira
**************************************************************************/
Answer& Answer::operator=(Answer& answer)
{
	if(this != &answer)
	{
		if(answer.aText != NULL)
		{
			aText = new char[100];
			strcpy(aText, answer.aText);
			b_correct = answer.b_correct;
		}
		else
		{
			aText = answer.aText;
			b_correct = answer.b_correct;
		}
	}
	return *this;
};

/**************************************************************************
Function name:		operand<<
Purpose:			Override operand<< from the system and addapt
					the program needs
In parameters:		ostream&
Out parameters:		ostream&
Version:			1.0
Author:				Lucas Pazelo Vargas de Oliveira
**************************************************************************/
ostream& operator<<(ostream& output, Answer& answer)
{
	if(answer.aText != NULL)
		return output<<answer.aText<<"\n";
	return output<<"\n";
};