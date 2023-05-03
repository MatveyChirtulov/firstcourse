#include "Pair.h"
Pair& Pair::operator=(const Pair& other)
{
	this->first = other.first;
	this->second = other.second;
	return *this;
}
bool Pair::operator==(const Pair& other)
{
	return (this->first == other.first && this->second == other.second);
}
bool Pair::operator!=(const Pair& other)
{
	return !(this->first == other.first && this->second == other.second);
}
Pair& Pair::operator-(const int constanta)
{
	this->first -= constanta;
	return *this;
}
Pair& Pair::operator-(const double constanta)
{
	this->second -= constanta;
	return *this;
}
void Pair::Show()
{
	cout << "(" << this->first << ":" << this->second << ")" << endl;
}

istream& operator>>(istream& in, Pair& p)
{
	in >> p.first;
	in >> p.second;
	return in;
}

ostream& operator<<(ostream& out, const Pair& p)
{
	out << "(";
	out << p.first;
	out << ":";
	out << p.second;
	out << ")";
	return out;
}
