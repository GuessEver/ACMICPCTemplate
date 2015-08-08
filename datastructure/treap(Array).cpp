struct treap {
	const int N = 100000 + 10;
	int L[N*20], R[N*20], S[N*20], fix[N*20], A[N*20];
	int root, total;
	void rotate_left(int &p)
	{
		int tmp = R[p];
		R[p] = L[tmp];
		int zsize = S[L[tmp]];
		S[p] = S[p] - S[tmp] + zsize;
		L[tmp] = p;
		S[tmp] = S[tmp] - zsize + S[p];
		p = tmp;
	}
	void rotate_right(int &p)
	{
		int tmp = L[p];
		L[p] = R[tmp];
		int zsize = S[R[tmp]];
		S[p] = S[p] - S[tmp] + zsize;
		R[tmp] = p;
		S[tmp] = S[tmp] - zsize + S[p];
		p = tmp;
	}
	void Insert(int &p, int x)
	{
		if(!p)
		{
			p = ++total;
			L[p] = R[p] = 0;
			S[p] = 1;
			fix[p] = rand();
			A[p] = x;
			return;
		}
		S[p]++;
		if(x < A[p])
		{
			Insert(L[p], x);
			if(fix[L[p]] > fix[p]) rotate_right(p);
		}
		else {
			Insert(R[p], x);
			if(fix[R[p]] > fix[p]) rotate_left(p);
		}
	}
	int Delete_min(int &p)
	{
		S[p]--;
		if(!L[p])
		{
			int value = A[p];
			p = R[p];
			return value;
		}
		else return Delete_min(L[p]);
	}
	void Delete(int &p, int x)
	{
		if(!p) return;
		S[p]--;
		if(x < A[p]) Delete(L[p], x);
		else if(x > A[p]) Delete(R[p], x);
		else {
			if(!L[p] && !R[p]) p = 0;
			else if(!L[p] || !R[p])
			{
				if(!L[p]) p = R[p];
				else p = L[p];
			}
			else A[p] = Delete_min(R[p]);
		}
	}
	int Count_leq(int &p, int x)
	{
		if(!p) return 0;
		if(A[p] <= x) return S[L[p]] + 1 + Count_leq(R[p], x);
		else return Count_leq(L[p], x);
	}
	int Count_geq(int &p, int x)
	{
		if(!p) return 0;
		if(A[p] >= x) return S[R[p]] + 1 + Count_geq(L[p], x);
		else return Count_geq(R[p], x);
	}
	int Find_kth(int &p, int k)
	{
		if(k == S[L[p]] + 1) return A[p];
		if(k <= S[L[p]]) return Find_kth(L[p], k);
		else return Find_kth(R[p], k - S[L[p]] - 1);
	}
};
