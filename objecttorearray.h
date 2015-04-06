#ifndef OBJECTTOREARRAY_H
#define OBJECTTOREARRAY_H

template<typename T>
class ObjectToreArray
{
public:
    ObjectToreArray(int width, int height);
    virtual ~ObjectToreArray();

    T *get(int x, int y, int centerX = 0, int centerY = 0) const;
    void set(int x, int y, int centerX = 0, int centerY = 0, T *cell);

    int height() const;
    int width() const;

private:
    T ***cells;
    int h;
    int w;
	    
	void uniformizeCoord(int &x, int &y, int centerX, int centerY) const;
};

#endif // OBJECTTOREARRAY_H
