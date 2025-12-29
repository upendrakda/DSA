// Program to convert infix expression to prefix expression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct {
    char data[MAX];
    int top;
} Stack;

// precedence function
int precedence(char ch) {
    switch(ch) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return 0;
}

// stack operations
void push(Stack *s, char ch) {
    s->data[++s->top] = ch;
}

char pop(Stack *s) {
    return s->data[s->top--];
}

char peek(Stack *s) {
    return s->data[s->top];
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

// reverse a string
void reverse(char exp[]) {
    int i, j;
    char temp;
    for(i = 0, j = strlen(exp)-1; i < j; i++, j--) {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
}

int main() {
    system("cls");

    Stack opstack;
    opstack.top = -1;

    char infix[MAX], prefix[MAX];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    // STEP 1: Reverse infix
    reverse(infix);

    // STEP 2: Replace '(' with ')' and vice versa
    for(i = 0; i < strlen(infix); i++) {
        if(infix[i] == '(')
            infix[i] = ')';
        else if(infix[i] == ')')
            infix[i] = '(';
    }

    // STEP 3: Convert to postfix (store in prefix array temporarily)
    for(i = 0; i < strlen(infix); i++) {
        char ch = infix[i];

        // operand
        if((ch >= 'a' && ch <= 'z') || 
           (ch >= 'A' && ch <= 'Z') || 
           (ch >= '0' && ch <= '9')) {
            prefix[j++] = ch;
        }
        // '('
        else if(ch == '(') {
            push(&opstack, ch);
        }
        // ')'
        else if(ch == ')') {
            while(!isEmpty(&opstack) && peek(&opstack) != '(') {
                prefix[j++] = pop(&opstack);
            }
            pop(&opstack); // remove '('
        }
        // operator
        else {
            while(!isEmpty(&opstack) &&
                  precedence(peek(&opstack)) > precedence(ch)) {
                prefix[j++] = pop(&opstack);
            }
            push(&opstack, ch);
        }
    }

    // pop remaining operators
    while(!isEmpty(&opstack)) {
        prefix[j++] = pop(&opstack);
    }

    prefix[j] = '\0';

    // STEP 4: Reverse postfix → prefix
    reverse(prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}