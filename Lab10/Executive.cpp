#include "Executive.h"

Executive::Executive()
{
	heap= new Heap<Patient>();
}

void Executive::run(std::string fileName)
{
	std::ifstream inFile(fileName);
	std::string command;
	while(inFile>>command)
	{
		if(command == "ARRIVE")
		{
			std::string firstName;
			std::string lastName;
			int age;
			std::string illness;
			int severity;
			inFile>>firstName;
			inFile>>lastName;
			inFile>>age;
			inFile>>illness;
			inFile>>severity;
			Patient* newPatient= new Patient(firstName, lastName, age, illness, severity);
			heap->add(*newPatient);
			delete newPatient;
		}
		else if(command == "COUNT")
		{
			if(heap->getNumberOfNodes() != 1)
			{
				std::cout<<"There are "<<heap->getNumberOfNodes()<<" patients waiting."<<std::endl<<std::endl;
			}
			else
			{
				std::cout<<"There is "<<heap->getNumberOfNodes()<<" patient waiting."<<std::endl<<std::endl;
			}
		}
		else if(command == "NEXT")
		{
			if(heap->getNumberOfNodes() != 0)
			{
				heap->peekTop().printInfo();
			}
			else
			{
				std::cout<<"There is nobody in the hospital!\n";
			}
		}
		else if(command == "TREAT")
		{
			if(heap->getNumberOfNodes() != 0)
			{
				heap->remove();
			}
			else
			{
				std::cout<<"There is nobody in the hospital!\n";
			}
		}
		else
		{
			throw std::runtime_error("There is an invalid command in our 'data.txt'\n");
		}	
	}
}

Executive::~Executive()
{
	delete heap;
}
