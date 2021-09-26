#include <stdio.h> 

int main() 

{ 

    FILE *fptr1, *fptr2, *fptr3, *fptr4, *fptr5, *fptr6, *fptr7, *fptr8, *fptr9, *fptr10, *fptr11; 

    char c;

    fptr1 = fopen("mytext.txt", "r");

    fptr2 = fopen("mytext_0.txt", "w"); 

    fptr3 = fopen("mytext_1.txt", "w");

    fptr4 = fopen("mytext_2.txt", "w");

    fptr5 = fopen("mytext_3.txt", "w");

    fptr6 = fopen("mytext_4.txt", "w");

    fptr7 = fopen("mytext_5.txt", "w");

    fptr8 = fopen("mytext_6.txt", "w");

    fptr9 = fopen("mytext_7.txt", "w");

    fptr10 = fopen("mytext_8.txt", "w");

    fptr11= fopen("mytext_9.txt", "w");

    c = fgetc(fptr1); 

    while (c != EOF) 

    { 

        fputc(c, fptr2); 

        c = fgetc(fptr1);

    }

    fclose(fptr1);

    fptr1 = fopen("mytext.txt", "r");

    c = fgetc(fptr1);

    while (c != EOF)

    { 

        fputc(c, fptr3); 

        c = fgetc(fptr1);

    }

    fclose(fptr1);

    fptr1 = fopen("mytext.txt", "r");

    c = fgetc(fptr1);

    while (c != EOF)

    {

        fputc(c, fptr4);

        c = fgetc(fptr1);

    }

    fclose(fptr1);

    fptr1 = fopen("mytext.txt", "r");

    c = fgetc(fptr1);

    while (c != EOF)

    {

        fputc(c, fptr5);

        c = fgetc(fptr1);

    }

    fclose(fptr1);

    fptr1 = fopen("mytext.txt", "r");

    c = fgetc(fptr1);

    while (c != EOF)

    {

        fputc(c, fptr6);

        c = fgetc(fptr1);

    }

    fclose(fptr1);

    fptr1 = fopen("mytext.txt", "r");

    c = fgetc(fptr1);

    while (c != EOF)

    {

        fputc(c, fptr7);

        c = fgetc(fptr1);

    }

    fclose(fptr1);

    fptr1 = fopen("mytext.txt", "r");

    c = fgetc(fptr1);

    while (c != EOF)

    {

        fputc(c, fptr8);

        c = fgetc(fptr1);

    }

    fclose(fptr1);

    fptr1 = fopen("mytext.txt", "r");

    c = fgetc(fptr1);

    while (c != EOF)

    {

        fputc(c, fptr9);

        c = fgetc(fptr1);

    }

    fclose(fptr1);

    fptr1 = fopen("mytext.txt", "r");

    c = fgetc(fptr1);

    while (c != EOF)

    {

        fputc(c, fptr10);

        c = fgetc(fptr1);

    }

    fclose(fptr1);

    fptr1 = fopen("mytext.txt", "r");

    c = fgetc(fptr1);

    while (c != EOF)

    {

        fputc(c, fptr11);

        c = fgetc(fptr1);

    }

    fclose(fptr1); 

    fclose(fptr2);

    fclose(fptr3); 

    fclose(fptr4);

    fclose(fptr5);

    fclose(fptr6);

    fclose(fptr7); 

    fclose(fptr8);

    fclose(fptr9);

    fclose(fptr10);

    fclose(fptr11);

    return 0; 

}