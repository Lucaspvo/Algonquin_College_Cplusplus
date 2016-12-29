/******************************************************************************
Filename:				Exam.cpp
Version:				1.0
Author:					Lucas Pazelo Vargas de Oliveira
Student No:				040 799 663
Course Name/Number:		C++ CST8219
Lab Sect:				302
Assignment #:			1
Assignment name:		ExamTemplate in C++
Due Date:				February 15                                      
Submission Date:		February 15
Professor:				Andrew Tyler                                           
Purpose:				Create an Exam whenever the user asks to add a new
						question. Also, it deletes a question and print
						all questions in the Exam array.
******************************************************************************/    
#include "Answer.h"
#include "Question.h"
#include "Exam.h"
#include <iostream>
using namespace std;

/**************************************************************************
Function name:		Exam
Purpose:			Constructor of Exam
In parameters:		none
Out parameters:		none
Version:			1.0
Author:				Lucas Pazelo Vargas de Oliveira
**************************************************************************/
Exam::Exam()
{
	Exam::title = new char[50];
	cout<<"What is the title of the exam?"<<endl;
	cin.getline(Exam::title, 50);
	for(int i = 0; i<MAX_QUESTIONS; i++)
		Exam::questions[i] = NULL;
}

/**************************************************************************
Function name:		~Exam
Purpose:			Destructor of Exam::title
In parameters:		none
Out parameters:		none
Version:			1.0
Author:				Lucas Pazelo Vargas de Oliveira
**************************************************************************/
Exam::~Exam()
{
	int i = 0;
	delete Exam::title;
	while (Exam::questions[i] != NULL && i < MAX_ANSWERS)
	{
		delete Exam::questions[i];
		i++;
	}
}

/**************************************************************************
Function name:		AddNewQuestion
Purpose:			Add a new Question in Exam's array
In parameters:		none
Out parameters:		bool
Version:			1.0
Author:				Lucas Pazelo Vargas de Oliveira
**************************************************************************/
bool Exam::AddNewQuestion()
{
	int i = 0, j, numAnswers;
	while(Exam::questions[i] != NULL)
		i++;
	if(i >= MAX_QUESTIONS)
		return false;
	Exam::questions[i] = new Question();
	cout<<"Please enter the new question text: ";
	Exam::questions[i]->qText = new char[50];
	getchar();
	cin.getline(Exam::questions[i]->qText, 50);
	cout<<"Please enter the new question mark: ";
	cin>>Exam::questions[i]->mark;
	cout<<"Please enter the number of answers, up to a max of 5: ";
	cin>>numAnswers;
	for(j = 0; j<MAX_ANSWERS; j++)
		Exam::questions[i]->answers[j].aText = NULL;
	j = 0;
	while(j < numAnswers)
	{
		Exam::questions[i]->answers[j].aText = new char[50];
		cout<<"Please enter answer " << j+1 << endl;
		getchar();
		cin.getline(Exam::questions[i]->answers[j].aText, 50);
		cout<<"Is it correct? (0 = no, 1 = yes)?:";
		cin>>Exam::questions[i]->answers[j].correct;
		j++;
	}
	return true;
}

/**************************************************************************
Function name:		DeleteQuestion
Purpose:			Delete a Question in Exam's array
In parameters:		none
Out parameters:		bool
Version:			1.0
Author:				Lucas Pazelo Vargas de Oliveira
**************************************************************************/
bool Exam::DeleteQuestion(){

	int qDelete;
	cout<<"Please enter the number of the question to delete (1, 2, 3, ...): ";
	cin>>qDelete;
	qDelete--;
	if(Exam::questions[qDelete] == NULL)
	{
		cout<<"empty question\n";
		return true;
	}
	cout<<"deleting question #"<<qDelete+1;
	delete Exam::questions[qDelete];
	while(Exam::questions[qDelete+1] != NULL)
	{
		Exam::questions[qDelete] = Exam::questions[qDelete+1];
		qDelete++;
	};
	Exam::questions[qDelete] = NULL;
	return true;
}

/**************************************************************************
Function name:		PrintQuestions
Purpose:			Print all Questions in Exam's array
In parameters:		none
Out parameters:		bool
Version:			1.0
Author:				Lucas Pazelo Vargas de Oliveira
**************************************************************************/
bool Exam::PrintQuestions()
{
	int i = 0, j;
	cout<<"TITLE: "<<Exam::title<<endl;
	while(Exam::questions[i] != NULL && i < MAX_QUESTIONS)
	{
		cout<<"QUESTION "<<i+1<<". Mark = "<<Exam::questions[i]->mark<<endl;
		cout<<Exam::questions[i]->qText<<endl;
		cout<<"ANSWERS"<<endl;
		j = 0;
		while(Exam::questions[i]->answers[j].aText != NULL && j < MAX_ANSWERS)
		{
			cout<<"Ans "<<j+1<<endl;
			cout<<Exam::questions[i]->answers[j].aText<<endl;
			j++;
		}
		i++;
	}
	return true;
}