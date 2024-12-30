#include <bits/stdc++.h>
#define F first
#define S second
#define mod 1000000007
#define Task ""
#define N 1000005
#define ALL(f) f.begin() , f.end()
#define ll long long
using namespace std;

typedef pair<int,int> ii;

int n,m,cnt=0;
bool isend[N];
int child[N][27];

void add(string s)
{
    int node=0;
    for(char c : s)
    {
        int x = c - 'a';
        if(child[node][x] == 0) child[node][x] = ++cnt;
        node = child[node][x];
    }
    isend[node]=1;
}

bool findd(string s)
{
    int node=0;
    for(char c : s)
    {
        int x = c - 'a';
        if(child[node][x] == 0) return 0;
        node = child[node][x];
    }
    return isend[node];
}

int main()
{

    string s;
    while(cin >> s)
    {
        if(s == "*") break;
        add(s);
    }

    while(cin >> s)
    {
        if(s == "*") break;
        if(s == "find")
        {
            string u;
            cin >> u;
            cout << findd(u) << "\n";
        }
        if(s == "insert")
        {
            string u;
            cin >> u;
            if(findd(u) == 1)
            {
                cout << 0 << "\n";
            }
            else
            {
                add(u);
                cout << 1 << "\n";
            }

        }
    }

    return 0;
}

