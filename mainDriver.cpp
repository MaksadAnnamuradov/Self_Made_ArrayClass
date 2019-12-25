#include <iostream>
#include "Array.h"
#include <cstdlib>
using namespace std;

int main()
{
	int size, n, temp;
	char choice;

	
	cout << "Please enter initial size for the vector: ";
	cin >> size;
	Array<short> ar(size);
	cout << "\nEnter starting values for the vector with size " << size <<endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter the value for " << i + 1 << " element: ";
		cin >> temp;
		ar.append(temp);

	}
	cout << endl;

	do
	{
		cout << "1. Append. \n2. Pop. \n3. Display. \n4. Quit." << endl;
		cout << "Choose one of the following from menu:";
		cin >> n;

		switch (n)
		{
		case 1: cout << "\nEnter the number to append: ";
			short v;
			cin >> v;
			ar.append(v);
			break;
		case 2: ar.pop();
			cout << "\nThe last element in the vector has been deleted" << endl;
			break;
		case 3: cout << endl;
			for (int i = 0; i <ar.size(); i++)
			{
				cout << ar[i] << endl;
			}
			break;
		case 4: exit(0);
		}

		cout << endl;
		cout << "Do you want to continue (y for yes, n for no): ";
		cin >> choice;
	} while (choice =='y' || choice == 'Y');

	system("pause");
	return 0;
}