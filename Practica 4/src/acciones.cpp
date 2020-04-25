#include <iostream>
#include <map>
#include <stack>
#include "acciones.h"
#include "color.h"
using namespace std;

acciones::acciones(){
    datos.clear();
}

acciones::acciones(const map<string,unsigned char>& otro){
    this->datos = otro;
}

acciones::acciones(const acciones& otro){
    this->datos = otro.datos;
}

acciones::~acciones(){
    datos.clear();
}

ostream& operator<<(ostream& os, acciones acc){
    map<string,unsigned char>::iterator it;
    for(it = acc.datos.begin(); it != acc.datos.end(); ++it){
        os << KBLU << (*it).first << " " << (*it).second << endl;
    }

    return os;
}

/****************************************************************************/
//METODOS ITERATOR

bool acciones::iterator::operator!=(const acciones::iterator& otro) const{
    return this->it != otro.it;
}

bool acciones::iterator::operator==(const acciones::iterator& otro) const{
    return it == otro.it;
}

acciones::iterator& acciones::iterator::operator++(){
    ++it;
    
    return *this;
}

acciones::iterator& acciones::iterator::operator--(){
    --it;
    
    return *this;
}

pair<string, unsigned char> acciones::iterator::operator*()const{
   return (*it);
}

/****************************************************************************/

//mezclar 1
//cortar 2
istream& operator>>(istream& is, acciones &acc){
    string linea;
    pair<string,unsigned char> par;
    string palabra="";
    char num;

    
    while(is.peek() != EOF){
        getline(is,linea,'\n');
        for(unsigned int i = 0; i<linea.size()-1; i++){
            if(linea[i] != ' '){
                palabra += linea[i];
            }else{
                num = linea[i+1];
                i = linea.size()-1;
            }
        }
        par = {palabra,num};
        palabra="";
        acc.aniadir(par);
    }

    return is;
}

void acciones::aniadir(pair<string,unsigned char> pareja){
    datos.insert(pareja);
}

void acciones::clear(){
    datos.clear();
}
