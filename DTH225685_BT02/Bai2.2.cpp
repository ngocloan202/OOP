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
		bool KiemTraGocToaDo();
		bool KiemTraTamGiacDeu();
		
		void nhap();
		void xuat();
		void swap(TamGiac &,TamGiac &);
		void TinhChuVi();
		void TinhDienTich();
		Diem TrongTamTG();
		float TinhCanh(Diem, Diem);
		
};

class MangTamGiac{
	private:
		TamGiac a[100];
		int n;
	public:
		void nhap();
		void xuat();
		void LietKeDinhTDO();
		void LietKeTamGiacDeu();
		void TongDTTG();
		void IncreaseSortCV();
};

int main(){
	MangTamGiac x;
	x.nhap(); x.xuat();
	x.LietKeDinhTDO();
	x.LietKeTamGiacDeu();
	x.TongDTTG();
	x.IncreaseSortCV();
	getch();
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
//A(0, 1)
//B(sqrt(3)/2, -1/2)
//C(-sqrt(3)/2, -1/2)

void TamGiac::nhap(){
	cout<<"Nhap dinh thu nhat: "<<endl;  A = Diem(0,0);//A.input();
	cout<<endl<<"Nhap dinh thu hai: "<<endl;B = Diem(sqrt(3),3);// B.input();
	cout<<endl<<"Nhap dinh thu ba: "<<endl; C = Diem(-sqrt(3),3);//C.input();
	while(!KiemTraTG()){
		cout<<"Vui long nhap lai 3 diem!"<<endl;
		cout<<"Nhap dinh thu nhat: "<<endl; A.input();
		cout<<endl<<"Nhap dinh thu hai: "<<endl; B.input();
		cout<<endl<<"Nhap dinh thu ba: "<<endl; C.input();
	}
	TinhChuVi();
	TinhDienTich();
}

void TamGiac::xuat(){
	cout<<endl<<"Diem A: "; A.output();
	cout<<"Diem B: "; B.output();
	cout<<"Diem C: "; C.output();
	cout<<"Chu vi: "<<cv;
	cout<<endl<<"Dien tich: "<<dt;
	cout<<endl;
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

void TamGiac::TinhChuVi(){
	float a,b,c;
	a=TinhCanh(A,B); 
	b=TinhCanh(B,C); 
	c=TinhCanh(A,C); 
	cv=a+b+c;
}

void TamGiac::TinhDienTich(){
	float a,b,c,p;
	a=TinhCanh(A,B);
	b=TinhCanh(B,C);
	c=TinhCanh(A,C);
	p=cv/2;
	dt=sqrt(p*(p-a)*(p-b)*(p-c));
}

bool TamGiac::KiemTraGocToaDo(){
	return ((A.getX()==0 && A.getY()==0) || (B.getX()==0 && B.getY()==0) 
	|| (C.getX()==0 && C.getY()==0));
}

bool TamGiac::KiemTraTamGiacDeu(){
	float AB=TinhCanh(A,B);
	float AC=TinhCanh(A,C);
	float BC=TinhCanh(B,C);
//	cout<<AB<<" "<<AC<<" "<<BC;
/*    if((AB == AC )&& (AB == BC) && (AC == BC))
    	return 1;
    return 0;*/
    return ((AB == AC ) && (AB == BC) && (AC == BC));
}

bool TamGiac::KiemTraTamGiacCan()
{
	float AB=TinhCanh(A,B);
	float AC=TinhCanh(A,C);
	float BC=TinhCanh(B,C);
    return ((AB == AC) && (AB == BC))&& (AC == BC));
}

void TamGiac::swap(TamGiac &a,TamGiac &b){
	TamGiac tmp=a;
	a=b;
	b=tmp;
}

void MangTamGiac::nhap(){
	cout<<"Nhap so luong tam giac: "; cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Tam giac thu "<<i+1<<" "<<endl;
		a[i].nhap();
	}
}

void MangTamGiac::xuat(){
	cout<<"Xuat thong tin: "<<endl;
	for(int i=0;i<n;i++){
		cout<<"Tam giac thu "<<i+1<<" "<<endl;
		a[i].xuat();
	}
}

void MangTamGiac::LietKeDinhTDO(){
	int kq=0;
	for(int i=0;i<n;i++)
	if(a[i].KiemTraGocToaDo()){
		kq=1;
		break;
	}
	if(kq==1){
		cout<<"Cac tam giac nam o goc toa do: ";
		for(int i=0;i<n;i++)
		if(a[i].KiemTraGocToaDo()){
			a[i].xuat();
		}
	}
}

void MangTamGiac::LietKeTamGiacDeu(){
	int kq=0;
	for(int i=0;i<n;i++)
	if(a[i].KiemTraTamGiacDeu()){
		kq=1;
		break;
	}
	if(kq==1)
	{
		cout<<"Cac tam giac deu: ";
		for(int i=0;i<n;i++)
		if(a[i].KiemTraTamGiacDeu()){
			a[i].xuat();
		}
	}
}

void MangTamGiac::TongDTTG(){
	float tong=0;
	for(int i=0;i<n;i++)
	tong+=a[i].getDT();
	cout<<"Tong dien tich tam giac: "<<tong;
}

void MangTamGiac::IncreaseSortCV(){
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i].getCV()>a[j].getCV())
				swap(a[i],a[j]);
	
	cout<<endl<<"Sap xep tang theo chu vi"<<endl;
	for (int i = 0; i < n; i++)
        a[i].xuat();
}
