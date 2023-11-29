#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <float.h>

using namespace std;

int FillMatrix(vector<vector <int>>&, int);
void PrintMatrix(vector<vector <int>>&, int);
void PrimaKraskalaAlgorithm();
void DijkstraAlgoritm();
int main()
{
	PrimaKraskalaAlgorithm();
	DijkstraAlgoritm();
}
int FillMatrix(vector<vector <int>>& matrix, int size)
{
	matrix.resize(size);
	for (int i = 0; i < size; i++)
		matrix[i].resize(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; ++j)
		{
			matrix[i][j] = rand() % 20;
			matrix[j][i] = matrix[i][j];
		}
		matrix[i][i] = 0;
	}
	return 0;
}
void PrintMatrix(vector<vector <int>>& matrix, int size)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix.size(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
void PrimaKraskalaAlgorithm()
{
	cout << "Prima-Kraskala algorithm: " << endl;
	int size;
	cout << "Enter the matrix dimension: ";
	cin >> size;
	int* color_arr = new int[size];
	int* res_arr1 = new int[size];
	int* res_arr2 = new int[size];
	vector<vector <int>> matrix;
	cout << "Load matrix: " << endl;
	FillMatrix(matrix, size);
	PrintMatrix(matrix, size);
	double min_length, length = 0;
	int k = 0;
	int row_ind, column_ind;
	for (int i = 0; i < size; i++)
		color_arr[i] = i;
	while (k < size - 1)
	{
		min_length = DBL_MAX;
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				if (matrix[i][j] < min_length && color_arr[i] != color_arr[j])
				{
					min_length = matrix[i][j];
					row_ind = i;
					column_ind = j;
				}
			}
		}
		length += min_length;
		res_arr1[k] = row_ind;
		res_arr2[k] = column_ind;
		k++;
		for (int i = 1; i <= size; i++)
		{
			if (color_arr[i] == color_arr[column_ind])
				color_arr[i] = color_arr[row_ind];
		}
	}
	for (int i = 0; i < size - 1; i++)
		cout << res_arr1[i] << " " << res_arr2[i] << endl;
	cout << "Minimum spanning tree length: " << length << endl << endl;
	delete[] color_arr;
	delete[] res_arr1;
	delete[] res_arr2;

}
void DijkstraAlgoritm()
{
	cout << "Dijkstra algoritm: " << endl;
	int size;
	cout << "Enter the matrix dimension: ";
	cin >> size;
	vector<vector <int>> matrix;
	cout << "Load matrix: " << endl;
	FillMatrix(matrix, size);
	PrintMatrix(matrix, size);

	vector<vector<int>>metrics; 
	for (int k = 0;k < matrix.size();k++)
	{
		int num_begin = k;
		vector <bool> label_array(matrix.size());
		vector <int> distance_array(matrix.size());
		label_array[num_begin] = 1;
		for (int i = 0; i < distance_array.size(); i++)
		{
			distance_array[i] = matrix[num_begin][i];
			label_array[i] = 0;
		}
		for (int i = 0;i < matrix.size() - 1;i++)
		{
			int min_elem = INT_MAX;
			int min_elem_number = 0;
			for (int j = 0; j < distance_array.size();j++)
			{
				if (min_elem > distance_array[j] && label_array[j] == 0)
				{
					min_elem_number = j;
					min_elem = distance_array[j];
				}
			}
			label_array[min_elem_number] = 1;
			for (int j = 0;j < distance_array.size();j++)
			{
				if (label_array[j] == 0)
					distance_array[j] = min(distance_array[j], min_elem + matrix[min_elem_number][j]);
			}
		}
		metrics.push_back(distance_array);
	}
	cout << "Shortest distance matrix: " << endl;
	for (int i = 0;i < metrics.size();i++)
	{
		for (int j = 0;j < metrics[i].size();j++)
			cout << metrics[i][j] << " ";
		cout << endl;
	}
}
