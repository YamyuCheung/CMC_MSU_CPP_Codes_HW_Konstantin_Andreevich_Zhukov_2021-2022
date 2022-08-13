//
//  F8.cpp
//  C++
//
//  Created by Xinyu Zhang on 17/05/2022.
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

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>compute;
        string s;
        if(tokens.size() == 0){
            return 0;
        }
        for(int i=0;i<tokens.size();++i){
            s=tokens[i];
            if(s=="+"||s=="-"||s=="*"||s=="/"){
                int a,b,res;
                b=compute.top();
                compute.pop();
                a=compute.top();
                compute.pop();
                if(s=="+") { res=a+b; }
                else if(s=="-") { res=a - b; }
                else if(s=="*") { res=a*b; }
                else if(s=="/") { res=a/b; }
                compute.push(res);
            }
            else{
                compute.push(stoi(s));
            }
        }
        return compute.top();
    }
};


int main() {
//    vector<string> tokens = {"100", "25", "+", "25", "/"};
    vector<string> tokens;

    char c;
    string str;
    while (cin.peek() != '\n'){
        c = cin.get();
        if(c != ' '){
            str += c;
        }else if(c == ' '){
            tokens.push_back(str);
            str = {};
        }
    }
    if(str.size()>0){
        tokens.push_back(str);
    }
    Solution solution;
    float res=solution.evalRPN(tokens);
    cout << res <<endl;
}

