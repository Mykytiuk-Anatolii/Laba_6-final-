#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <string>
#include <time.h>
using namespace std;

int task_manager()
{
	int task_number;
RENUMBER:	printf("Menu:\n     1.  Task 1\n     2.  Task 2\n     3.  Task 3\n");
	printf("Enter task number you wanna do: ");
	scanf_s("%d", &task_number);
	if (task_number < 1 || task_number > 3)
	{
		system("cls");
		printf("There is only 3 options!\n\n");
		goto RENUMBER;
	}
	return task_number;
}

/*
Задача 1. Створити дві ієрархії класів з віртуальним та без віртуального успадкуванням з елементами даних класів у кожному класі.
Схема успадкування на рисунку за варіантами.
Створити об’єкти похідних класів з віртуальним та без віртуального успадкуванням. Вивести розміри об’єктів даних класів.
*/
class Base
{
protected:
	int dat;
public:
	Base() : dat(1) {}
	Base(int a) : dat(a) {}
};
class d1 : protected Base
{
protected:
	int dat;
public:
	d1() : dat(1) {}
	d1(int b) : dat(b) {}
	d1(int b, int a) : dat(b), Base(a) {}
};
class d2 : protected Base
{
protected:
	int dat;
public:
	d2() : dat(1) {}
	d2(int c) : dat(c) {}
	d2(int c, int a) : dat(c), Base(a) {}
};
class D1 : protected d1
{
protected:
	int dat;
public:
	D1() : dat(0) {}
	D1(int d) : dat(d) {}
	D1(int d, int b) : dat(d), d1(b) {}
	D1(int d, int b, int a) : dat(d), d1(b, a) {}
};
class D2 : protected Base, protected d2
{
protected:
	int dat;
public:
	D2() : dat(0) {}
	D2(int e) : dat(e) {}
	D2(int e, int a, int c) : dat(e), Base(a), d2(c, a) {}
};
class R : protected D1, protected D2
{
protected:
	int dat;
public:
	R() : dat(0) {}
	R(int f) : dat(f) {}
	R(int f, int a, int b, int c, int d, int e) : dat(f), D1(a, b, d), D2(a, c, e) {}

	void ShowDat()
	{
		cout << "Base: " << Base::dat;
		cout << "Base: " << D1::d1::Base::dat;
		cout << "Base: " << D2::d2::Base::dat;
	}
};
class dv1 : virtual protected Base
{
protected:
	int dat;
public:
	dv1() : dat(1) {}
	dv1(int b) : dat(b) {}
	dv1(int b, int a) : dat(b), Base(a) {}
};
class dv2 : virtual protected Base
{
protected:
	int dat;
public:
	dv2() : dat(1) {}
	dv2(int c) : dat(c) {}
	dv2(int c, int a) : dat(c), Base(a) {}
};
class Dv1 : virtual protected dv1
{
protected:
	int dat;
public:
	Dv1() : dat(0) {}
	Dv1(int d) : dat(d) {}
	Dv1(int d, int b) : dat(d), dv1(b) {}
	Dv1(int d, int b, int a) : dat(d), dv1(b, a) {}
};
class Dv2 : virtual protected Base, virtual protected dv2
{
protected:
	int dat;
public:
	Dv2() : dat(0) {}
	Dv2(int e) : dat(e) {}
	Dv2(int e, int a, int c) : dat(e), Base(a), dv2(c, a) {}
};
class Rv : virtual protected Dv1, virtual protected Dv2
{
protected:
	int dat;
public:
	Rv() : dat(0) {}
	Rv(int f) : dat(f) {}
	Rv(int f, int a, int b, int c, int d, int e) : dat(f), Dv1(a, b, d), Dv2(a, c, e) {}

