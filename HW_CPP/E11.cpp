//
//  E11.cpp
//  C++
//
//  Created by Xinyu Zhang on 04/03/2022.
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

    double& operator[](int counter){
        return v[counter];
    }


    friend ostream& operator<<(ostream &os, const Vec& op);
    friend const Vec operator*(double a, const Vec& op);
    friend const Vec operator*(const Vec& op, double a);
    friend const Vec operator+(const Vec& a, const Vec& op);
    friend const Vec operator-(const Vec& a, const Vec& op);
    friend const bool operator==(const Vec& op, const Vec& op2);
    const Vec& operator=(const Vec& op);


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
const Vec operator+(const Vec& a, const Vec& op){
    Vec newindex(a.n);
    for (int counter = 0; counter < a.n; counter++){
        newindex.v[counter] = a.v[counter] + op.v[counter];
    }
    return newindex;
}
const Vec operator-(const Vec& a, const Vec& op){
    Vec newindex(a.n);
    for (int counter = 0; counter < a.n; counter++){
        newindex.v[counter] = a.v[counter] - op.v[counter];
    }
    return newindex;
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
const bool operator==(const Vec& op, const Vec& op2){
    if(op2.n == op.n){
        for(int counter = 0; counter < op.n; counter++){
            if(op2.v[counter] != op.v[counter]){
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
}
const Vec& Vec:: operator=(const Vec& op){
        if(n == op.n){
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
////    u = u - v;
////    cout << "u = " << u << endl;
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
