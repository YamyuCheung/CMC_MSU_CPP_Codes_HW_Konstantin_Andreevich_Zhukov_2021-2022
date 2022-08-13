//
//  E5.cpp
//  C++
//
//  Created by Xinyu Zhang on 18/02/2022.
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
//#include <iostream>
//#include <cstdlib>
//using namespace std;


class Quotient{
    int n;
    int d;
    int gcd(int n, int d){
        int a, gcd, b;
        a = n;
        gcd = d;
        b = a%gcd;
        while (b != 0){
            a = gcd;
            gcd = b;
            b = a%gcd;
        }
        if (gcd != 0){
            return gcd;
        }
        else{
            return 1;
        }
    }
public:
    Quotient(int x = 0, int y = 1){
        int ngcd = 0;
        n = x;
        d = y;
        if(d != 0){
            ngcd = gcd(n,d);
            if (ngcd != 1){
                n /= ngcd;
                d /= ngcd;
            }
        }
        if(d < 0){
            d = -d;
            n = -n;
        }
    }
    void print(){
        if (n == 0){
            cout << "0" << endl;
        }
        else if (d == 1){
            cout << n << endl;
        }
        else if (d == 0){
            d = 1;
            cout << n << endl;
        }
        else{
            cout << n << "/" << d << endl;
        }
    }
    
};

//int main()
//{
////       Quotient q1(4,2), q2(6,1), q3(-7), q4;
//       Quotient q1(6,0), q2(6,12), q3(7), q4;
//       q1.print();
//       q2.print();
//       q3.print();
//       q4.print();
//       return 0;
//}
