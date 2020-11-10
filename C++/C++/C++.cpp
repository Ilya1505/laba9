// C++.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include <Conio.h>
#include<Windows.h>
#include <iostream>
#include <string>


using namespace std;

class engine// ���������
{
private:
	int *power;// �������� (�.�.)
	string name;// ����� ���������
	double weight;// ���
	int probeg;// ������
	int resurs;// ������ ���������
public:
	engine &operator=(const engine &other)// ���������� ���������� =
	{
		if (power != nullptr)// �������� �� �� ������� �������� ���������
			delete power;
		power = new int;
		*this->power = *other.power;
		this->name = other.name;
		this->weight = other.weight;
		this->probeg = other.probeg;
		this->resurs = other.resurs;
		return *this;
	}
	engine(const engine &other)// ����������� � ������ ������������
	{
		this->power = other.power;// ������ ����������� ������ ����������
		this->name = other.name;
		this->weight = other.weight;
		this->probeg = other.probeg;
		this->resurs = other.resurs;
	}
	engine(string init_name, double weight, int power, int probeg, int resurs)// ����������� � �����������
	{
		this->power = new int;
		this->name = init_name;
		this->weight = weight;
		*this->power = power;
		this->probeg = probeg;
		this->resurs = resurs;
	}
	engine(string name)
	{
		this->power = new int;
		this->name = name;
		this->weight = 50;
		*this->power = 100;
		this->probeg = 0;
		this->resurs = 100;
	}
	engine()// ����������� ��� ����������
	{
		this->power = new int;
		name = "No_Name";
		weight = 10;
		*power = 100;
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
		*this->power = power;
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
		return *power;
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
		cin >> *power;
		cout << "������ ���������: ";
		cin >> probeg;
		cout << "������ ���������: ";
		cin >> resurs;
	}
	void Print()// ����� ������
	{
		cout << "����� ���������: " << name << endl;
		cout << "�������� ���������: " << *power << endl;
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
public:
	int *year;// ��� �������
	string name;// ����� ����
	string color;// ���� ����
	double price;// ����
	engine dvs;// ���������
public:
	cars(const cars &other)// ������������ � �������� ������������
	{
		this->year = new int;
		*this->year = *other.year;
		this->name = other.name;
		this->color = other.color;
		this->price = other.price;
		this->dvs = other.dvs;// ���������� ��������� ������������

	}
	cars(int year, string name, string color, double price, engine &dvs)// ����������� � �����������
	{
		this->year = new int;
		this->name = name;
		this->color = color;
		*this->year = year;
		this->price = price;
		this->dvs = dvs;//��������� ���������
	}
	cars(int price)// ����������� � ����� ����������
	{
		this->year = new int;
		this->name = "No_Name";
		this->color = "No_Color";
		*(this->year) = 2020;
		this->price = price;
	}
	cars()// ����������� ��� ����������
	{
		this->year = new int;
		name = "No_Name";
		color = "No_Color";
		*year = 2020;
		price = 1000;

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
		return color;
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
		cout << "���� ������: " << color << endl;
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
		getline(cin, color);
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
	engine dvs1("��-01", 10, 100, 0, 400);
	engine dvs2(dvs1);// ������ �����������
	dvs1.SetPower(500);// ��� ��������� �������� � dvs1, �������� � dvs2 ����� ��������
	cout<<"�������� dvs2: "<<dvs2.GetPower()<<endl<<endl;
	cars avto1(2020, "No_Name", "No_Color", 1000, dvs1);// ����� ������������ �� ����� ����������� (������ ������)
	cars avto2(1000); // ����� ������������ � ����� ���������� (������ ������)
	cars avto3; // ����� ������������ ��� ���������� (������ ������)
	cars *AvtoDin1 = new cars(2020, "No_Name", "No_Color", 5000, dvs1);// ����� ������������ �� ����� ����������� (������� ������)
	cars *AvtoDin2 = new cars(1000);// ����� ������������ � ����� ���������� (������� ������)
	cars *AvtoDin3 = new cars();// ����� ������������ ��� ���������� (������� ������)
	cars avto4 = avto3;// ����������� ��������� �����������
	avto3.SetYear(2015);// ��� ��������� year � avto3, year � avto4 �� ��������
	cout << "������ 1:";
	avto4.OutputCars();
	avto4.PutCars();
	printf("\n������ ����� �����:");
	avto4.OutputCars();
	Drive(&avto4);
	printf("\n����� ����-������:");
	avto4.OutputCars();
	avto4.Modern(100, 200, 500);
	printf("\n����� ������������:");
	avto4.OutputCars();
	//������ � ������������ �������� ����� new
	cars avtoArray[3] = { 1000, 2000, 3000 };
	for (int i = 0; i < 3; i++)
	{
		cout << endl << "������ " << i + 1;
		avtoArray[i].OutputCars();
	}
	for (int i = 0; i < 3; i++)
	{
		cout << endl << "������ " << i + 1;
		avtoArray[i].PutCars();
	}
	printf("\n������ ����� �����:\n");
	for (int i = 0; i < 3; i++)
	{
		cout << endl << "������ " << i + 1;
		avtoArray[i].OutputCars();
	}
	for (int i = 0; i < 3; i++)
	{
		Drive(&avtoArray[i]);
	}
	printf("����� ����-������:\n");
	for (int i = 0; i < 3; i++)
	{
		cout << endl << "������ " << i + 1;
		avtoArray[i].OutputCars();
	}
	for (int i = 0; i < 3; i++)
	{
		avtoArray[i].Modern(100, 200, 500);
	}
	printf("����� ������������:\n");
	for (int i = 0; i < 3; i++)
	{
		cout << endl << "������ " << i + 1;
		avtoArray[i].OutputCars();
	}
	delete AvtoDin1;
	delete AvtoDin2;
	delete AvtoDin3;
	getch();
	return 0;
}
