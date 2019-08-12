#include"Tetris.h"

#define FrameX 13   		//游戏窗口左上角的X轴坐标
#define FrameY 3   			//游戏窗口左上角的Y轴坐标
#define Frame_height  20 	//游戏窗口的高度
#define Frame_width   18 	//游戏窗口的宽度 

struct Tetris
{
	int number;					//方块个数	
	int score;					//成绩
	int speed;					//速度
	int level;					//等级
	int x;
	int y;
	int flag;					//当前方块序号
	int next;					//下一个方块序号
};

HANDLE hOut;

int n;
int i, j, Temp, Temp1, Temp2;   //Temp,Temp1,Temp2用来存放方块变换的过程值
int a[80][80] = { 0 };			//用来标记游戏屏幕图案，0表示没有方块，1表示有方块，2表示边框
int b[4];						//用来存放方块的位置，因为每个俄罗斯方块都是由4个小方块组成，所以创建大小为4的数组
void gotoxy(int x,int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int color(int n)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
	return 0;
}

void title()
{
	color(15);
	gotoxy(24, 3);
	printf("   俄  罗  斯  方  块   \n");
	color(11);
	gotoxy(18, 5);
	printf("■");
	gotoxy(18, 6);
	printf("■■");
	gotoxy(18, 7);
	printf("■");

	color(14);
	gotoxy(26, 6);
	printf("■■");
	gotoxy(28, 7);
	printf("■■");//

	color(10);
	gotoxy(36, 6);
	printf("■■");
	gotoxy(36, 7);
	printf("■■");

	color(13);
	gotoxy(45, 5);
	printf("■");
	gotoxy(45, 6);
	printf("■");
	gotoxy(45, 7);
	printf("■");
	gotoxy(45, 8);
	printf("■");

	color(12);
	gotoxy(56, 6);
	printf("■");//
	gotoxy(52, 7);
	printf("■■■");
}

void welcom()
{
	color(12);
	gotoxy(25, 12);
	printf("1.开始游戏");
	gotoxy(40, 12);
	printf("2.按键说明");
	gotoxy(25, 17);
	printf("3.游戏规则");
	gotoxy(40, 17);
	printf("4.退出");
	gotoxy(21, 22);
	color(3);
	printf("请选择[1 2 3 4]:");
	scanf_s("%d", &n);    //输入选项
	switch (n)
	{
	case 1:
		system("cls");
		DrwaGameframe(); 	//制作游戏窗口
		Gameplay(); 		//开始游戏
		break;
	case 2:
		explation();      	//按键说明函数
		break;
	case 3:
		regulation();     	//游戏规则函数
		break;
	case 4:
		exit(0);		//关闭游戏函数
		break;
	}
}

void  DrwaGameframe()
{
	gotoxy(FrameX + Frame_width - 8, FrameY - 2);
	color(12);
	printf("俄 罗 斯 方 块");
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 7);
	color(14);
	printf("*** 下一个方块 ***");
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 13);
	printf("***  ***  ***  ***");
	color(13);
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 15);
	printf("↑：反转");
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 17);
	printf("空格：暂停");
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 19);
	printf("esc：退出");
	a[FrameX][FrameY + Frame_height] = 2;
	a[FrameX + 2 * Frame_width - 2][FrameY + Frame_height] = 2;
	
	for (int i = 2; i < 2 * Frame_width - 2; ++i)
	{
		gotoxy(FrameX + i, FrameY);
		printf("═");
	}
	
	for (int i = 2; i < 2 * Frame_width - 2; ++i)
	{
		gotoxy(FrameX + i, FrameY + Frame_height);
		printf("═");
		a[FrameX + i][FrameY + Frame_height] = 2;
	}

	for (int i = 1; i < Frame_height; i++)
	{
		gotoxy(FrameX, FrameY + i);
		printf("║");
		a[FrameX][FrameY + i] = 2;
	}
	
	for (int i = 1; i < Frame_height; i++)
	{
		gotoxy(FrameX + 2 * Frame_width - 2, FrameY + i);
		printf("║");
		a[FrameX + 2 * Frame_width - 2][FrameY + i] = 2;
	}
}

