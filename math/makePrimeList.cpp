namespace prime{
	const int N = 10000000 + 10;
	int pri[N], h[N], Cnt;
	void make(int maxp) // O(2*N)
	{
		for(int i = 2; i <= maxp; i++)
		{
			if(!h[i]) pri[Cnt++] = i;
			for(int j = 0; j < Cnt && pri[j] <= maxp / i; j++)
			{
				h[i * pri[j]] = true;
				if(i % pri[j] == 0) break;
			}
		}
	}
}

