void getnext(char *t)
{
	memset(next, 0, sizeof(next));
	next[0] = -1;
	int j = 0, k = -1;
	int len = strlen(t);
	while(j < len)
	{
		if(k == -1 || t[j] == t[k]) next[++j] = ++k;
		else k = next[k];
	}
}
void kmp()
{
	getnext();
	int lens = strlen(s), lent = strlen(t);
	int i = 0, j = 0;
	while(i < lens)
	{
		if(j == -1 || s[i] == t[j]) i++, j++;
		else j = next[j];
		if(j == lent) return j - lent;
	}
	return -1;
}

