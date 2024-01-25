#ifndef OBJECT_H
#define OBJECT_H
#include <sstream>

class Object{
    protected:
        int xPos;
        int yPos;
        char icon;
    public:
        Object* nextHoriz;
        Object* nextVert;
        Object* prevHoriz;
        Object* prevVert;
        Object* above;
        Object* below;
        Object(int x, int y);
        char getIcon();
        int getCoord(bool dimension);
        Object* getNext(bool dimension);
        Object* getPrev(bool dimension);
        void setNext(Object* obj, bool dim);
        void setPrev(Object* obj, bool dim);
};
#endif