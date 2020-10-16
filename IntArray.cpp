#include <iostream>
#include<iomanip>

/*
ДОМАШНЕЕ ЗАДАНИЕ
Задание 1: Реализуйте следующие методы для IntArray
+ перегрузите оператор[] (для доступа к элементам массива)
+ перегрузите оператор + для объединения двух массивов (возвращает новый
IntArray, который содержит элементы первого и второго массива)
+ перегрузите оператор ввода и вывода для типа IntArray
*/

class IntArray
{
public:

	IntArray() {
	}

	~IntArray() {
		delete[] m_arr;
	}

	IntArray operator+(const IntArray& right)
	{
		IntArray tmp;
		for (int i = 0; i < m_index; i++) tmp.SetElementEnd(m_arr[i]);

		for (int i = 0; i < right.m_index; i++) tmp.SetElementEnd(right.m_arr[i]);

		return tmp;
	}

	IntArray(IntArray&& other)
	{
		m_arr = other.m_arr;
		m_capacity = other.m_capacity;
		m_index = other.m_index;
		m_count = other.m_count;
		other.m_arr = nullptr;
	}

	IntArray& operator=(const IntArray& other)
	{
		m_index = other.m_index;
		m_size = other.m_size;
		m_capacity = other.m_capacity;
		m_arr = new int[m_size];
		for (int i = 0; i < m_size; i++) {
			m_arr[i] = other.m_arr[i];
		}
		return *this;
	}

	IntArray& operator=(IntArray&& other)
	{
		m_arr = other.m_arr;
		m_capacity = other.m_capacity;
		m_index = other.m_index;
		m_count = other.m_count;
		other.m_arr = nullptr;
		return *this;
	}

	IntArray(const IntArray& other)
	{
		m_index = other.m_index;
		m_size = other.m_size;
		m_capacity = other.m_capacity;
		m_arr = new int[m_size];
		for (int i = 0; i < m_size; i++)
		{
			m_arr[i] = other.m_arr[i];
		}
	}

	static int getCount() {
		return m_count;
	}

	bool arrayState()const
	{
		return (m_index > 0);
	}

	int& operator[](const int number)const
	{
		return m_arr[number];
	}

	int getSize()const
	{
		return m_size;
	}

	int getIndex()const
	{
		return m_index;
	}

	void SetElementStar(int number)
	{
		if (m_index == m_size)capacity();


		if (m_index) {
			int* tmp = new int[m_size];
			tmp[0] = number;

			for (int i = 0, b = 1; i < m_index; b++, i++)
				tmp[b] = m_arr[i];

			m_index++;
			delete[] m_arr;
			m_arr = tmp;
		}
		else {
			m_arr[m_index++] = number;
		}
	}

	void SetElementEnd(const int number)
	{
		if (m_index == m_size)capacity();

		m_arr[m_index++] = number;

	}

private:
	void capacity() {
		m_size += m_capacity;

		int* tmp = new int[m_size];

		for (int i = 0; i < m_index; i++)
			tmp[i] = m_arr[i];

		delete[] m_arr;
		m_arr = tmp;
	}


	size_t  m_size = 5;
	size_t m_index = 0;
	int* m_arr = new int[m_size];
	size_t m_capacity = 5;
	static unsigned int m_count;
};

unsigned int IntArray::m_count = 0;

std::ostream& operator<<(std::ostream& os, IntArray& arr) {
	std::cout << "\nArrar # " << arr.getCount() << "\n __________________\n|                  |\n";
	for (int i = 0; i < arr.getIndex(); i++)
	{
		os << "| arr["
			<< std::right << std::setw(2) << std::setfill(' ') << i << "]  = "
			<< std::right << std::setw(5) << arr[i] << " |\n";
	}
	std::cout << "|__________________|\n\n";
	return os;
}

std::istream& operator>>(std::istream& is, IntArray& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		is >> arr[i];
	}
	return is;
}

int main()
{

	IntArray a;


	a.SetElementEnd(1);
	a.SetElementEnd(2);
	a.SetElementEnd(3);
	a.SetElementEnd(4);
	a.SetElementEnd(5);



	std::cout << "Fill the array = \n";

	//std::cin >> a;

	//OR

	/*for (int i = 0; i < a.getSize(); i++)
	{
		std::cin >> a[i];
	}*/


	std::cout << a;

	// OR

	/*for (int i = 0; i < a.getIndex(); i++)
	{
		std::cout << a[i] << " ";
	}*/


	IntArray b;
	b.SetElementEnd(60);
	b.SetElementEnd(70);
	b.SetElementEnd(80);
	b.SetElementEnd(90);
	b.SetElementEnd(100);

	std::cout << b;


	IntArray c = a + b;

	std::cout << c;
	/*for (int i = 0; i < c.getIndex(); i++)
	{
		std::cout << c[i] << " ";
	}*/

	std::cout << b[4];


}





