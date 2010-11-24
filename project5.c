#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
    FILE *filePtr;
    char fileName[40];
    char data[256];
    
    printf("Enter the name of the file: ");
    scanf("%39s", fileName);
    
    filePtr = fopen(fileName, "r");
    
    while ( 1 )
    {
        if ( fgets(data, 256, filePtr) == NULL )
            break;
        else
            printf("%o\n", data);
    }        
    return 0;
}
