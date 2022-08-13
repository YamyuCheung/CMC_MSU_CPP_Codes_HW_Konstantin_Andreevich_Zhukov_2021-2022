//
//  F3.cpp
//  C++
//
//  Created by Xinyu Zhang on 03/05/2022.
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
using namespace std;
enum {H, A, B, C, D, E, S};
char c;
void gc(){
    c = cin.get();
}


int morse(){
    int counter = 0;
    int sum = 0;
    int digitcounter = 0;
    int CS = H;
    gc();
    do{
        switch (CS){
            case H:
                if(c == '-'){
                    CS = C;
                    gc();
                    counter = 1;
                    break;
                }else if(c == '.'){
                    CS = A;
                    gc();
                    counter = 1;
                    break;
                }else{
                    throw c;
                }
                break;
            case A:
                if(counter < 4){
                    if(c == '.'){
                        counter++;
                        gc();
                    }else if(c == '-'){
                        CS = B;
                        digitcounter=counter+1;
                        gc();
                    }else{
                        throw c;
                    }
                }else{
                    if(c == '.'){
                        CS = E;
                        sum = sum*10+5;
                        gc();
                    }else if(c == '-'){
                        CS = E;
                        sum = sum*10+4;
                        gc();
                    }
                }
                break;
            case B:
                if(digitcounter < 4){
                    if(c == '-'){
                        digitcounter++;
                        gc();
                        break;
                    }else{
                        throw c;
                    }
                }else{
                    if(c == '-'){
                        sum = sum*10+counter;
                        gc();
                        CS = E;
                    }else{
                        throw c;
                    }
                }
                break;
            case C:
                if(counter < 4){
                    if(c == '-'){
                        counter++;
                        gc();
                    }else if(c == '.'){
                        CS = D;
                        digitcounter = counter+1;
                        gc();
                    }else{
                        throw c;
                    }
                }else{
                    if(c == '-'){
                        CS = E;
                        sum = sum*10;
                        gc();
                    }else if(c == '.'){
                        CS = E;
                        gc();
                        sum = sum*10+9;
                    }
                }
                break;
            case D:
                if(digitcounter < 4){
                    if(c == '.'){
                        digitcounter++;
                        gc();
                        break;
                    }else{
                        throw c;
                    }
                }else{
                    if(c == '.'){
                        sum = sum*10+counter+5;
                        gc();
                        CS = E;
                    }else{
                        throw c;
                    }
                }
                break;
            case E:
                if(c == ' '){
                    counter = 0;
                    digitcounter = 0;
                    CS = H;
                    gc();
                }else if (c == '\n'){
                    CS = S;
                }else{
                    throw c;
                }
                break;
            case S:
                return sum;
            default:
                break;
        }
        
    }while(true);
}

int main(){
    try{
        cout << fixed << morse() << endl;
    }catch(char c){
        cerr << "Error in Lexeme: " << c << endl;
    }
}


