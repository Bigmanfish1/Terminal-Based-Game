#include "Player.h"

using namespace std;

Player::Player(int x, int y): Object(x, y){
    icon = '&';
}

void Player::move(int x, int y){
    Object* node = this;
    while(node->below != NULL){
        node = node->below;
    }

    Object* newNode;    

    if(x == -1 && y == -1){
        newNode = node->prevHoriz->prevVert;
    }else if(x == 0 && y == -1){
        newNode = node->prevVert;
    }else if(x == 1 && y == -1){
        newNode = node->prevVert->nextHoriz;
    }else if(x == -1 && y == 0){
        newNode = node->prevHoriz;
    }else if(x == 1 && y == 0){
        newNode = node->nextHoriz;
    }else if(x == -1 && y == 1){
        newNode = node->prevHoriz->nextVert;
    }else if(x == 0 && y == 1){
        newNode = node->nextVert;
    }else if(x == 1 && y == 1){
        newNode = node->nextHoriz->nextVert;
    }

    while(node->above != this){
        node = node->above;
    }

    Object* tNew = newNode;
    while(newNode->above != NULL){
        tNew = newNode->above;
    }

    node->above = NULL;
    this->below = tNew;
    tNew->above = this;
    this->xPos = newNode->getCoord(false);
    this->yPos = newNode->getCoord(true);
}