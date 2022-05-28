#include "circle.h"

typedef struct circle
{
    char com;
    double i;
    double x;
    double y;
    double r;
    char corb[30];
    char corp[30];
}CIRCULO;

void *createCircle(double i,double x,double y, double r,char corb[30], char corp[30]){
    CIRCULO *cc= (CIRCULO*)malloc(sizeof(CIRCULO));
    //strcpy(cc->com,"c");
    cc->com = 'c';
    cc->i=i;
    cc->x=x;
    cc->y=y;
    cc->r=r;
    strcpy(cc->corb,corb);
    strcpy(cc->corp,corp);
  
    return(cc);
}

int testaCirculo(void *c){
  CIRCULO *cc= (CIRCULO*)c;
 
  if(cc->com=='c'){
    return (1);
  }
  else{
    return(0);
  }
}

void createSVGcircle(void *dataa, FILE *arquivo){
  CIRCULO *cc= (CIRCULO*)malloc(sizeof(CIRCULO));
  double xc,yc,rc;
  char corbc[30],corpc[30];
  xc=((CIRCULO*)dataa)->x;
  yc=((CIRCULO*)dataa)->y;
  rc=((CIRCULO*)dataa)->r;
  strcpy(corbc,((CIRCULO*)dataa)->corb);
  strcpy(corpc,((CIRCULO*)dataa)->corp);
  fprintf(arquivo, "\n\t<circle cx=\"%lf\" cy=\" %lf \" r=\" %lf \" stroke=\" %s \" stroke-width=\" 2 \" fill=\" %s \" opacity=\" 1 \"/>",xc,yc,rc,corbc,corpc);
        
}
