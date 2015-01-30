void make_prime_list(int maxp) // O(2*N)
{
	for(int i = 2; i <= maxp; i++)
	{
		if(!h[i]) pri[l++] = i;
		for(int j = 0; j < l && pri[j] <= maxp / i; j++)
		{
			h[i * pri[j]] = true;
			if(i % pri[j] == 0) break;
		}
	}
}
