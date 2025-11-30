
#ifndef stack_h
#define stack_h
#include "node.h"

class Stack {
	NodePtr top;
	int size;
public:
    void push(int);
    int pop();
    Stack();
    ~Stack();
};


Stack::Stack() {
    top = NULL;
    size = 0;
}

Stack::~Stack() {
    while (top != NULL)
        pop();
}

void Stack::push(int x) {
    NodePtr new_node = new NODE(x);
    new_node->set_next(top);
    top = new_node;
    size++;
}

int Stack::pop() {

    if (top == NULL) {
        cout << "Empty stack" << endl;
        return -1;
    }

    NodePtr t = top;
    int value = t->get_value();
    top = t->get_next();
    delete t;
    size--;

    // REQUIRED output during pop
    cout << value << endl;

    return value;
}

#endif