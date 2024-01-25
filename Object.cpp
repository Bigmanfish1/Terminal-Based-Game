#include "Object.h"

using namespace std;

Object::Object(int x, int y)
{
    xPos = x;
    yPos = y;
    icon = '?';
    nextHoriz = NULL;
    prevHoriz = NULL;
    nextVert = NULL;
    prevVert = NULL;
    above = NULL;
    below = NULL;
}

char Object::getIcon()
{
    Object *temp = this;
    char val;

    while (temp->above != NULL)
    {
        temp = temp->above;
    }
    val = temp->icon;
    return val;
}

int Object::getCoord(bool dimension)
{
    int pos;
    if (dimension == false)
    {
        pos = xPos;
    }
    else if (dimension == true)
    {
        pos = yPos;
    }

    return pos;
}

Object *Object::getNext(bool dimension)
{
    Object *temp;
    if (dimension == false)
    {
        temp = this->nextHoriz;
    }
    else if (dimension == true)
    {
        temp = this->nextVert;
    }

    return temp;
}

Object *Object::getPrev(bool dimension)
{
    Object *temp;
    if (dimension == false)
    {
        temp = this->prevHoriz;
    }
    else if (dimension == true)
    {
        temp = this->prevVert;
    }

    return temp;
}

void Object::setNext(Object *ob, bool dim)
{
    if (dim == false)
    {
        this->nextHoriz = ob->nextHoriz;
    }
    else if (dim == true)
    {
        this->nextVert = ob->nextVert;
    }
}

void Object::setPrev(Object *ob, bool dim)
{
    if (dim == false)
    {
        this->prevHoriz = ob->prevHoriz;
    }
    else if (dim == true)
    {
        this->prevVert = ob->prevVert;
    }
}
