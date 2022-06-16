#include <cstdlib>
#include <iostream>
#include <list>

#include "Clases/Fraccion.h"
#include "Clases/Fraccion.cpp"

using namespace std;

//Inicialización de la lista.
list<Fraccion> Lista;

//Funciones
int EsPrimoRecursivo(int num, int cont)
{
    if(cont == 0)
        return 1;
    else{
        if((num % cont) == 0)
            return EsPrimoRecursivo(num, cont - 1) + 1;
        else
            return EsPrimoRecursivo(num, cont - 1) + 0;
    }
}

bool EsPrimo(int num)
{
    int cont = 0;
    for(int i = 1; i < num; i++){
        if((num % i) == 0)
            cont++;
    }
    bool resp = (cont == 2) ? true : false;
    return resp;
}

void AgregarLLS()
{
    system("clear");

    int n, m;

    cout << "Ingrese una fracción:" << endl;
    cout << "Numerador: ";
    cin >> n;
    cin.ignore(5, '\n');
    cout << "Denominador: ";
    cin >> m;
    cin.ignore(5, '\n');

    Fraccion F1(n, m);

    if(m != 0)
        Lista.push_back(F1);
    else
        cout << "Vuelve a intentarlo." << endl;
}

void MostrarLLS()
{
    system("clear");

    list<Fraccion> ListAux;
    ListAux = Lista;

    cout << "Lista: ";
    while(!ListAux.empty()){
        //Copiamos un elemento de la lista.
        Fraccion Aux = ListAux.front();

        //Eliminamos ese elemento de la lista.
        ListAux.pop_front();
        
        //Imprimos ese elemento.
        Aux.verFraccion();
        (!ListAux.empty()) ? cout << "->" : cout << "->//" << endl;
    }
}

void ContabilizarLLS()
{
    system("clear");

    int cantidad = 0;

    list<Fraccion> ListAux;
    ListAux = Lista;

    cout << "La lista contiene: ";
    while(!ListAux.empty()){
        //Copiamos un elemento de la lista.
        Fraccion Aux = ListAux.front();

        //Eliminamos ese elemento de la lista.
        ListAux.pop_front();
        
        //Imprimos ese elemento.
        Aux.verFraccion();
        (!ListAux.empty()) ? cout << "->" : cout << "->//" << endl;

        if(Aux.Menor())
            cantidad++;
    }
    
    cout << "De todos estos elementos, hay: " << cantidad << " de fracciones que sus numeradores son menores a sus denominadores." << endl;
}

void MayorLLS()
{
    system("clear");

    Fraccion FraMayor;
    float mayor = 0;

    list<Fraccion> ListAux;
    ListAux = Lista;

    while(!ListAux.empty()){
        //Copiamos un elemento de la lista.
        Fraccion Aux = ListAux.front();

        //Eliminamos ese elemento de la lista.
        ListAux.pop_front();
        
        if(Aux.getResultado() > mayor){
            FraMayor = Aux;
            mayor = Aux.getResultado();
        }
    }
    cout << "La fracción mayor es: ";
    FraMayor.verFraccion();
    cout << endl;
}

void PromedioLLS()
{
    system("clear");

    //Copiar mi lista.
    list<Fraccion> ListAux;
    ListAux = Lista;

    int suma, cont;
    suma = cont = 0;

    while(!ListAux.empty()){
        Fraccion FraccionAux = ListAux.front();
        
        if(EsPrimo(FraccionAux.getNumerador())){
            suma += FraccionAux.getNumerador();
            cont++;
        }
    }

    float resultado;
    if(cont != 0)
        resultado = suma / cont;
    else
        resultado = 0;
    cout << "El promedio de números primos es igual a: " << resultado << endl;
}

void Menu()
{
    int eleccion;

    while(eleccion != 0){
        cout << "--------------------------------------" << endl;
        cout << "Eliga una opción:" << endl;
        cout << "1. Agregar un objeto a la LLS" << endl;
        cout << "2. Mostrar una LLS" << endl;
        cout << "3. Contabilizar en una LLS" << endl;
        cout << "4. Mayor en una LLS" << endl;
        cout << "5. Promedio en una LLS" << endl;
        cout << "Su elección es: ";
        cin >> eleccion;
        cin.ignore(5, '\n');

        switch(eleccion){
            case 1:
                AgregarLLS();
            break;
            case 2:
                if(!Lista.empty())
                    MostrarLLS();
                else
                    cout << "\t La lista está vacía" << endl;
            break;
            case 3:
                if(!Lista.empty())
                ContabilizarLLS();
            break;
            case 4:
                MayorLLS();
            break;
            case 5:
                PromedioLLS();
            break;
            default:
                cout << "\t Ingrese una opción válida." << endl;
                break;
        }
    }
}

int main()
{
    Menu();

    //int variable = 17;
    /* if(EsPrimoRecursivo(variable, variable - 1) == 1)
        cout << "el número " << variable << " es primo" << endl;
    else
        cout << "el número " << variable << " no es primo" << endl; */
    return 0;
}