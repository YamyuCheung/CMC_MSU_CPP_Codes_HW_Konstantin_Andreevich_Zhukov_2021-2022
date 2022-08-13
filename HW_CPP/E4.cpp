//
//  E4.cpp
//  C++
//
//  Created by Xinyu Zhang on 17/02/2022.
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
//using namespace std;

class Rect{
    int x, y;
    unsigned int wd, ht;
public:
    Rect(int a, int b, unsigned c, unsigned d){
        x = a; y = b; wd = c; ht = d;
    }
    Rect(){
        x = 0; y = 0; wd = 1; ht = 1;
    }
    Rect(unsigned a){
        x = 0; y = 0; wd = a; ht = a;
    }
    void print_corner(){
        cout << "(" << x << "," << y << ")" <<endl;
    }
    void print_sz(){
        cout << "wd=" << wd << " " << "ht=" << ht << endl;
    }
    int area(){
        return wd*ht;
    }
    int perimeter(){
        return 2*(wd+ht);
    }
    bool intersect(Rect r) {
        int wd_1=wd, ht_1=ht, wd_2=r.wd, ht_2=r.ht;
        int x_1=x, y_1=y, x_2=r.x, y_2=r.y;
        if((x_2 <= x_1+wd_1)&&(x_2+wd_2 >= x_1)&&(y_1+ht_1 >= y_2)&&(y_2+ht_2 >= y_1))
            return true;
        else
            return false;
    }
    
};


//int main()
//{
//     Rect r1(-2, -3, 2, 1);
//     Rect r2;
//     Rect r3(7);
//     r1.print_corner();
//     r1.print_sz();
//
//     int a2 = r2.area();
//     int p2 = r2.perimeter();
//        cout << a2 << " " << p2 << endl;
//
//     if (r1.intersect(r3))
//        cout << "YES" << endl;
//     else
//        cout << "NO" << endl;
//
//     if (r2.intersect(r3))
//        cout << "YES" << endl ;
//     else
//        cout << "NO" << endl;
//
//     return 0;
//}
