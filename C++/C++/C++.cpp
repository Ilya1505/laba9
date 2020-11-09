// C++.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <Conio.h>
#include<Windows.h>
#include <iostream>
#include <string>
using namespace std;
const int LEN = 20;
class engine// ���������
{
private:
	string name;// ����� ���������
	double weight;// ���
	int power;// �������� (�.�.)
	int probeg;// ������
	int resurs;// ������ ���������
public:
	engine(string init_name, double weight, int power, int probeg, int resurs)// ����������� � �����������
	{
		this->name = init_name;
		this->weight = weight;
		this->power = power;
		this->probeg = probeg;
		this->resurs = resurs;
	}
	engine()// ����������� ��� ����������
	{
		name = "no_name";
		weight = 10;
		power = 100;
		probeg = 0;
		resurs = 300;
	}

	engine operator +(const engine & other)// ���������� ��������� +
	{
		engine temp;
		temp.weight = weight + other.weight;
		temp.power = power + other.power;
		temp.probeg = probeg + other.probeg;
		temp.resurs = resurs + other.resurs;
		temp.name = name;
		return temp;
	}

	engine & operator ++()// ���������� ��������� ++, ���������� �����, ������� �� ������
	{
		weight++;
		power++;
		probeg++;
		resurs++;
		return *this;
	}

	engine operator ++(int value)// ���������� ��������� ++, ����������� �����
	{
		engine temp = *this;
		weight++;
		power++;
		probeg++;
		resurs++;
		return temp;
	}
	// ������� � �������
	void SetName(string name)
	{
		this->name = name;
	}
	void SetWeight(double weight)
	{
		this->weight = weight;
	}
	void SetPower(int power)
	{
		this->power = power;
	}
	void SetProbeg(int probeg)
	{
		this->probeg = probeg;
	}
	void SetResurs(int resurs)
	{
		this->resurs = resurs;
	}
	string GetName()
	{
		return name;
	}
	double GetwWight()
	{
		return weight;
	}
	int GetPower()
	{
		return power;
	}
	int GetProbeg()
	{
		return probeg;
	}
	int GetResurs()
	{
		return resurs;
	}
	void Remont()// ������ ���������
	{
		probeg = 0;
	}
	void Read()// ���� ������
	{
		fflush(stdin);
		cout << endl << "����� ���������: ";
		getline(cin, name);
		cout << "��� ���������: ";
		cin >> weight;
		cout << "�������� ���������: ";
		cin >> power;
		cout << "������ ���������: ";
		cin >> probeg;
		cout << "������ ���������: ";
		cin >> resurs;
	}
	void Print()// ����� ������
	{
		cout << "����� ���������: " << name << endl;
		cout << "�������� ���������: " << power << endl;
		cout << "������ ���������: " << probeg << endl;
		cout << "������ ���������: " << resurs << endl;
		cout << "����� ���������: ";
		printf("%.4lf\n", weight);
	}
	~engine()// ����������
	{

	}
};
class cars// ����� ����
{
private:
	string name;// ����� ����
	string color;// ���� ����
	int year;// ��� �������
	int count;// ���������� ����
	double price;// ����
	engine dvs;// ���������
public:
	cars(string name, string color, int year, int count, double price, engine dvs)// ����������� � �����������
	{
		this->name = name;
		this->color = color;
		this->year = year;
		this->count = count;
		this->price = price;
		this->dvs = dvs;//��������� ���������
	}
	cars()// ����������� ��� ����������
	{
		name = "no_name";
		color = "no_color";
		year = 2000;
		count = 0;
		price = 0;
	}
	void init(string name, string color, int year, int count, double price, engine dvs)// ������� �������������
	{
		this->name = name;
		this->color = color;
		this->year = year;
		this->count = count;
		this->price = price;
		this->dvs = dvs;//��������� ���������
	}
	// ������� � �������
	void SetName(string name)
	{
		this->name = name;
	}
	void SetColor(string color)
	{
		this->color = color;
	}
	void SetYear(int year)
	{
		this->year = year;
	}
	void SetCount(int count)
	{
		this->count = count;
	}
	void SetPrice(double price)
	{
		this->price = price;
	}
	string GetName()
	{
		return name;
	}
	string GetColor()
	{
		return color;
	}
	int GetYear()
	{
		return year;
	}
	int GetCount()
	{
		return count;
	}
	double GetPrice()
	{
		return price;
	}
	void OutputCars()// �������� ������ ������
	{
		cout << endl << "����� ������: " << name << endl;
		cout << "���� ������: " << color << endl;
		cout << "��� �������: " << year << endl;
		cout << "����������: " << count << endl;
		cout << "���� ������: ";
		printf("%.4lf\n", price);
		dvs.Print();
	}
	void PutCars()// ������� ����� ������
	{
		fflush(stdin);
		cout << endl << " ���� ������" << endl;
		cout << "����� ������: ";
		getline(cin, name);
		fflush(stdin);
		cout << "���� ������: ";
		getline(cin, color);
		cout << "��� ������� ������: ";
		cin >> year;
		cout << "����������: ";
		cin >> count;
		cout << "����: ";
		cin >> price;
		dvs.Read();
	}
	void SellCars()// ������� ������� ����
	{
		count--;
	}
	void Modern(double NewWeight, int NewPower, int NewResurs)// ������������
	{
		dvs.SetWeight(NewWeight);
		dvs.SetPower(NewPower);
		dvs.SetResurs(NewResurs);
		dvs.Remont();
	}
	friend void Drive(cars *avto);// ����-�����, ������������� ������� ��� ������ car
	~cars()
	{
	}
};

