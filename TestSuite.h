/**
*	@file TestSuite.h
*	@author 
*	@date 
*	@brief A small class to test LinkedLists of ints.
*/

#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <iostream>
#include <vector>
#include "LinkedListOfInts.h"
#include <stdexcept>

class TestSuite
{
	public:
	/** @pre None.
	*   @post An empty list is created.
	*/
	TestSuite();
	
	/** @pre None.
	*   @post Deletes all nodes in the list.
	*/
	~TestSuite();	

	/** @pre None
	*   @post None
	*   @return None
	*/	
	void runTests( );

	private:
	LinkedListOfInts * myList;
};

#endif
