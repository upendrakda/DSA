// Program to convert infix expression to postfix expression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct {
    char data[MAX];
    int top;
} Stack;

// Function to get precedence of operators
int precedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

// Stack operations
void push(Stack *s, char ch) {
    if(s->top < MAX-1) {
        s->top++;
        s->data[s->top] = ch;
    }
}

char pop(Stack *s) {
    if(s->top >= 0)
        return s->data[s->top--];
    return '\0'; // Return null char if stack empty
}

char peek(Stack *s) {
    if(s->top >= 0)
        return s->data[s->top];
    return '\0';
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int main(){
    system("cls");
    Stack opstack;
    opstack.top = -1;
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for(i = 0; i < strlen(infix); i++){
        char ch = infix[i];

        // If operand, add to postfix
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            postfix[j++] = ch;
        }
        // If '(', push to stack
        else if(ch == '('){
            push(&opstack, ch);
        }
        // If ')', pop till '('
        else if(ch == ')'){
            while(!isEmpty(&opstack) && peek(&opstack) != '('){
                postfix[j++] = pop(&opstack);
            }
            if(!isEmpty(&opstack) && peek(&opstack) == '(')
                pop(&opstack); // remove '('
        }
        // If operator
        else {
            while(!isEmpty(&opstack) && precedence(peek(&opstack)) >= precedence(ch)){
                postfix[j++] = pop(&opstack);
            }
            push(&opstack, ch);
        }
    }

    // Pop remaining operators
    while(!isEmpty(&opstack)){
        postfix[j++] = pop(&opstack);
    }

    postfix[j] = '\0'; // null terminate string

    printf("Postfix expression: %s\n", postfix);

    return 0;
}