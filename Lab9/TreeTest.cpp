#include "TreeTest.h"


void TreeTest::testAdds(BST<Pokemon, std::string> bst)
{
	std::string americanName;
	int pokeNumber;
	std::string japaneseName;
	std::cout<<"What do you want the Pokemon name(US) to be: \n";
	std::cin>>americanName;
	std::cout<<"What do you want the Pokemon number to be: \n";
	std::cin>>pokeNumber;
	std::cout<<"What do you want the Pokemon name(Japanese) to be: \n";
	std::cin>>japaneseName;
	try
	{
		Pokemon* newPokemon= new Pokemon(americanName, pokeNumber, japaneseName);
		bst.add(*newPokemon);
		delete newPokemon;
		bst.visitInOrder(std::bind(&TreeTest::print, this, std::placeholders::_1));
		std::cout<< std::endl;
	}
	catch (std::runtime_error rte)
	{
		std::cout<<"Duplicate pokemon name\n";
	}
	
}

void TreeTest::testWriteToFile(BST<Pokemon, std::string> bst)
{
	std::string outName;
	std::cout<<"Enter an output file name: \n";
	std::cin>>outName;
	outFile.open(outName);
	bst.visitInOrder(std::bind(&TreeTest::save, this, std::placeholders::_1));
	outFile.close();
}

void TreeTest::testRemoves(BST<Pokemon, std::string> bst)
{
	std::string name;
	std::cout<<"Enter the American name of the pokemon you would like to remove from the tree: \n";
	std::cin>>name;
	bst.remove(name);
	bst.visitInOrder(std::bind(&TreeTest::print, this, std::placeholders::_1));
}

void TreeTest::print(Pokemon poke)
{
	std::cout<<std::endl<<"American Name: "<<poke.getAmericanName()<<std::endl;
	std::cout<<"Pokedex Number: "<<poke.getNumber()<<std::endl;
	std::cout<<"Japanese Name: "<<poke.getJapaneseName()<<std::endl<<std::endl;
}

void TreeTest::save(Pokemon poke)
{
	outFile<<poke.getAmericanName()<<" "<<poke.getNumber()<<" "<<poke.getJapaneseName()<<"\n";
}
