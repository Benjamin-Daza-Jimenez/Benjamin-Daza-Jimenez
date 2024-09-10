#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
Nombre: GenerarMatrices
Parametro: N/A
Retorno: N/A
Genera un archivo de tipo texto el cual contiene 50 matrices de 512x512 numeros aleatorios entre 0 y 100. Cada matriz está separada por una linea que contiene el caracter "-".
*/
void GenerarMatrices(){
    ofstream file("DataSetMatrices.txt");
    srand(static_cast<unsigned>(std::time(nullptr)));
    for(int i=0; i<50; i++){//50
        for(int j=0; j<512;j++){//512
            for(int k=0; k<512; k++){//512
                int numero = rand() % 100 + 1;
                if(k!=511){//511
                    file<<numero<<" ";
                }
                else{
                    file<<numero<<endl;
                }
            }
        }
        if(i!=49){//49
            file<<"-"<<endl;
        }
        else{
            file<<"-";
        }
    }
}