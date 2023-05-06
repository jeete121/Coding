#include <bits/stdc++.h>
using namespace std;

class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
    Employee()
    {
    }
    Employee(int id, int importance, vector<int> subordinates)
    {
        this->id = id;
        this->importance = importance;
        this->subordinates = subordinates;
    }
};
int getImportance(vector<Employee *> employees, int id)
{

    vector<int> x;
    int ans = 0;
    for (int i = 0; i < employees.size(); i++)
    {
        if (employees[i]->id == id)
        {
            x = employees[i]->subordinates;
            ans += employees[i]->importance;
            break;
        }
    }
    set<int> st;
    for (int i = 0; i < x.size(); i++)
    {
        int p = x[i];

        if (st.find(p) != st.end())
            continue;
        st.insert(p);
        vector<int> m;
        for (int j = 0; j < employees.size(); j++)
        {
            if (employees[j]->id == p)
            {
                m = employees[j]->subordinates;
                ans += employees[j]->importance;
                break;
            }
        }
        for (int j = 0; j < m.size(); j++)
            x.push_back(m[j]);
    }
    return ans;
}

int main()
{
    vector<Employee *> employees;
    employees.push_back(new Employee{1, 5, {2, 3}});
    employees.push_back(new Employee{2, 3, {}});
    employees.push_back(new Employee{3, 3, {}});
    int id = 1;

    cout << getImportance(employees, id);
    return 0;
}