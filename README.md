# ObjectToreArray
Provide class which manage a toric 2D array.

## Toric array
Toric array mean the left side is adjacent to the right side and the top is adjacent to the bottom. So you can specify indexes out of bound, it will go around the tore and return you the right object.

## About the class
The class is a template class to fit all objects. The class can also work with other origin than (0,0). You can get or set object relative to another.

This template class is separate into a .h file and a .cpp file, so you have to include the .cpp instead of .h (cause of template class).
