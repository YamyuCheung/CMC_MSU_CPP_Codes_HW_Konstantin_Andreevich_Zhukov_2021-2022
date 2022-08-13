#include <iostream>
using namespace std;

class QuadTrin{
    double a, b, c;
    char chr;
public:
    QuadTrin(double argA, double argB, double argC, char argChr = 'x') : a(argA), b(argB), c(argC), chr(argChr) {}
    double& operator[](int coord);
    void set_letter(char argChr);

    friend ostream& operator<<(ostream& os, const QuadTrin& qua);
    friend istream& operator>>(istream& is, QuadTrin& qua);
};
void QuadTrin::set_letter(char argChr){
    chr = argChr;
}

double &QuadTrin::operator[](int coord) {
    if(coord == 2)
        return a;
    if(coord == 1)
        return b;
    if(coord == 0)
        return c;
    throw 1;
}

istream& operator>>(istream& is, QuadTrin& qua){
    return is >> qua.a >> qua.b >> qua.c;
}

ostream& operator<<(ostream& os, const QuadTrin& qua){
    if(qua.a != 0.)
	os << qua.a << qua.chr << "^2";
    else
	    return os << 0.;
    if(qua.b > 0.)
        os << "+" << qua.b << qua.chr;
    else if(qua.b == 0.) ;
    else
        os << qua.b << qua.chr;
    if(qua.c > 0.)
        os << "+" << qua.c;
    else if(qua.c == 0.) ;
    else
        os << qua.c;
    return os;
}

void QuadraticTrinomial();

int main() {
    try{
        QuadraticTrinomial();
    }
    catch(int num){
        if(num == 1){
            cerr << "Exception: index error" << endl;
        }
    }
    return 0;
}

void QuadraticTrinomial(){
    QuadTrin s1(1,2,3);
    cout << s1 << endl;
    s1.set_letter('y');
    cin >> s1;
    cout << s1 << endl;
    cout << s1[2] << " " << s1[1] << " " << s1[0] << endl;
}

/*
void QuadraticTrinomial(){
    QuadTrin s2(-1,4,-5);
    s2[0] = 5.1;
    cout << s2[3] << endl;
}
*/
