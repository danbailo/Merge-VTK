#include <iostream>
#include <stdio.h>
#include "polygon.h"

using namespace std;

// Polygon::Polygon(int three, int p1, int p2, int p3){
//     this->three = three;
//     this->p1 = p1;
//     this->p2 = p2;
//     this->p3 = p3;
// }

Polygon::Polygon(const char* str){
    int res=sscanf(str,"%d %d %d %d",&three,&p1,&p2,&p3);
    if(res!=4) throw "menos de 4 pontos numa linha";
}

void Polygon::print_polygon(){
    printf("%d %d %d %d\n",three,p1,p2,p3);
}