#include <bits/stdc++.h>
using namespace std;
#define nline "\n"
const int mod = 1e9 + 7;
const double pie = 3.14159265;
using ll = long long;
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(NULL);           \
    cout.tie(NULL);
#define all(v) v.begin(), v.end()
#define allg(v) v.rbegin(), v.rend()
#define pb push_back
#define eb emplace_back
#define po pop_back
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define yes cout << "YES" \
                 << "\n"
#define no cout << "NO" \
                << "\n"
#define yesr           \
    {                  \
        cout << "YES"; \
        return;        \
    }
#define nor           \
    {                 \
        cout << "NO"; \
        return;       \
    }
#define inpvec        \
    ll n;             \
    cin >> n;         \
    vector<ll> v(n);  \
    for (auto &i : v) \
        cin >> i;
#define print(v)          \
    for (auto i : v)      \
    {                     \
        cout << i << " "; \
    }                     \
    cout << "\n";
#define inpstr(n, s) \
    ll n;            \
    cin >> n;        \
    string s;        \
    cin >> s;
bool isPowerOfTwo(ll n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
ll largePow(ll a, ll b)
{
    ll anss = 1;
    while (b > 0)
    {
        if ((b & 1) != 0) // checking if b is odd or even
        {
            // this condition is for if b is ODD
            anss = (anss * (a % mod)) % mod;
        }
        // if b is EVEN
        a = (a % mod) * (a % mod);
        b = b >> 1; // just doing half of b, we can write b/2 also
    }
    return anss;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
vector<bool> seiveOfErasthones(ll n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (ll i = 2; i * i <= n; i++)
    {
        for (ll j = 2 * i; j <= n; j += i)
        {
            isPrime[j] = false;
        }
    }
    return isPrime;
}
ll Mex(unordered_set<ll> &st)
{
    ll mex = 0;

    while (st.find(mex) != st.end())
    {
        mex++;
    }
    return mex;
}
ll getIthbit(ll n, ll i)
{
    ll mask = (1 << i);
    return (n & mask) > 0 ? 1 : 0;
}
void setIthBit(ll &n, ll i)
{
    ll mask = (1 << i);
    n = (n | mask);
}
bool isPalindrome(string S)
{
    for (int i = 0; i < S.length() / 2; i++)
    {
        if (S[i] != S[S.length() - i - 1])
        {
            return false;
        }
    }
    return true;
}
bool areDistinct(vector<ll> arr)
{
    ll n = arr.size();
    unordered_set<int> s;
    for (ll i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    return (s.size() == arr.size());
}
ll highestPowerof2(unsigned int n)
{
    // Invalid input
    if (n < 1)
        return 0;

    ll res = 1;

    // Try all powers starting from 2^1
    for (ll i = 0; i < 8 * sizeof(unsigned int); i++)
    {
        ll curr = 1 << i;

        // If current power is more than n, break
        if (curr > n)
            break;

        res = curr;
    }

    return res;
}

//********************************************************************************

const int V = 6; // here you can take any value or take input from user and pass to the functions whenerver required;

int min_Key(int key[], bool visited[])  
{ 
    int min = 999, min_index;  // 999 represents an Infinite value

    for (int v = 0; v < V; v++) { 
        if (visited[v] == false && key[v] < min) { 
        	// vertex should not be visited
            min = key[v];
			min_index = v;  
        }
    }    
    return min_index;  
}  

int print_MST(int parent[], int cost[V][V])
{
    int minCost = 0;
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << " \t" << cost[i][parent[i]] << " \n";
        minCost += cost[i][parent[i]];
    }
    cout << "Total cost is" << minCost;
}

void find_MST(int cost[V][V])
{
    int parent[V], key[V];
    bool visited[V];

    // Initialize all the arrays
    for (int i = 0; i < V; i++)
    {
        key[i] = 999; 
        visited[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;     
    parent[0] = -1; 

    // The MST will have maximum V-1 vertices
    for (int x = 0; x < V - 1; x++)
    {
        
        int u = min_Key(key, visited);

        visited[u] = true; // Add the minimum key vertex to the MST

        // Update key and parent arrays
        for (int v = 0; v < V; v++)
        {
            
            if (cost[u][v] != 0 && visited[v] == false && cost[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = cost[u][v];
            }
        }
    }

    print_MST(parent, cost);
}

int main()
{
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt",
            "r", stdin);
    freopen("output.txt",
            "w", stdout);
#endif
    int cost[V][V];
    cout << "Enter the vertices for a graph with 6 vetices";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> cost[i][j];
        }
    }
    find_MST(cost);
}
