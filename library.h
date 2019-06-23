#ifndef BUGREPORTS_LIBRARY_H
#define BUGREPORTS_LIBRARY_H

#include <stdio.h>
typedef struct{
    int maxSize;
    int maxNumber;
    char fileName[];
}logSystem;
void saveLog(logSystem*,char[]);
void initWithDefault(logSystem* logs);


#endif //BUGREPORTS_LIBRARY_H