//Program to evaluate prefix expression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 50

typedef struct {
    int data[MAX];
    int top;
} Stack;

void push(Stack *s, int value) {
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    return s->data[s->top--];
}

// reverse string
void reverse(char exp[]) {
    int i, j;
    char temp;
    for(i = 0, j = strlen(exp) - 1; i < j; i++, j--) {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
}

int main() {
    system("cls");

    Stack s;
    s.top = -1;

    char prefix[MAX];
    int i, op1, op2, result;

    printf("Enter prefix expression: ");
    scanf("%s", prefix);

    // Step 1: Reverse prefix expression
    reverse(prefix);

    // Step 2: Evaluate like postfix
    for(i = 0; i < strlen(prefix); i++) {

        if(prefix[i] >= '0' && prefix[i] <= '9') {
            push(&s, prefix[i] - '0');
        }
        else {
            op1 = pop(&s);
            op2 = pop(&s);

            switch(prefix[i]) {
                case '+': result = op2 + op1; break;
                case '-': result = op2 - op1; break;
                case '*': result = op2 * op1; break;
                case '/': result = op2 / op1; break;
                case '^': result = pow(op2, op1); break;
            }
            push(&s, result);
        }
    }

    printf("Result = %d\n", pop(&s));

    return 0;
}
