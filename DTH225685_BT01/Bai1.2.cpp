#include<iostream>
#include<math.h>
#include<iomanip> 
#include<stdbool.h>
#include<conio.h>
using namespace std;

class complex{
	private:
		float real;
		float imaginary;
		
	public:
		complex();
		complex(const complex &);
		complex(float,float);
		
		void input();
		void output();
		float module();
		
		complex Tong(complex);
		complex Tru(complex);
		complex Tich(complex);
		complex Chia(complex);
		
		bool operator>(complex);
		bool operator<(complex);
		bool operator==(complex);
};

int main(){
	complex cp1,cp2;
	cout<<"Nhap 2 so phuc: "<<endl;
	cout<<"Nhap so phuc thu nhat: "<<endl; cp1.input(); 
	cout<<"Nhap so phuc thu hai: "<<endl; cp2.input(); 
	
	cout<<"2 so phuc vua nhap: "<<endl;
	cp1.output();
	cp2.output();
	
	cout<<"Module so phuc 1: "<<cp1.module()<<endl;
	cout<<"Module so phuc 2: "<<cp2.module()<<endl;
	
	cout<<endl<<"Tong hai so phuc: "; cp1.Tong(cp2).output();
	cout<<endl<<"Tru hai so phuc: "; cp1.Tru(cp2).output();
	cout<<endl<<"Tich hai so phuc: "; cp1.Tich(cp2).output();
	cout<<endl<<"Chia hai so phuc: "; cp1.Chia(cp2).output();
	
	if(cp1.operator>(cp2)) cout<<"So phuc a > so phuc b"<<endl;
	else if(cp1.operator<(cp2)) cout<<"So phuc a < so phuc b"<<endl;
	else if(cp1.operator==(cp2)) cout<<"So phuc a == so phuc b"<<endl;
	getch();
	return 0;
} 

complex::complex(){
	real=0.0;
	imaginary=0.0;
}

complex::complex(const complex &a){
	real=a.real;
	imaginary=a.imaginary;
}

complex::complex(float x,float y){
	real=x;
	imaginary=y;
}

void complex::input(){
	cout<<"Nhap so thuc: "; cin>>real;
	cout<<"Nhap so ao: "; cin>>imaginary;
	cout<<endl;
}

void complex::output(){
	cout<<real<<" + "<<imaginary<<"i"<<endl;
}

float complex::module(){
	return sqrt(pow(real,2)+pow(imaginary,2));
}

complex complex::Tong(complex cp){
	complex tmp;
	tmp.real= real + cp.real;
	tmp.imaginary= imaginary + cp.imaginary;
	return tmp;
}

complex complex::Tru(complex cp){
	complex tmp;
	tmp.real= real - cp.real;
	tmp.imaginary= imaginary - cp.imaginary;
	return tmp;
}

complex complex::Tich(complex cp){
	complex tmp;
	tmp.real= (real * cp.real) - (imaginary * cp.imaginary);
	tmp.imaginary= (real*cp.imaginary) + (imaginary*cp.real);
	return tmp;
}

complex complex::Chia(complex cp){
	complex tmp;
	tmp.real= (real * cp.real + imaginary * cp.imaginary)/(pow(cp.real,2) + pow(cp.real,2));
	tmp.imaginary= (imaginary*cp.real) - (real*cp.imaginary);
	return tmp;
}

bool complex::operator>(complex cp){
	return module()>cp.module();
}

bool complex::operator<(complex cp){
	return module()<cp.module();
}

bool complex::operator==(complex cp){
	return module()==cp.module();
}
