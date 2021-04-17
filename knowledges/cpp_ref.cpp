//
// Created by wk on 2021/4/12.
//

/*
 * std::ref ��ҪΪ�˽�����̳߳����C++11����ʽ����е�ֵ�������⡣
 * ����ʽ���(��std::bind)��ʹ��ʱ���ǶԲ���ֱ�ӿ��������������á�
 * std::reference_wrapper ���ڰ����ô��ݶ���� std::bind �� std::thread �Ĺ��캯��
 */

#include <iostream>
#include <functional>
#include <thread>
using namespace std;

class A{
public:
    mutable int m_idx;  // m_idx ���޸�

    A(int x) : m_idx(x) {
        cout << "���캯��  " << this << "  Thread_id  " << this_thread::get_id() <<endl;
    }

    A(const A& a){
        m_idx = a.m_idx;
        cout << "�������캯��  " << this << "  Thread_id  " << this_thread::get_id() << endl;
    }
    ~A(){
        cout << "�������� " <<this << "    Thread_id  " <<this_thread::get_id() << endl;
    }
};

void fun(const A& b){
    b.m_idx = 20;
    cout <<b.m_idx <<endl;
    cout <<"���߳�  "<< &b << "   Thread_id  " << this_thread::get_id() <<endl;
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
