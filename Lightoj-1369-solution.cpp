    #include <bits/stdc++.h>
     
    /*............................*/
     
    #define uint uint64_t
    #define mx 100001
    #define ll long long int
    #define ull unsigned long long int
    #define pii pair<int, int>
    #define pll pair<long long int, long long int>
    #define mp make_pair
    #define pb push_back
    #define inf INT_MAX
    #define mod 1000000007
    #define pi acos(-1)
    #define eps 1e-8
    #define gcd(a, b) __gcd(a, b)
    #define lcm(a, b) (a * b) / __gcd(a, b)
    #define input(ara, n)          \
       for (int i = 0; i < n; i++) \
       scanf("%d", &ara[i])
    #define inputl(ara, n)                   \
       for (long long int i = 0; i < n; i++) \
       scanf("%lld", &ara[i])
    #define printcase(p) printf("Case %d:\n", p)
    #define pf(a) printf("%d\n", a);
    #define pfl(a) printf("%lld\n", a);
    #define pfi(a) printf("%d ", a);
    #define pfll(a) printf("%lld ", a);
    #define sc(a) scanf("%d", &a)
    #define scc(a, b) scanf("%d %d", &a, &b)
    #define sccdbl(a, b) scanf("%lf %lf", &a, &b)
    #define sccc(a, b, c) scanf("%d %d %d", &a, &b, &c)
    #define scccdbl(a, b, c) scanf("%lf %lf %lf", &a, &b, &c)
    #define scl(a) scanf("%lld", &a)
    #define sccl(a, b) scanf("%lld %lld", &a, &b)
    #define scccl(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
    using namespace std;
    int main()
    {
       int t, p = 1;
       sc(t);
       while (t--)
       {
          ll n, q;
          sccl(n, q);
          ll ara[n];
          ll sum = 0;
          for (ll i = 0; i < n; i++)
          {
             scl(ara[i]);
             sum = sum + (n - 1 - i) * ara[i] - (i * ara[i]);
          }
          ll a, b, c;
          printcase(p++);
          while (q--)
          {
             scl(a);
             if (a == 0)
             {
                sccl(b, c);
                sum = sum - (n - 1 - b) * ara[b] + (b * ara[b]);
                ara[b] = c;
                sum = sum + (n - 1 - b) * ara[b] - (b * ara[b]);
             }
             else
             {
                printf("%lld\n", sum);
             }
          }
       }
       return 0;
    }
