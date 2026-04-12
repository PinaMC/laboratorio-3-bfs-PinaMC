#include "Search.h"
#include <queue>
#include <chrono>
#include <unordered_map>
#include <iostream>
#include <limits>

//Este archivo es el que contiene la implementación del algoritmo de búsqueda BFS (Breadth-First Search) 
//para encontrar un camino en un mapa representado por la clase Map. Además, incluye una función para reconstruir
//el camino encontrado a partir de un mapa de padres (pathCache) que se genera durante la búsqueda.
namespace std
{
    //this is needed to store a pair<int,int> in an associative container
    //este es necesario para almacenar un pair<int,int> en un contenedor asociativo
    //such as unorered_set and unordered_map
    //como un unordered_set y un unordered_map
    //unordeered_set significa que no se mantiene un orden de los elementos, lo que permite una búsqueda más rápida, pero no garantiza el orden de los elementos al iterar sobre ellos.
    //unordered_map es un contenedor que almacena pares clave-valor, donde cada clave es única. Al igual que unordered_set, no mantiene un orden específico de los elementos, lo que permite una búsqueda rápida basada en la clave.
    
	template<> struct hash<std::pair<int,int>>
	{
		std::size_t operator()( const std::pair<int,int> & p) const noexcept
		{
            hash<int> hasher;
			return hasher(p.first) ^ (hasher(p.second)<<1);

		}
	};
}

std::vector<std::pair<int,int>> Search::reconstruct(const std::unordered_map<std::pair<int,int>,std::pair<int,int>> &pathCache, const std::pair<int,int> &start){
	std::deque<std::pair<int,int>> nodes;
	auto node = start;//make copy

    //traverse path from goal to start

    //
	//while(true){
        //implement
	//}

    //revert path and return it
    std::vector<std::pair<int,int>> vec;
    for(auto p:nodes){
        vec.push_back(p);
    }
    return vec;
}

std::vector<std::pair<int,int>> Search::BFS(const Map& map, std::pair<int,int> start, std::pair<int,int> goal){
    std::cout<<"===========================\nRunning BFS...\n";
	auto startTime = std::chrono::high_resolution_clock::now();

    //stores possible directions
    std::pair<int,int> dirs[]{{-1,0},{0,1},{1,0},{0,-1}};

    bool visited[map.h][map.w]{false};      //we'll just use a matrix og booleans to indicated if visited
    std::queue<std::pair<int,int>> OPEN;
    std::unordered_map<std::pair<int,int>,std::pair<int,int>> pathCache;    ////hashmap to reconstruct path: child -> parent

    //add firts node to open list

    while(!OPEN.empty()){
        //get node

        //check if node is goal
		/*if(pos==goal){
			auto endTime = std::chrono::high_resolution_clock::now();
			int count=0;
            for(int i=0;i<map.h;i++){
                for(int j=0;j<map.w;j++){
                    if(visited[i][j])count++;
                }
            }
            std::cout<<"VISITED: "<<count<<std::endl;
			std::cout<<"OPEN: "<<OPEN.size()<<std::endl;
			std::cout<<"FOUND in "<<(endTime-startTime).count()/1000000.0<<"ms\n";
			return reconstruct(pathCache,pos);
		}*/

		for(auto dir:dirs){
			//copy the position

            //then move it
            
            //if illegal or visited, skip it
            
            //add child to open list

            //register path
		}
	}
	std::cout<<"NOT FOUND!!!!\n";
    
    //let's just return start and goal to draw them
    std::vector<std::pair<int,int>> path;
    path.push_back(start);
    path.push_back(goal);
    return path;
}
