/**
 *  @brief TDA instrucciones
 * 
 * Una instancia @e c del tipo de datos abstracto @c instrucciones esta compuesto
 * por un objeto ArbolBinario<string> datos que será el arbol binario que represente 
 * los pasos para realizar una receta, y por un objeto acciones acc que contendrá todas las
 * acciones posibles a realizar
 *
 * Un ejemplo de uso:
 * @include instrucciones.h
 * 
 * @autor Agustín Mérida Gutiérrez
 * @autor Eduardo Bárez Navarro
 * @date Diciembre 2019
 */
#ifndef INSTRUCCIONES_H
#define INSTRUCCIONES_H
#include <iostream>
#include <stack>
#include "arbolbinario.h"
#include "acciones.h"

using namespace std;

class instrucciones{
    private:
        ArbolBinario<string> datos;
        acciones acc;
        
    public:
        /**
         * @brief Constructor por defecto de un nuevo objeto de la clase instrucciones
         * @return crea un objeto por defecto de la clase instrucciones
         */
        instrucciones();

        /**
         * @brief Constructor por parametros de un nuevo objeto de la clase instrucciones
         * @param otro ArbolBinario<string> 
         * @param accion objeto acciones
         * @return crea un objeto cuyo atributo datos va a tener el valro de otro, y el atributo acc tendrá el valor de accion
         */
        instrucciones(const ArbolBinario<string> &otro, const acciones &accion);

        /**
         * @brief Constructor por copia de un nuevo objeto de la clase instrucciones
         * @param otras objeto instrucciones
         * @return crea un objeto cuyos atributos serán los del objeto instrucciones otras
         */
        instrucciones(const instrucciones& otras);

        /**
         * @brief Destructor de un objeto de la clase instrucciones
         * @return pone el objeto instrucciones a su estado inicial por defecto
         */
        ~instrucciones();

        /**
         * @brief Metodo de sobrecarga del flujo de salida
         * @param os ostream
         * @param inst objeto de la clase instrucciones
         * @return ostream& cuyo valor es el de las etiquetas del arbol del objeto isntrucciones inst
         */
        friend ostream& operator<<(ostream& os, instrucciones inst);

        /**
         * @brief Metodo de sobrecarga del flujo de entrada
         * @param is istream
         * @param inst objeto de la clase instrucciones
         * @return istream& cuyo valor es el conjunto de instrucciones que se ha introducido mediante un archivo
         */
        friend istream& operator>>(istream& is, instrucciones &inst);

        /**
         * @brief Metodo que indica cuando un string es una accion
         * @param accion string que se va a utilizar para comparar
         * @return pair<bool,char> cuyo bool será true si la accion de nombre accion existe y false si no es asi. 
         *         El char contendrá la ariedad de la accion si esta existe, si no su valor será ' '
         */
        pair<bool,char> esAccion(const string &accion);

        /**
         * @brief Metodo para asignarle un valor al atributo acc del objeto instrucciones
         * @param fichero_acciones acciones 
         * @return el valor del atributo acc del objeto que llama a este metodo será el de las acciones contenidas en el objeto acciones fichero_acciones
         */
        void aniadir_acciones(acciones fichero_acciones);

        /**
         * @brief Metodo get del objeto instrucciones
         * @return ArbolBinario<string> 
         */
        ArbolBinario<string> getArbol();

        /**
         * @brief Metodo encargado de obtener el ArbolBinario<string> de la fusion de dos recetas
         * @param i1 primer objeto instrucciones de la fusion
         * @param i2 segundo objeto instrucciones de la fusion
         * @return El atributo datos del objeto instrucciones que llama a este metodo será aquel cuya raiz sea "Acompañar", la rama izquierda será el correspondiente al
         *         atributo datos del objeto instrucciones i1 y la rama derecha será el correspondiente al atributo datos del objeto instrucciones i2
         */
        void calcularInstruccionesFusion( instrucciones i1, instrucciones i2);
};

#endif //fin de instrucciones.h