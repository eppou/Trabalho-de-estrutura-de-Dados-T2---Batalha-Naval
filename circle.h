#ifndef CIRCLE_H
#define CIRCLE_H
#include "bibliotecas.h"

void *createCircle(float,float,float,float,char[],char[]);
int testaCirculo(void *);
void createSVGcircle(void*,FILE *);

#endif