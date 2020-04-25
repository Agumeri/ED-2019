/**
 *  @brief TDA Ingredientes
 * 
 * Una instancia @e c del tipo de datos abstracto @c Ingredientes es un objeto
 * compuesto vector dinámico de Ingredientes (VD<Ingrediente>)
 *
 * Un ejemplo de uso:
 * @include Ingredientes.h
 * 
 * @autor Agustín Mérida Gutiérrez
 * @autor Eduardo Bárez Navarro
 * @date Octubre 2019
 */
#ifndef INGREDIENTES_H
#define INGREDIENTES_H
#include <iostream>
#include <cmath>
#include <string>
#include <vector> 
#include "Ingrediente.h"
#include "VD.hpp"
using namespace std;

class Ingredientes{
    private:
        VD<Ingrediente> datos;

    public:
    
        /**
        * @brief Constructor por defecto del objeto Ingredientes
        * @return Se inicializa el array dinámico de Ingrediente a 0
        */
        Ingredientes();

        /**
         * @brief Sobrecarga de operador =
         * @param I Ingredientes
         * @return Un dato de tipo Ingredientes que tiene lo mismo que I
         */
        Ingredientes operator=(const Ingredientes &I);

        /**
        * @brief Metodo get del objeto Ingredientes
        * @param i entero que indica la posicion a la que se va a acceder
        * @return Ingrediente que se encuentre en la posicion i de datos
        */
        Ingrediente getIngrediente(int i);

        /**
         * @brief Metodo del objeto Ingredientes que añade un elemento 
         * @param I ingrediente que se va a añadir al final del VD<Ingrediente> datos
         * @return El objeto Ingredientes tiene un dato mas
         */
        void aniadir( Ingrediente &I);

        /**
         * @brief Metodo del objeto Ingredientes que modifica un dato de este
         * @param pos entero que indica la posicion de datos
         * @param x Ingrediente que va a cambiarse por el del VD<Ingrediente>
         * @return Se cambia el Ingrediente de la posicion pos de VD<Ingrediente> por el ingrediente xs
         */
        void modificarIngrediente(int pos, const Ingrediente &x);

        /**
         * @brief Ordena el objeto por nombre
         * @return El objeto Ingrediente ordenado por el nombre de los ingredientes
         */
        void ordenarPorNombre();

        
        /**
         * @brief Metodo que ordena por tipo un objeto Ingredientes
         * @return Devuelve el objeto Ingredientes pero ordenado de menor a mayor por tipo 
         */
        Ingredientes ordenarPorTipo();
    
        /**
         * @brief Sobrecarga del flujo de salida
         * @param os ostream
         * @param I Ingredientes
         * @return Devuelve los ingredientes impresos por pantalla, mostrando sus atributos
         */
        friend ostream& operator<<(ostream & os, const Ingredientes& I);
        
        /**
         * @brief  Sobrecarga del flujo de entrada
         * @param is istream
         * @param I Ingredientes
         * @return Permite la creación de Ingredientes mediante la lectura del fichero
         */
        friend istream& operator>>(istream&  is, Ingredientes& I);
        
         /**
         * @brief Metodo que llama a OrdenarPorTipo y lo imprime
         * @param os ostream
         * @return Devuelve el objeto Ingredientes ordenado de menor a mayor por tipo 
         */
        void ImprimirPorTipo(ostream &os);

        /**
        * @brief Metodo get del objeto Ingredientes
        * @return int con el tamaño de datos
        */
        int size();

        /**
        * @brief Metodo get del objeto Ingredientes que devuelve un objeto de la clase Ingrediente
        * @param n string con un nombre de ingrediente
        * @return Ingrediente cuyo nombre es n
        */
        Ingrediente get(string n);

        /**
         * @brief Metodo del objeto Ingredientes que borra un Ingrediente 
         * @param nroIngrediente entero que indica la posición que se va a borrar del VD<Ingrediente>
         * @return Ingredientes con el Ingrediente de la posicion nroIngrediente borrado 
         */
        void borrarIngXPos(const int numIngrediente);

        /**
         * @brief Metodo del objeto Ingredientes que borra un Ingrediente segun su nombre
         * @param nombre string con el nombre de un Ingrediente de VD<Ingrediente>
         */
        void borrar(const string &nombre);
    
