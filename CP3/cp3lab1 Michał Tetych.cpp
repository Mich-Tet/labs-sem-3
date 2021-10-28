#include <iostream>
using namespace std;

template<class T>
class Myimg
{
	int arraySize;
	T** myArray;
public:
	Myimg(int arraySize) ;

	int getSize();
	void assignValue(int x, int y, int arraySize);
	
	T returnValue(int x, int y);
};
template<class T>
Myimg<T>::Myimg(int size)
{
	arraySize = size;
	myArray = new T* [arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		myArray[i] = new T[arraySize];
	}
}
template<class T>
int Myimg<T>::getSize()
{
	return arraySize;
}
template<class T>
void Myimg<T>::assignValue(int x,int y,int arraySize)
{
	myArray[x][y] = arraySize;
}
template<class T>
T Myimg<T>::returnValue(int x, int y)
{
	return myArray[x][y];
}
int main()
{
	Myimg<double> a(100);
	a.assignValue(5,10,175);
	cout << a.getSize() << endl;
	cout << a.returnValue(5, 10) << endl;
}