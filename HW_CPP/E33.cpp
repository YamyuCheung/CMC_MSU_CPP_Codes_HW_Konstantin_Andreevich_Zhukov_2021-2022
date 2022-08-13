//
//  E33.cpp
//  C++
//
//  Created by Xinyu Zhang on 07/04/2022.
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
#include <vector>
#include <list>
using namespace std;

void irb(vector<vector<int>> &mtx, int length, int width, int *str, int index){
    if(index > length || index < 1){
        return;
    }
    mtx.push_back({});
    for(int i = 0; i < width; i++){
        mtx[length].push_back(0);
    }
    for(int i = length; i >= index; i--){
        for(int j = 0; j < width; j++){
            mtx[i][j] = mtx[i-1][j];
        }
    }
    for(int i = 0; i < width; i++){
        mtx[index-1][i] = str[i];
    }
}

void ira(vector<vector<int>> &mtx, int length, int width, int *str, int index){
    if(index > length || index < 1){
        return;
    }
    mtx.push_back({});
    for(int i = 0; i < width; i++){
        mtx[length].push_back(0);
    }
    for(int i = length; i > index; i--){
        for(int j = 0; j < width; j++){
            mtx[i][j] = mtx[i-1][j];
        }
    }
    for(int i = 0; i < width; i++){
        mtx[index][i] = str[i];
    }
    
}

void icb(vector<vector<int>> &mtx, int length, int width, int *str, int index){
    if(index > width || index < 1){
        return;
    }
    for(int i = 0; i < length; i++){
        mtx[i].push_back(0);
        for(int j = width; j >= index; j--){
            mtx[i][j] = mtx[i][j-1];
        }
    }
    for(int i = 0; i < length; i++){
        mtx[i][index-1] = str[i];
    }
}

void ica(vector<vector<int>> &mtx, int length, int width, int *str, int index){
    if(index > width || index < 1){
        return;
    }
    for(int i = 0; i < length; i++){
        mtx[i].push_back(0);
        for(int j = width; j > index; j--){
            mtx[i][j] = mtx[i][j-1];
        }
    }
    for(int i = 0; i < length; i++){
        mtx[i][index] = str[i];
    }
}

void dr(vector<vector<int>> &mtx, int length, int width, int index){
    if(index > length || index < 1){
        return;
    }
    for(int i = index-1; i < length-1; i++){
        for(int j = 0; j < width; j++){
            mtx[i][j] = mtx[i+1][j];
        }
    }
    mtx.pop_back();
}

void dc(vector<vector<int>> &mtx, int length, int width, int index){
    if(index > width || index < 1){
        return;
    }
    for(int i = 0; i < length; i++){
        for(int j = index-1; j < width-1; j++){
            mtx[i][j] = mtx[i][j+1];
        }
        mtx[i].pop_back();
    }
}

void sr(vector<vector<int>> &mtx, int length, int width, int index1, int index2){
    if(index1 < 0 || index1 > length || index2 < 0 || index2 > length || index1 == index2){
        return;
    }
    index1--;
    index2--;
    int str[width];
    for(int i = 0; i < width; i++){
        str[i] = mtx[index1][i];
    }
    for(int i = 0; i < width; i++){
        mtx[index1][i] = mtx[index2][i];
    }
    for(int i = 0; i < width; i++){
        mtx[index2][i] = str[i];
    }
}

void sc(vector<vector<int>> &mtx, int length, int width, int index1, int index2){
    if(index1 < 0 || index1 > width || index2 < 0 || index2 > width || index1 == index2){
        return;
    }
    index1--;
    index2--;
    int str[length];
    for(int i = 0; i < length; i++){
        str[i] = mtx[i][index1];
    }
    for(int i = 0; i < length; i++){
        mtx[i][index1] = mtx[i][index2];
    }
    for(int i = 0; i < length; i++){
        mtx[i][index2] = str[i];
    }
}

void t(vector<vector<int>> &mtx, int length, int width){
    vector<vector<int>> t;
    for(int i = 0; i < width; i++){
        t.push_back({});
        for(int j = 0; j < length; j++){
            t[i].push_back(0);
        }
    }
    for(int i = 0; i < length; i++){
        for(int j = 0; j < width; j++){
            t[j][i] = mtx[i][j];
        }
    }
    mtx.clear();
    int tmp = width;
    width = length;
    length = tmp;
    for(int i = 0; i < length; i++){
        mtx.push_back({});
        for(int j = 0; j < width; j++){
            mtx[i].push_back(t[i][j]);
        }
    }
    t.clear();

}




void print(vector<vector<int>> mtx){
    for(int i = 0; i < mtx.size(); i++){
        for(int j = 0; j < mtx[i].size(); j++){
            cout << mtx[i][j] << " ";
        }
        cout << endl;
    }

}

int main(int argc, const char* argv[]){
    int length = 0, width = 0, size, value;
    cin >> length;
    cin >> width;
    size = length*width;
    vector<vector<int>> mtx;
    for(int i = 0; i <length; i++){
        mtx.push_back({});
        for(int j = 0; j < width; j++){
            cin >> value;
            mtx[i].push_back(value);
        }
    }
    if(argc == 2){
        if(!strcmp(argv[1], "-t")){
            t(mtx, length, width);
        }
    }else if(argc == 3){
        if(!strcmp(argv[1], "-irb")){
            int str[width];
            for(int i = 0; i < width; i++){
                cin >> str[i];
            }
            irb(mtx, length, width, str, atoi(argv[2]));
        }else if(!strcmp(argv[1], "-ira")){
            int str[width];
            for(int i = 0; i < width; i++){
                cin >> str[i];
            }
            ira(mtx, length, width, str, atoi(argv[2]));
        }else if(!strcmp(argv[1], "-icb")){
            int str[length];
            for(int i = 0; i < length; i++){
                cin >> str[i];
            }
            icb(mtx, length, width, str, atoi(argv[2]));
        }else if(!strcmp(argv[1], "-ica")){
            int str[length];
            for(int i = 0; i < length; i++){
                cin >> str[i];
            }
            ica(mtx, length, width, str, atoi(argv[2]));
        }else if(!strcmp(argv[1], "-dr")){
            dr(mtx, length, width, atoi(argv[2]));
        }else if(!strcmp(argv[1], "-dc")){
            dc(mtx, length, width, atoi(argv[2]));
        }
    }else if(argc == 4){
        if(!strcmp(argv[1], "-sr")){
            sr(mtx, length, width, atoi(argv[2]), atoi(argv[3]));
        }else if(!strcmp(argv[1], "-sc")){
            sc(mtx, length, width, atoi(argv[2]), atoi(argv[3]));
        }
    }

    print(mtx);
    return 0;
}
