//
//  E18.cpp
//  C++
//
//  Created by Xinyu Zhang on 15/03/2022.
//
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
//               佛祖保佑         永無BUG
//
//
//
//
#include <iostream>
#include <cmath>
using namespace std;

class BaseEllipse{ //Абстрактный класс
    double x, y;
    public:
    BaseEllipse(double arg_x, double arg_y):x(arg_x), y(arg_y){
    }
    void Move(double sd_x, double sd_y){
        x += sd_x;
        y += sd_y;
    }
    virtual    double area() const = 0;// чистая виртуальная функция эта фунция будет описана в классах наследниках
    virtual void Print() const{
        cout << "(" << x << "," << y << ")" ;
    }
    virtual ~BaseEllipse(){
    }
};

class Circle:public BaseEllipse{
    double r;
    public:
    Circle(double arg_x, double arg_y, double arg_r):BaseEllipse(arg_x, arg_y), r(arg_r){
    }
    virtual double area() const{
        return M_PI*r*r;
    }
    virtual void Print() const{
        BaseEllipse::Print();
        cout << " r = " << r << endl;
    }

};
class Ellipse:public BaseEllipse{
    double a, b, angle;
    public:
    Ellipse(double arg_x, double arg_y, double arg_a, double arg_b, double ang): BaseEllipse(arg_x, arg_y), a(arg_a), b(arg_b), angle(ang){
    }
    virtual double area() const{
        return M_PI*a*b;
    }
    virtual void Print() const{
        BaseEllipse::Print();
        cout << " a = " << a << " b = " << b << " angle = " << angle << endl;
    }
};

int main(){
    //BaseEllipse Be(2,3);
    BaseEllipse *B[3]; //указатели на абстрактный класс можно
    B[0] = new Ellipse(-1, 2, 3, 5, M_PI/6);
    B[1] = new Circle(4, -5, 3);
    B[2] = new Ellipse(2, 0, 2, 7, M_PI);

    for(int i = 0; i < 3; i++){
        B[i]->Print();
    }
    for(int i = 0; i < 3; i++){
        cout << B[i]->area() << endl;
    }
    for(int i = 0; i < 3; i++){
        B[i]->Move(2,3);
    }
    for(int i = 0; i < 3; i++){
        B[i]->Print();
    }
    for(int i = 0; i < 3; i++){
        delete B[i];
    }

    return 0;
}
