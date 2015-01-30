//求凸包 点list[0~n-1]
//凸包结果stack[0~top-1]
Point list[Maxn];
int Stack[Maxn],top;
bool _cmp (Point p1,Point p2)
{
	double tmp=(p1-list[0])^(p2-list[0]);
	if (fuhao(tmp)>0) return true;
	else if (fuhao(tmp)==0&&fuhao(dist(p1,list[0])-dist(p2,list[0]))<=0) 
		return true;
	else	return false;
}
void Graham(int n)
{
	Point p0;
	int k=0;
	p0=list[0];
	for (int i=1;i<n;++i)
	{
		if ((p0.y>list[i].y)||(p0.y==list[i].y&&p0.x>list[i].x))
		{
			p0=list[i];
			k=i;
		}
	}
	swap(list[k],list[0]);
	sort(list+1,list+n,_cmp);
	if (n==1)
	{
		top=1;
		stack[0]=0;
		return;
	}
	if (n==2)
	{
		top=2;
		stack[0]=0;
		stack[1]=1;
		return;
	}
	stack[0]=0;
	stack[1]=1;
	top=2;
	for (int i=2;i<n;++i)
	{
		while (top>1 && fuhao((list[stack[top-1]]-list[stack[top-2]])^(list[i]-list[stack[top-2]]))<=0)
			top--;
		stack[top++]=i;
	}
}

