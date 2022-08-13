//
//  E23.cpp
//  C++
//
//  Created by Xinyu Zhang on 20/03/2022.
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
//               佛祖保佑         永无BUG
//
//
//
//
#include<iostream>
#include<fstream>
#include<cstring>
#include<cerrno>
using namespace std;

class Exception{
    string errinformation;
public:
    Exception(const char* arg_errinf) : errinformation(arg_errinf){
    }
    Exception(const Exception& other){
        errinformation = other.errinformation;
    }
    ~Exception(){
    }
    string GetErrInf() const{
        return errinformation;
    }
};

class NegException: public Exception{
    int index;
    string errinf;
public:
    NegException(int arg, const char* arg_inf): Exception(arg_inf){
        index = arg;
    }
    int get_index() const{
        return index;
    }
    NegException(const NegException& other): Exception(other){
        index = other.index;
    }
    ~NegException(){
    }
};

class Vector_2d{
    private:
    int x,y;
    public:
    Vector_2d(int arg_x = 0, int arg_y = 0){
        x = arg_x;
        y = arg_y;
    }

    friend ostream& operator<<(ostream &os, const Vector_2d& op); //определяем оперпцию <<
    friend istream& operator>>(istream &is, Vector_2d& op); //
};
//Переопределим операцию * внешней функцией
ostream& operator<<(ostream &os, const Vector_2d& op){
    os << "(" << op.x << "," << op.y << ")" ;
    return os;
}
istream& operator>>(istream &is, Vector_2d& op){
    is >> op.x;
    if (cin.get() == '\n'){
        throw Exception("one coordinate");
    }
    is >> op.y;
    if (op.x < 0){
        throw NegException(op.x, "negative coordinate:");
    }
    if (op.y < 0){
        throw NegException(op.y, "negative coordinate:");
    }
    return is;
}

int main()
{
    try{
        Vector_2d v;
        cin >> v;
        cout << v << endl;
    }catch(NegException &ex){
        cerr << "Exception: " << ex.GetErrInf() << ex.get_index() << endl;
    }catch(Exception &ex){
        cerr << "Exception: " << ex.GetErrInf() <<endl;
    }
    
    return 0;
}

