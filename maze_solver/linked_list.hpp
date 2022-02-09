#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

#include "Node.hpp"

template <typename T>
class LinkedList
{
public:
  
  // default constructor
  LinkedList();
  
  // copy constructor
  LinkedList(const LinkedList& x);
    
  // destructor
  ~LinkedList();
  
  // copy assignment
  LinkedList& operator=(const LinkedList& x);

  // swap two lists 
  //void swap(LinkedList& x, LinkedList& y);
  
  // determine if a list is empty
  bool isEmpty() const;

  // return current length of the list
  std::size_t getLength() const;

  // insert item at position in the list using 0-based indexing
  //bool insert(std::size_t position, const T& item);
  
  // insert item at the front of the list
  bool insertFront(const T& item);
  
  // insert item at the end of the list
  bool insertEnd(const T& item);

  // remove item at position in the list using 0-based indexing
  //bool remove(std::size_t position);
  
  // remove item at position in the list using 0-based indexing
  bool removeFront();
  
  // remove item at position in the list using 0-based indexing
  bool removeEnd();

  // remove all items from the list
  void clear();

  // get a copy of the item at position using 0-based indexing
  T getEntry(std::size_t position) const;

  // set the value of the item at position using 0-based indexing
  //void setEntry(std::size_t position, const T& newValue);

private:
	//function to get a Node at index
	//should not be exposed to user
	Node<T>* getNode(std::size_t position) const;
	
	
	//variable to hold the start of the list
	Node<T>* head;
	
	//variable holding the number of items in the list
	std::size_t length;
  
};

#include "linked_list.tpp"

#endif
