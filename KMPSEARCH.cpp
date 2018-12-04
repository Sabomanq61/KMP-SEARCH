// KMPSEARCH.cpp: определяет точку входа для консольного приложения.
//
#include <iostream>
using namespace std;

void buildD(char *obraz,int * D,int n)
{
	D[0] = -1;
	int k = -1, j = 0;

	for (; j < n - 1;)
	{
		if (k >= 0)
		{
			if (obraz[j] != obraz[k])
			{
				k = D[k];
				continue;
			}
		}
		k++;
		j++;
		if (obraz[j] == obraz[k])
			D[j] = D[k];
		else
			D[j] = k;
	}
}

template <typename T>
void PrintArray(T *a, int n, int i = 0)
{
	for (; i < n; i++)
		cout << a[i];
	cout << endl;
}

int main()
{
	char *stroka = new char[80];
	
	cout << "Enter the string" << endl;

	cin.getline(stroka, 80);
	cout <<"stroka-----"<< stroka<<endl;
	
	cout << strlen(stroka)<<endl;
	char *obraz = new char[80];
	cout << "Enter obraz" << endl;
	
	cin.getline(obraz, 80);
	
	cout << "obraz-----" << obraz<<endl;

	int n = strlen(obraz) , m = strlen(stroka);
	int *D = new int[n];

	buildD(obraz, D, n);

	PrintArray(D, n);
	int i, j;
	bool search = true;
	for (i = j = 0; j < n;)
	{
		if (i - j <= m - n)
		{
			if (j >= 0 && stroka[i] != obraz[j])
			{
				j = D[j];
			}
			else
			{
				i++;
				j++;
			}
		}
		else
		{
			search = false;
			break;
		}
	}

	if (search) 
	{
		cout << "Obraz in stroka" << endl;
		PrintArray(stroka,i, i - n);
		cout << "end index obraz in stroka i=" << i;
	}
	else
	{
		cout << "Not found" << endl;
	}

	system("pause");
	return 0;
}

