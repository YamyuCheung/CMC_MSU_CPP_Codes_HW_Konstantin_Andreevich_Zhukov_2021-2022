//
//  E20.cpp
//  C++
//
//  Created by Xinyu Zhang on 12/04/2022.
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

class Parser{
protected:
    int start_index[2];
    int end_index[2];
public:
    int chg_x(char arg_x){
        return arg_x >= 'a' && arg_x <= 'h' ? arg_x - 60 : -1;
    }
    int chg_y(char arg_y){
        switch (arg_y) {
            case '1':
                return 1;
            case '2':
                return 2;
            case '3':
                return 3;
            case '4':
                return 4;
            case '5':
                return 5;
            case '6':
                return 6;
            case '7':
                return 7;
            case '8':
                return 8;
            default:
                return -1;
                break;
        }
    }
};
class Figure{
public:
    virtual bool chk(int arg_start_x, int arg_start_y, int arg_end_x, int arg_end_y) const = 0;
    virtual ~Figure() {}
};


class King : public Figure {
public:
    virtual bool chk(int arg_start_x, int arg_start_y, int arg_end_x, int arg_end_y) const{
        if(arg_start_x <= 0 || arg_end_x <= 0 || arg_start_y <= 0 || arg_end_y <= 0){
            return false;
        }else{
            if((abs(arg_start_x-arg_end_x) <= 1) && (abs(arg_start_y-arg_end_y)) <= 1){
                return true;
            }else{
                return false;
            }
        }
        return false;
    }
};

class Queen : public Figure{
public:
    virtual bool chk(int arg_start_x, int arg_start_y, int arg_end_x, int arg_end_y) const{
    if(arg_start_x <= 0 || arg_end_x <= 0 || arg_start_y <= 0 || arg_end_y <= 0){
        return false;
    }else{
        if((arg_start_x == arg_end_x) || (arg_start_y == arg_end_y) || (abs(arg_start_x-arg_end_x) == abs(arg_start_y-arg_end_y))){
            return true;
        }else{
            return false;
        }
    }
    return false;
    }
};

class Knight:public Figure{
public:
    virtual bool chk(int arg_start_x, int arg_start_y, int arg_end_x, int arg_end_y) const{
        if(arg_start_x <= 0 || arg_end_x <= 0 || arg_start_y <= 0 || arg_end_y <= 0){
            return false;
        }else{
            if ((abs(arg_start_x-arg_end_x)==1 && abs(arg_start_y-arg_end_y) == 2) || (abs(arg_start_x-arg_end_x)==2 && abs(arg_start_y-arg_end_y) == 1)){
                return true;
            }else{
                return false;
            }
        }
        return false;
    }
};

class Bishop:public Figure{
public:
    virtual bool chk(int arg_start_x, int arg_start_y, int arg_end_x, int arg_end_y) const{
        if(arg_start_x <= 0 || arg_end_x <= 0 || arg_start_y <= 0 || arg_end_y <= 0){
            return false;
        }else{
            if (abs(arg_start_x-arg_end_x) == abs(arg_start_y-arg_end_y)){
                return true;
            }else{
                return false;
            }
        }
        return false;
    }
};

class Rook: public Figure{
public:
    virtual bool chk(int arg_start_x, int arg_start_y, int arg_end_x, int arg_end_y) const{
        if(arg_start_x <= 0 || arg_end_x <= 0 || arg_start_y <= 0 || arg_end_y <= 0){
            return false;
        }else{
            if((arg_start_x==arg_end_x) || (arg_start_y==arg_end_y)){
                return true;
            }else{
                return false;
            }
        }
        return false;
    }
};



class ChessChecker : private Parser {
    char name;
    char start[2];
    char end[2];
    Figure *figureName;
public:
    ChessChecker(): figureName(nullptr) {
    }
    void setup(){
        cin >> name >> start >> end;
        start_index[0] = Parser::chg_x(start[0]);
        start_index[1] = Parser::chg_y(start[1]);
        end_index[0] = Parser::chg_x(end[0]);
        end_index[1] = Parser::chg_y(end[1]);
    switch(name){
        case 'K': figureName = new King; break;
        case 'Q': figureName = new Queen; break;
        case 'N': figureName = new Knight; break;
        case 'B': figureName = new Bishop; break;
        case 'R': figureName = new Rook; break;
        default:
            cout << "NO" << endl;
            return;
            break;
    }
        if(figureName->chk(start_index[0], start_index[1], end_index[0], end_index[1])){
        cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    ~ChessChecker() { delete figureName; }
};


int main(){
    ChessChecker prog1;
    prog1.setup();

    return 0;
}

