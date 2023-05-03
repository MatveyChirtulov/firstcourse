#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Vector
{
public:
	//конструктор с параметрами: выделяет память под s элементов и заполняет их
	//значением k
	Vector(int s, T k)
	{
		size = s;
		data = new T[size];
		for (int i = 0; i < size; i++)
			data[i] = k;
	};
	//конструктор копирования
	Vector(const Vector<T>& a)
	{
		size = a.size;
		data = new T[size];
		for (int i = 0; i < size; i++)
			data[i] = a.data[i];
	};
	//деструктор
	~Vector()
	{
		delete[]data;
		data = 0;
	};
	//оператор присваивания
	Vector& operator=(const Vector<T>& a)
	{
		if (this == &a)return *this;
		size = a.size;
		if (data != 0) delete[]data;
		data = new T[size];
		for (int i = 0; i < size; i++)
			data[i] = a.data[i];
		return *this;
	};
	//операция доступа по индексу
	T& operator[](int index)
	{
		if (index < size) return data[index];
		else cout << "\nError! Index>size";
	};
	//операция для умножения на константу
	Vector<T> operator*(const T k)
	{
		for (int i = 0; i < this->size; ++i)
			this->data[i] *= k;
		return *this;
	};
	//операция, возвращающая размер списка
	int operator()()
	{
		return this->size;
	};
	//перегруженные операции ввода-вывода
	friend ostream& operator<<(ostream& out, const Vector<T>& a)
	{
		for (int i = 0; i < a.size; ++i)
			out << a.data[i] << " ";
		return out;
	};
	friend istream& operator>>(istream& in, Vector<T>& a)
	{
		for (int i = 0; i < a.size; ++i)
			in >> a.data[i];
		return in;
	};
private:
	int size;//размер списка
	T* data;//укзатель на динамический массив значений списка
}; 
