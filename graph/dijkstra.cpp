void dijkstra()
{
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0; Q.push(make_pair(0, 1));
	while(!Q.empty())
	{
		int x = Q.top().second; Q.pop();
		if(done[x]) continue;
		done[x] = 1;
		for(Link p = head[x]; p; p = p->next)
			if(dist[p->y] > dist[x] + p->z)
			{
				dist[p->y] = dist[x] + p->z;
				Q.push(make_pair(-dist[p->y], p->y));
			}
	}
}
