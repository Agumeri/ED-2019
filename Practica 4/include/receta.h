/**
 *  @brief TDA Receta
 * 
 * Una instancia @e c del tipo de datos abstracto @c Receta es un objeto
 * compuesto un string que referencia a la receta que es, un unsigned int que 
 * indica si el plato es primero, segundo, tercero...., una lista compuesta por
 * pair<string, unsigned int>> donde string referencia a un ingrediente, e int la
 * cantidad en gramos de ese ingrediente, y un nombre referenciando al de la receta.
 * Además, hay un float para calorias, hc, grasas, proteinas y fibra que referencian la media
 * poderada de estos atributos según el tipo de ingrediente. 
 *
 * Un ejemplo de uso:
 * @include receta.h
 * 
 * @autor Agustín Mérida Gutiérrez
 * @autor Eduardo Bárez Navarro
 * @date Diciembre 2019
 */
#ifndef RECETA_H
#define RECETA_H
#include <iostream>
#include <string>
#include <list>
#include "Ingrediente.h"
#include "Ingredientes.h"
using namespace std;

class receta{
    private:
        string code;    //Codigo con el que se referencia la receta
        unsigned int plato; //Tipo de plato (primero, segundo, postre...)
        list<pair<string,unsigned int> > ings; //Nombre ingrediente , cantidad en gramos

        string nombre;  //Nombre de la receta

        //Datos para mantener el total de todos los ingredientes
        float calorias,
              hc,
              grasas,
              proteinas,
              fibra;

    public:

        //CLASE ITERATOR Y METODOS DE CLASE
        /***************************************************************************************/
        
        class iterator{
            private:
                list<pair<string,unsigned int> >::iterator it;
                list<pair<string,unsigned int>> * ptrings;
            public:
                /**
                 * @brief Constructor de un nuevo objeto iterator
                 * @return inicializa a 0 el valor it
                 */
                iterator():it(0){}

                /**
                 * @brief Constructor por parámetros de un nuevo objeto iterator
                 * @param ite que es una referencia a un iterador de la lista list<pair<string,unsigned int> >
                 * @return el iterador it pasa a tener el valor de ite
                 */
                iterator(const list<pair<string,unsigned int> >::iterator& ite): it(ite){}

                /**
                 * @brief Constructor por copia de un nuevo objeto iterator
                 * @param i que es una referencia de un objeto iterator
                 * @return it obtiene el valor del it del objeto i
                 */
                iterator(const iterator& i):it(i.it){}

                /**
                 * @brief Destructor del objeto iterator
                 * @return Se ponen todos los atributos de iterator a estado inicial (0) 
                 */
                ~iterator(){};

                /**
                 * @brief Función incrimento de iterator
                 * @return iterator aumenta una unidad
                 */
                iterator& operator++();// {++it; return *this;}

                /**
                 * @brief Funcion decremento de iterator
                 * @return iterator disminuye una unidad
                 */
                iterator& operator--();// {--it; return *this;}

                /**
                 * @brief Operador de comparacion de iterator
                 * @param otro es un objeto iterator
                 * @return true si los dos objetos tienen el mismo valor
                 * @return false si los dos objetos tienen diferente valor
                 */
                bool operator==(const iterator& otro) const;

                /**
                 * @brief Operador de comparacion de iterator
                 * @param otro es un objeto iterator
                 * @return true si los dos objetos son distintos
                 * @return false si los dos objetos tiene el mismo valor
                 */
                bool operator!=(const iterator& otro) const;

                /**
                 * @brief Operador de puntero
                 * @return pair<string,unsigned int>& correspondiente a la posición a la que apunta it
                 */
                pair<string,unsigned int> & operator*();

                friend class receta;
        };  

        /**
         * @brief Metodo begin de la clase iterator de receta
         * 
         * @return iterator de receta que referencia al principio de la lista de ingrediente|nºgramos
         */
        iterator begin(){
            iterator i;
            i.it = ings.begin();
            i.ptrings = &ings;
            return i;
        }
        
