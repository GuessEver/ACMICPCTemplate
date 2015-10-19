void dfs()
{
	st.clear();
	DFS.push(std::make_pair(root, 0));
	int END = 3;
	while(!DFS.empty())
	{
		pair<int, int> &now = DFS.top();
		if(now.second != END)
		{
			++now.second;
			DFS.push(std::make_pair(SON[now.first], 0));
		}
		else DFS.pop();
	}
}

