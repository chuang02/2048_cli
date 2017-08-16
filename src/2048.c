// 2048 GAME V6
// BY BTS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32 //Linux platform
#include <conio.h>
#include <windows.h>
#else  
#include <termios.h>
#include <unistd.h>
#endif

int num[16];
int num_v[16];//Compairation
char direct;
int check();
int signal;
int score;

char get1char(void)
{
#ifdef _WIN32
    // Do nothing
#else   
    struct termios stored_settings;
    struct termios new_settings;
    tcgetattr (0, &stored_settings);
    new_settings = stored_settings;
    new_settings.c_lflag &= (~ICANON);
    new_settings.c_cc[VTIME] = 0;
    new_settings.c_cc[VMIN] = 1;
    tcsetattr (0, TCSANOW, &new_settings);
#endif
    int ret = 0;
    char c;
    int express;
#ifdef _WIN32
    c = getch();
#else 
    c = getchar();
    putchar('\b'); 
#endif
    printf("[%c]\n", c);
    //system("sleep 0.2");
#ifdef _WIN32  
    // Do nothing  
#else  
    tcsetattr (0, TCSANOW, &stored_settings);
#endif
    return c;
}  

int rnd(int x)
{
    int judge;
    judge = rand() % 10 + 1;
    if(judge < 8) num[x] = 2;
    if(judge >= 8) num[x] = 4;
    return 0;
}

