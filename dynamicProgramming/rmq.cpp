int _rmq[N][30];
void init_RMQ(int *_orig) // [1, n]
{
	for(int i = 1; i <= n; i++) _rmq[i][0] = _orig[i];
	for(int j = 1; j <= log(1.0 * n) / log(2.0); j++)
		for(int i = 1; i <= n + 1 - (1 << j); i++)
			_rmq[i][j] = std::max(_rmq[i][j-1], _rmq[i+(1<<(j-1))][j-1]);
}
int query_RMQ(int l, int r) // max{x E [l, r]}
{
	int k = log(r - l + 1.0) / log(2.0);
	return std::max(_rmq[l][k], _rmq[r-(1<<k)+1][k]);
}
