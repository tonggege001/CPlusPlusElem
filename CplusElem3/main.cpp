#include <iostream>
#include <cstring>
#include "STACK.h"

using namespace std;

int main(int argc, char * argv[]) {
    char* state;
    STACK * stack1,*stack2;
    int count = 1;
    char * Ins;
    while(count < argc){
        //读取一个字符
        state = argv[count];
        count++;
        //开始状态
        if(strcmp(state,"-S") == 0){
            Ins = argv[count];
            count++;
            int m = atoi(Ins);
            stack1 = new STACK(m);
            std::cout<<'S'<<"  "<<m;
        }
        else if(strcmp(state,"-I")==0){
            std::cout<<"  I";
            int num = 0;
            while(true){
                Ins = argv[count];
                count++;
                //如果输入不合法则直接退回去
                if(count >argc||Ins[0]<'0'||Ins[0]>'9'){
                    count--;
                    break;
                }
                //处理爆栈情况
                if((int)(*stack1)>=stack1->size()){
                    num = -1;
                    std::cout<<"  E";
                    break;
                }
                else
                    *stack1<<atoi(Ins);
            }
            if(num==-1) return 0;
            for(int i = num;i<(int)(*stack1);i++){
                std::cout<<"  "<<(*stack1)[i];
            }
        }
        else if(strcmp(state,"-O")==0){
            std::cout<<"  O";
            Ins = argv[count];
            count++;
            int popNum = atoi(Ins);
            if(popNum>(int)(*stack1)){
                std::cout<<"  E";
                return 0;
            }
            else{
                int e;
                for(int i = 0;i<popNum;i++){
                    *stack1>>e;
                }
            }
            for (int i = 0; i < (int)(*stack1); i++) {
                std::cout << "  " << (*stack1)[i];
            }
        }
            //深拷贝构造操作
        else if(strcmp(state,"-C")==0){
            std::cout<<"  C";
            stack2 = new STACK(*stack1);
            delete stack1;
            stack1 = stack2;
            std::cout<<"  ";
            stack1->print();
        }
        else if(strcmp(state,"-A") == 0){
            std::cout<<"  A";
            Ins = argv[count];
            count++;
            stack2 = new STACK(atoi(Ins));
            *stack2=*stack1;
            delete stack1;
            stack1 = stack2;
            std::cout<<"  ";
            stack1->print();
        }
        else if(strcmp(state,"-N")==0){
            std::cout<<"  N  "<<(int)(*stack1);
        }
        else if(strcmp(state,"-G")==0){
            Ins = argv[count];
            count++;
            std::cout<<"  G";
            if((int)(*stack1) > atoi(Ins) && atoi(Ins) >0)
                std::cout <<"  "<< (*stack1)[atoi(Ins)];
            else {
                std::cout << "  E";
                return 0;
            }
        }
    }
    delete stack1;
    return 0;
}