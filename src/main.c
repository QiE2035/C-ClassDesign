/*
    主菜单
    2021.12.26
 */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// 子模块声明
void bdpq();     // bdpq小游戏
void scale();    // 进制转换
void badapple(); // Bad Apple

// 子函数声明
void print_menu(); // 打印菜单
char proc_in();    // 处理输入
void ba_hint();    // Bad Apple 提示

// 主函数
int main()
{
    system("chcp 65001");
    system("color f0"); //设置白底黑字

    // 主循环
    while (1)
    {
        // 设置窗口大小
        system("mode con cols=38 lines=28");
        // 清屏
        system("cls");
        // 打印菜单
        print_menu();
        // 处理输入
        if (proc_in())
        {
            break;
        }
    }

    return 0;
}

// 处理输入
char proc_in()
{
    // 处理输入
    switch (_getch())
    {
    case 'q': // 退出
        return 1;
    case '1': // bdpq小游戏
        bdpq();
        break;
    case '2': // 进制转换
        scale();
        break;
    case '3': // Bad Apple
        ba_hint();
        badapple();
        break;
    }

    return 0;
}

// 打印菜单
void print_menu()
{
    puts("\n\n\n\t 期末 C语言 课程设计");
    puts("\t --------------------");
    puts("\t [1] bdpq小游戏");
    puts("\t [2] 进制转换器");
    puts("\t [3] Bad Apple");
    puts("\t [q] 退出");
}

// Bad Apple 提示
void ba_hint()
{

    system("cls"); // 清屏

    // 提示需要外部资源
    puts("\n\n\n\t 请确认当前文件夹中");
    puts("\t 包含 BadApple.wav");
    printf("\t frame.rar 已经解压\n\n\n\t ");

    system("pause"); // 暂停
}
