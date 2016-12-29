/******************************************************************************
Filename:				Question.cpp
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
						of a Question and override operand<<() function.
******************************************************************************/ 
#include <iostream>
using namespace std;

#include "Answer.h"
#include "Question.h"
#include "string.h"

/**************************************************************************
Function name:		Question
Purpose:			Constructor of Answer
In parameters:		char*, unsigned int, Answer*
Out parameters:		none
Version:			1.0
Author:				Lucas Pazelo Vargas de Oliveira
**************************************************************************/
Question::Question(char* question, unsigned int mark, Answer* answer)
{
	qText = new char[100];
	strcpy(qText, question);
	Question::mark = mark;
	getchar();
	for(int i = 0; i<MAX_ANSWERS; i++){
		answers[i] = *(answer+i);
	}
};

/**************************************************************************
Function name:		Question
Purpose:			Copy Constructor of Question
In parameters:		Question&
Out parameters:		none
Version:			1.0
Author:				Lucas Pazelo Vargas de Oliveira
**************************************************************************/
Question::Question(Question& question)
{
	if(this != &question)
	{
		qText = new char[100];
		strcpy(qText, question.qText);
		mark = question.mark;
		for(int i = 0; i<MAX_ANSWERS; i++)
			answers[i] = question.answers[i];
	}
};

/**************************************************************************
Function name:		~Question
Purpose:			Destructor of Question::qText
In parameters:		none
Out parameters:		none
Version:			2.0
Author:				Lucas Pazelo Vargas de Oliveira
**************************************************************************/
Question::~Question()
{
	delete qText;
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
ostream& operator<<(ostream& output, Question& question)
{
	if(question.qText == 0)
	{
		output<<"Question does not exist"<<endl;
		return output;
	}
	output<<question.qText<<"\n";
	for(int i = 0; i < Question::MAX_ANSWERS; i++)
	{
		output<<"Ans #"<<i+1<<" :";
		output<<question.answers[i];
	}
	return output;
		
};