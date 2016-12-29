/******************************************************************************
Filename:				Answer.cpp
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
Purpose:				Simply uses the destructor of Question when the
						object go out of the scope.			
******************************************************************************/   
#include "Answer.h"
#include "Question.h"
#include "Exam.h"

/**************************************************************************
Function name:		~Answer
Purpose:			Destructor of Answer::aText
In parameters:		none
Out parameters:		none
Version:			1.0
Author:				Lucas Pazelo Vargas de Oliveira
**************************************************************************/
Answer::~Answer(){
	delete Answer::aText;
}