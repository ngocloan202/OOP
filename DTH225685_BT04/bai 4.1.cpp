//Su dung toan tu cin va cout 
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <iomanip>
#include <iostream>
using namespace  std;

//Class Hinh chu nhat
class HinhCN 
{
	private:
		float dai;
		float rong;
		float dt;  
		float cv;
	public:
		HinhCN();
		HinhCN(float d, float r);
		void Nhap();
		void Xuat();
		void TinhDT();
		void TinhCV();
		void setCV(float);
		void setDT(float);
		void setDai(float);
		void setRong(float);
		float getCV();
		float getDT();
		float getDai();
		float getRong();
		//..cac phuong thuc khac
};


//Hinh vuong
class HinhVuong:public HinhCN
{
	private: 
		float canh;
		//ke thua dt, cv tu HCN

	public:
		HinhVuong();
		HinhVuong(float);
		void Nhap();
		void Xuat();
//		void TinhDT();
//		void TinhCV();
//		float getCV();
//		float getDT();
//		float getCanh();
};

int main()
{
	HinhCN	hcn[50];
	HinhVuong hv[50];
	int n,m;
	cout<<"So luong Hinh CN: "; cin>>n;
	for(int i=0; i<n;i++)
	{
		cout<<"Hinh CN thu "<<i+1;
		hcn[i].Nhap();
	}
		
	cout<<"Thong tin cac Hinh CN: "<<endl;
	for(int i=0; i<n;i++)
		hcn[i].Xuat();
	
	
	//..Them code
	cout<<endl<<"So luong Hinh Vuong: "; cin>>m;
	for(int i=0; i<m;i++)
	{
		cout<<"Hinh Vuong thu "<<i+1;
		hv[i].Nhap();
	}	
		
	cout<<"Thong tin cac Hinh Vuong: "<<endl;
	for(int i=0; i<m;i++)
		hv[i].Xuat();
		
	float tongCV,tongDT;
	tongCV=tongDT=0;
	for(int i=0;i<n;i++){
		tongCV+=hcn[i].getCV();
		tongDT+=hcn[i].getDT();
	}
	cout<<"Tong CV HCN: "<<tongCV;
	cout<<endl<<"Tong DT HCN: "<<tongDT<<endl;
	
	tongCV=tongDT=0;
	for(int i=0;i<n;i++){
		tongCV+=hv[i].getCV();
		tongDT+=hv[i].getDT();
	}
	cout<<"Tong CV HV: "<<tongCV;
	cout<<endl<<"Tong DT HV: "<<tongDT<<endl;
	
	getch();
	return 1;
}

//Cac phuong thuc Hinh CN
HinhCN::HinhCN()
{
	dai = rong = dt=cv=0;
}
HinhCN::HinhCN(float d,float r)
{
	dai=d; rong=r;
}

float HinhCN::getDai(){
	return this->dai;
}

float HinhCN::getRong(){
	return this->rong;
}

float HinhCN::getCV(){
	return this->cv;
}

float HinhCN::getDT(){
	return this->dt;
}

void HinhCN::setDai(float dai){
	this->dai=dai;
}

void HinhCN::setRong(float rong){
	this->rong=rong;
}

void HinhCN::setCV(float cv){
	this->cv=cv;
}

void HinhCN::setDT(float dt){
	this->dt=dt;
}

void HinhCN::Nhap()
{
	cout<<endl<<"nhap do dai canh dai: "; cin>>dai;
	cout<<"nhap do dai canh rong: "; cin>>rong;
	TinhCV();
	TinhDT();
}
void HinhCN::Xuat()
{
	cout<<"canh dai: "<<dai<<" canh rong: "<<rong;
	cout<<" Chu vi: "<<cv<<" Dien tich: "<<dt<<endl;
}

void HinhCN::TinhDT()
{
	dt=(dai*rong);
}

void HinhCN::TinhCV()
{
	cv= (dai+rong)*2;
}


//Cac phuong thuc cua Hinh Vuong
HinhVuong::HinhVuong():HinhCN(){
    
}

HinhVuong::HinhVuong(float c):HinhCN(c,c){
	this->canh = c;
}

/*void HinhVuong::TinhCV(){
	HinhCN::setCV(canh * 4);
}

void HinhVuong::TinhDT(){
	HinhCN::setDT(canh*canh);
}

float HinhVuong::getCanh(){
	return canh;
}*/

/*float HinhVuong::getCV(){
	return HinhCN::getCV();
}

float HinhVuong::getDT(){
	return HinhCN::getDT();
}*/

void HinhVuong::Nhap(){
	cout<<endl<<"nhap canh:"; cin>>canh;
	setDai(canh); setRong(canh);
	TinhCV();
	TinhDT();
}

void HinhVuong::Xuat(){
	cout<<"canh: "<<getDai();
	cout<<" Chu vi: "<<getCV()<<" Dien tich: "<<getDT()<<endl;
}


