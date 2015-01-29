//   h[x] :   点 x 在第 h[x] 层
//   v[k] :   第 k 层有 v[k] 个点 
int sap(int x, int flow)
{
	if(x == n) return flow;
	int res = 0;
	for(int i = S; i <= T; i++)
		if(g[x][i] && h[x] == h[i] + 1)
		{
			int t = sap(i, min(g[x][i], flow - res));
			res += t; g[x][i] -= t; g[i][x] += t;
			if(res == flow) return res;
			if(h[S] >= T) return res;
		}
	//if(h[S] >= T) return res;
	if((--v[h[x]]) == 0) h[S] = T;
	++v[++h[x]];
	return res;
}
int main()
{
	v[0] = T;
	int maxflow = 0;
	while(h[S] < T) maxflow += sap(1, inf);
	reutrn 0;
}

