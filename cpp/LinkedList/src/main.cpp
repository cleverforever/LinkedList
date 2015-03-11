/* 
 * File:   main.cpp
 * Author: yuyc
 *
 * Created on 2015骞�3鏈�5鏃�, 涓嬪崍5:46
 */

#include <cstdlib>
#include "LinkedList.h"
using namespace std;

/*
 * 
 */
int main(int, char**) {
    LinkedList<int>* list = new LinkedList<int>();
    
    for(int i=1;i<=10;i++){
        bool isOK = list->insertInFront(i%5);
        if(!isOK){           
            delete list;
            return false;
        }
    }
    cout<<"inserted"<<endl;
    list->printList();

    for(int j=4;j>=0;j--){
        list->delNodeInFront(j);
        cout<<"deleted"<<j<<endl;    
        list->printList();
    }

    delete list;
    return 0;
}

