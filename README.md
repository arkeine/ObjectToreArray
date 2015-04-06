# ObjectToreArray
Provide class which manage a toric 2D array.

## Toric array
Toric array mean the left side is adjacent to the right side and the top is adjacent to the bottom. So you can specify indexes out of bound, it will go around the tore and return you the right object.

## About the class
The class is a template class to fit all objects and manage pointers on them. So your are responsible for populate the array (default value is null) and for free the memory of objects you have created. The class delete only its array, allowing you use your objects elsewhere.

The class can also work with other origin than (0,0). You can get or set object relative to another.
