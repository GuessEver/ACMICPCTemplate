头文件cstring
strlen(s);//获取长度  O(N)
strcpy(a+2,b+1)//从b+1开始全部赋值给a+2开始的字符串
strncpy(a+2,b+1,2)//从b+1开始赋值2个给a+2开始的字符串
strcmp(a,b)//比较a和b的大小，相等返回0，a>b返回正整数
strcat(a,b)//相当于string类的 a += b;
strstr(a,b)-a;//返回b在a中第一次出现的位置，不存在返回NULL(即0)，由于-a,所以最后应该是-a
