#include<iostream>
using namespace std;

struct Coordenadas{
    int fila;
    int columna;
    char ficha;
};

//DIMENSION DE LA MATRIZ
const int fila = 6;
const int columna = 7;
const char X = 'X';
const char O = 'O';

//JUGADORES
bool jugador = false;


//Inicializamos la matriz con -
void inicializar_partida(char mapa[][7]){

    cout << "Bienvenido a 4 en raya";
    cout << endl << endl;

    for(int i = 0; i < fila; i++)
        for(int j = 0; j < columna; j++)
            mapa[i][j] = '-';

}
//mostramos el tablero
void ver_tablero(char mapa[][7]){
    //mostramos los numeros de columnas
    for(int i = 0; i < columna; i++)
        cout << " " << i + 1 << " ";

    cout << endl << endl;
    //mostramos el tablero
    for(int i = 0; i < fila; i++){
        for(int j = 0; j < columna; j++)
            cout << " "<< mapa[i][j] << " ";
        cout << endl;
    }
    cout << endl << endl;
}

Coordenadas ingresar_ficha(char mapa[][7]){
    int columna_pivot = 0;
    Coordenadas coord;

    do{
        cout << "Ingresa el numero de columna: ";
        cin >> columna_pivot;
    }while(columna_pivot > 7 || columna_pivot < 0);
    
    //Direccion Directa
    columna_pivot--;

    int fila_pivot = fila;
    while(mapa[fila_pivot][columna_pivot] != '-')
        fila_pivot--;
    
    coord.columna = columna_pivot;
    coord.fila = fila_pivot;
    
    if(jugador){
        mapa[fila_pivot][columna_pivot] = X;
        coord.ficha = X;
    }
    else{
        mapa[fila_pivot][columna_pivot] = O;
        coord.ficha = O;
    } 

    return coord;
}
//Será la condición necesaria para que la partida siga continuando o no
bool partida(char mapa[][7]){
    int columna_vacia = 0;
    for(int i = 0; i < columna; i++){
        if(mapa[0][i] == ' ')
            columna_vacia++;
    }
    return columna_vacia;
}

bool vertical(char mapa[][7], Coordenadas coord){
    //cuenta desde atras
    //no puede ser menor a 0 y no puede ser mayor a 5
    int f = coord.fila;
    int fichas_totales = 1;
    /*
    while(f > 0 && mapa[f-1][coord.columna] == coord.ficha){
        fichas_totales++;
        f--;
    }*/
    f = coord.fila;
    while(f < 5 && mapa[f+1][coord.columna] == coord.ficha){
        fichas_totales++;
        f++;
    }
    return fichas_totales >= 4;
}
bool horizontal(char mapa[][7], Coordenadas coord){
    int c = coord.columna;
    int fichas_totales = 1;
    while(c > 0 && mapa[coord.fila][c-1] == coord.ficha){
        fichas_totales++;
        c--;
    }
    c = coord.columna;
    while(c < 6 && mapa[coord.fila][c+1] == coord.ficha){
        fichas_totales++;
        c++;
    }
    
    return fichas_totales >= 4;
}
bool diagonal(char mapa[][7], Coordenadas coord){
    //PARTE 1
    //DIAGONAL DECRECIENTE
    int c = coord.columna;
    int f = coord.fila;
    int fichas_totales = 1;

    while((c > 0 && f > 0) && mapa[f-1][c-1] == coord.ficha){
        fichas_totales++;
        c--;
        f--;
    }
    c = coord.columna;
    f = coord.fila;

    while((c < 6 && f < 5) && mapa[f+1][c+1] == coord.ficha){
        fichas_totales++;
        c++;
        f++;
    }
    
    if(fichas_totales >= 4) return true;
    
    else{
        //PARTE 2
        //DIAGONAL CRECIENTE
        fichas_totales = 1;
        c = coord.columna;
        f = coord.fila;

        while((c < 6 && f > 0) && mapa[f-1][c+1] == coord.ficha){
            fichas_totales++;
            f--;
            c++;
        }

        c = coord.columna;
        f = coord.fila;
        while((c > 0 && f < 5) && mapa[f+1][c-1] == coord.ficha){
            fichas_totales++;
            f++;
            c--;
        }
        return fichas_totales >= 4;
    }
}

bool ganador(char mapa[][7], Coordenadas coord, int ronda){
    //en la ronda 6 recien es posible que haya un ganador
    if(ronda < 6) return false;
    
    bool h = horizontal(mapa, coord);
    bool v = vertical(mapa, coord);
    bool d = diagonal(mapa, coord);

    return h || v || d;
}
void resultado(char mapa[][7]){
    ver_tablero(mapa);

    cout << "GANADOR: " << jugador ? X : O;
    cout << "!!!!!!";
}

int main(){
    
    char mapa[fila][columna];
    int ronda = 0;
    bool partida = true;

    inicializar_partida(mapa);

    while(partida){
        ver_tablero(mapa);
        Coordenadas coord = ingresar_ficha(mapa);
        ronda++;
        bool hay_ganador = ganador(mapa, coord, ronda);
        hay_ganador ? partida = false : jugador = !jugador;
    }
    
    resultado(mapa);

    return 0;
}