#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include "polygon.h"
#include "point.h"

using namespace std;

void Polygon::saveToFile(const char *arc){
    FILE *f = fopen(arc,"w");
    double n_pontos = point.size();
    int i;
    char c, letra = '\n';

    fprintf(f,"# vtk DataFile Version 2.0\n");
    fprintf(f,"Piramide example\n");
    fprintf(f,"ASCII\n");
    fprintf(f,"DATASET POLYDATA\n");
    fprintf(f,"POINTS %lu float\n",point.size());
    fprintf(f,"POLYGONS %.lf %.lf\n",(n_pontos-2), ((n_pontos-2)*3+(n_pontos-2)));
    
    fclose(f);
}

void Polygon::print(){
    for(Point* p:point){ //for each
        p->print();
    }
}

Polygon::Polygon(const char *arc){
    FILE *f = fopen(arc,"r");
    
    if(!f){
        printf("nao abri o arquivo");
        return;
    }
    char buff[256];
    int i=1;

    //para cada linha do arquivo até o final
    while((fgets(buff,256,f))){
        if(strlen(buff)==255){
            printf("Error, the line of a file can not exceed 256 characters\n");
            return;
        }
        try{
            point.push_back(new Point(buff));
        }catch(const char* err){
            printf("erro na linha %i: %s\n",i,err);
        }
        i++;
    }
    fclose(f);
}