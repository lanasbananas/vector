#include <iostream>
#include <stdio.h>

using namespace std;

class vector
{
private:

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
		if (_size < 0)
			throw("Can not negative size");
		_data = new double[_size];
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = data;
		};
	}; //конструктор копирования копирует данные в пустой объект (он только создается та ниче нет)

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

	vector(const vector& v)
	{
		_size = v._size;
		delete[] _data;
		_data = new double[_size];
		for (size_t i = 0; i < _size; i++)
			_data[i] = v._data[i];
	}

	vector(vector&& move) //чтобы работало + и -
	{ 
		_data = move._data;
		_size = move._size;
		move._data = nullptr;
		move._size = 0;
	} 
	vector& operator= (const vector& v) //оператор присваивания
	{
		//проверка на самоприсваивание
		if (this == &v)
			return (*this);
		if (_size == v._size)			///////////
		{                               //прежде чем выполнять надо выполнить осовобождение памяти
			delete[]_data;              //на которую указывает указатель дата
			_size = v._size;
			_data = new double[v._size];
		};
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = v._data[i];
		};               //возвращает ссылку на текущий объект
		return (*this); //разыменование оператора this
	}; //this - текущий оюъект класса

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

	vector operator*(const double data) //умножение на скаляр
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
	
	friend istream& operator>> (istream& is, vector& v) //оператор извлечния >> (istream-входной поток)
	{
		
		cout << "Size: ";
		is >> v._size;
		v._data = new double[v._size];
		for (size_t i = 0; i < v._size; i++)
			is >> v._data[i];
		return is;
	};

	friend ostream& operator<< (ostream& os, const vector& v) //оператор вставки << (ostream-выходной поток)
	{
		os << "[ ";
		for (size_t i = 0; i < v._size; i++)
			os << v._data[i] << " ";
		os << "]" << endl;
		return os;
	}; 

};

int main() 
{
	vector a;
	vector b;
	int num = 6;
	cin >> a;
	cin >> b;
	cout << "a = " << a;
	cout << "b = " << b;
	cout << "a + b = " << a + b;
	cout << "a - b = " << a - b;
	cout << "a * b = " << a * b;
	cout << "\na * num = " << a * num;
	cout << "b * num = " << b * num;
	cout << "a / num = " << a / num;
	cout << "b / num = " << b / num;
	return 0;
}