int sa[N], rank[N];
int c[N], tmp[N];
int height[N];
bool cmp(int *r, int a, int b, int l)
{
	return r[a] == r[b] && r[a + l] == r[b + l];
}
void DA(int n, int m) //n为长度，m为字串的最大值。均为开区间
{
	int i, j, p, *x = rank, *y = tmp;
	memset(c, 0, sizeof(c));
	for(i = 0; i < n; i++) c[ x[i] = s[i] ] ++;
	for(i = 1; i < m; i++) c[i] += c[i - 1];
	for(i = n - 1; i >= 0; i--) sa[ --c[x[i]] ] = i;
	for(j = 1, p = 0; p < n; j *= 2, m = p)
	{
		for(p = 0, i = n - j; i < n; i++) y[p++] = i;
		for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
		memset(c, 0, sizeof(c));
		for(i = 0; i < n; i++) c[ x[y[i]] ]++;
		for(i = 1; i < m; i++) c[i] += c[i - 1];
		for(i = n - 1; i >= 0; i--) sa[ --c[x[y[i]]] ] = y[i];
		swap(x, y); x[sa[0]] = 0;
		for(i = 1, p = 1; i < n; i++)
			if(x[i]) x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
	}
	for(i = 0; i < n; i++) rank[sa[i]] = i;
	int k = 0;
	for(i = 0; i < n; height[x[i++]] = k)
		for(k ? k-- : 0, j = sa[x[i] - 1]; s[i + k] == s[j + k]; k++);
}
int main()
{
	读入字串s，n=s的长度
	s[n++]=’$’;//最后加入一个不存在的值，排除超界情况
	DA(n,m);
}

