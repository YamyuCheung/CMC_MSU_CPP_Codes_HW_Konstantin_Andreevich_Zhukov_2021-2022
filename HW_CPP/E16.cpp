//
//  E16.cpp
//  C++
//
//  Created by Xinyu Zhang on 11/03/2022.
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
//
#include <iostream>
#include <string>
using namespace std;


class Person{ //класс родитеоль базовый класс
    string firstname;
    string lastname;
    protected:
    int age;
    public:
    Person(const string& fn, const string& ln, int ag){
        firstname = fn;
        lastname = ln;
        age = ag;
//        cout << "Person_constr ";
    }
    virtual void Print() const;
    void Change_age(int new_age){
        age = new_age;
    }
    virtual ~Person(){
//        cout << "Person_destr ";
    }

}; //если в классе есть виртуальный метод, то всегда делаем виртуальный деструктор

void Person::Print() const{
    cout << "Name: " << firstname;
    cout << " LName: " << lastname;
    cout << " Age: " << age << endl;
}

class Student:public Person{ //класс Student наследует все поля классса person но и все методы
    float grade; //средний бал
    public:
    Student(const string& fname, const string& lname, int arg_age, float arg_gr):Person(fname, lname, arg_age){
        grade = arg_gr;
//        cout << "Student_constr ";
    }
    virtual void Print() const;
    void Change_grade(float new_grade){
        grade = new_grade;
    }
    bool Bonus() const;
    virtual ~Student(){
//        cout << "Student_destr ";
    }
};

void Student::Print() const{
    Person::Print();
    cout << "Grade: " << grade << endl;
}

bool Student::Bonus() const {
    if (age >= 18 && grade >= 4.5){
        return true;
    }else{
        return false;
    }
}

//class GoodStudent:public student{
//};

//void func(Person &pers){
//}

//int main(){
//    const int IMAX = 5;
//    Person *P[IMAX];
//
//
//    for(int i = 0; i < IMAX; i++){
//        if(i%2){
//            P[i] = new Person("PN", "PL", i+20);
//        }else{
//            P[i] = new Student("SN", "SL", i+15, i*1.2);
//        }
//    }
//    cout << endl;
//    for(int i = 0; i < IMAX; i++){
//        P[i] -> Print();
//    }
//    for (int i = 0; i < IMAX; i++){
//        delete P[i];
//    }
//    return 0;
//}

