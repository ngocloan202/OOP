#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include<stdlib.h>
#include <iomanip>
#include <iostream>
using namespace  std;

#define MAX_NXB		50
//Class Nhanvien
class QLSach
{	protected:
		char MaSach[12];
		char NgayNhap[12];
		float DonGia;
		int SoLuong;
		char NXB[50];
		float ThanhTien;
		int Loai;
	public:
		QLSach();
		virtual void Nhap();
		void Xuat(); 
		virtual void TinhTien()=0; //Ham thuan ao
		float getThanhTien();
		int getLoai();
		char* getNXB();
		char* getMaSach();
		void swap(QLSach *, QLSach *);
};

	
//Class Bien che
class SachGK: public QLSach
{
	protected:
		int TinhTrang; //1-Moi; 0-Cu
	public:
		SachGK();
		void TinhTien();
		void Nhap();
};

//Dinh nghia lop SachTK

class SachTK : public QLSach
{
	protected:
		float Thue; 
	public:
		SachTK();
		float getThue();
		void Nhap();
		void TinhTien();
};

//Dinh nghia ham thanh vien cho lop QLSach
QLSach::QLSach()
{
	strcpy(MaSach,"");
	strcpy(NgayNhap,"");
	strcpy(NXB,"");
	ThanhTien=DonGia=SoLuong=0;
}

void QLSach::Nhap()
{
	cin.ignore();
	cout<<"Nhap MS: "; cin.getline(MaSach,12);
	cout<<"Nhap ngay: "; cin.getline(NgayNhap,12);
	cout<<"Nhap don gia: "; cin>>DonGia; 
	cout<<"Nhap so luong: "; cin>>SoLuong; cin.ignore();
	cout<<"Nhap nha xuat ban: "; cin.getline(NXB,MAX_NXB);
}

void QLSach::Xuat() 
{
	cout<<"MS: "<<MaSach<<", NG: "<<NgayNhap;
	cout<<", DG: "<<DonGia<<", SL: "<<SoLuong;
	cout<<",TT: "<<ThanhTien<<", NXB: "<<NXB<<endl;
}

float QLSach::getThanhTien()
{
	return ThanhTien;
}

int QLSach::getLoai()
{
	return Loai;
}

char* QLSach::getNXB()
{
	return NXB;
}

char* QLSach::getMaSach()
{
	return this->MaSach;
}

void swap(QLSach *a, QLSach *b)
{
	QLSach *tam;
	tam = a;
	a = b;
	b = tam;
}

//Dinh nghia ham thanh vien cho lop SachGK
SachGK::SachGK(): QLSach() 
{
	//QLSach::QLSach();
	TinhTrang=1; //mac nhien la Sach moi
	Loai=0;
}

void SachGK::TinhTien()
{
	if (TinhTrang==1)
		ThanhTien=SoLuong*DonGia;
	else
		ThanhTien=SoLuong*DonGia*0.5;
}

void SachGK::Nhap()
{
	QLSach::Nhap();
	cout<<"Nhap tinh trang sach (1: moi, 0: cu): ";
	cin>>TinhTrang;
	TinhTien();
}

//Cac ham thanh vien trong lop SachTK
SachTK::SachTK(): QLSach() 
{
	Thue=0;
	Loai=1;
}

float SachTK::getThue()
{
	return this->Thue;
}

void SachTK::Nhap()
{
	QLSach::Nhap();
	cout<<"Nhap thue: "; cin>>Thue;
	TinhTien();
}

void SachTK::TinhTien()
{
	ThanhTien= SoLuong*DonGia + SoLuong*DonGia*(Thue/100);
}

int main()
{
	QLSach *MSach[100];
	int i=0,n=0,dem=0;
	float tbc=0,sumstk=0,sumsgk=0;
	char Chon,Loai, nxb_ct[50];
	cout<<setiosflags(ios::fixed)<<setprecision(2);
	cout<<"Nhap thong tin cho cac loai sach"<<endl;
	do
	{
		cout<<"Sack Giao khoa hay Sach Tham khao (G/T)? ";
		cin>>Loai;
		Loai=toupper(Loai);
		if (Loai=='G')
			{
				MSach[n] = new SachGK();
				MSach[n]->Nhap();
				sumsgk+=MSach[n]->getThanhTien();
			}
		else
			{
				MSach[n] = new SachTK();
				MSach[n]->Nhap();
				sumstk+=MSach[n]->getThanhTien();
				tbc+=MSach[n]->getThanhTien();
				dem++;
			}
		n++; //tang len so luong sach
		cout<<"Tiep tuc (C/K)? ";
		cin>>Chon;
		Chon=toupper(Chon);
		if ((n==100)||(Chon=='K'))
			break;
	}
	while (1);
	
	//Xuat thong tin:		
	for(int i=0;i<n;i++){
		cout<<"Thong tin thu "<<i+1<<": ";
		MSach[i]->Xuat();
	}
	
	//Tong tien moi loai
	cout<<"Tong tien sach giao khoa: "<<sumsgk;
	cout<<endl<<"Tong tien sach tham khao: "<<sumstk<<endl;
	
	//Tinh tbc
	cout<<"Trung binh cong don gia cua cac sach tham khao: "<<tbc/dem;
	
	//Tim nxb_ct;
	int kq=0;
	cout<<endl<<endl<<"Nhap nxb can tim: "; cin.ignore(); cin.getline(nxb_ct,50);
	for(int i=0;i<n;i++)
		if(MSach[i]->getLoai()==1 && strcmp(MSach[i]->getNXB(),nxb_ct)==0)
		{
			cout<<"Thong tin nxb_ct: "<<endl;
			MSach[i]->Xuat();
			kq=1;
		}
	if(kq==0)
		cout<<"Khong tim thay nxb_ct";

	//dynamic_cast
//	SachTK *stk = new SachTK();
/*	for(int i=0;i<n;i++)
		if(dynamic_cast<SachTK*>(MSach[i])){
			cout<<dynamic_cast<SachTK*>(MSach[i])->getThue();
		}
	*/

	QLSach *tam;
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(strcmp(MSach[i]->getMaSach(),MSach[j]->getMaSach())>0)
			{
				tam = MSach[i];
				MSach[i] = MSach[j];
				MSach[j] = tam;
			}
		//	swap(MSach[i],MSach[j]);
	cout<<endl<<"Danh sach sau khi sap xep la: "<<endl;
	for(int i = 0; i < n ;i++)
		MSach[i]->Xuat();

	getch();
	return 1;
}
