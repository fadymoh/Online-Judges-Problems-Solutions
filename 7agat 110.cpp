#include <iostream>
#include <string>
using namespace std;
void readData(int);
void printAvg(int, int[], float[]);
void worstAvg(int, float[]);
void printID(int, int[], float[], float);
int numStudents;
int sizeID = 40;
int ID[40];
long int sizeGrades = 200;
float Grades[200];
float Avg[40];
int id;
float scores, total = 0;
float worst = 100;
int main()
{
	cout << "Put num of students: ";
	cin >> numStudents;
	while (numStudents > 40)
	{
		cout << "Error Re-enter: ";
		cin >> numStudents;
	}
	readData(numStudents);
	return 0;
}
void readData(int numStudents)
{
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Enter the Student ID: ";
		cin >> id;
		ID[i] = id;
	}

	for (int k = 0; k < numStudents; k++)
	{
		cout << "Enter the 5 scores of the Student: " << endl;

		for (int p = 0; p < 5; p++)
		{
			cin >> scores;

			while (scores > 100)
			{
				cout << "Error,Re-enter: ";
				cin >> scores;
			}
			Grades[p] = scores;
		}

	}
	printAvg(numStudents, ID, Grades);
}
void printAvg(int numStudents, int ID[], float Grades[])
{
	float sum = 0;
	for (int n = 0; n < numStudents; n++)
	for (int m = 0; m <= (numStudents * 5); (m = m + 5))
	{
		sum = sum + (Grades[m] + Grades[m + 1] + Grades[m + 2] + Grades[m + 3]
			+ Grades[m + 4]);
		Avg[n] = (sum / 5);
	}

	for (int z = 0; z < numStudents; z++)
		cout << "ID: " << ID[z] << " Average: " << Avg[z] << endl;
	worstAvg(numStudents, Avg);
}
void worstAvg(int numStudents, float Avg[])
{
	for (int s = 0; s < numStudents; s++)
	if (Avg[s] < worst)
		worst = Avg[s];

	cout << "The worst average of them all is: " << worst << endl;

	printID(numStudents, ID, Avg, worst);
}
void printID(int numStudents, int ID[], float Avg[], float worst)
{
	for (int z = 0; z < numStudents; z++)
	if (Avg[z] == worst)
		cout << "ID: " << ID[z] << " Average: " << Avg[z] << endl;
}