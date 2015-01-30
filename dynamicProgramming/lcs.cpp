int LCS() // O(N*N)
{//字符串纠正到以 1 为下标 
	int f[N][N];
	int res = 0;
	for(int i = 1; i < lena; i++)
		for(int j = 1; j < lenb; j++)
		{
			if(a[i] == a[j]) f[i][j] = f[i-1][j-1] + 1;
			else f[i][j] = max(f[i-1][j], f[i][j-1]);
			res = max(res, f[i][j]);
		}
	return res;
}

int LCS() // O(NlogN)
{//把 LCM 转化为 LIS 来做 
// 1 2 5 9 3 --> 1 2 3 4 5
// 1 5 3 9 2 --> 1 3 5 4 2 --> 对这个序列跑LIS()
	//-----change----- 
		//这里就要针对数据自己想尽办法转化了
		for(int i = 1; i <= n; i++) h[a[i]] = i;
		for(int i = 1; i <= n; i++) b[i] = h[b[i]];
	//-----end----- 
	return LIS();
}
