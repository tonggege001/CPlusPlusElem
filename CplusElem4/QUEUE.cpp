//
// Created by Administor on 2018/11/7.
//

#include <iostream>
#include "QUEUE.h"

QUEUE::QUEUE(int m) : STACK(m),s2(m) {

}

QUEUE::QUEUE(const QUEUE &s):STACK(s),s2(s.s2) {

}

QUEUE::operator int() const {
    const STACK * s = this;
    return s->STACK::operator int()+int(this->s2);
}

int QUEUE::full() const {
    if(int(this->s2)==0)
        return 0;
    else{
        if(this->STACK::size()==this->STACK::operator int())
            return 1;
        else
            return 0;
    }
}

int QUEUE::operator[](int x) const {
    //在辅助栈中搜索
    if(x < int(this->s2)){
        return s2[(int(s2))-x-1];
    }
    else{
        x = x-int(this->s2);
        return  this->STACK::operator[](x);
    }

}
/**
 * 入队列操作
 * 算法思想：首先判断辅助数组是否满，如果满了则返回错误码，否则元素放进父栈中。
 * @param e 元素
 * @return
 */
QUEUE &QUEUE::operator<<(int e) {
    if(!this->full()){
        //判断父栈是否满，如果满了则将原来的数据导入到辅助栈中

        if(this->STACK::size()==this->STACK::operator int()){
            int total = this->STACK::operator int();
            for(int i = 0;i<total;i++){
                int elem = 0;
                this->STACK::operator>> (elem);
                this->s2<<elem;
            }
        }
        this->STACK::operator<<(e);
    }
}

/**
 * 出队列，辅助栈中有元素则出辅助栈，否则的话将元素倾倒在辅助栈中，然后再在辅助数组中出栈，然后
 * 再将元素倒回原来的父栈
 * @param e
 * @return
 */
QUEUE &QUEUE::operator>>(int &e) {
    //辅助栈不空
    if(int(this->s2) != 0){
        s2>>e;
        return *this;
    }
    else{
        //将原数组倾倒在辅助数组中
        int num = this->STACK::operator int();
        for(int i = 0;i<num;i++){
            int elem;
            this->STACK::operator>>(elem);
            this->s2<<elem;
        }
        s2>>e;
        num = int(this->s2);
//        for(int i = 0;i<num;i++){
//            int elem;
//            s2>>elem;
//            this->STACK::operator<<(elem);
//        }
        return *this;
    }
}
//赋值操作
QUEUE &QUEUE::operator=(const QUEUE &s) {
    this->STACK::operator=(s);
    STACK * s_old = this;
    const STACK * s_new = &s;
    *s_old = *s_new;
    this->s2 = s.s2;
}

void QUEUE::print() const {
    for(int i = int(s2)-1;i>=0;i--){
        if(i>0)
            std::cout<<s2[i]<<"  ";
        else if(i==0 && this->STACK::operator int() >0){
            std::cout<<s2[i]<<"  ";
        }
        else{
            std::cout<<s2[i];
        }
    }
    for(int i = 0;i<this->STACK::operator int();i++){
        if(i!=this->STACK::operator int()-1)
            std::cout<<this->STACK::operator[](i)<<"  ";
        else
            std::cout<<this->STACK::operator[](i);

    }
}

QUEUE::~QUEUE() {

}





