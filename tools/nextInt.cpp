inline int nextInt()
{
	char ch = getchar(); int res = 0; bool sign = 0;
	while(!isdigit(ch) && ch != '-') ch = getchar();
	if(ch == '-') { sign = 1; ch = getchar(); }
	do res = (res << 1) + (res << 3) + ch - '0';
	while(isdigit(ch = getchar()));
	return sign ? -res : res;
}

