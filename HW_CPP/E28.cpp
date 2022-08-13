#include <iostream>
#include <cmath>
using namespace std;

template<class T>
class Vector_2d{
  T x, y;
  public:
  Vector_2d(T arg_x = 0, T arg_y = 0): x(arg_x), y(arg_y){

  }
  void print() const;
  T max_norm() const{
    return abs(x) > abs(y) ? abs(x) : abs(y);
  }
  Vector_2d<T>& operator=(const Vector_2d<T>& op);
  const Vector_2d<T> operator*(T a){
    return Vector_2d<T>(a*x, a*y);
  }
  template<class V>
  friend const Vector_2d<V> operator+(const Vector_2d<V>& op1, const Vector_2d<V>& op2);
};

template<class Type>
void Vector_2d<Type>::print() const{
  cout << "(" << x << "," << y << ")" << endl;
}

template<class T>
Vector_2d<T>& Vector_2d<T>::operator=(const Vector_2d<T>& op){
  x = op.x;
  y = op.y;
  return *this;
}
template<class V>
const Vector_2d<V> operator+(const Vector_2d<V>& op1, const Vector_2d<V>& op2){
  Vector_2d<V> tmp;
  tmp.x = op1.x + op2.x;
  tmp.y = op1.y + op2.y;
  return tmp;
}

//int main(){
//  Vector_2d<int> vi(2,3), ui, wi;
//  vi.print();
//  cout << "max_norm = " << vi.max_norm() << endl;
//  ui = vi * 3;
//  ui.print();
//  wi = vi+ui;
//  wi.print();
//  Vector_2d<double> vd(-3.14, 2.7), ud, wd;
//  vd.print();
//  cout << "max_norm = " << vd.max_norm() << endl;
//  ud = vd* 1.1;
//  ud.print();
//  wd = vd+ud;
//  wd.print();
//  return 0;
//}
