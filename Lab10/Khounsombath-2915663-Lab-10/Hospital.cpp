#include "Hospital.h"

void Hospital::arrive(std::string firstName, std::string lastName, int age, std::string illness, int severity)
{
	Patient* newPatient= new Patient(firstName, lastName, age, illness, severity);
	heap->add(*newPatient);
	newPatient = nullptr;
}

Patient* Hospital::next()
{

}

void Hospital::treat()
{

}

int Hospital::count()
{

}
