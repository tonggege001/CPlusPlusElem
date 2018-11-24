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
            //��ȡһ���ַ�
            state = argv[count];
            count++;
            //��ʼ״̬
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
                    //������벻�Ϸ���ֱ���˻�ȥ
                    if (count > argc || Ins[0] < '0' || Ins[0] > '9') {
                        count--;
                        break;
                    }
                    //����ջ���

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
                //����������
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
        int music_num = 0;//��������
        int M,F;  //��Ů���е�����
        int m;  //��ʿ��λ��
        int f;  //Ůʿ��λ��
        //��ʿ��ʼ��Ů��λ�ã�����ʿ��һ�κͳ�ʼ��Ů�������ʱ����˵�����ܹ���Ů������
        int m_initFriend;

        cout<<"��������ʿ��������"<<endl;
        cin>>M;
        QUEUE & Q_M = *new QUEUE(M);
        for(int i = 1;i<=M;i++){
            Q_M<<i;
        }

        cout<<"������Ůʿ��������"<<endl;
        cin>>F;
        QUEUE & Q_F = *new QUEUE(F);
        for(int i = 1;i<=F;i++){
            Q_F<<i;
        }
        cout<<"����������λ��m��";
        cin>>m;
        cout<<"������Ů��λ��f��";
        cin>>f;
        m_initFriend = m%f;  //������һ�ε�Ů���
        int find = 0;  //��¼��ʿ�ڼ���������һ����飬����ǵڶ�����˵����ԶҲ������Ů�����
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
        //����
        if(enable== false){
            cout<<"��ʿ��Զ���ܺ�Ůʿ����"<<endl;
        }
        else{
            cout<<"��ʿ�ڵ�"<<music_num<<"�׸�ʱ�ܹ���Ů������"<<endl;
        }
    }
}