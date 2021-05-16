#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define str1 "Sapere aude!"
#define str2 "Hello World!"


FILE* openFile(char* name_File);
int det_length_File(FILE* fp);
char* getString(int length_File, FILE* fp);
int getNumber(char* str, char* str2_p);
void changeStr(char* str, char* str1_p, int number);
void changeFile(char* name_File, char* str, int length_File);


int main(int argc, char * argv[]){

    FILE* fp = openFile(argv[1]);
    int length_File = det_length_File(fp);
    char* str = getString(length_File, fp);
    
   
    //char str1[] = "Sapere aude!";
    char* str1_p = str1;

    //char str2[] = "Hello World!";
    char* str2_p = str2;

    int number = getNumber(str, str2_p);

    int i = 0;
    for ( i = 0; i < length_File; i++) {
        putchar(str[i]);
    }
    printf("\n");


    changeStr(str, str1_p, number);

    changeFile(argv[1], str, length_File);

    for ( i = 0; i < length_File; i++) {
        putchar(str[i]);
    }

    free(str);
    return 0;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------
FILE* openFile(char* name_File){
    FILE* fp = fopen(name_File, "r+" );

    if( fp == NULL){
        printf("Cannot open file.\n");
        fclose(fp);
        exit(1);

    }else{
        return fp;
    }
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
int det_length_File(FILE* fp){
    fseek(fp, 0L, 2);
    int length_File = ftell(fp);
    rewind(fp);
    return length_File;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
char* getString(int length_File, FILE* fp){
    char* str = (char*)malloc(length_File);
    int i;
    for(i = 0; i < length_File; i++){
        str[i] = fgetc(fp); 
    }
    fclose(fp);
    return str;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
int getNumber(char* str, char* str2_p){
    char* istr;
    istr = strstr(str, str2_p);

    if( istr == NULL){
        printf("String not found\n");
        return 0;
    }else{
        int number = (int)(istr - str);
        return number;
    }
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
void changeStr(char* str, char* str1_p, int number){
    int i;
    for(i = 0; i < 12; i++){
        str[number + i] = str1_p[i];
    }
    return;
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
void changeFile(char* name_File, char* str, int length_File){
    FILE* fp = fopen(name_File, "w");
    int i, j = 0;
    for(i = 0; i < length_File; i++){
        if(str[i] == '\n'){
            j++;
        }
    }
    length_File = length_File - j;

    for(i = 0; i < length_File; i++){
    fputc(str[i], fp);
    }
    fclose(fp);
    return;
}
