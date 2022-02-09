#include "linked_list.hpp"
#include <iostream>

/* Joseph Schurer
 * Linked List for Project 4
 */

//getNode function definition
//added to return the node pointer of a specific position
//not a public function
template <typename T>
Node<T>* LinkedList<T>::getNode(std::size_t position) const{
	
	//set temp variable to head
	Node<T>* temp = head;
	//step through list until position
	for(std::size_t i=0;i<position;i++){
		temp = temp->getNext();
	}
	return temp;
}

//default constructor
template <typename T>
LinkedList<T>::LinkedList()
{
  head = nullptr;
  length = 0;
}

//default destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
	//clear the list to delete all item
	clear();
	head= nullptr;
}


template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
	//copu the length over
	length = x.length;
	
	//check if the list is empty
	if(length==0){ head=nullptr;}
	
	//if the list x is not empty
	else{
		//allocatearray and set the value of the item
		head = new Node<T>();
		head->setItem(x.head->getItem());
		
		Node<T>* temp = head;
		Node<T>* oldList = x.head->getNext();
		while(oldList!=nullptr){
			//create the next node
			Node<T>* newNode = new Node<T>();
			
			//set the item and pointer to proper value
			newNode->setItem(oldList->getItem());
			newNode->setPrev(temp);
			temp->setNext(newNode);
			
			//iterate oldList
			oldList = oldList->getNext();
			temp = temp->getNext();
		}
	}	
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{	
	//free memory used by list
	clear();
	head = nullptr;
	
	//copu the length over
	length = x.length;
	
	//check if the list is empty
	if(length==0){ head=nullptr;}
	
	//if the list x is not empty
	else{
		head = new Node<T>();
		head->setItem(x.head->getItem());
		
		Node<T>* temp = head;
		Node<T>* oldList = x.head->getNext();
		while(oldList!=nullptr){
			//create the next node
			Node<T>* newNode = new Node<T>();
			
			//set the item and pointer to proper value
			newNode->setItem(oldList->getItem());
			newNode->setPrev(temp);
			temp->setNext(newNode);
			
			//iterate oldList
			oldList = oldList->getNext();
			temp = temp->getNext();
		}
	}
  return *this;
}

//is empty function
//if length is 0 return true
template <typename T>
bool LinkedList<T>::isEmpty() const
{
	if(length==0){
		return true;
	}
	else{return false;}

}

//getLength returns the length
template <typename T>
std::size_t LinkedList<T>::getLength() const
{
  return length;
}

//Clear out the list function
template <typename T>
void LinkedList<T>::clear()
{
  //clear out the list until length == 0 using remove
  while(!isEmpty()){
	  removeFront();
  }
}

//getEntry from position
//NOTE:This function must be passed a valid position!
template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
	//get pointer to position
	Node<T>* tempNode = getNode(position);
	T ret = tempNode->getItem();
	return(ret);
}


//insertFront function
template <typename T>
bool LinkedList<T>::insertFront(const T& item)
{
  //setup of new node
  Node<T>* newNode = new Node<T>();
  newNode->setItem(item);
  
  //if the list is empty this should be the head
  if(head==nullptr){
	  head = newNode;
	  
  } else {
	  //if there is an existing head replace it
	  newNode->setNext(head);
	  head->setPrev(newNode);
	  head = newNode;
  }  
  length++;  
  return true;
}

//insertEnd function
template <typename T>
bool LinkedList<T>::insertEnd(const T& item)
{  
  //setup of new node
  Node<T>* newNode = new Node<T>;
  newNode->setItem(item);
  
  //if the list is empty place the node at the head
  if(head == nullptr){
	  head = newNode;
  }
  else{
	//get the last node in the list
	Node<T>* temp = getNode(length-1);
	temp->setNext(newNode);
	newNode->setPrev(temp);
  }
  length++;  
  return true;
}

//removeFront function
template <typename T>
bool LinkedList<T>::removeFront()
{
	if(length == 0) { return false;}
 	//hold head in a temp variable
	Node<T>* temp = head;
	//set head to the next item in the list
	head = head->getNext();
	
	//clean up head if it exists
	if(head!=nullptr){
		head->setPrev(nullptr);
	}
	 
	//carefully free the memory used by head
	temp->setNext(nullptr);
	temp->setPrev(nullptr);
	delete temp;
	temp = nullptr;
	
	length--;
	return true;
}

//removeEnd function
template <typename T>
bool LinkedList<T>::removeEnd()
{
	if(length == 0) { return false; }
	//if only one item
	if(length == 1){
		head->setNext(nullptr);
		head->setPrev(nullptr);
		delete head;
		head = nullptr;
	} 
	//list is more than just a head
	else{
		//get the second to last node last node
		Node<T>* lastNode = getNode(length-1);
		
		//second to last node
		Node<T>* secondLast = getNode(length-2);
		secondLast->setNext(nullptr);
		/*/sever the last node if necessary
		if(lastNode->getPrev()!=nullptr){
			//get the node before that
			Node<T>* tempPrev = lastNode->getPrev();
			tempPrev->setNext(nullptr);
		}*/
	
		//deallocate memory used by last node
		lastNode->setNext(nullptr);
		lastNode->setPrev(nullptr);
		delete lastNode;
		lastNode=nullptr;
		
	}
	
	length--;
	return true;
}
