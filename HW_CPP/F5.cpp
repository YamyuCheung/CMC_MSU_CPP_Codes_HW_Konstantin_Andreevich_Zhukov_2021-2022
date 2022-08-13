//
//  F5.cpp
//  C++
//
//  Created by Xinyu Zhang on 12/05/2022.
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
using namespace std;

class Parser{
    char c;
    string str;
public:
    void gc(){
        c = cin.get();
        if(c != '\n'){
            str += c;
        }
    }
    Parser(){
        gc();
        S();
    }
    
    void S(){
        if(c == 'a'){
            A();
            B();
        }else if(c == 'b'){
            B();
        }
    }
    void A(){
        if(c == 'a'){
            gc();
            A();
        }else if(c == 'b'){
            gc();
        }
    }
    void B(){
        if(c == 'b'){
            gc();
            B();
        }
    }
    bool analyze(){
        unsigned long length = str.length();
        unsigned long counter = 0;
        if(length == 0){
            return false;
        }
        if(str[0] == 'a'){
            for(counter = 0; counter < length; counter++){
                if(str[counter] == 'b'){
                    break;
                }else if(str[counter] != 'a'){
                    return false;
                }
            }
            if(counter == length-1 && str[counter] != 'b'){
                return false;
            }else if(str[counter] == 'b'){
                return true;
            }else{
                for(; counter < length; counter++){
                    if(str[counter] != 'b'){
                        return false;
                    }
                }
            }
        }else if(str[0] == 'b'){
            for(counter = 0; counter < length; counter++){
                if(str[counter] != 'b'){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    
};

int main(){
    Parser p;
    if(p.analyze()){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}


