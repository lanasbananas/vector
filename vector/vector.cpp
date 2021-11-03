#include <iostream>
#include <stdio.h>
using namespace std;

class vector
{
	size_t _size;
	double* _data;

public:

	vector()
	{
		_size = 2;
		_data = new double[_size];
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = 0;
		};
	};

	vector(size_t size, double data)  //констр копирования
	{
		_size = size;
		_data = new double[_size];
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = data;
		};
	};
	
	~vector() //деструктор
	{
		delete[] _data;
	};

	double operator[](size_t data) //оператор чтения (с выводом на экран) вектора по указанному индексу
	{
		if (data >= _size || data < 0)
			throw std::logic_error("Invalid index");
		return _data[data];
	};

	vector& operator = (const vector& v) //оператор присваивания
	{
		//проверка на самоприсваивание
		if (this == &v)
			return (*this);
		if (_size == v._size)			///////////
		{
			delete[]_data;
			_size = v._size;
			_data = new double[v._size];
		};
		for (int i = 0; i < _size; i++)
		{
			_data[i] = v._data[i];
		};
		return (*this);
	};

	vector operator+(const vector& v1) //сложение
	{
		if (_size != v1._size)
			throw("Can not sum2 vector!");
		vector sum;
		sum._size = _size;
		sum._data = new double[_size];
		for (int i = 0; i < _size; i++)
		{
			sum._data[i] = _data[i] + v1._data[i];
		};
		return sum;
	};

	vector operator-(const vector& v1) //вычитание
	{
		if (_size != v1._size)
			throw "Can not dif2 vector!";
		vector dif;
		dif._size = _size;
		for (int i = 0; i < _size; i++)
		{
			dif._data[i] = _data[i] - v1._data[i];
		};
		return dif;
	};
	
	double operator*(const vector& v1) //скалярное произведение
	{
		if (_size != v1._size)
			throw "Can not mul2 vector!";
		double mul = 0;
		for (size_t i = 0; i < _size; i++)
		{
			mul += _data[i] * v1._data[i];
		};
		return mul;
	};
	
	vector operator*(const double data)
	{
		vector res(_size, 0);
		for (size_t i = 0; i < _size; i++)
		{
			res._data[i] = _data[i] * data;
		};
		return res;
	};

	vector operator/(const double data)
	{
		if (data == 0)
			throw("Error!");
		vector res(_size, 0);
		for (size_t i = 0; i < _size; i++)
		{
			res._data[i] = _data[i] / data;
		};
		return res;
	};
}