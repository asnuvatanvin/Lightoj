#include <bits/stdc++.h>

/*............................*/

#define uint uint64_t
#define mx 5001
#define ll long long int
#define ull unsigned long long int
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define mp make_pair
#define pb push_back
#define inf INT_MAX
#define mod 100000007
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
#define printcase(p) printf("Case %d: ", p)
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
//As everyone should have the same amount of money then the average of all the money should be equal to each persons amount
bool visited[1001];
vector<ll> node[1001];
ll total, people, money[1001];
void dfs(ll u)
{
   visited[u] = true;
   total += money[u];
   people++;
   for (ll i = 0; i < node[u].size(); i++)
   {
      ll v = node[u][i];
      if (!visited[v])
         dfs(v);
   }
}
int main()
{
   int t, p = 1;
   sc(t);
   while (t--)
   {
      ll n, m, a, b, sum = 0;
      sccl(n, m);
      for (ll i = 1; i <= n; i++)
      {
         scl(money[i]);
         sum += money[i];
      }
      for (ll i = 0; i < m; i++)
      {
         sccl(a, b);
         node[a].pb(b);
         node[b].pb(a);
      }
      bool flag = true;
      ll avg = sum / n;
      memset(visited, false, sizeof(visited));
      for (ll i = 1; i <= n; i++)
      {
         if (!visited[i])
         {
            total = 0;
            people = 0;
            dfs(i);
            if (total % people != 0)
            {
               flag = false;
               break;
            }
            else
            {
               if (avg != (total / people))
               {
                  flag = false;
                  break;
               }
            }
         }
      }
      printcase(p++);
      if (flag)
      {
         printf("Yes\n");
      }
      else
      {
         printf("No\n");
      }
      for (ll i = 0; i < 1001; i++)
      {
         node[i].clear();
      }
   }
   return 0;
}