        /**
         * @brief Metodo que devuelve un Ingredientes auxiliar con el tipo especifico
         * @param tipo string cuyo valor equivale a un tipo de Ingrediente
         * @return Devuelve un objeto Ingredientes con  el tipo pasado por param
         */
        Ingredientes getIngredienteTipo(string tipo);

        /**
         * @brief Metodo get del objeto Ingredientes
         * @return VD<string> con todos los tipos de los Ingredientes 
         */
        VD<string> getTipos();
        
        /**
         * @brief Metodo del objeto Ingredientes que obtiene un array de enteros de calorias
         * @return VD<int> cuyos datos son las calorias de todos los ingredientes
         */
        VD<int> obtenerCalorias();

        /**
         * @brief Metodo del objeto Ingredientes que obtiene un array de enteros de hidratos
         * @return VD<int> cuyos datos son los prc_hidratos de todos los ingredientes
         */
        VD<int> obtenerHidratos();

        /**
         * @brief Metodo del objeto Ingredientes que obtiene un array de enteros de proteinas
         * @return VD<int> cuyos datos son los prc_proteinas de todos los ingredientes
         */
        VD<int> obtenerProteinas();
        
        /**
         * @brief Metodo del objeto Ingredientes que obtiene un array de enteros de grasas
         * @return VD<int> cuyos datos son los prc_grasas de todos los ingredientes
         */
        VD<int> obtenerGrasas();

        /**
         * @brief Metodo del objeto Ingredientes que obtiene un array de enteros de fibra
         * @return VD<int> cuyos datos son las prc_fibra de todos los ingredientes
         */
        VD<int> obtenerFibra();

        /**
         * @brief Metodo del objeto Ingredientes que devuelve un ingrediente
         * @return Ingrediente cuyo atributo num_cal es el mayor de todos los ingredientes del VD<Ingrediente>
         */
        Ingrediente ingrMaxCal();

        /**
         * @brief Metodo del objeto Ingredientes que devuelve un ingrediente
         * @return Ingrediente cuyo atributo prc_hidratos es el mayor de todos los ingredientes del VD<Ingrediente>
         */
        Ingrediente ingrMaxHc();

        /**
         * @brief Metodo del objeto Ingredientes que devuelve un ingrediente
         * @return Ingrediente cuyo atributo prc_proteinas es el mayor de todos los ingredientes del VD<Ingrediente>
         */
        Ingrediente ingrMaxPr();

        /**
         * @brief Metodo del objeto Ingredientes que devuelve un ingrediente
         * @return Ingrediente cuyo atributo prc_grasas es el mayor de todos los ingredientes del VD<Ingrediente>
         */
        Ingrediente ingrMaxGr();

        /**
         * @brief Metodo del objeto Ingredientes que devuelve un ingrediente
         * @return Ingrediente cuyo atributo prc_fibra es el mayor de todos los ingredientes del VD<Ingrediente>
         */
        Ingrediente ingrMaxFib();

        /**
         * @brief Metodo del objeto Ingredientes que devuelve un ingrediente
         * @return Ingrediente cuyo atributo num_cal es el menor de todos los ingredientes del VD<Ingrediente>
         */
        Ingrediente ingrMinCal();
        
        /**
         * @brief Metodo del objeto Ingredientes que devuelve un ingrediente
         * @return Ingrediente cuyo atributo prc_hidratos es el menor de todos los ingredientes del VD<Ingrediente>
         */
        Ingrediente ingrMinHc();
        
        /**
         * @brief Metodo del objeto Ingredientes que devuelve un ingrediente
         * @return Ingrediente cuyo atributo prc_proteinas es el menor de todos los ingredientes del VD<Ingrediente>
         */
        Ingrediente ingrMinPr();
        
        /**
         * @brief Metodo del objeto Ingredientes que devuelve un ingrediente
         * @return Ingrediente cuyo atributo prc_grasas es el menor de todos los ingredientes del VD<Ingrediente>
         */
        Ingrediente ingrMinGr();
        
        /**
         * @brief Metodo del objeto Ingredientes que devuelve un ingrediente
         * @return Ingrediente cuyo atributo prc_fibra es el menor de todos los ingredientes del VD<Ingrediente>
         */
        Ingrediente ingrMinFib();
};

#endif
