#include <iostream>
using namespace std;

void ispalinndrome()
{
	int size;
	cout << "Enter the num of letters of the string : ";
	cin >> size;

	char* array1 = new char[size];
	char* ptr1;
	ptr1 = array1;

	cout << "!!!Enter the Alphabets one by one!!!" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Enter the Alphabet : ";
		cin >> ptr1;
		ptr1++;
	}

	ptr1 = array1;

	cout << "Original string!" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << ptr1[i] ;
	}
	cout << endl;
	cout << "Reverse string!" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << ptr1[size-(i+1)];
	}

	cout << endl;
	for (int i = 0; i < size; i++)
	{
		if (ptr1[i] == ptr1[size-(i+1)])
		{
			continue;
		}
		else
		{
			cout << "This is not a Palindrome!" << endl;
			return;
		}
	}

	cout << "This is a palindrome" << endl;
	return;
	
	
}

int main()
{
	ispalinndrome();
	return 0;
}