void MakeTetris(struct Tetris *tetris)
{
	a[tetris->x][tetris->y] = b[0];    //中心方块位置的图形状态
	switch (tetris->flag)      //共7大类，19种类型
	{
		case 1:         /*田字方块 ■■
								   □■  */
		{
			color(10);
			a[tetris->x][tetris->y - 1] = b[1];
			a[tetris->x + 2][tetris->y - 1] = b[2];
			a[tetris->x + 2][tetris->y] = b[3];
			break;
		}
		case 2:         /*直线方块 ■□■■*/
		{
			color(13);
			a[tetris->x - 2][tetris->y] = b[1];
			a[tetris->x + 2][tetris->y] = b[2];
			a[tetris->x + 4][tetris->y] = b[3];
			break;
		}
		case 3:         /*直线方块  ■
									■
									□
									■  */
		{
			color(13);
			a[tetris->x][tetris->y - 1] = b[1];
			a[tetris->x][tetris->y - 2] = b[2];
			a[tetris->x][tetris->y + 1] = b[3];
			break;
		}
		case 4:					  /*T字方块 ■□■
							   				  ■  */
		{
			color(11);
			a[tetris->x - 2][tetris->y] = b[1];
			a[tetris->x + 2][tetris->y] = b[2];
			a[tetris->x][tetris->y + 1] = b[3];
			break;
		}
		case 5:         /* 顺时针90°T字方块   ■
											 ■□
											   ■*/
		{
			color(11);
			a[tetris->x][tetris->y - 1] = b[1];
			a[tetris->x][tetris->y + 1] = b[2];
			a[tetris->x - 2][tetris->y] = b[3];
			break;
		}
		case 6:         /* 顺时针180°T字方块     ■
												■□■*/
		{
			color(11);
			a[tetris->x][tetris->y - 1] = b[1];
			a[tetris->x - 2][tetris->y] = b[2];
			a[tetris->x + 2][tetris->y] = b[3];
			break;
		}
		case 7:         /* 顺时针270°T字方块   ■
												□■
												■  */
		{
			color(11);
			a[tetris->x][tetris->y - 1] = b[1];
			a[tetris->x][tetris->y + 1] = b[2];
			a[tetris->x + 2][tetris->y] = b[3];
			break;
		}
		case 8:         /* Z字方块   ■□
									   ■■*/
		{
			color(14);
			a[tetris->x][tetris->y + 1] = b[1];
			a[tetris->x - 2][tetris->y] = b[2];
			a[tetris->x + 2][tetris->y + 1] = b[3];
			break;
		}
		case 9:         /* 顺时针Z字方块      ■
											■□
											■  */
		{
			color(14);
			a[tetris->x][tetris->y - 1] = b[1];
			a[tetris->x - 2][tetris->y] = b[2];
			a[tetris->x - 2][tetris->y + 1] = b[3];
			break;
		}
		case 10:        /* 反转Z字方块      ■■
										  ■□  */
		{
			color(14);
			a[tetris->x][tetris->y - 1] = b[1];
			a[tetris->x - 2][tetris->y - 1] = b[2];
			a[tetris->x + 2][tetris->y] = b[3];
			break;
		}
		case 11:        /* 顺时针Z字方块    ■
				                     		■□
											  ■  */
		{
			color(14);
			a[tetris->x][tetris->y + 1] = b[1];
			a[tetris->x - 2][tetris->y - 1] = b[2];
			a[tetris->x - 2][tetris->y] = b[3];
			break;
		}
		case 12:        /* 7字方块    ■■
										□
										■  */
		{
			color(12);
			a[tetris->x][tetris->y - 1] = b[1];
			a[tetris->x][tetris->y + 1] = b[2];
			a[tetris->x - 2][tetris->y - 1] = b[3];
			break;
		}
		case 13:        /* 顺时针90°7字方块        ■
												■□■*/
		{
			color(12);
			a[tetris->x - 2][tetris->y] = b[1];
			a[tetris->x + 2][tetris->y - 1] = b[2];
			a[tetris->x + 2][tetris->y] = b[3];
			break;
		}
		case 14:        /* 顺时针180°7字方块      ■
												   □
												   ■■  */
		{
			color(12);
			a[tetris->x][tetris->y - 1] = b[1];
			a[tetris->x][tetris->y + 1] = b[2];
			a[tetris->x + 2][tetris->y + 1] = b[3];
			break;
		}
		case 15:        /* 顺时针270°7字方块    ■□■
												 ■    */
		{
			color(12);
			a[tetris->x - 2][tetris->y] = b[1];
			a[tetris->x - 2][tetris->y + 1] = b[2];
			a[tetris->x + 2][tetris->y] = b[3];
			break;
		}
		case 16:        /* 反转7字方块    ■■
										  □
										  ■    */
		{
			color(12);
			a[tetris->x][tetris->y + 1] = b[1];
			a[tetris->x][tetris->y - 1] = b[2];
			a[tetris->x + 2][tetris->y - 1] = b[3];
			break;
		}
		case 17:        /* 顺时针转90°7字方块    ■□■
													  ■*/
		{
			color(12);
			a[tetris->x - 2][tetris->y] = b[1];
			a[tetris->x + 2][tetris->y + 1] = b[2];
			a[tetris->x + 2][tetris->y] = b[3];
			break;
		}
		case 18:        /* 顺时针转180°7字方块    ■
												   □
												 ■■    */
		{
			color(12);
			a[tetris->x][tetris->y - 1] = b[1];
			a[tetris->x][tetris->y + 1] = b[2];
			a[tetris->x - 2][tetris->y + 1] = b[3];
			break;
		}
		case 19:        /* 顺指针转270°7字方块    ■
												   ■□■*/
		{
			color(12);
			a[tetris->x - 2][tetris->y] = b[1];
			a[tetris->x - 2][tetris->y - 1] = b[2];
			a[tetris->x + 2][tetris->y] = b[3];
			break;
		}
	}
}

