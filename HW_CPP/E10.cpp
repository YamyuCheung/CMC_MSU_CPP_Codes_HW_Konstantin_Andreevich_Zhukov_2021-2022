//
//  E10.cpp
//  C++
//
//  Created by Xinyu Zhang on 04/03/2022.
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
//#include<cmath>
//using namespace std;
class Complex{
    double x, y;
public:
    Complex(double arg_x = 0, double arg_y = 0){
        x = arg_x;
        y = arg_y;
    }
    
    
    friend ostream& operator<<(ostream &os, const Complex& op);
    friend const Complex operator*(double a, const Complex& op);
    friend const Complex operator*(const Complex& op, double a);
    friend const Complex operator-(double a, const Complex& op);
    friend const Complex operator-(const Complex& op, double a);
    friend const Complex operator+(double a, const Complex& op);
    friend const Complex operator+(const Complex& op, double a);
    friend const Complex operator+(const Complex& a, const Complex& op);
    friend const Complex operator-(const Complex& a, const Complex& op);
    friend const Complex operator*(const Complex& a, const Complex& op);
    friend const bool operator==(const Complex op, const Complex op2);
    const Complex operator=(const Complex& op);
    
    
};
ostream& operator<<(ostream& os, const Complex& op){
    if(op.x == 0){
        if(op.y == 0){
            return os<<op.x;
        }else if(op.y == 1){
            return os<<"i";
        }else if(op.y == -1){
            return os << "-i";
        }else{
            return os << op.y << "i";
        }
    }else{
        if(op.y == 0){
            return os << op.x;
        }else if(op.y == 1){
            return os << op.x << "+i";
        }else if(op.y == -1){
            return os << op.x << "-i";
        }else if(op.y > 0){
            return os << op.x << "+" << op.y << "i";
        }else{
            return os << op.x << "-" << abs(op.y) << "i";
        }
    }
    return os;
}
const Complex operator+(const Complex& a, const Complex& op){
    return Complex(a.x+op.x, a.y+op.y);
}
const Complex operator-(const Complex& a, const Complex& op){
    return Complex(a.x-op.x, a.y-op.y);
}
const Complex operator*(const Complex& a, const Complex& op){
    return Complex(op.x*a.x-op.y*a.y, op.x*a.y+a.x*op.y);
}
const Complex operator*(double a, const Complex& op){
    return Complex(a*op.x, a*op.y);
}
const Complex operator*(const Complex& op, double a){
    return Complex(a*op.x, a*op.y);
}
const Complex operator-(double a, const Complex& op){
    return Complex(a-op.x, op.y);
}
const Complex operator-(const Complex& op, double a){
    return Complex(a-op.x, op.y);
}
const Complex operator+(double a, const Complex& op){
    return Complex(a+op.x, op.y);
}
const Complex operator+(const Complex& op, double a){
    return Complex(a+op.x, op.y);
}
const Complex Complex:: operator=(const Complex& op){
    x = op.x;
    y = op.y;
    return *this;
}

const bool operator==(const Complex op, const Complex op2){
    if((op.x == op2.x) && (op.y == op2.y)){
        return true;
    }else{
        return false;
    }
}


//int main()
//{
//   Complex c(1,-2), g(3), v;
//   cout << "c = " << c << endl;
//   cout << "g = " << g << endl;
//   cout << "v = " << v << endl;
//   v = 4.*c*2.;
//   cout << "v = " << v << endl;
//   g = 3.-g+c-2.*v;
//   cout << "g = " << g << endl;
//   cout << "2.*g*v = " << 2.*g*v << endl;
//   v = g = c;
//   if (c == g)
//        v = 2.*Complex(0,1);
//   else
//        v = 2.;
//   cout << "c = " << c << " g = " << g << "v = " << v << endl;
//   return 0;
//}
