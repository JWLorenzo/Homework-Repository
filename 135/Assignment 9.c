//Jacob Lorenzo
//Creates an array based on command line arguments and pushes numbers to it.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//initializes the array
void init(int *head, int *tail)
{
    *head = *tail = 0;
}

//checks if the array is full
int full(int tail,const int size)
{
    return tail == size;
}

//pushes integers to the array
void push(int *q,int *tail, int element,int size)
{
    if(!full(*tail,size)){
    q[(*tail)++] = element;
    }
}

//displays the current array in the correct format
void display(int *q,int head,int tail)
{
    int i = tail - 1;
    while(i >= head)
        printf("%d,",q[i--]);
    printf("\n");
}

int main(int argc, char *argv[])
{
    //setting up arrays for data verification and command line inputs
    char z[10],y[10],x[10],w[10],*value;
    value = argv[1];
    int finVal = *value-'0';
    const int SIZE = finVal+1;
    int head, tail, element;
    int queue[SIZE];
    init(&head,&tail);
    
    //while loop condition ends the loop so it doesn't go forever
    while(!full(tail,SIZE)){
    printf("Enter command (push, print, or quit): ");
    scanf(" %[^\n]s",z);
    
    //memset clears the memory so it doesn't print out garbled characters
    memset(x, '\0', sizeof(x));
    memset(y, '\0', sizeof(y));
    memset(w, '\0', sizeof(w));
    strncpy(x,z,4);
    
    //if statement ends the program if quit is typed
    if (strcmp(x,"quit") == 0){
        exit(1);
    }
    //strncpy separates the input into comparable chunks
    strncpy(w,z,5);
    strncpy(y,z+5,strlen(z)-5);
    
    //if statements to determine behavior
    if (strcmp(x,"push") == 0){
        push(queue,&tail,atoi(y),SIZE);
    }
    else if (strcmp(w,"print") == 0){
        display(queue,head,tail);
    }
    }
    
    //once the program ends, it prints the overflow since the program ends if it either overflows or exits
    printf("Overflow: %d",queue[0]);
    }
    
