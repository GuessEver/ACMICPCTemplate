int prim()
{
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0; Q.push(make_pair(0, 1));
	int res = 0;
	while(!Q.empty())
	{
		int x = Q.top().second; Q.pop();
		if(done[x]) continue;
		res += dist[x]; done[x] = 1;
		for(Link p = head[x]; p; p = p->next)
			if(dist[p->y] > p->z)
			{
				dist[p->y] = p->z;
				Q.push(make_pair(-dist[p->y], p->y));
			}
	}
	return res;
}
