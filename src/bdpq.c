/*
    bdpq小游戏
    原创小游戏
    移动光标，更改字母
    每一次更改都会将同行同列的字母更改
    将所有字母变成同一个即可通关
    2021.12.26
 */

#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define MAP_SIZE 3    // 地图大小
#define WHITE_BLACK 0 // 白底黑字
#define BLACK_WHITE 1 // 黑底白字

// 全局变量
char map[MAP_SIZE][MAP_SIZE], // 地图数组
    win = 1;                  // 是否完成
struct                        // 当前单元
{
    char x;
    char y;
} pos = {0, 0};

// 子函数声明
void main_loop();           // 主要循环
void print_map();           // 输出地图
void set_color(char color); // 设置颜色
char in_key();              // 输入处理
void change_char();         // 改变字母
void is_win();              // 是否完成
void refresh_map();         // 刷新地图
void print_fwk();           // 打印外框
void print_hint();          // 打印提示

// 模块主函数
void bdpq()
{
    srand((unsigned int)malloc(0)); // 设置随机种
    refresh_map();                  // 初始化地图
    main_loop();                    // 进入主循环
}

// 主循环
void main_loop()
{
    while (1)
    {
        set_color(WHITE_BLACK);

        system("cls"); // 清屏

        // 打印内容
        puts("\n\n\n\t bdpq小游戏 \n");
        print_fwk();
        print_map();
        print_fwk();
        print_hint();

        // 判定输入
        if (in_key())
        {
            break;
        }

        is_win(); // 判定是否完成
    }
}

// 输出地图
void print_map()
{
    static const char bdpq[4] = "bdpq"; // 字母集

    char i, j; // 遍历索引

    for (i = 0; i < MAP_SIZE; i++)
    {
        printf("\t  | ");
        for (j = 0; j < MAP_SIZE; j++)
        {
            if (i == pos.y && j == pos.x)
            {
                set_color(BLACK_WHITE); // 被选中单元设置黑底白字
            }
            printf("%c ", bdpq[map[i][j]]); // 输出单元
            set_color(WHITE_BLACK);
        }
        puts("|");
    }
}

// 设置颜色
void set_color(char color)
{
    if (color == WHITE_BLACK) // 白底黑字
    {
        SetConsoleTextAttribute(
            GetStdHandle(STD_OUTPUT_HANDLE),
            BACKGROUND_INTENSITY |
                BACKGROUND_GREEN |
                BACKGROUND_RED |
                BACKGROUND_BLUE);
    }
    else if (color == BLACK_WHITE) // 黑底白字
    {
        SetConsoleTextAttribute(
            GetStdHandle(STD_OUTPUT_HANDLE),
            FOREGROUND_INTENSITY |
                FOREGROUND_GREEN |
                FOREGROUND_RED |
                FOREGROUND_BLUE);
    }
}

// 输入处理
char in_key()
{
    switch (_getch())
    {
    case 'r': // 刷新地图
        refresh_map(map);
        break;
    case 'q': // 退出游戏
        return 1;
    case 'w': // 向上移动
        pos.y = (--pos.y + MAP_SIZE) % MAP_SIZE;
        break;
    case 'a': // 向左移动
        pos.x = (--pos.x + MAP_SIZE) % MAP_SIZE;
        break;
    case 's': // 向下移动
        pos.y = ++pos.y % MAP_SIZE;
        break;
    case 'd': // 向右移动
        pos.x = ++pos.x % MAP_SIZE;
        break;
    case 'e': // 改变字母
        change_char();
        break;
    }

    return 0;
}

// 改变字母
void change_char()
{
    char i, j; // 遍历索引

    for (i = 0; i < MAP_SIZE; i++)
    {
        for (j = 0; j < MAP_SIZE; j++)
        {
            // 被选中单元同行列字母集索引+1
            if (!win && (i == pos.y || j == pos.x))
            {
                map[i][j] = ++map[i][j] % 4;
            }
        }
    }
}

// 判定是否完成
void is_win()
{
    char i, j,            // 遍历索引
        last = map[0][0]; // 上一个单元

    win = 1;

    for (i = 0; i < MAP_SIZE; i++)
    {
        for (j = 0; j < MAP_SIZE; j++)
        {
            if (map[i][j] != last)
            {
                win = 0; // 设置未完成
            }
            last = map[i][j];
        }
    }
}

// 刷新地图
void refresh_map()
{
    char i, j; // 遍历索引

    win = 0;

    for (i = 0; i < MAP_SIZE; i++)
    {
        for (j = 0; j < MAP_SIZE; j++)
        {
            map[i][j] = rand() % 4; // 随机字母
        }
    }
}

// 打印外框
void print_fwk()
{
    char i; // 遍历索引

    printf("\t  +");
    for (i = 0; i < MAP_SIZE; i++)
    {
        printf("--");
    }
    putchar('-');
    puts("+");
}

// 打印提示
void print_hint()
{
    puts("\n\t 将所有字母变 \n\t 同一个即通关 \n");
    puts("\t [e] 改变字母");
    puts("\t [w] 向上移动");
    puts("\t [a] 向左移动");
    puts("\t [s] 向下移动");
    puts("\t [d] 向右移动");
    puts("\t [r] 刷新地图");
    puts("\t [q] 退出游戏");

    if (win)
    {
        puts("\n\t 你赢了!");
    }
}