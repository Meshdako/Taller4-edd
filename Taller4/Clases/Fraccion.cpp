#include "Fraccion.h"
#include <iostream>

using namespace std;

Fraccion::Fraccion()
{
    numerador = 0;
    denominador = 1;
}

Fraccion::Fraccion(int num, int den)
{
    if(Verificar(num, den)){
        cout << "Su fracción es infinita, no nos metamos en esos términos, que no terminaríamos nunca este programa.\n\t    Gracias." << endl;
    }
    else{
        numerador = num;
        denominador = den;
        resultado = (float)num / (float)den;

        cout << "Datos ingresados correctamente." << endl;
    }
}

void Fraccion::verFraccion()
{
    cout << numerador << "/" << denominador;
}

bool Fraccion::Verificar(int a, int b)
{
    bool respuesta = (b == 0) ? true : false;
    return respuesta;
}

bool Fraccion::Menor()
{
    bool respuesta = (numerador < denominador) ? true : false;
    return respuesta;
}