//
//  E17.cpp
//  C++
//
//  Created by Xinyu Zhang on 12/03/2022.
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
#include <string>

using namespace std;

class event{
    int year, month, day;
    string coursename;
public:
    event(const string& coursename, int year, int month, int day){
        this->coursename = coursename;
        this->year = year;
        this->month = month;
        this->day = day;
    }
    void change_date(int year, int month, int day){
        this->year = year;
        this->month = month;
        this->day = day;
    }
    virtual void print_res() const;
    virtual void change_grade(bool result){

    }
    virtual void change_grade(int grade){

    }
    virtual ~event(){

    }
};

class test:public event{
    bool result;
public:
    test(const string& coursename, int year, int month, int day, bool result):event(coursename, year, month, day){
        this->result = result;
    }
    virtual void print_res() const;
    virtual void change_grade(bool result){
        this->result = result;
    }
    virtual ~test(){

    }
};

class exam:public event{
    int grade;
public:
    exam(const string& coursename, int year, int month, int day, int grade):event(coursename, year, month, day){
        this->grade = grade;
    }
    virtual void print_res() const;
    virtual void change_grade(int grade){
        this->grade = grade;
    }
    virtual ~exam(){

    }
};

void event::print_res() const{
    cout << coursename << " " << year << " " << month << " " << day;
}
void test::print_res() const{
    event::print_res();
    cout << " " << boolalpha << result << endl;
}
void exam::print_res() const{
    event::print_res();
    cout << " Grade " << grade << endl;
}


int main()
{
        const int NUM =7;
        event *session[NUM];

        session[0]=new test("MS Office",2020,12,23,true);
        session[1]=new exam("Operation System",2021,1,15,2);
        session[2]=new test("Practicum",2020,12,25,false);
        session[3]=new exam("Differential equation",2021,1,20,3);
        session[4]=new test("Theory of probability",2020,12,29,true);
        session[5]=new exam("Philosophy",2021,1,24,5);
        session[6]=new exam("C++",2021,1,11,4);

        for (int i=0;i<NUM;i++)
                session[i]->print_res();

        session[2]->change_date(2021,2,24);
        session[2]->change_grade(true);

        session[1]->change_date(2021,2,13);
        session[1]->change_grade(3);

        cout<<endl;
        for (int i=0;i<NUM;i++)
                session[i]->print_res();

        for (int i=0;i<NUM;i++)
        delete session[i];
        return 0;
}
