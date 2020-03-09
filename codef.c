#include<stdio.h>
#include<stdlib.h>
#define SIZE 10000
#define TABSPACE 4
void printFile(FILE *fptr)
{
    char ch;

    while((ch = fgetc(fptr)) != EOF)
	    if(ch=='\t') {       //To replace tab with 4 spaces
		    for(int i=0;i<TABSPACE;i++)
		    putchar(' ');
	    }
    	
	    else
        	putchar(ch);
}

int isEmpty(const char *str)
{
    char ch;

    do
    {
        ch = *(str++);

        // Check non whitespace character
        if(ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r' && ch != '\0')
            return 0;

    } while (ch != '\0');

    return 1;
}


void removeEmptyLines(FILE *File1, FILE *File2)
{
    char line[SIZE];

    while ((fgets(line,SIZE,File1)) != NULL)
    {
        /* If current line is not empty then write to temporary file */
        if(!isEmpty(line))
            fputs(line,File2);
    }
}



int main()
{
	FILE * fptr;
	FILE * fptr2;
	  char filename[100], c; 
	  int char_count=0,line_count=0;
  
    printf("Enter the filename to indend \n"); 
    scanf("%s", filename);
   printf("\n"); 
   
    fptr = fopen(filename, "r"); 
    fptr2=fopen("edited.c","w");
    if (fptr == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
  
    // Read contents from file 
    //c = fgetc(fptr); 
    
    printf("Before indendation: \n\n");
    while (c != EOF) 
    { 
	char_count++;
	if (c == '\n') // Increment count if this character is newline
            line_count = line_count + 1;
        printf ("%c", c); 
        c = fgetc(fptr); 
    }
	
    // Move src file pointer to beginning
    rewind(fptr);

    // remove empty lines
    removeEmptyLines(fptr, fptr2);

    fclose(fptr);
    fclose(fptr2);
    //printf("No of characters in file: %d\n",char_count);
    //printf("No of lines in file: %d\n",line_count);

	 remove(filename);
    rename("edited.c", filename);

    printf("\n\n\nFile contents after editing.\n\n");

    // Open source file and print its contents
    fptr = fopen(filename, "r");
    printFile(fptr);
    fclose(fptr);


    return 0;
}
