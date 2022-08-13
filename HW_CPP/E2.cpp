//
//  E2.cpp
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
#include<math.h>
#include <cstring>
using namespace std;
char* right(char* str, int N){
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
    if (N > counter){
        N = counter;
    }
    else if (N <= 0){
        *str = NULL;
    }
    str = str+(counter-N);
    return str;
}
//unsigned long right(unsigned long num, int N){
//    int *savedigit = NULL, counter, calcdigit = 0;
//    unsigned long tmp;
//    tmp = num;
//    while (tmp){
//        tmp /= 10;
//        calcdigit++;
//    }
//    if (calcdigit < N){
//        N = calcdigit;
//    }
//    if (N <= 0){
//        return 0;
//    }
//    savedigit = (int*)malloc(N*sizeof(int));
//    if (NULL == savedigit){
//        cout << "Program failed to allocate memory." << endl;
//        exit(1);
//    }
//    for(counter = 0; counter < N; counter++){
//        savedigit[counter] = num%10;
//        num /= 10;
//    }
//    num = 0;
//    for(counter = 0; counter < N; counter++){
//        num = savedigit[counter]*pow(10, counter) + num;
//    }
//    free(savedigit);
//    savedigit = NULL;
//
//    return num;
//}
unsigned long right(unsigned long num, int N) {
 if(N < 1)
  return 0;
 unsigned long s = 1;
 for(int i=0; i<N; i++) {
  s*=10;
 }
 num%=s;
 return num;
}


int main(){
    char str[100], str1[100];
    int N;
    unsigned long N2 = 0;
    cin.getline(str, 99);
    char str_1[] = "string";
    char str_2[] = "number";
    if (strcmp(str, str_1) == 0){
        cin.getline(str1, 99);
        cin >> N;
        cout << right(str1, N) << endl;
    }
    else if (strcmp(str, str_2) == 0){
        cin >> N2;
        cin >> N;
        cout << right(N2, N) << endl;
    }
    else{
        return -1;
    }
    return 0;
}
