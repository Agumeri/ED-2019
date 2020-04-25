#include "Ingrediente.h"
#include "Ingredientes.h"
#include "receta.h"
#include "recetas.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]){
    string rec = argv[1];
    string ing = argv[2];
    string  num = argv[3];

    ifstream f1(ing),f2(rec);

    Ingredientes all_ingre;
    recetas all_recetas;

    cout << "Lectura de todos los ingredientes"<< endl;
    f1>>all_ingre;

    cout << "Lectura de todas las recetas" << endl;
    f2>>all_recetas;

    recetas re, resultado;
    recetas::iterator it;

    for(it = all_recetas.begin(); it != all_recetas.end(); ++it){
        cout << "\nValores nutricionales de la receta: " << (*it);
        (*it).calcularNutrientes(all_ingre);
        cout << "Calorias: "  << (*it).getCalorias() << "\t\tHidratos de Carb. : " << (*it).getHC() << "\t\tProteinas: " 
             << (*it).getProteinas() << "\t\tGrasas: " << (*it).getGrasas() << "\tFibras: " << (*it).getFibras() << endl;
        
        if((*it).getCalorias() <= stoi(num)){
            re.aniadir( (*it) );
        }
    }

    for(it = re.begin(); it != re.end(); ++it){
        (*it).calcularNutrientes(all_ingre);
    }

    resultado = re.maximizarCalorias(stoi(num));
    float caloriasTot = 0.0;
    float proteinasTot = 0.0;
    cout<<"Las recetas escogidas son: " <<endl;
    for(it = resultado.begin(); it != resultado.end(); ++it){
        cout << (*it) << endl;
        (*it).calcularNutrientes(all_ingre);
        caloriasTot += (*it).getCalorias();
        proteinasTot += (*it).getProteinas();

    }

    cout << "Calorias Totales " << caloriasTot << "  Proteinas Totales " << proteinasTot << endl;


    cout << "\n\n ------ FIN DEL PROGRAMA ------ \n" << endl;

}