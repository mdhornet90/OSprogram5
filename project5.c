#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct file
{
    unsigned int permissions;
    char name[10];
    int nameSize;
};

int main (void)
{
    void convert(struct file *temp, char tdata[256]);
    FILE *filePtr;
    char fileName[40];
    char data[256];
    char proceed[4];
    int i;
    struct file newFile;
    
    while(1)
    {
        printf("\nEnter the name of the file: ");
        scanf("%39s", fileName);
        
        filePtr = fopen(fileName, "r");
      
        while(1)
        {
            if ( filePtr == NULL )
            {
                printf("Error: file not found.\n");
                break;
            }
            else
            {
                if ( fgets(data, 256, filePtr) == NULL )
                    break;
                else
                {
                    for ( i = 0; i < 256 && data[i] != '\0'; i++ );
                    newFile.nameSize = i - 10;
                    convert(&newFile, data);
                }
            }
        }
        
        printf("\nDo you want to continue? (yes or no): ");
        scanf("%4s", proceed);
        
        while(1)
        {    
            if ( !strcasecmp(proceed, "no") )
                return 0;
            else if ( !strcasecmp(proceed, "yes") )
                break;
            else
            {
                printf("\nPlease enter yes or no: ");
                scanf("%4s", proceed);
            }
        }
    }
}

void convert(struct file *tFile, char tData[256])
{
    struct file *temp = tFile;
    int i, j;
    
    //LOL I DUNNO
    
}
