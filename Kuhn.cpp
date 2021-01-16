// Code works in O(n^2 * k) time
#include <bits/stdc++.h>
using namespace std;

#define vi vector <long long>
#define mp make_pair
#define ll long long
#define pb push_back

ll n, m, k, x, y, cnt;
vi g[1111], mt;
bool used[1111];
bool try_kuhn (int v) {
	if (used[v])  return false;
	used[v] = true;
	for (auto to : g[v]) {
		if (mt[to] == -1 || try_kuhn (mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;
    for(int i = 1; i <= m; i++){
        cin >> x >> y;
        if(n <= k)
            g[x].pb(y);
        else
            g[y].pb(x);
    }
    if(n > k)
        swap(n, k);
    mt.assign (k + 1, -1);
	vector<char> used1 (n + 1, false);
	for (int i = 1; i <= n; i++)
		for (auto j : g[i])
			if (mt[j] == -1) {
				mt[j] = i;
				used1[i] = true;
				break;
			}
	for (int i = 1; i <= n; i++) {
		if (used1[i])  continue;
		for(int i = 1; i <= n; i++)
            used[i] = 0;
		try_kuhn (i);
	}

	for (int i = 1; i <= k; i++)
		if (mt[i] != -1)
			cnt++;
    cout << cnt << endl;
}
