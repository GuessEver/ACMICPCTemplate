void floyd()
{
	for(int k = 1; k <= n; k++) // 这里可以看作是一个加边的过程
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
}

// 最小环 
void MinCircle()
{
	cap[] = map[];
	int circle = 0x3f3f3f3f;
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i < k; i++)
			for(int j = i+1; j < k; j++)
				circle = min(circle, map[i][j] + cap[j][k]+cap[k][i]);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
	}
	return circle == 0x3f3f3f3f ? -1 : circle;
}

// floyd判圏法 （大白书 p44）
void Circle()
{
	int ans = k;
	int k1 = k, k2 = k;
	do{
		k1 = next(k1);
		k2 = next(k2); ans = max(ans, k2);
		k2 = next(k2); ans = max(ans, k2);
	}while(k1 != k2);
	return ans;
}
