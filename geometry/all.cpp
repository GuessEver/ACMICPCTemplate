#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
using std::max;
using std::min;
using std::sort;
using std::swap;
using std::pair;
using std::make_pair;
const double eps = 1e-8, inf = 1e20;
const double pi = 4.0 * atan(1.0);
#define Degree(_rad) (180.0 / pi * (_rad))

int fuhao(double x)
{
	if (fabs(x)<eps) return 0;
	if (x<0) return -1;
	else return 1;
}

///////////////////////////   Point && Vector   ///////////////////////////
struct Point{
	double x, y;
    Point (){}
    Point (double _x,double _y):x(_x),y(_y){}
	void init(double a, double b) { x = a; y = b; }
	
	// basic calc
		bool operator == (const Point &b) const
		{
			return !fuhao(x - b.x) && !fuhao(y - b.y);
		}
		Point operator + (const Point &b) const
		{
			return Point(x + b.x, y + b.y);
		}
		Point operator - (const Point &b) const
		{
			return Point(x - b.x, y - b.y);
		}
		Point operator * (const double &b) const
		{
			return Point(x * b, y * b);
		}
		
		Point Rotate(Point p, double alpha) // alpha E [0, +oo) 逆时针
		{
			double x0 = p.x, y0 = p.y;
			double tx = x - x0, ty = y - y0;
			double nx = tx * cos(alpha) - ty * sin(alpha);
			double ny = tx * sin(alpha) + ty * cos(alpha);
			nx += x0; ny += y0;
			return Point(nx, ny);
		}
		
	// Vector
		double operator *(const Point &b)const
		{// Dot
			return x * b.x + y * b.y;
		}
		double operator ^ (const Point &b)const
		{// Cross
			return x * b.y - y * b.x;
		}
		double Abs() { return sqrt(x * x + y * y); }
};
double Dist(const Point &a, const Point &b) { return (a - b).Abs(); }
typedef Point Vector;

double Angle(Vector a, Vector b)
{
	return acos(a * b / a.Abs() / b.Abs());
}
Vector Get_H(Vector A)
{ // 求与向量垂直的单位向量   使用前确保不为0向量
	// A != Vector(0.0, 0.0);
	double L = A.Abs();
	return Vector(-A.y / L, A.x / L);
}

///////////////////////////      E - N - D      ///////////////////////////


///////////////////////////         Line        ///////////////////////////
struct Line{
	Point s,e;
	Line() {}
	Line(Point ss, Point ee)
	{
		s = ss; e = ee;
	}
	
	// 两直线的关系：重合0， 平行1， 相交2 并返回交点
	pair<int,Point> operator &(const Line &b) const
	{
		Point ans = s;
		if(fuhao((s-e)^(b.s-b.e))==0)
		{
			if (fuhao((s-b.e)^(b.s-b.e))==0)
				return make_pair(0,ans);//重合
			else return make_pair(1,ans);//平行
		}
		double t = ((s-b.s)^(b.s-b.e)) / ((s-e)^(b.s-b.e));
		ans.x += (e.x-s.x) * t;
		ans.y += (e.y-s.y) * t;
		return make_pair(2,ans);//相交
	}
};
///////////////////////////      E - N - D      ///////////////////////////

