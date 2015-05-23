int timeStamp = 0;
int n, m, g[N][N];
int vis[N], pre[N];

bool search(int x)
{
	for(int i = 1; i <= m; i++)
		if(g[x][i] && vis[i] != timeStamp)
		{
			vis[i] = timeStamp;
			if(pre[i] == -1 || search(pre[i]))
			{
				pre[i] = x;
				return 1;
			}
		}
	return 0;
}

int maxMatch()
{
	int res = 0;
	memset(pre, -1, sizeof(pre));
	for(int i = 1; i <= n; i++)
	{
		++timeStamp;
		res += search(i);
	}
	return res;
}
