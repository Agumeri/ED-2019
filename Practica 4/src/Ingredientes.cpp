#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Ingrediente.h"
#include "Ingredientes.h"
using namespace std;


//CLASE ITERADOR
//************************************************************************
//Ingredientes::iterator::iterator(){
//    ptrdatos = nullptr;
//    pos = 0;
//}

bool Ingredientes::iterator::operator!=(const iterator& otro) const {
    return it != otro.it;
}

bool Ingredientes::iterator::operator==(const iterator& otro) const{
    return it == otro.it;
}

Ingredientes::iterator & Ingredientes::iterator::operator++(){
    ++it;
    return *this;
}

Ingredientes::iterator & Ingredientes::iterator::operator--(){
    --it;   
    return *this;
}

Ingrediente & Ingredientes::iterator::operator*(){
    return *it;
}
//*****************************************************************************

void Ingredientes::aniadir(Ingrediente& ing){
    bool encontrado=false;
    for(unsigned int i=0; i<datos.size()&& !encontrado; ++i){
        if(ing.getNombre()<datos[i].getNombre()){
            datos.insert(datos.begin()+i, ing);
            encontrado=true;
        }
    }
    if(!encontrado){
        datos.push_back(ing);
    }
}

/*
void Ingredientes::aniadir( Ingrediente& I){
    Ingredientes::iterator it;
    for(it=datos.begin(); it != datos.end; ++it){
        if(I.getNombre() > (*it).getNombre()){
            it = datos.insert(it,I);
        }
    }
}
*/


Ingredientes Ingredientes::operator=(const Ingredientes &I){
    if(this!=&I){
        datos.resize(I.datos.size());
    }
    return *this;
}


ostream& operator<<(ostream & os, const Ingredientes &I){
    
    for(unsigned int i=0; i < I.datos.size() ; ++i){
        os <<  I.datos[i];
        
    }

    return os;
}

istream& operator>>(istream&  is, Ingredientes& I){
    Ingrediente aux;

    //Primera linea que da error
    string linea;
    getline(is,linea);

    while (is.peek() != EOF){
        is >> aux;
        I.aniadir(aux);
    }
    return is;
}

void Ingredientes::ImprimirPorTipo(ostream &os){
    Ingredientes aux = ordenarPorTipo();
    os << aux;
}

Ingredientes Ingredientes::ordenarPorTipo(){
    for (unsigned int i = 0; i < this->datos.size(); i++){
        for (unsigned int j = i+1; j < this->datos.size(); j++){
            if(datos[i].getTipo() > datos[j].getTipo()){
                swap(datos[i],datos[j]);
            }
        }
    }
    return *this;
}

Ingrediente Ingredientes::get(string n){
    Ingredientes::iterator it;
    Ingrediente res;
    for(it = datos.begin(); it != datos.end(); ++it){
        if((*it).getNombre() == n)
            res = (*it);
    }

    return res;
}

void Ingredientes::borrar(const string &nombre){
    bool encontrado = false;

    for(unsigned int i=0; i<datos.size() && !encontrado; i++){
        if(datos[i].getNombre() == nombre){
            while(i < datos.size()){
                datos[i] = datos[i+1];
                i++;
            }
            encontrado = true;
        }
    }

    datos.pop_back();
}

vector<string> Ingredientes::getTipos(){
    vector<string> tipos;
    bool encontrado = false;
    for (unsigned int i=0; i<datos.size(); i++){
        for(unsigned int j=0; j<tipos.size() && !encontrado; j++){
            if(tipos[j] == datos[i].getTipo())
                encontrado = true;
        }
        if(!encontrado){
            if(!datos[i].getTipo().empty())
                tipos.push_back(datos[i].getTipo());
        }else{
            encontrado = false;
        };
    }

    return tipos;
}

Ingredientes Ingredientes::getIngredienteTipo(string tipo){
    Ingredientes tipos;

    for(unsigned int i=0; i<datos.size(); i++){
        string cadena = datos[i].getTipo();
        if(cadena == tipo){
            tipos.aniadir(this->datos[i]);
        }else{
            cout.flush();
        }
    }

    return tipos;
}