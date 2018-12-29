#include <iostream>

using namespace std; 

void FindMax(int* arr, int n, int& maxIndex, int& maxItem); 
void FindMaxInMatrix(int** matrix, int n, int m, int* indexArray, int* maxItemArray); 
void Display(int** matrix, int n, int m, int* indexArray, int* maxItemArray);

int main()
{
	setlocale(LC_ALL, "rus"); 
	int n, m;
	cout << "¬ведите размерность матрицы :"; 
	cin >> n >> m; 

	int** matrix = new int*[n]; 
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m]; 
	}
	int* indexArray = new int[n]; 
	int* maxItemArray = new int[n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = rand() % 30; 
		}
	}

	FindMaxInMatrix(matrix, n, m, indexArray, maxItemArray); 

	Display(matrix, n, m, indexArray, maxItemArray); 
	system("pause"); 
	return 0; 
}

void FindMax(int* arr, int n, int& maxIndex, int& maxItem)
{
	maxIndex = 0; 
	maxItem = arr[maxIndex]; 

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > arr[maxIndex])
		{
			maxIndex = i; 
			maxItem = arr[i]; 
		}
	}
}

void FindMaxInMatrix(int** matrix, int n, int m, int* indexArray, int* maxItemArray)
{
	for (int i = 0; i < n; i++)
	{
		int maxIndex; 
		int maxItem; 
		FindMax(matrix[i], m, maxIndex, maxItem); 
		indexArray[i] = maxIndex; 
		maxItemArray[i] = maxItem; 
	}
}

void Display(int** matrix, int n, int m, int* indexArray, int* maxItemArray)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << "  "; 
		}
		cout << "\t" << indexArray[i] << "\t\t" << maxItemArray[i] << "\n\n"; 
	}
}