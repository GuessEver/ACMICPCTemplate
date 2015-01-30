int A[N], S[N], L[N], R[N], root, total;
void rotate_left(int &x)
{
	int y = R[x];
	R[x] = L[y];
	L[y] = x;
	S[y] = S[x];
	S[x] = S[L[x]] + S[R[x]] + 1;
	x = y;
}
void rotate_right(int &x)
{
	int y = L[x];
	L[x] = R[y];
	R[y] = x;
	S[y] = S[x];
	S[x] = S[L[x]] + S[R[x]] + 1;
	x = y;
}

void maintain(int &p, bool flag)
{
	if(flag)//调整右边
	{
		if(S[R[R[p]]] > S[L[p]] rotate_left(p);
				else if(S[R[L[p]]] > S[L[p]])
		{
			rotate_right(R[p]);
				rotate_left(p);
			}
			else return;
			}
	else
	{
		if(S[L[L[p]]] > S[R[p]]) rotate_right(p);
		else if(S[L[R[p]]] > S[R[p]])
		{
			rotate_left(L[p]);
			rotate_right(p);
		}
		else return;
	}
	maintain(L[p], 0);
	maintain(R[p], 1);
	maintain(p, 0);
	maintain(p, 1);
}

void insert(int &p, int e)
{
	if(!p)
	{
		p = ++total;
		L[p] = R[p] = 0;
		A[p] = e; S[p] = 1;
		return;
	}
	S[p]++;
	if(e < A[p]) insert(L[p], e);
	else insert(R[p], e);
	maintain(p, k >= A[p]);
}

int getmin()
{
	for(int x = root; L[x]; x = L[x]);
	return A[x];
}
int getmax()
{
	for(int x = root; R[x]; x = R[x]);
	return A[x];
}
int kth(int &p, int k)
{
	int tmp = S[L[p]] + 1;
	if(k == tmp) return A[p];
	else if(k < tmp) return kth(L[p], k);
	else return kth(R[p], k - tmp);
}


