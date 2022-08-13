//
//  F7.cpp
//  C++
//
//  Created by Xinyu Zhang on 11/05/2022.
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
#include <iostream>
#include <cstring>
using namespace std;

char c;
string str;
bool chk = false, chk2 = false;

void gc(){
    c = cin.get();
}

void S();
void A();

void S(){
    if(c == '0'){
        str = 'a';
        chk = true;
        gc();
        A();
    }else if(c == '1'){
        str = 'b';
        gc();
        A();
    }
    else throw c;
}

void A(){
    if(c == '0'){
        str += 'a';
        gc();
        A();
    }else if(c == '1'){
        gc();
        A();
        str += 'b';
    }else if(c == '\n'){
    }else{
        throw c;
    }
}

int main(){
    try{
        gc();
        S();
        for(int i = 0; i < str.length(); i++){
            if(str[i] == 'a'){
                cout << 'a';
            }
        }
        for(int i = 0; i < str.length(); i++){
            if(str[i] == 'b'){
                cout << 'b';
            }
        }
        cout << endl;
    }catch(char c){
        cerr << "Error in: " << c << endl;
    }
    return 0;
}


