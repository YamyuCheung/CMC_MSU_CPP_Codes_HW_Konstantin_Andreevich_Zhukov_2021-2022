//
//  E1.cpp
//  C++
//
//  Created by Xinyu Zhang on 12/02/2022.
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
//               佛祖保佑         永无BUG
//
//
//

#include <iostream>
using namespace std;
void count_symbols(const char *str){
    int i = 0, counter = 0;
    while(*(str+i) != '\0'){
        if(*(str+i) >= 'A' && *(str+i) <= 'Z' ) {
            counter++;
        }else if(  *(str+i) >= 'a' && *(str+i) <= 'z'  ){
            counter++;
        }else if( *(str+i) >= '0' && *(str+i) <= '9' ){
            counter++;
        }else if( *(str+i) == ' ' ){
            counter++;
        }else{
            counter++;
        }
            i++;
}
    printf("%d\n", counter);
}

void count_symbols(int arg){
    if (arg == 0){
        cout << arg << endl;
    }
    if (arg != 0){
        int num = 10, counter = 0;
        while (arg != 0){
            arg /= num;
            counter++;
        }
        printf("%d\n", counter);
    }
}
void count_symbols(double f, int n){
    int sum1 = 0, num = 10;
    if (f >= 1 || f <= -1){
        f /= num;
        sum1++;
    }
    printf("%d\n", sum1+n);
}
void count_symbols(double f){
    int sum = 0, num = 10;
    while (f >= 1){
        f /= num;
        sum++;
    }
    printf("%d\n", sum);
    
}
void count_symbols(int* arr, int n){
    int i=0, counter = 0, tmp;
    for(i = 0; i < n; i++){
        tmp = arr[i];
        while(tmp != 0){
            tmp /= 10;
            counter++;
        }
    }
    printf("%d\n", counter);
}
void count_symbols(int* ptr){
    int counter = 0, tmp = *ptr;
    while(tmp){
        tmp /= 10;
        counter++;
    }
    printf("%d\n", counter);
}

int main()
{
    int array[7] = {18, 20, 3, 493, 7};
    count_symbols("mather");
    count_symbols(12389);
    count_symbols(3.14, 3);
    count_symbols(2.71828);
    count_symbols(array, 5);
    count_symbols(array);
    return 0;
}
