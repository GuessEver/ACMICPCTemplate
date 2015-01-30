//x^y  % mod
int mul(int x, LL y, int mod) // �ݹ� 
{
	if(y == 1) return x;
	if(y & 1) return (mul((x * (LL)x) % mod, y / 2, mod) * (LL)x) % mod;
	else return mul((x * (LL)x) % mod, y / 2, mod) % mod;
}
int mul(int x, int y, int mod) // �ǵݹ� 
{
	int s = 1;
	int ss = x;
	while(y)
	{
		if(y & 1) s = s * ss;
		y /= 2;
		ss *= ss;
	}
	return s;
}

