#include "line.h"

typedef struct 
{
    char com[2];
    float i;
    float x1;
    float y1;
    float x2;
    float y2;
    char cor[30];
}RETA;

void *createline(float i,float x1,float y1,float x2,float y2,char cor[30]){
    RETA *l=(RETA*)malloc(sizeof(RETA));
    strcpy(l->com,"l");
    l->i=i;
    l->x1=x1;
    l->y1=y1;
    l->x2=x2;
    l->y2=y2;
    strcpy(l->cor,cor);
    void *ptrLine;
    ptrLine=l;
    return(ptrLine);
}

int testeline(void *l){
    RETA *ll=(RETA*)malloc(sizeof(RETA));
    ll= (RETA*)l;
    if((strcmp(ll->com,"l"))==0){
        return(1);
    }
    else{
        return(0);
    }
}

void createSVGline(void *dataa, FILE *arquivo){
    float xl1,xl2,yl1,yl2;
    char corl[30];
    xl1=((RETA*)dataa)->x1;
    xl2=((RETA*)dataa)->x2;
    yl1=((RETA*)dataa)->y1;
    yl2=((RETA*)dataa)->y2;
    strcpy(corl,((RETA*)dataa)->cor);

    fprintf(arquivo, "\n\t<line x1=\" %f \" x2=\" %f \" y1=\" %f \" y2=\" %f \" stroke=\" %s \" />",xl1,xl2,yl1,yl2,corl);
}