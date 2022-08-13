//
//  E30.cpp
//  C++
//
//  Created by Xinyu Zhang on 03/04/2022.
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

template <class T>
class Set{
    int n;
    T *ptr;
public:
    Set<T>(T *ptr = nullptr, int n = 0);
    void add(T elem);
    void add(T* ptr, int n);
    void del(T elem);

    void print();
    bool in(T num);
    template<class T2>friend const Set<T2> operator*(const Set<T2>& op1, const Set<T2>& op2);
    Set<T> operator+(const Set<T>& op);

    ~Set(){
        delete [] ptr;
    }
};

template<class T>
bool Set<T>::in(T num){
    for(int i = 0; i < n; i++){
        if(this->ptr[i] == num){
            return true;
        }
    }
    return false;
}


template<class T>Set<T>::Set(T *ptr, int n){
    T *tmp, *tmp2;
    int tmp2n;
    bool chk = true;
    int tmpn = n, tmpi = 0, tmpi2 = 0;
    tmp = new T[n];
    tmp2n = n;
    tmp2 = new T[n];
    for(int i = 0; i < n; i++){
        tmp2[i] = ptr[i];
    }
    for(int i = 0; i < n; i++){
        tmp[i] = 0;
    }
    for(int i = 0; i < n; i++){
        for(int j =0; j < tmpi; j++){
            if(tmp2[i] == tmp[j]){
                tmp2n--;
                chk = false;
            }
        }
        if(chk == true){
            tmp[tmpi2] = this->ptr[i];
            tmpi2++;
        }
        tmpi++;
        chk = true;
    }

    this->n = tmpn;
    this->ptr = new T[this->n];
    for(int i = 0; i < this->n; i++){
        this->ptr[i] = tmp2[i];
    }
    delete [] tmp2;
    delete [] tmp;

}

template<class T>void Set<T>::add(T elem){
    T *tmp;
    bool chk = true;
    for(int i = 0; i < this->n; i++){
        if(this->ptr[i] == elem){
            chk = false;
            break;
        }
    }
    if(chk == true){
        if (this->n == 0){
            this->n = 1;
            this->ptr = new T[n];
            this->ptr[0] = elem;
        }else{
            tmp = new T[this->n+1];
            for(int i = 0; i < this->n; i++){
                tmp[i] = this->ptr[i];
            }
            tmp[this->n] = elem;
            this->ptr = new T[this->n+1];
            for(int i = 0; i < this->n+1; i++){
                this->ptr[i] = tmp[i];
            }
            this->n++;
            delete [] tmp;
        }
    }
}

template<class T>void Set<T>::add(T *ptr, int n){
    T *tmp2;
    int tmpn = 0, sizetmp2, chgj = 0;
    bool chk = true;
    if (this->n == 0){
        this->ptr = new T[n];
        this->n = n;
        for(int i = 0; i < n; i++){
            this->ptr[i] = ptr[i];
        }
    }else{
        tmpn = this->n+n;
        for(int i = 0; i < this->n; i++){
            for(int j = 0; j < n; j++){
                if(this->ptr[i] == ptr[j]){
                    tmpn--;
                }
            }
        }
        tmp2 = new T[this->n];
        sizetmp2 = this->n;
        for(int i = 0; i < this->n; i++){
            tmp2[i] = this->ptr[i];
        }
        this->n = tmpn;
        this->ptr = new T[n];
        for(int i = 0; i < sizetmp2; i++){
            this->ptr[i] = tmp2[i];
        }
        delete [] tmp2;
        int i = sizetmp2;
        for(int j = chgj; j < n; j++){
            for(int k = 0; k < sizetmp2; k++){
                if(this->ptr[k] == ptr[j]){
                    chk = false;
                }
            }
            if (chk == true){
                this->ptr[i] = ptr[j];
                if (i < this->n){
                    i++;
                }
                chgj = j+1;
            }
            chk = true;
        }


    }
}

template<class T>void Set<T>::del(T elem){
    T *tmp;
    bool chk = false;
    int j = 0;
    for(int i = 0; i < n; i++){
        if(this->ptr[i] == elem){
            chk = true;
        }
    }
    if (chk == true){
        int tmpn = this->n-1;
        tmp = new T[tmpn];
        for(int i = 0; i < this->n; i++){
            if(this->ptr[i] != elem){
                tmp[j] = ptr[i];
                j++;
            }
        }
        this->ptr = new T[tmpn];
        this->n = tmpn;
        for(int i = 0; i < this->n; i++){
            this->ptr[i] = tmp[i];
        }
        delete [] tmp;
    }
}

template<class T>void Set<T>::print(){
    T tmp;
    if(n == 0){
        cout << endl;
    }else{
        for(int i = 0; i < n - 1; i++){ //冒泡排序
            for(int j = 0; j < n - 1 - i; j++){
                if(this->ptr[j] > this->ptr[j+1]){
                    tmp = this->ptr[j+1];
                    this->ptr[j+1] = this->ptr[j];
                    this->ptr[j] = tmp;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if (i+1 < n){
                cout << ptr[i] << " ";
            }else{
                cout << ptr[i] << endl;
            }
        }
    }
}



template<class T>const Set<T> operator*(const Set<T>& op1, const Set<T>& op2){
    Set<T> tmp;
    tmp.n = 0;
    int tmpi = 0;
    for(int i = 0; i < op1.n; i++){
        for(int j = 0; j < op2.n; j++){
            if(op2.ptr[j] == op1.ptr[i]){
                tmp.n++;
            }
        }
    }
    tmp.ptr = new T[tmp.n];
    for(int i = 0; i < op1.n; i++){
        for(int j = 0; j < op2.n; j++){
            if(op2.ptr[j] == op1.ptr[i]){
                tmp.ptr[tmpi] = op1.ptr[i];
                tmpi++;
            }
        }
    }
    return tmp;
}

template<class T>Set<T> Set<T>::operator+(const Set<T>& op){
    Set<T> tmp;
    tmp.n = op.n;
    tmp.ptr = new T[tmp.n];
    for(int i = 0; i < tmp.n; i++){
        tmp.ptr[i] = op.ptr[i];
    }
    for(int i = 0; i < n; i++){
        if(!tmp.in(ptr[i])){
            tmp.add(ptr[i]);
        }
    }
    return tmp;
}



int main()
{
        int a[] = { 1,2,3,4,5 };
        int b[] = { 3,2,6};
        Set <int> seti1(a,5),seti2,seti3,seti4;
        seti2.add(b, 3);
        seti1.print();
        seti2.print();
        seti3 = seti1*seti2;
        cout << "Intersect: ";
        seti3.print();
        seti4 = seti1 + seti2;
        cout << "Union: ";
        seti4.print();
        seti3.add(7);
        seti4.del(3);
        seti3.print();
        seti4.print();
        return 0;
}
