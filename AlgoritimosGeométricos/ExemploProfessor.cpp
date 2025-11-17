/*
Aplicação de Algoritimos geométricos no calculo das coordenadas de um triangulo
Calculo da area do triangulo de acordo com as coordenadas dos seus vertices
*/
#include <iostream>
using namespace std; 

struct ponto{
    int x, y;
};

//Formula da area do triangulo a partir das coordenadas dos seus vertices
float areaTriangulo(ponto a, ponto b, ponto c){
    return (a.x*b.y - a.y*b.x + a.y*c.x - a.x*c.y + b.x*c.y - b.y*c.x)/2;
}

int main(){
    ponto p1, p2, p3;
    
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;
    
    cout << areaTriangulo(p1, p2, p3) << endl;
    
    return 0;
}