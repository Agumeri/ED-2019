#include "recetas.h"
#include <string>
#include <map>
#include "color.h"
using namespace std;

/****************************************************************************/
//METODOS ITERATOR

bool recetas::iterator::operator!=(const recetas::iterator otro) const{
    return this->it != otro.it;
}

bool recetas::iterator::operator==(const recetas::iterator otro) const{
    return it == otro.it;
}

recetas::iterator& recetas::iterator::operator++(){
    ++it;
    
    return *this;
}

recetas::iterator& recetas::iterator::operator--(){
    --it;
    
    return *this;
}

receta& recetas::iterator::operator*(){
   return it->second;
}

/****************************************************************************/
//METODOS CONST_ITERATOR
bool recetas::const_iterator::operator!=(const recetas::const_iterator otro) const{
    return it->first != otro.it->first;
}

bool recetas::const_iterator::operator==(const recetas::const_iterator otro) const{
    return it->first == otro.it->first;
}

recetas::const_iterator& recetas::const_iterator::operator++(){
    ++it;
    
    return *this;
}

recetas::const_iterator& recetas::const_iterator::operator--(){
    --it;
    
    return *this;
}

receta recetas::const_iterator::operator*(){
        return it->second;
}
/****************************************************************************/

recetas::recetas(){
    datos.clear();
}

recetas::recetas(const map<string,receta> &otra){
    datos = otra;
}

recetas::recetas(const recetas& otra){
    this->datos=otra.datos;
}

recetas::~recetas(){
    datos.clear();
}

int recetas::size(){
    return datos.size();
}

void recetas::aniadir(receta &rec){
    string codigo = rec.getCode();
    pair<string,receta> par = {codigo,rec};
    datos.insert(par);
}

ostream& operator<<(ostream & os, recetas rec){
    recetas::iterator it;
    it = rec.begin();

    for(it = rec.begin(); it != rec.end(); ++it)
        os << KBLU << "CODE:" << KWHT << (*it).getCode() << KBLU << "       NOMBRE: " << KWHT << (*it).getNombre() << KBLU << "       PLATO: " << KWHT <<(*it).getPlato() << endl;

    return os;
}

istream& operator>>(istream&  is,recetas& rec){
    receta x;
    while(is.peek()!=EOF){
        is >> x;
        rec.aniadir(x);
    }
    return is;
}

receta recetas::operator[](const string &cod){
    map<string,receta>::iterator it=datos.find(cod);
        if (it!=datos.end())
        return (*((this->datos.insert(make_pair(cod,receta()))).first)).second;
    else {
        receta aux;
        aux.setNombre("Undefined");
        return aux;
    }
}

/*
receta recetas::operator[](const string &cod)const{
    map<string,receta>::const_iterator it=datos.find(cod);
    if (it!=datos.end())
        return (*((this->datos.insert(make_pair(cod,receta()))).first)).second;
    else{
        receta aux;
        aux.setNombre("Undefined");
        return aux;
    }
}
*/
void recetas::borrar(const string& rec){
    datos.erase(rec);
}

void recetas::clear(){
    datos.clear();
}

recetas recetas::maximizarCalorias(int num){
    recetas::iterator it;
    recetas::iterator it2;
    recetas aux;
    float auxraz= 0.0;
    float razonMax= -999.0;

    for(it=datos.begin(); it!=--datos.end(); ++it){
        for(it2=(++it); it2!=datos.end(); ++it2){
            auxraz=((*it).getProteinas()+(*it2).getProteinas())/((*it).getHC()+(*it2).getHC());
            if(auxraz <= num){
                    if(razonMax<auxraz){
                    aux.clear();
                    aux.aniadir((*it));
                    aux.aniadir((*it2));
                    razonMax=auxraz;
                    }
            }
            
        }
    }

    return aux;
}
