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
    ll tree[mx * 4];
    ll lazy[mx * 4];
    void buildtree(ll node, ll first, ll last)
    {
       if (first == last)
       {
          tree[node] = 0;
          lazy[node] = 0;
          return;
       }
       ll left = node * 2;
       ll right = node * 2 + 1;
       ll mid = (first + last) / 2;
       buildtree(left, first, mid);
       buildtree(right, mid + 1, last);
       tree[node] = tree[left] + tree[right];
       lazy[node] = lazy[left] + lazy[right];
       //tree[node]=min(tree[left],tree[right]);
    }
    void update(ll node, ll start, ll end, ll l, ll r, ll val)
    {
       if (lazy[node] != 0)
       {
          // This node needs to be updated
          tree[node] += (end - start + 1) * lazy[node]; // Update it
          if (start != end)
          {
             lazy[node * 2] += lazy[node];     // Mark child as lazy
             lazy[node * 2 + 1] += lazy[node]; // Mark child as lazy
          }
          lazy[node] = 0; // Reset it
       }
       if (start > end or start > r or end < l) // Current segment is not within range [l, r]
          return;
       if (start >= l and end <= r)
       {
          // Segment is fully within range
          tree[node] += (end - start + 1) * val;
          if (start != end)
          {
             // Not leaf node
             lazy[node * 2] += val;
             lazy[node * 2 + 1] += val;
          }
          return;
       }
       ll mid = (start + end) / 2;
       update(node * 2, start, mid, l, r, val);       // Updating left child
       update(node * 2 + 1, mid + 1, end, l, r, val); // Updating right child
       tree[node] = tree[node * 2] + tree[node * 2 + 1];   // Updating root with max value
    }
     
    ll query(ll node, ll start, ll end, ll l, ll r)
    {
       if (start > end or start > r or end < l)
          return 0; // Out of range
       if (lazy[node] != 0)
       {
          // This node needs to be updated
          tree[node] += (end - start + 1) * lazy[node]; // Update it
          if (start != end)
          {
             lazy[node * 2] += lazy[node];     // Mark child as lazy
             lazy[node * 2 + 1] += lazy[node]; // Mark child as lazy
          }
          lazy[node] = 0; // Reset it
       }
       if (start >= l and end <= r) // Current segment is totally within range [l, r]
          return tree[node];
       ll mid = (start + end) / 2;
       ll p1 = query(node * 2, start, mid, l, r);       // Query left child
       ll p2 = query(node * 2 + 1, mid + 1, end, l, r); // Query right child
       return (p1 + p2);
    }
    int main()
    {
       int t, p = 1;
       sc(t);
       while (t--)
       {
          ll n, q;
          sccl(n, q);
          buildtree(1, 1, n);
          ll a, b, c, d;
          printcase(p++);
          while (q--)
          {
             scl(a);
             if (a == 0)
             {
                scccl(b, c, d);
                update(1, 1, n, b + 1, c + 1, d);
             }
             else
             {
                sccl(b, c);
                ll ans = query(1, 1, n, b + 1, c + 1);
                printf("%lld\n", ans);
             }
          }
       }
       return 0;
    }
