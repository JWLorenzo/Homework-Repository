//Jacob Lorenzo
//takes matrix sizes and generates random values to fill the matrix, then multiplies
//the two matrices
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h>
//r refers to row and c refers to column
int r1,c1,r2,c2;
int main(){
    //sets the time at 0 for random
    srand(time(0));
    printf("Enter number of rows and columns of first matrix (format: r x c):\n");
    //the scanf skips the 3 middle between the two numbers
    scanf(" %d%*c%*c%*c%d",&r1,&c1);
    //initial conditionl to make sure that the matrix work and both are greater than 0
    if (r1>0 && c1>0){
    }else{
       printf("Error: Tre number of rows or columns of a matrix can’t be 0\n");
       main();
    }
    //same situation as the previous setup, but for the second matrix
    printf("Enter number of rows and columns of second matrix (format: r x c):\n");
    scanf(" %d%*c%*c%*c%d",&r2,&c2);
    printf("\n");
    if (r2>0 && c2>0){
    }else{
       printf("Error: Tre number of rows or columns of a matrix can’t be 0\n");
       main();
    }
    printf("Program output:\n\n");
    //sets up the 3 arrays that are used for storing numbers and multiplying
    int array1[r1][c1];
    int array2[r2][c2];
    int array3[r1][c2];
    //setting up array1 using for loops
    if(c1 == r2){
    for(int i = 0; i<r1; ++i){
        for(int j = 0; j<c1; ++j){
            //rand() generates a random number
            array1[i][j] = (rand() % 
           (9 - 1 + 1)) + 1;
        }
    }
    //setting up array2 the same thing as the previous setup
    for(int i = 0; i<r2; ++i){
        for(int j = 0; j<c2; ++j){
            array2[i][j] = (rand() % 
           (9 - 1 + 1)) + 1;
           
        }
    }
    //setting up array3 full of 0's because it can be buggy without the 0's
    for (int i = 0; i<r1; ++i) {
        for (int j = 0; j<c2; ++j) {
            array3[i][j] = 0;
        }
    }
    
    //adding numbers to array3 through a similar method to the previous loops, 
    //but the k is used to make the the matrices line up
    for (int i = 0; i<r1; ++i) {
        for (int j = 0; j<c2; ++j) {
            for (int k=0; k<c1; ++k) {
                array3[i][j] += array1[i][k] * array2[k][j];
            }
        }
    }
    //printing array1 through a method similar to the setup of the array, but
    //uses an if statement to make sure it doesn't print all in the same line
    printf("Array1 Matrix:\n\n");
    for(int i = 0; i<r1; ++i){
        for(int j = 0; j<c1; ++j){
                printf("%d ",array1[i][j]);
                if (j == c1 - 1)
                printf("\n");
        }
    }
    printf("\n"); 
    //printing array2 using the same method as the array1
    printf("Array2 Matrix:\n\n");
    for(int i = 0; i<r2; ++i){
        for(int j = 0; j<c2; ++j){
            printf("%d ",array2[i][j]);
            if (j == c2 - 1)
                printf("\n");
        }
    }
    printf("\n");
    printf("Array3 Matrix:\n\n");
    //printing array3 through the same method as array 1 and 2
    for(int i = 0; i<r1; ++i){
        for(int j = 0; j<c2; ++j){
                printf("%2d ",array3[i][j]);
                if (j == c2 - 1)
                printf("\n");
        }
    }
    //else statement makes sure that the arrays don't bug out when multiplied
    }else{
        printf("Error: The %d x %d matrix can't be multiplied by %d x %d matrix.\nReason: the number of columns of the 1st matrix must equal to the number of rows of the 2nd matrix.\n",r1,c1,r2,c2);
        exit(0);
    }
    
}

