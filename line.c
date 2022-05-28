#include "line.h"

typedef struct 
{
    char com;
    double i;
    double x1;
    double y1;
    double x2;
    double y2;
    char cor[30];
}RETA;

void *createline(double i,double x1,double y1,double x2,double y2,char cor[30]){
    RETA *l=(RETA*)malloc(sizeof(RETA));
    //strcpy(l->com,"l");
    l->com = 'l';
    l->i=i;
    l->x1=x1;
    l->y1=y1;
    l->x2=x2;
    l->y2=y2;
    strcpy(l->cor,cor);

    return(l);
}

int testeline(void *l){
    RETA *ll = (RETA*)l;
    
    if(ll->com=='l'){
        return(1);
    }
    else{
        return(0);
    }
}

void createSVGline(void *dataa, FILE *arquivo){
    double xl1,xl2,yl1,yl2;
    char corl[30];
    xl1=((RETA*)dataa)->x1;
    xl2=((RETA*)dataa)->x2;
    yl1=((RETA*)dataa)->y1;
    yl2=((RETA*)dataa)->y2;
    strcpy(corl,((RETA*)dataa)->cor);

    fprintf(arquivo, "\n\t<line x1=\" %lf \" x2=\" %lf \" y1=\" %lf \" y2=\" %lf \" stroke=\" %s \" />",xl1,xl2,yl1,yl2,corl);
}
