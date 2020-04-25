/**
 *  @brief TDA Vector Dinámico (VD)
 * 
 * Una instancia @e c del tipo de datos abstracto @c VD es un objeto
 * compuesto por un array dinámico del tipo T (typename T), y el número de 
 * elementos de ese array, es decir, su tamaño. 
 *
 * Un ejemplo de uso:
 * @include VD.hpp
 * 
 * @autor Agustín Mérida Gutiérrez
 * @autor Eduardo Bárez Navarro
 * @date Octubre 2019
 */

#ifndef VD_H
#define VD_H
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <cassert>
using namespace std;


template <class T>
class VD{
    private:
        T *datos;
        int nelementos;
    
    public: 
        /**
         * @brief Constructor de un objeto VD
         * @return Se pone a nulo el array dinámico y el numero de elementos a cero
         */
        VD(){
            datos=nullptr;
            nelementos=0;
        }
        
        /**
         * @brief Constructor de un objeto VD con un numero de elementos determinado
         * @param num_elementos numero de elementos que se va a asignar VD
         * @return Se reserva la cantidad de memoria indicada por num_elementos del array dinámico y a nelementos se le asigna num_elementos
         * @pre num_elemetos debe ser mayor o igual a cero
         */
        VD(int num_elementos){
            if(num_elementos>=0)
                datos = new T[num_elementos];
            
            nelementos = num_elementos;
        }   

        /**
         * @brief Constructor de copia 
         * @param original es un objeto de la clase VD
         * @return Se crea un objeto VD asignandole los mismos atributos que otro objeto ya existente de la misma clase
         * @pre nelementos debe de ser mayor a cero
         */
        VD(const VD& original){
            nelementos = original.nelementos;

            if(nelementos > 0){
                datos = new T[nelementos];
                for(int i=0; i<nelementos; i++){
                    datos[i] = original.datos[i];
                }
            }else{
                datos = 0;
            }
        }

        /**
         * @brief Destructor del objeto VD
         * @pre nelementos debe de ser mayor a cero
         */
        ~VD(){
            if(this->nelementos > 0)
                delete [] datos;
            nelementos = 0;
        }

        /**
         * @brief Operador de asignación del objeto VD
         * @param original es un objeto de la clase VD
         * @return VD& con el mismo valor que original
         * @pre VD& ha de ser distinto a original
         */
        VD& operator=(const VD& original){
            if(this != &original){
                if(nelementos > 0)
                    delete[] datos;

                nelementos = original.nelementos;
                datos = new T[nelementos];

                for(int i=0; i<nelementos; i++){
                    datos[i] = original.datos[i];
                }
            
            }

            return *this;
        }

        /**
         * @brief Metodo get del objeto VD para conseguir el tamaño del array dinamico 
         * @return int con el valor de la variable nelementos
         */
        int size() const{
            return nelementos;
        }

        /**
         * @brief Metodo subíndice del objeto VD utilizado para acceder al dato correspondiente a una posición del array dinámico 
         * @param i entero que indica la posicion del array a la que se va a acceder
         * @return T& localizado en la posicion i del array dinámico datos
         * @pre i debe ser mayor o igual a 0 y menor o igual a nelementos
         */
        T &operator[](int i){
            assert(i>=0 && i<=nelementos);
            return datos[i];
        }
        
        /**
         * @brief Metodo subíndice del objeto VD utilizado para acceder al dato correspondiente a una posición del array dinámico 
         * @param i entero que indica la posicion del array a la que se va a acceder
         * @return T& localizado en la posicion i del array dinámico datos
         */
        const T &operator[](int i) const{
            assert(i>=0 && i<=nelementos);
            return datos[i];
        }

        /**
         * @brief Metodo set del objeto VD
         * @param i entero que indica la posicion del array a la que se va a acceder y el valor que se va a introducir
         * @return Se asigna el valor i a la posicion i del array dinamico i
         */
        void set(int i){
            this->datos[i] = i;
        }