//判断线段相交
bool inter(Line l1,Line l2)
{
	return
	max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
	max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
 	max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
	max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
	fuhao((l2.s-l1.e)^(l1.s-l1.e)) * fuhao((l2.e-l1.e)^(l1.s-l1.e))<=0 &&
	fuhao((l1.s-l2.e)^(l2.s-l2.e)) * fuhao((l1.e-l2.e)^(l2.s-l2.e))<=0;
}
//判断直线与线段相交
bool Seg_inter_line(Line l1,Line l2)//l1为直线 l2为线段
{
	return fuhao((l2.s-l1.e)^(l1.s-l1.e))*fuhao((l2.e-l1.e)^(l1.s-l1.e))<=0;
}
//点到直线距离
//返回点到直线最近的点
Point PointToLine(Point P,Line L)
{
	Point ans;
	double t=((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
	ans.x=L.s.x+(L.e.x-L.s.x)*t;
	ans.y=L.s.y+(L.e.y-L.s.y)*t;	
	return ans;
}
//点到线段距离
//返回点到线段最近的点
Point NearestPointToLineSeg(Point P,Line L)
{
	Point ans;
	double t = ((P-L.s)*(L.e-L.s)) / ((L.e-L.s)*(L.e-L.s));	
	if (t>=0&&t<=1)
	{
		ans.x = L.s.x + (L.e.x-L.s.x)*t;
		ans.y = L.s.y + (L.e.y-L.s.y)*t;
	}
	else {
		if (Dist(P,L.s)<Dist(P,L.e))
			ans = L.s;
		else 	ans = L.e;
	}
	return ans;
}
//多边形面积
double CalcArea(Point p[],int n)	
{
	double ans=0;
	for (int i=0;i<n;++i)
		ans+=(p[i]^p[(i+1)%n])/2;
	return fabs(ans);
}
//判断点在线段上
bool OnSeg(Point P,Line L)
{
	return 
			fuhao((L.s-P)^(L.e-P))==0 &&
			fuhao((P.x-L.s.x)*(P.x-L.e.x))<=0 &&
			fuhao((P.y-L.s.y)*(P.y-L.e.y))<=0;
}
//三点求圆心坐标
Point waixin(Point a,Point b,Point c)
{
	double a1=b.x-a.x,b1=b.y-a.y,c1=(a1*a1+b1*b1)/2;
	double a2=c.x-a.x,b2=c.y-a.y,c2=(a2*a2+b2*b2)/2;
	double d=a1*b2-a2*b1;
	return Point(a.x+(c1*b2-c2*b1)/d,a.y+(a1*c2-a2*c1)/d);
}


///////////////////////////        Graham       ///////////////////////////
//求凸包 点list[0~n-1]
//凸包结果Stack[0~top-1]
const int Maxn = 100;////////////////here!! 
Point list[Maxn];           //////////?!?!?!?!补全Maxn !?!?!?!?!?!?!?!?!?!?!
int Stack[Maxn],top;
bool _cmp (Point p1,Point p2)
{
	double tmp=(p1-list[0])^(p2-list[0]);
	if (fuhao(tmp)>0) return true;
	else if (fuhao(tmp)==0&&fuhao(Dist(p1,list[0])-Dist(p2,list[0]))<=0) 
		return true;
	else	return false;
}
void Graham(int n)
{
	Point p0;
	int k=0;
	p0=list[0];
	for (int i=1;i<n;++i)
	{
		if ((p0.y>list[i].y)||(p0.y==list[i].y&&p0.x>list[i].x))
		{
			p0=list[i];
			k=i;
		}
	}
	swap(list[k],list[0]);
	sort(list+1,list+n,_cmp);
	if (n==1)
	{
		top=1;
		Stack[0]=0;
		return;
	}
	if (n==2)
	{
		top=2;
		Stack[0]=0;
		Stack[1]=1;
		return;
	}
	Stack[0]=0;
	Stack[1]=1;
	top=2;
	for (int i=2;i<n;++i)
	{
		while (top>1 && fuhao((list[Stack[top-1]]-list[Stack[top-2]])^(list[i]-list[Stack[top-2]]))<=0)
			top--;
		Stack[top++]=i;
	}
}
///////////////////////////      E - N - D      ///////////////////////////


///////////////////////////         Area        ///////////////////////////
double PolygonArea(Point *pp, int nn) // pp[0, n-1]
{
	double ans_area = 0.0;
	for(int i = 1; i < nn-1; i++)
	{
		ans_area += (pp[i] - pp[0]) ^ (pp[i+1] - pp[0]);
	}
	return fabs(ans_area / 2); 
}
///////////////////////////      E - N - D      ///////////////////////////

///////////////////////////     点在多边形内    ///////////////////////////
int isPointInPolygon(Point p, Point *poly, int nn)
{
	int w = 0;
	for(int i = 0; i < n; i++)
	{
		if(OnSeg(p, Line(poly[i], poly[(i+1)%n]))) return -1; // 边界上
		int k = fuhao((poly[(i+1)%n] - poly[i]) ^ (p - poly[i]));
		int d1 = fuhao(poly[i].y - p.y);
		int d2 = fuhao(poly[(i+1)%n].y - p.y);
		if(k > 0 && d1 <= 0 && d2 > 0) wn++;
		if(k < 0 && d1 > 0 && d2 <= 0) wn--;
	}
	if(wn != 0) return 1; //内部
	return 0; // 外部
}
///////////////////////////      E - N - D      ///////////////////////////


int main()
{
}
