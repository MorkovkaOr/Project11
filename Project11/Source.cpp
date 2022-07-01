#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

int** Allocate(const int rows, const int cols);
void Clear(int**& arr, const int rows);


void FillRand(int** arr, const int rows, const int cols);

void Print(int** arr, const int rows, const int cols);

void insert_row(int**& arr, int& rows, const int cols, int position);
void insert_col(int** arr, const int rows,  int& cols, int position);
void push_col_right(int** arr, const int rows, int& cols);
void push_col_left(int** arr, const int rows, int& cols);
void push_row_down(int**& arr, int& rows, const int cols);
void push_row_up(int**& arr, int& rows, const int cols);
void pop_row_down(int**& arr, int& rows, const int cols);
void pop_row_up(int**& arr, int& rows, const int cols);
void erase_row(int**& arr, int& rows, const int cols, int position);
void pop_col_right(int** arr, const int rows, int& cols);
void pop_col_left(int** arr, const int rows, int& cols);
void erase_col(int** arr, const int rows, int& cols, int position);
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	cout << "»сходный массив:\n";
	Print(arr, n);

	int value;
	cout << "¬ведите добавл€емое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "¬ведите добавл€емое значение: "; cin >> value;
	//arr = push_front(arr, n, value);
	Print(arr = push_front(arr, n, value), n);
	Print(arr = pop_back(arr, n), n);
	Print(arr = pop_front(arr, n), n);
	delete[] arr;
#endif // DYNAMIC_MEMORY_1
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
	cout << arr << endl;
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
void Clear(int**& arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;	
	arr = nullptr;
}

void Print(int** arr, const int rows, const int cols)
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
void insert_row(int**& arr, int& rows, const int cols, int position)
{
	int** buffer = new int* [rows + 1]{};
	for (int i = 0,b=0; b < rows; i++,b++)
	{
		
		buffer[i] = arr[b];
		if (i == position-1)
		{
			buffer[position] = new int[cols] {};
			i++;
		}
	}
	delete[] arr;
	arr = buffer;
	rows++;

}
void push_row_down(int**& arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[rows] = new int[cols] {};
	rows++;
}
void push_row_up(int**& arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new int[cols] {};
	rows++;
}
void push_col_right(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void push_col_left(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j+1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
void insert_col(int** arr, const int rows, int& cols, int position)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
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
void pop_row_down(int**& arr, int& rows, const int cols)
{
	int** buffer = new int* [rows - 1]{};
	for (int i = 0; i < rows-1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows--;
}
void pop_row_up(int**& arr, int& rows, const int cols)
{
	int** buffer = new int* [rows - 1]{};
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	arr = buffer;
	rows--;
}
void erase_row(int**& arr, int& rows, const int cols, int position)
{
	int** buffer = new int* [rows - 1]{};
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
void pop_col_right(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0; j < cols-1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void pop_col_left(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
		for (int j = 0; j < cols-1; j++)
		{
			buffer[j] = arr[i][j+1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
void erase_col(int** arr, const int rows, int& cols, int position)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1]{};
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