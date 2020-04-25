#include <iostream>
#include <list>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include "receta.h"
#include "Ingrediente.h"
#include "Ingredientes.h"
using namespace std;

//METODOS ITERATOR
/********************************************************************/
bool receta::iterator::operator!=(const iterator& otro) const {
    return it != otro.it;
}

bool receta::iterator::operator==(const iterator& otro) const{
    return it == otro.it;
}

receta::iterator & receta::iterator::operator++(){
    if(it != ptrings->end()){
        ++it;
    }

    return *this;
}

receta::iterator & receta::iterator::operator--(){
    if(it != ptrings->begin()){
        --it;
    }  
     
    return *this;
}

/***************************************************************************************/

pair<string,unsigned int> & receta::iterator::operator*(){
    return *it;
}

bool receta::const_iterator::operator!=(const const_iterator& otro) const {
    return it != otro.it;
}

bool receta::const_iterator::operator==(const const_iterator& otro) const{
    return it == otro.it;
}

receta::const_iterator & receta::const_iterator::operator++(){
    if(it != ptrings->end()){
        ++it;
    }

    return *this;
}

receta::const_iterator & receta::const_iterator::operator--(){
    if(it != ptrings->begin()){
        --it;
    }  
     
    return *this;
}

pair<string,unsigned int> receta::const_iterator::operator*(){
    return *(it);
}

/******************************************************************/
receta::receta(){
    code = "";
    plato = 0;
    nombre = "";
    calorias = 0.0;
    hc = 0.0;
    grasas = 0.0;
    proteinas = 0.0;
    fibra = 0.0;
}

receta::receta(string codigo, unsigned int plato, string nombre, list<pair<string, unsigned int>> ings){
    this->code = codigo;
    this->plato = plato;
    this->nombre = nombre;
    this->ings = ings;
}

receta::receta(const receta& otra){
    this->code = otra.code;
    this->plato = otra.plato;
    this->ings = otra.ings;
    this->nombre = otra.nombre;
    this->calorias = otra.calorias;
    this->hc = otra.hc;
    this->grasas = otra.grasas;
    this->proteinas = otra.proteinas;
    this->fibra = otra.fibra;
}

receta::~receta(){
    code = "";
    plato = -1;
    ings.resize(0);
    nombre = "";
    calorias = 0.0;
    hc = 0.0;
    grasas = 0.0;
    proteinas = 0.0;
    fibra = 0.0;
}

ostream& operator<<(ostream & os,receta ing){
    receta::iterator it;

    os << ing.getCode()
       << ";"  << ing.getPlato()
       << ";" << ing.getNombre() << ";";
       for(it = ing.begin(); it != ing.end(); ++it){
           os << (*it).first << "" << (*it).second << ";";
       }
       

    return os;
}

istream& operator>>(istream&  is, receta& ing){
    string cod, plat, ingr, nom, buf;
    char fin = ';'; 
    

    getline(is,cod,fin);
    getline(is,plat,fin);
    getline(is,nom,fin);

    list<pair<string,unsigned int>> lista;
    list<pair<string,unsigned int>>::iterator it;  

    string nombre, gramos;
    getline(is,buf,'\n');
   
    //cout << buf << endl;

    vector<string> cadenas_ingr;
    string cadena;
    istringstream flujocadenas(buf);
    while(getline(flujocadenas, cadena, ';')){
        cadenas_ingr.push_back(cadena);
        //cout << cadena << endl;
    }

    for(unsigned int i = 0; i < cadenas_ingr.size(); i++){
        for(unsigned int j = 0; j < cadenas_ingr[i].length(); j++){
            if(cadenas_ingr[i][j] >= '0' && cadenas_ingr[i][j] <= '9') {
                gramos += cadenas_ingr[i][j];
            }
            else
                nombre += cadenas_ingr[i][j];
        }
        //cout << nombre << ":" << gramos << " | " << i << endl;
        nombre.pop_back();
        lista.push_back({nombre,stoi(gramos)});

        gramos = "";
        nombre = "";
    }

    receta rec(cod,stoi(plat),nom,lista);
    ing = rec;
    return is;
    
}

/*
istream& operator>>(istream&  is, receta& ing){
    string cod, plat, ingr, nom;
    string name, gramos;
    char fin = ';';
    getline(is, cod, fin);
    getline(is, plat, fin);
    getline(is, nom, fin);
    
    list<pair<string,unsigned int>> lis;
    list<pair<string,unsigned int>>::iterator it;
    
    //lis.push_back({"",0});
    //it = lis.begin();
    getline(is,ingr);
        int i = 0;
        while(ingr[i] != ' '){
            name.push_back(ingr[i]);
            i++;
        }
    
        i++;
        while(i < ingr.size()){
            gramos.push_back(ingr[i]);
            i++;
        }
    lis.push_back({name,stoi(gramos)});
    
    ingr.clear();
    name.clear();
    gramos.clear();

    receta fich(cod,stoi(plat),nom,lis);

    ing = fich;

    return is;
    
}
*/


string receta::getCode(){
    return this->code;
}

unsigned int receta::getPlato(){
    return this->plato;
}

list<pair<string,unsigned int>> receta::getIngs(){
    return this->ings;
}

string receta::getNombre(){
    return this->nombre;
}

int receta::ningredientes(){
    return ings.size();
}

void receta::calcularNutrientes(Ingredientes &all_ingre){
    receta::iterator it;
    float calor = 0.0,
          hidratos = 0.0,
          prot = 0.0,
          gras = 0.0,
          fib = 0.0;

    for(it = this->begin(); it != this->end(); ++it){
        Ingrediente ingr = all_ingre.get( (*it).first );
        int gramos = (*it).second;
        
        calor += (ingr.getCalorias()*gramos*1.0)/100;
        hidratos += (ingr.getHc()*gramos*1.0)/100;
        prot += (ingr.getProteinas()*gramos*1.0)/100;
        gras += (ingr.getGrasas()*gramos*1.0)/100;
        fib += (ingr.getFibra()*gramos*1.0)/100;
    }
    

    this->calorias = calor;
    this->hc = hidratos;
    this->proteinas = prot;
    this->grasas = gras;
    this->fibra = fib;

    cout << endl;
}

float receta::getCalorias(){
    return this->calorias;
}

float receta::getHC(){
    return this->hc;
}

float receta::getGrasas(){
    return this->grasas;
}

float receta::getProteinas(){
    return this->proteinas;
}

float receta::getFibras(){
    return this->fibra;
}