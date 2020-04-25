/**
 *  @brief TDA Ingredientes
 * 
 * Una instancia @e c del tipo de datos abstracto @c Ingredientes esta compuesta
 * por un dato de la stl vector<Ingrediente> datos, ademas de otro 
 * vector<int> indice_tipo, que nos indicará la posicion de los datos;
 *
 * Un ejemplo de uso:
 * @include Ingredientes.h
 * 
 * @autor Agustín Mérida Gutiérrez
 * @autor Eduardo Bárez Navarro
 * @date Diciembre 2019
 */
#ifndef INGREDIENTES_H
#define INGREDIENTES_H
#include <iostream>
#include <string>
#include <vector> 
#include "Ingrediente.h"
using namespace std;

class Ingredientes{
    private:
        vector<Ingrediente> datos;
        vector<int> indice_tipo;
    public:


        //*********************************************************************++
        class iterator{
            private:
                vector<Ingrediente>::iterator it;
            public:
                iterator():it(0){}
                iterator(const vector<Ingrediente>::iterator& ite): it(ite){}
                iterator(const iterator& i):it(i.it){}
                ~iterator(){};
                iterator& operator++();// {++it; return *this;}
                iterator& operator--();// {--it; return *this;}
                bool operator==(const iterator& otro) const;
                bool operator!=(const iterator& otro) const;
                Ingrediente & operator*();

                friend class Ingredientes;
        };
        //*********************************************************************
        //Metodos begin y end de la clase iterator
                iterator begin(){
                    iterator i;
                    i.it = datos.begin();
                    return i;
                }

                iterator end(){
                    iterator i;
                    i.it = datos.end();
                    return i;
                }
            
        //*********************************************************************
        
        class const_iterator{
            private:
                vector<Ingrediente>::const_iterator itc;

            public:
                const_iterator():itc(0){}
                const_iterator(const vector<Ingrediente>::const_iterator& ite): itc(ite){}
                const_iterator(const const_iterator& i):itc(i.itc){}
                const_iterator& operator++() {++itc; return *this;}
                const_iterator operator--() {--itc; return *this;}
                bool operator==(const const_iterator& i) const {return itc == i.itc;}
                bool operator!=(const const_iterator& i) const {return itc!=i.itc;}
                Ingrediente operator*() const {return *itc;}

                friend class Ingredientes;
        };
        //*********************************************************************
        //Metodos begin y end de la clase const_iterator

        const_iterator begin() const{
            return const_iterator(datos.cbegin());
        }

        const_iterator end() const{
            return const_iterator(datos.cend());
        }
        //***********************************************************************
        
        /**
         * @brief Sobrecarga de operador =
         * @param I Ingredientes
         * @return Un dato de tipo Ingredientes que tiene lo mismo que I
         */
        Ingredientes operator=(const Ingredientes &I);

        /**
         * @brief Sobrecarga del flujo de salida
         * @param os ostream
         * @param I Ingredientes
         * @return Devuelve los ingredientes impresos por pantalla, mostrando sus atributos
         */
        friend ostream& operator<<(ostream & os, const Ingredientes &I);
        
        /**
         * @brief  Sobrecarga del flujo de entrada
         * @param is istream
         * @param I Ingredientes
         * @return Permite la creación de Ingredientes mediante la lectura del fichero
         */
        friend istream& operator>>(istream&  is, Ingredientes& I);

        /**
         * @brief Metodo del objeto Ingredientes que añade un elemento 
         * @param I ingrediente que se va a añadir al final del vector<Ingrediente> datos
         * @return El objeto Ingredientes tiene un dato mas
         */
        void aniadir(Ingrediente& ing);

        /**
         * @brief Ordena el objeto por nombre
         * @return El objeto Ingrediente ordenado por el nombre de los ingredientes
         */
        void ordenarPorNombre();

        /**
         * @brief Metodo que llama a OrdenarPorTipo y lo imprime
         * @param os ostream
         * @return Devuelve el objeto Ingredientes ordenado de menor a mayor por tipo 
         */
        void ImprimirPorTipo(ostream &os);

        /**
         * @brief Metodo que ordena por tipo un objeto Ingredientes
         * @return Devuelve el objeto Ingredientes pero ordenado de menor a mayor por tipo 
         */
        Ingredientes ordenarPorTipo();

        /**
        * @brief Metodo get del objeto Ingredientes
        * @return int con el tamaño de datos
        */
        int size(){return datos.size();}

        /**
        * @brief Metodo get del objeto Ingredientes que devuelve un objeto de la clase Ingrediente
        * @param n string con un nombre de ingrediente
        * @return Ingrediente cuyo nombre es n
        */
        Ingrediente get(string n);

        /**
         * @brief Metodo del objeto Ingredientes que borra un Ingrediente segun su nombre
         * @param nombre string con el nombre de un Ingrediente de VD<Ingrediente>
         */
        void borrar(const string &nombre);

        /**
         * @brief Metodo get del objeto Ingredientes
         * @return vector<string> con todos los tipos de los Ingredientes 
         */
        vector<string> getTipos();

        /**
         * @brief Metodo que devuelve un Ingredientes auxiliar con el tipo especifico
         * @param tipo string cuyo valor equivale a un tipo de Ingrediente
         * @return Devuelve un objeto Ingredientes con  el tipo pasado por param
         */
        Ingredientes getIngredienteTipo(string tipo);


};//end ingredientes



#endif