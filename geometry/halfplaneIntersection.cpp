#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using std::vector;

const double EPS = 1e-10, INF = 1e20;
const double PI = acos(-1.0);
const int sign(const double &x) {
	if(fabs(x) < EPS) return 0;
	return x < 0 ? -1 : 1;
}
const int dcmp(const double &x, const double &y) {
	return sign(x - y);
}
struct Point {
	double x, y;
	Point() {}
	Point(const double &_x, const double &_y) { x = _x; y = _y; }
	void Read() { scanf("%lf%lf", &x, &y); }
	bool operator < (const Point &b) const {
		if(dcmp(x, b.x) == 0) return dcmp(y, b.y) < 0;
		return dcmp(x, b.x) < 0;
	}
	Point operator + (const Point &b) const {
		return Point(x + b.x, y + b.y);
	}
	Point operator - (const Point &b) const {
		return Point(x - b.x, y - b.y);
	}
	Point operator * (const double &k) const {
		return Point(x * k, y * k);
	}
	Point operator / (const double &k) const {
		return Point(x / k, y / k);
	}
	double operator * (const Point &b) const {
		return x * b.x + y * b.y;
	}
	double operator ^ (const Point &b) const {
		return x * b.y - y * b.x;
	}
	bool operator == (const Point &b) const {
		return dcmp(x, b.x) == 0 && dcmp(y, b.y) == 0;
	}
	double Abs() const {
		return sqrt(x * x + y * y);
	}
};
typedef Point Vector;
// 单位法向量
const Vector getNormalVector(const Vector &P) {
	double L = P.Abs(); // `L` CANNOT BE `0` !!!!
	return Vector(-P.y / L, P.x / L);
}
struct Line {
	Point P; // 直线上任意一点
	Vector v; // 直线向量，左边为对应半平面
	double angle;
	Line() {}
	Line(const Point &_P, const Vector &_v) {
		P = _P; v = _v;
		angle = atan2(v.y, v.x);
	}
	bool operator < (const Line &L) const {
		return angle < L.angle;
	}
};

// 判断点在直线左边（线上不算）
const bool isPointOnLineLeft(const Point &P, const Line &L) {
	return sign(L.v ^ (P - L.P)) > 0;
}
// 两直线交点（假设交点唯一存在）
const Point getLineIntersection(const Line &L1, const Line &L2) {
	Vector u = L1.P - L2.P;
	double t = (L2.v ^ u) / (L1.v ^ L2.v);
	return L1.P + L1.v * t;
}
// 半平面交（结果在poly，返回顶点数）
int HalfplaneIntersection(Line *L, int n, Point *poly) {
	std::sort(L, L + n);
	int first, last;
	Point *p = new Point[n];
	Line *q = new Line[n];
	q[first=last=0] = L[0];
	for(int i = 1; i < n; i++) {
		while(first < last && !isPointOnLineLeft(p[last-1], L[i])) last--;
		while(first < last && !isPointOnLineLeft(p[first], L[i])) first++;
		q[++last] = L[i];
		if(sign(q[last].v ^ q[last-1].v) == 0) {
			last--;
			if(isPointOnLineLeft(L[i].P, q[last])) q[last] = L[i];
		}
		if(first < last) p[last-1] = getLineIntersection(q[last-1], q[last]);
	}
	while(first < last && !isPointOnLineLeft(p[last-1], q[first])) last--;
	if(last - first <= 1) return 0; // 空集
	p[last] = getLineIntersection(q[last], q[first]); // 计算首位两个半平面交点
	// 保存答案
	for(int i = first; i <= last; i++) poly[i-first] = p[i];
	return last - first + 1;
}

int main() {
	return 0;
}
