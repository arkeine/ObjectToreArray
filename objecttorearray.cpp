#include "objecttorearray.h"
#include <algorithm>

/*============================================*/
//  CONSTRUCTOR / DESTRUCTOR
/*============================================*/

template<typename T>
ObjectToreArray<T>::ObjectToreArray(int width, int height)
{
    this->h = height;
    this->w = width;
    cells = new T*[w];

    for (int i = 0; i < w; ++i)
    {
        cells[i] = new T[h];
    }
}

template<typename T>
ObjectToreArray<T>::ObjectToreArray(const ObjectToreArray<T> &o)
{
    this->h = o.h;
    this->w = o.w;
    cells = new T*[w];

    for (int i = 0; i < w; ++i)
    {
        cells[i] = new T[h];
        for (int j = 0; j < h; ++j)
        {
            cells[i][j] = o.cells[i][j];
        }
    }
}

template<typename T>
ObjectToreArray<T> &ObjectToreArray<T>::operator=(ObjectToreArray<T> o) //Force copy
{
    std::swap(this->h, o.h);
    std::swap(this->w, o.w);
    std::swap(this->cells, o.cells);
    return *this;
}

template<typename T>
ObjectToreArray<T>::~ObjectToreArray()
{
    for (int i = 0; i < w; ++i)
    {
        delete cells[i];
    }
    delete cells;
}

/*============================================*/
//  ASSESSOR / MUTATOR
/*============================================*/

template<typename T>
T &ObjectToreArray<T>::get(int x, int y, int centerX, int centerY) const
{
    uniformizeCoord(x, y, centerX, centerY);

    return cells[x][y];
}

template<typename T>
void ObjectToreArray<T>::set(const T &cell, int x, int y, int centerX, int centerY)
{
    uniformizeCoord(x, y, centerX, centerY);
	
    cells[x][y] = cell;
}

template<typename T>
int ObjectToreArray<T>::height() const
{
    return h;
}

template<typename T>
int ObjectToreArray<T>::width() const
{
    return w;
}

/*============================================*/
//  PRIVATE
/*============================================*/

template<typename T>
void ObjectToreArray<T>::uniformizeCoord(int &x, int &y, int centerX, int centerY) const
{
    //Real coord
    x %= w;
    y %= h;

    x = centerX + x;
    y = centerY + y;

    //Apply tore effect
    if(x < 0)
    {
        x += w;
    }
    else if(x >= w)
    {
        x = w - x;
    }
    if(y < 0)
    {
        y += h;
    }
    else if(y >= h)
    {
        y = h - y;
    }
}

