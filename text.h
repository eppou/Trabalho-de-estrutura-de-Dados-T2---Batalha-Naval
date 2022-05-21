#ifndef TEXT_H
#define TEXT_H
#include "bibliotecas.h"

void *createText(float,float,float,char[],char[],char[],char[]);
int testetext(void *);
void createSVGtext(void *,FILE*);

#endif