#include "rectangle.h"

typedef struct 
{
    char com;
    double i;
    double x;
    double y;
    double w;
    double h;
    char corb[30];
    char corp[30];
}RETANGULO;

void *createrectangle(double i,double x,double y,double w,double h, char corb[30],char corp[30]){
    RETANGULO *R=(RETANGULO*)malloc(sizeof(RETANGULO));
    //strcpy(R->com,"r");
    R->com = 'r';
    R->i=i;
    R->x=x;
    R->y=y;
    R->w=w;
    R->h=h;
    strcpy(R->corb,corb);
    strcpy(R->corp,corp);
    return(R);
}

int  testeRetangulo (void *r){
    RETANGULO *rr= (RETANGULO*)r;
   // rr=(RETANGULO*)r;
    if(rr->com=='r'){
        return(1);
    }
    else{
        return(0);
    }
}

void createSVGrectangle(void *dataa, FILE *arquivo){
        double xr,yr,wr,hr;
        char corbr[30],corpr[30];
        xr=((RETANGULO*)dataa)->x;
        yr=((RETANGULO*)dataa)->y;
        wr=((RETANGULO*)dataa)->w;
        hr=((RETANGULO*)dataa)->h;
        strcpy(corbr,((RETANGULO*)dataa)->corb);
        strcpy(corpr,((RETANGULO*)dataa)->corp);
        fprintf(arquivo, "\n\t<rect x=\" %lf \" y=\" %lf \" width=\" %lf \" height=\" %lf \" stroke=\" %s \" stroke-width=\" 1px \" fill=\" %s \" opacity=\" 1 \"/>",xr,yr,wr,hr,corbr,corpr);

}
