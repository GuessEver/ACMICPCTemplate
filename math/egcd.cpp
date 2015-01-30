ax + by = 1
bx1 + (a%b)y1 = 1    ==>   bx + (a-a/b*b)y = 1
  ==> ay1 + b(x1-a/b*y1) = 1
对应  ax  + by         = 1

int egcd(int a, int b, int &x, int &y)
{
	if(b == 0)
	{
		x = 1; y = 0;
		return a;
	}
	int x1, y1;
	int e = egcd(b, a%b, x1, y1);
	x = y1;
	y = x1 - a / b * y1;
	return e;
}
