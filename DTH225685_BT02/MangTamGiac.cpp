#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

class Point
{
private:
    float x, y;

public:
    Point();
    Point(float h, float t);
    void Nhap();
    void Xuat();
    float getX();
    float getY();
    float Distance(Point P);
};
class Triangle
{
protected:
    Point A, B, C;
    float dt, cv;

public:
    Triangle();
    Triangle(Point A, Point B, Point C);
    void Nhap();
    void Xuat();
    int KiemTra();
    int KiemTraGocToaDo();
    int KiemTraTamGiacDeu();
    void Perimeter();
    void Area();
    float getCV();
    float getDT();
};
class TriangleArray
{
    Triangle a[100];
    int n;

public:
    void Nhap();
    void Xuat();
    void LK_TamGiacCoDinhGocToaDo();
    void LK_TamGiacDeu();
    float TongCV();
    float TongDT();
    void SapXepTang_CV();
    void SapXepTang_DT();
};
int main()
{
    TriangleArray ta;
    ta.Nhap();
    ta.Xuat();
    ta.LK_TamGiacCoDinhGocToaDo();
    ta.LK_TamGiacDeu();
    cout<<"Tong chu vi: "<<ta.TongCV()<<endl;
    cout<<"Tong dien tich: "<<ta.TongDT()<<endl;
    ta.SapXepTang_CV();
    ta.SapXepTang_DT();
}
Point::Point()
{
    x = y = 0;
}
Point::Point(float h, float t)
{
    x = h, y = t;
}
void Point::Nhap()
{
    cout << "\nNhap hoanh do x: ";
    cin >> x;
    cout << "Nhap hoah do y: ";
    cin >> y;
}
void Point::Xuat()
{
    cout << "(" << x << ", " << y << ")";
}
float Point::getX()
{
    return x;
}
float Point::getY()
{
    return y;
}
float Point::Distance(Point P)
{
    return sqrt((x - P.x) * (x - P.x) + (y - P.y) * (y - P.y));
}
// Triangle
Triangle::Triangle()
{
    Point A(0, 0), B(0, 0), C(0, 0);
    dt = cv = 0;
}
Triangle::Triangle(Point A, Point B, Point C)
{
    this->A = A;
    this->B = B;
    this->C = C;
}
void Triangle::Nhap()
{
//    do
//    {
        cout << "\nNhap ba dinh tam giac" << endl;
        cout << "Nhap dinh thu nhat: ";
        A.Nhap();
        cout << "Nhap dinh thu hai: ";
        B.Nhap();
        cout << "Nhap dinh thu ba: ";
        C.Nhap();
        if (KiemTra()==0)
            cout << "Nhap lai tam giac" << endl;
 //   } while (!KiemTra()==0);
}
void Triangle::Xuat()
{
    cout << "\nDinh thu nhat: ";
    A.Xuat();
    cout << "\nDinh thu hai: ";
    B.Xuat();
    cout << "\nDinh thu ba: ";
    C.Xuat();
    Perimeter();
    Area();
    cout << "\nChu vi: " << cv << "\nDien tich: " << dt << endl;
}
int Triangle::KiemTra()
{
    int kt = 1;
    if ((A.getX() - B.getX()) * (C.getY() - B.getY()) ==
        (C.getX() - B.getX()) * (A.getY() - B.getY()))
        kt = 0;
    return kt;
}
int Triangle::KiemTraGocToaDo()
{
    int kt = 0;
    if ((A.getX() == 0 && A.getY() == 0) || (B.getX() == 0 && B.getY() == 0) 
	|| (C.getX() == 0 && C.getY() == 0))
        kt = 1;
    return kt;
}
int Triangle::KiemTraTamGiacDeu()
{
    float AB = A.Distance(B);
    float AC = A.Distance(C);
    float BC = B.Distance(C);
    if (AB == AC && AB == BC && AC == BC)
        return 1;
    else
        return 0;
}
void Triangle::Perimeter()
{
    cv = A.Distance(B) + A.Distance(C) + B.Distance(C);
}
void Triangle::Area()
{
    float p = ((A.Distance(B) + A.Distance(C) + B.Distance(C)) / 2);
    dt = sqrt(p * (p - A.Distance(B)) * (p - A.Distance(C)) * (p - B.Distance(C)));
}
float Triangle::getCV()
{
    return cv;
}
float Triangle::getDT()
{
    return dt;
}

// Triangle Array
void TriangleArray::Nhap()
{
	cout << "Nhap so tam giac: ";
    cin >> n;
    for (int i = 0; i < n; i++){
    	cout << "Nhap tam giac: "<<i+1<<" "<<endl;
    	    a[i].Nhap();
    	cout << endl;
	}
    
}
void TriangleArray::Xuat()
{
    for (int i = 0; i < n; i++)
        a[i].Xuat();
    cout << endl;
}
void TriangleArray::LK_TamGiacCoDinhGocToaDo()
{
    cout << "Cac tam giac co goc nam dinh toa do" << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i].KiemTraGocToaDo())
            a[i].Xuat();
    }
    cout << endl;
}
void TriangleArray::LK_TamGiacDeu()
{
	int kq=0;
    cout << "Cac tam giac deu:" << endl;
    for (int i = 0; i < n; i++)
    if (a[i].KiemTraTamGiacDeu()==1)
    {
            a[i].Xuat();
            kq=1;
            cout << endl;
    }
    cout<<kq;
}
float TriangleArray::TongCV()
{
    float tong_cv = 0.0;
    for (int i = 0; i < n; i++)
    {
        a[i].Perimeter();
        tong_cv += a[i].getCV();
    }
    cout << endl;
    return tong_cv;
}
float TriangleArray::TongDT()
{
    float tong_dt = 0.0;
    for (int i = 0; i < n; i++)
    {
        a[i].Area();
        tong_dt += a[i].getDT();
    }
    cout << endl;
    return tong_dt;
}
void TriangleArray::SapXepTang_CV()
{
    cout<<"Sap xep tang theo chu vi"<<endl;
    Triangle t;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (a[i].getCV() > a[j].getCV())
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
    }
    for (int i = 0; i < n; i++)
        a[i].Xuat();
}
void TriangleArray::SapXepTang_DT()
{
    Triangle t;
    cout<<"Sap xep tang theo dien tich"<<endl;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (a[i].getDT() > a[j].getDT())
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
    }
    for (int i = 0; i < n; i++)
        a[i].Xuat();
}
