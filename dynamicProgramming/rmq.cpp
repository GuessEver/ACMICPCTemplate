int _rmq[N][30], Log[你想开多大就开多大];
for(int i = 2; i < 随便; i++) Log2[i] = Log2[i>>1] + 1;
void init_RMQ(int *_orig) // [1, n]
{
	for(int i = 1; i <= n; i++) _rmq[i][0] = _orig[i];
	for(int j = 1; j <= Log2[n]; j++)
		for(int i = 1; i <= n + 1 - (1 << j); i++)
			_rmq[i][j] = std::max(_rmq[i][j-1], _rmq[i+(1<<(j-1))][j-1]);
}
int query_RMQ(int l, int r) // max{x E [l, r]}
{
	int k = Log2[r - l + 1];
	return std::max(_rmq[l][k], _rmq[r-(1<<k)+1][k]);
}
