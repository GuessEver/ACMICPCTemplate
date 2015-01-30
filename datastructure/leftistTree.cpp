//很多时候需要配合并查集一起使用
int getroot(int x){return f[x]==x ? x : f[x]=getroot(f[x]);}

//把x和y合并在一起，其实就是把y插入x
int merge(int x,int y)//返回合并后子树的根
{
	if(!x || !y) return x|y;
	if(A[x] < A[y]) swap(x,y);//大根堆，如果y比x大，与其让y插入x，不如让x插入y
	R[x]=merge(R[x],y);//始终往右子树合并
	f[R[x]] = x;//更新并查集
	if(D[R[x]] > D[L[x]]) swap(L[x],R[x]);//保持左偏树性质
	D[x] = D[R[x]] + 1;
	若还有其他维护信息也需要更新;
	return x;//返回根
}

int del(int x)
{
	int t = merge(L[x],R[x]);
	f[L[x]] = L[x]; f[R[x]] = R[x];//更新并查集
	L[x] = R[x] = D[x] = 0;
	return t;
}