        /**
         * @brief Metodo que cambia la memoria reservada del array dinamico datos por uno determinado
         * @param n entero que indica el tamaño que va a tener el array redimensionado
         * @return Se redimensiona el array dinámico datos con un tamaño n
         * @pre n debe de ser diferente al valor de nelementos
         */
        /*
        void resize(int n){
            if(n != nelementos){
                if(n != 0){
                    T *datos2;
                    datos2 = new T[n];
                    if(nelementos > 0){
                        int min = nelementos<n?nelementos:n;
                        for(int i=0; i<min; ++i){
                            datos2[i] = datos[i];

                        delete[] datos;
                        }
                    nelementos = n;
                    datos = datos2;
                    }
                }else{
                    if(nelementos > 0){
                        delete[] datos;
                        datos = 0;
                        nelementos = 0;
                    }
                }
            }
        }*/

        void resize(int new_nelementos){
            int min;

            if (new_nelementos != nelementos){
                if(new_nelementos > 0){
                    /* Reserva nuevo espacio */
                    T *p = new T[new_nelementos];

                    /* Copiar los componentes que se mantienen */
                    min = (nelementos < new_nelementos ? nelementos : new_nelementos);
                    for (int i = 0; i < min; i++)
                        p[i] = datos[i];

                    delete[] datos;
                    datos = p;
                    nelementos = new_nelementos;
                }
                else{
                    if(nelementos>0)
                        delete [] datos;
                    datos=0;
                    nelementos=0;
                    
                }
            }
        }
        
            

        /**
         * @brief Metodo del objeto VD que añade un elemento al final del array dinamico 
         * @param aux variable de la clase T
         * @return Se añade al final del array dinamico datos el objeto T aux 
         */
        void  aniadirElemento( T aux){
            VD otro(this->nelementos+1);
            for(int i=0; i<this->nelementos; i++)
                otro.datos[i] = this->datos[i];
            otro.datos[nelementos] = aux;

            (*this) = otro;
        }
        
        /**
         * @brief Metodo del objeto VD para modificar un elemento
         * @param pos entero que indica la posicion a modificar 
         * @param x variable de la clase T
         * @return El dato de la posicion pos del array dinamico datos cambia su valor al de x
         */
        void modificarElemento(int pos, T x){
            datos[pos]=x;
        }

        /**
         * @brief Metodo del objeto VD para borrar un elemento
         * @param pos entero que indica una posicion
         * @return Se elimina un elemento del array dinamico datos de la posicion pos
         */

        void borrarElemento(int pos){
            if(pos<nelementos && pos>0){
                for(int i=pos; i < nelementos-1; i++){
                    modificarElemento(i, datos[i+1]);
                }
                resize(nelementos-1);
            }
        }
        /*
        void borrarElemento(int pos){
            for(int i=0; i<nelementos; i++){
                if(i == pos){
                    while(i<nelementos-1){
                        datos[i] = datos[i+1];
                        i++;
                    }
                    i = nelementos;
                }
            }
            nelementos--;
        }*/

        /**
         * @brief Metodo del template VD utilizado para obtener la media 
         * @return float cuyo valor es la media de los elementos del array
         */
        float obtenerMedia(){
            float suma = 0;
            for (int i = 0; i < nelementos; i++) {
              suma += datos[i];
            }
            return suma / nelementos;
        }

        /**
         * @brief Metodo del template VD utilizado para obtener la varianza 
         * @return float cuyo valor es la varianza de los elementos del array
         */
        float obtenerVarianza(){
            float media = obtenerMedia();
            float varianza = 0;

            for(int i=0; i<nelementos; i++)
                varianza += pow((datos[i] - media),2);
            
            return varianza;
        }

        /**
         * @brief Metodo del template VD utilizado para obtener la desviación típica
         * @param varianza float cuyo valor debe de ser la varianza calculada mediante el metodo obtenerVarianza
         * @return float cuyo valor es la desviación tipica de los elementos del array
         */
        float obtenerDesviacion(float varianza){
            float desviacion = 0;

            if(varianza == 0){
                float varianza = obtenerVarianza();
            }

            return desviacion = sqrt(varianza/nelementos);

        }
};



#endif