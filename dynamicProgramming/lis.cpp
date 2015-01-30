int f[N];
int LIS()//O(N*N)
{
	for(int i = 1; i <= n; i++)
		for(int j = i-1; j >= 1; j--)
			if(a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
	int res = 0;
	for(int i = 1; i <= n; i++) res = max(res, f[i]);
	return res;
}

int c[N], len = 0;
int LIS()//(NlogN)
{
	for(int i = 1; i <= n; i++)
	{
		//-----find-----
			int l = 1, r = len, mid;
			while(l <= r)
			{
				mid = (l + r) / 2;
				if(a[i] > c[mid]) l = mid + 1;
				else r = mid - 1;
			}
		//-----end-----
		c[l] = a[i];
		len = max(len, l);
	}
	return len;
}
