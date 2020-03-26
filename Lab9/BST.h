#ifndef BST_H
#define BST_H

#include<iostream>
#include<string>
#include<stdexcept>
#include<functional>

#include "BNode.h"
#include "Pokemon.h"

#include "BSTInterface.h"

template <typename ItemType, typename KeyType>
class BST: public BSTInterface<ItemType, KeyType>
{
	public:
		BST();
		~BST();
		BST(BST<ItemType,KeyType>& original);
		void add(ItemType entry);
		ItemType search(KeyType key) const;
		void clear();
		bool contains(ItemType Key, BNode<ItemType>* curSubTree);
		void recAdd(ItemType entry, BNode<ItemType>* curSubTree);
		void recDelete(BNode<ItemType>* curTree);
		ItemType recSearch(KeyType Key, BNode<ItemType>* curSubTree) const;
		BNode<ItemType>* recPrint(BNode<ItemType>* curSubTree);
		void print();
		void remove(KeyType key); //throws std::runtime_error if not in tree
		BNode<ItemType>* removeHelper(KeyType key, BNode<ItemType>* curSubTree);
		void addRec(BNode<ItemType>* subTree);
		void save(std::string outFile, BST<ItemType, KeyType>* pokeDex, std::string traversal);
		void visitPreOrder(std::function<void(ItemType)> visit) const; //Visits each node in pre order
		void visitInOrder(std::function<void(ItemType)> visit) const; //Visits each node in in order
		void visitPostOrder(std::function<void(ItemType)> visit) const; //Visits each node in post order
		void preOrder(std::function<void(ItemType)> visit, BNode<ItemType>* curNode) const;
		void inOrder(std::function<void(ItemType)> visit, BNode<ItemType>* curNode) const;
		void postOrder(std::function<void(ItemType)> visit, BNode<ItemType>* curNode) const;
	private:
		BNode<ItemType>* m_root;
		void recCopy(BNode<ItemType>* original, BNode<ItemType>* copy);
};
#include "BST.cpp"
#endif
