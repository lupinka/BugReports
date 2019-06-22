#ifndef BUGREPORTS_LIBRARY_H
#define BUGREPORTS_LIBRARY_H

#include <stdio.h>
typedef struct{
    int maxSize;
    int maxNumber;
    char fileName[];
}logSystem;
void hello(void);
void saveLog(logSystem*,char[]);


#endif //BUGREPORTS_LIBRARY_H