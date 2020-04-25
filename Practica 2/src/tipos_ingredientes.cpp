#include <iostream>
#include <string>
#include "Ingrediente.h"
#include "Ingredientes.h"
#include <fstream>
#include <VD.hpp>
#include <stdlib.h>
using namespace std;

void MuestraParametros(){
	
	cout<<"1.- Dime el nombre del fichero con los ingredientes"<<endl;
}

int main(int argc, char*argv[])
{
    if(argc!=2){
        MuestraParametros();
        return 0;
    }

    string nf = argv[1];
    ifstream f(nf);
    if(!f){
        cout << "No puedo abrir " << nf << endl;
        return 0;
    }

    string linea;
    getline(f,linea);

    f.seekg(0);
    Ingredientes all_ingredientes;
    f>>all_ingredientes;
    
    //APARTADO 1
    //Introducimos el tipo de alimento y calculamos su desviacion
    //************************************************************************************************

    //INICIALIZAMOS VECTORES DINAMICOS PARA CADA UNO DE LOS ATRIBUTOS
    //***************************************************************
        VD<int> calorias,
                hidratos,
                proteinas,
                grasas,
                fibras;
    //****************************************************************

    cout << "\nEstadistica________________________" << endl; 
    string tipo;
    cout << "Tipo de alimento: ";
    cin >> tipo;
    Ingredientes ingre_tipo = all_ingredientes.getIngredienteTipo(tipo);
    //cout<<"Los ingredientes de tipo "<<tipo<<" son: "<<endl << ingre_tipo << endl;

    //Obtenemos todos los datos de los atributos organizados en vectores dinámicos
    calorias = ingre_tipo.obtenerCalorias();
    hidratos = ingre_tipo.obtenerHidratos();
    proteinas = ingre_tipo.obtenerProteinas();
    grasas = ingre_tipo.obtenerGrasas();
    fibras = ingre_tipo.obtenerFibra();

    //Calculamos la desviación típica de cada uno de los atributos
    float desviacionCal = calorias.obtenerDesviacion(calorias.obtenerVarianza()),
          desviacionHc = hidratos.obtenerDesviacion(hidratos.obtenerVarianza()),
          desviacionPr = proteinas.obtenerDesviacion(proteinas.obtenerVarianza()),
          desviacionGr = grasas.obtenerDesviacion(grasas.obtenerVarianza()),
          desviacionFib = fibras.obtenerDesviacion(fibras.obtenerVarianza());

    cout << "Promedio +-Desviacion " << endl;
    cout << "Calorias"
         << "\t Hidratos de Carb"
         << "\t Proteinas"
         << "\t Grasas"
         << "\t\t Fibra" << endl;
    
    cout << calorias.obtenerMedia() << "+-" <<desviacionCal << "\t"
         << hidratos.obtenerMedia() << "+-" <<desviacionHc  << "\t\t"
         << proteinas.obtenerMedia() << "+-" <<desviacionPr  << "\t"
         << grasas.obtenerMedia() << "+-" <<desviacionGr  << "\t "
         << fibras.obtenerMedia() << "+-" <<desviacionFib << endl;
    
    
    //*********************************************************************************************
    //APARTADO 2
    //Obtenemos el ingrediente que tenga mayor atributo (5 ingredientes, uno por cada atributo)
    //*********************************************************************************************

    //Obtenemos los ingredientes cuyo atributo deseado es el mayor de entre todos
    Ingrediente maxCal = ingre_tipo.ingrMaxCal(),
                maxHc  = ingre_tipo.ingrMaxHc(),
                maxPr  = ingre_tipo.ingrMaxPr(),
                maxGr  = ingre_tipo.ingrMaxGr(),
                maxFib = ingre_tipo.ingrMaxFib();

    //Los mostramos por pantalla
    cout << "\nMaximos valores " << endl;
    cout << "Calorias(Alimento)"
         << "\t Hidratos de Carb(Alimento)"
         << "\t Proteinas(Alimento)"
         << "\t Grasas(Alimento)"
         << "\t Fibra(Alimento)" << endl;

    cout << maxCal.getCalorias() << " " << maxCal.getNombre() << "\t"
         << maxHc.getHc() << " " << maxHc.getNombre()  << "\t\t"
         << maxPr.getProteinas() << " " << maxPr.getNombre()  << "\t\t"
         << maxGr.getGrasas() << " " <<maxGr.getNombre()  << "\t "
         << maxFib.getFibra() << " " << maxFib.getNombre() << endl;



    //*********************************************************************************************
    //APARTADO 3
    //Obtenemos el ingrediente que tenga menor atributo (5 ingredientes, uno por cada atributo)
    //*********************************************************************************************

    //Obtenemos los ingredientes cuyo atributo deseado es el menor de entre todos
    Ingrediente minCal = ingre_tipo.ingrMinCal(),
                minHc  = ingre_tipo.ingrMinHc(),
                minPr  = ingre_tipo.ingrMinPr(),
                minGr  = ingre_tipo.ingrMinGr(),
                minFib = ingre_tipo.ingrMinFib();

    //Los mostramos por pantalla
    cout << "\nMinimos valores " << endl;
    cout << "Calorias(Alimento)"
         << "\t Hidratos de Carb(Alimento)"
         << "\t Proteinas(Alimento)"
         << "\t Grasas(Alimento)"
         << "\t Fibra(Alimento)" << endl;

    cout << minCal.getCalorias() << " " << minCal.getNombre() << "\t"
         << minHc.getHc() << " " << minHc.getNombre()  << "\t\t"
         << minPr.getProteinas() << " " << minPr.getNombre()  << "\t\t"
         << minGr.getGrasas() << " " <<minGr.getNombre()  << "\t "
         << minFib.getFibra() << " " << minFib.getNombre() << endl
         << endl;

    
    //***********************************************************************************************

}