void PrintTetris(struct Tetris *tetris)
{
	for (i = 0; i<4; i++)
	{
		b[i] = 1;         				//数组b[4]的每个元素的值都为1
	}
	MakeTetris(tetris);      			//制作游戏窗口
	for (i = tetris->x - 2; i <= tetris->x + 4; i += 2)
	{
		for (j = tetris->y - 2; j <= tetris->y + 1; j++)
		{
			if (a[i][j] == 1 && j>FrameY)
			{
				gotoxy(i, j);
				printf("■");     //打印边框内的方块
			}
		}
	}
	//打印菜单信息
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 1);
	color(4);
	printf("level : ");
	color(12);
	printf(" %d", tetris->level);
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 3);
	color(4);
	printf("score : ");
	color(12);
	printf(" %d", tetris->score);
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 5);
	color(4);
	printf("speed : ");
	color(12);
	printf(" %dms", tetris->speed);
}

int ifMove(struct Tetris *tetris)   //判断该点是否可以移动
{
 	if(a[tetris->x][tetris->y]!=0)//当中心方块位置上有图案时，返回值为0，即不可移动
 	{
  		return 0;
 	}
 	else
 	{
  		if( 
   		( tetris->flag==1  && ( a[tetris->x][tetris->y-1]==0   &&
    	a[tetris->x+2][tetris->y-1]==0 && a[tetris->x+2][tetris->y]==0 ) ) ||
   		( tetris->flag==2  && ( a[tetris->x-2][tetris->y]==0   && 
    	a[tetris->x+2][tetris->y]==0 && a[tetris->x+4][tetris->y]==0 ) )   ||
   		( tetris->flag==3  && ( a[tetris->x][tetris->y-1]==0   &&
    	a[tetris->x][tetris->y-2]==0 && a[tetris->x][tetris->y+1]==0 ) )   ||
   		( tetris->flag==4  && ( a[tetris->x-2][tetris->y]==0   &&
    	a[tetris->x+2][tetris->y]==0 && a[tetris->x][tetris->y+1]==0 ) )   ||
   		( tetris->flag==5  && ( a[tetris->x][tetris->y-1]==0   &&
   		 a[tetris->x][tetris->y+1]==0 && a[tetris->x-2][tetris->y]==0 ) )   ||
   		( tetris->flag==6  && ( a[tetris->x][tetris->y-1]==0   &&
    	a[tetris->x-2][tetris->y]==0 && a[tetris->x+2][tetris->y]==0 ) )   ||
   		( tetris->flag==7  && ( a[tetris->x][tetris->y-1]==0   &&
    	a[tetris->x][tetris->y+1]==0 && a[tetris->x+2][tetris->y]==0 ) )   ||
   		( tetris->flag==8  && ( a[tetris->x][tetris->y+1]==0   &&
    	a[tetris->x-2][tetris->y]==0 && a[tetris->x+2][tetris->y+1]==0 ) ) ||
   		( tetris->flag==9  && ( a[tetris->x][tetris->y-1]==0   &&
    	a[tetris->x-2][tetris->y]==0 && a[tetris->x-2][tetris->y+1]==0 ) ) ||
   		( tetris->flag==10 && ( a[tetris->x][tetris->y-1]==0   &&
    	a[tetris->x-2][tetris->y-1]==0 && a[tetris->x+2][tetris->y]==0 ) ) ||
   		( tetris->flag==11 && ( a[tetris->x][tetris->y+1]==0   &&
    	a[tetris->x-2][tetris->y-1]==0 && a[tetris->x-2][tetris->y]==0 ) ) ||
   		( tetris->flag==12 && ( a[tetris->x][tetris->y-1]==0   &&
    	a[tetris->x][tetris->y+1]==0 && a[tetris->x-2][tetris->y-1]==0 ) ) ||
   		( tetris->flag==15 && ( a[tetris->x-2][tetris->y]==0   &&
    	a[tetris->x-2][tetris->y+1]==0 && a[tetris->x+2][tetris->y]==0 ) ) ||
   		( tetris->flag==14 && ( a[tetris->x][tetris->y-1]==0   &&
    	a[tetris->x][tetris->y+1]==0 && a[tetris->x+2][tetris->y+1]==0 ) ) ||
   		( tetris->flag==13 && ( a[tetris->x-2][tetris->y]==0   &&
    	a[tetris->x+2][tetris->y-1]==0 && a[tetris->x+2][tetris->y]==0 ) ) ||
   		( tetris->flag==16 && ( a[tetris->x][tetris->y+1]==0   &&
    	a[tetris->x][tetris->y-1]==0 && a[tetris->x+2][tetris->y-1]==0 ) ) ||
   		( tetris->flag==19 && ( a[tetris->x-2][tetris->y]==0   &&
    	a[tetris->x-2][tetris->y-1]==0 && a[tetris->x+2][tetris->y]==0 ) ) ||
   		( tetris->flag==18 && ( a[tetris->x][tetris->y-1]==0   &&
    	a[tetris->x][tetris->y+1]==0 && a[tetris->x-2][tetris->y+1]==0 ) ) ||
   		( tetris->flag==17 && ( a[tetris->x-2][tetris->y]==0   &&
    	a[tetris->x+2][tetris->y+1]==0 && a[tetris->x+2][tetris->y]==0 ) ) )
   		{
    		return 1;
   		}
	}
 	return 0;
}

