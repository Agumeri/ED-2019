#include <iostream>
#include <fstream>
#include <list>
#include "Ingrediente.h"
#include "Ingredientes.h"
#include "recetas.h"
#include "acciones.h"
#include "color.h"
#include "instrucciones.h"
using namespace std;

int main(int argc, char* argv[]){
    /**************************************************************************************************************************************************/
    //Section 1: Lectura de todos los ficheros necesarios
    string acc = argv[1];
    string rec = argv[2];
    string ing = argv[3];
    string ins = argv[4]; // datos/instrucciones/

    ifstream f(acc);
    ifstream f2(rec);
    ifstream f3(ing);
    

    acciones fichero_acciones;
    recetas fichero_recetas;
    Ingredientes fichero_ingredientes;
    instrucciones fichero_instrucciones;

    

    f3 >> fichero_ingredientes;
    cout << "Se han leido los ingredientes " << endl;
    f3.close();
    
    f >> fichero_acciones;
    cout << "Se han leido las acciones " << endl;
    f.close();

    cout << "Se han leido las recetas" << endl;
    f2 >> fichero_recetas;
    f.close();

    
    fichero_instrucciones.aniadir_acciones(fichero_acciones);
    /**************************************************************************************************************************************************/

    /**************************************************************************************************************************************************/
    //Section 2: Obtencion del calculo de nutrientes y de las instrucciones a seguir de una receta específica
    string cod;
    cout << "\n\nEscoja un codigo de receta: ";
    cin >> cod;

    ins += cod + "m.txt";

    receta r1;
    if (fichero_recetas[cod].getNombre()!="Undefined"){
        r1 = fichero_recetas[cod];

        cout << KBLU << "\n\nCODE:" << KWHT << r1.getCode() << KBLU << "       NOMBRE: " << KWHT << r1.getNombre() << 
                KBLU << "       PLATO: " << KWHT << r1.getPlato() << endl;

        receta::iterator iter;
        cout << UNDL(BOLD("\nIngredientes:")) << endl;
        for(iter = r1.begin(); iter != r1.end(); ++iter){
            cout << "  " << (*iter).first << " " << (*iter).second << endl;
        }        

        r1.calcularNutrientes(fichero_ingredientes);
        cout << UNDL(BOLD("\nInformacion nutricional:")) << endl;

        cout << "  Calorias: "  << r1.getCalorias() << endl;
        cout << "  Hidratos de Carb. : " << r1.getHC() << endl;
        cout << "  Proteinas: " << r1.getProteinas() << endl;
        cout << "  Grasas: " << r1.getGrasas() << endl;
        cout << "  Fibras: " << r1.getFibras() << endl;

        ifstream f4(ins);
        cout << "El fichero de instrucciones a leer es ----> " << ins << endl;
        f4 >> fichero_instrucciones;

        f4.close();

        cout << UNDL(BOLD("\nPasos a seguir: ")) << endl;
        cout << fichero_instrucciones << endl;

    }else{
        cout<< BOLD("La receta con codigo "<<cod<<" no existe")<<endl;
        cout << "\n\n-------- FIN DEL PROGRAMA -------- " << endl << endl;
        return 0;
    }
    
    /**************************************************************************************************************************************************/
    
    /**************************************************************************************************************************************************/
    //Section 3: Obtención de la fusión de una receta (incluyendo el calculo de sus nutrientes y las instrucciones a proceder para realizarla)
    string codigo1, codigo2;
    cout << "\n\nIntroduzca los codigos de dos recetas para fusionarlas: ";
    cin >> codigo1 >> codigo2;

    receta ra = fichero_recetas[codigo1], rb = fichero_recetas[codigo2];
    receta rf;
    
    if (ra.getNombre()!="Undefined" && rb.getNombre()!="Undefined"){
        //Fusionar si es 1,1  2,2,  3,3
        if(ra.getPlato() == rb.getPlato()){
            //Comprobamos si las recetas son validas para fusionar
            if(ra.esValido(fichero_ingredientes) && rb.esValido(fichero_ingredientes)){
                rf.fusionarRecetas(ra,rb);
                rf.calcularNutrientes(fichero_ingredientes);
            }else{
                if(!ra.esValido(fichero_ingredientes))
                    cout << "No se pueden fusionar las recetas " << ra.getCode() << " y " << rb.getCode() <<  " porque la receta " << ra.getCode() << " no es correcta" << endl;

                if(!rb.esValido(fichero_ingredientes))
                    cout << "No se pueden fusionar las recetas " << ra.getCode() << " y " << rb.getCode() <<  " porque la receta " << rb.getCode() << " no es correcta" << endl;

                cout << "\n\n\n-------- FIN DEL PROGRAMA -------- " << endl << endl;

                return 0;
            }

        }else{
            cout << "ERROR: No es posible fusionar una receta de tipo " << ra.getPlato() << " y otra de tipo " << rb.getPlato() << endl;
            cout << "\n\n\n-------- FIN DEL PROGRAMA -------- " << endl << endl;
            return 0;
        }

        cout << KBLU << "\n\nCODE:" << KWHT << rf.getCode() << KBLU << "       NOMBRE: " << KWHT << rf.getNombre() << 
                KBLU << "       PLATO: " << KWHT << rf.getPlato() << endl;

        receta::iterator iter;
        cout << UNDL(BOLD("\nIngredientes:")) << endl;
        for(iter = rf.begin(); iter != rf.end(); ++iter){
            cout << "  " << (*iter).first << " " << (*iter).second << endl;
        }        

        cout << UNDL(BOLD("\nInformacion nutricional:")) << endl;
        cout << "  Calorias: "  << rf.getCalorias() << endl;
        cout << "  Hidratos de Carb. : " << rf.getHC() << endl;
        cout << "  Proteinas: " << rf.getProteinas() << endl;
        cout << "  Grasas: " << rf.getGrasas() << endl;
        cout << "  Fibras: " << rf.getFibras() << endl;

        instrucciones inst_fusion, inst_a, inst_b;
        inst_fusion.aniadir_acciones(fichero_acciones);
        inst_a.aniadir_acciones(fichero_acciones);
        inst_b.aniadir_acciones(fichero_acciones);

        string nombre1, nombre2;
        nombre1 += "datos/instrucciones/" + ra.getCode() + "m.txt";
        nombre2 += "datos/instrucciones/" + rb.getCode() + "m.txt";

        ifstream f6(nombre1);
        cout << "\nLeemos el fichero de instrucciones " << nombre1 << endl;
        f6 >> inst_a;

        ifstream f7(nombre2);
        cout << "Leemos el fichero de instrucciones " << nombre2 << endl;
        f7 >> inst_b;

        inst_fusion.calcularInstruccionesFusion(inst_a, inst_b);

        cout << UNDL(BOLD("\nPasos a seguir: ")) << endl;
        cout << inst_fusion << endl;

    }else{
        if(ra.getNombre()=="Undefined")
            cout<<BOLD("La receta con codigo "<<codigo1<<" no existe")<<endl;
        if(rb.getNombre()=="Undefined")
            cout<<BOLD("La receta con codigo "<<codigo2<<" no existe")<<endl;
    }
    /**************************************************************************************************************************************************/
    
    cout << "\n\n\n-------- FIN DEL PROGRAMA -------- " << endl << endl;

    return 0;

}