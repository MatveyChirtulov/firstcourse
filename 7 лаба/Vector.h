#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Vector
{
public:
	//����������� � �����������: �������� ������ ��� s ��������� � ��������� ��
	//��������� k
	Vector(int s, T k)
	{
		size = s;
		data = new T[size];
		for (int i = 0; i < size; i++)
			data[i] = k;
	};
	//����������� �����������
	Vector(const Vector<T>& a)
	{
		size = a.size;
		data = new T[size];
		for (int i = 0; i < size; i++)
			data[i] = a.data[i];
	};
	//����������
	~Vector()
	{
		delete[]data;
		data = 0;
	};
	//�������� ������������
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
	//�������� ������� �� �������
	T& operator[](int index)
	{
		if (index < size) return data[index];
		else cout << "\nError! Index>size";
	};
	//�������� ��� ��������� �� ���������
	Vector<T> operator*(const T k)
	{
		for (int i = 0; i < this->size; ++i)
			this->data[i] *= k;
		return *this;
	};
	//��������, ������������ ������ ������
	int operator()()
	{
		return this->size;
	};
	//������������� �������� �����-������
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
	int size;//������ ������
	T* data;//�������� �� ������������ ������ �������� ������
}; 
