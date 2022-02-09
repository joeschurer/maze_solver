#include "deque.hpp"
#include <stdexcept>
#include <iostream>

/* Joseph Schurer
 * Deque Implementation 
 */

//default constructor
template <typename T>
Deque<T>::Deque(){
}

//default destructor
template <typename T>
Deque<T>::~Deque(){
}

//copy constructor
template <typename T>
Deque<T>::Deque(const Deque& x){
	list = x.list;
}
	
// overloaded assignment operator
template <typename T>
Deque<T>& Deque<T>::operator=(const Deque& x){
	list=x.list;
	return * this;
}

//isEmpty function
template <typename T>
bool Deque<T>::isEmpty() const noexcept{
	return (list.isEmpty());
}

	/** Add item to the front of the deque
	* may throw std::bad_alloc	
	*/
template <typename T>
void Deque<T>::pushFront(const T & item){
	//try to add item but catch std::bad_alloc
	try{ 
		list.insertFront(item);
	} catch (std::bad_alloc &e){
		std::cerr<< "Allocation failed" << e.what() << std::endl;
		std::terminate;
	}
}

/** Remove the item at the front of the deque
   * throws std::runtime_error if the deque is empty
   */
template <typename T>
void Deque<T>::popFront(){
	//if the list is empty throw exception
	if(list.isEmpty()) {throw std::runtime_error("Queue empty!");}
	//otherwise remove first item
	list.removeFront();
}

/** Returns the item at the front of the deque
   * throws std::runtime_error if the deque is empty
   */
template <typename T>
T Deque<T>::front() const{
	//if the list is empty throw exception
	if(list.isEmpty()) {throw std::runtime_error("Queue empty!");}
	
	//get and return the first item in the list
	T temp = list.getEntry(0);
	return temp;
}

/** Add item to the back of the deque
   * may throw std::bad_alloc
   */
template <typename T>
void Deque<T>::pushBack(const T & item){
	//try to add item but catch std::bad_alloc
	try{ 
		list.insertEnd(item);
	} catch (std::bad_alloc &e){
		std::cerr<< "Allocation failed" << e.what() << std::endl;
		std::terminate;
	}
	
}

/** Remove the item at the back of the deque
   * throws std::runtime_error if the deque is empty
   */
template <typename T>
void Deque<T>::popBack(){
	//throw exception if empty
	if(list.isEmpty()) {throw std::runtime_error("Queue empty!");}
	//remove the last item
	list.removeEnd();
}


  /** Returns the item at the back of the deque
   * throws std::runtime_error if the deque is empty
   */
template <typename T>
T Deque<T>::back() const{
	//throw exception if list empty
	if(list.isEmpty()) {throw std::runtime_error("Queue empty!");}
	
	//get and return the lasst item in the list
	std::size_t len = list.getLength();
	T temp = list.getEntry(len-1);
	return temp;
}
