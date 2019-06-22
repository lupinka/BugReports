#include "library.h"

#include <stdio.h>
#include <string.h>
void hello(void) {
    printf("Hello, World!\n");
}

void saveLog(logSystem* logs,char newlog[]){
    FILE *file,*file2,*file3;
    char ch;
    char nazwa[5],nazwabuf[5], nazwabuf2[5];
    strcpy(nazwa,logs->fileName);
    strcpy(nazwabuf,logs->fileName);
    strcpy(nazwabuf2,logs->fileName);
    int fileSize;
    file = fopen(nazwa,"r");
    if(file==NULL) fileSize=0;
    else {
        fseek(file,0L,SEEK_END);
        fileSize=ftell(file);
    }
    printf("%d\n",fileSize);
    fclose(file);

    if(fileSize+strlen(newlog)>16/*1024*/){
        for(int i=logs->maxSize;i>=0;i++)
        {
            char ii=i+'0';
            char previous=i-1+'0';
            //file = fopen(nazwa,"r");
            file = fopen(strcat(nazwabuf2,&previous),"r");
            file2=fopen(strcat(nazwabuf,&ii),"w");
            while ((ch = fgetc(file)) != EOF)
                fputc(ch, file2);
            fclose(file);
            fclose(file2);
        }
        /*file = fopen(nazwa,"r");
        file2=fopen(strcat(nazwabuf,"1"),"w");
        while ((ch = fgetc(file)) != EOF)
            fputc(ch, file2);
        fclose(file);
        fclose(file2);

        file = fopen(nazwa, "w");
        fprintf(file, "%s\n", newlog);
        fclose(file);*/
    }
    else {
        file = fopen(nazwa, "a");
        fprintf(file, "%s\n", newlog);
        fclose(file);
    }
    printf("%s\n",nazwa);
}