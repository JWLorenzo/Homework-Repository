#include<stdio.h>
#include<stdlib.h>
int Calculate(int e1,int e2){
    return abs(e2 - e1);
}

void PrintArr(int Arr[][3],int p1,int p2){
    for(int i = 0; i < p1; i++){
        for (int k = 0; k < p2; k++){
            printf("%d ",Arr[i][k]);
            
        }
        printf("\n");
    }
}

int main(){
int InitArray[3][3] = {{2,5,12},{9,10,8},{14,16,4}};
int FinalArray[3][3];
for(int i = 0; i < 3; i++){
        for (int k = 0; k < 3; k++){
            FinalArray[i][k] = Calculate(InitArray[i][k],InitArray[1][1]);
        }
    }
PrintArr(FinalArray,3,3);
return 0;
}

