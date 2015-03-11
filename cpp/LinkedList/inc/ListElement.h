
/* 
 * File:   LinkedElement.h
 * Author: yuyc
 *
 * Created on 2015骞�2鏈�12鏃�, 涓婂崍11:56
 */

#ifndef LINKEDELEMENT_H
#define	LINKEDELEMENT_H
#include<cstdio>

template<class T>
class ListElement {
public:
    ListElement(const T& data):_next(NULL), _data(data){}
    virtual ~ListElement(){}
    
    inline  ListElement* getNext()  const {return _next;}
    inline const T& getValue() const {return _data;}
    inline void setNext(ListElement* elem) { _next = elem;}
    inline void setValue(const T&value) { _data = value;}
    
private:
    ListElement* _next;
    T _data;

    ListElement(const ListElement& orig):_next(NULL){}
};

#endif	/* LINKEDELEMENT_H */