        /**
         * @brief Metodo end de la clase iterator de receta
         * @return iterator de receta que referencia al final de la lista de ingrediente|nºgramos
         */
        iterator end(){
            iterator i;
            i.it = ings.end();
            i.ptrings = &ings;
            return i;
        }

        class const_iterator{
            private:
                list<pair<string,unsigned int> >::const_iterator it;
                list<pair<string,unsigned int>> * ptrings;
            public:
                /**
                 * @brief Constructor de un nuevo objeto iterator
                 * @return inicializa a 0 el valor it
                 */
                const_iterator():it(0){}

                /**
                 * @brief Constructor de un nuevo objeto iterator
                 * @param ite que es una referencia a un iterador de la lista list<pair<string,unsigned int> >
                 * @return el iterador it pasa a tener el valor de ite
                 */
                const_iterator(const list<pair<string,unsigned int> >::const_iterator& ite): it(ite){}

                /**
                 * @brief Constructor de un nuevo objeto iterator
                 * @param i que es una referencia de un objeto iterator
                 * @return it obtiene el valor del it del objeto i
                 */
                const_iterator(const const_iterator& i):it(i.it){}

                /**
                 * @brief Destructor del objeto iterator
                 * @return Se ponen todos los atributos de iterator a estado inicial (0) 
                 */
                ~const_iterator(){};

                /**
                 * @brief Función incrimento de iterator
                 * @return iterator& se le aumenta una unidad
                 */
                const_iterator& operator++();// {++it; return *this;}

                /**
                 * @brief Funcion decremento de iterator
                 * @return iterator& se le quita una unidad
                 */
                const_iterator& operator--();// {--it; return *this;}

                /**
                 * @brief Operador de comparacion de iterator
                 * @param otro es un objeto iterator
                 * @return true si los dos objetos tienen el mismo valor
                 * @return false si los dos objetos tienen diferente valor
                 */
                bool operator==(const const_iterator& otro) const;

                /**
                 * @brief Operador de comparacion de iterator
                 * @param otro es un objeto iterator
                 * @return true si los dos objetos son distintos
                 * @return false si los dos objetos tiene el mismo valor
                 */
                bool operator!=(const const_iterator& otro) const;

                /**
                 * @brief Operador de puntero
                 * @return pair<string,unsigned int>& correspondiente a la posición a la que apunta it
                 */
                pair<string,unsigned int> operator*();

                friend class receta;
        };    

        /**
         * @brief Metodo begin de la clase iterator
         * @return iterator de recetas que referencia al inicio de la lista
         */
        const_iterator cbegin(){
            const_iterator i;
            i.it = ings.begin();
            i.ptrings = &ings;
            return i;
        }
        
        /**
         * @brief Metodo end de la clase iterator
         * @return iterator de recetas que referencia al final de la lista 
         */
        const_iterator cend(){
            const_iterator i;
            i.it = ings.end();
            i.ptrings = &ings;
            return i;
        }
        /***************************************************************************************/
        
        /**
         * @brief Constructor de un nuevo objeto de receta
         * @return Crea un nuevo objeto receta vacío
         */
        receta();

        /**
         * @brief Constructor por parámetros de un nuevo objeto de receta
         * @param codigo string indicando el codigo de la receta
         * @param plato unsigned int indicando el orden del plato
         * @param nombre string indicando el nombre de la receta
         * @param ings list<pair<string, unsigned int>> que indica una lista de ingredientes y los gramos de cada uno
         * @return Crea un nuevo objeto receta donde el valor de sus atributos es el de los parámetros que se le han pasado
         */
        receta(string codigo, unsigned int plato, string nombre, list<pair<string, unsigned int>> ings);
        
        /**
         * @brief Constructor por copia de un nuevo objeto de receta
         * @param otra referencia a un objeto receta
         * @return el objeto que llama a este constructor obtiene los parametros de otra
         */
        receta(const receta& otra);
        
        /**
         * @brief Destructor del objeto receta
         * @return Los parámetros del objeto receta se ponen en estado inicial
         */
        ~receta();
        

