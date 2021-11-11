// lab2
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <map>
#include <ctime>

using namespace std;

struct WithTail
{
    int tail;
    WithTail(int t) : tail(t) {}
    bool operator()(const pair<string, int> &p)
    {
        return p.second % 10 == tail;
    }
};

struct Entry
{
    string name;
    int number;
};

Entry entries[] = {
    {"Alice", 123456},
    {"Bob", 234567},
    {"Cathy", 456789},
    {"David", 345678}};

int main()
{
    int n = sizeof(entries) / sizeof(Entry);

    vector<Entry> v(entries, entries + n);
    // or
    //    vector<Entry> v;
    //    for (int i; i<n; i++)
    //        v.push_back(entries[i]);

    shuffle(v.begin(), v.end(), default_random_engine(time(NULL)));

    for (const auto &p : v)
        cout << p.name << ", " << p.number << endl;

    map<string, int> m;
    for (const auto &p : v)
        m[p.name] = p.number;

    auto p = find_if(m.begin(), m.end(), WithTail(9));
    if (p != m.end())
        cout << "Name is: " << p->first << endl;
    else
        cout << "Name not found\n";
}
