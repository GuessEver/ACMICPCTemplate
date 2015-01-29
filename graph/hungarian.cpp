int ttt = 0; // 全局时间戳变量

bool search(int x)
{
	for(int i = 1; i <= m; i++)
		if(map[x][i] && vis[i] != ttt)
		{
			vis[i] = ttt;
			if(pre[i] == -1 || search(pre[i]))
			{
				pre[i] = x;
				return 1;
			}
		}
	return 0;
}

int match()
{
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		++ttt; // 这里不用memset节省时间
		res += search(i);
	}
	return res;
}
