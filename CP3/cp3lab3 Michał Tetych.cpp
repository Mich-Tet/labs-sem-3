#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
//iterator
// define a list vector and insert values define your own class for strings, create a insert operator that 
//will allow to instert chars between exising words

using namespace std;
//1. Task
auto test123() {
    vector<int> test{ 1,2,3,4,5 };
    vector<int>::iterator iterator;

    iterator = test.insert(test.begin(), 10);
    test.insert(iterator, 20);

    int i = 2;


    iterator = test.insert(test.begin() + i, 10);
    iterator = test.insert(test.begin() + i * i, 333);
    iterator = test.insert(test.begin() + i, 10);
    cout << "My vector: " << endl;
    fill_n(back_inserter(test), 2, 1);
    for (auto iterator = test.begin(); iterator != test.end(); iterator++)
        cout << ' ' << *iterator;
    cout << '\n';
    return 0;
}
//2. Task
class myword
{
public:
    string buf;
    myword(const char* txt)
    {
        buf = string(txt);
    }
    class iterator
    {
        int idx;
        string* ps;
    public:
        iterator(int n, string& s) : idx(n), ps(&s) {}
        bool operator!=(const iterator& s) const
        {
            return !((idx == s.idx) && (ps == s.ps));
        }
        char operator*()
        {
            return (*ps)[idx];
        }
        iterator& operator++()
        {
            idx++;
            return *this;
        }
        bool operator==(const int s) const
        {
            return (idx == s);
        }
    };
    iterator begin()
    {
        return iterator(0, this->buf);
    }
    iterator end()
    {
        return iterator(buf.length(), this->buf);
    }
    void insert(myword txt, int pos, char a)
    {
        myword::iterator p = txt.begin();

        string we;

        while (p != txt.end())
        {
            we += *p;
            if (p == pos)
            {
                we += a;
            }
            ++p;
        }
        cout << we;
    }
};


int main()
{
    //1.
    test123();

    //2.
    myword a("Hello");
    a.insert(a,3, 'd');


    return 0;
}