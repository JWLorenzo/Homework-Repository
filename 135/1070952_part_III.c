

#include <stdio.h>
float arr[50], buffer;
int main()
{
    for(int i = 0; i < sizeof(arr); i++){
        printf("Enter a gross salary: ");
        scanf(" %f",&buffer);
        if(buffer >= 4000.00){
            arr[i] = ((buffer*(1-.03)) -100)*(1-.35);
        }else{
            printf("The value was less than 4000.00\n");
            i--;
        }
    }
    for (int i = 0; i<50; i++){
        printf("%.2f, ",arr[i]);
    }
}