void CleanTetris(struct Tetris *tetris)
{
	for (int i = 0; i < 4; ++i)
	{
		b[i] = 0;
	}
	MakeTetris(tetris);
	for (i = tetris->x - 2; i <= tetris->x + 4; i += 2)       //■X ■■  X为中心方块
	{
		for (j = tetris->y - 2; j <= tetris->y + 1; j++)
		{
			if (a[i][j] == 0 && j > FrameY)
			{
				gotoxy(i, j);
				printf(" ");
			}
		}
	}
}

void Flag(struct Tetris *tetris)
{
	tetris->number++;
	srand((int)time(NULL));
	if (tetris->number == 1)
	{
		tetris->flag = rand() % 19 + 1;
	}
	tetris->next = rand() % 19 + 1;
}

void Del_Fullline(struct Tetris *tetris)
{ 
	int k, del_rows = 0;  //分别用于记录某行方块的个数和删除方块的行数的变量
	for (j = FrameY + Frame_height - 1; j >= FrameY + 1; j--)
	{
		k = 0;
		for (i = FrameX + 2; i<FrameX + 2 * Frame_width - 2; i += 2)
		{
			if (a[i][j] == 1) //竖坐标依次从下往上，横坐标依次由左至右判断是否满行
			{
				k++;  //记录此行方块的个数
				if (k == Frame_width - 2)  //如果满行 
				{
					for (k = FrameX + 2; k<FrameX + 2 * Frame_width - 2; k += 2)//删除满行的方块
					{
						a[k][j] = 0;
						gotoxy(k, j);
						printf("  ");
						//      					Sleep(1);
					}
					for (k = j - 1; k>FrameY; k--) //如果删除行以上的位置有方块，则先清除，再将方块下移一个位置
					{
						for (i = FrameX + 2; i<FrameX + 2 * Frame_width - 2; i += 2)
						{
							if (a[i][k] == 1)
							{
								a[i][k] = 0;
								gotoxy(i, k);
								printf("  ");
								a[i][k + 1] = 1;
								gotoxy(i, k + 1);
								printf("■");
							}
						}
					}
					j++;   //方块下移后，重新判断删除行是否满行
					del_rows++; //记录删除方块的行数
				}
			}
		}
	}
	tetris->score += 10 * del_rows; //每删除一行，得10分
	if (del_rows>0 && (tetris->score % 100 == 0 || tetris->score / 100>tetris->level - 1))
	{        //如果得100分即累计删除10行，速度加快30ms并升一级
		tetris->speed -= 30;
		tetris->level++;
	}
}

