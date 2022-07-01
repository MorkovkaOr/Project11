#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
int** Allocate(const int rows, const int cols);
char** Allocatec(const int rows, const int cols);
template<typename T>
void Clear(T**& arr, const int rows);

void FillRand(int** arr, const int rows, const int cols);
void FillRand(char** arr, const int rows, const int cols);
template<typename T>
void Print(T** arr, const int rows, const int cols);
template<typename T>
void insert_row(T**& arr, int& rows, const int cols, int position);
template<typename T>
void insert_col(T** arr, const int rows,  int& cols, int position);
template<typename T>
void push_col_right(T** arr, const int rows, int& cols);
template<typename T>
void push_col_left(T** arr, const int rows, int& cols);
template<typename T>
void push_row_down(T**& arr, int& rows, const int cols);
template<typename T>
void push_row_up(T**& arr, int& rows, const int cols);
template<typename T>
void push_row_down(T**& arr, int& rows, const int cols);
template<typename T>
void pop_row_up(T**& arr, int& rows, const int cols);
template<typename T>
void pop_row_down(T**& arr, int& rows, const int cols);
template<typename T>
void erase_row(T**& arr, int& rows, const int cols, int position);
template<typename T>
void pop_col_right(T** arr, const int rows, int& cols);
template<typename T>
void pop_col_left(T** arr, const int rows, int& cols);
template<typename T>
void erase_col(T** arr, const int rows, int& cols, int position);
template<typename T>
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
	int position;
	int rows;	//количество строк
	int cols;	//количество элементов строки
	cout << "¬ведите количество строк: "; cin >> rows;
	cout << "¬ведите количество элементов строки: "; cin >> cols;

	//ќбъ€вление двумерного динамического массива:
	int** arr = Allocate(rows, cols);

	//»спользование двумерного динамического массива:
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	push_row_up(arr, rows, cols);
	Print(arr, rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	push_row_down(arr, rows, cols);
	Print(arr, rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	push_col_right(arr, rows, cols);
	Print(arr, rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	
	push_col_left(arr, rows, cols);
	Print(arr, rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "¬ведите индекс добавл€емой строки "; cin >> position;
	insert_row(arr, rows, cols, position);
	Print(arr, rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "¬ведите индекс добавл€емого столбца "; cin >> position;
	insert_col(arr, rows, cols, position);
	Print(arr, rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	pop_row_down(arr, rows, cols);
	Print(arr, rows, cols);
	
	pop_row_up(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "¬ведите индекс удал€емой строки "; cin >> position;
	erase_row(arr, rows, cols, position);
	Print(arr, rows, cols);

	pop_col_right(arr, rows, cols);
	Print(arr, rows, cols);

	pop_col_left(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "¬ведите индекс удал€емого столбца "; cin >> position;
	erase_col(arr, rows, cols, position);
	Print(arr, rows, cols);

	Clear(arr, rows);

	//ќбъ€вление двумерного динамического массива:
	char** arrc = Allocate(rows, cols);

	//»спользование двумерного динамического массива:
	FillRand(arrc, rows, cols);
	Print(arrc, rows, cols);

	push_row_up(arrc, rows, cols);
	Print(arrc, rows, cols);

	FillRand(arrc, rows, cols);
	Print(arrc, rows, cols);

	push_row_down(arrc, rows, cols);
	Print(arrc, rows, cols);

	FillRand(arrc, rows, cols);
	Print(arrc, rows, cols);

	push_col_right(arrc, rows, cols);
	Print(arrc, rows, cols);

	FillRand(arrc, rows, cols);
	Print(arrc, rows, cols);

	push_col_left(arrc, rows, cols);
	Print(arrc, rows, cols);

	FillRand(arrc, rows, cols);
	Print(arrc, rows, cols);

	cout << "¬ведите индекс добавл€емой строки "; cin >> position;
	insert_row(arrc, rows, cols, position);
	Print(arrc, rows, cols);

	FillRand(arrc, rows, cols);
	Print(arrc, rows, cols);
	cout << "¬ведите индекс добавл€емого столбца "; cin >> position;
	insert_col(arrc, rows, cols, position);
	Print(arrc, rows, cols);

	FillRand(arrc, rows, cols);
	Print(arrc, rows, cols);

	pop_row_down(arrc, rows, cols);
	Print(arrc, rows, cols);

	pop_row_up(arrc, rows, cols);
	Print(arrc, rows, cols);

	cout << "¬ведите индекс удал€емой строки "; cin >> position;
	erase_row(arrc, rows, cols, position);
	Print(arrc, rows, cols);

	pop_col_right(arrc, rows, cols);
	Print(arrc, rows, cols);

	pop_col_left(arrc, rows, cols);
	Print(arrc, rows, cols);

	cout << "¬ведите индекс удал€емого столбца "; cin >> position;
	erase_col(arrc, rows, cols, position);
	Print(arrc, rows, cols);

	Clear(arrc, rows);
}

int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}
char** Allocatec(const int rows, const int cols)
{
	char** arr = new char* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new char[cols] {};
	}
	return arr;
}


template<typename T>
void Clear(T**& arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;	
	arr = nullptr;
}
template<typename T>
void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(arr + i) + j) << tab;
		}
		cout << endl;
	}
	cout << endl;
}

void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void FillRand(char** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
		}
	}
}
template<typename T>
void insert_row(T**& arr, int& rows, const int cols, int position)
{
	T** buffer = new T* [rows + 1]{};
	for (int i = 0,b=0; b < rows; i++,b++)
	{
		
		buffer[i] = arr[b];
		if (i == position-1)
		{
			buffer[position] = new T[cols] {};
			i++;
		}
	}
	delete[] arr;
	arr = buffer;
	rows++;

}
template<typename T>
void push_row_down(T**& arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[rows] = new T[cols] {};
	rows++;
}
template<typename T>
void push_row_up(T**& arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new T[cols] {};
	rows++;
}
template<typename T>
void push_col_right(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>
void push_col_left(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j+1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>
void insert_col(T** arr, const int rows, int& cols, int position)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0,b=0; j < cols; j++,b++)
		{
			buffer[b] = arr[i][j];
			if (j == position - 1)
			{
				b++;
			}
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>
void pop_row_down(T**& arr, int& rows, const int cols)
{
	T** buffer = new T* [rows - 1]{};
	for (int i = 0; i < rows-1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows--;
}
template<typename T>
void pop_row_up(T**& arr, int& rows, const int cols)
{
	T** buffer = new T* [rows - 1]{};
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	arr = buffer;
	rows--;
}
template<typename T>
void erase_row(T**& arr, int& rows, const int cols, int position)
{
	T** buffer = new T* [rows - 1]{};
	for (int i = 0,b=0; i < rows - 1; i++,b++)
	{

		buffer[i] = arr[b];
		if (i == position-1)
		{
			b++;
		}
	}
	delete[] arr;
	arr = buffer;
	rows--;
}
template<typename T>
void pop_col_right(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols-1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T>
void pop_col_left(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols-1; j++)
		{
			buffer[j] = arr[i][j+1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T>
void erase_col(T** arr, const int rows, int& cols, int position)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0, b = 0; j < cols - 1; j++, b++)
		{
			buffer[j] = arr[i][b];
			if (j == position - 1)
			{
				b++;
			}
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}