/*
@Justin Khounsombath
@BNode.h
@5/3/19
@Brief: method definitions for BNode
*/

#ifndef BNODE_H
#define BNODE_H

#include <iostream>
#include <string>

#include "BNodeInterface.h"

template <typename ItemType>
class BNode: public BNodeInterface<ItemType>
{
	public:
		/*
		*@pre none
		*@post constructor for BNode
		*@param ItemType entry: entry we place into node
		*@return none
		*@throw none
		*/
		BNode(ItemType entry);

		/*
		*@post destructor
		*/
		~BNode();

		/*
		*@pre none
		*@post gets the value inside the node(in this case, the Pokemon object)
		*@param none
		*@return ItemType(for this lab Pokemon)
		*@throw none
		*/
		ItemType getEntry() const;
		/*
		*@pre none
		*@post returns the pointer to the left child node
		*@param none
		*@return BNode<ItemType>*
		*@throw none
		*/
		BNode<ItemType>* getLeft() const;
		/*
		*@pre none
		*@post returns a pointer to the right child node
		*@param none
		*@return BNode<ItemType>*
		*@throw none
		*/
		BNode<ItemType>* getRight() const;
		/*
		*@pre none
		*@post sets the entry for a node
		*@param ItemType entry: entry we place into node
		*@return none
		*@throw none
		*/
		void setEntry(ItemType entry);
		/*
		*@pre none
		*@post sets the left child pointer
		*@param BNode<ItemType>* left: the node we want to make our left child pointer
		*@return none
		*@throw none
		*/
		void setLeft(BNode<ItemType>* left);
		/*
		*@pre none
		*@post sets the right child pointer
		*@param BNode<ItemType>* right: the node we want to make our right child pointer
		*@return none
		*@throw none
		*/
		void setRight(BNode<ItemType>* right);
	private:
		ItemType m_entry;
		BNode<ItemType>* m_left;
		BNode<ItemType>* m_right;
};
#include "BNode.cpp"
#endif
