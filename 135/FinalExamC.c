#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LSIZ 150
#define RSIZ 100 
#include <ctype.h>

int main(void) 
{
    char line[RSIZ][LSIZ],line2[RSIZ][LSIZ];
	char fname[20];
    FILE *fptr = NULL,*fptr2 = NULL; 
    int i = 0, tot = 0, y=0;
    float sum = 0;
    fptr = fopen("reviews.txt", "r");
    fptr2 = fopen("reviews.txt", "r");
    while(fgets(line[i], LSIZ, fptr)&&fgets(line2[i], LSIZ, fptr2)) 
	{
        line[i][strlen(line[i])] = '\0';
        line2[i][strlen(line2[i])] = '\0';
        i++;
    }
    tot = i;

	printf("\nName    S1 S2 S3 S4 S5 Ave.\n");    

    for(i = 0; i < tot; ++i)
    {
        printf("%-8s",strtok(line2[i],","));
        
        for(int x = 0; x < strlen(line[i]); x++){
            if(isdigit(line[i][x]) > 0){
                printf("%-3d", line[i][x]-'0');
                sum += line[i][x]-'0';
                y++;
            }
            if(x == (strlen(line[i])-1)){
               printf("%*.2f",10+(3*(3-y)),(sum)/y);
               y = 0;
               sum = 0;
               }
            }
        printf("\n");
    }
    printf("\n");
    return 0;
}
