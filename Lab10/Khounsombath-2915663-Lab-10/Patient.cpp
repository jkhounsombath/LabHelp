#include "Patient.h"

Patient::Patient()
{

}

Patient::Patient(std::string firstName, std::string lastName, int age, std::string illness, int severity)
{
	m_firstName= firstName;
	m_lastName= lastName;
	m_age= age;
	m_illness= illness;
	m_severity= severity;
}

Patient::~Patient()
{

}

void Patient::printInfo()
{
	std::cout<<"Next Patient: \n";
	std::cout<<"\tName: "<<m_lastName<<", "<<m_firstName<<".\n";
	std::cout<<"\tAge: "<<m_age<<std::endl;
	std::cout<<"\tSuffers from: "<<m_illness<<std::endl;
	std::cout<<"\tIllness severity: "<<m_severity<<std::endl;
}

bool Patient::operator <(const Patient& p2) 
{
	if(this->m_severity == p2.m_severity)
	{
		return (this->m_age < p2.m_age);
	}
	else
	{
		return (this->m_severity < p2.m_severity);
	}
}

bool Patient::operator >(const Patient& p2)
{
	if(this->m_severity == p2.m_severity)
	{
		return (this->m_age > p2.m_age);
	}
	else
	{
		return (this->m_severity > p2.m_severity);
	}
}
