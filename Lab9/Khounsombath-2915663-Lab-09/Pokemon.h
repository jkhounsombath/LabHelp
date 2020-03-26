#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>

class Pokemon
{
	public:
		Pokemon();
		~Pokemon();
		Pokemon(std::string americanName, int number, std::string japaneseName);
		std::string getAmericanName();
		std::string getJapaneseName();
		int getNumber();
		bool operator <(const std::string& s2);
		bool operator <(const Pokemon& p2);
		bool operator >(const std::string& s2);
		bool operator >(const Pokemon& p2);
		bool operator ==(const std::string& s2);
		bool operator ==(const Pokemon& p2);
	private:
		std::string m_americanName;
		int m_number;
		std::string m_japaneseName;
		
};
#endif
