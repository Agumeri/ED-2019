#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include "acciones.h"
#include "arbolbinario.h"
#include "instrucciones.h"
#include "Ingredientes.h"
#include "recetas.h"
#include "color.h"
using namespace std;

instrucciones::instrucciones(){
    datos.clear();
    acc.clear();
}


instrucciones::instrucciones(const ArbolBinario<string> &otro, const acciones &accion){
    datos = otro;
    acc = accion;
}

instrucciones::instrucciones(const instrucciones& otras){
    *this = otras;
}

instrucciones::~instrucciones(){
    datos.clear();
    acc.clear();
}

void instrucciones::aniadir_acciones(acciones fichero_acciones){
    acciones::iterator it;
    it = fichero_acciones.begin();

    while(it != fichero_acciones.end()){
        acc.aniadir((*it));
        ++it;
    }

}

pair<bool,char> instrucciones::esAccion(const string &accion){
    bool es_Accion = false;
    char res = ' ';
    pair<bool,char> par;
    acciones::iterator it = this->acc.begin();

    while(it != this->acc.end() && !es_Accion){
        if( accion == (*it).first){
            es_Accion = true;
            res = (*it).second;
        }
        ++it;
    }

    par = {es_Accion,res};
    return par;

}

ostream& operator<<(ostream& os, instrucciones inst){
    string ingg, ingg_anterior = "";
    char ariedad; 
    for (ArbolBinario<string>::postorden_iterador it= inst.datos.beginpostorden(); it!=inst.datos.endpostorden(); ++it){
        if(inst.esAccion(*it).first){
            ariedad = inst.esAccion(*it).second;
            if(ariedad == '1'){
                if(ingg == ingg_anterior){
                    os << *it << endl;
                }else{
                    os << *it << " " << ingg << endl;
                    ingg_anterior = ingg;
                }
            }else if(ariedad == '2'){
                if(*it == "Add")
                    os << *it << " " << ingg << endl;
                else
                    os << *it << endl;
                
                
            }
        }else{
            ingg = *it;
        }
    }

    //inst.datos.RecorridoPostOrden(os);
    return os;
}


istream& operator>>(istream& is, instrucciones &inst){
    //stack<ArbolBinario<string>> s;
    stack<ArbolBinario<string>> pila_arboles;
    string linea;
    while(is.peek()!=EOF){
        getline(is,linea,'\n');
        string action;
        string ingg;
        bool fin = false;
        for(unsigned int i=0; i<linea.size() && !fin; i++){
            if(linea[i]!=' '){
                action+=linea[i];
            }else{
                for(unsigned int j=i+1; j<linea.size(); j++){
                    ingg+=linea[j];
                }
                fin=true;
            }  
        }
        if(ingg!=""){
            ArbolBinario<string> aux1(ingg);
            pila_arboles.push(aux1);
        }

        ArbolBinario<string> aux2(action);    

        acciones::iterator it;
        char num ;
        bool enc = false;
        for(it = inst.acc.begin(); it != inst.acc.end() && !enc; ++it){
            
            if( action == (*it).first ){
                num = (*it).second;
                enc = true;
            }
        }

        if(num == '1'){
            ArbolBinario<string> arbol(action);                        
            arbol.Insertar_Hd(arbol.getRaiz(), pila_arboles.top());    
            pila_arboles.pop();
            pila_arboles.push(arbol);

        }else if(num == '2'){
            ArbolBinario<string> raiz(action);
            ArbolBinario<string> arbol_derecha(pila_arboles.top());     
            pila_arboles.pop();
            ArbolBinario<string> arbol_izquierda(pila_arboles.top());   
            pila_arboles.pop();              
            
            

            raiz.Insertar_Hi(raiz.getRaiz(), arbol_izquierda);
            raiz.Insertar_Hd(raiz.getRaiz(), arbol_derecha);

            pila_arboles.push(raiz);
        }

        ingg="";
        action="";
        fin = false;
        enc = false;

    }

    ArbolBinario<string> aux = pila_arboles.top();
    inst.datos = aux;

    return is;
}

ArbolBinario<string> instrucciones::getArbol(){
    return this->datos;
}

void instrucciones::calcularInstruccionesFusion(instrucciones i1,instrucciones i2){
    ArbolBinario<string> raiz("Acompañar");
    ArbolBinario<string> rama1 = i1.getArbol(), 
                         rama2 = i2.getArbol();

    raiz.Insertar_Hd(raiz.getRaiz(), rama2);
    raiz.Insertar_Hi(raiz.getRaiz(), rama1);
    

    this->datos = raiz;
}
/*
        Acompañar
        /      \
       I1       I2
*/