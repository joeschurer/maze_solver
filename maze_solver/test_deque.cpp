#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "deque.hpp"

/* Joseph Schurer
 * Deque Tests
 * 
 */
 

//Test the Default Constructor
TEST_CASE( "Constructor", "[deque]" ) {
	Deque<int> q;
	REQUIRE(q.isEmpty());
}

//Test PushFront
TEST_CASE("Test pushing from the front", "[deque]"){
	Deque<int> q;
	q.pushFront(2);
	q.pushFront(1);
	q.pushFront(0);
	REQUIRE(!q.isEmpty());
}

//Test Pushback
TEST_CASE("Test pushing from the back", "[deque]"){
	Deque<int> q;
	q.pushBack(0);
	q.pushBack(1);
	q.pushBack(2);
	REQUIRE(!q.isEmpty());
}

//Test reading from the front and back
TEST_CASE("Test the front and back function", "[deque]"){
	Deque<int> q;
	q.pushBack(1);
	q.pushFront(0);
	REQUIRE(q.front()==0);
	REQUIRE(q.back()==1);
	q.pushBack(2);
	q.pushFront(-1);
	REQUIRE(q.front()==-1);
	REQUIRE(q.back()==2);
}

//Test popFront
TEST_CASE("Test popFront", "[deque]"){
	Deque<int> q;
	q.pushFront(4);
	q.pushFront(3);
	q.pushFront(2);
	q.pushFront(1);
	q.pushFront(0);
	
	for(int i=0;i<5;i++){
		REQUIRE(q.front()==i);
		q.popFront();
	}
	
	
	REQUIRE(q.isEmpty());
}

//Test popBack
TEST_CASE("Test popBack", "[deque]"){
	Deque<int> q;
	q.pushBack(4);
	q.pushBack(3);
	q.pushBack(2);
	q.pushBack(1);
	q.pushBack(0);
	
	for(int i=0;i<5;i++){
		REQUIRE(q.back()==i);
		q.popBack();
	}
	
	REQUIRE(q.isEmpty());
}

//Test resuing a queue then isEmpty
TEST_CASE("Test reuse and isEmpty", "[deque]"){
	Deque<int> q;
	q.pushFront(2);
	q.pushBack(3);
	q.pushBack(4);
	q.pushFront(1);
	q.pushFront(0);
	
	for(int i=0;i<5;i++){
		REQUIRE(q.front()==i);
		q.popFront();
	}
	
	//verify that queue is empty after filling then removing items
	REQUIRE(q.isEmpty());
	
	//check that it can be reused
	q.pushBack(4);
	q.pushBack(3);
	q.pushBack(2);
	q.pushBack(1);
	q.pushBack(0);
	
	for(int i=0;i<5;i++){
		REQUIRE(q.back()==i);
		q.popBack();
	}
	
	REQUIRE(q.isEmpty());
}

//Test the copy constructor and operator overloading
TEST_CASE("Test the overloaded assignment operator and copy constructor","[Deque]"){
	Deque<int> q;
	q.pushFront(2);
	q.pushBack(3);
	q.pushBack(4);
	q.pushFront(1);
	q.pushFront(0);
	
	
	Deque<int> a(q);
	REQUIRE(!a.isEmpty());
	Deque<int> b=q;
	REQUIRE(!b.isEmpty());
	
	for(int i=0;i<5;i++){
		REQUIRE(a.front()==i);
		a.popFront();
	}
	
	//verify that queue is empty after filling then removing items
	REQUIRE(a.isEmpty());
	
	//check that it can be reused
	a.pushBack(4);
	a.pushBack(3);
	a.pushBack(2);
	a.pushBack(1);
	a.pushBack(0);
	
	for(int i=0;i<5;i++){
		REQUIRE(a.back()==i);
		a.popBack();
	}
	
	REQUIRE(a.isEmpty());
	
	for(int i=0;i<5;i++){
		REQUIRE(b.front()==i);
		b.popFront();
	}
	
	//verify that queue is empty after filling then removing items
	REQUIRE(b.isEmpty());
	
	//check that it can be reused
	b.pushBack(4);
	b.pushBack(3);
	b.pushBack(2);
	b.pushBack(1);
	b.pushBack(0);
	
	for(int i=0;i<5;i++){
		REQUIRE(b.back()==i);
		b.popBack();
	}
	
	REQUIRE(b.isEmpty());
}

TEST_CASE("Trying to fix some stuff", "[Deque]"){
	struct location{
	intmax_t row;
	intmax_t col;
	};
	
	Deque<location> Frontier;
	location a;
	a.row=0;
	a.col=0;
	
	Frontier.pushFront(a);

}
