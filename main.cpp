#include "Map.h"
#include "Search.h"
#include "ColorMap.h"
#include <cassert>
#include <iostream>
//compile with: g++ -Wall -Wextra -std=c++11 -g Foo.cpp -o foo
//debug with: gdb ./foo
//----------------
//compile with: g++ -Wall -Wextra -std=c++11 -g Foo.cpp -o foo
//debug with: valgrind --leak-check=full ./foo

int main(int argc, char *argv[]){

    //main usa mapp.h/ map.cpp para el mapa obviamente
    //search.h/search.cpp para el algoritmos bfs (basicamente lo principal del laboratorio)
    //y usa colorMap.h/colorMap.cpp para imprimir el mapa con colores (heredando de Map y reimplementando los métodos print)


    //Verify that the amount of arguments is correct
    //6 arguments: program name, map file, x1, y1, x2, y2

    //Load map with class Map
    Map map(argv[1]);
    ColorMap colorMap(map);
    colorMap.print();

    auto path = Search::BFS(map,{atoi(argv[2]),atoi(argv[3])},{atoi(argv[4]),atoi(argv[5])}); 
    colorMap.print(path);
    
    //Calculate path distance
    //Print path distance
    
    return 0;
}