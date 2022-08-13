//
//  E14.cpp
//  C++
//
//  Created by Xinyu Zhang on 08/03/2022.
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
    char* err_code;
    int index1, index2;
public:
    Exception(const char* arg_code, int arg1, int arg2){
        err_code = strdup(arg_code);
        index1 = arg1;
        index2 = arg2;
    }
    const int get_index1(){
        return this->index1;
    }
    const int get_index2(){
        return this->index2;
    }
    const char* get_err_code(){
        return err_code;
    }
};
class Vec{
    int n;
    double *v;
public:
    Vec(int n, double *v);
    Vec(int n = 1);
    Vec(const Vec &op);
    Vec& operator=(const Vec& op){
        if(this->n == op.n){
            for (int counter = 0; counter < op.n; counter++){
                v[counter] = op.v[counter];
            }
        }else{
            delete[] v;
            n = op.n;
            v = new double[op.n];
            for (int counter = 0; counter < op.n; counter++){
                v[counter] = op.v[counter];
            }
        }
        return *this;
    }

    const Vec operator+(const Vec& a) const{
        if (a.n != n){
            throw Exception("err_code1", n, a.n);
        }
        Vec newindex(a.n);
        for (int counter = 0; counter < a.n; counter++){
            newindex.v[counter] = a.v[counter] + v[counter];
        }
        return newindex;
    }
    const Vec operator-(const Vec& a) const{
        Vec newindex(a.n);
        for (int counter = 0; counter < a.n; counter++){
            newindex.v[counter] = v[counter] - a.v[counter];
        }
        return newindex;
    }
    double& operator[](int counter){
        if ((counter >= n) || (counter < 0)){
            throw Exception("err_code2", 0, counter);
        }
        return v[counter];
    }

    bool operator==(const Vec op){
        if(this->n == op.n){
            for(int counter = 0; counter < op.n; counter++){
                if(this->v[counter] != op.v[counter]){
                    return false;
                }
            }
            return true;
        }else{
            return false;
        }
    }

    friend ostream& operator<<(ostream &os, const Vec& op);
    friend const Vec operator*(double a, const Vec& op);
    friend const Vec operator*(const Vec& op, double a);

    ~Vec(){
        delete [] v;
    }
};
ostream& operator<<(ostream& os, const Vec& op){
    os << "(";
    for(int counter = 0; counter < op.n; counter++){
        if(op.n-1 == counter){
            os << op.v[counter];
        }else{
            os << op.v[counter] << ",";
        }
    }

    os << ")";
    return os;
}
const Vec operator*(double a, const Vec& op){
    Vec newindex(op.n);
    for (int counter = 0; counter < op.n; counter++){
        newindex.v[counter] = a*op.v[counter];
    }
    return newindex;
}
const Vec operator*(const Vec& op, double a){
    Vec newindex(op.n);
    for (int counter = 0; counter < op.n; counter++){
        newindex.v[counter] = a*op.v[counter];
    }
    return newindex;
}
Vec::Vec(int n, double *v){
    this->n = n;
    this->v = new double[n];
    for (int i = 0; i < n; i++){
        this->v[i] = v[i];
    }
}
Vec::Vec(int n){
    this->n = n;
    v = new double[n];
    for (int i = 0; i < n; i++){
        v[i] = 0;
    }
}
Vec::Vec(const Vec &op){
    n = op.n;
    v = new double[n];
    for(int i = 0; i < n; i++){
        v[i] = op.v[i];
    }
}

//void error()
//{
//     Vec v1(3), v2(5), v3;
//
//      v3 = v1+v2;
//
//}
//void error()
//{
//    Vec v(5);
//    double a = v[7];
//}

int main(){
    try{
        error();
    }catch(Exception &ex){
        if(!strcmp(ex.get_err_code(), "err_code1")){
            cerr << "Exception: addition of vectors of different lengths: " << ex.get_index1() << ' ' << ex.get_index2() << endl;
        }else if(!strcmp(ex.get_err_code(), "err_code2")){
            cerr << "Exception: incorrect indexing: " << ex.get_index2() << endl;
        }
    }catch(...){
        cerr << "Exception: unknown error" << endl;
    }
    return 0;
}

//int main()
//{
//        double y1[4] = {1,2,3,4};
//        double y2[4] = {-2,1,3,-3};
//
//        Vec u(4, y1), v(4, y2);
//        Vec w(4);
//
//        cout << "u = " << u << endl;
//        cout << "v = " << v << endl;
//        w = u = u;
//        cout << "w = u = " << w << endl;
//        w = 4.*u + v*3;
//        cout << "w = 4.*u + v*3 = " << w << endl;
//        w[2] = 3;
//        w[0] = -1;
//        cout << "w = " << w << endl;
//
//        return 0;
//}

