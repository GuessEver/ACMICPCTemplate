struct EG{int from,to,flow,cost,next;}edge[M];

void add_edge(int a,int b,int c,int d)
{
	edge[L]=(EG){a,b,c,+d,head[a]};
	head[a]=L++;
	edge[L]=(EG){b,a,0,-d,head[b]};
	head[b]=L++;
}

bool spfa()
{
	memset(inQ, 0, sizeof(inQ));
	memset(dist, 0x3f, sizeof(dist));
	dist[S] = 0;
	q.push(S);
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		inQ[x] = 0;
		for(int i = head[x]; i != -1; i = edge[i].next)
			if(edge[i].flow && dist[edge[i].to] > dist[x] + edge[i].cost)
			{
				pre[edge[i].to] = i;
				dist[edge[i].to] = dist[x] + edge[i].cost;
				if(!inQ[edge[i].to])
				{
					inQ[edge[i].to] = 1;
					q.push(edge[i].to);
				}
			}
	}
	return dist[T] != inf;
}
void MFMC()
{
	memset(head, -1, sizeof(head));
	建图调用 add_edge(); 
	
	int mincost = 0, maxflow = 0;
	while(spfa())
	{
		int res = inf;
		for(int i = T; i != S; i = edge[pre[i]].from)
		{
			res = min(res, edge[pre[i]].flow);
		}
		for(int i = T; i != S; i = edge[pre[i]].from)
		{
			edge[pre[i]].flow -= res;
			edge[pre[i] ^ 1].flow += res;
		}
		maxflow += res;
		mincost += res * dist[T];
	}
}

