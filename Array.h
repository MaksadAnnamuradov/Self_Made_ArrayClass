#pragma once

#include <iostream>
using namespace std;

template <class T>
class Array {
private:
	T *elements = nullptr;   // Template elements pointer
	unsigned int sizevar;       //size variable to keep track of the size of the vector class
	unsigned int capacityvar;   //capacity variable to hold the capacity of the vector class
public:
	void append(T const& data);  // append function that recives constant refrence variable data
	void pop();               // pop function
	unsigned int capacity() const; // return capacity

	unsigned int size() const; // for returning size

	T &operator[](const unsigned int &);   //Overloading [] operator

	const T &operator[](const unsigned int &)const;   // Overloading const [] operator

	void recapacity(unsigned int); // if size is eqaul to capacity double the capacity
	
	//Constructors
	Array(const Array<T> & );

	Array(unsigned int = 5);

	//Desctructor
	~Array();
};



//Declaration of copy constructor
template<class T>
Array<T>::Array(const Array<T> & array) {

	//Copy the elements of array to the elements of Array template class
	sizevar = array.size;
	capacityvar = array.capacity;
	elements = new T[size];
	for (unsigned int i = 0; i < size; i++)
	{
		elements[i] = array.elements[i];
	}
}

//Defualt Constructor with capacity of value 5
template<class T>
Array<T>::Array(unsigned int cap) {
	capacityvar = cap;
	sizevar = 0;

	elements = new T[capacityvar];
}

//Template Destructor
template<class T>
Array<T>::~Array() {
	delete[] elements;
}

//Append function that recives elem 
template <class T>
void Array<T>::append(T const& elem) {
	// append copy of passed element 
	if (sizevar == capacityvar)
	{
		recapacity(capacityvar * 2);
	}
	
	elements[sizevar] = elem;
	sizevar++;
}

//Template Pop() function
template <class T>
void Array<T>::pop() {
	sizevar--;
	if (sizevar < (capacityvar / 4) && capacityvar >= 2)
	{
		recapacity(capacityvar / 2);
	}
}

//Size function that returns the value of the size
template<class T>
unsigned int Array<T>::size() const {
	return sizevar;
}

//returns the value capacity
template<class T>
unsigned int Array<T>::capacity()const {
	return capacityvar;
}

//Overloading [] operator
template <class T>
T &Array<T>::operator[](const unsigned int &sub)
{
	return elements[sub];
}

//Overloading [] operator
template <class T>
const T &Array<T>::operator[](const unsigned int &sub) const
{
	if (sub < 0 || sub >= sizevar)
	{
		cout << "Subscript out of range!" << endl;
	}
	return elements[sub];
}

//Overlaoding << operator
template <class T>
ostream &operator <<(ostream &stream, const Array<T>& obj)
{
	for (int i = 0; i < obj.size(); i++)
	{
		stream << obj[i] << endl;
	}
	return stream;
}

//Template recapacity function
template <class T>
void Array<T>::recapacity(unsigned int c) {
	T *temp = new T[c];
	for (unsigned int i = 0; i < sizevar; i++)
	{
		temp[i] = elements[i];
	}
	delete[] elements;

	capacityvar *= 2;
	elements = temp;
}