void Gameplay()
{
	int n;
	struct Tetris t, *tetris = &t;       					//定义结构体的指针并指向结构体变量
	char ch;         									//定义接收键盘输入的变量
	tetris->number = 0;      								//初始化俄罗斯方块数为0个
	tetris->speed = 300;      							//初始移动速度为300ms
	tetris->score = 0;      								//初始游戏的分数为0分
	tetris->level = 1;      								//初始游戏为第1关
	while (1)
	{
		Flag(tetris);										//随机产生方序号
		Temp = tetris->flag;								//记住当前俄罗斯方块序号
		tetris->x = FrameX + 2 * Frame_width + 6;			//获得预览界面方块的x坐标
		tetris->y = FrameY + 10;				/**/
		tetris->flag = tetris->next;						//获取下一个俄罗斯方块的序号 
		PrintTetris(tetris);
		tetris->x = FrameX + Frame_width;					//获取窗口中心方块的坐标
		tetris->y = FrameY - 1;
		tetris->flag = Temp;								//取出当前的俄罗斯方块序号
		while (1)
		{
			label:PrintTetris(tetris);						//打印俄罗斯方块
			Sleep(tetris->speed);   					//延缓时间
			CleanTetris(tetris);
			Temp1 = tetris->x;
			Temp2 = tetris->flag;		
			if (_kbhit())									//判断键盘输入
			{	
				ch = _getch();
				if (ch == 75)							//左移键ASCII码
				{
					tetris->x -= 2;
				}
				if (ch == 77)     							//按 →键则向右动，中心横坐标加2
				{
					tetris->x += 2;
				}
				if (ch == 72)     						//按 ↑键则变体,即当前方块顺时针转90度
				{
					if (tetris->flag >= 2 && tetris->flag <= 3)
					{
						tetris->flag++;
						tetris->flag %= 2;
						tetris->flag += 2;
					}
					if (tetris->flag >= 4 && tetris->flag <= 7)
					{
						tetris->flag++;
						tetris->flag %= 4;
						tetris->flag += 4;
					}
					if (tetris->flag >= 8 && tetris->flag <= 11)
					{
						tetris->flag++;
						tetris->flag %= 4;
						tetris->flag += 8;
					}
					if (tetris->flag >= 12 && tetris->flag <= 15)
					{
						tetris->flag++;
						tetris->flag %= 4;
						tetris->flag += 12;
					}
					if (tetris->flag >= 16 && tetris->flag <= 19)
					{
						tetris->flag++;
						tetris->flag %= 4;
						tetris->flag += 16;
					}
				}
				if (ch == 32)     					//按空格键，暂停
				{
					PrintTetris(tetris);
					while (1)
					{
						if (_kbhit())   			//再按空格键，继续游戏
						{
							ch = _getch();
							if (ch == 32)
							{
								goto label;
							}
						}
					}
				}
				if (ch == 27)
				{
					system("cls");
					memset(a, 0, 6400 * sizeof(int));       //初始化BOX数组
					welcom();
				}
				if (ifMove(tetris) == 0) 			//如果不可动，上面操作无效
				{
					tetris->x = Temp1;
					tetris->flag = Temp2;
				}
				else      						//如果可动，执行操作
				{
					goto label;
				}

			}
			tetris->y++;						//没有按键tetris->y++;
			if (ifMove(tetris) == 0)
			{
				tetris->y--;
				PrintTetris(tetris);
				Del_Fullline(tetris);
				break;
			}
		}
		for (i = tetris->y - 2; i < tetris->y + 2; i++)
		{
			if (FrameY == i)				//表示到顶
			{
				system("cls");
				gotoxy(17, 18);
				color(14);
				printf("1.再来一局");
				gotoxy(44, 18);
				printf("2.退出");
				scanf_s("%d", &n);
				switch (n)
				{
				case 1:
					system("cls");
					Replay(tetris);
					break;
				case 2:
					break;
				}
			}
		}
		tetris->flag = tetris->next;				//清理右边窗口
		tetris->x = FrameX + 2 * Frame_width + 6;
		tetris->y = FrameY + 10;
		CleanTetris(tetris);
	}
}

