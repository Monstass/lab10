#include <iostream>
#include <vector>
#include <ctime>
#include <numeric>
#include <iomanip>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void made_vector(vector <float>&, int);
void show_vector(vector <float>&);
float find_average(vector <float>&);
void find_number_less(vector <float>&, float);
void find_deviation(vector <float>&, float);

int main()
{
	vector<float> array;
	int size;
	float average;

	while (1)
	{
		cout << "Enter the size of array: ";
		cin >> size;
		if (size > 0 && size < 33)
		{
			break;
		}
		cout << endl;
	}

	made_vector(array, size);
	show_vector(array);
	average = find_average(array);
	find_number_less(array, average);
	find_deviation(array, average);

	return 0;
}

void made_vector(vector <float>& _array, int _size)
{
	for (int i = 0; i < _size; ++i)
	{
		// push_back - добавляет элементы в конец контейнера
		_array.push_back(rand() % 1000);
	}
}

void show_vector(vector <float>& _array)
{
	cout << "Vector: ";
	// auto i - итератор, на начало контейнера
	for (auto i = _array.begin(); i != _array.end(); ++i)
	{
		// вывод с помощью указателя на итератор
		cout << std::fixed << std::setprecision(2) << *i << "  ";
	}
}

float find_average(vector <float>& _array)
{
	float _average, sum;
	// std::accumulate - сумма элементов контейнера
	sum = std::accumulate(_array.begin(), _array.end(), 0);
	// .size() - размер контейнера
	_average = sum / _array.size();

	cout << endl << "Average: " << _average;

	return _average;
}

void find_number_less(vector <float>& _array, float _average)
{
	int s_less = 0;

	for (auto i = _array.begin(); i != _array.end(); ++i)
	{
		if (*i < _average)
		{
			s_less++;
		}
	}

	cout << endl << "Number of elements less than average: " << s_less;
}

void find_deviation(vector <float>& _array, float _average)
{
	float min, deviation;
	// min_element - нахождение минимального элемента в контейнере
	min = *std::min_element(_array.begin(), _array.end());

	if (min != 0)
	{
		deviation = fabs((_average - min) / min) * 100;
		cout << endl << "Deviation: " << std::fixed << std::setprecision(2) << deviation << "%";
	}
	else
	{
		cout << "Error...";
	}
}