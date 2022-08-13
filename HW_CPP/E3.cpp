//
//  E3.cpp
//  C++
//
//  Created by Xinyu Zhang on 15/02/2022.
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


using namespace std;

class Complex{
    double r; //закрытая часть
    double arg;
    public:
        Complex(double a = 0, double b = 0){ //конструктор с параметрами. конструктор преобразования, Конструктор по умолчанию
            r = sqrt(a*a + b*b);
            arg = atan2(b, a);
        }
        double modulo(){
            return r;
        }
        double argument(){
            return arg;
        }
        double get_re(){
            return r*cos(arg);
        }
        double get_im(){
            return r*sin(arg);
        }
        void print(){
            cout << r*cos(arg) << "+" << r*sin(arg) << "i" << endl;
        }
};

double pow2(Complex num){
    return num.get_re()*num.get_re() + num.get_im()*num.get_im();
}
