#include<iostream>
#include<cmath>
#include<stdbool.h>
using namespace std;

class phanso{
	private:
		int tuso;
		int mauso;
	public:
		phanso();
		phanso TongPS(phanso);
		void nhap();
		void xuat();
		void rutgonPS();
		void setTuso(int);
		void setMauso(int);
		void swap(phanso&,phanso&);
		
		int getTuso();
		int getMauso();
		int xetdau();
		int ucln(int,int);
		float GiaTriPS();
		
		bool KTMauSo_Bang1();
		bool KTPSDuong();
};

class MangPS{
	private:
		phanso a[100];
		int n;
	public: 
		void nhap();
		void xuat();
		void GiaTri_NH1();
		void IncreaseSort();
		bool KTCacMauSo_Bang1();
		phanso TongCacPS();
		float TongGTPS();
		float TBPSDuong();
};

int main(){
	MangPS x;
	x.nhap();
	x.xuat();
	x.GiaTri_NH1();
	
	if(x.KTCacMauSo_Bang1()) cout<<endl<<"Cac phan so co mauso = 1"<<endl;
	else cout<<endl<<"Co phan so co mauso != 1"<<endl;
	
	cout<<endl<<"Tong cac phan so la: "; x.TongCacPS().xuat();
	cout<<"Tong gia tri cac phan so la: "<<x.TongGTPS();
	cout<<endl<<"Trung binh cong gia tri phan so duong: "<<x.TBPSDuong();
	
	cout<<endl<<"Phan so sau khi sap xep: "<<endl; x.IncreaseSort(); x.xuat();
	return 0;
}

phanso::phanso(){
	tuso=0; mauso=1;
}

void phanso::nhap(){
	cout<<"Nhap tu so: "; cin>>tuso;
	cout<<"Nhap mau so: "; cin>>mauso;
	if(mauso==0){
		cout<<"Vui long nhap lai mau so!"<<endl;
		cin>>mauso;
	} 
}

int phanso::xetdau(){
	if(tuso*mauso>0)
		return 1;
	if(tuso*mauso<0)
		return -1;
	return 0;
}

void phanso::xuat(){
	if(xetdau()==1){
		if(tuso<0){
			tuso=abs(tuso);
			mauso=abs(mauso); 
		}
	}
	else if(xetdau()==-1){
		if(mauso<0)
			tuso=tuso*(-1);
			mauso=abs(mauso);
	}
	cout<<tuso<<"/"<<mauso<<endl;
}

int phanso::getTuso(){
	return tuso;
}

int phanso::getMauso(){
	return mauso;
}

void phanso::setMauso(int Mauso){
	mauso=Mauso;
}

void phanso::setTuso(int Tuso){
	tuso=Tuso;
}

int phanso::ucln(int a,int b){
	a=abs(a);
	b=abs(b);
	int sl,sn;
	if(a>b){
		sl=a;
		sn=b;
	}
	else{
		sl=b;
		sn=a;
	}
	int r=sl%sn;
	while(r!=0){
		sl=sn;
		sn=r;
		r=sl%sn;
	}
	return sn;
}

void phanso::rutgonPS(){
	int k=ucln(tuso,mauso);
	tuso=tuso/k;
	mauso=mauso/k;
}

float phanso::GiaTriPS(){
	return (float)tuso/(float)mauso;
}

phanso phanso::TongPS(phanso b){
	phanso tmp;
	tmp.tuso=tuso*b.mauso+mauso*b.tuso;
	tmp.mauso=mauso*b.mauso;
	tmp.rutgonPS();
	return tmp;
}

bool phanso::KTMauSo_Bang1(){
	return mauso==1;
}

bool phanso::KTPSDuong(){
	return ((float)tuso/(float)mauso)>0;
}

void phanso::swap(phanso &a,phanso &b){
	phanso tmp=a;
	a=b;
	b=tmp;
}

void MangPS::nhap(){
	cout<<"Nhap so luong phan tu: "; cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Phan so thu "<<i+1<<": "<<endl;
		a[i].nhap();
		cout<<endl;
	}
}

void MangPS::xuat(){
	cout<<"Xuat thong tin: "<<endl;
	for(int i=0;i<n;i++){
		a[i].xuat();
	}
}

void MangPS::GiaTri_NH1(){
	int tmp=0;
	for(int i=0;i<n;i++){
		if(a[i].GiaTriPS()<1){
				tmp=1;
				break;
		}
	}
	if(tmp==1){
		cout<<endl<<"Gia tri phan so < 1: "<<endl;
		for(int i=0;i<n;i++){
			if(a[i].GiaTriPS()<1){
				a[i].xuat();
			}
		}
	}
	else cout<<"Khong co gia tri phan so nao < 1";
}

bool MangPS::KTCacMauSo_Bang1(){
	for(int i=0;i<n;i++){
		if(a[i].getMauso()!=1) 
			return 0;
	}
	return 1;
}

phanso MangPS::TongCacPS(){
	phanso tong;
	for(int i=0;i<n;i++){
		tong=a[i].TongPS(tong);
	}
	return tong;
}

float MangPS::TongGTPS(){
	float tong=0;
	for(int i=0;i<n;i++){
		tong+=a[i].GiaTriPS();
	}
	return tong;
}

float MangPS::TBPSDuong(){
	float tong=0, tmp=0;
	for(int i=0;i<n;i++){
		if(a[i].KTPSDuong()){
			tong+=a[i].GiaTriPS();
			tmp++;
		}
	}
	return tong/tmp;
}

void MangPS::IncreaseSort(){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++)
			if(a[i].GiaTriPS()>a[j].GiaTriPS())
				swap(a[i],a[j]);
	}
}
