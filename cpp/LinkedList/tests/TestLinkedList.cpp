#include "cute.h"
#include "TestLinkedList.h"

TestLinkedList::TestLinkedList() {
	list = new LinkedList<int>();
    for(int i=1;i<=5;i++){
        list->insertInFront(i);
    }
}

void TestLinkedList::testInsert() {
    ListElement<int>*  cur = list->getHead();
    for(int j=5;j>=1;j--){
        ASSERT_EQUAL( j, cur->getValue() );
        cur = cur->getNext();
    }
}

TestLinkedList::~TestLinkedList() {
	delete list;
}

void TestLinkedList::testDelete() {
    for(int j=5;j>=1;j--){
        list->delNodeInFront(j);
        ASSERT(!list->findNode(j));
    }
}


cute::suite make_suite_TestLinkedList(){
	cute::suite s;
	s.push_back(CUTE_SMEMFUN(TestLinkedList, testInsert));
	s.push_back(CUTE_SMEMFUN(TestLinkedList, testDelete));
	return s;
}

