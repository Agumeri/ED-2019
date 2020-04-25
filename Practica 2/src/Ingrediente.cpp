#include <iostream>
#include <cmath>
#include <string>
#include "Ingrediente.h"

using namespace std;

Ingrediente::Ingrediente(){
    name          = "";
    num_cal       = 0;
    prc_hidratos  = 0;
    prc_proteinas = 0;
    prc_grasas    = 0;
    prc_fibra     = 0;
    tipo          = "";
}

Ingrediente::Ingrediente(string name, int num_cal, int prc_hidratos, int prc_proteinas, int prc_grasas, int prc_fibra, string tipo){
    this->name = name;
    this->num_cal = num_cal;
    this->prc_hidratos = prc_hidratos;
    this->prc_proteinas = prc_proteinas;
    this->prc_grasas = prc_grasas;
    this->prc_fibra = prc_fibra;
    this->tipo = tipo;
}

Ingrediente::Ingrediente(const Ingrediente& otro){
    this->name = otro.name;
    this->num_cal = otro.num_cal;
    this->prc_hidratos = otro.prc_hidratos;
    this->prc_proteinas = otro.prc_proteinas;
    this->prc_grasas = otro.prc_grasas;
    this->prc_fibra = otro.prc_fibra;
    this->tipo = otro.tipo;
}

Ingrediente::~Ingrediente(){
    name          = "";
    num_cal       = 0;
    prc_hidratos  = 0;
    prc_proteinas = 0;
    prc_grasas    = 0;
    prc_fibra     = 0;
    tipo          = "";
}

ostream& operator<< (ostream &os, const Ingrediente & I){
    return os << "\nNombre: " << I.name 
              << "\nCalorias: " << I.num_cal 
              << "\nHc: " << I.prc_hidratos 
              << "\nProteinas: " << I.prc_proteinas
              << "\nGrasas: " << I.prc_grasas 
              << "\nFibra: " << I.prc_fibra 
              << "\nTipo: " <<I.tipo << endl;
    
}

istream &operator>>(istream &is, Ingrediente &I){
    string nom, tip, cal, hc, pro, gra, fib;
    char fin = ';';
    //Pillo elemento a elemento
    getline(is, nom, fin);
    getline(is, cal, fin);
    getline(is, hc , fin);
    getline(is, pro, fin);
    getline(is, gra, fin);
    getline(is, fib, fin);
    getline(is, tip);

    //Lo paso de string a entero con stoi y se lo paso a this
    Ingrediente fich(nom, stoi(cal), stoi(hc), stoi(pro), stoi(gra), stoi(fib), tip);
    I = fich;

    return is;
}


string Ingrediente::getNombre(){
    return this->name;
}

int Ingrediente::getCalorias(){
    return this->num_cal;
}

int Ingrediente::getHc(){
    return this->prc_hidratos;
}

int Ingrediente::getProteinas(){
    return this->prc_proteinas;
}

int Ingrediente::getGrasas(){
    return this->prc_grasas;
}

int Ingrediente::getFibra(){
    return this->prc_fibra;
}

string Ingrediente::getTipo(){
    return this->tipo;
}
