#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
    FILE *filePtr;
    char fileName[40];
    unsigned int  data;
    
    printf("Enter the name of the file: ");
    scanf("%39s", &fileName);
    
    filePtr = fopen(fileName, "r");
    
    while ( 1 )
    {
        if ( fscanf(filePtr, "%o", &data) == EOF )
            break;
        else
            printf("%o\n", data);
    }        
    return 0;
}
