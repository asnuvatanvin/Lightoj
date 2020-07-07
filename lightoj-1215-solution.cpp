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
#define pi acos(-1)
#define eps 1e-8
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / __gcd(a, b)
#define input(ara, n)           \
    for (int i = 0; i < n; i++) \
    scanf("%d", &ara[i])
#define inputl(ara, n)                    \
    for (long long int i = 0; i < n; i++) \
    scanf("%lld", &ara[i])
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
    int t, h = 1;
    sc(t);
    while (t--)
    {
        ll a, b, l;
        scccl(a, b, l);
        ll m = a * b / gcd(a, b);
        if (l % m != 0)
        {
            printf("Case %d: impossible\n", h++);
        }
        else
        {
            //now this is a problem to find the number p for which lcm(p,m)=l
            //p has to be a number that can divide l and not m

            ll p = l / m; // p contains the prime factor that should be in l and not in m
            //for this gcd(p,m) has to be equal to zero
            //until gcd(p,m) not equal to zero all the common factors are transferred to p from m
            //final p is the answer
            ll g = gcd(p, m);
            while (g != 1)
            {
                p *= g;
                m /= g;
                g = gcd(m, p);
            }
            printf("Case %d: %lld\n", h++, p);
        }
    }
    return 0;
}