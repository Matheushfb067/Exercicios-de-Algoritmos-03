/*
Calcule as coordenadas baricêntricas do ponto P em relaçãos aos
pontos p1, p2 e p3:
p = (3,2), p1 = (1,2), p2 = (4,4) e p3=(4,1)
*/

#include <iostream>
using namespace std; 

struct ponto{
    int x, y;
};

float areaTriangulo(ponto a, ponto b, ponto c){
    return (a.x*b.y - a.y*b.x + a.y*c.x - a.x*c.y + b.x*c.y - b.y*c.x)/2;
}

int main(){
    ponto p1, p2, p3, p;
    float ref, l1, l2, l3;
    
    cin >> p.x >> p.y;
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;
    
   ref = areaTriangulo(p1, p2, p3);
   l1 = areaTriangulo(p, p2, p3)/ref;
   l2 = areaTriangulo(p1, p, p3)/ref;
   l3 = areaTriangulo(p1, p2, p)/ref;
   
   cout << l1 << " " <<  l2 << " " << l3 << endl;
    
    return 0;
}