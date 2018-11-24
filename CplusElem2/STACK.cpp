//
// Created by Administor on 2018/10/24.
//

#include "STACK.h"
#include <iostream>

using namespace std;


STACK::STACK(int m):elems(new int[m]),max(m) {
    this->pos=0;
}

STACK::STACK(const STACK &s):elems(new int[s.max]),max(s.max) {
    this->pos = s.pos;
    for(int i = 0;i<this->pos;i++){
        this->elems[i] = s.elems[i];
    }
}

int STACK::size() const {
    return this->max;
}

int STACK::howMany() const {
    return this->pos;
}

int STACK::getelem(int x) const {
    return this->elems[x];
}

STACK &STACK::push(int e) {
    if(this->pos<this->max){
        this->elems[this->pos] = e;
        this->pos++;
        return *this;
    }
}

STACK &STACK::pop(int &e) {
    this->pos--;
    e = this->elems[this->pos];
    return *this;
}

STACK &STACK::assign(const STACK &s) {
    delete this->elems;
    this->pos = s.pos;
    int * p = (int *)&this->max;
    *p = s.max;
    *(int **) (&this->elems) = new int[s.max];
    for (int i = 0; i < s.pos; i++) {
        this->elems[i] = s.elems[i];
    }
    return *this;
}

void STACK::print() const {
    for(int i = 0;i<this->pos;i++){
        if(i != this->pos-1)
            cout<<this->elems[i]<<"  ";
        else
            cout<<this->elems[i];
    }
}

STACK::~STACK() {
    delete this->elems;
    *(int **)(&this->elems) = nullptr;
}



















