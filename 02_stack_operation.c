// Program to show array implementaion of stack along with its different operations

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct{
    int stack[MAX];
    int top;
} Stack;

void push(Stack *s){
    int num;
    if(s->top == MAX-1){
        printf("Stack is Full!\n\n");
        return;
    }
    else{
        printf("Enter the element to push:");
        scanf("%d", &num);
        s->top++;
        s->stack[s->top]= num;
        printf("\n");
    }
}

void pop(Stack *s){
    int num;
    if(s->top == -1){
        printf("Stack is Empty!\n\n");
        return;
    }
    else{
        num = s->stack[s->top];
        printf("Poped Element: %d\n", num);
        s->top--;
        printf("\n");
    }
}

void display(Stack *s){
    int i;
    if(s->top == -1){
        printf("Stack is Empty!\n\n");
        return;
    }
    else{
        printf("Elements on the Stack: ");
        for(i=0; i<= s->top; i++){
            printf("%d\t",s->stack[i]);
        }
        printf("\n\n");
    }
}

int main(){
    system("clear");
    Stack s;
    s.top= -1;
    int choice;
    do{
        printf("--- Select Stack Operation ---");
        printf("\n1. push()");
        printf("\n2. pop()");
        printf("\n3. display()");
        printf("\n4. exit()");
        printf("\nEnter your choice:");
        scanf("%d",&choice);         
        switch (choice){
            case 1:
                push(&s);
                break;
            
            case 2:
                pop(&s);
                break;

            case 3:
                display(&s);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid input!\n");
                break;
        }
    }while(choice != 4);
    
    return 0;
}