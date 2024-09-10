#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
Nombre: DataSet
Parametro: N/A
Retorno: N/A
Genera un archivo de tipo texto el cual contiene 5000 lineas con 5000 números aleatorios entre 0 y 10000 cada una.
*/
void DataSet(){
    ofstream file("DataSetSort.txt");
    srand(static_cast<unsigned>(std::time(nullptr)));
    for(int j=0; j<5000; j++){
        for(int i=0; i<5000;i++){ 
            int numero = rand() % 10000 + 1;
            if(i!=4999){
                file<<numero<<",";
            }
            else{
                file<<numero<<endl;
            }
        }
    }
    file.close();
}
