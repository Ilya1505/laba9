// C++.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include <Conio.h>
#include<Windows.h>
#include <iostream>
#include <string>

//const string NAME = "No_Name";
//const string COLOR = "No_Color";

using namespace std;

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
	engine(string name)
	{
		this->name = name;
		this->weight = 50;
		this->power = 100;
		this->probeg = 0;
		this->resurs = 100;
	}
	engine()// ����������� ��� ����������
	{
		name = "No_Name";
		weight = 10;
		power = 100;
		probeg = 0;
		resurs = 300;
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
	int *year;// ��� �������
	string name;// ����� ����
	string color;// ���� ����
	double price;// ����
	engine dvs;// ���������
public:
	cars(const cars &other)
	{
		this->year = new int;
		*this->year = *other.year;
		this->name = other.name;
		this->color = other.color;
		this->price = other.price;
		this->dvs = other.dvs;

	}
	cars(int year, string name, string color, double price, engine dvs)// ����������� � �����������
	{
		this->year = new int;
		this->name = name;
		this->color = color;
		*this->year = year;
		this->price = price;
		this->dvs = dvs;//��������� ���������
	}
	cars(engine dvs)// ����������� � ����� ����������
	{
		this->year = new int;
		this->name = "No_Name";
		this->color = "No_Color";
		*(this->year) = 2020;
		this->price = 1000;
		this->dvs = dvs;//��������� ���������
	}
	cars()// ����������� ��� ����������
	{
		this->year = new int;
		name = "No_Name";
		color = "No_Color";
		*year = 2020;
		price = 0;

	}
	// ������� � �������
	void SetName(string name)
	{
		this->name = name;
	}
	void SetColor(string color)
	{
		//this->color = color;
	}
	void SetYear(int year)
	{
		*this->year = year;
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
		//return color;
	}
	int GetYear()
	{
		return *year;
	}
	double GetPrice()
	{
		return price;
	}
	void OutputCars()// �������� ������ ������
	{
		cout << endl << "����� ������: " << name << endl;
		//cout << "���� ������: " << color << endl;
		cout << "��� �������: " << *year << endl;
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
		//getline(cin, color);
		cout << "��� ������� ������: ";
		cin >> *year;
		cout << "����: ";
		cin >> price;
		dvs.Read();
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
	printf("�������������:");
	engine dvs("��-01", 10, 100, 0, 400);
	cars avto1(2020, "No_Name", "No_Color", 1000, dvs);// ����� ������������ �� ����� ����������� (������ ������)
	cars avto2(dvs); // ����� ������������ � ����� ���������� (������ ������)
	cars avto3; // ����� ������������ ��� ���������� (������ ������)
	cars *AvtoDin1 = new cars(2020, "No_Name", "No_Color", 5000, dvs);// ����� ������������ �� ����� ����������� (������� ������)
	cars *AvtoDin2 = new cars(dvs);// ����� ������������ � ����� ���������� (������� ������)
	cars *AvtoDin3 = new cars();// ����� ������������ ��� ���������� (������� ������)
	cars avto4 = avto3;
	AvtoDin3->OutputCars();

	//engine b("��-02", 10, 100, 0, 500);
	//engine c = a + b;// ���������� ��������� +
	//++c;// ���������� ��������� ++ �������
	//engine dvs = c++;// ���������� ��������� ++ �������� 
	//cars avto("no_name", "no_color", 0, 0, 1000, dvs);
	//avto.OutputCars();
	//avto.PutCars();
	//printf("\n������ ����� �����:");
	//avto.OutputCars();
	//Drive(&avto);
	//printf("\n����� ����-������:");
	//avto.OutputCars();
	//avto.Modern(100, 200, 500);
	//printf("\n����� ������������:");
	//avto.OutputCars();
	//avto.SellCars();
	//printf("\n����� �������:");
	//avto.OutputCars();
	////������ � ������������� �����������
	//printf("\n������������ ����������\n");
	//printf("�������������:\n");
	//cars* avto1 = new cars("no_name", "no_color", 0, 0, 100, dvs);
	//avto1->OutputCars();
	//avto1->PutCars();
	//printf("\n������ ����� �����:\n");
	//avto1->OutputCars();
	//Drive(avto1);
	//printf("����� ����-������:\n");
	//avto1->OutputCars();
	//avto1->Modern(100, 200, 500);
	//printf("����� ������������:\n");
	//avto1->OutputCars();
	//avto1->SellCars();
	//printf("����� ������� \n");
	//avto1->OutputCars();
	//delete avto1;
	////������ � ������������ �������� ����� new
	//int n;
	//printf("\n������������ ������ � ������� new\n");
	//printf("\n������� ����������� �������: ");
	//scanf("%d", &n);
	//cars* avtoArray = new cars[n];
	//printf("\n�������������:\n");
	//for (int i = 0; i < n; i++)
	//{
	//	(avtoArray + i)->init("no_name", "no_color", 0, 0, 1000, dvs);
	//}
	//for (int i = 0; i < n; i++)
	//{
	//	(avtoArray + i)->OutputCars();
	//}
	//for (int i = 0; i < n; i++)
	//{
	//	(avtoArray + i)->PutCars();
	//}
	//printf("\n������ ����� �����:\n");
	//for (int i = 0; i < n; i++)
	//{
	//	(avtoArray + i)->OutputCars();
	//}
	//printf("����-�����\n");
	//for (int i = 0; i < n; i++)
	//{
	//	Drive(avtoArray + i);
	//}
	//printf("����� ����-������:\n");
	//for (int i = 0; i < n; i++)
	//{
	//	(avtoArray + i)->OutputCars();
	//}
	//for (int i = 0; i < n; i++)
	//{
	//	(avtoArray + i)->Modern(100, 200, 500);
	//}
	//printf("����� ������������:\n");
	//for (int i = 0; i < n; i++)
	//{
	//	(avtoArray + i)->OutputCars();
	//}
	//for (int i = 0; i < n; i++)
	//{
	//	(avtoArray + i)->SellCars();
	//}
	//printf("����� ������� \n");
	//for (int i = 0; i < n; i++)
	//{
	//	(avtoArray + i)->OutputCars();
	//}
	//delete[] avtoArray;
	getch();
	return 0;
}
