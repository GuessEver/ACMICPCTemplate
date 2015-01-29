//====初始化====
头文件string并加上std::
string s(str);//相当于string s=str;
string s(cstr);//把char数组类型的字符串cstr作为s的初值
s.clear();//清空，相当于 s="";

//====长度====
s.length();//获取s的长度，O(1)
s.size();//一样

//====插入删除====
s.insert(2, "a"); //在s的位置2插入string类字符串"a"
s.erase(2, 3); //从s的位置2开始删除3个字符

//====查找====
s.find("abc");//查找字符串"abc"在s中第一次出现的位置（据说是KMP实现的）
//s="aabcc"; printf("%d %d\n",(int)s.find("abc"),(int)s.find("aabb"));
//上一行程序应输出 1 -1  （若没找到必须强行转换为int才为 -1 ）

