//
//  F2.cpp
//  C++
//
//  Created by Xinyu Zhang on 23/04/2022.
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
using namespace std;
enum {H, A, B, S};
char c;

void gc(){
    c = cin.get();
}

string Parser(){
    string str;
    int CS = H;
    gc();
    do{
        switch (CS) {
            case H:
                if(c == 'a'){
                    CS = A;
                    str = 'a';
                    gc();
                }else{
                    throw c;
                }
                break;
            case A:
                if(c == 'd'){
                    CS = A;
                    str += 'd';
                    gc();
                }else if(c == 'a'){
                    CS = B;
                    str += 'a';
                    gc();
                }else{
                    throw c;
                }
                break;
            case B:
                if (c == 'a'){
                    CS = A;
                    str += 'a';
                    gc();
                }else if(c == '\n'){
                    CS = S;
                }
                else{
                    throw c;
                }
                break;
            case S:
                return str;

            default:
                break;
        }
    }while(true);
}

int main(){
    try{
        string str;
        str = Parser();
        cout << fixed << str << endl;
    }catch(char c){
        cerr << "Error in Lexcem: " << c << endl;
    }
    return 0;
}

