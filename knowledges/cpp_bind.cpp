//
// Created by wk on 2021/4/12.
//

/*
 * std::bind 使用
 * 1. bind预先绑定的参数需要传具体的变量或值进去，对于预先绑定的参数，是pass-by-value的；
 * 2. 对于不事先绑定的参数，需要传std::placeholders进去，从_1开始，依次递增。placeholder是pass-by-reference的；
 * 3. bind的返回值是可调用实体，可以直接赋给std::function对象;
 * 4. 类的this可以通过对象或者指针来绑定;
 * 5. 对于绑定的指针、引用类型的参数，使用者需要保证在可调用实体调用之前，这些参数是可用的；
*/
#include <iostream>
#include <functional>

using namespace std;

void TestFunc(int& a, char c, float& f){
    cout<< ++a << endl;
    cout<< c <<endl;
    cout<< f++ <<endl;
}

int main(){

    int v1 = 2;
    char v2 = 'a';
    float v3 = 3.5;

    auto bindFunc1 = bind(TestFunc, std::ref(v1), v2,  std::ref(v3));
    bindFunc1();

    cout << "=================\n";
    cout<< v1 <<endl;
    cout<< v2 <<endl;
    cout<< v3 <<endl;

//    cout << "=================\n";
//
//    // std::placeholders是一个占位符， 当使用bind生成一个新的可调用对象时，它可以标识新的可调用
//    // 对象的第几个参数和原函数的第几个参数相对应。
//    auto bindFunc2 = bind(TestFunc, std::placeholders::_1, std::placeholders::_2, 3.2);
//    bindFunc2(2, 'a');
//
//    cout<< "===================\n";
//
//    auto bindFunc3 = bind(TestFunc, std::placeholders::_3, std::placeholders::_1, std::placeholders::_2);
//    bindFunc3(2.3, 5, 'b');

    return 0;

}