void Replay(struct Tetris *tetris)
{
	system("cls");                  	//清屏
	memset(a, 0, 6400 * sizeof(int));       //初始化BOX数组，否则不会正常显示方块，导致游戏直接结束
	DrwaGameframe();       	//制作游戏窗口
	Gameplay(); 			//开始游戏
}

void explation()
{
	color(13);
	system("cls");
	gotoxy(32, 3);
	printf("按键说明");
	gotoxy(26, 6);
	printf("1:玩家可以根据← →来进行移动方块");
	gotoxy(26, 8);
	printf("2:通过↑来变换方块");
	gotoxy(26, 10);
	printf("3:空格可以暂停游戏");
	gotoxy(26, 12);
	printf("4:Esc暂停游戏");
	gotoxy(26, 14);
	printf("\n");
	system("pause");
	system("cls");
	main();
}	

void regulation()
{
	color(14);
	system("cls");
	gotoxy(36, 3);
	printf("游戏规则");
	gotoxy(20, 6);
	printf("由小方块组成的不同形状的板块陆续从屏幕上方落下来");
	gotoxy(20, 8);
	printf("玩家通过调整板块的位置和方向，使它们在屏幕底部拼出完整的一条或几条");
	gotoxy(20, 10);
	printf("这些完整的横条会随即消失，给新落下来的板块腾出空间，与此同时，玩家得到分数奖励");
	gotoxy(20, 12);
	printf("没有被消除掉的方块不断堆积起来，一旦堆到屏幕顶端，玩家便告输，游戏结束");
	printf("\n\n");
	system("pause");		//暂停函数
	system("cls");
	main();
}