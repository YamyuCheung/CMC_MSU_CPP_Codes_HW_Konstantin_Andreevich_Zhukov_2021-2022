//
//  E27.cpp
//  C++
//
//  Created by Xinyu Zhang on 25/03/2022.
//
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
template<typename T>
T maxn(T *arr, int n){
    T maxvalue = arr[0];
    for(int i = 0; i < n; i++){
        if (maxvalue < arr[i]){
            maxvalue = arr[i];
        }
    }
    return maxvalue;
}

template<>
const char* maxn(const char* arr[], int n){
    const char* maxvalue = arr[0];
    for(int i = 0; i < n; i++){
        if(strlen(maxvalue) < strlen(arr[i])){
            maxvalue = arr[i];
        }
    }
    return maxvalue;
}

//int main()
//{
//    using namespace std;
//    int arri[6] = {1, 2, 5, 3, 1, -1};
//    double arrd[4] = {2.3, -1.3, 8.7, 4.5};
//    const char * arrc[5] = {"first", "second", "third", "long string", "another string"};
//
//    cout << "max of integer = " << maxn(arri, 6) << endl;
//    cout << "max of double = " << maxn(arrd, 4) << endl;
//    cout << "max string is " << maxn(arrc, 5) << endl;
//
//    return 0;
//}
