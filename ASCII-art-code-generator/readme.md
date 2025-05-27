# ASCII字符画 程序生成器
功能：给定字符画，自动转义，生成画出字符画的c代码
使用步骤：
0. vscode工作目录(ctrl+K ctrl+O)打开这个文件夹，ctrl+shift+` 呼出终端
1. 在`in.txt`里面粘贴字符画并保存
2. 终端输入 `gcc replace.c -o replace`
3. 终端输入 `./replace < in.txt > out.c`
4. `out.c`即为所需c代码