// 2048 GAME V2
// BY BTS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>

int num[16];
int num_v[16];//Compairation
char direct;

char get1char(void)
{
    struct termios stored_settings;
    struct termios new_settings;
    tcgetattr (0, &stored_settings);
    new_settings = stored_settings;
    new_settings.c_lflag &= (~ICANON);
    new_settings.c_cc[VTIME] = 0;
    new_settings.c_cc[VMIN] = 1;
    tcsetattr (0, TCSANOW, &new_settings);
    int ret = 0;
    char c;
    int express;
    c = getchar();
    putchar('\b'); 
    printf("You made a move:  [%c]\n", c);
    system("sleep 0.4");
    tcsetattr (0, TCSANOW, &stored_settings);

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
    system("clear");//clear sreen
    printf("-----------\n");
    printf("2048 CLI V2\n\n");
    printf("Built by Coder-BTS\n\n\n");
    printf("Use <HJKL> | E-Exit | R-Reset\n\n");
    printf("-----------------------------\n");
    printf("|      |      |      |      |\n");
    printf("| %4d | %4d | %4d | %4d |\n",num[0],num[1],num[2],num[3]);
    printf("|      |      |      |      |\n");
    printf("-----------------------------\n");
    printf("|      |      |      |      |\n");
    printf("| %4d | %4d | %4d | %4d |\n",num[4],num[5],num[6],num[7]);
    printf("|      |      |      |      |\n");
    printf("-----------------------------\n");
    printf("|      |      |      |      |\n");
    printf("| %4d | %4d | %4d | %4d |\n",num[8],num[9],num[10],num[11]);
    printf("|      |      |      |      |\n");
    printf("-----------------------------\n");
    printf("|      |      |      |      |\n");
    printf("| %4d | %4d | %4d | %4d |\n",num[12],num[13],num[14],num[15]);
    printf("|      |      |      |      |\n");
    printf("-----------------------------\n");
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
    if(direct == 'h' || direct == 'H') goto to_left;
    if(direct == 'j' || direct == 'J') goto to_down;
    if(direct == 'k' || direct == 'K') goto to_up;
    if(direct == 'l' || direct == 'L') goto to_right;
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
                    num[j-1] = 0;
                }
            }
        }
    }
    if(compair() == 0) goto get_wait;
    bakup();
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
                    num[j+1] = 0;
                }
            }
        }
    }
    if(compair() == 0) goto get_wait;
    bakup();
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
                    num[j+4] = 0;
                }
            }
        }
    }
    if(compair() == 0) goto get_wait;
    bakup();
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
                    num[j-4] = 0;
                }
            }
        }
    }
    if(compair() == 0) goto get_wait;
    bakup();
    goto to_down;
get_wait:
    new_block = rand() % 16;
    if(num[new_block] != 0) goto get_wait;
    rnd(new_block);
    goto get_direct;
quit_g:
    exit(1);
    return 0;
}
