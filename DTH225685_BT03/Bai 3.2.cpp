//Mang cac doi tuong 
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <iostream>
using namespace  std;

class Thisinh
{
	private:
		char Maso[12];
		char Hoten[40];
		float Diemlt, Diemth, Dtb;
		char Ketqua[12];
	public:
		Thisinh();
		float getDiemlt();
		float getDiemth();
		float getDtb();
		char* getMaso();
		char* getHoten();
		
		void Nhap();
		void TinhDTB();
		void KetQua();
		void Xuat();
		
};

class MangThisinh
{
	private:
		Thisinh mts[100];
		int n;
	public:
		void Nhap();
		void Xuat();
		void LietKeDltvDthLonhon7();
		void TimThisinh();
		void SXTDTheoHoten();
		
		float TBCDiemThisinh();
};


int main()
{
	MangThisinh mThisinh;
	
	//Nhap danh sach
	cout<<"Nhap thong tin cac Thi sinh: ";
	mThisinh.Nhap();
	
	cout<<"Thong tin cac Thi sinh: ";
	mThisinh.Xuat();
	
	mThisinh.LietKeDltvDthLonhon7();
	
	float tbc = mThisinh.TBCDiemThisinh();
	cout<<endl<<"Trung binh cong diem cua thi sinh trong danh sach: "<<tbc<<endl;
	
	mThisinh.TimThisinh();
	
	
	cout<<endl<<endl<<"Danh sach thi sinh sap xep tang dan theo ho ten: ";
	mThisinh.SXTDTheoHoten();
	
//	Thisinh ts;
//	ts.Nhap();
//	cout<<ts.getMaso()<<" "<<ts.getHoten();
	getch();
	return 1;

}

//Cac phuong thuc lop Thisinh
Thisinh::Thisinh()
{
	strcpy(this->Maso,"");
	strcpy(this->Hoten,"");
	this->Diemlt=this->Diemth=this->Dtb=0;
	
}

float Thisinh::getDiemlt()
{
	return this->Diemlt;
}

float Thisinh::getDiemth()
{
	return this->Diemth;
}

float Thisinh::getDtb()
{
	return this->Dtb;
}

char* Thisinh::getMaso()
{
	return this->Maso;
}

char* Thisinh::getHoten()
{
	return this->Hoten;
}

void Thisinh::Nhap()
{
	cout<<"Ma so thi sinh: "; gets(Maso);
	cout<<"Ho ten thi sinh: "; gets(Hoten);
	cout<<"Diem ly thuyet: "; cin>>Diemlt;
	cout<<"Diem thuc hanh: "; cin>>Diemth;
	cin.ignore();
	TinhDTB();
	KetQua();
}

void Thisinh::Xuat()
{
	cout<<endl<<"Ma so: "<<Maso;
	cout<<" - Ho ten: "<<Hoten; 
	cout<<" - Diem LT : "<<Diemlt;
	cout<<" - Diem TH: "<<Diemth;
	cout<<" - DTB = "<<Dtb;
	cout<<" - Ket qua: "<<Ketqua;
}

void Thisinh::TinhDTB()
{
	Dtb= (Diemlt + Diemth*2)/3;
}

void Thisinh::KetQua()
{
	if(Dtb>=5) strcpy(Ketqua,"Dat");
	else
		strcpy(Ketqua,"Khong dat"); 
}


//Cac phuong thuc Lop MangThisinh
void MangThisinh::Nhap()
{
	cout <<"\nSo luong Thi sinh : "; cin >> n;
	cin.ignore();
	for (int i=0;i<n;i++)
	{
		cout<<"Nhap Thi sinh thu "<<i+1<<" : "<<endl;
		mts[i].Nhap();
	}
}

void MangThisinh::Xuat()
{
	for (int i=0;i<n;i++)
	{
		mts[i].Xuat();
		cout << " ";
	}
}

void MangThisinh::LietKeDltvDthLonhon7()
{
	int kq=0;
	for(int i=0;i<n;i++)
		if((mts[i].getDiemlt()>7) && (mts[i].getDiemth()>7))
		{
			kq=1;
			break;
		}
			
	if(kq==1)
	{
		cout<<endl<<endl<<"Danh sach thi sinh co diem lt & diem th > 7: ";
		for(int i=0;i<n;i++)
			if((mts[i].getDiemlt()>7) && (mts[i].getDiemth()>7))
				mts[i].Xuat();
	}
}

float MangThisinh::TBCDiemThisinh()
{
	float tbc=0;
	for(int i=0;i<n;i++)
		tbc+=mts[i].getDtb();
	if(n>0)
		return tbc/n;
	return 0;	
}

void MangThisinh::TimThisinh()
{
	char TimMs[40];
	int kq=0;
	cout<<endl<<"Nhap ma so thi sinh can tim: "; gets(TimMs);
	for(int i=0;i<n;i++)
		if(strcmp(mts[i].getMaso(),TimMs)==0)
		{
			kq=1;
			cout<<"Thong tin thi sinh: ";
			mts[i].Xuat();
			break;
		}
	if(kq==0)
		cout<<"Khong co thi sinh nao trung voi ma so thi sinh ban vua nhap!"<<endl;
}

void MangThisinh::SXTDTheoHoten()
{
	for(int i=0;i<n-1;i++)
	{
		Thisinh tmp;
		for(int j=i+1;j<n;j++)
			if(strcmp(mts[i].getHoten(),mts[j].getHoten())>0)
			{
				tmp=mts[i];
				mts[i]=mts[j];
				mts[j]=tmp;				
			}
	}
	for(int i=0;i<n;i++)
		mts[i].Xuat();
}
