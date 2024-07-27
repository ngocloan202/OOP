#include<iostream>
#include<malloc.h>
using namespace std;
struct phanso{
	int tuso, mauso;
};
phanso nhap(phanso &p);
int KiemTraPhanSo(phanso p);
int main(){
	phanso *p;
//	p=(phanso*)malloc(sizeof(phanso));
	p=new phanso; 
	nhap(*p);
	if(KiemTraPhanSo(*p)==-1) cout<<"Phan so am";
	else if(KiemTraPhanSo(*p)==1) cout<<"Phan so duong";
	else cout<<"Phan so bang 0";
	delete p;
	return 0;
} 

phanso nhap(phanso &p){
	cout<<"Tu so: "; cin>>p.tuso;
	cout<<"Mau so: "; cin>>p.mauso;
	if(p.mauso==0){
		cout<<"Vui long nhap lai mau so!"<<endl;
		cout<<"Mau so: "; cin>>p.mauso;
	}
	return p;
}

int KiemTraPhanSo(phanso p){
	if((p.mauso<0 && p.tuso>0) || (p.mauso>0 && p.tuso<0)) return -1;
	else if((p.mauso<0 && p.tuso<0) || (p.tuso>0 && p.mauso>0)) return 1;
	else if(p.tuso==0) return 0;
} 
