#include <iostream>

using namespace std;

void iniciarMatriz(int [][9]);
void mostrarMatriz(int [][9]);
void llenarMatriz(int , int , int , int [][9]);
void revisarFila(int, int, int [][9]);
void revisarColumna(int, int, int [][9]);
void revisarSubMatriz(int [][3], int, int [][9]);

int main()
{
    int coordenadax,coordenaday,valor,seleccion=0,ct=1,columna=0,fila=0,valorBuscado=0;
    int matriz[9][9];
    int subMatriz[3][3];
    iniciarMatriz(matriz);
    while (seleccion != -1 || ct == 81){
        cout << "Ingrese posicion en x: ";
        cin >>coordenadax;
        cout << "Ingrese posicion en y: ";
        cin >>coordenaday;
        cout << "Ingrese valor que va a ingresar: ";
        cin >>valor;
        llenarMatriz(coordenadax,coordenaday,valor,matriz);
        cout << "Digite 1 para añadir un nuevo valor, y -1 para salir: ";
        cin >> seleccion;
        cout << endl;
        ct++;
    }
    mostrarMatriz(matriz);
    cout << "Ingrese el valor que busca: ";
    cin >> valorBuscado;
    cout << "Ingrese la fila en la que busca: ";
    cin >> fila;
    revisarFila(fila,valorBuscado,matriz);
    cout << "Ingrese la columna en la que busca: ";
    cin >> columna;
    revisarColumna(columna,valorBuscado,matriz);
    revisarSubMatriz(subMatriz,valorBuscado,matriz);
    return 0;
}

void iniciarMatriz(int matriz[9][9]){
    for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                matriz[i][j]=0;
            }
        }
}

void llenarMatriz(int x, int y, int valor, int matriz[9][9]){
    if (matriz[x][y]!=0){
        cout << "Esa posicion ya tiene un dato ingresado" << endl;
    }else if (x < 0 || x > 8 || y < 0 || y > 8){
        cout << "coordenada mal ingresada" << endl;
        return;
    }else{
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                if (x==j && y==i){
                    matriz[i][j]=valor;
                }
            }
        }
    }
}

void revisarFila(int y, int valor, int matriz[9][9]){
    int aux=0;
    for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                if (matriz[i][j]==valor && i==y)aux=1;
            }
        }
        if (aux == 1) cout << "Valor encontrado" << endl;
        else cout << "Valor no encontrado" << endl;
}

void revisarColumna(int x, int valor, int matriz[9][9]){
    int aux=0;
    for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                if (matriz[i][j]==valor && j==x)aux=1;
            }
        }
        if (aux == 1) cout << "Valor encontrado" << endl;
        else cout << "Valor no encontrado" << endl;
}

void revisarSubMatriz(int subMatriz[3][3], int valor, int matriz[9][9]){
    int aux=0;
    int x;
    cout << "Ingrese la posicion en x: ";
    cin >> x;
        if (x>6){
            cout << "En esa posicion no es posible generar una sub matriz de 3x3 comenzando de esa posicion" << endl;
        }
        for (int i=x; i<x+3; i++){
            for (int j=x; j<x+3; j++){
                subMatriz[i][j]=matriz[i][j];
                if (valor==subMatriz[i][j])aux=1;
            }
        }
        if (aux == 1) cout << "Valor encontrado" << endl;
        else cout << "Valor no encontrado" << endl;
}


void mostrarMatriz(int matriz[9][9]){
    for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                cout << matriz[i][j];
            }
            cout << endl;
        }
}
