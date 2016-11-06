/**
*	@file TestSuite.cpp
*	@author 
*	@date 
*	@brief Implementation of TestSuite.h
*/

#include "TestSuite.h"

#define ERRBUFFSIZE 2048
#define ERRBUFFLAST ( ERRBUFFSIZE - 1 )

void verifyTests( std::vector<std::string> & wrong, int testNum, const char * testName );

TestSuite::TestSuite()
{
}

TestSuite::~TestSuite()
{
}

void TestSuite::runTests()
{
	char errBuff[ ERRBUFFSIZE ];
	errBuff[ ERRBUFFLAST ] = '\0';
	std::vector<std::string> wrong;
	int testNum = 0;
	
	std::cout << "Starting Tests.\n\n";

	/************************************************************************
	 **     Test 1 addBack()
	 ***********************************************************************/	
	myList = new LinkedListOfInts();
	testNum++;
	
	try
	{
		// fill up the list adding to the back.
		for( int i = 0; i < 20; i++ )
		{
			myList->addBack( i );
		}
		
		// check stuff got added to list correctly.
		std::vector<int> v = myList->toVector();
		
		for( int i = 0; i < 20; i++ )
		{
			if( v[i] != i )
			{
				snprintf( errBuff, ERRBUFFLAST, "Failed at element: %3d, expected: %3d was: %3d.", i, i, v[i] );
				std::string bad_message( errBuff );
				
				wrong.push_back( bad_message );
			}
		}
	}
	catch( const std::exception& e )
	{
		snprintf( errBuff, ERRBUFFLAST, "Problem running test says: %s.", e.what() );
		std::string bad_message( errBuff );
		wrong.push_back( bad_message );
	}
	
	verifyTests( wrong, testNum, "addBack()" );
	
	delete myList;
	
	
	/************************************************************************
	 **     Test 2 addFront()
	 ***********************************************************************/	
	myList = new LinkedListOfInts();
	testNum++;
	
	try
	{
		// fill up the list adding to the front.
		for( int i = 19; i >= 0; i-- )
		{
			myList->addFront( i );
		}
		
		// check stuff got added to list correctly.
		std::vector<int> v = myList->toVector();
		
		for( int i = 0; i < 20; i++ )
		{
			if( v[i] != i )
			{
				snprintf( errBuff, ERRBUFFLAST, "Failed at element: %3d, expected: %3d was: %3d.", i, i, v[i] );
				std::string bad_message( errBuff );
				wrong.push_back( bad_message );
			}
		}
	}
	catch( const std::exception& e )
	{
		snprintf( errBuff, ERRBUFFLAST, "Problem running test says: %s.", e.what() );
		std::string bad_message( errBuff );
		wrong.push_back( bad_message );
	}
	
	verifyTests( wrong, testNum, "addFront()" );
	
	delete myList;
	
	
	/************************************************************************
	 **     Test 3 removeBack()
	 ***********************************************************************/	
	myList = new LinkedListOfInts();
	testNum++;
	
	try
	{
		// remove on the empty list, should return false
		if ( myList->removeBack() )
		{
			snprintf( errBuff, ERRBUFFLAST, "Returned true when removing from empty list!!!" );
			std::string bad_message( errBuff );
			wrong.push_back( bad_message );
		}
		
		// fill up the list adding to the back.
		for( int i = 0; i < 20; i++ )
		{
			myList->addBack( i );
		}
		
		// grab the current elements to check against.
		std::vector<int> v = myList->toVector();
		if( v.size() != 20 )
		{
			snprintf( errBuff, ERRBUFFLAST, "This test may fail falsely, expecting 20 elements, were %3lu.", v.size() );
			std::string bad_message( errBuff );
			wrong.push_back( bad_message );
		}
		
		// remove 10 of the elements, should return true each time.
		for( int i = 0; i < 10; i++ )
		{
			if ( myList->removeBack() )
			{
				continue;
			}
			
			snprintf( errBuff, ERRBUFFLAST, "Improper return removing element: %3d, returned false", 19 - i );
			std::string bad_message( errBuff );
			wrong.push_back( bad_message );
		}
		
		// grab the new vector to check against
		std::vector<int> v2 = myList->toVector();
		if( v2.size() != 10 )
		{
			snprintf( errBuff, ERRBUFFLAST, "Expecting 10 elements to be left, were %3lu.", v2.size() );
			std::string bad_message( errBuff );
			wrong.push_back( bad_message );
		}
		
		// make sure what is left matches
		for( int i = 0; i < 10; i++ )
		{
			if( v[i] != v2[i])
			{
				snprintf( errBuff, ERRBUFFLAST, "Failed at element: %3d, expected: %3d was: %3d.", i, v[i], v2[i] );
				std::string bad_message( errBuff );
				wrong.push_back( bad_message );
			}
		}
		
		// remove the last 10 elements
		for( int i = 0; i < 10; i++ )
		{
			if ( myList->removeBack() )
			{
				continue;
			}
			
			snprintf( errBuff, ERRBUFFLAST, "Improper return removing element: %3d, returned false", 9 - i );
			std::string bad_message( errBuff );
			wrong.push_back( bad_message );
		}
		
		// remove on the empty list, should return false
		if ( myList->removeBack() )
		{
			snprintf( errBuff, ERRBUFFLAST, "Returned true when removing from empty list!!!" );
			std::string bad_message( errBuff );
			wrong.push_back( bad_message );
		}
	}
	catch( const std::exception& e )
	{
		snprintf( errBuff, ERRBUFFLAST, "Problem running test says: %s.", e.what() );
		std::string bad_message( errBuff );
		wrong.push_back( bad_message );
	}
	
	verifyTests( wrong, testNum, "removeBack()" );
	
	delete myList;
	
	/************************************************************************
	 **     Test 4 removeFront()
	 ***********************************************************************/	
	myList = new LinkedListOfInts();
	testNum++;
	
	try
	{
		// remove on the empty list, should return false
		if ( myList->removeFront() )
		{
			snprintf( errBuff, ERRBUFFLAST, "Returned true when removing from empty list!!!" );
			std::string bad_message( errBuff );
			wrong.push_back( bad_message );
		}
		
		// fill up the list adding to the back.
		for( int i = 0; i < 20; i++ )
		{
			myList->addBack( i );
		}
		
		// grab the current elements to check against.
		std::vector<int> v = myList->toVector();
		if( v.size() != 20 )
		{
			snprintf( errBuff, ERRBUFFLAST, "This test may fail falsely, expecting 20 elements, were %3lu.", v.size() );
			std::string bad_message( errBuff );
			wrong.push_back( bad_message );
		}
		
		// remove 10 of the elements, should return true each time.
		for( int i = 0; i < 10; i++ )
		{
			if ( myList->removeFront() )
			{
				continue;
			}
			
			snprintf( errBuff, ERRBUFFLAST, "Improper return removing element: %3d, returned false", 19 - i );
			std::string bad_message( errBuff );
			wrong.push_back( bad_message );
		}
		
		// grab the new vector to check against
		std::vector<int> v2 = myList->toVector();
		if( v2.size() != 10 )
		{
			snprintf( errBuff, ERRBUFFLAST, "Expecting 10 elements to be left, were %3lu.", v2.size() );
			std::string bad_message( errBuff );
			wrong.push_back( bad_message );
		}
		
		// make sure what is left matches
		for( int i = 0; i < 10; i++ )
		{
			if( v[i + 10] != v2[i])
			{
				snprintf( errBuff, ERRBUFFLAST, "Failed at element: %3d, expected: %3d was: %3d.", i, v[i + 10], v2[i] );
				std::string bad_message( errBuff );
				wrong.push_back( bad_message );
			}
		}
		
		// remove the last 10 elements
		for( int i = 0; i < 10; i++ )
		{
			if ( myList->removeFront() )
			{
				continue;
			}
			
			snprintf( errBuff, ERRBUFFLAST, "Improper return removing element: %3d, returned false", 9 - i );
			std::string bad_message( errBuff );
			wrong.push_back( bad_message );
		}
		
		// remove on the empty list, should return false
		if ( myList->removeBack() )
		{
			snprintf( errBuff, ERRBUFFLAST, "Returned true when removing from empty list!!!" );
			std::string bad_message( errBuff );
			wrong.push_back( bad_message );
		}
	}
	catch( const std::exception& e )
	{
		snprintf( errBuff, ERRBUFFLAST, "Problem running test says: %s.", e.what() );
		std::string bad_message( errBuff );
		wrong.push_back( bad_message );
	}
	
	verifyTests( wrong, testNum, "removeFront()" );
	
	delete myList;
	
	/************************************************************************
	 **     Test 5 isEmpty()
	 ***********************************************************************/	
	myList = new LinkedListOfInts();
	testNum++;
	
	try
	{
		// is empty on the empty list should return true
		if ( !myList->isEmpty() )
		{
			snprintf( errBuff, ERRBUFFLAST, "returned false on the empty list!!!" );
			std::string bad_message( errBuff );
			wrong.push_back( bad_message );
		}
		
		// fill up the list adding to the back.
		for( int i = 0; i < 20; i++ )
		{
			myList->addBack( i );
		}
		
		// grab the current elements to check against.
		std::vector<int> v = myList->toVector();
		if( ( v.size() == 0 ) != myList->isEmpty() )
		{
			snprintf( errBuff, ERRBUFFLAST, 
						"The size of the list is %3lu, but returned %s.", 
						v.size(), 
						myList->isEmpty() ? "true" : "false" );
			std::string bad_message( errBuff );
			wrong.push_back( bad_message );
		}
		
		// remove the elements if that works.
		for( int i = 0; i < 20; i++ )
		{
			myList->removeFront();
		}
		
		// grab the new vector to check against
		v = myList->toVector();
		if( ( v.size() == 0 ) != myList->isEmpty() )
		{
			snprintf( errBuff, ERRBUFFLAST, 
						"The size of the list is %3lu, but returned %s.", 
						v.size(), 
						myList->isEmpty() ? "true" : "false" );
			std::string bad_message( errBuff );
			wrong.push_back( bad_message );
		}
	}
	catch( const std::exception& e )
	{
		snprintf( errBuff, ERRBUFFLAST, "Problem running test says: %s.", e.what() );
		std::string bad_message( errBuff );
		wrong.push_back( bad_message );
	}
	
	verifyTests( wrong, testNum, "isEmpty()" );
	
	delete myList;
	
	/************************************************************************
	 **     Test 6 size()
	 ***********************************************************************/	
	myList = new LinkedListOfInts();
	testNum++;
	
	try
	{
		// should return 0 on the empty list
		if ( myList->size() != 0 )
		{
			snprintf( errBuff, ERRBUFFLAST, "Size should return 0 on empty list, but instead returned %3d.", myList->size() );
			std::string bad_message( errBuff );
			wrong.push_back( bad_message );
		}
		
		// fill up the list adding to the back.
		for( int i = 0; i < 20; i++ )
		{
			myList->addBack( i );
		}
		
		// grab the current elements to check against.
		std::vector<int> v = myList->toVector();
		if( ( int )( v.size() ) != myList->size() )
		{
			snprintf( errBuff, ERRBUFFLAST, "Size of list is %3lu, but size() returned %3d.", v.size(), myList->size() );
			std::string bad_message( errBuff );
			wrong.push_back( bad_message );
		}
		
		// try to remove 10 of the elements.
		for( int i = 0; i < 10; i++ )
		{
			myList->removeFront();
		}
		
		// grab the current elements to check against.
		v = myList->toVector();
		if( ( int )(v.size()) != myList->size() )
		{
			snprintf( errBuff, ERRBUFFLAST, "Size of list is %3lu, but size() returned %3d.", v.size(), myList->size() );
			std::string bad_message( errBuff );
			wrong.push_back( bad_message );
		}
		
		// try to empty the list
		for( int i = 0; i < 10; i++ )
		{
			myList->removeFront();
		}
		
		// grab the current elements to check against.
		v = myList->toVector();
		if( ( int )( v.size() ) != myList->size() )
		{
			snprintf( errBuff, ERRBUFFLAST, "Size of list is %3lu, but size() returned %3d.", v.size(), myList->size() );
			std::string bad_message( errBuff );
			wrong.push_back( bad_message );
		}
	}
	catch( const std::exception& e )
	{
		snprintf( errBuff, ERRBUFFLAST, "Problem running test says: %s.", e.what() );
		std::string bad_message( errBuff );
		wrong.push_back( bad_message );
	}
	
	verifyTests( wrong, testNum, "size()" );
	
	delete myList;
	
	/************************************************************************
	 **     Test 6 search()
	 ***********************************************************************/	
	myList = new LinkedListOfInts();
	testNum++;
	
	try
	{
		// fill up the list adding to the back.
		for( int i = 0; i < 20; i++ )
		{
			myList->addBack( i );
		}
		
		// make sure we can find the elements we inserted.
		std::vector<int> v = myList->toVector();
		
		for(int n : v)
		{
			if( !myList->search( n ) )
			{
				snprintf( errBuff, ERRBUFFLAST, "Element %3d, is in the list but search() did not find it.", n );
				std::string bad_message( errBuff );
				wrong.push_back( bad_message );
			}
		}
		
		// make sure we can't find elements that we didn't insert
		for( int i = 20; i < 40; i++ )
		{
			if( myList->search( i ) )
			{
				snprintf( errBuff, ERRBUFFLAST, "Element %3d, should not be in the list but search() found it.", i );
				std::string bad_message( errBuff );
				wrong.push_back( bad_message );
			}
		}
	}
	catch( const std::exception& e )
	{
		snprintf( errBuff, ERRBUFFLAST, "Problem running test says: %s.", e.what() );
		std::string bad_message( errBuff );
		wrong.push_back( bad_message );
	}
	
	verifyTests( wrong, testNum, "search()" );
	
	delete myList;
	
	std::cout << "\n";
}


void verifyTests( std::vector<std::string> & wrong, int testNum, const char * testName )
{
	if( wrong.size() == 0 )
	{
		std::cout << "Test " << testNum << ": " << testName << ": PASSED\n";
	}
	else
	{
		std::cout << "Test " << testNum << ": " << testName << ": FAILED\n";
		for( std::string message : wrong ) 
		{
			std::cout << "\t" <<  message << "\n";
		}
		
		wrong.clear();
	}	
}
