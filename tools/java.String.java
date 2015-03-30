String s = "abcdefg"; // 注意0下标!
char c = s.charAt(2);// 相当于`char c = s[2]`(C++)(c = 'c')
char ch[];
ch = s.toCharArray(); // 字符串转换为字符数组
for(int i = 0; i < ch.length; i++) ch[i] += 2;
System.out.println(ch); // 输出cdefghi
String tmp1 = s.substring(1); // bcdefg
String tmp2 = s.substring(2, 4); // cd
