#include <cstdio>
#include <cmath>
#include <algorithm>

const double EPS = 1e-10;
int sign(double x) {
	if(fabs(x) < EPS) return 0;
	return x > 0 ? 1 : -1;
}
int dcmp(double x, double y) {
	return sign(x - y);
}
struct Point {
	double x, y;
	Point() {}
	Point(double _x, double _y) { x = _x; y = _y; }
	bool operator < (const Point &b) const {
		if(dcmp(x, b.x) == 0) return dcmp(y, b.y) < 0;
		return dcmp(x, b.x) < 0;
	}
	Point operator - (const Point &b) const {
		return Point(x - b.x, y - b.y);
	}
	Point operator + (const Point &b) const {
		return Point(x + b.x, y + b.y);
	}
	double operator ^ (const Point &b) const {
		return y * b.x - x * b.y;
	}
};
// 凸包Andrew算法，输入点p[]，n个点，输出点ch，返回个数
// p[]中不能有重复点，执行完成后顺序被破坏
// 两个 < 改成 <= 可以让凸包边上含有点
int Andrew(Point *p, int n, Point *ch) {
	std::sort(p, p + n);
	int m = 0;
	for(int i = 0; i < n; i++) {
		while(m > 1 && sign((ch[m-1]-ch[m-2]) ^ (p[i]-ch[m-2])) < 0) m--;
		ch[m++] = p[i];
	}
	int k = m;
	for(int i = n-2; i >= 0; i--) {
		while(m > k && sign((ch[m-1]-ch[m-2]) ^ (p[i]-ch[m-2])) < 0) m--;
		ch[m++] = p[i];
	}
	if(n > 1) m--;
	return m;
}

int main() {
	return 0;
}
