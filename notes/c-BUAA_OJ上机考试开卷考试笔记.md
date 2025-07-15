# Fauci自用的开卷考试笔记

## 常见WA

1. 全局数组开大一点
2. 十年OI一场空，不开`longlong`见祖宗（不过我不是OIer）
3. `getchar()`吃空字符串

## C语言程设部分

### 基本调试 (linux环境)

EOF - `ctrl+d`

重定向 - `./main < in.txt > out.txt`

### 自己的编译器上面用gets()

> 可以改编译选项，比如说用回`C89`，但是没啥必要，新标准废除了`gets()`，有的比赛也用的新标准。这里就跟着新标准走。

判断字符串相等用`strcmp(str1,str2) == 0`

```c
#include<string.h>
#include<stdio.h>
void my_gets(char*s,int limit){
    fgets(s,limit,stdin);
    s[strcspn(s,"\n")] = '\0';
}
// int main(){
//     char str[100];
//     my_gets(str,100);
//     puts(str);
// }
```

多行读取只好手写了，用下面的。

```c
#include<string.h>
#include<stdio.h>
char str[1005];
int main(){
    while(fgets(str, 1005, stdin)!=NULL){
        str[strcspn(str, "\n")] = '\0';
        ...
    }
}
```

### 基础数学函数

```c
int gcd(int a,int b) {
 return b?gcd(b,a%b):a;
}
```

```c
int lcm(int a,int b) {
 return((a/gcd(a,b))*b);
}
```

```c
int isPrime(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return 0; 
    }
    return 1;
}
```

分解质因数：

```c
void primeFactors(int n) // 分解质因数，可以引入数组来进行进一步运算
{
    while (n % 2 == 0)
    {
        printf("%d ", 2);
        n = n / 2;
    }
    for (int i = 3; i*i<=(n); i = i + 2)
        while (n % i == 0)
        {
            printf("%d ", i);
            n = n / i;
        }
    if (n > 2) // 不可删除
        printf("%d ", n);
}
```

```c
int max(int a, int b) {
    return a >= b ? a : b;
}
```

```c
int min(int a, int b) {
    return a <= b ? a : b;
}
```

### 反转整数（不考虑溢出）

> 如果想试图反转`2147483647`，要么用`longlong`要么用字符串处理

```c
int reserve(int num) {
    int ret = 0;
    while(num) {
        ret = ret * 10 + num % 10;
        num /= 10;
    }
    return ret;
}
```

### 快读

批注： f 表示正负号，x 是和。

**核心算法**：每读入一个(有效的) ch，`x = x * 10 + (ch - '0');`

```c
int fastReadInt() {
    int x = 0, f = 1;
    char ch = getchar(); //吃回车
    // 判断是否为负号
    if (ch == '-') {
        f = -1;
        ch = getchar();
    }
    // 读取数字字符并转换为整数
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * f;
}
```

### 字符串的动态内存分配

例题：读取并存储`10,000`个字符串，每个长度不超过`1,000`。但总字符数不超过`200,000`(即200KB内存)

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

### float比较

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

### 排序后去重输出

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

### 日期处理

```c
// 返回值为 0-6 ，0 表示星期日，1 表示星期一
int getWeekday(int y,int m,int d) {
    int c,w;
    if(m<3) {
        y++;
        m+=12;
    }
    c=y/100;
    y%=100;
    w=(y+y/4+c/4-2*c+(26*(m+1))/10+d-1)%7;
    if(w<0) {
        w+=7;
    }
    return w;
}
```

```c
int isLeap(int y) {
    return(y%4==0)&&(y%100!=0)||(y%400==0);
}
```

```c
int getDaysOfMonth(int y,int m) {
    int days=0;
    switch(m) {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            days=31;
            break;
        case 4:case 6:case 9:case 11:
            days=30;
            break;
        case 2:
            days=isLeap(y)?29:28;
            break;
    }
    return days;
}
```

### 二分查找

直接查key

```c
int binary_search(int arr[], int key, int l, int r) {
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
```

第一个比key小的数

```c
int binary_search_floor(int arr[], int key, int l, int r) {
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] < key) {
            ans = mid;          // 先记录当前候选答案
            l = mid + 1;        // 继续向右找更大的符合条件的值
        } else {
            r = mid - 1;        // 不满足条件，向左缩范围
        }
    }
    return ans;
}
```

## DS部分

> 我自学DS刷题高度依赖c++的stl库，一直用现成的`#include<stack>` `#include<queue>`，还有`vector`和`unordered_map`什么的。为了适应buaa风格的oj，在这列出了栈和队的基本操作。

### 栈

> 维护一个数组和top指针即可。
>
> `my_stack[]` 是栈数组，`top` 是栈顶指针，初始为 `-1`，`Max_size` 是栈的最大容量。

| 操作     | 代码实现             |
|----------|----------------------|
| push     | `my_stack[++top]`    |
| pop      | `top--`              |
| top      | `my_stack[top]`      |
| is_empty | `top == -1`          |
| is_full  | `top == Max_size-1`  |

### 队列

> 使用数组维护队列，有两个指针：`front` 和 `rear`。  
>
> 初始时 `front = 0`，`rear = -1`，`my_queue[]` 是队列数组，`Max_size` 是最大容量。
>
> 广度优先搜索直接用 `while(rear >= front){...}`

| 操作       | 代码实现                     |
|------------|------------------------------|
| enqueue    | `my_queue[++rear] = x;`      |
| dequeue    | `front++`                    |
| front_elem | `my_queue[front]`            |
| is_empty   | `front > rear`               |
| is_full    | `rear == Max_size - 1`       |