	void ShowvDat()
	{
		cout << "Base: " << Base::dat;
		cout << "Base: " << Dv1::Base::dat;
		cout << "Base: " << Dv2::Base::dat;
	}
};
void task1()
{
	int a, b, c, d, e, f;
	cout << " a: ";
	cin >> a;
	cout << " b: ";
	cin >> b;
	cout << " c: ";
	cin >> c;
	cout << " d: ";
	cin >> d;
	cout << " e: ";
	cin >> e;
	cout << " f: ";
	cin >> f;

	R A, B(f, a, b, c, d, e);
	cout << "Size of Base: " << sizeof(Base) << endl;
	cout << "Size of d1: " << sizeof(d1) << endl;
	cout << "Size of d2: " << sizeof(d2) << endl;
	cout << "Size of D1: " << sizeof(D1) << endl;
	cout << "Size of D2: " << sizeof(D2) << endl;
	cout << "Size of R: " << sizeof(R) << " or " << sizeof(A) << " or " << sizeof(B) << endl;

	A.ShowDat();
	B.ShowDat();

	Rv C, D(f, a, b, c, d, e);
	cout << "Size of Base: " << sizeof(Base) << endl;
	cout << "Size of dv1: " << sizeof(dv1) << endl;
	cout << "Size of dv2: " << sizeof(dv2) << endl;
	cout << "Size of Dv1: " << sizeof(Dv1) << endl;
	cout << "Size of Dv2: " << sizeof(Dv2) << endl;
	cout << "Size of Rv: " << sizeof(Rv) << " or " << sizeof(C) << " or " << sizeof(D) << endl;

	C.ShowvDat();
	D.ShowvDat();
}
/*
Створити абстрактний клас згідно варіанту.
Для перевірки визначити масив вказівників на абстрактний клас, яким присвоюється адреси об'єктів похідних класів
Задача 2. Створити абстрактний базовий клас чотирикутник із віртуальними
функціями обчислення площі та периметру. Створити похідні класи: квадрат,
прямокутник, паралелограм, трапеція зі своїми функціями площі та периметру.
*/
class Quadrangle
{
public:
	virtual double square() = 0;
	virtual double perimeter() = 0;
};
class Quadrate : Quadrangle
{
public:
	double a;
	Quadrate() : a(1) {}
	Quadrate(double n) : a(n) {}
	virtual double square()override
	{
		return a * a;
	}
	virtual double perimeter()override
	{
		return a * 4;
	}
};
class Rectangl : Quadrangle
{
public:
	double a;
	double b;
	Rectangl() : a(1), b(1) {}
	Rectangl(double n, double m) : a(n), b(m) {}
	virtual double square()override
	{
		return a * b;

	}
	virtual double perimeter()override
	{
		return (a * 2) + (b * 2);
	}
};
class Parallelogram : Quadrangle
{
public:
	double a;
	double b;
	double h;
	Parallelogram() : a(1), b(1), h(1) {}
	Parallelogram(double n, double m, double k) : a(n), b(m), h(k) {}
	virtual double square()override
	{
		return a * h;
	}
	virtual double perimeter()override
	{
		return (a * 2) + (b * 2);
	}
};
class Trapez : Quadrangle
{
public:
	double a;
	double b;
	double c;
	double d;
	double h;
	Trapez() : a(1), b(1), c(1), d(1), h(1) {}
	Trapez(double n, double m, double o, double p, double k) : a(n), b(m), c(o), d(p), h(k) {}
	virtual double square()override
	{
		return (a + b) * h / 2;
	}
	virtual double perimeter()override
	{
		return a + b + c + d;
	}
};
void task2()
{
	cout << " Quadrate: " << endl;
	cout << "---------------" << endl;
	Quadrate q = Quadrate(2);
	cout << "--Square: " << q.square() << endl;
	cout << "--Perimeter: " << q.perimeter() << endl << endl;

	cout << " Rectangle: " << endl;
	cout << "---------------" << endl;
	Rectangl r = Rectangl(2, 3);
	cout << "--Square: " << r.square() << endl;
	cout << "--Perimeter: " << r.perimeter() << endl << endl;


	cout << " Parallelogram: " << endl;
	cout << "---------------" << endl;
	Parallelogram t = Parallelogram(2, 3, 4);
	cout << "--Square: " << t.square() << endl;
	cout << "--Perimeter: " << t.perimeter() << endl << endl;

	cout << " Trapeze: " << endl;
	cout << "---------------" << endl;
	Trapez tr = Trapez(2, 3, 4, 5, 6);
	cout << "--Square: " << tr.square() << endl;
	cout << "--Perimeter: " << tr.perimeter() << endl << endl;
}

