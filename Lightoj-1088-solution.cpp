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
//first value not less than a
ll lowerbound(ll ara[], ll low, ll high, ll a, ll n)
{
   if (low > high)
   {
      return -1;
   }
   ll mid = (low + high) / 2;
   if (ara[mid] == a)
   {
      return mid;
   }
   else if (ara[mid] > a)
   {
      if (mid - 1 >= 0 && ara[mid - 1] < a)
      {
         return mid;
      }
      else if (mid - 1 < 0)
      {
         return mid;
      }
      else
      {
         return lowerbound(ara, low, mid - 1, a, n);
      }
   }
   else if (ara[mid] < a)
   {
      if (mid + 1 <= (n - 1) && ara[mid + 1] > a)
      {
         return mid + 1;
      }
      else if (mid + 1 >= n)
      {
         return n;
      }
      else
      {
         return lowerbound(ara, mid + 1, high, a, n);
      }
   }
}
//first value greater than a
ll upperbound(ll ara[], ll low, ll high, ll a, ll n)
{
   if (low > high)
   {
      return -1;
   }
   ll mid = (low + high) / 2;
   if (ara[mid] == a)
   {
      return mid + 1;
   }
   else if (ara[mid] > a)
   {
      if (mid - 1 >= 0 && ara[mid - 1] < a)
      {
         return mid;
      }
      else if (mid - 1 < 0)
      {
         return mid;
      }
      else
      {
         return upperbound(ara, low, mid - 1, a, n);
      }
   }
   else if (ara[mid] < a)
   {
      if (mid + 1 <= (n - 1) && ara[mid + 1] > a)
      {
         return mid + 1;
      }
      else if (mid + 1 >= n)
      {
         return n;
      }
      else
      {
         return upperbound(ara, mid + 1, high, a, n);
      }
   }
}
int main()
{
   int t, p = 1;
   sc(t);
   while (t--)
   {
      ll n, q;
      sccl(n, q);
      ll ara[n];
      inputl(ara, n);
      ll a, b;
      printcase(p++);
      while (q--)
      {
         sccl(a, b);
         a = lowerbound(ara, 0, n - 1, a, n);
         b = upperbound(ara, 0, n - 1, b, n);
         if ((b - a) < 0)
         {
            pf(0);
         }
         else
         {
            pfl(b - a);
         }
      }
   }
   return 0;
}
