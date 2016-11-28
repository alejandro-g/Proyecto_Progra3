
#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
using std::string;

int** crearMatriz(int, int);
void freeMatriz(int**, int);
void imprimirMatriz(int**, int, int);
void imprimirMenu();
int** colocarCoordenada(int**, int, int, int, int, int);

int main(){

  imprimirMenu();

}

//metodo encargado de crear la matriz en memoria dinamica
int** crearMatriz(int filas, int columnas){
  int** matriz = new int*[filas];

  for(int i = 0; i < filas; ++i){
    matriz[i] = new int [columnas];
  }
  return matriz;
}

//metodo que sirve para librar memoria
void freeMatriz(int**matriz, int filas){
  for(int i = 0; i < filas; ++i){
    delete[] matriz[i];
    matriz[i] = NULL;
  }
  delete[]matriz;
}

//metodo que imprime la matriz
void imprimirMatriz(int** matriz, int filas, int columnas){
  for (int i = 0; i < filas; ++i) {
    for(int j = 0; j < columnas; ++j) {
      cout << "[" << matriz[i][j] << "]";
    }
    cout << endl;
  }
}

bool validarNumeros(int numero){
  if(numero <= 3){
    return numero > 1;
  } else if (numero % 2 == 0 || numero % 3 == 0){
    return false;
  } else {
    for (int i = 5; i * i <= numero; i += 6) {
      if(numero % i == 0 || numero % (i + 2) == 0){
        return false;
      }
    }
    return true;
  }
}

//metodo para colocar las coordenadas ingresadas por el usuario en la matriz
int** colocarCoordenada(int** matriz, int filas, int columnas, int corX, int corY, int numIngresado){
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      if(i == corX && j == corY){
        matriz[i][j] = numIngresado;
      }
    }
  }
  return matriz;
}

//metodo que revisa si la columna donde se coloca la coordenada ya esta llena
bool isColumnFull(int** matriz, int filas, int columnas, int fila, int columna){
  int emptyColumnCells = 0;
  for (int i = 0; i < filas; i++) {
    if (matriz[i][columna] != -1) {
      emptyColumnCells++;
    }
  }
  if (emptyColumnCells != columnas) {
    return false;
  }else {
    return true;
  }
}

//metodo que revisa si la columna donde se coloca la coordenada ya esta llena
bool isFilaFull(int** matriz, int filas, int columnas, int fila, int columna){
  int emptyRowCells = 0;
  for (int i = 0; i < columnas; i++) {
    if (matriz[fila][i] != -1) {
      emptyRowCells++;
    }
  }
  if (emptyRowCells != filas) {
    return false;
  }else {
    return true;
  }
}

//revisa si una coordenada ingresada por el usuario ya ha sido tomada
int** checkIfEmpty(int** matriz, int filas, int columnas, int corX, int corY, int numIngresado){
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      if(i == corX && j == corY){
        if(matriz[i][j] == -1){
          matriz[i][j] = numIngresado;
        }else{
          cout << "Lo sentimos pero este espacio ya ha sido tomado" << endl;
          cout << "Por favor ingrese otra coordenada X: ";
          cin >> corX;
          cout << "Por favor ingrese otra coordenada Y: ";
          cin >> corY;
          matriz[i][j] = numIngresado;
        }
      }
    }
  }
}

//inicializar la matriz con -1
void colocarValorInicial(int**matriz, int filas,int columnas){
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      matriz[i][j] = -1;
    }
  }
}

//calcula el numero de la fila rellenada y retorna si es primo o no
bool isRowPrime(int** matriz, int filas, int columnas, int fila){
  string nume = "";
  for (int i = 0; i < columnas; i++) {
    string num = to_string(matriz[fila][i]);
    const char *num2 = num.c_str();
    nume = nume + num2;
  }
  int numeroEntero = stoi(nume);
  return validarNumeros(numeroEntero);
}

bool isColumnPrime(int** matriz, int filas, int columnas, int columna){
  string nume = "";
  for (int i = 0; i < filas; i++) {
    string num = to_string(matriz[i][columna]);
    const char *num2 = num.c_str();
    nume = nume + num2;
  }
  int numeroEntero = stoi(nume);
  return validarNumeros(numeroEntero);
}

