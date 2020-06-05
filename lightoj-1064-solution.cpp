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
#define input(ara, n)          \
   for (int i = 0; i < n; i++) \
   scanf("%d", &ara[i])
#define inputl(ara, n)                   \
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
//int X[]={1,-1,0,0}; //co-ordinate move
//int Y[]={0,0,1,-1}; //co-ordinate move
//int X[]={1,1,2,2,-1,-1,-2,-2}; //Knights move
//int Y[]={2,-2,1,-1,2,-2,1,-1}; //Knights move
/******Always use printf & scanf*******/
ll cap, item;
ll power[26], dp[30][200];
void cal_pow()
{
   power[0] = 1;
   for (int i = 1; i < 25; i++)
   {
      power[i] = power[i - 1] * 6;
   }
}
ll solve(ll i, ll w)
{
   if (i == item)
   {
      if (w >= cap)
      {
         return 1;
      }
      else
      {
         return 0;
      }
   }
   ll result = 0;
   if (dp[i][w] != -1)
   {
      return dp[i][w];
   }
   for (ll j = 1; j <= 6; j++)
   {
      result += solve(i + 1, w + j);
   }
   dp[i][w] = result;
   return dp[i][w];
}
int main()
{
   cal_pow();
   int t, p = 1;
   sc(t);
   while (t--)
   {
      sccl(item, cap);
      for (ll i = 0; i < 30; i++)
      {
         for (ll j = 0; j < 200; j++)
         {
            dp[i][j] = -1;
         }
      }
      ll result = solve(0, 0);
      ll g = gcd(result, power[item]);
      if(result==0){
         printf("Case %d: 0\n",p++);
      }
      else if (result % power[item] == 0 && result!=0)
      {
         printf("Case %d: 1\n", p++);
      }
      else
      {
         printf("Case %d: %lld/%lld\n", p++, result / g, power[item] / g);
      }
   }
   return 0;
}