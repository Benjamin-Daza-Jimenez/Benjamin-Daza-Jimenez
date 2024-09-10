#include <iostream>
#include <vector>
using namespace std;
/*
Nombre: Transponer
Parametro: 
    vector<vector<int>>m: copia de la matriz la cual se quiere transponer.
Retorno: 
    mT: matriz transpuesta.
Transpone la matriz a través de generar una matriz invirtiendo los tamaños de i y j, resultando una matriz de orden j e i.
*/
vector<vector<int>> Transponer(vector<vector<int>> m){
    int filas=m.size();
    int columnas=m[0].size();
    vector<vector<int>>mT(columnas, vector<int>(filas));
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            mT[j][i]=m[i][j];
        }
    }
    return mT;
}
/*
Nombre: MultiMatricesTrasp
Parametro: 
    vector<vector<int>>m1: copia de la primera matriz (vector de vectores) la cual se quiere multiplicar.
    vector<vector<int>>m2: copia de la segunda matriz (vector de vectores) la cual se quiere multiplicar.
    vector<vector<int>>&m3: paso por referencia de la matriz resultante inicializada en 0.
Retorno: N/A
Multiplica las matrices m1 y m2, pero primero, m2 es transpuesta y luego se hace el recorrido de la sumatoria de la multiplicación.
*/
void MultiMatricesTrasp(vector<vector<int>>m1,vector<vector<int>>m2,vector<vector<int>>&m3){
    //Primero trasponer la matriz m2
    vector<vector<int>>m2T=Transponer(m2);
    
    int filasA=m1.size();
    int colAfilB=m1[0].size();
    int columnasB=m2T.size();

    for(int i=0; i<filasA; i++){
        for(int j=0; j<columnasB; j++){
            for(int k=0; k<colAfilB; k++){
                m3[i][j]+= m1[i][k] * m2T[j][k];
            }
        }
    }
}