//metodo que imprime menu para el usuario
void imprimirMenu(){
  bool win = false;
  string Jugador1, Jugador2;
  int contador = 1;
  int opcion;
  int choice;
  int filas, columnas;
  int** matriz;
  int corX, corY;
  int numIngresado;
  cout << "Bienvenido al juego de la matriz prima!" << endl;
  cout << "Jugador 1, Desea ingresar un nombre? (1=Si | 0=No): ";
  cin >> opcion;
  if(opcion == 0){
    cout << "Bienvenido Jugador 1!" << endl;
  }else{
    cout << "Jugador 1- Porfavor ingrese su nombre: ";
    cin >> Jugador1;
    cout << "Bienvenido " << Jugador1 << "!" << endl;
  }
  cout << "Jugador 2, Desea ingresar un nombre> (1=Si | 0=No): ";
  cin >> opcion;
  if(opcion == 0){
    cout << "Bienvenido Jugador 2!" << endl;
  }else{
    cout << "Jugador 2- Porfavor ingrese su nombre: ";
    cin >> Jugador2;
    cout << "Bienvenido " << Jugador2 << "!" << endl;
  }

  do{
    cout << endl;
    cout << "******JUEGO DE LA MATRIZ PRIMA******" << endl;
    cout << endl;
    cout << "1.Jugar" << endl << "2.Mostrar el marcador" << endl << "3.Salir" << endl;
    cout << "Ingrese su opcion: ";
    cin >> choice;
    if(choice == 1){
      cout << "Ingrese cantidad de filas de la matriz: ";
      cin >> filas;
      cout << "Ingrese cantidad de columnas de la matriz: ";
      cin >> columnas;
      matriz = crearMatriz(filas,columnas);
      colocarValorInicial(matriz, filas, columnas);
      imprimirMatriz(matriz, filas, columnas);
      while(!win){
        if(contador % 2 != 0){
          cout << "Jugador 1- Por favor ingrese la coordenada X: ";
          cin >> corX;
          cout << "Jugador 1- Por favor ingrese la coordenada Y: ";
          cin >> corY;
          cout << "Jugador 1- Por favor ingrese un numero (0-9): ";
          cin >> numIngresado;
          if(numIngresado > 9 || numIngresado < 0){
            cout << "El numero debe estar entre los rangos o debe ser positivo" << endl;
          }else{
            checkIfEmpty(matriz, filas, columnas, corX, corY, numIngresado);
            colocarCoordenada(matriz, filas, columnas, corX, corY, numIngresado);
            imprimirMatriz(matriz, filas, columnas);
          }
        }else{
          cout << "Jugador 2- Por favor ingrese la coordenada X: ";
          cin >> corX;
          cout << "Jugador 2- Por favor ingrese la coordenada Y: ";
          cin >> corY;
          cout << "Jugador 2- Por favor ingrese un numero (0-9): ";
          cin >> numIngresado;
          if(numIngresado > 9 || numIngresado < 0){
            cout << "En numero debe estar entre los rangos o debe ser positivo" << endl;
          }else{
            checkIfEmpty(matriz, filas, columnas, corX, corY, numIngresado);
            colocarCoordenada(matriz, filas, columnas, corX, corY, numIngresado);
            imprimirMatriz(matriz, filas, columnas);
          }
        }
        if(isColumnFull(matriz, filas, columnas, corX, corY)){
          cout << "*******************************" << endl;
          cout << "Columna llena!" << endl;
          cout << "*******************************" << endl;
          //promedioColumna, si retorna un primo, hacer  el break
          if(isColumnPrime(matriz, filas, columnas, corY)){
            cout << "La columna " << corX << " forma un numero primo, hay un ganador!" << endl;
            break;
          }
        }else  if(isFilaFull(matriz, filas, columnas, corX, corY)){
            cout << "*******************************" << endl;
            cout << "Fila llena!" << endl;
            cout << "*******************************" << endl;
            //promedioFila, si retorna primo, hacer break
            if(isRowPrime(matriz, filas, columnas, corX)){
              cout << "La fila " << corX << " forma un numero primo, hay un ganador!" << endl;
              break;
            }
          }
        contador++;
      }//fin while
    }
    if(choice == 2){
      cout << "Resultados de la Partida!";
    }

    if (choice == 3){
      cout << "Seguro que desea salir del juego? (1=Si | 0=No): ";
      cin >> opcion;
      if(opcion == 0){
        imprimirMenu();
      }else{
        cout << "Tenga un buen dia!" << endl;
        freeMatriz(matriz, filas);
      }
    }
  }while (choice !=0 && choice < 3);

}
