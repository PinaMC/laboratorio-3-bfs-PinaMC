#include "Map.h"
#include <iostream>
#include <fstream>

using namespace std;

Map::Map():h(0),w(0){

}

Map::Map(string filename){
    
    //Load the file
    //Resize map
    //Save file information in map
    //Close file
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