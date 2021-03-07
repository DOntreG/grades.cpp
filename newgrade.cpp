/* Programmmer: D'Ontre Gilliard
   Date: 3/6/2021 
*/

#include <iostream>
#include <iomanip>
using namespace std;
const int rows = 2, cols = 5;

int maxRowIndex, maxColIndex;

int minRowIndex, minColIndex;

void getGrades(double[][cols], int, int);
double findHighest(double[][cols], int, int);
double findLowest(double[][cols], int, int);
double findAverage(double[][cols], int, int);

int main() {
	double grades[rows][cols];

	getGrades(grades, rows, cols);


	double highest = findHighest(grades, rows, cols);
	double lowest = findLowest(grades, rows, cols);
	double average = findAverage(grades, rows, cols);

	cout << fixed << setprecision(2) << showpoint;
	
	cout << "The average grade = " << average << endl;
	
	cout << "Student #1 " << (maxRowIndex + 1) << " had received the highest grade of "
		<< highest << " in the exam " << (maxColIndex + 1) << endl;
	
	cout << "Student #2 " << (minRowIndex + 1) << " had received the lowest grade of "
		<< lowest << " in the test " << (minColIndex + 1) << endl;

	return 0;
}

void getGrades(double a[][cols], int rows, int cols) {
	//Get Values
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < cols; j++) 
		{
			cout << "Enter a grade for student " << i + 1 << " and exam " << j + 1 << endl;
			cin >> a[i][j];
		}
	}
}

double findHighest(double a[][cols], int rows, int cols)
{
	//Find the highest

	double highest = a[0][0];
	maxRowIndex = 0;
	maxColIndex = 0;
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < cols; j++) 
		{	
			if (a[i][j] > highest)
			{
				highest = a[i][j];
				maxRowIndex = i;
				maxColIndex = j;
			}
		}
	}

	return highest;
}

double findLowest(double a[][cols], int rows, int cols) 
{
	//Find the lowest
	double lowest = a[0][0];
	minRowIndex = 0;
	minColIndex = 0;
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < cols; j++) 
		{
			if (a[i][j] < lowest) 
			{
				lowest = a[i][j];
				minRowIndex = i;
				minColIndex = j;
			}
		}
	}
	
	return lowest;
}

double findAverage(double a[][cols], int rows, int cols)
{
	//Find the Average
	double total = 0.0;
	double average;
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < cols; j++)
		{
			total += a[i][j];
		}
	}
	average = total / (rows * cols);
	return average;
}
