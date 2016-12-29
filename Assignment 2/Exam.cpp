/******************************************************************************
Filename:				Exam.cpp
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
Purpose:				Create an Exam whenever the user asks to add a new
						question. Also, it deletes a question and print
						all questions in the Exam array, also it can print
						only one question asked by the user.
******************************************************************************/ 
#include <iostream>
using namespace std;

#include "Answer.h"
#include "Question.h"
#include "Exam.h"

/**************************************************************************
Function name:		Exam
Purpose:			Constructor of Exam
In parameters:		none
Out parameters:		none
Version:			2.0
Author:				Lucas Pazelo Vargas de Oliveira
**************************************************************************/
Exam::Exam()
{
	Exam::title = new char[100];
	cout<<"What is the title of the exam?"<<endl;
	cin.getline(Exam::title, 100);
	for(int i = 0; i<MAX_QUESTIONS; i++)
		Exam::questions[i] = NULL;
};

/**************************************************************************
Function name:		~Exam
Purpose:			Destructor of Exam::title
In parameters:		none
Out parameters:		none
Version:			2.0
Author:				Lucas Pazelo Vargas de Oliveira
**************************************************************************/
Exam::~Exam()
{
	int i = 0;
	delete title;
	while (questions[i] != NULL && i < MAX_QUESTIONS)
	{
		delete questions[i];
		i++;
	}
};

/**************************************************************************
Function name:		AddNewQuestion
Purpose:			Add a new Question in Exam's array
In parameters:		none
Out parameters:		bool
Version:			2.0
Author:				Lucas Pazelo Vargas de Oliveira
**************************************************************************/
bool Exam::AddNewQuestion()
{
	int i = 0, j, numAnswers;
	unsigned int mark;
	bool correct;
	Answer answers[Question::MAX_ANSWERS];
	Answer* pAnswer;
	while(questions[i] != NULL)
		i++;
	if(i >= MAX_QUESTIONS)
	{
		cout<<"Max questions reached"<<endl;
		return true;
	}
	cout<<"Please enter the new question text: ";
	char *qText = new char[100];
	getchar();
	cin.getline(qText, 100);
	cout<<"Please enter the new question mark: ";
	cin>>mark;
	cout<<"Please enter the number of answers, up to a max of 5: ";
	cin>>numAnswers;
	while(numAnswers < 0 || numAnswers > Question::MAX_ANSWERS)
	{
		cout<<"Please enter the number of answers, up to a max of 5: ";
		cin>>numAnswers;
	}
	j = 0;
	while(j < numAnswers)
	{
		char* aText = new char[100];
		cout<<"Please enter answer " << j+1 << endl;
		getchar();
		cin.getline(aText, 100);
		cout<<"Is it correct? (0 = no, 1 = yes)?:";
		cin>>correct;
		pAnswer = new Answer(aText, correct);
		answers[j] = *(pAnswer);
		delete aText;
		delete pAnswer;
		j++;
	}
	while(j < Question::MAX_ANSWERS)
	{
		pAnswer = new Answer(NULL, 0);
		answers[j] = *(pAnswer);
		delete pAnswer;
		j++;
	}
	questions[i] = new Question(qText, mark, &answers[0]);
	delete qText;
	return true;
};

/**************************************************************************
Function name:		DeleteQuestion
Purpose:			Delete a Question in Exam's array
In parameters:		none
Out parameters:		bool
Version:			2.0
Author:				Lucas Pazelo Vargas de Oliveira
**************************************************************************/
bool Exam::DeleteQuestion()
{
	int qDelete;
	cout<<"Please enter the number of the question to delete (1, 2, 3, ...): ";
	cin>>qDelete;
	qDelete--;
	while(qDelete < 0 || qDelete >= MAX_QUESTIONS)
	{
		cout<<"Please enter the number of the question to delete (1, 2, 3, ...): ";
		cin>>qDelete;
	}
	if(questions[qDelete] == NULL)
	{
		cout<<"Empty Question"<<endl;
		return true;
	}
	cout<<"deleting question #"<<qDelete+1<<endl;
	delete questions[qDelete];
	while(questions[qDelete+1] != NULL && qDelete+1 < MAX_QUESTIONS)
	{
		questions[qDelete] = questions[qDelete+1];
		qDelete++;
	};
	questions[qDelete] = NULL;
	return true;
};

/**************************************************************************
Function name:		operator[]
Purpose:			Resturns a question choosed by the user indicated
					by index passed as parameter
In parameters:		unsigned int
Out parameters:		Question
Version:			1.0
Author:				Lucas Pazelo Vargas de Oliveira
**************************************************************************/
Question Exam::operator[](unsigned int index)
{
	if(index-1 >= 0 && index-1 < MAX_QUESTIONS)
	{
		if(questions[index-1] != NULL)
			return *(questions[index-1]);
	}
	return Question();
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
ostream& operator<<(ostream& output, Exam& exam)
{
	output<<"TITLE: "<<exam.title<<"\n";
	int i = 0;
	while(exam.questions[i] != NULL && i < Exam::MAX_QUESTIONS)
	{
		output<<"Question "<<i+1<<":\n";
		output<<exam[i+1];
		i++;
	}
	return output;
};