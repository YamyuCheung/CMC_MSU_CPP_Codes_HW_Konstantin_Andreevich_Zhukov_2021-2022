//
//  E24.cpp
//  C++
//
//  Created by Xinyu Zhang on 26/03/2022.
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
#include <cstring>
using namespace std;

class Flower{
    static int counter, counter2;
    int tmp = 10;
    const char* flowername;
public:
    Flower(const char* arg_flowername, int arg_tmp):flowername(arg_flowername), tmp(arg_tmp){
        if (!strcmp(flowername, "white")){
            counter++;
        }else if(!strcmp(flowername, "pink")){
            counter2++;
        }else{
            createrule();
        }
    }
    Flower(const char* arg_flowername):flowername(arg_flowername){
        if (!strcmp(flowername, "white")){
            counter++;
        }else if(!strcmp(flowername, "pink")){
            counter2++;
        }else{
            createrule();
        }
    }
    Flower(int arg_tmp):tmp(arg_tmp){
        createrule();
    }
    Flower(){
        createrule();
    }
    void createrule(){
        if (counter < counter2){
            flowername = "white";
            counter++;
        }else if (counter > counter2){
            flowername = "pink";
            counter2++;
        }else if (tmp%2 == 0){
            flowername = "pink";
            counter2++;
        }else if (tmp%2 != 0){
            flowername = "white";
            counter++;
        }
    }
    static void Print_flowers(){
        cout << "White: " << counter << " Pink: " << counter2 << endl;
    }
    ~Flower(){
        if (!strcmp(flowername, "white")){
            counter--;
        }else{
            counter2--;
        }
    }

};

int Flower::counter = 0;
int Flower::counter2 = 0;


int main(){
    Flower fl1("white");
    Flower fl2("pink", 5);
    Flower fl3("white", 7);
    Flower::Print_flowers();
    Flower fl4("green");
    Flower::Print_flowers();
    Flower fl5("blue", 17);
    Flower::Print_flowers();
    Flower fl6;
    Flower::Print_flowers();
    Flower fl7;
    Flower::Print_flowers();
    return 0;
}
