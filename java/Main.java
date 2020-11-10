import java.util.Scanner;
public class Main
{
	public static void main(String[] args)
	{
	System.out.println("�������������: "+System.lineSeparator());
	engine dvs = new engine("no_name", 10, 100, 0, 300);
	cars avto = new cars("no_name", "no_color", 0, 1000, dvs);
	AfterDrive rezult = new AfterDrive();// ������ ���������������� ������
	int probeg;
	avto.OutputCars();
	avto.PutCars();
	System.out.println(System.lineSeparator()+"������ ����� �����: ");
	avto.OutputCars();
	avto.Drive(rezult);
	probeg=rezult.km;
	System.out.println(System.lineSeparator()+"������ ����� ����-������: ");
	System.out.println(probeg+" ��"+System.lineSeparator());
	avto.Modern(100, 200, 500);
	System.out.println("����� ������������: ");
	avto.OutputCars();
	// ������ ��������
	engine []arrayE = new engine[2];
	for(int i=0;i<arrayE.length;i++)
	{
		arrayE[i] = new engine("no_name", 10, 100, 0, 300);
	}
	cars []arrayC = new cars[2];
	for(int i=0; i<arrayC.length;i++)
	{
		arrayC[i]=new cars("no_name", "no_color", 0, 1000, arrayE[i]);
	}
	for(int i=0; i<arrayC.length;i++)
	{	
		System.out.println(System.lineSeparator());
		arrayC[i].OutputCars();
	}
	for(int i=0; i<arrayC.length;i++)
	{	System.out.println(System.lineSeparator());
		arrayC[i].PutCars();
	}
	System.out.println(System.lineSeparator()+"������ ����� �����: ");
		for(int i=0; i<arrayC.length;i++)
	{	System.out.println(System.lineSeparator());
		arrayC[i].OutputCars();
	}
	System.out.println(System.lineSeparator()+"������ ����� ����-������: ");
	for(int i=0; i<arrayC.length;i++)
	{	arrayC[i].Drive(rezult);
		probeg=rezult.km;
		System.out.println(System.lineSeparator());
		System.out.println(probeg+" ��");
	}
	for(int i=0; i<arrayC.length;i++)
	{
		arrayC[i].Modern(100, 200, 500);
	}
	System.out.println(System.lineSeparator()+"����� ������������: ");
	for(int i=0; i<arrayC.length;i++)
	{	System.out.println(System.lineSeparator());
		arrayC[i].OutputCars();
	}
	System.out.println(System.lineSeparator()+"����� ���������� �����: "+avto.GetCount());
	}
};

class AfterDrive// ��������������� �����
{
	public int km;
}

class engine// ���������
{
	private String name=new String();// ����� ���������
	private double weight;// ���
	private int power;// �������� (�.�.)
	private int probeg;// ������
	private int resurs;// ������ ���������

	public engine(String name, double weight, int power, int probeg, int resurs)// ����������� � �����������
	{
		this.name=name;
		this.weight = weight;
		this.power = power;
		this.probeg = probeg;
		this.resurs = resurs;
	}
	public engine()// ����������� ��� ����������
	{
		name="no_name";
		weight = 10;
		power = 100;
		probeg = 0;
		resurs = 300;
	}
	// ������� � �������
	public void SetName(String name)
	{
		this.name=name;
	}
	public void SetWeight(double weight)
	{
		this.weight = weight;
	}
	public void SetPower(int power)
	{
		this.power = power;
	}
	public void SetProbeg(int probeg)
	{
		this.probeg = probeg;
	}
	public void SetResurs(int resurs)
	{
		this.resurs = resurs;
	}
	public String GetName()
	{
		return name;
	}
	public double GetwWight()
	{
		return weight;
	}
	public int GetPower()
	{
		return power;
	}
	public int GetProbeg()
	{
		return probeg;
	}
	public int GetResurs()
	{
		return resurs;
	}
	public void Remont()// ������ ���������
	{
		probeg = 0;
	}
	public void Read()// ���� ������
	{
		Scanner read = new Scanner(System.in);
		System.out.println("������� ����� ���������: ");
		name=read.nextLine();
		System.out.println("������� �������� ���������: ");
		power=read.nextInt();
		System.out.println("������� ������ ���������: ");
		probeg=read.nextInt();
		System.out.println("������� ������ ���������: ");
		resurs=read.nextInt();
		System.out.println("������� ��� ���������: ");
		weight=read.nextDouble();
	}
	public void Print()// ����� ������
	{
		System.out.println("����� ���������: " + name);
		System.out.println("�������� ���������: " + power);
		System.out.println("������ ���������: " + probeg);
		System.out.println("������ ���������: " + resurs);
		System.out.println("��� ���������: " + weight);
	}
};

class cars// ����� ����
{	
	private static int count;// ����������� ����������, �������� ���������� ��������� �������� cars
	private int id;// ���������� ����� ��� ������� ������� cars
	private String name=new String();// ����� ����
	private String color=new String();// ���� ����
	private int year;// ��� �������
	private double price;// ����
	private engine dvs = new engine();// ���������
	public static int GetCount()// ����������� �����
	{
		return count;
	}
	public cars(String name, String color, int yr, double pr, engine dvs)// ����������� � �����������
	{
		this.name=name;
		this.color=color;
		this.year = yr;
		this.price = pr;
		this.dvs = dvs;//��������� ���������
		count++;
		id=count;
	}
	public cars()// ����������� ��� ����������
	{
		name="no_name";
		color="no_color";
		year = 2000;
		price = 0;
		count++;
		id = count;
	}
	// ������� � �������
	public void SetName(String name)
	{
		this.name=name;
	}
	public void SetYear(int year)
	{
		this.year = year;
	}
	public void SetPrice(double price)
	{
		this.price = price;
	}
	public int GetID()
	{
		return id;
	}
	public String GetName()
	{
		return name;
	}
	public String GetColor()
	{
		return color;
	}
	public int GetYear()
	{
		return year;
	}
	public double GetPrice()
	{
		return price;
	}
	public void PutCars()// �������� ����� ������
	{
		Scanner read = new Scanner(System.in);
		System.out.println("������� ����� ������: ");
		name=read.nextLine();
		System.out.println("������� ���� ������: ");
		color=read.nextLine();
		System.out.println("������� ��� ������� ������: ");
		year=read.nextInt();
		System.out.println("������� ���� ������: ");
		price=read.nextDouble();
		dvs.Read();
	}
	public void OutputCars()// ������� ������ ������
	{
		System.out.println("ID ������: "+id);
		System.out.println("����� ������: " + name);
		System.out.println("���� ������: " + color);
		System.out.println("��� ������� ������: " + year);
		System.out.println("����: " + price);
		dvs.Print();
	}
	public void Drive(AfterDrive rezult)// ����-�����
	{
		rezult.km = dvs.GetProbeg() + 10;
	}
	public void Modern(double NewWeight, int NewPower, int NewResurs)// ������������
	{
		dvs.SetWeight(NewWeight);
		dvs.SetPower(NewPower);
		dvs.SetResurs(NewResurs);
		dvs.Remont();
	}
};