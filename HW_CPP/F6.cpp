//
//  F6.cpp
//  C++
//
//  Created by Xinyu Zhang on 06/05/2022.
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

char c;

void gc(){
  c = cin.get();
}

void S();
void A();

void S(){
  if(c == '0'){
    gc();
    S();
    cout << 'b';
  }else if(c == '1'){
    cout << 'a';
    gc();
    A();
  }else{
    throw c;
  }
}

void A(){
  if(c == '1'){
    cout << 'a';
    gc();
    A();
  }else if(c == '\n'){
  }else{
    throw c;
  }
}

int main(){
  try{
    gc();
    S();
    cout<< endl;
  }catch(char c){
    cerr << "Error in: " << c << endl;
  }
  return 0;
}