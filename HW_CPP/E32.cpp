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
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iterator>
using namespace std;
void print(const int arg){
    cout << arg << " ";
}

bool chk(list<int>& li, list<int>::iterator &pl, int num){
    for(pl = li.begin(); pl != li.end(); pl++){
        if(num == *pl){
            return true;
        }
    }
    return false;
}

int get_maxvalue(list<int> &li, list<int>::iterator &pl){
    int maxvalue;
    pl = li.begin();
    maxvalue = *pl;
    for(pl = li.begin(); pl != li.end(); pl++){
        if(maxvalue < *pl){
            maxvalue = *pl;
        }
    }
    return maxvalue;
}

void mf(list<int> &li, list<int>::iterator &pl){
    int maxvalue = get_maxvalue(li, pl);
    for(pl = li.begin(); pl != li.end(); pl++){
        if(*pl == maxvalue){
            break;
        }
    }
    li.erase(pl);
    li.push_front(maxvalue);
}
void me(list<int> &li, list<int>::iterator &pl){
    int maxvalue = get_maxvalue(li, pl);
    for(pl = li.begin(); pl != li.end(); pl++){
        if(*pl == maxvalue){
            break;
        }
    }
    li.erase(pl);
    li.push_back(maxvalue);
}


int main(int argc, const char* argv[]){
  list<int> li;
  int arg = 0, ss, ss2;
  auto pl = li.begin();
  while(cin.peek() != '\n'){
      ss = cin.get();
      ss2 = cin.peek();
      cin.putback(ss);
      if(ss == ' ' && ss2 == '\n'){
          break;
      }
    cin >> arg;
    li.push_back(arg);
  }
    if(argc == 2){
        if(!strcmp(argv[1], "-sa")){
            li.sort();
        }else if(!strcmp(argv[1], "-sd")){
            li.sort();
            li.reverse();
        }else if(!strcmp(argv[1], "-mf")){
            mf(li, pl);
        }else if(!strcmp(argv[1], "-me")){
            me(li, pl);
        }
    }else if(argc == 3){
        if(!strcmp(argv[1], "-ae")){
            li.push_back(atoi(argv[2]));
        }else if(!strcmp(argv[1], "-af")){
            li.push_front(atoi(argv[2]));
        }else if(!strcmp(argv[1], "-d")){
            if(chk(li, pl, atoi(argv[2]))){
                li.erase(pl);
            }
        }
    }else if(argc == 4){
        if(!strcmp(argv[1], "-ib")){
            if(chk(li, pl, atoi(argv[3]))){
                li.insert(pl, atoi(argv[2]));
            }
        }else if(!strcmp(argv[1], "-ia")){
            if(chk(li, pl, atoi(argv[3]))){
                li.insert(++pl, atoi(argv[2]));
            }
        }
    }

    for_each(li.begin(), li.end(), print);
    cout << endl;

  return 0;
}