void Drive(cars *avto)// ������� �������� ����� ���������
{
	int probeg;
	probeg = avto->dvs.GetProbeg() + 10;
	avto->dvs.SetProbeg(probeg);
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);// ����������� �������������� �����/������
	SetConsoleOutputCP(1251);
	system("color F0");
	// ������ �� ������������ �����������
	printf("����������� ����������\n");
	printf("�������������:");
	engine a("��-01", 10, 100, 0, 400);
	engine b("��-02", 10, 100, 0, 500);
	engine c = a + b;// ���������� ��������� +
	++c;// ���������� ��������� ++ �������
	engine dvs = c++;// ���������� ��������� ++ �������� 
	cars avto("no_name", "no_color", 0, 0, 1000, dvs);
	avto.OutputCars();
	avto.PutCars();
	printf("\n������ ����� �����:");
	avto.OutputCars();
	Drive(&avto);
	printf("\n����� ����-������:");
	avto.OutputCars();
	avto.Modern(100, 200, 500);
	printf("\n����� ������������:");
	avto.OutputCars();
	avto.SellCars();
	printf("\n����� �������:");
	avto.OutputCars();
	//������ � ������������� �����������
	printf("\n������������ ����������\n");
	printf("�������������:\n");
	cars* avto1 = new cars("no_name", "no_color", 0, 0, 100, dvs);
	avto1->OutputCars();
	avto1->PutCars();
	printf("\n������ ����� �����:\n");
	avto1->OutputCars();
	Drive(avto1);
	printf("����� ����-������:\n");
	avto1->OutputCars();
	avto1->Modern(100, 200, 500);
	printf("����� ������������:\n");
	avto1->OutputCars();
	avto1->SellCars();
	printf("����� ������� \n");
	avto1->OutputCars();
	delete avto1;
	//������ � ������������ �������� ����� new
	int n;
	printf("\n������������ ������ � ������� new\n");
	printf("\n������� ����������� �������: ");
	scanf("%d", &n);
	cars* avtoArray = new cars[n];
	printf("\n�������������:\n");
	for (int i = 0; i < n; i++)
	{
		(avtoArray + i)->init("no_name", "no_color", 0, 0, 1000, dvs);
	}
	for (int i = 0; i < n; i++)
	{
		(avtoArray + i)->OutputCars();
	}
	for (int i = 0; i < n; i++)
	{
		(avtoArray + i)->PutCars();
	}
	printf("\n������ ����� �����:\n");
	for (int i = 0; i < n; i++)
	{
		(avtoArray + i)->OutputCars();
	}
	printf("����-�����\n");
	for (int i = 0; i < n; i++)
	{
		Drive(avtoArray + i);
	}
	printf("����� ����-������:\n");
	for (int i = 0; i < n; i++)
	{
		(avtoArray + i)->OutputCars();
	}
	for (int i = 0; i < n; i++)
	{
		(avtoArray + i)->Modern(100, 200, 500);
	}
	printf("����� ������������:\n");
	for (int i = 0; i < n; i++)
	{
		(avtoArray + i)->OutputCars();
	}
	for (int i = 0; i < n; i++)
	{
		(avtoArray + i)->SellCars();
	}
	printf("����� ������� \n");
	for (int i = 0; i < n; i++)
	{
		(avtoArray + i)->OutputCars();
	}
	delete[] avtoArray;
	getch();
	return 0;
}
