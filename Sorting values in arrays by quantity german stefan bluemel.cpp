#include <iostream>
using namespace std;

void sortieren(int arr[20], int anzahl);
void sorting(int arr[2][20], int rows, int columns);
void ausgeben2d(int arr[2][20], int rows, int columns,int arr1[20],int anzahl);
void haeufigkeit(int arr[20], int anzahl,int counter[2][20]);

void main(void)
{
	int arr[20] = { 5, 63, 1, 9, 5, 23, 19, 1, 68, 7, 5, 9, 1, 62, 82, 94, 103, 5, 1, 1 };
	int counter[2][20] = { 0 };
	sortieren(arr, 20);
	haeufigkeit(arr, 20, counter);
}

void sortieren(int arr[20], int anzahl)//Sorts 1 dimensional arrays
{
	int helper=0;
	for (size_t i = 0; i < anzahl; i++)
	{
		for (size_t x = 0; x < anzahl - i-1; x++)
		{
			if (arr[x]>arr[x+1])
			{
				helper = arr[x];
				arr[x] = arr[x + 1];
				arr[x + 1] = helper;
			}
		}
	}
}

void haeufigkeit(int arr[20], int anzahl,int counter[2][20])//finds the 3 most frequent values in the array arr[20]
{
	int unique_values = 0;//This var counts how many unique values are contained in the one dimensional array

	for (size_t i = 0; i < anzahl-1; i++)
	{
		if(arr[i]== arr[i+1])//All numbers in the one dimensional array are beeing compared with the value in the same array with an index thats higher than their own by one
		{ 
			counter[0][unique_values] = arr[i];//All numbers in the one dimensional array are getting copied into the first row of the 2 dimensional array if they are not already contained in it
			counter[1][unique_values] = (counter[1][unique_values] + 1);//the second row of the 2 dimensional array counts how many times the value in the row above within the same column exists in the one dimensional array
		}
		else//if a new number has been found
		{
			counter[1][unique_values] = (counter[1][unique_values] + 1);
			unique_values++;// +1 to the count of unique numbers
			counter[0][unique_values] = arr[i+1];
		}
	}
	counter[1][unique_values] = (counter[1][unique_values] + 1);//this line is finishing a task that hasnt been completed within the limits of the loop

	sorting(counter, 2, 20); //2D Array is being sorted
	ausgeben2d(counter, 2, 20,arr,anzahl); //the first three columns and both of the rows of the 2D Array are being displayed in the console
}

void sorting(int arr[2][20], int rows, int columns)//Sorts 2 dimensional arrays
{
	int helper;
	for (size_t i = 0; i < 20; i++)//Repeats the sorting with the bubble sort principle
	{
		for (size_t x = 0; x < 20-i-1; x++)//Navigates through all unsorted fields
		{
			if (arr[1][x] < arr[1][x + 1])//Sorts the values from high to low based on the values of the quantities in the second row of the 2D array
			{
				helper = arr[1][x];
				arr[1][x] = arr[1][x + 1];
				arr[1][x + 1] = helper;

				helper = arr[0][x];
				arr[0][x] = arr[0][x + 1];
				arr[0][x + 1] = helper;
			}
		}
	}
}

void ausgeben2d(int arr[2][20], int rows, int columns, int arr1[20], int anzahl) //Displays the 2 dimensional array
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t x = 0; x < 3; x++)
		{
			cout << arr[i][x] << "  ";
		}
		cout << endl;
	}
}