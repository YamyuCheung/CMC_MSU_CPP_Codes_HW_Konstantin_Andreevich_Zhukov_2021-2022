#include <iostream>
#include <cmath>
using namespace std;

void Solution();

class Root{
protected:
	double root1, root2;
public:
	virtual void find_roots() = 0;
	virtual void print_roots() const = 0;
	virtual ~Root() {}
};

class Linear : public Root {
	double a, b;
public:
	Linear(double argA, double argB) : a(argA), b(argB) {}
	virtual void print_roots() const;
	virtual void find_roots();
};

void Linear::find_roots(){
	if(a == 0.){
		if(b == 0.)
			throw 1;//无穷多解
		else
			throw 2;//无解
	}
	root1 = -b / a;
	if(root1 == 0.)
		root1 = 0.;
}

void Linear::print_roots() const {
	cout << root1 << endl;
}
// 根不存在或多于两个 则发送异常
class Square : public Root {
	double a, b, c;
public:
	Square(double argA, double argB, double argC) : a(argA), b(argB), c(argC) {}
	virtual void print_roots() const;
	virtual void find_roots();
};

void Square::find_roots(){
	if(a == 0.){
		if(b == 0.){
			if(c == 0.)
				throw 1;
			else
				throw 2;
		}
		root1 = root2 = -c / b;
		if(root1 == 0.)
			root1 = 0.;
		if(root2 == 0.)
			root2 = 0.;
		return;
	}
	double n = b*b - 4*a*c;
	if(n < 0.)
		throw 2;//无实数解
	n = sqrt(n);
	root1 = (-b + n)/(2.*a);
	root2 = (-b - n)/(2.*a);
	if(root1 == 0.)
		root1 = 0.;
	if(root2 == 0.)
		root2 = 0.;
}

void Square::print_roots() const {
	cout << root1 << " " << root2 << endl;
}

int main(){
	try{
		Solution();
	}
	catch(int n){
		if(n == 1){
			cerr << "Exception: infinitely many roots" << endl;
		}
		if(n == 2){
			cerr << "Exception: no roots" << endl;
		}
	}
	return 0;
}

void Solution(){
	Root *r[5];
	r[0] = new Linear(2.,3.);
	r[1] = new Square(2.,-5.,2.);
	r[2] = new Linear(2.,0.);
	r[3] = new Square(16.,0.,-25.);
	r[4] = new Square(1.,7.,0.);
	for(int i = 0; i < 5; i++)
		r[i] -> find_roots();
	for(int i = 0; i < 5; i++)
		r[i] -> print_roots();
	for(int i = 0; i < 5; i++)
		delete r[i];
}

/*
void Solution(){
	Linear l1(0.,0.);
	Root& r1 = l1;
	r1.find_roots();
	r1.print_roots();
}
*/
/*
void Solution(){
	Square s1(0.,-2.,1.);
	s1.find_roots();
	s1.print_roots();
}
*/


