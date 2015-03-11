/* 
 * File:   LinkedList.h
 * Author: yuyc
 *
 * Created on 2015骞�2鏈�11鏃�, 涓嬪崍11:08
 */

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

#include"ListElement.h"
#include <cstdlib>
#include <iostream>

template<class T>
class LinkedList {
public:
    LinkedList():_head(NULL){}
    
    virtual ~LinkedList() {
        ListElement<T>* head = this->getHead();        
        while(head){
//            cout << "~LinkedList is invoked"<<endl;            
            this->setHead(head->getNext());
            delete head;
            head = this->getHead();   
        }
    }

    bool insertInFront(const T& data){
        ListElement<T> *newElem = new ListElement<T>(data);
        if (!newElem) {
            std::cout << "error happened @ insertInfront"<<std::endl;
            return false;
        }

        ListElement<T>* head = this->getHead();  
        newElem->setNext(head);
        this->setHead(newElem);

        return true;
    }

    void delNodeInFront(const T& data){
        ListElement<T> *pCur=NULL, *pNext=NULL;
        pCur=pNext=this->getHead();

        while(pNext){
        	if( pNext->getValue() == data ){
        		if( pNext == this->getHead() ){
        			pCur = pNext->getNext();
        			this->setHead(pCur);
        			delete pNext;
        			pNext = pCur;
        			continue;
        		}
        		else{
    				pCur->setNext(pNext->getNext());
        			delete pNext;
        			pNext = pCur->getNext();
        		}
        	}
        	else{
        		pCur = pNext;
        		pNext = pNext->getNext();
        	}
        }
    }
    
    void printList() const{
        ListElement<T>* head = this->getHead();
        if( !head ){
            std::cout<<"There is no element!"<<std::endl;
            return;
        }

        int i=0;
        ListElement<T> *cur = head;
        while(cur){
           std::cout<<"No:"<<i <<" is " << cur->getValue() <<std::endl;
           cur = cur->getNext();
           i++;
        }
    }
    
    ListElement<T>* getHead() const {
        return _head;
    }
    
    ListElement<T>* findNode(const T& data)const{
        ListElement<T>* cur = this->getHead();
        while(cur){
            if(cur->getValue() == data){
                break;
            }
            else
                cur = cur->getNext();
        }
        return cur;        
    }
    
protected:   
   void setHead(ListElement<T>* head){
       _head = head;
   }
   
private:
    ListElement<T>* _head;

};

#endif	/* LINKEDLIST_H */

