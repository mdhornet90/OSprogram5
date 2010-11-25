#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct file
{
    unsigned int permissions[3];
    unsigned int name[28];
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

        filePtr = fopen(fileName, "rb");

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
                    newFile.nameSize = i - 9;
                    convert(&newFile, data);

                    for ( i = 0; newFile.name[i] != '\0'; i++ )
                        printf("%c", newFile.name[i]);
                    printf(" ");
                    for ( i = 0; i < 3; i++ )
                        printf("%o", newFile.permissions[i]);
                    printf("\n");
                }
            }
        }

        if (filePtr != NULL)
            fclose(filePtr);
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
    int i, j, k;

    for ( i = 0, j = 0; i < 9; i += 3, j++)
        temp->permissions[j] = ((tData[i] & 1) << 2) | ((tData[i + 1] & 1) << 1) | ((tData[i + 2] & 1) << 0);

    for ( i = 9, j = 0; i <= temp->nameSize; i += 9, j++)
        for ( k = 8; k >= 0; k-- )
            temp->name[j] = ((tData[i] & 1) << 8) | ((tData[i + 1] & 1) << 7) | ((tData[i + 2] & 1) << 6) | ((tData[i + 3] & 1) << 5) |
                        ((tData[i + 4] & 1) << 4) | ((tData[i + 5] & 1) << 3) | ((tData[i + 6] & 1) << 2) | ((tData[i + 7] & 1) << 1) |
                        ((tData[i + 8] & 1) << 0);

    temp->name[(temp->nameSize / 9)] = '\0';
}
