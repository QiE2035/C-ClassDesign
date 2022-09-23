/*
    进制转换器
    十进制转其它进制
    支持最高 36 进制
    支持转换为负进制
    2021.12.26
 */

#include <stdio.h>
#include <stdlib.h>

// 子函数声明
void conv(long in, short base); // 转换

// 模块主函数
void scale()
{
    long in;    // 输入数字 超长整型用以支持更大的数字
    short base; // 目标进制

    // 主循环
    while (1)
    {
        system("cls"); // 清屏

        // 打印提示
        puts("\n\n\n\t 进制转换器");
        puts("\t 最大36进制");
        puts("\t 可为负进制");
        puts("\t 输入0退出");
        puts("\t ----------\n\n\n");

        // 输入数字
        printf("    请输入要转换的数字:");
        scanf("%ld", &in);
        getchar(); // 清除回车

        // 输入0则退出
        if (!in)
        {
            break;
        }

        // 输入进制
        printf("    请输入要转换的进制:");
        scanf("%hd", &base);
        getchar(); // 清除回车

        // 进制是否合法
        if (!base || abs(base) == 1 || abs(base) > 36)
        {
            printf("    进制不能为%d\n", base);
        }
        else
        {
            // 转换
            printf("    转换的结果为:");
            conv(in, base);
            printf("\n    ");
        }

        system("pause"); // 暂停
    }
}

// 转换函数
void conv(long in, short base)
{
    char bit;

    // 为0直接跳出
    if (in == 0)
    {
        return;
    }

    // 处理进制位
    bit = in % base;
    if (bit < 0)
    {
        bit -= base; // 转为正数
        in += base;
    }
    if (bit >= 10)
    {
        bit += 'A' - 10; // 大于9的用字母
    }
    else
    {
        bit += '0'; // 转换成对应字符
    }

    conv(in / base, base); // 递归 后计算先输出

    putchar(bit);
}