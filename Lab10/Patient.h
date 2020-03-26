/*
@Justin Khounsombath
@Patient.h
@5/3/19
@Brief: method definitions for Patient
*/

#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>

class Patient
{
	public:
		/*
		*@pre none
		*@post constructor
		*@param none
		*@return none
		*@throw none
		*/
		Patient();
		/*
		*@pre none
		*@post sets the right child pointer
		*@param BNode<ItemType>* right: the node we want to make our right child pointer
		*@return none
		*@throw none
		*/
		Patient(std::string firstName, std::string lastName, int age, std::string illness, int severity);
		/*
		*@pre none
		*@post sets the right child pointer
		*@param BNode<ItemType>* right: the node we want to make our right child pointer
		*@return none
		*@throw none
		*/
		~Patient();
		/*
		*@pre none
		*@post sets the right child pointer
		*@param BNode<ItemType>* right: the node we want to make our right child pointer
		*@return none
		*@throw none
		*/
		bool operator <(const Patient& p2);
		/*
		*@pre none
		*@post sets the right child pointer
		*@param BNode<ItemType>* right: the node we want to make our right child pointer
		*@return none
		*@throw none
		*/
		bool operator >(const Patient& p2);
		/*
		*@pre none
		*@post sets the right child pointer
		*@param BNode<ItemType>* right: the node we want to make our right child pointer
		*@return none
		*@throw none
		*/
		void printInfo();
	private:
		std::string m_firstName;
		std::string m_lastName;
		int m_age;
		std::string m_illness;
		int m_severity;
};
#endif
