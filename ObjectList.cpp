#include "ObjectList.h"

using namespace std;

ObjectList::ObjectList(bool dim)
{
    dimension = dim;
    head = NULL;
    current = head;
}

void ObjectList::add(Object *obj)
{
    if (dimension == false)
    {
        Object *nodePtr;
        if (head == NULL)
        {
            head = obj;
            current = head;
        }
        else
        {
            nodePtr = head;
            while (nodePtr != NULL && nodePtr->getCoord(dimension) < obj->getCoord(dimension))
            {
                nodePtr = nodePtr->nextHoriz;
            }

            if (nodePtr == head)
            {
                obj->nextHoriz = nodePtr;
                nodePtr->prevHoriz = obj;
                head = obj;
                current = head;
            }
            else if (nodePtr == NULL)
            {
                Object *temp = head;
                while (temp->nextHoriz != NULL)
                {
                    temp = temp->nextHoriz;
                }

                temp->nextHoriz = obj;
                obj->prevHoriz = temp;
            }
            else if (nodePtr->getCoord(dimension) == obj->getCoord(dimension))
            {
                nodePtr->prevHoriz->nextHoriz = obj;
                obj->prevHoriz = nodePtr->prevHoriz;
                obj->nextHoriz = nodePtr;
                nodePtr->prevHoriz = obj;
            }
            else
            {
                nodePtr->prevHoriz->nextHoriz = obj;
                obj->prevHoriz = nodePtr->prevHoriz;
                obj->nextHoriz = nodePtr;
                nodePtr->prevHoriz = obj;
            }
        }
    }
    else if (dimension == true)
    {
        Object *nodePtr;
        if (head == NULL)
        {
            head = obj;
            current = head;
        }
        else
        {
            nodePtr = head;
            while (nodePtr != NULL && nodePtr->getCoord(dimension) < obj->getCoord(dimension))
            {
                nodePtr = nodePtr->nextVert;
            }

            if (nodePtr == head)
            {
                obj->nextVert = nodePtr;
                nodePtr->prevVert = obj;
                head = obj;
                current = head;
            }
            else if (nodePtr == NULL)
            {
                Object *temp = head;
                while (temp->nextVert != NULL)
                {
                    temp = temp->nextVert;
                }

                temp->nextVert = obj;
                obj->prevVert = temp;
            }
            else if (nodePtr->getCoord(dimension) == obj->getCoord(dimension))
            {
                nodePtr->prevVert->nextVert = obj;
                obj->prevVert = nodePtr->prevVert;
                obj->nextVert = nodePtr;
                nodePtr->prevVert = obj;
            }
            else
            {
                nodePtr->prevVert->nextVert = obj;
                obj->prevVert = nodePtr->prevVert;
                obj->nextVert = nodePtr;
                nodePtr->prevVert = obj;
            }
        }
    }
}

Object *ObjectList::getHead()
{
    return head;
}

string ObjectList::print()
{
    string res = "";
    Object *node = head;
    if (dimension == false)
    {
        while (node != NULL)
        {
            res += node->getIcon();
            node = node->nextHoriz;
        }
    }else if(dimension == true){
        while (node != NULL)
        {
            res += node->getIcon();
            node = node->nextVert;
        }
    }

    return res;
}

Object *ObjectList::iterate()
{
    Object *temp;
    if (dimension == false)
    {
        temp = current;
        if (current != NULL)
        {
            current = current->nextHoriz;
        }
    }
    else if (dimension == true)
    {
        temp = current;
        if (current != NULL)
        {

            current = current->nextVert;
        }
    }

    if (temp == NULL)
    {
        current = head;
    }

    return temp;
}

void ObjectList::reset()
{
    current = head;
}

string ObjectList::debug()
{
    string res = "Forward:\n";
    if (dimension == false)
    {
        Object *node = head;
        while (node != NULL)
        {

            string top;
            string i = "";
            i += node->getIcon();
            stringstream s;
            s << node->getCoord(false);
            string x = s.str();
            stringstream st;
            st << node->getCoord(true);
            string y = st.str();
            if (node->above == NULL)
            {
                top = "Y";
            }
            else
            {
                top = "N";
            }
            res += "<" + i + "> at (" + x + "," + y + ") Top:" + top + "\n";

            node = node->nextHoriz;
        }

        res += "Back:\n";

        node = head;
        while (node->nextHoriz != NULL)
        {
            node = node->nextHoriz;
        }

        while (node != NULL)
        {
            string top;
            string i = "";
            i += node->getIcon();
            stringstream s;
            s << node->getCoord(false);
            string x = s.str();
            stringstream st;
            st << node->getCoord(true);
            string y = st.str();

            if (node->above == NULL)
            {
                top = "Y";
            }
            else
            {
                top = "N";
            }
            res += "<" + i + "> at (" + x + "," + y + ") Top:" + top + "\n";

            node = node->prevHoriz;
        }
    }
    else if (dimension == true)
    {
        Object *node = head;
        while (node != NULL)
        {
            string top;
            string i = "";
            i += node->getIcon();
            stringstream s;
            s << node->getCoord(false);
            string x = s.str();
            stringstream st;
            st << node->getCoord(true);
            string y = st.str();

            if (node->above == NULL)
            {
                top = "Y";
            }
            else
            {
                top = "N";
            }
            res += "<" + i + "> at (" + x + "," + y + ") Top:" + top + "\n";

            node = node->nextVert;
        }

        res += "Back:\n";

        node = head;
        while (node->nextVert != NULL)
        {
            node = node->nextVert;
        }

        while (node != NULL)
        {
            string top;
            string i = "";
            i += node->getIcon();
            stringstream s;
            s << node->getCoord(false);
            string x = s.str();
            stringstream st;
            st << node->getCoord(true);
            string y = st.str();

            if (node->above == NULL)
            {
                top = "Y";
            }
            else
            {
                top = "N";
            }
            res += "<" + i + "> at (" + x + "," + y + ") Top:" + top + "\n";

            node = node->prevVert;
        }
    }

    return res;
}