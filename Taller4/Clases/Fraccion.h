#ifndef FRACCION_H
#define FRACCION_H

class Fraccion
{
    private:
        int numerador;
        int denominador;
        float resultado;
    public:
        Fraccion();
        Fraccion(int, int);
        //~Fraccion();

        //Setters
        void setNumerador(int x){numerador = x;}
        void setDenominador(int x){denominador = x;}
        void setResultado(float x){resultado = x;}

        //Getters
        int getNumerador(){return numerador;}
        int getDenominador(){return denominador;}
        float getResultado(){return resultado;}

        void verFraccion();
        bool Verificar(int, int);
        bool Menor();
};

#endif  //FRACCION_H