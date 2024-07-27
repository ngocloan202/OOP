#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <iostream>
using namespace  std;

class SoPhuc
{
	private:
		float Thuc, Ao;
	public:
		SoPhuc(); // Constructor mac dinh
		SoPhuc(float R,float I);
		SoPhuc (const SoPhuc & Z); // Constructor sao chep
		SoPhuc (float R); // Constructor chuyen doi
		void Nhap();  //Nhap so phuc
		void Xuat(); // Hien thi so phuc
		
		float getThuc();
		float getAo();
		
		// Cac tinh toan 
		SoPhuc operator + (SoPhuc Z);
		SoPhuc operator - (SoPhuc Z);
		SoPhuc operator * (SoPhuc Z);
		SoPhuc operator / (SoPhuc Z);
		
		//Ham tinh toan 
		void Cong(SoPhuc Z);
		void Tru(SoPhuc Z);
		void Nhan(SoPhuc Z);
		void Chia(SoPhuc Z);
		
		//int LonHon(SoPhuc Z);  
    	//int NhoHon(SoPhuc Z);  
	   	//int Bang(SoPhuc Z);  
		
		// Cac tinh toan so sanh
		////int operator == (SoPhuc Z);
		//int operator != (SoPhuc Z);
		//int operator > (SoPhuc Z);
		//int operator >= (SoPhuc Z);
		//int operator < (SoPhuc Z);
		//int operator <= (SoPhuc Z);
	
		float Module(); // Giá tri tuyet doi cua so phuc
		
		//Cac ham kiem tra
		//int ThuanAo();
		//int ThuanThuc();
		
		
};

class MangSoPhuc
{
	private:
		SoPhuc a[100];
		int n;
	public:
		void Nhap();
		void Xuat();
		void LKModuleNH1();
		void IncreaseSortbyModule();
		
		int KiemTraRealLH1();
		float TongCacSoPhuc();
		float AVGCacSoPhuc();
		//..cac phuong thuc cn lai
		
};


int main()
{
	MangSoPhuc x;
	
	//Nhap danh sach
	cout<<"Nhap thong tin cac So phuc trong Mang: ";
	x.Nhap();
	cout<<"Thong tin cac So phuc trong Mang: ";
	x.Xuat();
	x.LKModuleNH1();
	
	if(x.KiemTraRealLH1())
		cout<<endl<<"Toan bo mang co so thuc < 10";
	else
		cout<<endl<<"Khong co so thuc < 10";
	
	
	cout<<endl<<"Tong cac so phuc trong mang: "<<x.TongCacSoPhuc();
	cout<<endl<<"AVG Module cac so phuc trong mang: "<<x.AVGCacSoPhuc()<<endl;
	
	x.IncreaseSortbyModule();
	getch();
	return 1;

}


SoPhuc::SoPhuc()
{
	Thuc = 0.0;
	Ao = 0.0;
}

SoPhuc::SoPhuc(float R,float I)
{
	Thuc = R;
	Ao = I;
}

SoPhuc::SoPhuc(const SoPhuc & Z)  //Ham dung sao chep
{
	Thuc = Z.Thuc;
	Ao = Z.Ao;
}

SoPhuc::SoPhuc(float R) 
{
	Thuc = R;
	Ao = 0.0;
}

void SoPhuc::Nhap()
{
	cout<<"\n Nhap phan thuc "; cin>>Thuc;
	cout<<"\n Nhap phan ao "; cin>>Ao;

}


void SoPhuc::Xuat()
{
	cout<<"(" << Thuc << " + " << Ao << "i)";
}

float SoPhuc::getThuc()
{
	return Thuc;
}

float SoPhuc::getAo()
{
	return Ao;
}

/*
Cho hai so phuc z = a + bi và w = c + di.
Phep Cong:  z+w  = (a +c) + (b+d)i
Phep Tru:  z-w  = (a -c) + (b-d)i
Phep Nhan:  z.w  = (a * c - b * d) + (a * d + b * c)i
Phep Chia:  z/w   = [(a * c + b * d) / (c * c + d * d)] + (b * c - a * d)i
*/

void SoPhuc::Cong(SoPhuc Z)
{
	SoPhuc Tmp;
	Tmp.Thuc = Thuc + Z.Thuc;
	Tmp.Ao = Ao + Z.Ao;
	cout<<endl<<"Tong 2 so phuc: "; 
	Tmp.Xuat();
	cout<<endl;
}

