int predoing(LL a, int *num)
{
	int le = 0;
	while(a)
	{
		num[++le] = a % 10;
		a /= 10;
	}
	return le;
}
int calc(int pos, int d, int u, int last)
{
	if(pos == 0) return 1;
	int &res = f[pos][d][u][last];
	if(res != -1) return res;
	res = 0;
	int st = d ? L[pos] : 0;
	int ed = u ? R[pos] : 9;
	for(int i = st; i <= ed; i++)
		if(合法) res += calc(pos - 1, d && i == L[pos], u && i == R[pos], i);
	return res;
}

