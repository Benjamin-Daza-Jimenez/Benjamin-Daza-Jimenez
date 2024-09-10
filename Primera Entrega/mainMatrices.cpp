#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
#include "DataSetsMatrices.cpp"
#include "MultiMatrices.cpp"
#include "MultiMatricesTrasp.cpp"
#include "Strassen.cpp"

using namespace std;

int main(){
    GenerarMatrices();//Genera un archivo con matrices
    ifstream file("DataSetMatrices.txt");
    vector<vector<vector<int>>>AllMatrices;
    vector<vector<int>>Matriz;
    string line;

    while(getline(file,line)){
        if(line!="-"){
            vector<int>fila;
            stringstream item(line);
            string aux;
            while(getline(item,aux,' ')){
                fila.push_back(stoi(aux));
            }
            Matriz.push_back(fila);
        }
        else{
            AllMatrices.push_back(Matriz);
            Matriz.clear();
        }
    }
    file.close();

    vector<vector<vector<int>>>Resultado;
    auto start = chrono::high_resolution_clock::now(); //Inicio del clock
    for(int i=0; i<AllMatrices.size(); i++){
        vector<vector<int>>m1=AllMatrices[i];
        vector<vector<int>>m2=AllMatrices[i+1];
        int filasA=m1.size();
        int columnasB=m2.size();
        vector<vector<int>>m3(filasA, vector<int>(columnasB, 0));
        //MultiMatrices(m1,m2,m3);
        //MultiMatricesTrasp(m1,m2,m3);
        vector<vector<int>>m3=strassen(m1,m2);
        Resultado.push_back(m3);
        i++;
    }
    auto end = chrono::high_resolution_clock::now(); //Fin del clock
    chrono::duration<double> tiempo = end - start;//Fin-Inicio
    cout<<"El tiempo de ejecucion es de: "<<tiempo.count()<<endl;//Tiempo final


    ofstream multi("MatricesResultantes.txt");
    for(int i=0; i<Resultado.size();i++){ //Guardar los datos
        for(int j=0; j<Resultado[i].size();j++){
            for(int k=0; k<Resultado[i][j].size();k++){
                if(k!=Resultado[i][j].size()-1){
                    multi<<Resultado[i][j][k]<<" ";
                }
                else{
                multi<<Resultado[i][j][k]<<endl;
                }
            }
        }
        if(i!=Resultado.size()-1){
            multi<<"-"<<endl;
        }
        else{
            multi<<"-";
        }
    }
    multi.close();
    return 0;
}