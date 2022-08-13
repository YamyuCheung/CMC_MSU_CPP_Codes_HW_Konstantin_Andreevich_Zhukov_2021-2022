//
//  E25.cpp
//  C++
//
//  Created by Xinyu Zhang on 27/03/2022.
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
//
//
#include <iostream>
#include <cstring>
using namespace std;

class Exception{
    string errinf, teaminf;
public:
    Exception(const char* arg_errinf, const char* arg_teaminf):errinf(arg_errinf),teaminf(arg_teaminf){
    }
    Exception(const Exception& other){
        errinf = other.errinf;
        teaminf = other.teaminf;
    }
    ~Exception(){
    }
    string GetErrinf() const{
        return errinf;
    }
    string GerTeaminf() const{
        return teaminf;
    }
};

class OtherException:public Exception{
    int index;
    string errinf;
    string teaminf;
public:
    OtherException(const char* arg_errinf, const char* arg_teaminf, int arg): Exception(arg_errinf, arg_teaminf){
        index = arg;
    }
    int get_index() const{
        return index;
    }
    OtherException(const OtherException& other):Exception(other){
        index = other.index;
    }
    ~OtherException(){
    }
};


class Player{
    const char* teamname;
    int playernumber;
    static int zenit[11], cska[11], maxzenit, maxcska;
public:
    Player(const char* arg_teamname, int arg_playernumber):teamname(arg_teamname), playernumber(arg_playernumber){
        if(!strcmp(teamname, "Zenit")){
            if (playernumber < 1){
                throw OtherException("Wrong number", "Zenit", playernumber);
            }
            if (maxzenit == 11){
                throw Exception("Too many players", "Zenit");
            }
            for(int i = 0; i < 11; i++){
                if(zenit[i] == playernumber){
                    throw OtherException("Double number", "Zenit", playernumber);
                }
            }
            for(int i = 0; i < 11; i++){
                if(zenit[i] == 0){
                    zenit[i] = playernumber;
                    break;
                }
            }
            maxzenit++;
        }else if (!strcmp(teamname, "CSKA")){
            if (playernumber < 1){
                throw OtherException("Wrong number", "CSKA", playernumber);
            }
            if (maxcska == 11){
                throw Exception("Too many players", "CSKA");
            }
            for(int i = 0; i < 11; i++){
                if(cska[i] == playernumber){
                    throw OtherException("Double number", "CSKA", playernumber);
                }
            }
            for(int i = 0; i < 11; i++){
                if (cska[i] == 0){
                    cska[i] = playernumber;
                    break;
                }
            }
            maxcska++;
        }else{
            throw Exception("Wrong name", teamname);
        }
    }
    void Print(){
        if(!strcmp(teamname, "Zenit")){
            cout << teamname << " " << playernumber << endl;
        }else{
            cout << teamname << " " << playernumber << endl;
        }
    }
    static void Print_teams(){
        if (maxzenit != 0){
            cout << "Zenit:";
            for(int i = 0; i < 11; i++){
                if(zenit[i] != 0){
                    cout << " " << zenit[i];
                }
            }
            cout << endl;
        }
        if (maxcska != 0){
            cout << "CSKA:";
            for(int i = 0; i < 11; i++){
                if(cska[i] != 0){
                    cout << " " << cska[i];
                }
            }
            cout << endl;
        }
    }
    ~Player(){
        if (!strcmp(teamname, "Zenit")){
            for(int i = 0; i < 11; i++){
                if (playernumber == zenit[i]){
                    zenit[i] = 0;
                    break;
                }
            }
            maxzenit--;
        }else{
            for(int i = 0; i < 11; i++){
                if (playernumber == cska[i]){
                    cska[i] = 0;
                    break;
                }
            }
            maxcska--;
        }
    }

};
int Player::zenit[11] = {0};
int Player::cska[11] = {0};
int Player::maxzenit = 0;
int Player::maxcska = 0;
//void Players()
//{
//    Player p10("AAA", 2);
//    Player pl("CSKA", 1);
//    Player p2("CSKA", 2);
//    Player p3("CSKA", 3);
//    Player p4("CSKA", 4);
//    Player p5("CSKA", 5);
//    Player p6("CSKA", 6);
//    Player p7("CSKA", 7);
//    Player p8("CSKA", 8);
//    Player p9("CSKA", 9);
//    Player pl0("CSKA", 10);
//    Player pl1("CSKA", 11);
//    Player pl2("CSKA", 12);
//
//        Player::Print_teams();
//}

int main(){
    try{
        Players();
    }catch (OtherException &ex){
        cerr << "Exception: " << ex.GetErrinf() << " in team " << ex.GerTeaminf()<< " Error number: " << ex.get_index() << endl;
    }catch(Exception &ex){
        cerr << "Exception: " << ex.GetErrinf() << " in team " << ex.GerTeaminf() << endl;
    }

    return 0;
}

