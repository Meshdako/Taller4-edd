#include <iostream>
#include <list>

//#include "Fraccion.h"
//#include "Fraccion.cpp"

using namespace std;

class Fraccion
{
    private:
        int numerador;
        int denominador;
        float resultado;
    public:
        Fraccion(){
            numerador = 0;
            denominador = 1;
            resultado = (float)numerador / (float) denominador;
        }
        Fraccion(int num, int den){
            if(Verificador(den)){
                numerador = num;
                denominador = den;
                resultado = (float)numerador / (float)denominador;
            }
            else{
                cout << "No se puede devidir por 0." << endl;
            }
        }

        //Getters
        float getResultado(){return resultado;}

        bool Verificador(int num){
            bool respuesta = (num != 0) ? true : false;
            return respuesta;
        }
        bool Menor(){
            bool respuesta = (numerador < denominador) ? true : false;
            return respuesta;
        }
        void verFraccion(){
            cout << numerador << "/" << denominador;
        }
};

typedef struct Nodo{
    Fraccion Fracc;
    struct Nodo *siguiente;
}Nodo;

typedef struct Lista{
    Nodo* Cabeza;
}Lista;

Nodo* CrearNodo(Fraccion N)
{
    Nodo* nodo = new Nodo();
    nodo->Fracc = N;
    nodo->siguiente = NULL;
    return nodo;
}

void DestruirNodo(Nodo* nodo)
{
    free(nodo);
}

void InsertarPrincipio(Lista* lista, Fraccion N)
{
    Nodo* nodo = CrearNodo(N);
    nodo->siguiente = lista->Cabeza;
    lista->Cabeza = nodo;
}

void InsertarFinal(Lista* lista, Fraccion N)
{
    Nodo* nodo = CrearNodo(N);

    if(lista->Cabeza == NULL){
        lista->Cabeza = nodo;
    }
    else{
        Nodo* Aux = lista->Cabeza;

        //Recorremos la lista.
        while(Aux->siguiente){
            Aux = Aux->siguiente;
        }
        Aux->siguiente = nodo;
    }
}

void InsertarDespues(Fraccion P, Lista* lista, Fraccion N)
{
    Nodo* nodo = CrearNodo(N);

    if(lista->Cabeza == NULL){
        lista->Cabeza = nodo;
    }
    else{
        Nodo* Aux = lista->Cabeza;
        int pos = 0;

        while(Aux->Fracc.getResultado() != P.getResultado()){
            Aux = Aux->siguiente;
        }
        nodo->siguiente = Aux->siguiente;
        Aux->siguiente = nodo;
    }
}

Fraccion* Obtener(Fraccion N, Lista* lista)
{
    if(lista->Cabeza == NULL){
        return 0;
    }
    else{
        Nodo* Aux = lista->Cabeza;

        while(Aux->Fracc.getResultado() != N.getResultado()){
            Aux = Aux->siguiente;
        }
        return &Aux->Fracc;
    }
}

Lista* MiLista = (Lista*) new Lista();

//Funciones
void Agregar()
{
    int auxnumerador, auxdenominador;
    
    cout << "Ingrese un numerador: ";
    cin >> auxnumerador;
    cout << "Ingrese un denominador: ";
    cin >> auxdenominador;

    Fraccion FAux(auxnumerador, auxdenominador);

    if(auxdenominador != 0)
        InsertarFinal(MiLista, FAux);
    else
        cout << "vuelve a intentarlo." << endl;
}

void Mostrar()
{
    Nodo* Aux = MiLista->Cabeza;
    while(Aux != NULL){
        Fraccion FAux = Aux->Fracc;
        FAux.verFraccion();
        Aux = Aux->siguiente;

        (Aux != NULL) ? cout << "->" : cout << "->//" << endl;
    }
} 

/* void Contabilizar()
{

}

void Mayor()
{

}

void Promedio()
{

}
 */

//Menú

int main()
{
    Agregar();
    Agregar();
    Agregar();
    Agregar();
    Mostrar();
}