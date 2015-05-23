void spfa()
{
	memset(inQ, 0, sizeof(inQ));
	memset(dist, 0x3f, sizeof(dist));
	dist[S] = 0; Q.push(S); inQ[S] = 1; //S为源点
	while(!Q.empty())
	{
		int x = Q.front(); Q.pop(); inQ[x] = 0;
		for(Link p = head[x]; p; p = p->next)
			if(dist[p->y] > dist[x] + p->z)
			{
				dist[p->y] = dist[x] + p->z;
				if(!inQ[p->y])
				{
					Q.push(p->y);
					inQ[p->y] = 1;
				}
			}
	}
}
