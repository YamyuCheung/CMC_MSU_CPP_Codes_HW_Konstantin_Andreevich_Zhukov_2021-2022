//
//  E15.cpp
//  C++
//
//  Created by Xinyu Zhang on 15/03/2022.
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
#include<iostream>
#include<cstring>
using namespace std;

class Exception_err_in1{
    string errstr;
    int index1;
public:
    Exception_err_in1(int arg1){
        errstr = "Exception: problem in insert incorrect parameter:" ;
        index1 = arg1;
    }
    const int get_index1(){
        return this->index1;
    }
    const string get_errstr(){
        return this->errstr;
    }
};

class Exception_err_del1{
    string errstr;
    int index1, index2;
public:
    Exception_err_del1(int arg1, int arg2){
        errstr = "Exception: problem in del incorrect parameter:" ;
        index1 = arg1;
        index2 = arg2;
    }
    const int get_index1(){
        return this->index1;    
    }
    const int get_index2(){
        return this->index2;
    }
    const string get_errstr(){
        return this->errstr;
    }
};
class Exception_err_del2{
    string errstr;
    int index1;
public:
    Exception_err_del2(int arg1){
        errstr = "Exception: problem in del incorrect parameter:" ;
        index1 = arg1;
    }
    const int get_index1(){
        return this->index1;
    }
    const string get_errstr(){
        return this->errstr;
    }
};

class mstring{
    private:
        char* m_str;
        unsigned int m_length;
    public:
        mstring():m_length(0){
            m_str = new char[m_length+1];
            m_str[0] = '\0';
        }
        mstring(const mstring & str){
            m_length = str.m_length;
            m_str = new char[m_length+1];
            strcpy(m_str, str.m_str);
        }
        mstring(const char* str){
            m_length = strlen(str);
            m_str = new char[m_length+1];
            strcpy(m_str, str);
        }
        ~mstring(){
            delete[] m_str;
        }
        int length(){
            return m_length;
        }
        bool isempty(){
            if(m_length == 0)
                return true;
            else
                return false;
        }
        void add(char c){
            char *str = new char[m_length+2];
            strcpy(str, m_str);
            str[m_length] = c;
            str[m_length+1] = '\0';
            delete[] m_str;
            m_str = str;
            ++m_length;
        }
        
        void add(const char* c){
            int c_length = strlen(c);
            char *str = new char[m_length+c_length+1];
            strcpy(str, m_str);
            strcpy(str+m_length, c);
            //str[m_length+c_length] = '\0';
            delete[] m_str;
            m_str = str;
            m_length += c_length;
        }
        void insert(char c,int i){
            if (i > m_length || i < 0){
                throw Exception_err_in1(i);
            }
            char *str  = new char[m_length+2];
            strcpy(str, m_str);
            char *str2 = new char[m_length-i+1];
            strcpy(str2, str+i);
            str[i] = c;
            strcpy(str+i+1, str2);
            delete[] str2;
            delete[] m_str;
            m_str = str;
            ++m_length;
        }
        void insert(const char* c,int i){
            if (i > m_length || i < 0){
                throw Exception_err_in1(i);
            }
            int c_length = strlen(c);
            char *str  = new char[m_length+c_length+1];
            strcpy(str, m_str);
            char *str2 = new char[m_length-i+1];
            strcpy(str2, str+i);
            strcpy(str+i, c);
            strcpy(str+i+c_length, str2);
            delete[] str2;
            delete[] m_str;
            m_str = str;
            m_length += c_length;
        }
        void del(int i){
            if (i >= m_length || i < 0){
                throw Exception_err_del2(i);
            }
            char *str  = new char[m_length];
            char *str2 = new char[m_length-i];
            strcpy(str2, m_str+i+1);
            strcpy(m_str+i, str2);
            strcpy(str, m_str);
            delete[] str2;
            delete[] m_str;
            m_str = str;
            --m_length;
        }
        
        void del(int i, int j){
            if (i > j){
                throw Exception_err_del1(i,j);
            }
            if (i < 0 || i >= m_length){
                throw Exception_err_del1(i,j);
            }
            if (j < 0 || j >= m_length){
                throw Exception_err_del1(i,j);
            }
            int c_length = j-i+1;
            char *str  = new char[m_length+1-c_length];
            char *str2 = new char[m_length-j];
            strcpy(str2, m_str+j+1);
            strcpy(m_str+i, str2);
            strcpy(str, m_str);
            delete[] str2;
            delete[] m_str;
            m_str = str;
            m_length -= c_length;
        }
        
        int search(const char* str){
            if(strlen(str) == 0)
                return -1;
            int i=0, j=0, check=1;
            for(; i<m_length; ++i)
            {
                while(str[j]!='\0')
                {
                    if(m_str[i+j]=='\0')
                        return -1;
                    if(str[j] == m_str[i+j])
                    {
                        j++;
                    }
                    else
                    {
                        check = 0;
                        break;
                    }
                }
                if(check)
                    return i;
                j = 0;
                check = 1;
            }
        return -1;
        }
        
        void print(){
            printf("%s\n", m_str);
        }
    friend ostream& operator<<(ostream &os, const mstring &op);
};
ostream& operator<<(ostream& os, const mstring& op){
    if (op.m_length >= 1){
        os << op.m_str << endl;
    }
    return os;
}


void error()
{
        mstring s ("hello world");
        mstring s1 = s;
        mstring s2;
        if (!s1.isempty())
        {
           s1.insert(' ', 5);
           s1.insert('m',6);
           s1.insert('y',7);
           s.insert(" my",5);
           s.print();
           s1.print();
        }
        s.del(0,13);
        cout << s << s1 << s2 << endl;

}
//void error()
//{
//        mstring s ("hello world");
//        mstring s1 = s;
//        mstring s2;
//        if (!s1.isempty())
//        {
//           s1.insert(' ', 12);
//           s1.insert('m',6);
//           s1.insert('y',7);
//           s.insert(" my",5);
//           s.print();
//           s1.print();
//        }
//        s.del(9);
//        s1.del(-5,7);
//        s.print();
//        s1.print();
//}

int main(){
    try{
        error();
    }catch(Exception_err_in1& ex){
        cerr << ex.get_errstr() << ex.get_index1() << endl;
    }catch(Exception_err_del1& ex){
        cerr << ex.get_errstr() << ex.get_index1() << " " << ex.get_index2() << endl;
    }catch(Exception_err_del2& ex){
        cerr << ex.get_errstr() << ex.get_index1() << endl;
    }

    return 0;
}
//int main()
//{
//        mstring s ("hello");
//        mstring s1 = s;
//        mstring s2;
//        cout << s.length() << endl;
//        if (s2.isempty())
//        {
//          s.add('!');
//          s2.add("HI!");
//          s.print();
//          s2.print();
//        }
//        if (!s1.isempty())
//        {
//           s1.insert(' ',5);
//           s1.insert('m',6);
//           s1.insert('y',7);
//           s.insert(" my",5);
//           s.print();
//           s1.print();
//        }
//        s.del(9);
//        s1.del(5,7);
//        s.print();
//        s1.print();
//        cout << s.search("my") << endl;
//        cout << s2.search("my") << endl;
//        return 0;
//}
