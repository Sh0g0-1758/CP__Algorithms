// All complex things are inherently simple. If you can't explain something simply,
// you just don't understand it well enough.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define endl "\n"
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define INF 1e18
using cd = complex<double>;
const double PI=acos(-1);

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

int main()
{
    fastio();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        char temp;
        cin >> n >> temp;
        ll trump;
        if(temp == 'C')
            trump = 0;
        else if(temp == 'D')
            trump = 1;
        else if(temp == 'H')
            trump = 2;
        else
            trump = 3;
        vector<vector<ll>> cards(4, vector<ll>(8, 0));
        for(ll i = 0; i < 2 * n;i++) {
            string card;
            cin >> card;
            char temp = card[1];
            if(temp == 'C')
                cards[0][card[0] - '2']++;
            else if(temp == 'D')
                cards[1][card[0] - '2']++;
            else if(temp == 'H')
                cards[2][card[0] - '2']++;
            else
                cards[3][card[0] - '2']++;
        }
        vector<ll> indexes;
        for(ll i = 0; i < 4;i++) {
            if(i != trump) {
                if(accumulate(cards[i].begin(), cards[i].end(), 0)%2 != 0) {
                        indexes.push_back(i);
                }
            }
        }
        bool answer;
        if((accumulate(cards[trump].begin(), cards[trump].end(), 0) >= indexes.size()) and (accumulate(cards[trump].begin(), cards[trump].end(),0) - indexes.size()) % 2 == 0)
        {
            answer = true;
        } else {
            answer = false;
        }
        if (!answer) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        } else if (indexes.size() != 0) {
            for(ll i = 0; i < indexes.size();i++) {
                ll index = indexes[i];
                ll indx1, indx2;
                indx1 = find(cards[index].begin(), cards[index].end(), 1) - cards[index].begin();
                indx2 = find(cards[trump].begin(), cards[trump].end(), 1) - cards[trump].begin();
                cout << indx1 + 2;
                if(index == 0)
                    cout << "C";
                else if(index == 1)
                    cout << "D";
                else if(index == 2)
                    cout << "H";
                else
                    cout << "S";
                cout << " ";
                cout << indx2 + 2;
                if(trump == 0)
                    cout << "C";
                else if(trump == 1)
                    cout << "D";
                else if(trump == 2)
                    cout << "H";
                else
                    cout << "S";
                cout << endl;
                cards[index][indx1] = 0;
                cards[trump][indx2] = 0;
            }
        }
        for(ll i = 0;i < 4;i++) {
            ll cnt = 0;
            for(ll j = 0; j < 8;j++) {
                if(cards[i][j] == 1) {
                    cout << j + 2;
                    if(i == 0)
                        cout << "C";
                    else if(i == 1)
                        cout << "D";
                    else if(i == 2)
                        cout << "H";
                    else
                        cout << "S";
                    cout << " ";
                    cnt++;
                }
                if(cnt == 2) {
                    cout << endl;
                    cnt = 0;
                }
            }
        }
    }
    return 0;
}