void draw_canvas()
{
#ifdef _WIN32
    system("cls");//clear sreen
#else
    system("clear");//clear screen
#endif
    int express;
    express = 0;
    printf("\033[m");
    printf("2048 CLI V6\n");
    printf("Built by Coder-BTS\n\n");
    printf("Use <HJKL> | E-Exit | R-Reset\n\n");
    printf("\033[0;33m");
    printf("-----------------------------\n");
    printf("|      |      |      |      |\n");
    printf("|");
    do
    {
        if(num[express] == 2) printf(" \033[m%4d\033[0;33m |",num[express]);
        if(num[express] == 4) printf(" \033[0;32;32m%4d\033[0;33m |",num[express]);
        if(num[express] == 8) printf(" \033[1;32m%4d\033[0;33m |",num[express]);
        if(num[express] == 16) printf(" \033[0;32;34m%4d\033[0;33m |",num[express]);
        if(num[express] == 32) printf(" \033[0;35m%4d\033[0;33m |",num[express]);
        if(num[express] == 64) printf(" \033[1;35m%4d\033[0;33m |",num[express]);
        if(num[express] == 128) printf(" \033[0;32;31m%4d\033[0;33m |",num[express]);
        if(num[express] == 256) printf(" \033[1;31m%4d\033[0;33m |",num[express]);
        if(num[express] == 512) printf(" \033[0;33m%4d\033[0;33m |",num[express]);
        if(num[express] == 1024) printf(" \033[1;30m%4d\033[0;33m |",num[express]);
        if(num[express] == 2048) printf(" \033[0;37m%4d\033[0;33m |",num[express]);
        if(num[express] == 4096) printf(" \033[1;34m%4d\033[0;33m |",num[express]);
        if(num[express] == 0) printf("      |",num[express]);
        express++;
    }while(express < 4);
    printf("\n|      |      |      |      |\n");
    printf("-----------------------------\n");
    printf("|      |      |      |      |\n");
    printf("|");
    do
    {
        if(num[express] == 2) printf(" \033[m%4d\033[0;33m |",num[express]);
        if(num[express] == 4) printf(" \033[0;32;32m%4d\033[0;33m |",num[express]);
        if(num[express] == 8) printf(" \033[1;32m%4d\033[0;33m |",num[express]);
        if(num[express] == 16) printf(" \033[0;32;34m%4d\033[0;33m |",num[express]);
        if(num[express] == 32) printf(" \033[0;35m%4d\033[0;33m |",num[express]);
        if(num[express] == 64) printf(" \033[1;35m%4d\033[0;33m |",num[express]);
        if(num[express] == 128) printf(" \033[0;32;31m%4d\033[0;33m |",num[express]);
        if(num[express] == 256) printf(" \033[1;31m%4d\033[0;33m |",num[express]);
        if(num[express] == 512) printf(" \033[0;33m%4d\033[0;33m |",num[express]);
        if(num[express] == 1024) printf(" \033[1;30m%4d\033[0;33m |",num[express]);
        if(num[express] == 2048) printf(" \033[0;37m%4d\033[0;33m |",num[express]);
        if(num[express] == 4096) printf(" \033[1;34m%4d\033[0;33m |",num[express]);
        if(num[express] == 0) printf("      |",num[express]);
        express++;
    }while(express < 8);
    printf("\n|      |      |      |      |\n");
    printf("-----------------------------\n");
    printf("|      |      |      |      |\n");
    printf("|");
    do
    {
        if(num[express] == 2) printf(" \033[m%4d\033[0;33m |",num[express]);
        if(num[express] == 4) printf(" \033[0;32;32m%4d\033[0;33m |",num[express]);
        if(num[express] == 8) printf(" \033[1;32m%4d\033[0;33m |",num[express]);
        if(num[express] == 16) printf(" \033[0;32;34m%4d\033[0;33m |",num[express]);
        if(num[express] == 32) printf(" \033[0;35m%4d\033[0;33m |",num[express]);
        if(num[express] == 64) printf(" \033[1;35m%4d\033[0;33m |",num[express]);
        if(num[express] == 128) printf(" \033[0;32;31m%4d\033[0;33m |",num[express]);
        if(num[express] == 256) printf(" \033[1;31m%4d\033[0;33m |",num[express]);
        if(num[express] == 512) printf(" \033[0;33m%4d\033[0;33m |",num[express]);
        if(num[express] == 1024) printf(" \033[1;30m%4d\033[0;33m |",num[express]);
        if(num[express] == 2048) printf(" \033[0;37m%4d\033[0;33m |",num[express]);
        if(num[express] == 4096) printf(" \033[1;34m%4d\033[0;33m |",num[express]);
        if(num[express] == 0) printf("      |",num[express]);
        express++;
    }while(express < 12);
    printf("\n|      |      |      |      |\n");
    printf("-----------------------------\n");
    printf("|      |      |      |      |\n");
    printf("|");
    do
    {
        if(num[express] == 2) printf(" \033[m%4d\033[0;33m |",num[express]);
        if(num[express] == 4) printf(" \033[0;32;32m%4d\033[0;33m |",num[express]);
        if(num[express] == 8) printf(" \033[1;32m%4d\033[0;33m |",num[express]);
        if(num[express] == 16) printf(" \033[0;32;34m%4d\033[0;33m |",num[express]);
        if(num[express] == 32) printf(" \033[0;35m%4d\033[0;33m |",num[express]);
        if(num[express] == 64) printf(" \033[1;35m%4d\033[0;33m |",num[express]);
        if(num[express] == 128) printf(" \033[0;32;31m%4d\033[0;33m |",num[express]);
        if(num[express] == 256) printf(" \033[1;31m%4d\033[0;33m |",num[express]);
        if(num[express] == 512) printf(" \033[0;33m%4d\033[0;33m |",num[express]);
        if(num[express] == 1024) printf(" \033[1;30m%4d\033[0;33m |",num[express]);
        if(num[express] == 2048) printf(" \033[0;37m%4d\033[0;33m |",num[express]);
        if(num[express] == 4096) printf(" \033[1;34m%4d\033[0;33m |",num[express]);
        if(num[express] == 0) printf("      |",num[express]);
        express++;
    }while(express < 16);
    printf("\n|      |      |      |      |\n");
    printf("-----------------------------\n\033[m");
    printf(">>> Score:   %d <<<\n",score);
    if(check() == 1)
    {
        printf("\n\nCan you make a forward move?\n");
    }
    printf("\033[m");
}

void bakup()
{
    int k;
    for(k = 0;k < 16;k++)
    {
        num_v[k] = num[k];//bakup .old data
    }
}

