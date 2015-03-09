#include "cute_suite.h"
#include "LinkedList.h"

extern cute::suite make_suite_TestLinkedList();

class TestLinkedList{
public:
	TestLinkedList();
	~TestLinkedList();
	void operator() ();

	void testInsert();
	void testDelete();

private:
	LinkedList<int>* list;
};
