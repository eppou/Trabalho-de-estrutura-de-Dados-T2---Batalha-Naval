#ifndef LINE_H
#define LINE_H
#include "bibliotecas.h"

void *createline(float,float,float,float,float,char[]);
int testeline(void*);
void createSVGline(void *,FILE*);

#endif