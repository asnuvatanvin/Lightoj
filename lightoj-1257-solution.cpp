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
int main()
{
   int t,p=1;
   sc(t);
   while (t--)
   {
      double l,w,a,b,c,x1,x2,x;
      sccdbl(l,w);
      a=12.0;
      b=4.0*(l+w)*(-1.0);
      c=l*w;
      x=(-b-sqrt(b*b-4.0*a*c))/(2.0*a);
      printf("Case %d: %lf\n",p++,(l-2.0*x)*(w-2.0*x)*x);
   }
   /*The idea is if the height of the box is x then the volume would be V=(l-2*x)*(w-2*x)*x
   If simplified the equation becomes V=4*x^3-2*x^2*(l+w)+x*l*w
   For maximization or for finding the critical values both sides are differentiated w.r.t x
   That implies 12*x^2-4*x*(l+w)+l*w=0. Solving this equation we get the answer.*/
   return 0;
}