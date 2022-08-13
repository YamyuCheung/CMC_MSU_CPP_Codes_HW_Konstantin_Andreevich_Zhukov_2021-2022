//
//  E29.cpp
//  C++
//
//  Created by Xinyu Zhang on 29/03/2022.
//
//
//
//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               佛祖保佑         永无BUG
//
//
//
//
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class Exception{
    string errinf;
public:
    Exception(const char* arg_errinf):errinf(arg_errinf){
    }
    Exception(const Exception& other){
        errinf = other.errinf;
    }
    ~Exception(){
    }
    string GetErrinf() const{
        return errinf;
    }
};
class Exception1 : public Exception{
    int errindex;
    string errinf;
public:
    Exception1(const char* arg_errinf, int arg_errindex):Exception(arg_errinf){
        errindex = arg_errindex;
    }
    int get_index() const{
        return errindex;
    }
    Exception1(const Exception1& other):Exception(other){
        errindex = other.errindex;
    }
    ~Exception1(){
    }

};
class Exception2 : public Exception1{
    int errindex;
    int errindex2;
    string errinf;
public:
    Exception2(const char* arg_errinf, int arg_errindex, int arg_errindex2):Exception1(arg_errinf, arg_errindex){
        errindex2 = arg_errindex2;
    }
    int get_index2() const{
        return errindex2;
    }
    Exception2(const Exception2& other):Exception1(other){
        errindex2 = other.errindex2;
    }
    ~Exception2(){
    }
};

template<class D>
class Vec{
    int n;
    D *v;
public:
    Vec<D>(int n, D *v);
    Vec<D>(int n);
    Vec<D>(const Vec<D>& op);
    void set(D arg, int coord);
    D get(int coord);
    D max_norm();
    D& operator[](int index);
    Vec<D>& operator=(const Vec<D>& op);

    template<class T>friend const Vec<T> operator+(const Vec<T>& op1, const Vec<T>& op2);
    template<class T>friend const Vec<T> operator*(const Vec<T>& op, T a);
    template<class T>friend const Vec<T> operator*(T a, const Vec<T>& op);
    template<class T>friend const T operator^(const Vec<T>& op1, const Vec<T>& op2);
    template<class T>friend const Vec<T> operator+=(const Vec<T>& op1, const Vec<T>& op2);
    template<class T>friend ostream& operator<<(ostream &os, const Vec<T>& op);
    template<class T>friend bool operator==(const Vec<T>& op1, const Vec<T>& op2);

    ~Vec<D>(){
        delete [] v;
    }

};

template<class D>Vec<D>::Vec(int n, D *v){
    if (n < 0){
        throw Exception("length error");
    }
    this->n = n;
    this->v = new D[n];
    for(int i = 0; i < n; i++){
        this->v[i] = v[i];
    }
}

template<class D>Vec<D>::Vec(int n){
    if (n < 0){
        throw Exception("length error");
    }
    this->n = n;
    v = new D[n];
    for(int i = 0; i < n; i++){
        v[i] = 0;
    }
}

template<class D>Vec<D>::Vec(const Vec<D> &op){
    n = op.n;
    v = new D[n];
    for(int i = 0; i < n; i++){
        v[i] = op.v[i];
    }
}
template<class D>void Vec<D>::set(D arg, int coord){
    if((coord < n) && (coord >= 0)){
        v[coord] = arg;
    }else{
        throw Exception("coordinate error in set()");
    }
}

template<class D>D Vec<D>::get(int coord){
    if((coord < n) && (coord >= 0)){
        return v[coord];
    }else{
        throw Exception("coordinate error in get()");
    }
}

template<class D>D Vec<D>::max_norm(){
    D mn = 0;
    for(int i = 0; i < n; i++){
        if (mn < abs(v[i])){
            mn = abs(v[i]);
        }
    }
    return mn;
}

template<class D>D& Vec<D>::operator[](int index){
    if (index >= 0 && index < n){
        return v[index];
    }else{
        throw Exception1("incorrect indexing:", index);
    }
}

template<class D>
Vec<D>& Vec<D>::operator=(const Vec<D> &op){
    if (n == op.n){
        for(int i = 0; i < n; i++){
            v[i] = op.v[i];
        }
    }else{
        delete [] v;
        n = op.n;
        v = new D[n];
        for (int i = 0 ; i < n; i++){
            v[i] = op.v[i];
        }
    }
    return *this;
}

template<class D>const Vec<D> operator+(const Vec<D>& op1, const Vec<D>& op2){
    if (op1.n != op2.n){
        throw Exception2("addition of vectors of different lengths:", op1.n, op2.n);
    }
    Vec<D> tmp(op1.n);
    for(int i = 0; i< op1.n; i++){
        tmp.v[i] = op1.v[i]+op2.v[i];
    }
    return tmp;
}

template<class D>const Vec<D> operator*(const Vec<D>& op, D a){
    Vec<D> tmp(op.n);
    for (int i = 0; i < op.n; i++){
        tmp.v[i] = a*op.v[i];
    }
    return tmp;
}

template<class D>const Vec<D> operator*(D a, const Vec<D>& op){
    Vec<D> tmp(op.n);
    for (int i = 0; i < op.n; i++){
        tmp.v[i] = a*op.v[i];
    }
    return tmp;
}

template<class D>const D operator^(const Vec<D>& op1, const Vec<D>& op2){
    if (op1.n != op2.n){
        throw Exception2("multiplication of vectors of different lengths:", op1.n, op2.n);
    }
    D tmp = 0;
    for (int i = 0; i < op1.n; i++){
        tmp = op1.v[i]*op2.v[i] + tmp;
    }
    return tmp;
}
template<class D>const Vec<D> operator+=(const Vec<D>& op1, const Vec<D>& op2){
    if (op1.n != op2.n){
        throw Exception2("addition of vectors of different lengths:", op1.n, op2.n);
    }
    Vec<D> tmp(op1.n);
    for(int i = 0; i < op1.n; i++){
        op1.v[i] = op1.v[i] + op2.v[i];
    }
    return op1;
}

template<class D>
ostream& operator<<(ostream& os, const Vec<D>& op){
    os << "(";
    for (int i = 0; i < op.n; i++){
        if(op.n-1 == i){
            os << op.v[i];
        }else{
            os << op.v[i] << ",";
        }
    }
    os << ")";
    return os;
}

template<class D>bool operator==(const Vec<D>& op1, const Vec<D>& op2){
    if(op1.n == op2.n){
        for(int i = 0; i < op1.n; i++){
            if(op2.v[i] != op1.v[i]){
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
}


//void Vector()
//{
//      double wd[3] = {1.5,2.3,-1.7};
//      double wd2[4] = {1.1,2.3,4.5,6.7};
//      Vec<double>  vd1(3, wd), vd2(4, wd2);
//      vd2 += vd1;
//      cout << "vd1 = " << vd1 << endl;
//      cout << "vd2 = " << vd2 << endl;
//      double prd = vd1^vd2;
//      cout << "vd1^vd2 = " << prd << endl;
//      vd2 = vd1 = vd1;
//      cout << "vd2 = " << vd2 << endl;
//}

int main(){
    try{
        Vector();
    }catch(Exception2& ex){
        cerr << "Exception: " << ex.GetErrinf() << " " << ex.get_index() << " " << ex.get_index2() << endl;
    }catch(Exception1& ex){
        cerr << "Exception: " << ex.GetErrinf() << " " << ex.get_index() << endl;
    }catch(Exception& ex){
        cerr << "Exception: " << ex.GetErrinf() << endl;
    }catch(...){
        cerr << "Exception: unknown error" << endl;
    }

    return 0;
}
