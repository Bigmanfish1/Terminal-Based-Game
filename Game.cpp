#include "Game.h"

using namespace std;

Game::Game(int w, int h, string chars){
    map = new Map(w, h);
    int index = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(chars[index] == '&'){
                Floor* floor = new Floor(j, i);
                player = new Player(j, i);
                floor->above = player;
                player->below = floor;
                map->add(floor);
            }else if(chars[index] == '#'){
                Wall* wall = new Wall(j, i);
                map->add(wall);
            }else if(chars[index] == '.'){
                Floor* floor = new Floor(j, i);
                map->add(floor);
            }else if(chars[index] == '?'){
                Object* ob = new Object(j, i);
                map->add(ob);
            }
          
            index++;
        }
    }
}

Game::~Game(){
    delete map;
    map = NULL;
    delete player;
    player = NULL;
}

string Game::display(){
    return map->print();
}

void Game::update(char input){
    if(player != NULL){
    if(input == '1'){
        if(player != NULL){
            player->move(-1, 1);
        }
    }else if (input == '2')
    {
        if(player != NULL){
            player->move(0, 1);
        }
    }else if(input == '3'){
        if(player != NULL){
            player->move(1, 1);
        }
    }else if(input == '4'){
        if(player != NULL){
            player->move(-1, 0);
        }
    }else if(input == '6'){
        if(player != NULL){
            player->move(1, 0);
        }
    }else if(input == '7'){
        if(player != NULL){
            player->move(-1, -1);
        }
    }else if(input == '8'){
        if(player != NULL){
            player->move(0, -1);
        }
    }else if(input == '9'){
        if(player != NULL){
            player->move(1, -1);
        }
    }
    }
}