//
//  E6.cpp
//  C++
//
//  Created by Xinyu Zhang on 18/02/2022.
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

class Complex{
    double re;
    double im;
    public:
    Complex(double a, double b)
    {
        re = a; im = b;
    }
    Complex(double a)
    {
        re = a; im = 0;
    }
    Complex(){
        re = 0; im = 0;
    }
    Complex(const Complex & z){
        re = z.re; im = z.im;
    }
    void set(double a, double b){
        re = a; im = b;
    }
    double modulo() const{
        return sqrt(re*re +im*im);
    }
    double argument() const{
        return atan2(im, re);
    }
    double get_re() const{
        return re;
    }
    double get_im() const{
        return im;
    }
    void print() const{
        cout << re << "+" << im << "i" << endl;
    }
    ~Complex(){
        
    }
    
};
double pow2(const Complex& num){
    return num.get_re()*num.get_re()+num.get_im()*num.get_im();
}
