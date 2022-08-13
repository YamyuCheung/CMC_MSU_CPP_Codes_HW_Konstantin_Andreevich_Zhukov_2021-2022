//
//  E7.cpp
//  C++
//
//  Created by Xinyu Zhang on 22/02/2022.
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
//#include<iostream>
//#include<cstring>
//#include<cmath>
//
//using namespace std;
class Vec{
    int n;
    double *v;
public:
    Vec(int n, double *v);
    Vec(int n);
    Vec(const Vec &op);
    void print() const;
    void set(double arg, int coord) const;
    double get(int coord) const;
    double euc_norm() const;
    double max_norm() const;
    ~Vec(){
        delete [] v;
    }
};
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
void Vec::print() const{
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
void Vec::set(double arg, int coord) const{
    if((coord>= 0) && (coord < n)){
        v[coord] = arg;
    }
}
double Vec::get(int coord) const{
    if((coord < n) && coord >= 0){
        return v[coord];
    }else{
        return 0;
    }
}
double Vec::euc_norm() const{
    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += v[i]*v[i];
    }
    return sqrt(sum);
}
double Vec::max_norm() const{
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
//
//int main(void)
//{
//    double y1[3] = {1.1,2.2,3.3};
//    double y2[5] = {2,1,0,5,7};
//    Vec x(3, y1), y(5, y2), z(4);
//    Vec u = x;
//
//    y.print();
//    x.print();
//    z.print();
//    u.print();
//
//    x.set(23, 2);  u.set(34, 1);  z.set(-3, 3);
//    cout << "x[2] = " << x.get(2) << endl;
//    cout << "u[1] = " << u.get(1) << endl;
//    x.print();
//    x.euc_norm();
//    cout << "euc_norma y: " << y.euc_norm() << endl;
//    cout << "max_norma z: " << z.max_norm() << endl;
//    return 0;
//}
