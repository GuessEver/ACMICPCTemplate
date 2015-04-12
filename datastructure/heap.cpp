#include <cstdio>
#include <algorithm>

const int N = 250000;

int n, a[N], x, size = 0;

void update(int i)
{
	while(i > 1 && a[i] > a[i/2])
	{
		std::swap(a[i], a[i/2]);
		i /= 2;
	}
}

void pop()
{
	int i = 1; a[i] = 0;
	while(i * 2 <= size && (a[i] < a[i*2] || a[i] < a[i*2+1]))
	{
		if(i * 2 == size || (i * 2 < size && a[i*2] >= a[i*2+1]))
		{
			a[i] = a[i*2];
			a[i*2] = 0;
			i = i * 2;
		}
		else {
			a[i] = a[i*2+1];
			a[i*2+1] = 0;
			i = i * 2 + 1;
		}
	}
	a[i] = a[size]; size--;
	update(i);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		a[++size] = x;
		update(size);
	}
	for(int i = 1; i <= n; i++)
	{
		printf("%d ", a[1]);
		pop();
	}
	return 0;
}
