#include <iostream>
#include <cmath>
#include "Ingredientes.h"

 
Ingredientes::Ingredientes():datos(0){}


Ingrediente Ingredientes::getIngrediente(int i){
    return datos[i];
}

int Ingredientes::size(){
    return this->datos.size();
}

Ingredientes Ingredientes::operator=(const Ingredientes &I){
    if(this!=&I){
        datos.resize(I.datos.size());
    }
    return *this;
}

Ingrediente Ingredientes::get(string n){
    for(int i=0; i<size(); i++){
        if(datos[i].getNombre()==n)
            return getIngrediente(i);
    }
}

void Ingredientes::borrarIngXPos(const int numIngrediente){
    datos.borrarElemento(numIngrediente);
}

void Ingredientes::borrar(const string &nombre){
    bool encontrado = false;
    int i=0;
    while(i<size() && !encontrado){
        if (getIngrediente(i).getNombre() == nombre){
            borrarIngXPos(i);
            encontrado = true;
        }
        i++;
    }
    
}


void Ingredientes::aniadir( Ingrediente &I){
    datos.aniadirElemento(I);
    this->ordenarPorNombre();

}

ostream& operator<<(ostream & os, const Ingredientes &I){
    
    for(int i=0; i < I.datos.size() ; ++i){
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


void Ingredientes::modificarIngrediente(int pos, const Ingrediente &x){
    datos.modificarElemento(pos, x);
}

void Ingredientes::ordenarPorNombre(){
    Ingrediente aux;

    for(int i=0; i<this->datos.size(); i++){
        for(int j=i+1; j<this->datos.size(); j++){
            if(this->getIngrediente(i).getNombre() > this->getIngrediente(j).getNombre()){
                aux = this->getIngrediente(i);
                this->datos[i] = this->datos[j];
                this->datos[j] = aux;
            }
        }
    }
}

Ingredientes Ingredientes::ordenarPorTipo(){
    Ingredientes x = *this;
    Ingrediente aux;
    for (int i = 0; i < this->datos.size(); i++)
        for (int j = i+1; j < this->datos.size() - 1; j++)
            if (x.getIngrediente(i).getTipo() > x.getIngrediente(j).getTipo()){
                aux = x.getIngrediente(i);
                x.modificarIngrediente(i, getIngrediente(j));
                x.modificarIngrediente(j, aux);
            }
    return x;
}

/*
Ingredientes Ingredientes::ordenarPorTipo(){
    Ingredientes x = *this;
    Ingrediente aux;
    for (int i = 1; i < this->datos.size(); i++)
        for (int j = 0; j < this->datos.size() - 1; j++)
            if (x.getIngrediente(j).getTipo() > x.getIngrediente(j + 1).getTipo()){
                aux = x.getIngrediente(j);
                x.modificarIngrediente(j, getIngrediente(j + 1));
                x.modificarIngrediente(j + 1, aux);
            }
    return x;
}
*/

Ingredientes Ingredientes::getIngredienteTipo(string tipo){
    Ingredientes tipos;

    for (int i = 0; i < datos.size(); i++){
        string cadena = datos[i].getTipo();
        //cout << "TIPO PREIF: "<< cadena << endl;
        if (cadena == tipo){
            //cout << this->datos[i].getTipo() << "ES IGUAL A VERDURA"<< endl;
            tipos.aniadir(this->datos[i]);
        }else{
            cout.flush();
            //cout << cadena << "Es diferente de: " << tipo<< endl;
        }
    }
    return tipos;
}

VD<string> Ingredientes::getTipos(){
    VD<string> tipos;
    bool encontrado = false;
    for (int i = 0; i < size(); i++){
        for (int j = 0; j < tipos.size() && !encontrado; j++){
            if (tipos[j] == datos[i].getTipo())
                encontrado = true;
        }
        if (!encontrado){
            if (!datos[i].getTipo().empty())
                tipos.aniadirElemento(datos[i].getTipo());
        }else{encontrado = false;}
    }
    return tipos;
}


//METODOS UTILIZADOS EN TIPOS_INGREDIENTES.CPP
VD<int> Ingredientes::obtenerCalorias(){
  VD<int> aux;
  for (int i = 0; i < this->datos.size(); i++) {
    aux.aniadirElemento(this->datos[i].getCalorias());
  }

  return aux;
}


VD<int> Ingredientes::obtenerHidratos(){
  VD<int> aux;
  for (int i = 0; i < this->datos.size(); i++) {
    aux.aniadirElemento(this->datos[i].getHc());
  }

  return aux;
}


VD<int> Ingredientes::obtenerProteinas(){
  VD<int> aux;
  for (int i = 0; i < this->datos.size(); i++) {
    aux.aniadirElemento(this->datos[i].getProteinas());
  }

  return aux;
}


VD<int> Ingredientes::obtenerGrasas(){
  VD<int> aux;
  for (int i = 0; i < this->datos.size(); i++) {
    aux.aniadirElemento(this->datos[i].getGrasas());
  }

  return aux;
}


VD<int> Ingredientes::obtenerFibra(){
  VD<int> aux;
  for (int i = 0; i < this->datos.size(); i++) {
    aux.aniadirElemento(this->datos[i].getFibra());
  }

  return aux;
}

//FUNCIONES PARA CALCULAR INGREDIENTE CON UN ATRIBUTO MAXIMO
//************************************************************************************
Ingrediente Ingredientes::ingrMaxCal(){
    Ingrediente aux = this->getIngrediente(0);

    for(int i=1; i<this->datos.size(); i++){
        if(aux.getCalorias() < this->datos[i].getCalorias()){
            aux = datos[i];
        }
    }

    return aux;
}

Ingrediente Ingredientes::ingrMaxHc(){
    Ingrediente aux = this->getIngrediente(0);

    for(int i=1; i<this->datos.size(); i++){
        if(aux.getHc() < this->datos[i].getHc()){
            aux = datos[i];
        }
    }

    return aux;
}

Ingrediente Ingredientes::ingrMaxPr(){
    Ingrediente aux = this->getIngrediente(0);

    for(int i=1; i<this->datos.size(); i++){
        if(aux.getProteinas() < this->datos[i].getProteinas()){
            aux = datos[i];
        }
    }

    return aux;
}

Ingrediente Ingredientes::ingrMaxGr(){
    Ingrediente aux = this->getIngrediente(0);

    for(int i=1; i<this->datos.size(); i++){
        if(aux.getGrasas() < this->datos[i].getGrasas()){
            aux = datos[i];
        }
    }

    return aux;
}

Ingrediente Ingredientes::ingrMaxFib(){
    Ingrediente aux = this->getIngrediente(0);

    for(int i=1; i<this->datos.size(); i++){
        if(aux.getFibra() < this->datos[i].getFibra()){
            aux = datos[i];
        }
    }

    return aux;
}

//****************************************************************************
//FUNCIONES PARA CALCULAR UN INGREDIENTE CON UN ATRIBUTO MINIMO
Ingrediente Ingredientes::ingrMinCal(){
    Ingrediente aux = this->getIngrediente(0);

    for(int i=1; i<this->datos.size(); i++){
        if(aux.getCalorias() > this->datos[i].getCalorias()){
            aux = datos[i];
        }
    }

    return aux;
}
Ingrediente Ingredientes::ingrMinHc(){
    Ingrediente aux = this->getIngrediente(0);

    for(int i=1; i<this->datos.size(); i++){
        if(aux.getHc() > this->datos[i].getHc()){
            aux = datos[i];
        }
    }

    return aux;
}
Ingrediente Ingredientes::ingrMinPr(){
    Ingrediente aux = this->getIngrediente(0);

    for(int i=1; i<this->datos.size(); i++){
        if(aux.getProteinas() > this->datos[i].getProteinas()){
            aux = datos[i];
        }
    }

    return aux;
}
Ingrediente Ingredientes::ingrMinGr(){
    Ingrediente aux = this->getIngrediente(0);

    for(int i=1; i<this->datos.size(); i++){
        if(aux.getGrasas() > this->datos[i].getGrasas()){
            aux = datos[i];
        }
    }

    return aux;
}
Ingrediente Ingredientes::ingrMinFib(){
    Ingrediente aux = this->getIngrediente(0);

    for(int i=1; i<this->datos.size(); i++){
        if(aux.getFibra() > this->datos[i].getFibra()){
            aux = datos[i];
        }
    }

    return aux;
}

//***************************************************************