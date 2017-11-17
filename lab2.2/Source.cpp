//����� 2, ���� 2, ������� 2. 
//������� �.�., ����� �����, ����� �� �����, ���� ���������� ���������.
/*
1 - ���� ���������(�����) ��������� +
2 - ����� +
3 - �������� ����������������� ���������� +
4 - ����� ��������� ����������������� ���������� +
5 - ����� � ������� ��������� � ����������� ��������� ��������� ����
6 - ����� � ������� �������� �������� � �������� ��������� ���� ��� � �������� ������� � ���� �� �������� +-
7 - �������� ��������� ��������
8 - ���������(��������������) ��������� ��������
9 - ���������� ������� �������� � ������� ����������� ��������� ���� +
	(��� ���������� ����� ������������ ��� ����, ��� � ��++ ����������� ������������ ����������������� ����������)
10 - ���������� � ��������� � �������������� ���� ��������� ������� �� ��������� ������� � �������
	(��������, ����� ����� �� ���� ������) - ������ ������������� 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include <ctime>

typedef struct
{
	bool isEmpty;
	int id;
	int test;
	
	/*char firstName[80];
	char lastName[80];
	char *patronymic[80];
	
	unsigned long long accNum;
	unsigned long fundSum;
	SYSTEMTIME lasEdited;
*/
} Account;

void fillAcc(Account *accounts, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		(accounts + i)->id = i;
		(accounts + i)->isEmpty = false;
		(accounts + i)->test = 1 + rand() % 100;
	}
}

void printArrayTest(Account *accounts, int arrSize)
{
	printf("id	test\n\n");
	for (int i = 0; i < arrSize; i++)
	{
		printf("%d	", (accounts + i)->id);
		printf("%d	", (accounts + i)->test);
		printf("\n");
	}
	printf("\n");
}

void scanAcc(Account *accounts, int id)
{
	printf("please enter a number:\n");
	scanf("%d", &(accounts + id)->test);
}

void printAcc(Account *accounts, int id)
{
	if ((accounts + id)->isEmpty == false)
		printf("%d \n", (accounts + id)->test);
	else
		printf("account with this id doesent exist\n");
}

void clearingAcc(Account *accounts, int id, int arrSize)
{
	if (id < arrSize)
	{
		(accounts + id)->isEmpty = true;
		(accounts + id)->test = 0;
	}
}

void freePlaceSearch(Account *accounts, Account *acc, int arrSize)
{
	int i;
	for (i = 0; i < arrSize && (accounts + i)->isEmpty == false; i++);
	if ((accounts + i)->isEmpty == true)
		(accounts + i)->test = acc->test;
	else
		printf("there is no free places\n");
}

int minSearch(Account *accounts, int arrSize)
{
	int min = accounts[0].test;
	for (int i = 0; i < arrSize; i++)
	{
		if (min > (accounts + i)->test)
			min = (accounts + i)->test;
	}
	return min;
}

Account* searchAcc(Account *accounts, Account *acc, int arrSize)
{
	int i;
	for (i = 0; i < arrSize && (accounts + i)->test != acc->test; i++);
	if (i < arrSize && (accounts + i)->isEmpty == false)
		return (accounts + i);	
	else
	{
		int minDiff = accounts[0].test;
		int m = 0;
		for (i = 0; i < arrSize; i++)
		{
			if (abs(acc->test - (accounts + i)->test) < minDiff)
			{
				minDiff = (accounts + i)->test;
				m = i;
			}
		}
		return (accounts + m);
}

void removeAcc(Account *accounts, int id)
{
	(accounts + id)->test = 0;
}

void editElement(Account *accounts, int id, int arrSize)
{
	if (id < arrSize)
		(accounts + id)->isEmpty = true;
}

void sortAcc(Account *accounts, int arrsize)
{
	bool isSwap;
	do {
		isSwap = false;
		int lastSwap = 0;
		for (int i = 0; i < arrsize - 1; i++)
		{
			if ((accounts + i)->test > (accounts + i + 1)->test)
			{
				Account t = *(accounts + i);
				*(accounts + i) = *(accounts + i + 1);
				*(accounts + i + 1) = t;
				isSwap = true;
				lastSwap = i + 1;
			}
		}
		arrsize = lastSwap;
	} while (isSwap);
}

void main()
{
	int arrSize = 20;

	Account *accounts = (Account *)malloc(arrSize * sizeof(Account));

	Account acc;
	acc.test = 6;
	//acc.isEmpty = true;

	fillAcc(accounts, arrSize);
	printArrayTest(accounts, arrSize);
	printf("%d\n", (searchAcc(accounts, &acc, arrSize))->id);
	//printArrayTest(accounts, arrSize);

	free(accounts);
}