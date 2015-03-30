Arrays.fill(a, x); // for(int i = 0; i < N; i++) a[i] = x;
Arrays.fill(a, l, r, x); // for(int i = l; i < r; i++) a[i] = x;
Arrays.sort(a); // 给a的所有元素排序 升序
Arrays.sort(a, l, r); // 给a的[l, r)元素排序 升序
Arrays.sort(a, l, r, new cmp());

import java.io.*;
import java.util.*;
import java.math.*;
class INT{
	int s;
	public INT(int x) { s = x; }// 构造函数 INT a = new INT(3);
}
class cmp implements Comparator<INT>{
	public int compare(INT a, INT b)
	{
		return a.s - b.s;
	}
}
public class Main{
	public static void main(String args[])
	{
		Scanner cin = new Scanner(System.in);
		int n;
		INT a[] = new INT[100];
		for(int i = 1; i <= 10; i++) a[i] = new INT(11 - i);
		Arrays.sort(a, 1, 11, new cmp());
	}
}
//a[i].s排序前10 9 8 7 6 5 4 3 2 1
//a[i].s排序后1 2 3 4 5 6 7 8 9 10

String s = Integer.toString(n, B); // 把十进制数n转换成B进制数
int b = Integer.parseInt(s, B); // 把B进制数s转换成10进制数