/*
Створити ієрархію типів, що описують класи сутностей. Класи мають поля характерні сутності та успадковувати поля батьківських класів.
Визначити конструктори та віртуальні деструктори, перевантажити операції введення та виведення.
В похідному класі визначити виводить інформацію про об’єкт класу, що успадковане від батьківських класів.
Продумати ієрархію типів таким чином щоб похідний клас успадковував двох батьків(множинне спадкування).
Задача 3. Ієрархія типів складається з сутностей: людина, батько, мати, син.
*/
class Human
{
protected:
	string name;
public:
	Human() : name("NoName") {}
	Human(string n) : name(n) {}
	~Human()
	{
		cout << "Human destructor complete" << endl;
	}
	friend ostream& operator<<(ostream& os, Human& a);
	friend istream& operator>>(istream& os, Human& a);

};
ostream& operator<<(ostream& os, Human& a)
{
	os << a.name;
	return os;
}
istream& operator>>(istream& is, Human& a)
{
	is >> a.name;
	return is;
}
/*_________________________________________________________________________________________________*/
class Father
{
protected:
	string hair_color;
public:
	Father() : hair_color("Brown") {}
	Father(string hc) : hair_color(hc) {}
	~Father()
	{
		cout << "Father destructor complete" << endl;
	}
	friend ostream& operator<<(ostream& os, Father& a);
	friend istream& operator>>(istream& os, Father& a);
};
ostream& operator<<(ostream& os, Father& a)
{
	os << a.hair_color;
	return os;
}
istream& operator>>(istream& is, Father& a)
{
	is >> a.hair_color;
	return is;
}
/*_________________________________________________________________________________________________*/
class Mother
{
protected:
	string eyes_color;
public:
	Mother() : eyes_color("Brown") {}
	Mother(string cy) : eyes_color(cy) {}
	~Mother()
	{
		cout << "Mather destructor complete" << endl;
	}
	friend ostream& operator<<(ostream& os, Mother& a);
	friend istream& operator>>(istream& os, Mother& a);
};
ostream& operator<<(ostream& os, Mother& a)
{
	os << a.eyes_color;
	return os;
}
istream& operator>>(istream& is, Mother& a)
{
	is >> a.eyes_color;
	return is;
}
/*_________________________________________________________________________________________________*/
class Son : protected Father, protected Mother, protected Human
{
protected:
	int growth;
public:
	Son() : growth(160) {}
	Son(int g) : growth(g) {}
	Son(int g, string hc, string cy, string n) : growth(g), Father(hc), Mother(cy), Human(n) {}
	~Son()
	{
		cout << "Son destructor complete" << endl;
	}
	friend ostream& operator<<(ostream& os, Son& a);
	friend istream& operator>>(istream& os, Son& a);
};
ostream& operator<<(ostream& os, Son& a) {
	cout << "Growth: " ;
	os << a.growth << endl;
	cout << "Name: " ;
	os << a.name << endl;
	cout << "Hair color: " ;
	os << a.hair_color << endl;
	cout << "Eyes color: " ;
	os << a.eyes_color << endl;
	cout << endl;
	return os;
}
istream& operator>>(istream& is, Son& a) {
	is >> a.growth;
	is >> a.name;
	is >> a.hair_color;
	is >> a.eyes_color;
	return is;
};

void task3()
{
	string name, eyes_color, hair_color;
	int growth;
	cout << "Enter growth: ";
	cin >> growth;
	cout << " Enter name: ";
	cin >> name;
	cout << " Enter eyes color: ";
	cin >> eyes_color;
	cout << " Enter hair color: ";
	cin >> hair_color;
	Son sf = Son(growth, hair_color, eyes_color, name);
	cout << "Son: " << endl;
	cout << sf;
}

int main()
{
TASK:	int task_number = task_manager();
	switch (task_number)
	{
	case 1:
		task1();
		break;
	case 2:
		task2();
		break;
	case 3:
		task3();
		break;
	default:
		break;
	}

	string answer;
FIN:	printf("\nDo you want to do one more task? Enter '1' if you do, and '0' if you don`t: ");
	cin >> answer;
	if (answer == "1")
	{
		system("cls");
		goto TASK;
	}
	if (answer == "0")
	{
		system("cls");
		printf("Bye!");
	}
	else
	{
		printf("Please enter 'yes' or 'no'\n");
		goto FIN;
	}
}
