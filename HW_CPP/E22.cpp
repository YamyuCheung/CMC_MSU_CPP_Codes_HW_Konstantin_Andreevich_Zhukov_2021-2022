//
//  E22.cpp
//  C++
//
//  Created by Xinyu Zhang on 18/03/2022.
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
//
#include<iostream>
#include<fstream>
#include<cstring>
#include<cerrno>
using namespace std;

class Exception{
    string comment;
public:
    Exception(const char* arg_com) : comment(arg_com){}
    Exception(const Exception& other) {comment = other.comment;}
    ~Exception() {}
    string GetComment() const{return comment;};
};

class FileException : public Exception{
    char *filename;
    char *strdup(const char * str);
public:
    FileException(const char* arg_file, const char* arg_com): Exception(arg_com){
        filename = strdup(arg_file);
    }
    FileException(const FileException& other) : Exception(other){
        filename = strdup(other.filename);
    }
    char* GetFilename() const{return filename;}
    ~FileException(){delete[] filename;}
};

char* FileException::strdup(const char* str){
    char* res = new char[strlen(str)+1];
    strcpy(res, str);
    return res;
}

class FileErrCodeException: public FileException{
    int err_code;
public:
    FileErrCodeException(const char* arg_file, const char* arg_com): FileException(arg_file, arg_com){
        err_code = errno;
    }
    FileErrCodeException(const FileErrCodeException& other): FileException(other){
        err_code = other.err_code;
    }
    int GetErrCode() const{
        return err_code;
    }
};


int count_symbols(const char* filename) {
    ifstream fin(filename); //ß‡ß“ßÓß”ß›ßﬂß⁄ß÷ ß⁄ ß‡ß‰ß‹ß‚ßÌß‰ß⁄ß÷ ßÊß—ß€ß›ß— ßﬂß— ßÈß‰ß÷ßﬂß⁄ß÷
    int n = 0;
    if (!fin.is_open()) // ß·ß‚ß‡ß”ß÷ß‚ß‹ß—, ßÈß‰ß‡ ßÊß—ß€ß› ß‡ß‰ß‹ß‚ßÌß‰
        throw FileErrCodeException(filename, "can't open file");
    else {
        while (fin.get() != EOF)
            n++;
        if (n == 0){
            throw FileException(filename, "is empty"); //ошибка если файл пустой
        }
    }
    fin.close(); //ßŸß—ß‹ß‚ßÌß‰ßÓ ßÊß—ß€ß›
    return n;
}

int main(int argc, char** argv) {
    try {
        if (argc < 2) {
            throw Exception("no filename");
        }
        int count;
        count = count_symbols(argv[1]);
        cout << "File " << argv[1] << " contains " << count << " symbols" << endl;
        ofstream fout("result.txt");
        if (fout.is_open()){
            fout << "File " << argv[1] << " contains " << count << " symblos" << endl;
            fout.close();
        }
    }


    catch (FileErrCodeException& ex) {//ß›ß⁄ß“ß⁄ß‰ ß⁄ß„ß„ß‹ß›ßßÈß÷ßﬂß⁄ß÷ ß„ß‡ß‡ß‰ß”ß„ß‰ß”ßÂß÷ß‰
        cerr << "Exception: " << ex.GetComment() << " " << ex.GetFilename();
        cerr << " Error code: " << strerror(ex.GetErrCode()) << endl; //strerror ß·ß÷ßÈß—ß‰ßÓ ß„ß‰ß‚ß‡ß‹ß— ß·ß‡ ß‡ßÍß⁄ß“ß‹ß—
        return 1;
    }
    catch (FileException& ex){
        cerr << "Exception: " << ex.GetFilename() << " " << ex.GetComment() << endl;
    }
    catch (Exception& ex){
        cerr << "Exception: " << ex.GetComment()<< endl;
    }
    catch (...) {
        cerr << "Unknown error" << endl;
        return 3;
    }

    return 0;

}
