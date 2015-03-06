/* 
 * File:   main.cpp
 * Author: yuyc
 *
 * Created on 2015年3月5日, 下午5:46
 */

#include <cstdlib>
#include "LinkedList.h"
using namespace std;

/*
 * 
 */
int main(int, char**) {
    LinkedList<int>* list = new LinkedList<int>();
    
    for(int i=1;i<=5;i++){
        bool isOK = list->insertInFront(i);
        if(!isOK){           
            delete list;
            return false;
        }
    }
    cout<<"inserted"<<endl;
    list->printList();
    
    for(int j=5;j>=1;j--){
        list->delNodeInFront(j);
        cout<<"deleted"<<j<<endl;    
        list->printList();
    }

//    delete list;
    return 0;
}

