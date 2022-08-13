//
//  E19.cpp
//  C++
//
//  Created by Xinyu Zhang on 16/03/2022.
//
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

class SpatialFigures{
    double x, y, z;
public:
    SpatialFigures(double arg_x, double arg_y, double arg_z):x(arg_x), y(arg_y), z(arg_z){
        
    }
    void move(double mv_x, double mv_y, double mv_z){
        x = mv_x;
        y = mv_y;
        z = mv_z;
    }
    virtual double area() const = 0;
    virtual double volume() const = 0;
    virtual void print() const{
        cout << "(" << x << "," << y << "," << z << ") ";
    }
    virtual ~SpatialFigures(){
    }
};

class cube:public SpatialFigures{
    double l;
public:
    cube(double arg_x, double arg_y, double arg_z, double arg_l):SpatialFigures(arg_x, arg_y, arg_z), l(arg_l){
    }
    virtual double area() const{
        return l*l*6;
    }
    virtual double volume() const{
        return l*l*l;
    }
    virtual void print() const{
        SpatialFigures::print();
        cout << "l=" << l << endl;
    }
};
class ball:public SpatialFigures{
    double r;
public:
    ball(double arg_x, double arg_y, double arg_z, double arg_r):SpatialFigures(arg_x, arg_y, arg_z), r(arg_r){
    }
    virtual double area() const{
        return 4*M_PI*r*r;
    }
    virtual double volume() const{
        return (4./3.)*M_PI*r*r*r;
    }
    virtual void print() const{
        SpatialFigures::print();
        cout << "r=" << r << endl;
    }
};
class cylinder:public SpatialFigures{
    double r, h;
public:
    cylinder(double arg_x, double arg_y, double arg_z, double arg_r, double arg_h):SpatialFigures(arg_x, arg_y, arg_z), r(arg_r), h(arg_h){
    }
    virtual double area() const{
        return 2*M_PI*r*r + 2*M_PI*r*h;
    }
    virtual double volume() const{
        return M_PI*r*r*h;
    }
    virtual void print() const{
        SpatialFigures::print();
        cout << "r=" << r << " " << "h=" << h << endl;
    }
};


int main()
{
        ball ba(1,2,3,3);
        cube cu(2,1,3,2);
        cylinder cy(3,1,2,3,4);
        ba.print();
        cout << "area ball = " << ba.area() << endl;
        cout << "volume ball = " << ba.volume() << endl;
        cu.print();
        cout << "area cube = " << cu.area() << endl;
        cout << "volume cube = " << cu.volume() << endl;
        cy.print();
        cout << "area cylinder = " << cy.area() << endl;
        cout << "volume cylinder = " << cy.volume() << endl;
        ba.move(0,0,0);
        ba.print();
        cu.move(-2,-5,-7);
        cu.print();
        cy.move(5,-9,1);
        cy.print();

        return 0;
}
