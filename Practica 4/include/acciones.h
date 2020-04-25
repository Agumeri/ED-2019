/**
 *  @brief TDA acciones
 * 
 * Una instancia @e c del tipo de datos abstracto @c acciones esta compuesto
 * por un dato de la stl map<string,unsigned char> donde el string será el nombre
 * de la accion en cuestión, y el unsigned char será la ariedad de este
 *
 * Un ejemplo de uso:
 * @include acciones.h
 * 
 * @autor Agustín Mérida Gutiérrez
 * @autor Eduardo Bárez Navarro
 * @date Diciembre 2019
 */
#ifndef ACCIONES_H
#define ACCIONES_H
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

class acciones{
    private:
        map<string,unsigned char> datos;

        public:
        class iterator{
            private:
                map<string,unsigned char>::iterator it;
            public:
                iterator():it(0){}
                iterator(const map<string,unsigned char>::iterator& ite): it(ite){}
                iterator(const iterator& i):it(i.it){}
                ~iterator(){};
                iterator& operator++();// {++it; return *this;}
                iterator& operator--();// {--it; return *this;}
                bool operator==(const iterator& otro) const;
                bool operator!=(const iterator& otro) const;
                pair<string,unsigned char> operator*() const;

                friend class acciones;
        };
        //*********************************************************************
        //Metodos begin y end de la clase iterator
                iterator begin(){
                    iterator i;
                    i.it = datos.begin();
                    return i;
                }
        
        /**
         * @brief Metodo end de la clase iterator de iterator
         * @return iterator de accion que itera a una accion
         */
                iterator end(){
                    iterator i;
                    i.it = datos.end();
                    return i;
                }
            
        //*********************************************************************

            /**
             * @brief Constructor de un objeto de la clase acciones
             * @return Crea un objeto acciones
             */
            acciones();

            /**
             * @brief Constructor por parámetros de un objeto de la clase acciones
             * @param otro map<string,unsigned char>
             * @return crea un objeto acciones cuyo atributo datos tiene el valor del parámetro otro
             */
            acciones(const map<string,unsigned char>& otro);
            
            /**
             * @brief Constructor por copia de un objeto de la clase acciones
             * @param otro objeto de la clase acciones
             * @return crea un objeto acciones cuyo valor es el del objeto acciones otro
             */
            acciones(const acciones& otro);

            /**
             * @brief Destructor del objeto acciones
             * @return el objeto de la clase acciones tiene sus atributos nulos (vacíos)
             */
            ~acciones();

            /**
             * @brief Metodo de sobrecarga de salida de la clase acciones
             * @param os flujo de salida
             * @param acc objeto de la clase acciones
             * @return ostream& 
             */
            friend ostream& operator<<(ostream& os, acciones acc);
            
            /**
             * @brief Metodo de sobrecarga de entrada de la clase acciones
             * @param is flujo de entrada
             * @param acc objeto de la clase acciones
             * @return istream& 
             */
            friend istream& operator>>(istream& is, acciones &acc);
            
            /**
             * @brief Metodo añadir de la clase acciones
             * @param pareja pair<string,unsigned char>
             * @return se añade al map del objeto acciones el pair pareja
             */
            void aniadir(pair<string,unsigned char> pareja);
            
            /**
             * @brief Metodo clear de la clase acciones
             * @return Vacía el map del objeto acciones
             */
            void clear();
            

};//fin de acciones.h

    

#endif