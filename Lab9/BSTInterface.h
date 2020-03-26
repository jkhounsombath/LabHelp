#ifndef BSTINTERFACE_H
#define BSTINTERFACE_H

template <typename ItemType, typename KeyType>
class BSTInterface
{
    public:
	    virtual ~BSTInterface(){}
	    virtual void add(ItemType entry) = 0;
	    virtual ItemType search(KeyType key) const = 0;
	    virtual void clear() = 0;
	    virtual void remove(KeyType key) = 0; //throws std::runtime_error if not in tree
    	   // virtual void visitPreOrder(std::function<void(ItemType)> visit) const = 0; //Visits each node in pre order
           // virtual void visitInOrder(std::function<void(ItemType)> visit) const = 0; //Visits each node in in order
           // virtual void visitPostOrder(std::function<void(ItemType)> visit) const = 0; //Visits each node in post order
	    //More methods to come in next lab
};
#endif
