void prime()
{
	memset(dist, 0, sizeof(dist));
	int res = 0;
	while(!Q.empty())
	{
		int x = Q.top().second;
		if(done[x]) {Q.pop(); continue;}
		res += Q.top().first;
		Q.pop();
		for(Link p = head[x]; p; p = p->next)
			if(dist[p->y] > p->z)
			{
				dist[p->y] = p->z;
				Q.push(make_pair(dist[p->y], p->y));
			}
	}
}
