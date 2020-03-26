#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>
#include <fstream>
#include "Pokemon.h"
#include "BNode.h"
#include "BST.h"
#include "TreeTest.h"
#include <algorithm>
#include <functional>

class Executive
{
	public:
		Executive();
		~Executive();
		void run(std::string fileName);
		void passFunc(Pokemon poke);
	private:
		BST<Pokemon, std::string>* bst;
		BST<Pokemon, std::string>* bstCopy;
		bool isCopied = false;
		std::ofstream outFile;
};
#endif
