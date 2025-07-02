# BUAA_OJ 各种坑

## 输入样例 & 输出样例 调试步骤

解决的问题：按一下回车得到一次输出，难以比对答案。

1. 按`f5`编译(其实是调试，然后还要按`shift+f5`)，得到文件`main`
2. 创建`in.txt`文件，粘贴输入样例并保存
3. 终端输入 `./main < in.txt > out.txt`（用相对路径）
4. 直接比对`out.txt`和输出样例

## EOF

windows端的EOF是`Ctrl+Z Enter`，linux端的是`Ctrl + D`

(文本文件中) win回车等于`\r\n`，linux回车是`\n`

> 碎碎念：以后我就用linux了🤪

## 字符画转义相关

把字符串丢到notepad3里面，替换顺序：
`\` -> `\\`
`'` -> `\'`
`"` -> `\"`
每行貌似还要弄个`\n`

也可以直接用文件重定向，参见附件

## 读取整行的gets与fgets

一些比较现代的ide编译`gets()`已经不给过了，有的平台`gets()`也不给编译了。但是buaa的oj还能过。。

```c
char str[Maxsize];
gets(str);
```

替代方案(最安全)：
> 注意一下，`fgets`的第二个参数`Maxsize`开小了也会`RuntimeError(SIGSEGV)`，解决方案就是防御性编程，遇到字符串直接开`buffer[10005]`而不是`buffer[10001]`，所谓“不差这么几个字节的内存”。

```c
char str[Maxsize];
fgets(str,Maxsize,stdin);
str[strcspn(str, "\n")] = '\0';
```

## 字符串的动态内存分配

例题：读取并存储`10,000`个字符串，每个长度不超过`1,000`。但总字符数不超过`200,000`(即200KB内存)

常见解法：

```c
char strings[10005][1005];
// 一个字符串就是1KB
// 占了10,000KB的内存，即10MB，编译不通过
for (int i = 0; i < 10000; i++) {
    gets(string[i]);
}
```

动态分配：

```c
char  buffer[1005];
char* ptr[10005]; //所谓的 指针数组

for (int i = 0; i < 10000; i++) {
    fgets(buffer, 1005, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    //前面两行只是读取，在buaaoj上可以用gets代替
    ptr[i] = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
    //用多少拿多少
    strcpy(ptr[i], buffer);
}

// ......

for (int i = 0; i < 10000; i++) {
    free(ptr[i]); //有借有还
}
```

## float比较

如果真忘了就直接复制下面的。。

```c
#define eps 1e-8
int XGreaterThanY(double x,double y){
 return x-y>eps;// 正得够多 → x > y
}
int XLessThanY(double x,double y){
 return x-y<-eps;// 负得够多 → x < y
}
int XEqualToY(double x,double y){
 return fabs(x-y)<eps;// 接近 0 → 相等
}
```

使用例：

```c
if(XGreaterThanY(a,b)){
    //do something
}
if(!XEqualToY(c,d)){
    //do something
}
```

## qsort()的cmp()函数指南

### 基本语法

```c
typedef ... My_type;
int cmp(const void*p1,const void*p2){
    My_type* pp1 = (My_type*)p1; //pp1 pp2为中间变量，便于访问
    My_type* pp2 = (My_type*)p2; //否则后面每个指针都要写成((My_type*)p1)
    
    //后面利用pp1和pp2手写比较规则，支持多字段排序。
}
```

### 原理&注意事项

`cmp()`返回值为`int`。主要看正负，若返回负值，`*p1`放在`*p2`前。

偷懒写法 `return pp1->a - pp2->a;`刚好就是把小的排在前面
但是这么写要注意：

1.两个极端数相减超范围

2.两个浮点数相减之差小于1会return 0;因为返回值是int而不是double

一般都是`if(pp1->a < pp2->a) return -1;`
（如果是浮点数比较，自己根据规则改一下）

## 排序后去重输出

例题：对已经排好序的数组，去除重复元素并输出。

如 `arr[] = {1,1,2,2,2,3,3,4,5};`

输出`1 2 3 4 5`

解法1：常规

```c
// 先特判开头，然后把不同的全打印出来。
#include <stdio.h>
int arr[] = {1, 1, 2, 2, 2, 3, 3, 4, 5};
int main() {
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d", arr[0]);
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            printf(" %d", arr[i]);
        }
    }
    puts("");
}
```

解法2：双指针

```c
// 代码中的left right双指针，永远打印left，left随着right移动。
// 特判最后一个
#include <stdio.h>
int arr[] = {1,1,2,2,2,3,3,4,5};
int main() {
    int left = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int right = 0; right < n; right++) {
        if (arr[left] != arr[right]) {
            printf("%d ", arr[left]);
            left = right;
        }
    }
    printf("%d\n", arr[n - 1]);
}
```

## 常见WA

1. `scanf("%d",&n)`读取单行的数字后，如果再用`fgets()`/`gets()`，数字末尾有个`'\n'`要用`getchar()`吃掉，不然接下来的字符串读到的是`'\n'`，如果用上述方法去掉`'\n'`就只能得到空字符串。
2. 求一个数组的最大值，不宜初始化`int max = 0`,应该是`int max = arr[0]`。如果数组都是负的，前者不会输出任何东西。。。
3. 写`cmp()`函数的时候不要偷懒，浮点数作返回值不可预测：写`return a-b;`如果`a-b`是`0.9`那就判成相等了。。。
4. 看好数据范围，有的`int`相乘会超出`int`。必要的时候需要强制类型转换。

```c
 int a,b;
 a=2147483647;
 b=2;
 long long c,d;
 c=a+b;
 d=a*b;
 printf("%lld %lld\n",c,d);
 //错误，输出-2147483647 -2
 c=(long long)a+b;
 d=(long long)a*b;
 printf("%lld %lld\n",c,d);
 //正确，输出2147483649 4294967294
```

## 比较无聊的东西

1. `No` / `N0` / `NO` 诸如此类
2. 16进制可以4按四个bit为单位操作。如 `x & 0xFFFF00FF`(如果要用union访问内存的话，涉及计算机的小端储存)
