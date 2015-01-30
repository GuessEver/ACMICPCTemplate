int MaxSubSum()
{
	int f[N], res;
	for(int i = 1; i <= n; i++)
	{
		f[i] = max(a[i], f[i-1] + a[i]);
		res = max(res, f[i]);
	}
	return res;
}

int MaxSubSum()
{
	int res = 0, now = 0;
	for(int i = 1; i <= n; i++)
	{
		now += a[i];
		res = max(res, now);
		if(now < 0) now = 0;
	}
	return res;
}
