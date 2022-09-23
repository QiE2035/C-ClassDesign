本程序有如下内容:
1. bdpq小游戏
    原创小游戏
    移动光标，更改字母
    每一次更改都会将同行同列的字母更改
    将所有字母变成同一个即可通关
2. 进制转换器
    十进制转其它进制
    支持最高 36 进制
    支持转换为负进制
3. Bad Apple
    "有色差的地方就有《Bad Apple》"
    2009 年知名黑白剪影动画《Bad Apple》的字符画
    https://www.bilibili.com/video/BV1xx411c79H
    使用前请先将 frame.rar 解压
    部分来源于互联网

仅可在 Windows 下使用
(理论上兼容 Wine)

开发环境使用 Visual Studio Code
编译使用 w64devkit MinGW GCC
版本管理使用 Git
理论上兼容 VC6, Dev-C++

编译指令
gcc bdpq.c badapple.c scale.c main.c -o main -lwinmm