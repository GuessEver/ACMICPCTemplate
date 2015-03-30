Scanner cin = new Scanner(System.in);//一定记住最后 cin.close();
Scanner cin = new Scanner(new BufferedInputStream(System.in));

//一般直接用 System.out.println();
PrintWriter cout = new PrintWriter(System.out);//一定记住最后 cout.close();
PrintWriter cout = new PrintWriter(new BufferedOutputStream(System.out));

int n = cin.nextInt();
String s = cin.next();
double m = cin.nextDouble();
String line = cin.nextLine(); // 读一整行
BigInteger c = cin.nextBigInteger();
while(cin.hasNext()) {};

//PrintWriter 用 cout.println(...);
System.out.println(n + "-->" + s "-->" + m);

//使用format控制格式,与C/C++一样,double用%f,
System.out.format("%03d", c).println();
System.out.format("%.3f", c).println();

//变量声明
int a, b[] = new int[100];
double a, b[] = new double[100];
int a[][] = new int[100][100];
String ...
BigInteger/BigDecimal ...
