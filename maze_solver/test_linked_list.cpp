#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"
/* Joseph Schurer
 * Linked List
 * 5/31/2020
 */

template class LinkedList<int>;

//consgtructor test
TEST_CASE( "Test the default constructor", "[LinkedList]" ) {
	LinkedList<int> test;
	REQUIRE(test.getLength()==0);
}

TEST_CASE( "Test insert front", "[LinkedList]" ) {
	LinkedList<int> test;
	REQUIRE(test.insertFront(1));
	REQUIRE(test.insertFront(2));
	REQUIRE(test.insertFront(3));
	REQUIRE(test.getLength()==3);
}

TEST_CASE( "Test insert end", "[LinkedList]" ) {
	LinkedList<int> test;
	REQUIRE(test.insertEnd(3));
	REQUIRE(test.insertEnd(2));
	REQUIRE(test.insertEnd(1));
	REQUIRE(test.getLength()==3);
}
