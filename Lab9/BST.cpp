template <typename ItemType, typename KeyType>
BST<ItemType, KeyType>::BST()
{
	m_root= nullptr;
}

template <typename ItemType, typename KeyType>
BST<ItemType, KeyType>::~BST()
{
	recDelete(m_root);
}

template <typename ItemType, typename KeyType>
BST<ItemType, KeyType>::BST(BST<ItemType,KeyType>& original)
{
	if(original.m_root != nullptr)
	{
		this->m_root = new BNode<ItemType>(original.m_root->getEntry());
		recCopy(original.m_root, m_root);
	}
	else
	{
		throw std::runtime_error("The original BST is empty\n");
	}
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::recCopy(BNode<ItemType>* original, BNode<ItemType>* copy)
{
	if(original->getLeft() != nullptr)
	{
		copy->setLeft(new BNode<ItemType>(original->getLeft()->getEntry()));
		recCopy(original->getLeft(), copy->getLeft());
	}
	if(original->getRight() != nullptr)
	{
		copy->setRight(new BNode<ItemType>(original->getRight()->getEntry()));
		recCopy(original->getRight(), copy->getRight());
	}
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::add(ItemType entry)
{
	if(contains(entry, m_root))
	{
		throw(std::runtime_error("The value is already in our tree!\n"));
	}
	if(m_root == nullptr)
	{
		BNode<ItemType>* newNode= new BNode<ItemType>(entry);
		m_root= newNode;
		newNode= nullptr;
		delete newNode;
	}
	else
	{	
		recAdd(entry, m_root);
	}
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::clear()
{
	
}

template <typename ItemType, typename KeyType>
bool BST<ItemType, KeyType>::contains(ItemType Key, BNode<ItemType>* curSubTree)
{
	if(curSubTree == nullptr)
	{
		return false;
	}
	else if(curSubTree->getEntry() == Key)
	{
		return(true);
	}
	else if(curSubTree->getEntry() > Key)
	{
		return(contains(Key, curSubTree->getLeft()));
	}
	else if (curSubTree->getEntry() < Key)
	{
		return(contains(Key, curSubTree->getRight()));
	}
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::recDelete(BNode<ItemType>* curTree)
{
	if(curTree != nullptr)
	{
		recDelete(curTree->getLeft());
		recDelete(curTree->getRight());
		delete curTree;
	}
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::recAdd(ItemType entry, BNode<ItemType>* curSubTree)
{
	if(curSubTree == nullptr)
	{
		curSubTree= new BNode<ItemType>(entry);
	}
	else if(curSubTree->getEntry() > entry)
	{
		if(curSubTree->getLeft() == nullptr)
		{
			curSubTree->setLeft(new BNode<ItemType>(entry));
		}
		else
		{
			recAdd(entry, curSubTree->getLeft());
		}
	}
	else if(curSubTree->getEntry() < entry)
	{
		if(curSubTree->getRight() == nullptr)
		{
			curSubTree->setRight(new BNode<ItemType>(entry));
		}
		else
		{
			recAdd(entry, curSubTree->getRight());
		}
	}
}

template <typename ItemType, typename KeyType>
ItemType BST<ItemType, KeyType>::search(KeyType Key) const
{
	return(recSearch(Key, m_root));
}

template <typename ItemType, typename KeyType>
ItemType BST<ItemType, KeyType>::recSearch(KeyType Key, BNode<ItemType>* curSubTree) const
{
	if(curSubTree == nullptr)
	{
		throw std::runtime_error("Value is not in the tree\n");
	}
	if(curSubTree->getEntry() == Key)
	{
		return(curSubTree->getEntry());
	}
	else if (curSubTree->getEntry() < Key)
	{
		return(recSearch(Key, curSubTree->getRight()));
	}
	else
	{
		return(recSearch(Key, curSubTree->getLeft()));
	}
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::print()
{
	recPrint(m_root);
}

template <typename ItemType, typename KeyType>
BNode<ItemType>* BST<ItemType, KeyType>::recPrint(BNode<ItemType>* curSubTree)
{
	recPrint(curSubTree->getLeft());
	if(curSubTree!= nullptr)
	{
		std::cout<<curSubTree->getEntry().getAmericanName()<< std::endl;
	}
	recPrint(curSubTree->getRight());
	return nullptr;
}


template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::remove(KeyType key)
{
	removeHelper(key, m_root);
}

template <typename ItemType, typename KeyType>
BNode<ItemType>* BST<ItemType, KeyType>::removeHelper(KeyType entry, BNode<ItemType>* curSubTree)
{
	if(curSubTree == nullptr)
	{
		throw std::runtime_error("Value is not in the tree\n");
	}
	if(curSubTree->getEntry() < entry)
	{
		curSubTree->setRight(removeHelper(entry, curSubTree->getRight()));
	}
	else if(curSubTree->getEntry() > entry)
	{
		curSubTree->setLeft(removeHelper(entry, curSubTree->getLeft()));
	}
	else
	{
		if(curSubTree->getLeft() == nullptr)
		{
			BNode<ItemType>* temp = curSubTree->getRight();
			delete curSubTree;
			return(temp);
		}
		else if(curSubTree->getRight() == nullptr)
		{
			BNode<ItemType>* temp = curSubTree->getLeft();
			delete curSubTree;
			return(temp);
		}
		BNode<ItemType>* temp = curSubTree->getRight();
		while(temp->getLeft())
		{
			temp = temp->getLeft();
		}
		curSubTree->setEntry(temp->getEntry());
		curSubTree->setRight(removeHelper(entry, curSubTree->getRight()));
	}
	return(curSubTree);
}

template<typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::addRec(BNode<ItemType>* subTree)
{
	if(subTree->getLeft() != nullptr)
	{
		add(subTree->getLeft()->getEntry());
		addRec(subTree->getLeft());
	}
	if(subTree->getRight() != nullptr)
	{
		add(subTree->getRight()->getEntry());
		addRec(subTree->getRight());
	}
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::visitPreOrder(std::function<void(ItemType)> visit) const
{
	preOrder(visit, m_root);
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::visitInOrder(std::function<void(ItemType)> visit) const
{
	inOrder(visit, m_root);
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::visitPostOrder(std::function<void(ItemType)> visit) const
{
	postOrder(visit, m_root);
}

template<typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::preOrder(std::function<void(ItemType)> visit, BNode<ItemType>* curNode) const
{
	if(curNode != nullptr)
	{
		visit(curNode->getEntry());
		preOrder(visit, curNode->getLeft());
		preOrder(visit, curNode->getRight());
	}
}

template<typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::inOrder(std::function<void(ItemType)> visit, BNode<ItemType>* curNode) const
{
	if(curNode != nullptr)
	{
		inOrder(visit, curNode->getLeft());
		visit(curNode->getEntry());
		inOrder(visit, curNode->getRight());
	}
}

template<typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::postOrder(std::function<void(ItemType)> visit, BNode<ItemType>* curNode) const
{
	if(curNode != nullptr)
	{
		postOrder(visit, curNode->getLeft());
		postOrder(visit, curNode->getRight());
		visit(curNode->getEntry());
	}
}
