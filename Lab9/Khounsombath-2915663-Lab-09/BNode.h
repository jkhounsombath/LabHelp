#ifndef BNODE_H
#define BNODE_H

#include <iostream>
#include <string>

#include "BNodeInterface.h"

template <typename ItemType>
class BNode: public BNodeInterface<ItemType>
{
	public:
		BNode(ItemType entry);
		~BNode();
		ItemType getEntry() const;
		BNode<ItemType>* getLeft() const;
		BNode<ItemType>* getRight() const;
		void setEntry(ItemType entry);
		void setLeft(BNode<ItemType>* left);
		void setRight(BNode<ItemType>* right);
	private:
		ItemType m_entry;
		BNode<ItemType>* m_left;
		BNode<ItemType>* m_right;
};
#include "BNode.cpp"
#endif
