#include<iostream>
using namespace std;

struct Region{
    int id;
    int color;                     //LAS REPRESENTACIONES DE LOS 4 COLORES A USAR SON  ->  Azul = 1, Rojo = 2, Verde = 3, Amarillo = 4
    
}regiones[10], adyacentes[10][10]; //Filas -> cada region, Columnas -> cada adyacencia de cada region

//Prototipos de funciones
void ingresarMapa();

void mostrarMapa(Region [], Region [][10]);
   
void verificarMapa(Region [], Region [][10]);

int main(){

    //se llama a la funcion que ingrese el mapa 
    ingresarMapa();
    //mostrar los datos del mapa ingresado
    //mostrarMapa(regiones, adyacentes);
    //se llama a la funcion que comprueba si el mapa cumple o no con el teorema de four color
    verificarMapa(regiones, adyacentes);
    
    return 0;
}

void ingresarMapa(){
    //ingresar los ID de las regiones
    regiones[0].id = 1; 
    regiones[1].id = 2;
    regiones[2].id = 3;
    regiones[3].id = 4;
    regiones[4].id = 5;
    regiones[5].id = 6;
    regiones[6].id = 7;
    regiones[7].id = 8;
    regiones[8].id = 9;
    regiones[9].id = 10;

    //ingresar los colores de las regiones
    regiones[0].color = 1; 
    regiones[1].color = 3;
    regiones[2].color = 1;
    regiones[3].color = 4; 
    regiones[4].color = 2;
    regiones[5].color = 3;
    regiones[6].color = 4;
    regiones[7].color = 1;
    regiones[8].color = 3;
    regiones[9].color = 2;

    //ingresar las adyacencias de las regiones
    //adyacencias de la region 1
    adyacentes[0][0] = regiones[1];
    adyacentes[0][1] = regiones[3];
    adyacentes[0][2] = regiones[4];
    //adyacencias de la region 2
    adyacentes[1][0] = regiones[0];
    adyacentes[1][1] = regiones[2];
    adyacentes[1][2] = regiones[4];
    //adyacencias de la region 3
    adyacentes[2][0] = regiones[1];
    adyacentes[2][0] = regiones[4];
    adyacentes[2][1] = regiones[5];
    adyacentes[2][2] = regiones[6];
    //adyacencias de la region 4
    adyacentes[3][0] = regiones[0];
    adyacentes[3][1] = regiones[4];
    adyacentes[3][2] = regiones[7];
    //adyacencias de la region 5
    adyacentes[4][0] = regiones[0];
    adyacentes[4][1] = regiones[1];
    adyacentes[4][2] = regiones[2];
    adyacentes[4][3] = regiones[3];
    adyacentes[4][4] = regiones[5];
    adyacentes[4][5] = regiones[7];
    //adyacencias de la region 6
    adyacentes[5][0] = regiones[2];
    adyacentes[5][1] = regiones[4];
    adyacentes[5][2] = regiones[6];
    adyacentes[5][3] = regiones[7];
    //adyacencias de la region 7
    adyacentes[6][0] = regiones[2];
    adyacentes[6][1] = regiones[5];
    adyacentes[6][2] = regiones[7];
    adyacentes[6][3] = regiones[9];
    //adyacencias de la region 8
    adyacentes[7][0] = regiones[3];
    adyacentes[7][1] = regiones[4];
    adyacentes[7][2] = regiones[5];
    adyacentes[7][3] = regiones[6];
    adyacentes[7][4] = regiones[8];
    adyacentes[7][5] = regiones[9];
    //adyacencias de la region 9
    adyacentes[8][0] = regiones[7];
    adyacentes[8][1] = regiones[9];
    //adyacencias de la region 10
    adyacentes[9][0] = regiones[6];
    adyacentes[9][1] = regiones[7];
    adyacentes[9][2] = regiones[8];
}

void mostrarMapa(Region regiones[], Region adyacentes[][10]){
    for(int i=0; i<10; i++){
        cout<<"\n\nDatos de la region "<<regiones[i].id<<endl;
        cout<<"Color: "<<regiones[i].color<<endl;
        cout<<"Adyacencias: ";
        for(int j=0; j<10; j++){
            if(adyacentes[i][j].id != 0){
                cout<<"Region: "<<adyacentes[i][j].id<<" ";
            }
        }
    }
}

void verificarMapa(Region regiones[], Region adyacentes[][10]){
    bool cumple = true;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(regiones[i].color == adyacentes[i][j].color){        //se verifica que los colores de las regiones adyacentes sean distintas de cada region
                cout<<"\nLa region "<<regiones[i].id<<" tiene adyacencia con la region "<<adyacentes[i][j].id<<" y ambas comparten el mismo color"<<endl;
                cumple = false;
                
            }
        }
    }
    if(cumple){
        cout<<"\n\nEl mapa si cumple con el teorema"<<endl;
    }
    else{
        cout<<"\n\nEl mapa no cumple con el teorema"<<endl;
    }
}