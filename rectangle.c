#include "rectangle.h"

typedef struct 
{
    char com[2];
    float i;
    float x;
    float y;
    float w;
    float h;
    char corb[30];
    char corp[30];
}RETANGULO;

void *createrectangle(float i,float x,float y,float w,float h, char corb[30],char corp[30]){
    RETANGULO *R=(RETANGULO*)malloc(sizeof(RETANGULO));
    strcpy(R->com,"r");
    R->i=i;
    R->x=x;
    R->y=y;
    R->w=w;
    R->h=h;
    strcpy(R->corb,corb);
    strcpy(R->corp,corp);
    void *ptrRectangle;
    ptrRectangle = R;
    return(ptrRectangle);
}

int  testeRetangulo (void *r){
    RETANGULO *rr=(RETANGULO*)malloc(sizeof(RETANGULO));
    rr=(RETANGULO*)r;
    if(strcmp(rr->com,"r")==0){
        return(1);
    }
    else{
        return(0);
    }
}

void createSVGrectangle(void *dataa, FILE *arquivo){
        float xr,yr,wr,hr;
        char corbr[30],corpr[30];
        xr=((RETANGULO*)dataa)->x;
        yr=((RETANGULO*)dataa)->y;
        wr=((RETANGULO*)dataa)->w;
        hr=((RETANGULO*)dataa)->h;
        strcpy(corbr,((RETANGULO*)dataa)->corb);
        strcpy(corpr,((RETANGULO*)dataa)->corp);
        fprintf(arquivo, "\n\t<rect x=\" %f \" y=\" %f \" width=\" %f \" height=\" %f \" stroke=\" %s \" stroke-width=\" 1px \" fill=\" %s \" opacity=\" 1 \"/>",xr,yr,wr,hr,corbr,corpr);

}