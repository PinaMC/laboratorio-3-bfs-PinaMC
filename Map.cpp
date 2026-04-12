#include "Map.h"
#include <iostream>
#include <fstream>

//fstream para leer archivos
using namespace std;

Map::Map():h(0),w(0){

}

Map::Map(string filename){

    //Load the file
    //Resize map
    //Save file information in map
    //Close file

    //1- Abrir el archivo:
    ifstream file(filename);//ifstream para leer el archivo
    if(!file.is_open()){
        cerr<<"Error al abrir el file: "<<filename<<endl;
        exit(1);
    }
    //2- Leer la primera linea para obtener h y w
    //El archivo simple.txt es el txt mas pequeño con tiene 8 filas y 6 columnas, entonces h=11 y w=16
    file>>h>>w; 

    //3- Redimiensiona el mapa
    _map.resize(h, vector<int>(w)); //En h filas y w columnas

    //5-Leer los numeros / guardar la información del archivo en el _map
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            file >> _map[i][j]; // lee cada número directamente como int
        }
    }
    file.close(); //cierra el archivo

}   

Map::Map(const Map& rhs):h(rhs.h),w(rhs.w),_map(rhs._map){

}

Map::~Map(){
    
}

Map& Map::operator=(const Map& rhs){
    if(this==&rhs)return *this;
    h=rhs.h;
    w=rhs.w;
    _map=rhs._map;
    return *this;
}
   
void Map::print() const{
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<_map[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void Map::print(vector<pair<int,int>> path) const{
    auto __map=_map;

    __map[path[0].first][path[0].second]=2;
    for(int i=1;i<(int)path.size()-1;i++){
         __map[path[i].first][path[i].second]=4;
    }
     __map[path[path.size()-1].first][path[path.size()-1].second]=3;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){

            cout<<__map[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool operator==(const Map& lhs, const Map& rhs){
    return lhs.h==rhs.h && lhs.w==rhs.w && lhs._map==rhs._map;
}