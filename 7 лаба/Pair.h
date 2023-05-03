#pragma once
using namespace std;
#include <iostream>
class Pair
{
	int first;
	double second;
public:
	void Show();
	Pair() { first = 0; second = 0; };
	Pair(int f, double s) { first = f; second = s; };
	Pair(const Pair& other) { first = other.first; second = other.second; };
	~Pair() {};
	int get_first() { return first; };
	double get_second() { return second; };
	void set_first(int f) { first = f; };
	void set_second(double s) { second = s; };
	//перегруженные операторы
	Pair& operator =(const Pair& other);
	bool operator ==(const Pair& other);
	bool operator !=(const Pair& other);
	Pair& operator -(const int constanta);
	Pair& operator -(const double constanta);
	//дружественная глобальная функция
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);
};

