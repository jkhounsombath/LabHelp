/*
@Justin Khounsombath
@Hospital.h
@5/3/19
@Brief: method definitions for Hospital
*/

#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
#include <string>

#include "Patient.h"
#include "Heap.h"

class Hospital
{
	public:
		/*
		*@pre none
		*@post adds to heap
		*@param BNode<ItemType>* right: the node we want to make our right child pointer
		*@return none
		*@throw none
		*/
		void arrive(std::string firstName, std::string lastName, int age, std::string illness, int severity);
		/*
		*@pre none
		*@post sets the right child pointer
		*@param BNode<ItemType>* right: the node we want to make our right child pointer
		*@return none
		*@throw none
		*/
		Patient* next();
		/*
		*@pre none
		*@post sets the right child pointer
		*@param BNode<ItemType>* right: the node we want to make our right child pointer
		*@return none
		*@throw none
		*/
		void treat();
		/*
		*@pre none
		*@post sets the right child pointer
		*@param BNode<ItemType>* right: the node we want to make our right child pointer
		*@return none
		*@throw none
		*/
		int count();
	private:
		Heap<Patient>* heap;
};
#endif
