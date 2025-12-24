//Program to implement Dynamic Memory Allocation (DMA) using malloc(), 
//calloc(), realloc() and free()

#include<stdio.h>
#include<stdlib.h>

void using_malloc(){
    int  i, n, new, *ptr, *ptr1;
    char choice;
    printf("Enter total number of elements:");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    printf("\nEnter Elements:\n");
    for(i=0; i<n; i++){
        printf("Element[%d]:",i+1);
        scanf("%d",(ptr+i));
    }

    printf("Do you want to reallocate(y/n?):");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y')
    {
        printf("Enter new size: ");
        scanf("%d", &new);

        ptr1 = (int *)realloc(ptr, new * sizeof(int));
        
        ptr = ptr1;

        if (new > n)
        {
            printf("Enter remaining elements:\n");
            for (i = n; i < new; i++)
            {
                printf("Element[%d]: ", i + 1);
                scanf("%d", (ptr + i));
            }
        }

        n = new;
    }

    printf("\nElements You Entered:\n");
    for(i=0; i<n; i++){
        printf("%d\t",*(ptr+i));
    }
    printf("\n\n");
    free(ptr);
}

void using_calloc(){
    int  i, n, new, *ptr, *ptr1;
    char choice;
    printf("Enter total number of elements:");
    scanf("%d",&n);
    ptr=(int*)calloc(n,sizeof(int));
    printf("\nEnter Elements:\n");
    for(i=0; i<n; i++){
        printf("Element[%d]:",i+1);
        scanf("%d",(ptr+i));
    }

    printf("Do you want to reallocate(y/n?):");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y')
    {
        printf("Enter new size: ");
        scanf("%d", &new);

        ptr1 = (int *)realloc(ptr, new * sizeof(int));
        
        ptr = ptr1;

        if (new > n)
        {
            printf("Enter remaining elements:\n");
            for (i = n; i < new; i++)
            {
                printf("Element[%d]: ", i + 1);
                scanf("%d", (ptr + i));
            }
        }

        n = new;
    }


    printf("\nElements You Entered:\n");
    for(i=0; i<n; i++){
        printf("%d\t",*(ptr+i));
    }
    printf("\n\n");
    free(ptr);
}

int main(){
    system("clear");
    int choice;
    printf("-- Dynamic Memory Allocation --");
    printf("\n1. Using malloc()");
    printf("\n2. Using calloc()");
    printf("\n3. Exit\n");
    printf("Enter Your Choice:");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        using_malloc();
        break;
    case 2:
        using_calloc();
        break;
    case 3:
        exit(0);
    default:
        printf("Invalid Input!");
        break;
    }

    return 0;
}