/**
 *  @brief TDA Recetas
 * 
 * Una instancia @e c del tipo de datos abstracto @c recetas esta compuesto por
 * un map<string,receta> donde la key string tendrá el valor del codigo de la receta,
 * y receta será el objeto de la clase receta con todos sus datos
 *
 * Un ejemplo de uso:
 * @include recetas.h
 * 
 * @autor Agustín Mérida Gutiérrez
 * @autor Eduardo Bárez Navarro
 * @date Noviembre 2019
 */

#ifndef RECETAS_H
#define RECETAS_H
#include <iostream>
#include <map>
#include <string>
#include "receta.h"
using namespace std;

class recetas{
    private:
        map<string,receta> datos;

    public: 
        

        /***********************************************************************************/
        //CLASE ITERATOR DE RECETAS
        class iterator{
            private:
                map<string,receta>::iterator it;

            public:

                /**
                 * @brief Constructor de un nuevo objeto iterator
                 * @return inicializa a 0 el valor it y a "" el valor de pos
                 */
                iterator():it(0){};

                /**
                 * @brief Construct a new iterator object
                 * @param otro que es una referencia a un iterador de map<string,receta>
                 * @param ocad que es una referencia a un string
                 * @return el iterador it pasa a tener el valor de otro y pos el valor del string pos
                 */
                iterator(const map<string,receta>::iterator &otro):it(otro){}
                
                /**
                 * @brief Constructor por copia de un nuevo objeto iterator
                 * @param iter que es una referencia de un objeto iterator
                 * @return it obtiene el valor del it del objeto iter y pos el del pos de iter
                 */
                iterator(const iterator& iter): it(iter.it){};
                
                /**
                 * @brief Destructor del objeto iterator
                 * @return Se ponen todos los atributos de iterator a estado inicial (0) 
                 */
                ~iterator(){};

                /**
                 * @brief Operador de comparacion de iterator
                 * @param otro es un objeto iterator
                 * @return true si los dos objetos son distintos
                 * @return false si los dos objetos tiene el mismo valor
                 */
                bool operator!=(const iterator otro) const;

                /**
                 * @brief Operador de comparacion de iterator
                 * @param otro es un objeto iterator
                 * @return true si los dos objetos tienen el mismo valor
                 * @return false si los dos objetos tienen diferente valor
                 */
                bool operator==(const iterator otro) const;

                /**
                 * @brief Función incrimento de iterator
                 * @return iterator aumenta una unidad
                 */
                iterator& operator++();

                /**
                 * @brief Funcion decremento de iterator
                 * @return iterator disminuye una unidad
                 */
                iterator& operator--();

                /**
                 * @brief Operador de puntero
                 * @return receta asociada a una clave del map datos
                 */
                receta& operator*();

            friend class recetas;
        };

        /**
         * @brief Metodo begin de la clase iterator de recetas
         * @return iterator de recetas que referencia al principio del map
         */
        iterator begin(){
            iterator it;
            it.it = datos.begin();
            return it;
        }

        /**
         * @brief Metodo end de la clase iterator de recetas
         * @return iterator de recetas que referencia al final del map
         */
        iterator end(){
            iterator it;
            it.it = datos.end();
            return it;
        }


        /****************************************************************************/
        //CLASE CONST_ITERATOR DE RECETAS
        class const_iterator{
            private:
                map<string,receta>::const_iterator it;

            public:
                /**
                 * @brief Constructor de un nuevo objeto const_iterator
                 * @return inicializa a 0 el valor it y a "" el valor de pos
                 */
                const_iterator():it(0){};
                
                /**
                 * @brief Constructor por parámetros del objecto const_iterator
                 * @param otro que es una referencia a un const_iterador de map<string,receta>
                 * @param ocad que es una referencia a un string
                 * @return el iterador it pasa a tener el valor de otro y pos el valor del string pos
                 */
                const_iterator(const map<string,receta>::const_iterator &otro):it(otro){}
                
                /**
                 * @brief Constructor por copia de un nuevo objeto const_iterator
                 * @param iter que es una referencia de un objeto const_iterator
                 * @return it obtiene el valor del it del objeto iter y pos el del pos de iter
                 */
                const_iterator(const const_iterator& iter): it(iter.it){};
                
