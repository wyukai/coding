//
// Created by wk on 2021/4/12.
//

/*
 * std::ref 主要为了解决多线程程序和C++11函数式编程中的值拷贝问题。
 * 函数式编程(如std::bind)在使用时，是对参数直接拷贝，而不是引用。
 * std::reference_wrapper 用于按引用传递对象给 std::bind 或 std::thread 的构造函数
 */

#include <iostream>
#include <functional>
#include <thread>
using namespace std;

class A{
public:
    mutable int m_idx;  // m_idx 可修改

    A(int x) : m_idx(x) {
        cout << "构造函数  " << this << "  Thread_id  " << this_thread::get_id() <<endl;
    }

    A(const A& a){
        m_idx = a.m_idx;
        cout << "拷贝构造函数  " << this << "  Thread_id  " << this_thread::get_id() << endl;
    }
    ~A(){
        cout << "析构函数 " <<this << "    Thread_id  " <<this_thread::get_id() << endl;
    }
};

void fun(const A& b){
    b.m_idx = 20;
    cout <<b.m_idx <<endl;
    cout <<"子线程  "<< &b << "   Thread_id  " << this_thread::get_id() <<endl;
}

int main(){
    int i, &n1 = i;
    i =5;
    n1 =10;
    cout << i <<" "<< n1<<endl;
//    A a(10);
//    thread t(fun, std::ref(a));
//
//    t.join();
//
//    cout << a.m_idx <<endl;
    return 0;
}




//void func(int& n1, int& n2, const int& n3){
//    cout<< "In function : " << n1 << n2 << n3 <<endl;
//    ++n1;
//    ++n2;
//}
//
//int main(){
//    int n1 = 1, n2 = 2, n3 = 3;
//    std::function<void()> bound_f = std::bind(func, n1, std::ref(n2), std::cref(n3));
//
//    n1 = 4;
//    n2 = 5;
//    n3 = 6;
//
//    cout <<  "before function : " << n1 << n2 << n3 <<endl;
//    bound_f();
//    cout <<"After function :" << n1 << n2 << n3 <<endl;
//    return 0;
//}