        /**
         * @brief Metodo de salida de receta
         * 
         * @param os flujo de salida 
         * @param ing objeto receta
         * @return ostream cuyo valor es el de receta
         */
        friend ostream& operator<<(ostream & os, receta rec);

        /**
         * @brief Metodo de salida de receta
         * 
         * @param is flujo de salida 
         * @param ing objeto receta
         * @return istream cuyo valor es lo que se ha leido por pantalla y se almacena correctamente en ing
         */
        friend istream& operator>>(istream&  is,receta& rec);

        /**
         * @brief Metodo getter del atributo Code de receta
         * 
         * @return string 
         */
        string getCode();

        /**
         * @brief Metodo getter del atributo plato de receta
         * 
         * @return unsigned int 
         */
        unsigned int getPlato();

        /**
         * @brief Metodo getter del atributo ings de receta
         * 
         * @return list<pair<string,unsigned int>> 
         */
        list<pair<string,unsigned int>> getIngs();

        /**
         * @brief Metodo getter del atributo nombre de receta
         * 
         * @return string 
         */
        string getNombre();

        /**
         * @brief Metodo getter del atributo calorias de receta
         * 
         * @return float 
         */
        float getCalorias();

        /**
         * @brief Metodo getter del atributo hc de receta
         * 
         * @return float 
         */
        float getHC();

        /**
         * @brief Metodo getter del atributo proteinas de receta
         * 
         * @return float 
         */
        float getProteinas();

        /**
         * @brief Metodo getter del atributo grasas de receta
         * 
         * @return float 
         */
        float getGrasas();
        
        /**
         * @brief Metodo getter del atributo fibras de receta
         * 
         * @return float 
         */
        float getFibras();

        /**
         * @brief Metodo getter de receta
         * @return int cuyo valor indica cuantos ingredientes tiene la receta
         */
        int ningredientes();
        
        /**
         * @brief Metodo de la clase receta utilizado para calcular todos los nutrientes de una receta
         * @param all_ingre que tiene como valor todos los ingredientes disponibles (obtenidos del archivo ingredientes.txt)
         * @return Los nutrientes de la receta son actualizados con el valor que les corresponde tras realizar el calculo
         */
        void calcularNutrientes(Ingredientes &all_ingre);

        /**
         * @brief Metodo set del objeto de la clase receta
         * @param nuevo_nombre string con un nombre nuevo
         * @return el nombre de la receta pasa a ser el string nuevo_nombre
         */
        void setNombre(string nuevo_nombre);

        /**
         * @brief Metodo set del objeto de la clase receta
         * @param nuevo_code string con un codigo nuevo
         * @return el codigo de la receta pasa a ser el string nuevo_code
         */
        void setCode(string nuevo_code);

        /**
         * @brief Metodo set del objeto de la clase receta
         * @param num_plato string con el nuevo numero de plato
         * @return el numero de plato de la receta pasa a ser el unsigned int num_plato
         */
        void setPlato(unsigned int num_plato);

        /**
         * @brief Metodo set del objeto de la clase receta
         * @param lista list<pair<string,unsigned int>>  con la nueva lista de ingredientes
         * @return la lista de ingredientes de la receta pasa a ser a tener el valor del list lista
         */
        void setIngredientes(list<pair<string,unsigned int>> lista);
    
        /**
         * @brief Metodo encargado de fusionar dos recetas en una
         * @param r1 primer objeto receta de la fusion
         * @param r2 segundo objeto receta de la fusion
         * @return la receta que llame a esta funcion fusionara las dos recetas situadas en los parametros, suponiendo esto
         *         la suma de todos sus atributos (nuevo nombre, nuevo codigo, mismo numero de plato y unión de la lista de ingredientes de ambos)
         */
        void fusionarRecetas(receta r1, receta r2);

        /**
         * @brief Metodo encargado de comprobar si un ingrediente está incluido en un objeto Ingredientes
         * @param otros objeto Ingredientes usado para la comparación
         * @return true significa que el objeto ingrediente está incluido en el objeto Ingredientes otros
         * @return false significa que el objeto ingrediente no está incluido en el objeto Ingredientes otros
         */
        bool esValido(Ingredientes otros);
};//end receta

#endif