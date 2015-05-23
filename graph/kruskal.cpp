int kruskal()
{
	sort(edge, edge+Cnt, cmp);
	int res = 0;
	for(int i = 0; i < Cnt; i++)
	{
		if(getroot(edge[i].x) == getroot(edge[i].y)) continue;
		f[getroot(edge[i].x)] = getroot(edge[i].y);
		res += edge[i].z;
	}
	return res;
}
