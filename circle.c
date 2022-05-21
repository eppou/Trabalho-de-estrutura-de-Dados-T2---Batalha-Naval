#include "circle.h"

  typedef struct 
{
    char com[2];
    float i;
    float x;
    float y;
    float r;
    char corb[30];
    char corp[30];
}CIRCULO;

void *createCircle(float i,float x,float y, float r,char corb[30], char corp[30]){
    CIRCULO *cc= (CIRCULO*)malloc(sizeof(CIRCULO));
    strcpy(cc->com,"c");
    cc->i=i;
    cc->x=x;
    cc->y=y;
    cc->r=r;
    strcpy(cc->corb,corb);
    strcpy(cc->corp,corp);
    void *ptrCircle;
    ptrCircle=cc;
    return(ptrCircle);
}

int testaCirculo(void *c){
  CIRCULO *cc= (CIRCULO*)malloc(sizeof(CIRCULO));
  cc= (CIRCULO*)c;
  if(strcmp (cc,"c")==0){
    return (1);
  }
  else{
    return(0);
  }
}

void createSVGcircle(void *dataa, FILE *arquivo){
  CIRCULO *cc= (CIRCULO*)malloc(sizeof(CIRCULO));
  float xc,yc,rc;
  char corbc[30],corpc[30];
  xc=((CIRCULO*)dataa)->x;
  yc=((CIRCULO*)dataa)->y;
  rc=((CIRCULO*)dataa)->r;
  strcpy(corbc,((CIRCULO*)dataa)->corb);
  strcpy(corpc,((CIRCULO*)dataa)->corp);
  fprintf(arquivo, "\n\t<circle cx=\"%f\" cy=\" %f \" r=\" %f \" stroke=\" %s \" stroke-width=\" 2 \" fill=\" %s \" opacity=\" 1 \"/>",xc,yc,rc,corbc,corpc);
        
}