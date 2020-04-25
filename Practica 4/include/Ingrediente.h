/**
 *  @brief TDA Ingrediente
 * 
 * Una instancia @e c del tipo de datos abstracto @c Ingrediente es un objeto
 * compuesto un string que indica el nombre, otro string que indica el tipo de
 * alimento que es, y cinco enteros que indican el numero de calorias, el
 * numero de hidratos de carbono, el numero de proteinas, el valor de grasas y
 * el valor de fibra del Ingrediente (cada uno, un int)
 *
 * Un ejemplo de uso:
 * @include Ingrediente.h
 * 
 * @autor Agustín Mérida Gutiérrez
 * @autor Eduardo Bárez Navarro
 * @date Diciembre 2019
 */
#ifndef INGREDIENTE_H
#define INGREDIENTE_H
#include <iostream>
#include <cmath>
#include <string>

using namespace std;


class Ingrediente{
    private:
        string name;
        int num_cal,
               prc_hidratos,
               prc_proteinas,
               prc_grasas,
               prc_fibra;
        string tipo;

    public:

        /**
         * @brief Constructor vacio de Ingrediente
         * @return Atributos inicializado a 0 y NULL
         */
        Ingrediente();

        /**
         * @brief Constructor con parametros
         * @param name string
         * @param num_cal int
         * @param prc_hidratos int
         * @param prc_proteinas int
         * @param prc_grasas int
         * @param prc_fibra int
         * @param tipo string
         * @return Ingrediente con atributos inicializados segun param
         */
        Ingrediente(string name, int num_cal, int prc_hidratos, int prc_proteinas, int prc_grasas, int prc_fibra, string tipo);

        /**
         * @brief Constructor por copia
         * @param otro Ingrediente
         * @return Ingrediente con los mismos valores que el Ingrediente otro
         */
        Ingrediente(const Ingrediente& otro);

        /**
         * @brief Destructor de Ingrediente
         */
        ~Ingrediente();

        /**
         * @brief Sobrecarga del flujo de salida
         * @param os ostream
         * @param I Ingrediente
         * @return Devuelve el ingrediente impreso por pantalla, mostrando sus atributos
         */
        friend ostream& operator<<(ostream & os, const Ingrediente& I);

        /**
         * @brief  Sobrecarga del flujo de entrada
         * @param is istream
         * @param I Ingrediente
         * @return Permite la creación de un ingrediente mediante la lectura del fichero
         */
        friend istream& operator>>(istream&  is, Ingrediente& I);

        /**
         * @brief Get the Nombre object
         * @return private: name string
         */
        string getNombre();

        /**
         * @brief Get de calorias
         * @return private: num_cal int
         */
        int getCalorias();
        
        /**
         * @brief Get de nombre
         * @return private: prc_hidratos int
         */
        int getHc();

        /**
         * @brief Get de proteinas
         * @return private: prc_proteinas int
         */
        int getProteinas();
        
        /**
         * @brief Get de grasas
         * @return private: prc_grasas int
         */
        int getGrasas();

        /**
         * @brief Get de fibra
         * @return private: prc_fibra int
         */
        int getFibra();

        /**
         * @brief Get de tipo
         * @return private: tipo string
         */
        string getTipo();
};

#endif