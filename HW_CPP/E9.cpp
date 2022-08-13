//
//  E9.cpp
//  C++
//
//  Created by Xinyu Zhang on 25/02/2022.
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
//
#include <iostream> //class ostream cout это объект класса ostream

using namespace std;
class Vector_2d{
    private:
    int x,y;
    public:
    Vector_2d(int arg_x = 0, int arg_y = 0){
        x = arg_x;
        y = arg_y;
    }
    void print(const char* str) const; //Константный метод
    const Vector_2d operator+(const Vector_2d& op) const;
    const Vector_2d operator-(const Vector_2d& op) const{
        return Vector_2d(x-op.x, y-op.y); //ананимный объект
    }
    int get_x() const{
        return x;
    }
    int get_y() const{
        return y;
    }
    const Vector_2d& operator=(const Vector_2d& op){ // работа не вызывается конструктор копирования, а передаем по ссылке
        x = op.x; y = op.y;
        return *this; //this указатель на объект *this это сам объект не вызывается конструктор копирования
    } //возвращаем значение по ссылке
    bool operator==(const Vector_2d& op){
        if ((x == op.x) && (y = op.x)){
            return true;
        }else{
            return false;
        }
    }
    const Vector_2d operator*(int a) const{
        return Vector_2d(a*x, a*y);
    }
    Vector_2d& operator++(){
        x++;
        y++;
        return *this;
    }
    Vector_2d operator++(int){
        Vector_2d tmp(x,y);
        x++;
        y++;
        return tmp;
    }
    const Vector_2d& operator+=(const Vector_2d& op){
        x += op.x; y+= op.y;
        return *this;
    }
    friend const Vector_2d operator*(int a, const Vector_2d& op);
    friend ostream& operator<<(ostream &os, const Vector_2d& op); //определяем оперпцию <<
    friend istream& operator>>(istream &is, Vector_2d& op); //
};
//Переопределим операцию * внешней функцией
ostream& operator<<(ostream &os, const Vector_2d& op){
    os << "(" << op.x << "," << op.y << ")" ;
    return os;
}
istream& operator>>(istream &is, Vector_2d& op){
    is >> op.x >> op.y;
    return is;
}
const Vector_2d operator*(int a, const Vector_2d& op){
    // int x = op.get_x(); //не удобно использовать метод get_x и get_y
    // int y = op.get_y();
    return Vector_2d(a*op.x, a*op.y);

}
const Vector_2d Vector_2d:: operator+(const Vector_2d& op) const{ //Операция сложения для двух векторов
    Vector_2d tmp;
    tmp.x = x + op.x;
    tmp.y = y + op.y;
    return tmp;
}//мы позвращаем копию объект
void Vector_2d::print(const char* str = 0) const{
    if (str){
        cout << str << " = ";
    }
    cout << "(" << x << "," << y << ")" << endl;

}
//int main()
//{
//    int x, y, z = 6;
//    Vector_2d v(1,2); //x = 1 y =2
//    Vector_2d u(3); //x = 3, y = 0
//    Vector_2d w; //x = 0 y = 0
//    v.print("v");
//    u.print();
//    (u+v).print("u+v"); //u+v -> u.operator+(v)
//    (u-v).print("u-v");
//    w = v;
//    w.print("w");
//    x = y = z = 5; //x = 5; y = 5; z = 5;
//    w = u = v; //u = v->.operator = (v)
//    w.print("w");
//    u.print("u");
//    // if (u+w == v){
//    //     cout << "YES" << endl;
//    // }else{
//    //     cout << "NO" << endl;
//    // }
//    w = v*4; //ok
//    w.print("v*4"); //v*4-> v.operator*(4)
//    u = 4*v; //error
//    u.print("4*v");
//    cout << "v = " << v << endl; // использовать << для вывода вектора
//    cin >> u;
//    cout << "u = " << u << endl;
//    w = u++;
//    cout << "w = " << w << "u = " << u << endl;
//    w+= u;
//
//    return 0;
//}
