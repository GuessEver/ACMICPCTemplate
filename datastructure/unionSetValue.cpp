#include <cstdio>
#include <cstdlib>

const int N = 100000 + 10;

int n, f[N], g[N];

int getroot(int x)
{
	if(f[x] == x) return x;
	int tmp = getroot(f[x]);
	g[x] += g[f[x]]; // update the value
	return f[x] = tmp;
}

void merge(int x, int y) // merge x's set and y's set
{ // Guarantee that the x must be the root of its set, which means x == getroot(x) is true, but it may not be same for y
	int fy = getroot(y);
	g[x] += g[y] + abs(x - y) % 1000; // update the value
	f[x] = fy;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) f[i] = i;
	char op; int x, y;
	while(scanf(" %c", &op) == 1 && op != 'O')
	{
		if(op == 'I')
		{
			scanf("%d%d", &x, &y);
			if(getroot(x) == getroot(y)) continue;
			merge(x, y);
		}
		else{
			scanf("%d", &x);
			getroot(x); // !!! update the value of x before output
			printf("%d\n", g[x]);
		}
		//for(int i = 1; i <= n; i++) printf("%d ", f[i]); puts("");
	}
	return 0;
}
