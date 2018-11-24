#include <iostream>
#include <cstring>


typedef struct STACK {
	int  *elems;	//申请内存用于存放栈的元素
	int   max;	//栈能存放的最大元素个数
	int   pos;	//栈实际已有元素个数，栈空时pos=0;
}STACK;



//初始化p指向的栈：最多m个元素
void initSTACK(STACK *const p, int m) {
	p->elems = (int *)malloc(sizeof(int)*m);
	p->max = m;
	p->pos = 0;

}

//用栈s初始化p指向的栈
void initSTACK(STACK *const p, const STACK&s) {
	p->elems = (int *)malloc(sizeof(int)*s.max);
	p->max = s.max;
	p->pos = s.pos;
	for (int i = 0; i<s.pos; i++) {
		p->elems[i] = s.elems[i];
	}
}
//返回p指向的栈的最大元素个数max
int  size(const STACK *const p) {
	if (p == NULL) return -1;
	return p->max;
}
//返回p指向的栈的实际元素个数pos
int  howMany(const STACK *const p) {
	if (p == NULL) return -1;
	return p->pos;
}

//取下标x处的栈元素
int  getelem(const STACK *const p, int x) {
	if (p == NULL) return -1;
	return p->elems[x];

}
STACK *const push(STACK *const p, int e) {
	if (p->pos<p->max) {
		p->elems[p->pos] = e;
		p->pos++;
		return p;
	}
	return NULL;
}

STACK *const pop(STACK *const p, int &e) {
	if (p->pos>0) {
		p->pos--;
		e = p->elems[p->pos];
	}
	return p;
}

//赋s给p指的栈,并返回p
STACK *const assign(STACK*const p, const STACK&s) {
	if (p->elems != NULL) free(p->elems);
	p->elems = (int *)malloc(sizeof(int) * s.max);
	p->max = s.max;
	for (int i = 0; i<s.pos; i++) {
		p->elems[i] = s.elems[i];
	}
	p->pos = s.pos;
	return p;
}

//打印p指向的栈
void print(const STACK*const p) {
	for (int i = 0; i<p->pos; i++) {
		std::cout << p->elems[i];
		if (i != p->pos - 1)
			std::cout << "  ";
	}
}
//销毁p指向的栈
void destroySTACK(STACK*const p) {
	if (p->elems != NULL)
		free(p->elems);
}


int main(int argc, char *argv[]) {
	char* state;
	struct STACK * stack1 = NULL, *stack2 = NULL;
	int count = 1;
	char * Ins;
	while (count < argc) {
		//读取一个字符
		state = argv[count];
		count++;
		//开始状态
		if (strcmp(state, "-S") == 0) {
			stack1 = (STACK *)malloc(sizeof(STACK));
			Ins = argv[count];
			count++;
			int m = atoi(Ins);
			initSTACK(stack1, m);
			std::cout << 'S' << "  " << m;
		}
		else if (strcmp(state, "-I") == 0) {
			std::cout << "  I";
			int num = 0;
			while (true) {
				Ins = argv[count];
				count++;
				//如果输入不合法则直接退回去
				if (count >argc || Ins[0]<'0' || Ins[0]>'9') {
					count--;
					break;
				}
				//处理爆栈情况
				if (push(stack1, atoi(Ins)) == NULL) {
					num = -1;
					std::cout << "  E";
					break;
				}
			}
			if (num == -1) return 0;
			for (int i = num; i<stack1->pos; i++) {
				std::cout << "  " << getelem(stack1, i);
			}
		}
		else if (strcmp(state, "-O") == 0) {
			std::cout << "  O";
			Ins = argv[count];
			count++;
			int popNum = atoi(Ins);
			if (popNum>stack1->pos) {
				std::cout << "  E";
				return 0;
			}
			else {
				int e;
				for (int i = 0; i<popNum; i++) {
					pop(stack1, e);
				}
			}
			for (int i = 0; i < stack1->pos; i++) {
				std::cout << "  " << stack1->elems[i];
			}
			
		}
		//深拷贝构造操作
		else if (strcmp(state, "-C") == 0) {
			std::cout << "  C";
			stack2 = (STACK*)malloc(sizeof(STACK));
			initSTACK(stack2, *stack1);
			free(stack1);
			stack1 = stack2;
			std::cout << "  ";
			print(stack1);
		}
		else if (strcmp(state, "-A") == 0) {
			std::cout << "  A";
			Ins = argv[count];
			count++;
			stack2 = (STACK *)malloc(sizeof(STACK));
			initSTACK(stack2, atoi(Ins));
			assign(stack2, *stack1);
			free(stack1);
			stack1 = stack2;
			std::cout << "  ";
			print(stack1);
		}
		else if (strcmp(state, "-N") == 0) {
			std::cout << "  N  " << howMany(stack1);
		}
		else if (strcmp(state, "-G") == 0) {
			Ins = argv[count];
			count++;
			std::cout << "  G";
			if(stack1->pos > atoi(Ins) && atoi(Ins) >0)
				std::cout <<"  "<< getelem(stack1, atoi(Ins));
			else {
				std::cout << "  E";
				return 0;
			}
		}
	}
	destroySTACK(stack1);
	free(stack1);
	return 0;
}
























