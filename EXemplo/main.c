//random access file demo
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define FNAME "random.dat"
#define FILENAME "TABELA_IRS_2020_1TITULAR.csv"

// test data struct

struct t_Record {
    int randnum;
    char word[16];
}
Record;

typedef struct {
    char col1[50], col2[50], col3[50], col4[50];
} csv;

void readcsv(csv *values){
    FILE *fp=fopen(FILENAME,"r");
    
    if(!fp){
        printf("Ocorreu um erro\n");
        exit(EXIT_FAILURE);
    }
    char buff[1024];
    int row_count=0;
    int field_count=0;
    
   
    int i=0;
    
    while(fgets(buff,1024,fp)){
        field_count=0;
        row_count++;
        
        char *field=strtok(buff,";");
        while(field){
            if(field_count == 0) strcpy(values[i].col1,field);
             if(field_count == 1) strcpy(values[i].col2,field);
             if(field_count == 2) strcpy(values[i].col3,field);
             if(field_count == 3) strcpy(values[i].col4,field);
            
            field=strtok(NULL,";");
            field_count++;
        }
        i++;
    }
    fclose(fp);
    printValues(values);
}

void printValues(csv *values){

    for(int i=0;i<999;i++){
        printf("COL1 %s,COL2 %s,COL3 %s,COL4 %s,\n",values[i].col1,values[i].col2,values[i].col3,values[i].col4);
    }
}



///////////////////////////////////////////////////////
// Random Access File Handlers
//

// open or create the file

FILE *FileOpen(char* Filename) {
    FILE* pFile;
    pFile = fopen(Filename, "rb+");
    if (!pFile)
        pFile = fopen(Filename, "wb+");
    return pFile;
}


// Write a record to the file

int WriteRecord(FILE *File, int RecNum) {
    if (fseek(File, RecNum * sizeof (Record), SEEK_SET) == 0)
        if (fwrite(&Record, sizeof (Record), 1, File))
            return 1;
    return 0;
}


// read a record from the file

int ReadRecord(FILE *File, int RecNum) {
    if (fseek(File, RecNum * sizeof (Record), SEEK_SET) == 0)
        if (fread(&Record, sizeof (Record), 1, File))
            return 1;
    return 0;
}



////////////////////////////////////////////////////////
// this is for demonstration purposes only
// you would not do this in a real program

void InitFile(FILE* File) {
    int x, y;
    memset(&Record, sizeof (Record), 0);
    for (x = 0; x < 1000; x++) {
        Record.randnum = rand();
        for (y = 0; y < ((Record.randnum % 15) + 1); y++)
            Record.word[y] = (rand() % 26) + 'a';
        Record.word[y] = 0;
        if (!WriteRecord(File, x))
            printf("Oh drat!");
    }
}



//////////////////////////////////////////////////////////
// program mains
//

int main(void) { /*FILE *File;
    int Quit = 0;
    int Rec = 0; // record number

    srand(time(NULL));

    File = FileOpen(FNAME); 
    if (!File)
      { printf("Curses foiled again!\n\n");
        exit(-1); }

    // write out 1000 test records  
    printf("Create a new file? (y/n)  ");
    if ( toupper( getchar() ) == 'Y')
      InitFile(File);
  
    // lets peek
    do
      { printf("Enter a record number (0 - 999) to load : ");
        if (! scanf("%d",&Rec) )
          Quit = 1;  // enter any letter to quit
        else 
          { // read and display the record 
           if (! ReadRecord(File,Rec) ) 
              printf("Could not read record %d\n",Rec);
            else
              { printf("-----\n");
                printf("Record Number : %d\n",Rec);
                printf("Number Value  : %d\n",Record.randnum);
                printf("Record Name   : %s\n",Record.word);
                printf("-----\n"); 
                getchar();
                printf("Do you want to rename this record (y/n)? ");
                if ( toupper( getchar() ) == 'Y')
                  { printf("Enter a new name : ");
                    if ( scanf("%s",Record.word) )
                      WriteRecord(File,Rec);  } } }
      } while (! Quit); 


    fclose(File);
     * */
     csv values[999];
  readcsv(values);
  
  
    return 0;
}