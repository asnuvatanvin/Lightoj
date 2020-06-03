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
/*solution idea:http://ojsolver.blogspot.com/2016/04/uva-10566-lightoj-1062-crossed-ladders.html*/
double bs(double low,double high,double x,double y,double h){
   if(low>high){
      return -1;
   }
   double mid=(low+high)/2.0;
   double h1=sqrt((x*x)-(mid*mid));
   double h2=sqrt((y*y)-(mid*mid));
   double hh=(h1*h2)/(h1+h2);
   if(abs(hh-h)<=0.000001){
      return mid;
   }
   else if(hh>h){
      return bs(mid,high,x,y,h);
   }
   else{
      return bs(low,mid,x,y,h);
   }
}
int main()
{
   int t,p=1;
   sc(t);
   while (t--)
   {
      double x,y,h;
      scccdbl(x,y,h);
      double ans=bs(0,min(x,y),x,y,h);
      printf("Case %d: %lf\n",p++,ans);
   }
   return 0;
}