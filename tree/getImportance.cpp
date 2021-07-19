//
// Created by wk on 2021/7/19.
//
/*
 * 690. Employee Importance
Input: employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
Output: 11
Explanation: Employee 1 has importance value 5, and he has two direct subordinates: employee 2 and employee 3.
They both have importance value 3.
So the total importance value of employee 1 is 5 + 3 + 3 = 11.

 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Employee{
    int id;
    int importance;
    vector<int> subordinates;
    Employee(int i, int p, vector<int> sub): id(i), importance(p), subordinates(sub){};
};
unordered_map<int, int> m;
int result;

void dfs(vector<Employee*> employees, int id){
    int index = m[id];
    result += employees[index]->importance;
    for (int i = 0; i < employees[index]->subordinates.size(); ++i) {
        dfs(employees, employees[index]->subordinates[i]);
    }
    return;

}
int getImportance(vector<Employee*> employees, int id){
    // id 与 index对应
    for (int i = 0; i < employees.size(); ++i) {
        m[employees[i]->id] = i;
    }
    dfs(employees, id);
    return result;
}


int main(){
    Employee* e1 = new Employee(1,5,{2,3});
    Employee* e2 = new Employee(2,3, {});
    Employee* e3 = new Employee(3,3, {});


    vector<Employee*> employees;
    employees.push_back(e1);
    employees.push_back(e2);
    employees.push_back(e3);
    int total_impor = getImportance(employees, 1);
    cout <<  total_impor << endl;
}