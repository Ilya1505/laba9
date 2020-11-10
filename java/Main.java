import java.util.Scanner;
public class Main
{
	public static void main(String[] args)
	{
	engine dvs1 = new engine("no_name", 10, 100, 0, 1000);// ����������� �� ����� �����������
	cars avto1 = new cars("no_name", "no_color", 2020, 1000, dvs1);// ����������� �� ����� �����������
	engine dvs2 = new engine("no_name");// ����������� � ����� ����������
	cars avto2 = new cars(dvs2);// ����������� � ����� ����������
	cars avto3 = new cars();// ����������� ��� ����������
	AfterDrive rezult = new AfterDrive();// ������ ���������������� ������
	int probeg;
	avto1.OutputCars();
	avto1.PutCars();
	System.out.println(System.lineSeparator()+"������ ����� �����: ");
	avto1.OutputCars();
	avto1.Drive(rezult);
	probeg=rezult.km;
	System.out.println(System.lineSeparator()+"������ ����� ����-������: ");
	System.out.println(probeg+" ��"+System.lineSeparator());
	avto1.Modern(100, 200, 500);
	System.out.println("����� ������������: ");
	avto1.OutputCars();
	// ������ ��������
	engine []arrayE = new engine[2];
	for(int i=0;i<arrayE.length;i++)
	{
		arrayE[i] = new engine("no_name");// ������ �������� ��������� ����� ����������� � ����� ����������
	}
	cars []arrayC = new cars[2];
	for(int i=0; i<arrayC.length;i++)
	{
		arrayC[i]=new cars(arrayE[i]);// ������ �������� ��������� ����� ����������� � ����� ����������
	}
	for(int i=0; i<arrayC.length;i++)
	{	
		System.out.println(System.lineSeparator()+"������ "+(i+1));
		arrayC[i].OutputCars();
	}
	for(int i=0; i<arrayC.length;i++)
	{	System.out.println(System.lineSeparator()+"������ "+(i+1));
		arrayC[i].PutCars();
	}
	System.out.println(System.lineSeparator()+"������ ����� �����: ");
		for(int i=0; i<arrayC.length;i++)
	{	System.out.println(System.lineSeparator()+"������ "+(i+1));
		arrayC[i].OutputCars();
	}
	System.out.println(System.lineSeparator()+"������ ����� ����-������: ");
	for(int i=0; i<arrayC.length;i++)
	{	arrayC[i].Drive(rezult);
		probeg=rezult.km;
		System.out.println(System.lineSeparator()+"������ "+(i+1));
		System.out.println(probeg+" ��");
	}
	for(int i=0; i<arrayC.length;i++)
	{
		arrayC[i].Modern(100, 200, 500);
	}
	System.out.println(System.lineSeparator()+"����� ������������: ");
	for(int i=0; i<arrayC.length;i++)
	{	System.out.println(System.lineSeparator()+"������ "+(i+1));
		arrayC[i].OutputCars();
	}
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

	public engine(String name, double weight, int power, int probeg, int resurs)// ����������� �� ����� �����������
	{
		this.name=name;
		this.weight = weight;
		this.power = power;
		this.probeg = probeg;
		this.resurs = resurs;
	}
	public engine(String name)// ����������� � ����� ����������
	{
		this.name=name;
		this.weight = 10;
		this.power = 100;
		this.probeg = 0;
		this.resurs = 1000;
	}
	public engine()// ����������� ��� ����������
	{
		name="no_name";
		weight = 10;
		power = 100;
		probeg = 0;
		resurs = 1000;
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
	private String name=new String();// ����� ����
	private String color=new String();// ���� ����
	private int year;// ��� �������
	private double price;// ����
	private engine dvs;// ���������
	public cars(String name, String color, int yr, double pr, engine dvs)// ����������� �� ����� �����������
	{	
		this.name=name;
		this.color=color;
		this.year = yr;
		this.price = pr;
		this.dvs = dvs;//��������� ���������
	}
	public cars(engine dvs)// ����������� � ����� ����������
	{	
		this.name="no_name";
		this.color="no_color";
		this.year = 2020;
		this.price = 10000;
		this.dvs=dvs;
	}
	public cars()// ����������� ��� ����������
	{	
		this.dvs = new engine();
		name="no_name";
		color="no_color";
		year = 2000;
		price = 0;
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