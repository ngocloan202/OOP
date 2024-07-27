#include<iostream>
#include<cmath>
#include<conio.h>
#include<stdbool.h>
using namespace std;

class phanso{
	private:
		int tuso;
		int mauso;
	public:
		phanso();
		phanso(const phanso &);
		phanso(int, int);
		
		int getTuso();
		int getMauso();
		void setTuso(int);
		void setMauso(int);
		
		int ucln(int,int);
		void nhap();
		void xuat();
		void rutgon();
		float GiaTriPS();
		
		phanso ChuanHoaPS();
		phanso Cong(phanso);
		phanso Tru(phanso);
		phanso Nhan(phanso);
		phanso Chia(phanso);
		
		bool operator>(phanso);
		bool operator>=(phanso);
		bool operator<(phanso);
		bool operator<=(phanso);
		bool operator==(phanso);
		bool operator!=(phanso);
		
		phanso operator+(phanso);
		void operator-(phanso);
		void operator*(phanso);
		void operator/(phanso);
		void tinh_toantu(phanso);
};

int main(){
	phanso a,b,c;
	
	//nhap, xuat phanso
	cout<<"Nhap phan so thu nhat: "<<endl; a.nhap();
	cout<<"Phan so vua nhap: "; a.xuat();
	cout<<"Phan so sau khi toi gian: "; a.rutgon(); a.xuat();
	cout<<"Chuan hoa phan so: "; a.ChuanHoaPS().xuat();
	
	cout<<endl<<endl<<"Nhap phan so thu hai: "<<endl; b.nhap();
	cout<<"Phan so vua nhap: "; b.xuat();
	cout<<"Phan so sau khi toi gian: "; b.rutgon(); b.xuat();
	cout<<"Chuan hoa phan so: "; b.ChuanHoaPS().xuat();
	//Chuan hoa phanso
	c=b+a;
	
//	cout<<"Gia tri phan so thu nhat: "<<a.GiaTriPS();
	//tinh phanso
	//c1:
	cout<<endl<<endl<<"Tong hai phan so c1: "; a.Cong(b).xuat();
	cout<<endl<<"Hieu hai phan so c1: "; a.Tru(b).xuat();
	cout<<endl<<"Tich hai phan so c1: "; a.Nhan(b).xuat();
	cout<<endl<<"Chia hai phan so c1: "; a.Chia(b).xuat();
	
	//c2:
	a.operator+(b).xuat();
	a.operator-(b);
	a.operator*(b);
	a.operator/(b);
	
	//so sanh phanso
	if(a.operator>(b)) cout<<endl<<"Phan so a > phan so b"<<endl;
	else if (a.operator<(b)) cout<<endl<<"Phan so a < phan so b"<<endl;
	else cout<<endl<<"Phan so a = phan so b"<<endl;
	
	
	if(a.operator>(b)) cout<<endl<<"Phan so a > phan so b"<<endl;
	else if(a.operator>=(b)) cout<<endl<<"Phan so a >= phan so b"<<endl;
	else if (a.operator<(b)) cout<<endl<<"Phan so a < phan so b"<<endl;
	else if (a.operator<=(b)) cout<<endl<<"Phan so a <= phan so b"<<endl;
	else if (a.operator!=(b)) cout<<endl<<"Phan so a != phan so b"<<endl;
	else cout<<endl<<"Phan so a = phan so b"<<endl;
	getch();
	return 0;
}

phanso::phanso(){
	tuso=0; mauso=1;
}

phanso::phanso(const phanso &p){
	tuso=p.tuso; mauso=p.mauso;
}

phanso::phanso(int t,int m){
	tuso=t; mauso=m;
}

phanso phanso::ChuanHoaPS(){
	phanso tmp;
	if(tuso*mauso>0){
		tmp.tuso=abs(tuso);
		tmp.mauso=abs(mauso);
	}
	else{
		if(mauso<0){
			tmp.tuso=tuso*(-1);
			tmp.mauso=mauso*(-1);
		}
	}
	return tmp;
}

void phanso::nhap(){
	cout<<"Nhap tu so: "; cin>>tuso;
	cout<<"Nhap mau so: "; cin>>mauso;
	if(mauso==0){
		cout<<"Vui long nhap lai mau so!"<<endl;
		cin>>mauso;
	}
}

void phanso::xuat(){
	if(mauso==1) cout<<tuso<<endl;
	else 
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
	if(a>b) {
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

void phanso::rutgon(){
	int k=ucln(tuso,mauso);
	tuso=tuso/k;
	mauso=mauso/k;
}

float phanso::GiaTriPS(){
	return (float) tuso/mauso;
}

phanso phanso::Cong(phanso ps){
	phanso tmp;
	tmp.tuso=tuso*ps.mauso + mauso*ps.tuso;
	tmp.mauso=mauso*ps.mauso;
	tmp.rutgon();
	return tmp;
}

phanso phanso::Tru(phanso ps){
	phanso tmp;
	tmp.tuso=tuso*ps.mauso - mauso*ps.tuso;
	tmp.mauso=mauso*ps.mauso;
	tmp.rutgon();
	return tmp;
}

phanso phanso::Nhan(phanso ps){
	phanso tmp;
	tmp.tuso=tuso*ps.tuso;
	tmp.mauso=mauso*ps.mauso;
	tmp.rutgon();
	return tmp;
}

phanso phanso::Chia(phanso ps){
	phanso tmp;
	tmp.tuso=tuso*ps.mauso;
	tmp.mauso=mauso*ps.tuso;
	tmp.rutgon();
	return tmp;
}

bool phanso::operator>(phanso ps){
	float a = GiaTriPS();
	float b = ps.GiaTriPS();
	return a>b;
}

bool phanso::operator>=(phanso ps){
	float a = GiaTriPS();
	float b = ps.GiaTriPS();
	return a>=b;
}

bool phanso::operator<(phanso ps){
	float a = GiaTriPS();
	float b = ps.GiaTriPS();
	return a<b;
}

bool phanso::operator<=(phanso ps){
	float a = GiaTriPS();
	float b = ps.GiaTriPS();
	return a<=b;
}

bool phanso::operator!=(phanso ps){
	float a = GiaTriPS();
	float b = ps.GiaTriPS();
	return a!=b;
}

bool phanso::operator==(phanso ps){
	float a = GiaTriPS();
	float b = ps.GiaTriPS();
	return a==b;
}

phanso phanso::operator+(phanso ps){
	cout<<endl<<"Cong hai phan so c2: ";
	phanso tmp;
	tmp.tuso=tuso*ps.mauso + mauso*ps.tuso;
	tmp.mauso=mauso*ps.mauso;
	tmp.rutgon();
	tmp.xuat();
	return tmp;
}

void phanso::operator-(phanso ps){
	cout<<endl<<"Tru hai phan so c2: ";
	phanso tmp;
	tmp.tuso=tuso*ps.mauso - mauso*ps.tuso;
	tmp.mauso=mauso*ps.mauso;
	tmp.rutgon();
	tmp.xuat();
}

void phanso::operator*(phanso ps){
	cout<<endl<<"Tich hai phan so c2: ";
	phanso tmp;
	tmp.tuso=tuso*ps.tuso;
	tmp.mauso=mauso*ps.mauso;
	tmp.rutgon();
	tmp.xuat();
}

void phanso::operator/(phanso ps){
	cout<<endl<<"Chia hai phan so c2: ";
	phanso tmp;
	tmp.tuso=tuso*ps.mauso;
	tmp.mauso=mauso*ps.tuso;
	tmp.rutgon();
	tmp.xuat();
}

