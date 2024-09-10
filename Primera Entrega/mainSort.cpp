#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <chrono>
#include "DataSetsSort.cpp"
#include "MergeSort.cpp"
#include "QuickSort.cpp"
#include "SelectionSort.cpp"

using namespace std;

int main(){
    int aux;
    cout<<"Algoritmos de ordenamiento"<<endl;
    cout<<"(1) Funcion sort de c++"<<endl;
    cout<<"(2) MergeSort"<<endl;
    cout<<"(3) QuickSort"<<endl;
    cout<<"(4) SelectionSort"<<endl;
    cout<<"Ingrese el numero que indica el algoritmo que desea probar: ";cin>>aux;

    DataSet(); //Se crea el DataSet

    ifstream file("DataSetSort.txt");
    string line;
    vector<vector<int>> AllVectors;
    while(getline(file,line)){
        vector<int>Vector;
        stringstream item(line);
        string aux;
        while(getline(item,aux,',')){
            Vector.push_back(stoi(aux));
        }
        AllVectors.push_back(Vector);
    }
    file.close();

    auto start = chrono::high_resolution_clock::now(); //Inicio del clock
    if(aux==1){
        for(int i=0; i<AllVectors.size(); i++){
            vector<int>Vector=AllVectors[i];
            sort(Vector.begin(),Vector.end());
            AllVectors[i]=Vector;
        }
    }
    else if(aux==2){
        for(int i=0; i<AllVectors.size(); i++){
            vector<int>Vector=AllVectors[i];
            MergeSort(Vector,0,Vector.size()-1);
            AllVectors[i]=Vector;
        }
    }
    else if(aux==3){
        for(int i=0; i<AllVectors.size(); i++){
            vector<int>Vector=AllVectors[i];
            QuickSort(Vector,0,Vector.size()-1);
            AllVectors[i]=Vector;
        }
    }
    else if(aux==4){
        for(int i=0; i<AllVectors.size(); i++){
            vector<int>Vector=AllVectors[i];
            SelectionSort(Vector,Vector.size()-1);
            AllVectors[i]=Vector;
        }
    }
    auto end = chrono::high_resolution_clock::now(); //Fin del clock
    chrono::duration<double> tiempo = end - start;//Fin-Inicio
    cout<<"El tiempo de ejecución es de: "<<tiempo.count()<<endl;//Tiempo final

    ofstream order("DataOrdenada.txt");
    for(vector<int>Vector:AllVectors){
       for(int j=1; j<Vector.size();j++){
            if(j!=(Vector.size()-1)){
                order<<Vector[j]<<",";
            }
            else{
                order<<Vector[j]<<endl;
            }
        } 
    }
    order.close();
    return 0;
}