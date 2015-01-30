struct Parti{int val, left;} val[30][N];
void build_tree(int d, int l, int r)
{
	if(l == r) return;
	int m = (l + r) >> 1, same = m - l + 1;
	int lcnt = l, rcnt = m + 1;
	for(int i = l; i <= r; i++)
		if(val[d][i].val < sorted[m]) same--;
	for(int i = l; i <= r; i++)
	{
		int flag = 0;
		if((val[d][i].val < soted[m]) || (val[d][i].val == sorted[m] && same))
		{
			flag = 1;
			val[d + 1][lcnt++] = val[d][i];
			if(val[d][i].val == sorted[m]) same--;
		}
		else val[d][rcnt++] = val[d][i];
		val[d][i].left = val[d][i - 1].left + flag;
	}
	build_tree(d + 1, l, m);
	build_tree(d + 1, m + 1, r);
}
int query(int d, int l, int r, int x, int y, int k)
{
	if(l == r) return val[d][l].val;
	int m = (l + r) >> 1;
	int lx = val[d][x - 1].left - val[d][l - 1].left; //[l,x-1] to left
	int ly = val[d][y].left - val[d][x - 1].left; //[x,y] to left
	int rx = (x - 1 - l + 1) - lx; //[l,x-1] to right
	int ry = (y - x + 1) - ly; //[x,y] to right
	if(ly >= k) return query(d+1, l, m, l-1+lx+1, l-1+lx+ly, k);
	else return query(d+1, m+1, r, m+1-1+rx+1, m+1-1+rx+ry, k-ly);
}

