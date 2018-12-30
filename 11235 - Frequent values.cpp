#include <iostream>

#include <iomanip>

using namespace std;

//Declaration of Functions

void drawline(char);

void adjacent(char, int);

int main()

{

	//Declaration of Variables

	int num[20];   //array of size 20

	int n;          //number of values

	int c;          //count of num

	double sum = 0;

	double avg;     //the average of the values

	int largest = 1;

	int smallest = 15;

	int count_b5 = 0;   //count of number of values below than 5 initialzed by 0

						//Input

	cout << "Enter the number of values: " << endl;

	cin >> n;

	//Validation

	while ((n <= 0) || (n>20))

	{

		cout << "Invaild input, reenter " << endl;

		cin >> n;

	}

	//Input data to the array

	for (int c = 0; c<n; c++)

	{

		//c is only declared here

		cin >> num[c];

		//Validation

		while ((num[c] <= 0) || (num[c] > 15))

		{

			cout << "Invaild input, reenter " << endl;

			cin >> num[c];

		}

	}

	//Processing

	drawline('=');

	cout << setw(15) << "Number of values: " << n << endl << setw(15) << "Results" << endl;

	drawline('-');

	for (int c = 0; c < n; c++)

	{

		cout << setw(8) << num[c] << setw(5);

		adjacent('#', num[c]);

		drawline('-');

	}

	for (int c = 0; c<n; c++)

	{

		sum = sum + num[c];



		if (num[c] > largest)

			largest = num[c];



		if (num[c]< smallest)

			smallest = num[c];



		//defintion of count_b5

		if (num[c] < 5)

			count_b5++;

	}

	avg = sum / n;

	cout << setw(15) << "Average= " << avg << endl << setw(15) << "Highest value= " << largest << endl << setw(15) << "Lowest value= " << smallest << endl << setw(15) << "Number of Values Below 5=" << count_b5 << endl;

	return 0;

}





//Definitoin of drawline

void drawLine(char ss)

{

	for (int k = 1; k <= 30; k++)

		cout << ss;

	cout << endl;

}

//Defintion of adjacent

void adjacent(char ss, int end) // end is equivalent to num[c]

{

	for (int k = 1; k < end; k++)

		cout << ss;

	cout << endl;

}