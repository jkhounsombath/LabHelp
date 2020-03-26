/*
@Justin Khounsombath
@Executive.h
@5/3/19
@Brief: method definitions for Executive
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

#include "Patient.h"
#include "Heap.h"

class Executive
{
	public:
		/*
		*@pre none
		*@post constructor for Executive
		*@param none
		*@return none
		*@throw none
		*/
		Executive();
		/*
		*@pre none
		*@post destructor for BNode
		*@param none
		*@return none
		*@throw none
		*/
		~Executive();
		/*
		*@pre none
		*@post runs the program
		*@param std::string fileName: file passed from command line
		*@return none
		*@throw none
		*/
		void run(std::string fileName);
	private:
		Heap<Patient>* heap;
};
#endif