int compair()
{
    int k;
    for(k = 0;k < 16;k++)
    {
        if(num_v[k] != num[k]) return 1;
    }
    return 0;
}

int check()
{
    int k;
    for(k = 0;k < 16;k++)
    {
        if(num[k] == 0) return 0;
    }
    return 1;
}

int main()
{
    int k;
    int j;
    int new_block;
start:
    for(k = 0;k < 16;k++)//init void
    {
        num[k] = 0;
    }
    srand(time(NULL));
    score = 0;
    rnd(11);//init
    rnd(14);
    rnd(15);
    for(k = 0;k < 16;k++)
    {
        num_v[k] = num[k];//bakup .old data
    }
get_direct: 
    //system("clear");//clear screen
    draw_canvas();
    //system("stty -icanon");
    direct = get1char();
    //printf("%c",direct);
    signal = 0;
    bakup();
    if(direct == 'h' || direct == 'H' || direct == 68) goto to_left;
    if(direct == 'j' || direct == 'J' || direct == 66) goto to_down;
    if(direct == 'k' || direct == 'K' || direct == 65) goto to_up;
    if(direct == 'l' || direct == 'L' || direct == 67) goto to_right;
    if(direct == 'r' || direct == 'R') goto start;
    if(direct == 'e' || direct == 'E') 
    {
        system("clear");
        exit(1);
    }
    goto get_direct; 
to_right: 
    for(k = 0;k <= 12;k += 4)
    {
        for(j = k + 3;j >= k + 1;j--)
        {
            if(num[j] == 0)
            {
                num[j] = num[j-1];
                num[j-1] = 0;
            }
            if(num[j] != 0)
            {
                if(num[j] == num[j-1])
                {
                    num[j] = num[j] * 2;
                    score = score + num[j];
                    num[j-1] = 0;
                }
            }
        }
    }
    if(compair() == 0) goto get_wait;
    bakup();
    signal = 1;
    goto to_right;
to_left:
    for(k = 0;k <= 12;k += 4)
    {
        for(j = k;j <= k + 2;j++)
        {
            if(num[j] == 0)
            {
                num[j] = num[j+1];
                num[j+1] = 0;
            }
            if(num[j] != 0)
            {
                if(num[j] == num[j+1])
                {
                    num[j] = num[j] * 2;
                    score = score + num[j];
                    num[j+1] = 0;
                }
            }
        }
    }
    if(compair() == 0) goto get_wait;
    bakup();
    signal = 1;
    goto to_left;
to_up:
    for(k = 0; k <= 3;k++)
    {
        for(j = k;j <= 11;j += 4)
        {
            if(num[j] == 0)
            {
                num[j] = num[j+4];
                num[j+4] = 0;
            }
            if(num[j] != 0)
            {
                if(num[j] == num[j+4])
                {
                    num[j] = num[j] * 2;
                    score = score + num[j];
                    num[j+4] = 0;
                }
            }
        }
    }
    if(compair() == 0) goto get_wait;
    bakup();
    signal = 1;
    goto to_up;
to_down:
    for(k = 12;k <= 15;k++)
    {
        for(j = k;j >= 4;j -= 4)
        {
            if(num[j] == 0)
            {
                num[j] = num[j-4];
                num[j-4] = 0;
            }
            if(num[j] != 0)
            {
                if(num[j] == num[j-4])
                {
                    num[j] = num[j] * 2;
                    score = score + num[j];
                    num[j-4] = 0;
                }
            }
        }
    }
    if(compair() == 0) goto get_wait;
    bakup();
    signal = 1;
    goto to_down;
get_wait:
    draw_canvas();
    if(signal == 0) goto get_direct;
    if(check() == 1) goto get_direct;
    new_block = rand() % 16;
    if(num[new_block] != 0) goto get_wait;
#ifdef _WIN32
    sleep(100);
#else
    system("sleep 0.1");
#endif
    rnd(new_block);
    goto get_direct;
quit_g:
    exit(1);
    return 0;
}
