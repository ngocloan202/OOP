#include<bits/stdc++.h>
#define Pi 3.14

using namespace std;

class Diem{
	private:
		float x,y;
	public:
		Diem();
		Diem(float,float);
		float getX();
		float getY();
		void nhap();
		void xuat();
};

class HinhTron{
	protected:
		Diem O;
		Diem A;
		float r, cv,dt;
	public:
		HinhTron();
		float getR();
		float getCV();
		float getDT();
		void nhap();
		void xuat();
		float TinhBanKinh();
		float TinhChuVi();
		float TinhDienTich();
};

int main(){
	HinhTron ht;
	ht.nhap();
	ht.xuat();
	return 0;
}

Diem::Diem(){
	x=0.0; y=0.0;
}

Diem::Diem(float a, float b){
	x=a; y=b;
}

HinhTron::HinhTron(){
	Diem A(0.0,0.0);
	r=cv=dt=0.0;
}

float Diem::getX(){
	return x;
}

float Diem::getY(){
	return y;
}

float HinhTron::getR(){
	return r;
}

float HinhTron::getCV(){
	return cv;
}

float HinhTron::getDT(){
	return dt;
}

void Diem::nhap(){
	cout<<"Nhap hoanh do: "; cin>>x;
	cout<<"Nhap tung do: "; cin>>y;
}

void Diem::xuat(){
	cout<<'('<<x<<','<<y<<')'<<endl<<endl;
}

void HinhTron::nhap(){
	O = Diem(0.0,0.0);
	cout<<"Nhap toa do diem A: "<<endl; A.nhap();
	r=TinhBanKinh();
	cv=TinhChuVi();
	dt=TinhDienTich();
}

void HinhTron::xuat(){
	cout<<"Toa do diem A: "; A.xuat();
	cout<<"Chu vi hinh tron: "<<cv;
	cout<<endl<<"Dien tich hinh tron: "<<dt;
}

float HinhTron::TinhBanKinh(){
	return sqrt(pow(A.getX()-O.getX(),2)+pow(A.getY()-O.getY(),2));
}

float HinhTron::TinhChuVi(){
	return 2*Pi*r;
}

float HinhTron::TinhDienTich(){
	return Pi*pow(r,2);
}
