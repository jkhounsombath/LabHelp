#include "Pokemon.h"

Pokemon::Pokemon()
{

}

Pokemon::~Pokemon()
{

}

Pokemon::Pokemon(std::string americanName, int number, std::string japaneseName)
{
	m_americanName= americanName;
	m_number= number;
	m_japaneseName= japaneseName;
}

std::string Pokemon::getAmericanName()
{
	return(m_americanName);
}

std::string Pokemon::getJapaneseName()
{
	return(m_japaneseName);
}

int Pokemon::getNumber()
{
	return(m_number);
}

bool Pokemon::operator <(const std::string& s2) 
{
	return (this->m_americanName < s2);
}

bool Pokemon::operator >(const std::string& s2) 
{
	return (this->m_americanName > s2);
}

bool Pokemon::operator <(const Pokemon& p2)
{
	return(this->m_americanName < p2.m_americanName);
}

bool Pokemon::operator >(const Pokemon& p2)
{
	return(this->m_americanName > p2.m_americanName);
}

bool Pokemon::operator ==(const std::string& s2)
{
	return(this->m_americanName == s2);
}

bool Pokemon::operator ==(const Pokemon& p2)
{
	return(this->m_americanName == p2.m_americanName);
}

