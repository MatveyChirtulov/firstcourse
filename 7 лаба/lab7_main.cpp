#include "Vector.h"
#include "Pair.h"
void main()
{


	setlocale(0, "Ru");
	//�������������, ���� � ����� �������� �������
	Vector<int>A(5, 0);
	cin >> A;
	cout << A << endl;
	//������������� � ����� �������� �������
	Vector <int>B(10, 1);
	cout << B << endl;
	//�������� ������������
	B = A;
	cout << B << endl;
	//������ �� �������
	cout << A[2] << endl;
	//��������� ����� �������
	cout << "size=" << A() << endl;
	//�������� �������� � ����������
	B = A * 10;
	cout << B << endl;
	//������ � ������� Pair
	const int first = 33;
	const double second = 4.5;
	Pair d(2, 3.7);
	Pair e = d;
	cout << "a=";
	d.Show();
	cout << "b=";
	e.Show();
	cout << "a==b?\t" << (d == e) << endl;
	cout << "a!=b?\t" << (d != e) << endl;
	cout << "const int first = 33\nconst double second = 4.5\n";
	cout << "a-first=";
	d - first;
	d.Show();
	cout << "b-second=";
	e - second;
	e.Show();
	
}