                /**
                 * @brief Destructor del objeto iterator
                 * @return Se ponen todos los atributos de iterator a estado inicial (0) 
                 */
                ~const_iterator(){};

                /**
                 * @brief Operador de comparacion de iterator
                 * @param otro es un objeto const_iterator
                 * @return true si los dos objetos son distintos
                 * @return false si los dos objetos tiene el mismo valor
                 */
                bool operator!=(const const_iterator otro) const;

                /**
                 * @brief Operador de comparacion de iterator
                 * @param otro es un objeto const_iterator
                 * @return true si los dos objetos tienen el mismo valor
                 * @return false si los dos objetos tienen diferente valor
                 */
                bool operator==(const const_iterator otro) const;

                /**
                 * @brief Función incrimento de const_iterator
                 * @return const_iterator aumenta una unidad
                 */
                const_iterator& operator++();

                /**
                 * @brief Funcion decremento de iterator
                 * @return iterator disminuye una unidad
                 */
                const_iterator& operator--();

                /**
                 * @brief Operador de puntero
                 * @return receta asociada a una clave del map datos
                 */
                receta operator*();

            friend class recetas;

        };

        /**
         * @brief Metodo begin de la clase const_iterator de recetas
         * @return const_iterator de recetas que referencia al principio del map
         */
        const_iterator cbegin() {
            const_iterator it;
            it.it = datos.cbegin();
            return it;
        }

        /**
         * @brief Metodo end de la clase const_iterator de recetas
         * @return const_iterator de recetas que referencia al final del map
         */
        const_iterator cend() {
            const_iterator it;
            it.it = datos.cend();
            return it;
        }

        /****************************************************************************/

        /**
         * @brief Constructor de un nuevo objeto de recetas
         * @return Crea un nuevo objeto recetas vacío
         */
        recetas();

        /**
         * @brief Construct por parametros de un nuevo objeto de recetas
         * @param otra map<string,receta> que indica un map con contenido
         * @return Crea un nuevo objeto recetas cuyo map tiene el valor de otra
         */
        recetas(const map<string,receta> &otra);

        /**
         * @brief Constructor por copia de un nuevo objeto de recetas
         * @param otra referencia a un objeto recetas
         * @return el objeto que llama a este constructor obtiene los parametros de otra
         */
        recetas(const recetas &otra);

        /**
         * @brief Destructor del objeto recetas
         * @return Los parámetros del objeto recetas se ponen en estado inicial
         */
        ~recetas();

        /**
         * @brief Metodo getter de recetas
         * @return int cuyo valor indica el numero de recetas que hay en total
         */
        int size();

        /**
         * @brief Metodo que añade una receta al map
         * @param rec objeto receta
         * @return Se le añade al map datos uun objeto receta en su correspondiente posicion
         */
        void aniadir(receta &rec);

        /**
         * @brief Metodo de salida de recetas
         * 
         * @param os flujo de salida 
         * @param ing objeto recetas
         * @return ostream cuyo valor es el de todas las recetas almacenadas en recetas
         */
        friend ostream& operator<<(ostream & os,recetas rec);

        /**
         * @brief Metodo de salida de recetas
         * 
         * @param is flujo de salida 
         * @param ing objeto receta
         * @return istream cuyo valor es lo que se ha leido por pantalla y se almacena correctamente en ing
         */
        friend istream& operator>>(istream&  is,recetas& rec);

        /**
         * @brief Operador de acceso de recetas
         * @param s string que referencia a una key del map datos
         * @return receta asociada a la key s
         */
        receta operator[](const string& s);

        /**
         * @brief Metodo borrar de recetas
         * @param rec string que referencia a una key del map datos
         * @return datos ahora tiene un elemento menos, que es el asociado al key rec
         */
        void borrar(const string& rec);

        /**
         * @brief Metodo del objeto recetas para maximizar dos objetos recetas
         * @param num, el numero calorias maxima
         * @return receta, devuelve la receta maximizada a razon de proteinas e hidratos de carbono
         */
        recetas maximizarCalorias(int num);
        /**
         * @brief Metodo del objeto recetas para eliminar su contenido
         * @return El objeto datos ha sido vaciado
         */
        void clear();

};//end recetas

#endif