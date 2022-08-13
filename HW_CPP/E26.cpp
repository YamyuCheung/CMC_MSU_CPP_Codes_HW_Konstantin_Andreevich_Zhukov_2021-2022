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

struct Pers{
  char name[20];
  int num_int;
  double num_double;
}; //swap только между полями num_int иnum_double
void Swap(int& a, int& b){
  int tmp = a;
  a = b;
  b = tmp;
}

template<typename T>
void Swap(T& a, T& b){
  T tmp = a;
  a = b;
  b = tmp;
}

template<> 
void Swap<Pers>(Pers &j1, Pers &j2){
  int tmp_i = j1.num_int;
  double tmp_d = j1.num_double;
  j1.num_int = j2.num_int;
  j1.num_double = j2.num_double;
  j2.num_int = tmp_i;
  j2.num_double = tmp_d;
}


template<typename T>
void Swap(T* a, T* b, int n){
  for (int i = 0; i < n; i++){
    T tmp = a[i];
    a[i] = b[i];
    b[i] = tmp;
  }
}

template<typename D>
void Print(D* a, int n){
  for (int i = 0; i < n; i++){
    cout << a[i] << " ";
  }
  cout << endl;
}

//int main(){
//  int i = 23, j = 86;
//  cout << "i = " << i << " j = " << j << endl;
//  Swap(i, j);
//  cout << "i = " << i << " j = " << j <<endl;
//  double x = 3.14, y = 2.7;
//  cout << "x = " << x << " y = " << y <<endl;
//  Swap(x, y);
//  cout << "x = " << x << " y = " << y <<endl;
//  double *a, *b;
//  a = new double[5]; b = new double[5];
//  for(i = 0; i < 5; i++){
//    a[i] = i+1;
//    b[i] = 10-i;
//  }
//  Print(a,5); Print(b, 5);
//  Swap(a, b);
//  Print(a,5); Print(b, 5);
//  delete [] a; delete [] b;
//  double aa[5] = {1.2, 2.3, 3.4, 4.5, 5.6};
//  double bb[5] = {6.7, 7.8, 8.9, 0.1, 3.8};
//  Print(aa, 5); Print(bb, 5);
//  Swap(aa, bb, 5);
//  Print(aa, 5); Print(bb, 5);
//  Pers p1 = {"Name1", 34, 3.14};
//  Pers p2 = {"Name2", 45, 2.7};
//  cout << "p1 = " << p1.name << " " <<p1.num_int << " " << p1.num_double << endl;
//  cout << "p2 = " << p2.name << " " << p2.num_int << " " << p2.num_double << endl;
//  Swap(p1, p2);
//  cout << "p1 = " << p1.name << " " << p1.num_int << " " << p1.num_double << endl;
//  cout << "p2 = " << p2.name << " " << p2.num_int << " " << p2.num_double << endl;
//
//  return 0;
//
//}
