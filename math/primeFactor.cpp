void factor()
{
	make_prime_list();
	for(int j = 0; j < Cnt && pri[j]*pri[j] <= n; j++)
	{
		if(n % pri[j] == 0)
		{
			printf("%d ", pri[j]);
			while(n % pri[j] == 0) n /= pri[j];
		}
	}
	if(n!=1) printf("%d",n);
}
