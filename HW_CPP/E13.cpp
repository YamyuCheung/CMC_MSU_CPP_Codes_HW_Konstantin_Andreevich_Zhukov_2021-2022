//
//  E13.cpp
//  C++
//
//  Created by Xinyu Zhang on 07/03/2022.
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
#include<cerrno>
#include<cmath>

using namespace std;
class Vec{
    int n;
    double *v;
public:
    Vec(int n, double *v);
    Vec(int n);
    Vec(const Vec &op);
    void print();
    void set(double arg, int coord);
    double get(int coord);
    double euc_norm();
    double max_norm();
    ~Vec(){
        delete [] v;
    }
};
Vec::Vec(int n, double *v){
    if (n < 0){
        throw "err_code1";
    }
    this->n = n;
    this->v = new double[n];
    for (int i = 0; i < n; i++){
        this->v[i] = v[i];
    }
}
Vec::Vec(int n){
    if (n < 0){
        throw "err_code1";
    }
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
void Vec::print(){
    if (n == 0){
        return;
    }else{
        cout << "(";
        for(int i = 0; i < n; i++){
            cout << v[i];
            if(i+1 < n){
                cout << ",";
            }
            else{
                cout << ")" << endl;
            }
        }
    }
}
void Vec::set(double arg, int coord){
    if((coord < 0) || (coord >= n)){
        throw "err_code3";
    }
    if((coord>= 0) && (coord < n)){
        v[coord] = arg;
    }
}
double Vec::get(int coord){
    if ((coord >= n) || (coord < 0)){
        throw "err_code2";
    }
    if((coord < n) && coord >= 0){
        return v[coord];
    }else{
        return 0;
    }
}
double Vec::euc_norm(){
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += v[i]*v[i];
    }
    return sqrt(sum);
}
double Vec::max_norm(){
    if (n == 0){
        return 0;
    }else{
        double dout = 0;
        for (int i = 0; i < n; i++){
            if (dout < abs(v[i])){
                dout = abs(v[i]);
            }
        }
        return dout;
    }
}

//void error()
//{
//    double y1[3] = {1,2,3};
//    double y2[5] = {2,1,0,5,7};
//    Vec x(-3, y1), y(5, y2), z(4);
//    Vec u = x;
//    y.print();
//    x.print();
//    z.print();
//    u.print();
//}

int main(){
    try{
        error();
    }catch (const char* err_code){
        if(!strcmp(err_code, "err_code1")){
            cerr << "Exception: length error" << endl;
        }
        else if (!strcmp(err_code, "err_code2")){
            cerr << "Exception: coordinate error in get()" << endl;
        }
        else if (!strcmp(err_code, "err_code3")){
            cerr << "Exception: coordinate error in set()" << endl;
        }
    }catch(...){
        cerr << "Exception: unknown error" << endl;
    }
    return 0;
}

