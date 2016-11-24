
#include <iostream>
#include <string>

using namespace std;
using std::string;

int** crearMatriz(int, int);
void freeMatriz(int**, int);
void imprimirMatriz(int**, int, int);
void imprimirMenu();
int** colocarCoordenada(int**, int, int, int, int);

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
int** colocarCoordenada(int** matriz, int filas, int columnas, int corX, int corY){
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      if(i == corX && j == corY){
        matriz[i][j] = 1;
      }
    }
  }
  return matriz;
}

int** checkIfEmpty(int** matriz, int filas, int columnas, int corX, int corY){
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {

    }
  }
}

void colorValorInicial(int**matriz, int filas,int columnas){
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      matriz[i][j] = -1;
    }
  }
}


//metodo que imprime menu para el ususario
void imprimirMenu(){
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
      colorValorInicial(matriz, filas, columnas);
      imprimirMatriz(matriz, filas, columnas);
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
          colocarCoordenada(matriz, filas, columnas, corX, corY);
          imprimirMatriz(matriz, filas, columnas);
        }
      }
    }
    if(choice == 2){
      cout << "Entro 2";
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
