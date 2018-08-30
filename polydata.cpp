#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "polydata.h"
#include "point.h"
#include "polygon.h"

using namespace std;

void Polydata::saveToFile(const char *arc){
    FILE *f = fopen(arc,"w");
    double n_pontos = point.size();

    fprintf(f,"# vtk DataFile Version 2.0\n");
    fprintf(f,"Piramide example\n");
    fprintf(f,"ASCII\n");
    fprintf(f,"DATASET POLYDATA\n");
    fprintf(f,"POINTS %lu float\n",point.size());
    for(Point* p:point){ //for each
        fprintf(f,"%e %e %e\n",p->x,p->y,p->z);
    }
    fprintf(f,"\nPOLYGONS %.lf %.lf\n",(n_pontos-2)*2, (((n_pontos-2)*3+(n_pontos-2)))*2);
    for(Polygon* p:polygon){ //for each
        fprintf(f,"%i %i %i %i\n",p->three,p->p1,p->p2,p->p3);
    }
    fclose(f);
}

void Polydata::print_point(){
    for(Point* p:point){ //for each
        p->print_point();
    }
}
int Polydata::size(){
    return point.size();
}
void Polydata::print_polygon(){
    for(Polygon* p:polygon){ //for each
        p->print_polygon();
    }
}

void Polydata::polydata_point(const char *arc){
    FILE *arq = fopen(arc,"r");
    
    if(!arq){
        printf("nao abri o arquivo");
        return;
    }
    char str[256];
    
    int i=1;
    int n;
    //para cada linha do arquivo até o final
    while((fgets(str,256,arq))){
        char* buff=(char*)&str;
        if(strlen(str)==255){
            printf("Error, the line of a file can not exceed 256 characters\n");
            return;
        }
        n=0;
        try{
            int res;
            while(1){
                double x,y,z;
                buff+=n;
                res=sscanf(buff,"%lf %lf %lf%n",&x,&y,&z,&n);
                if(res!=3)break;
                point.push_back(new Point(x,y,z));
            }

        }catch(const char* err){
            printf("erro na linha %i: %s\n",i,err);
        }
        i++;
    }
    fclose(arq);
}

void Polydata::polydata_polygon(const char *arc){
    FILE *arq = fopen(arc,"r");
    
    if(!arq){
        printf("nao abri o arquivo");
        return;
    }
    char buff[256];
    int i=1;

    //para cada linha do arquivo até o final
    while((fgets(buff,256,arq))){
        if(strlen(buff)==255){
            printf("Error, the line of a file can not exceed 256 characters\n");
            return;
        }
        try{
            polygon.push_back(new Polygon(buff));
        }catch(const char* err){
            printf("erro na linha %i: %s\n",i,err);
        }
        i++;
    }
    fclose(arq);
}