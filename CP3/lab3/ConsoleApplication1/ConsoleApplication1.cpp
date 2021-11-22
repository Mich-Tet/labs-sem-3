#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
//iterator
// define a list vector and insert values define your own class for strings, create a insert operator that 
//will allow to instert chars between exising words

using namespace std;

auto test123() {
    vector<int> test{ 1,2,3,4,5 };
    vector<int>::iterator iterator;
    
    iterator = test.insert(test.begin(), 10);
    test.insert(iterator, 20);

    int i = 2;
    
    
    iterator = test.insert(test.begin()+i, 10);
    iterator = test.insert(test.begin() + i*i, 333);
    iterator = test.insert(test.begin() + i, 10);
    cout << "My vector: " << endl;
    fill_n(back_inserter(test), 2, 1);
    for (auto iterator = test.begin(); iterator != test.end(); iterator++)
        cout << ' ' << *iterator;
    cout << '\n';
    return 0;
}

class myword
{
public:
    string buf;
    myword(const char *txt)
    {
        buf = string(txt);
    }
    class iterator
    {
        int idx;
        string* ps;
    public:
        iterator(int n, string &s) : idx(n), ps(&s) {}
        bool operator!=(const iterator &s) const
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
        friend ostream& operator<<(ostream& os, const myword& dt);

    };
void insert(int pos, char a)
{
    vector<char> L;
    vector <char>::iterator L_Iter;
    insert_iterator< vector < char> > Iter(L, L.end());
    *Iter = a;
    for (L_Iter = L.begin(); L_Iter != L.end(); L_Iter++)
    cout << *L_Iter << " ";
}  
iterator begin()
{
    return iterator(0, this->buf);
}
iterator end()
{
    return iterator(buf.length(), this->buf);
}
};

ostream& operator<<(ostream& os, const myword& dt)
{
    os << dt.buf;
    return os;
}
int testword()
{
    myword a(" Hello ");
    myword::iterator p = a.begin();
    cout << "\n ===== \n";
    cout << "\nMy word is: \n";
    a.insert(1,'d');
    while (p != a.end())
    {
        cout << *p;
        ++p;
    }
    return 0;
}
int main()
{
    myword a(" Hello ");
    myword::iterator p = a.begin();
    a.insert(1,'d');
    cout << a;
    test123();
    testword();
    
   
    
    return 0;
}