void SoPhuc::Tru(SoPhuc Z)
{
	SoPhuc Tmp;
	Tmp.Thuc = Thuc - Z.Thuc;
	Tmp.Ao = Ao - Z.Ao;
	cout<<"Tru 2 so phuc: ";
	Tmp.Xuat();
	cout<<endl;
}

void SoPhuc::Nhan(SoPhuc Z)
{
	SoPhuc Tmp;
	Tmp.Thuc = Thuc*Z.Ao - Ao*Z.Thuc;
	Tmp.Ao = Thuc*Z.Ao + Ao*Z.Thuc;
	cout<<"Nhan 2 so phuc: ";
	Tmp.Xuat();
	cout<<endl;
}

void SoPhuc::Chia(SoPhuc Z)
{
	SoPhuc Tmp;
	Tmp.Thuc = (Thuc * Z.Thuc + Ao * Z.Ao)/(pow(Z.Thuc,2) + pow(Z.Ao,2));
	Tmp.Ao = Ao*Z.Thuc - Thuc*Z.Ao;
	cout<<"Chia 2 so phuc: ";
	Tmp.Xuat();
	cout<<endl;
}

SoPhuc SoPhuc::operator + (SoPhuc Z)
{
	SoPhuc Tmp;
	Tmp.Thuc = Thuc + Z.Thuc;
	Tmp.Ao = Ao + Z.Ao;
	return Tmp;
}

SoPhuc SoPhuc::operator - (SoPhuc Z){
	SoPhuc Tmp;
	Tmp.Thuc = Thuc - Z.Thuc;
	Tmp.Ao = Ao - Z.Ao;
	return Tmp;
}

SoPhuc SoPhuc::operator * (SoPhuc Z)
{
	SoPhuc Tmp;
	Tmp.Thuc = Thuc*Z.Ao - Ao*Z.Thuc;
	Tmp.Ao = Thuc*Z.Ao + Ao*Z.Thuc;
	return Tmp;
}

SoPhuc SoPhuc::operator / (SoPhuc Z)
{
	SoPhuc Tmp;
	Tmp.Thuc = (Thuc * Z.Thuc + Ao * Z.Ao)/(pow(Z.Thuc,2) + pow(Z.Ao,2));
	Tmp.Ao = Ao*Z.Thuc - Thuc*Z.Ao;
	return Tmp;
}

float SoPhuc::Module()
{
	return sqrt(Thuc*Thuc+Ao*Ao);
}



//CAC PHUONG THUC THUOC LOP MangSoPhuc
void MangSoPhuc::Nhap()
{
	cout <<"\n Nhap n : "; cin >> n;
	for (int i=0;i<n;i++)
	{
		cout<<"Nhap a["<<i<<"]: ";
		a[i].Nhap();
	}
}

void MangSoPhuc::Xuat()
{
	for (int i=0;i<n;i++)
	{
		a[i].Xuat();
		cout << " ";
	}
/*	for (int i=0;i<n-1;i++)
	{
		a[i].Cong(a[i+1]);
		a[i].Tru(a[i+1]);
		a[i].Nhan(a[i+1]);
		a[i].Chia(a[i+1]);
	}*/
}

void MangSoPhuc::LKModuleNH1()
{
	int kq=0;
	for(int i=0;i<n;i++)
	if(a[i].Module()<1)
	{
		kq=1;
		break;
	}
//	cout<<kq;
	if(kq==1)
	{
		cout<<endl<<"Cac so phuc co module < 1: "<<endl;
		for(int i=0;i<n;i++)
			if(a[i].Module()<1)
		a[i].Xuat();
	}	
}

int MangSoPhuc::KiemTraRealLH1(){
	for(int i=0;i<n;i++)
	if(a[i].getThuc()<10)
		return 0;
	return 1;
}

float MangSoPhuc::TongCacSoPhuc()
{
	float tong=0;
	for(int i=0;i<n;i++)
		tong+=a[i].Module();
	return tong;
}

float MangSoPhuc::AVGCacSoPhuc()
{
	float tong = TongCacSoPhuc();
	return tong/n;
}

void MangSoPhuc::IncreaseSortbyModule()
{
	for(int i=0;i<n-1;i++)
	{
		SoPhuc tmp;
		for(int j=i+1;j<n;j++)
		if(a[i].Module()>a[j].Module())
		{
			tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
		}
	}
	
	cout<<endl<<"Sap xep so phuc tang dan theo Module: "<<endl;
	for(int i=0;i<n;i++)
		a[i].Xuat();
}		
