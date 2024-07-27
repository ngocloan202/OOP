#include<iostream>
#include<conio.h>
#include<math.h>
#include<stdbool.h>
using namespace std;

class Diem{
	private:
		float x, y;
	public:
		Diem();
		Diem(float,float);
		void input();
		void output();
		float getX();
		float getY();
		void setX(float);
		void setY(float);
		bool KiemTraThangHang(Diem,Diem);
		float TinhKC(Diem);
};

class TamGiac{
	protected:
		Diem A, B, C;
		float cv;
		float dt;
	public:
		TamGiac();
		float getCV();
		float getDT();
		bool KiemTraTG();
		void nhap();
		void xuat();
		Diem TrongTamTG();
		float TinhCanh(Diem, Diem);
		float TinhChuVi();
		float TinhDienTich();
};

int main(){
	TamGiac tg;
	tg.nhap();
	tg.xuat();
	cout<<endl<<"Trong tam TG: "; tg.TrongTamTG().output();
//	getch();
	return 0;
}

Diem::Diem(){
	x=0.0; y=0.0;
}

Diem::Diem(float a,float b){
	x=a; y=b;
}

void Diem::input(){
	cout<<"Nhap hoanh do: "; cin>>x;
	cout<<"Nhap tung do: "; cin>>y;
}

void Diem::output(){
	cout<<'('<<x<<','<<y<<')'<<endl<<endl;
}

float Diem::getX(){
	return x;
}

float Diem::getY(){
	return y;
}

void Diem::setX(float X){
	x=X;
}

void Diem::setY(float Y){
	y=Y;
}

float Diem::TinhKC(Diem B){
	return sqrt(pow(x-B.x,2) + pow(y-B.y,2));
}

bool Diem::KiemTraThangHang(Diem B, Diem C){
	return (B.x-x)*(C.y-y)==(C.x-x)*(y-B.y);
}

bool TamGiac::KiemTraTG(){
	return (B.getX()-A.getX())*(C.getY()-A.getY())==(C.getX()-A.getX())*(A.getY()-B.getY());
}

TamGiac::TamGiac(){
	Diem A(0,0), B(0,0), C(0,0); 
	cv=dt=0.0;
}

float TamGiac::getCV(){
	return cv;
}

float TamGiac::getDT(){
	return dt;
}

void TamGiac::nhap(){
	cout<<"Nhap Diem A: "<<endl; A.input();
	cout<<endl<<"Nhap Diem B: "<<endl; B.input();
	cout<<endl<<"Nhap Diem C: "<<endl; C.input();
	while(!KiemTraTG()){
		cout<<"Vui long nhap lai 3 diem!"<<endl;
		cout<<"Nhap Diem A: "<<endl; A.input();
		cout<<endl<<"Nhap Diem B: "<<endl; B.input();
		cout<<endl<<"Nhap Diem C: "<<endl; C.input();
	}
	cv=TinhChuVi();
	dt=TinhDienTich();
}

void TamGiac::xuat(){
	cout<<endl<<"Diem A: "; A.output();
	cout<<"Diem B: "; B.output();
	cout<<"Diem C: "; C.output();
	cout<<"Chu vi: "<<getCV();
	cout<<endl<<"Dien tich: "<<getDT();
}

Diem TamGiac::TrongTamTG(){
	Diem tmp;
	tmp.setX((A.getX()+B.getX()+C.getX())/3);
	tmp.setY((A.getY()+B.getY()+C.getY())/3);
	return tmp;
}

float TamGiac::TinhCanh(Diem A, Diem B){
	return sqrt(pow(A.getX()-B.getX(),2)+pow(A.getY()-B.getY(),2));
}

float TamGiac::TinhChuVi(){
	float a,b,c;
	a=TinhCanh(A,B); 
	b=TinhCanh(B,C); 
	c=TinhCanh(A,C); 
	return a+b+c;
}

float TamGiac::TinhDienTich(){
	float a,b,c,p;
	a=TinhCanh(A,B);
	b=TinhCanh(B,C);
	c=TinhCanh(A,C);
	p=TinhChuVi()/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
