# BUAA_OJ 各种坑

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

```c
char str[Maxsize];
fgets(str,Maxsize,stdin);
str[strcspn(str, "\n")] = '\0';
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
