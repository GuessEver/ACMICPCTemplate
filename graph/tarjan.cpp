void dfs(int x)
{
	now[x] = low[x] = ++dfstime;
	hash[x] = 1;
	st.push(x); inst[x] = 1;
	for(int i = 1; i <= n; i++)
		if(map[x][i])
		{
			if(!hash[i])
			{
				dfs(i);
				low[x] = min(low[x], low[i]);
			}
			else if(inst[i]) low[x] = min(low[x], now[i]);
		}
	if(low[x] == now[x])
	{
		while(!st.empty())
		{
			int u = st.top();
			st.pop(); inst[u] = 0;
			belong[u] = number;
			if(u == x) break;
		}
		numer++;
	}
}
void tarjan()
{
	for(int i = 1; i <= n; i++)
		if(!hash[i]) dfs(i);
	if(!st.empty()) // 这是一个未知bug   栈中还会剩下一个强连通分量 
	{
		while!st.empty())
		{
			int u = st.top();
			st.pop();
			belong[u] = number;
		}
		number++;
	}
}
