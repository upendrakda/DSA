//Program to evaluate postfix expression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 50

typedef struct {
    int data[MAX];
    int top;
} Stack;

// stack operations
void push(Stack *s, int value) {
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    return s->data[s->top--];
}

int main() {
    system("cls");

    Stack s;
    s.top = -1;

    char postfix[MAX];
    int i, op1, op2, result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for(i = 0; i < strlen(postfix); i++) {

        // operand (single digit)
        if(postfix[i] >= '0' && postfix[i] <= '9') {
            push(&s, postfix[i] - '0'); // char to int
        }
        // operator
        else {
            op2 = pop(&s);
            op1 = pop(&s);

            switch(postfix[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
            }
            push(&s, result);
        }
    }

    printf("Result = %d\n", pop(&s));

    return 0;
}
