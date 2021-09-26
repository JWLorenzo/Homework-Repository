//Jacob Lorenzo
//Asks the user for information about weekend profits for a bakery
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//costarray is the array of costs
int costArray[3] = {3,4,1};
//amountarray is the array of amounts purchased
int amountArray[2][3];
//buffer is used to input values and is used for verification
char buffer[] = "";
//this function contains a chain of if statements to determine what to print next
void dayAmnt(int i,int j){
    if (i == 0  && j ==0 ){
        printf("Number of Bagel sales on Saturday: ");
            }
    if (i == 0  && j == 1 ){
        printf("Number of Bagel sales on Sunday: ");
            }
    if (i == 1 && j == 0){
        printf("Number of Flatbread sales on Saturday: ");
            }
    if (i == 1 && j == 1){
        printf("Number of Flatbread sales on Sunday: ");
            }
    if (i == 2 && j == 0){
        printf("Number of Muffin sales on Saturday: ");
            }
    if (i == 2 && j == 1){
        printf("Number of Muffin sales on Sunday: ");
            }
}
int main(){
    for(int j = 0; j<2; ++j){
        for(int i = 0; i<3; ++i){
            //input verify is used to count if the string consists entirely of numbers via counting up with a for loop
            int inputVerify = 0;
            dayAmnt(i,j);
            //scans for a string because using a double creates an infinite loop
            scanf(" %s",buffer);
            //the for loop that goes through every character in the string
            for (int k = 0; k <= strlen(buffer);k++){
                if (buffer[k] >= '0' && buffer[k] <= '9'){
                    inputVerify++;
                }
            }
            //adds it to the matrix if the verify is equivalent to the string length
            if (inputVerify == strlen(buffer)){
                amountArray[i][j] = atoi(buffer);
            }else{
                //this else statement brings it back to the prior state to repeat until a valid input is entered
                printf("\nProgram output:\n");
                printf("\nError: Sales figures must be numbers.\nPlease try again.\n\n");
                i-=1;
            }
        }
    }
    //uses a for loop to print out cost array
    printf("\nProgram output:\n\n");
    for(int i = 0; i<3; ++i){
       printf(" %1d",costArray[i]); 
    }
    
    printf("\n\n");
    //print the array with the entered values
    for(int i = 0; i<3; ++i){
        for(int j = 0; j<2; ++j){
            printf(" %2d",amountArray[i][j]);
            if (j == 2 - 1)
                printf("\n");
            }
    }
    printf("\n");
    //calculates the totals for saturday and sunday
    int satTotal = (amountArray[0][0])*costArray[0]+
    (amountArray[1][0])*costArray[1]+(amountArray[2][0])*costArray[2];
    
    int sunTotal = (amountArray[0][1])*costArray[0]+
    (amountArray[1][1])*costArray[1]+(amountArray[2][1])*costArray[2];
    
    //prints out final product
    printf("= %d %d\n\n",satTotal,sunTotal);
    printf("Total sales on Saturday: $%d\n",satTotal);
    printf("Total sales on Sunday: $%d\n",sunTotal);
    printf("Total sales on weekend: $%d\n",satTotal+sunTotal);
    
    return 0;
}
