#include <iostream>
#include <cstring>
#include "QUEUE.h"

using namespace std;

bool isPrime(int a,int b){
    if(a==b) return false;
    for(int i = 2;i<=min(a,b);i++){
        if((!a%i) && (!b%i)){
            return true;
        }
    }
}

int main(int argc, char * argv[]) {
    if(argc != 1) {
        char *state;
        QUEUE *stack1, *stack2;
        int count = 1;
        char *Ins;
        while (count < argc) {
            //读取一个字符
            state = argv[count];
            count++;
            //开始状态
            if (strcmp(state, "-S") == 0) {
                Ins = argv[count];
                count++;
                int m = atoi(Ins);
                stack1 = new QUEUE(m);
                std::cout << 'S' << "  " << m;
            } else if (strcmp(state, "-I") == 0) {
                std::cout << "  I";
                int num = 0;
                while (true) {
                    Ins = argv[count];
                    count++;
                    //如果输入不合法则直接退回去
                    if (count > argc || Ins[0] < '0' || Ins[0] > '9') {
                        count--;
                        break;
                    }
                    //处理爆栈情况

                    if (stack1->full()) {
                        num = -1;
                        std::cout << "  E";
                        break;
                    } else
                        *stack1 << atoi(Ins);
                }
                if (num == -1) return 0;
                for (int i = num; i < (int) (*stack1); i++) {
                    std::cout << "  " << (*stack1)[i];
                }
            } else if (strcmp(state, "-O") == 0) {
                std::cout << "  O";
                Ins = argv[count];
                count++;
                int popNum = atoi(Ins);
                if (popNum > (int) (*stack1)) {
                    std::cout << "  E";
                    return 0;
                } else {
                    int e;
                    for (int i = 0; i < popNum; i++) {
                        *stack1 >> e;
                    }
                }
                for (int i = 0; i < (int) (*stack1); i++) {
                    std::cout << "  " << (*stack1)[i];
                }
            }
                //深拷贝构造操作
            else if (strcmp(state, "-C") == 0) {
                std::cout << "  C";
                stack2 = new QUEUE(*stack1);
                delete stack1;
                stack1 = stack2;
                std::cout << "  ";
                stack1->print();
            } else if (strcmp(state, "-A") == 0) {
                std::cout << "  A";
                Ins = argv[count];
                count++;
                stack2 = new QUEUE(atoi(Ins));
                *stack2 = *stack1;
                delete stack1;
                stack1 = stack2;
                std::cout << "  ";
                stack1->print();
            } else if (strcmp(state, "-N") == 0) {
                std::cout << "  N  " << (int) (*stack1);
            } else if (strcmp(state, "-G") == 0) {
                Ins = argv[count];
                count++;
                std::cout << "  G";
                if ((int) (*stack1) > atoi(Ins) && atoi(Ins) > 0)
                    std::cout << "  " << (*stack1)[atoi(Ins)];
                else {
                    std::cout << "  E";
                    return 0;
                }
            }
        }
        delete stack1;
        return 0;
    } else{
        int music_num = 0;//歌曲轮数
        int M,F;  //男女队列的人数
        int m;  //男士的位置
        int f;  //女士的位置
        //男士初始的女伴位置，当男士再一次和初始的女伴跳舞的时候，这说明不能够和女伴跳舞
        int m_initFriend;

        cout<<"请输入男士的人数："<<endl;
        cin>>M;
        QUEUE & Q_M = *new QUEUE(M);
        for(int i = 1;i<=M;i++){
            Q_M<<i;
        }

        cout<<"请输入女士的人数："<<endl;
        cin>>F;
        QUEUE & Q_F = *new QUEUE(F);
        for(int i = 1;i<=F;i++){
            Q_F<<i;
        }
        cout<<"请输入男生位置m：";
        cin>>m;
        cout<<"请输入女生位置f：";
        cin>>f;
        m_initFriend = m%f;  //男生第一次的女舞伴
        int find = 0;  //记录男士第几次遇见第一个舞伴，如果是第二次这说明永远也见不到女舞伴了
        bool enable = false;
        do{
            int man,women;
            Q_M>>man;
            Q_F>>women;
            if(man==m){
                music_num++;
                if(women==m_initFriend){
                    find++;
                    if(find==2){
                        enable = false;
                        break;
                    }
                }
                if(women == f){
                    enable = true;
                    break;
                }
            }
            Q_M<<man;
            Q_F<<women;

        }while (true);
        //插入
        if(enable== false){
            cout<<"男士永远不能和女士跳舞"<<endl;
        }
        else{
            cout<<"男士在第"<<music_num<<"首歌时能够和女伴跳舞"<<endl;
        }
    }
}