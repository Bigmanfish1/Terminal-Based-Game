#include "Map.h"


using namespace std;

Map::Map(int w, int h){
    width = w;
    height = h;
    rows = new ObjectList*[height];
    for(int i = 0; i < height; i++){
        rows[i] = new ObjectList(false);
    }

    columns = new ObjectList*[width];
    for(int i = 0; i < width; i++){
        columns[i] = new ObjectList(true);
    }
}

Map::~Map(){
    if(rows != NULL){
        for(int i = 0; i < height; i++){
            if(rows[i] != NULL){
                rows[i]->reset();
	            while (Object* p = rows[i]->iterate()){
                    delete p;
                }
                delete rows[i];
            }

            
        }
        delete[] rows;
        rows = NULL;
    }
   
}

void Map::add(Object* obj){
    int y = obj->getCoord(true);
    int x = obj->getCoord(false);

    rows[y]->add(obj);
    columns[x]->add(obj);

}

string Map::print(){
    string res = "";
    for(int i = 0; i < height; i++){
        res += rows[i]->print() + "\n";
    }

    return res;
}
