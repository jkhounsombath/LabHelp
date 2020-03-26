/*
@Justin Khounsombath
@Heap.h
@5/3/19
@Brief: method definitions for Heap
*/

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <string>
#include <stdexcept>

#include "HeapInterface.h"
#include "Patient.h"

template <typename T>
class Heap:public HeapInterface<T>
{
	private:
		T* m_arr;
		int m_size; //array size
		int m_heapSize;//heap size
		/*
		*@pre none
		*@post adjusts the size of the array
		*@param none
		*@return none
		*@throw none
		*/
		void resize();
		/*
		*@pre none
		*@post moves a value up an array if the value above it is less
		*@param int index: the index of the value to upheap
		*@return none
		*@throw none
		*/
		void upheap(int index);
		/*
		*@pre none
		*@post moves a value down an array if the value is less than the values below
		*@param int index: the index of the value to downheap
		*@return none
		*@throw none
		*/
		void downheap(int index);
	public:
		/*
		*@pre none
		*@post constructor
		*@param none
		*@return none
		*@throw none
		*/
		Heap();
		/*
		*@pre none
		*@post destructor
		*@param none
		*@return none
		*@throw none
		*/
		~Heap();
		/*
		*@pre none
		*@post returns true or false based on if the heap is empty
		*@param none
		*@return true if the heap is empty false if not
		*@throw none
		*/
		bool isEmpty() const;
		/*
		*@pre none
		*@post returns the number of nodes in the heap
		*@param none
		*@return returns number of nodes in the heap
		*@throw none
		*/
		int getNumberOfNodes() const;
		/*
		*@pre none
		*@post returns the height of the heap
		*@param none
		*@return returns the height of the heap
		*@throw none
		*/
		int getHeight() const;
		/*
		*@pre none
		*@post returns the top of the heap
		*@param none
		*@return The node in the top of the heap
		*@throw runtime_error if the heap is empty
		*/
		T peekTop() const; //Can throw std::runtime_error
		/*
		*@pre none
		*@post adds a value to the heap
		*@param data: value to be added to heap
		*@return none
		*@throw none
		*/
		void add(T data);
		/*
		*@pre none
		*@post removes the top of the heap
		*@param none
		*@return none
		*@throw if we attempt to remove from an empty heap
		*/
		void remove(); //Can throw std::runtime_error
		/*
		*@pre none
		*@post used by destructor to clear the tree
		*@param none
		*@return none
		*@throw none
		*/
		void clear();
		/*
		*@pre none
		*@post places a new value in the tree
		*@param none
		*@return none
		*@throw none
		*/
		void arrive(std::string firstName, std::string lastName, int age, std::string illness, int severity);
		/*
		*@pre none
		*@post returns the patient at the top of the heap
		*@param none
		*@return patient at the top of the heap
		*@throw none
		*/
		Patient* next();
		/*
		*@pre none
		*@post delete value at the top of the heap
		*@param none
		*@return none
		*@throw none
		*/
		void treat();
		/*
		*@pre none
		*@post return the number of people awaiting help at the Hospital
		*@param none
		*@return count of people in our heap
		*@throw none
		*/
		int count();
};
#include "Heap.cpp"
#endif
