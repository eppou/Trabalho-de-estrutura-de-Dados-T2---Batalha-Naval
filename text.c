#include "text.h"

typedef struct
{
    char com;
    double i;
    double x;
    double y;
    char corb[30];
    char corp[30];
    char a[3];
    char texto[100];
}TEXTO;

void *createText(double i, double x,double y,char corb[30],char corp[30],char a[3],char texto[100]){
    TEXTO *tt=(TEXTO*)malloc(sizeof(TEXTO));
    //strcpy(tt->com,"t");
    tt->com = 't';
    tt->i=i;
    tt->x=x;
    tt->y=y;
    strcpy(tt->corb,corb);
    strcpy(tt->corp,corp);
    strcpy(tt->a,a);
    strcpy(tt->texto,texto);

    return(tt);
}

int testetext(void *t){
    TEXTO *tt = (TEXTO*)t;

    if(tt->com=='t'){
        return(1);
    }
    else{
        return(0);
    }

}

void createSVGtext(void *dataa,FILE *arquivo){
    double xt,yt;
    char corbt[30],corpt[30],texto[300];
    xt=((TEXTO*)dataa)->x;
    yt=((TEXTO*)dataa)->y;
    strcpy(corbt,((TEXTO*)dataa)->corb);
    strcpy(corpt,((TEXTO*)dataa)->corp);
    strcpy(texto,((TEXTO*)dataa)->texto);
    fprintf(arquivo, "\n\t<text x=\" %lf \" y=\" %lf \" style=\" font-size: 6px; font-style: normal; font-weight: normal; fill: %s; fill-opacity: 1; stroke: %s; stroke-width: 1px; stroke-opacity: 1; paint-order: stroke fill;\"><tspan x=\"%lf\" y=\"%lf\">%s</tspan></text>",xt,yt,corpt,corbt,xt,yt,texto);
}
