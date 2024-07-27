//Su dung toan tu cin va cout 
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include<stdlib.h>
#include <iomanip>
#include <iostream>
using namespace  std;

#define MAX_TEN		50
#define MAX_MASO	10
#define LCB     1800000 

//Class Nhanvien
class NhanVien
{	protected: //private:
		char HoTen[MAX_TEN];
		char MaSo[MAX_MASO];
		float Luong;
	public:
		NhanVien();
		float getLuong();
		virtual void TinhLuong()=0; 
		void Xuat(); 
		virtual void Nhap();
		//...bo sung code
};

	
//Class Bien che
class BienChe: public NhanVien
{	protected: //private: 
		float HeSoLuong;
		float HeSoPhuCap;
	public:
		BienChe();
		void TinhLuong();
		void Nhap();
		//...bo sung code
};

//Dinh nghia lop HopDong
class HopDong : public NhanVien
{	protected: //private:
		float TienCong; // 1 ngay
		float NgayCong; // lon hon 24 ngay thi tinh 1.2
	public:
		HopDong();
		void TinhLuong();
		void Nhap();
		//...bo sung code
};

//Dinh nghia ham thanh vien cho lop NhanVien
NhanVien::NhanVien()
{
	strcpy(HoTen,""); 
	strcpy(MaSo,"");
	Luong=0;
}

float NhanVien::getLuong(){
	return Luong;
}

void NhanVien::Nhap()
{
	cout<<"Ma so:";	cin>>MaSo;
	cin.ignore(); //xoa dau Enter trong buffer
	cout<<"Ho va ten:"; 
	cin.getline(HoTen,MAX_TEN);
	//cin>>HoTen;
}

void NhanVien::Xuat() 
{	//setiosflags(ios::fixed)<<setprecision(2);
	cout<<"Ma so:"<<MaSo<<",Ho va ten:"<<HoTen
		 <<",Luong:"<<Luong<<endl;
}
	

//Dinh nghia ham thanh vien cho lop BienChe
BienChe::BienChe()
{
	HeSoLuong=HeSoPhuCap=0;
}

void BienChe::Nhap()
{	
	NhanVien::Nhap();
	do{
		cout<<"Nhap he so luong (3.0-14.0): "; cin>>HeSoLuong;
		if(HeSoLuong<3 || HeSoLuong>13.0)
			cout<<"Vui long nhap he so luong tu 3.0->14.0"<<endl;
	}while(HeSoLuong<3 || HeSoLuong>13.0);
	do{
		cout<<"Nhap he so phu cap (0.0-2.0): "; cin>>HeSoPhuCap;
		if(HeSoPhuCap<0 || HeSoPhuCap>2.0)
			cout<<"Vui long nhap he so phu cap tu 0.0 den 2.0"<<endl;
	}while(HeSoPhuCap<0 || HeSoPhuCap>2.0);
	TinhLuong();
}

void BienChe::TinhLuong()
{
	Luong=LCB*(HeSoLuong+HeSoPhuCap);
}

//Cac ham thanh vien trong lop HopDong
HopDong::HopDong()
{
	TienCong=NgayCong=0;
}

void HopDong::Nhap()
{
	NhanVien::Nhap();
	do{
		cout<<"Nhap tien cong 1 ngay: "; cin>>TienCong;
		if(TienCong < 100000 || TienCong > 200000)
			cout<<"Vui long nhap lai tien cong trong 1 ngay!"<<endl;
	}while(TienCong < 100000 || TienCong > 200000);
	cout<<"Nhap so ngay lam viec trong 1 thang: "; cin>>NgayCong;
	TinhLuong();
}

void HopDong::TinhLuong()
{
	if(this->NgayCong>24)
		Luong = TienCong * NgayCong * 1.2;
	else 
		Luong = TienCong * NgayCong;
}

int main()
{
	NhanVien *Nv[100];	int N=0;
	char Chon,Loai;
	cout<<"Nhap thong tin cho cac Nhan vien"<<endl;
	do
	{	cout<<"Bien che hay Hop dong (B/H)? ";
		cin>>Loai; 	Loai=toupper(Loai);
		if (Loai=='B')
			Nv[N]=new BienChe;
		else
			Nv[N]=new HopDong;
		Nv[N++]->Nhap();
		cout<<"Tiep tuc (C/K)? ";	cin>>Chon;
		Chon=toupper(Chon);
		if ((N==100)||(Chon=='K'))
			break;
	}
	while (1);
	
	cout<<endl<<"Thong tin cua cac nhan vien vua nhap"<<endl;
	for(int i=0;i<N;i++){
		cout << "Thong tin nhan vien thu " << i + 1 << endl;
		Nv[i]->Xuat();
		cout << endl;
	}
	
	float sum=0;
	for(int i=0;i<N;i++){
		sum+=Nv[i]->getLuong();
	}
	cout<<"Tong luong cac nhan vien trong danh sach: "<<sum<<endl;
	
	float tbc=sum/N;
	cout<<"Trung binh cong luong nhan vien trong danh sach: "<<tbc<<endl;
	
	cout<<"Cac nhan vien co muc luong lon hon 5tr"<<endl;
	for(int i=0;i<N;i++)
		if(Nv[i]->getLuong() > 5000000)
			Nv[i]->Xuat();
	getch();
	return 1;
}
