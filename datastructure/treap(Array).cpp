struct treap {
	const int N = 100000 + 10;
	int L[N*20], R[N*20], S[N*20], fix[N*20], key[N*20];
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
			key[p] = x;
			return;
		}
		S[p]++;
		if(x < key[p])
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
			int value = key[p];
			p = R[p];
			return value;
		}
		else return Delete_min(L[p]);
	}
	void Delete(int &p, int x)
	{
		if(!p) return;
		S[p]--;
		if(x < key[p]) Delete(L[p], x);
		else if(x > key[p]) Delete(R[p], x);
		else {
			if(!L[p] && !R[p]) p = 0;
			else if(!L[p] || !R[p])
			{
				if(!L[p]) p = R[p];
				else p = L[p];
			}
			else key[p] = Delete_min(R[p]);
		}
	}
};
