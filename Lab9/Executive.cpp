#include "Executive.h"

Executive::Executive()
{
	bst= new BST<Pokemon, std::string>();
	bstCopy= nullptr;
}

Executive::~Executive()
{
	delete bst;
	if(bstCopy != nullptr)
	{
		delete bstCopy;
	}
}

void Executive::run(std::string fileName)
{
	std::ifstream inFile(fileName);
	std::string AName;
	std::string JName;
	int PNumber;
	while(inFile>>AName)
	{
		inFile>>PNumber;
		inFile>>JName;
		Pokemon* newPokemon= new Pokemon(AName, PNumber, JName);
		bst->add(*newPokemon);
		newPokemon= nullptr;
		delete newPokemon;
	}
	std::string input;
	std::cout<<"Welcome to the Pokedex!\n";
	while(input != "Quit" && input != "3" && input != "quit")
	{
		std::cout<<"What task would you like me to perform?\n\n1.Search\n2.Add\n3.Quit\n4.Remove\n5.Copy\n6.Save\n7.Test";
		std::cin>>input;
		if(input == "Search" || input == "1" || input == "search" )
		{
			std::string AName;
			std::cout<<"Enter an american name of a pokemon to search: \n";
			std::cin>>AName;
			if(isCopied == true)
			{
				try
				{
					Pokemon poke= bstCopy->search(AName);
					std::cout<<std::endl<<"American Name: "<<poke.getAmericanName()<<std::endl;
					std::cout<<"Pokedex Number: "<<poke.getNumber()<<std::endl;
					std::cout<<"Japanese Name: "<<poke.getJapaneseName()<<std::endl<<std::endl;
				}
				catch (std::runtime_error rte)
				{
					std::cout<<"Not found\n";
				}
			}
			else
			{
				std::cout<<"Copy already made\n";
			}
		}
		else if(input == "Add" || input == "2" || input == "add")
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
			if(isCopied == true)
			{
				try
				{
					Pokemon* newPokemon= new Pokemon(americanName, pokeNumber, japaneseName);
					bstCopy->add(*newPokemon);
					delete newPokemon;
				}
				catch (std::runtime_error rte)
				{
					std::cout<<"Duplicate pokemon name\n";
				}
			}
			else
			{
				std::cout<<"Copy does not exist!\n";
			}
		}
		else if(input == "Remove" || input == "remove" || input == "4")
		{
			std::string name;
			std::cout<<"Enter the American name of the pokemon you would like to remove from the tree: \n";
			std::cin>>name;
			if(isCopied == true)
			{
				try
				{
					bstCopy->remove(name);
				}
				catch (std::runtime_error rte)
				{
					std::cout<<"Name does not exist in the tree\n";
				}
			}
			else
			{
				std::cout<<"Copy does not exist!\n";
			}
		}
		else if(input == "Copy" || input == "copy" || input == "5")
		{
			if(isCopied == true)
			{
				std::cout<<"Copy already made\n";
			}
			else
			{
				isCopied= true;
				bstCopy= new BST<Pokemon, std::string>(*bst);
			}
		}	
		else if(input == "Save" || input == "save" || input == "6")
		{
			std::string outName;
			std::cout<<"Enter an output file name: \n";
			std::cin>>outName;
			outFile.open(outName);
			std::string pokedexType;
			std::string traversalOrder;
			do
			{
				std::cout<<"Which pokedex would ou like to save (original or copy): \n";
				std::cin>>pokedexType;
			}while(pokedexType != "original" && pokedexType != "copy");
			std::cout<<"Traversal order? \n";
			std::cin>>traversalOrder;
			if(pokedexType == "Original")
			{
				if(traversalOrder == "Preorder")
				{
					bst->visitPreOrder(std::bind(&Executive::passFunc, this, std::placeholders::_1));
				}
				else if(traversalOrder == "Postorder")
				{
					bst->visitPostOrder(std::bind(&Executive::passFunc, this, std::placeholders::_1));
				}
				else if(traversalOrder == "Inorder")
				{
					bst->visitInOrder(std::bind(&Executive::passFunc, this, std::placeholders::_1));
				}
				else
				{
					std::cout<<"Choices are Preorder, Postorder, Indorder\n";
				}
			}
			else
			{
				if(traversalOrder == "Preorder")
				{
					bstCopy->visitPreOrder(std::bind(&Executive::passFunc, this, std::placeholders::_1));
				}
				else if(traversalOrder == "Postorder")
				{
					bstCopy->visitPostOrder(std::bind(&Executive::passFunc, this, std::placeholders::_1));
				}
				else if(traversalOrder == "Inorder")
				{
					bstCopy->visitInOrder(std::bind(&Executive::passFunc, this, std::placeholders::_1));
				}
				else
				{
					std::cout<<"Choices are Preorder, Postorder, Indorder\n";
				}
			}
			outFile.close();
		}
		else if(input == "Test" || input == "test" || input =="7")
		{
			std::string testType;
			std::cout<<"What test would you like to perform? (add, remove, write)\n";
			std::cin>>testType;
			TreeTest tree;
			if(testType == "add")
			{
				tree.testAdds(*bst);
			}
			else if(testType == "remove")
			{
				tree.testRemoves(*bst);
			}
			else if(testType == "write")
			{
				tree.testWriteToFile(*bst);
			}
			else
			{
				std::cout<<"The only options are write, remove, and add\n";
			}
		}
		else if(input == "Quit" || input == "Add" || input == "2" || input == "add" || input == "Search" || input == "1" || input == "search" || input == "3" || input == "quit" || input == "Remove" || input == "remove" || input == "3" || input == "Test" || input == "test" || input =="5" || input == "Copy" || input == "copy" || input == "5" || input == "Save" || input == "save" || input == "6" || input == "Test" || input == "test" || input =="7")
		{
		}
		else
		{
			std::cout<<"I cannot perform this task!(Options are Search or Add or Quit\n";
		}
	}
	std::cout<<std::endl;
}

void Executive::passFunc(Pokemon poke)
{
	outFile<<poke.getAmericanName()<<" "<<poke.getNumber()<<" "<<poke.getJapaneseName()<<"\n";
}
