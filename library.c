#include "library.h"

#include <stdio.h>
#include <string.h>
void hello(void) {
    printf("Hello, World!\n");
}

void saveLog(logSystem* logs,char newlog[]){
    FILE *file,*file2,*filestart;
    char ch;
    char nazwa[10],nazwabuf[10], nazwabuf2[10];
    strcpy(nazwa,logs->fileName);
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
        for(int i=logs->maxNumber;i>=0;i--)
        {
            int pre=i-1;
            if(pre==-1){
                pre=logs->maxNumber-1;
            }
            strcpy(nazwabuf,nazwa);
            strcpy(nazwabuf2,nazwa);
            char ii[5];
            char previous[5];
            sprintf(ii,"%d",i);
            sprintf(previous,"%d",pre);

            //file = fopen(nazwa,"r");
            printf("previous:%s ii:%s\n",previous,ii);
            file = fopen(strcat(nazwabuf2,previous),"a+");
            file2=fopen(strcat(nazwabuf,ii),"w");
            printf("%s %s %s\n",nazwa,nazwabuf,nazwabuf2);
            if(file!=NULL) {
                while ((ch = fgetc(file)) != EOF)
                    fputc(ch, file2);
            }
            fclose(file);
            fclose(file2);
        }
        filestart = fopen(nazwa,"w");
        fprintf(filestart, "%s\n", newlog);
        fclose(filestart);
    }
    else {
        file = fopen(nazwa, "a");
        fprintf(file, "%s\n", newlog);
        fclose(file);
    }
    printf("%s\n",nazwa);
}