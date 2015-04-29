#include <cstdio>
#include <cstring>

int fac[10], a[10];

bool Read(int *p)
{
	for(int i = 0; i < 9; i++)
	{
		char chtmp;
		if(scanf(" %c", &chtmp) != 1) return 0;
		p[i] = chtmp == 'x' ? 0 : chtmp - '0';
	}
	return 1;
}

int Cantor(int *p) // Eight puzzle status -> Integer
{
	int res = 0;
	for(int i = 0; i < 9; i++)
	{
		int cnt = 0;
		for(int j = i + 1; j < 9; j++)
			if(p[j] < p[i]) cnt++;
		res += cnt * fac[9 - i - 1];
	}
	return res;
}

bool used[10] = {0};
int getRank(int r)
{
	for(int i = 0, j = 0; i < 9; i++)
	{
		if(!used[i] && j == r) return i;
		if(!used[i]) j++;
	}
}
void getStatus(int cantor, int *p) // Integer -> Eight puzzle status
{
	memset(used, 0, sizeof(used));
	for(int i = 0; i < 9; i++)
	{
		p[i] = getRank(cantor / fac[9 - i - 1]);
		used[p[i]] = 1;
		cantor %= fac[9 - i - 1];
	}
}

void PRINT(int *p)
{
	int hash = Cantor(p);
	printf("Cantor value = %d\n", hash);
	getStatus(hash, p);
	printf("Cantor Status = ");
	for(int i = 0; i < 9; i++) printf("%d", p[i]); puts("");
}

int main()
{
	fac[0] = 1; for(int i = 1; i < 10; i++) fac[i] = fac[i-1] * i;
	while(Read(a)) PRINT(a);
	return 0;
}
