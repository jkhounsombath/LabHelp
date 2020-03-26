#ifndef TREETEST_H
#define TREETEST_H

#include <iostream>
#include <string>
#include <functional>
#include <fstream>

#include "BST.h"

class TreeTest
{
	private:
		std::ofstream outFile;
	public:
		void testAdds(BST<Pokemon, std::string> bst);
		void testWriteToFile(BST<Pokemon, std::string> bst);
		void testRemoves(BST<Pokemon, std::string> bst);
		void print(Pokemon poke);
		void save(Pokemon poke);
};
#endif
