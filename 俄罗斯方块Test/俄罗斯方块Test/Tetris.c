#include"Tetris.h"

#define FrameX 13   		//��Ϸ�������Ͻǵ�X������
#define FrameY 3   			//��Ϸ�������Ͻǵ�Y������
#define Frame_height  20 	//��Ϸ���ڵĸ߶�
#define Frame_width   18 	//��Ϸ���ڵĿ�� 

struct Tetris
{
	int number;					//�������	
	int score;					//�ɼ�
	int speed;					//�ٶ�
	int level;					//�ȼ�
	int x;
	int y;
	int flag;					//��ǰ�������
	int next;					//��һ���������
};

HANDLE hOut;

int n;
int i, j, Temp, Temp1, Temp2;   //Temp,Temp1,Temp2������ŷ���任�Ĺ���ֵ
int a[80][80] = { 0 };			//���������Ϸ��Ļͼ����0��ʾû�з��飬1��ʾ�з��飬2��ʾ�߿�
int b[4];						//������ŷ����λ�ã���Ϊÿ������˹���鶼����4��С������ɣ����Դ�����СΪ4������
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
	printf("   ��  ��  ˹  ��  ��   \n");
	color(11);
	gotoxy(18, 5);
	printf("��");
	gotoxy(18, 6);
	printf("����");
	gotoxy(18, 7);
	printf("��");

	color(14);
	gotoxy(26, 6);
	printf("����");
	gotoxy(28, 7);
	printf("����");//

	color(10);
	gotoxy(36, 6);
	printf("����");
	gotoxy(36, 7);
	printf("����");

	color(13);
	gotoxy(45, 5);
	printf("��");
	gotoxy(45, 6);
	printf("��");
	gotoxy(45, 7);
	printf("��");
	gotoxy(45, 8);
	printf("��");

	color(12);
	gotoxy(56, 6);
	printf("��");//
	gotoxy(52, 7);
	printf("������");
}

void welcom()
{
	color(12);
	gotoxy(25, 12);
	printf("1.��ʼ��Ϸ");
	gotoxy(40, 12);
	printf("2.����˵��");
	gotoxy(25, 17);
	printf("3.��Ϸ����");
	gotoxy(40, 17);
	printf("4.�˳�");
	gotoxy(21, 22);
	color(3);
	printf("��ѡ��[1 2 3 4]:");
	scanf_s("%d", &n);    //����ѡ��
	switch (n)
	{
	case 1:
		system("cls");
		DrwaGameframe(); 	//������Ϸ����
		Gameplay(); 		//��ʼ��Ϸ
		break;
	case 2:
		explation();      	//����˵������
		break;
	case 3:
		regulation();     	//��Ϸ������
		break;
	case 4:
		exit(0);		//�ر���Ϸ����
		break;
	}
}

void  DrwaGameframe()
{
	gotoxy(FrameX + Frame_width - 8, FrameY - 2);
	color(12);
	printf("�� �� ˹ �� ��");
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 7);
	color(14);
	printf("*** ��һ������ ***");
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 13);
	printf("***  ***  ***  ***");
	color(13);
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 15);
	printf("������ת");
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 17);
	printf("�ո���ͣ");
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 19);
	printf("esc���˳�");
	a[FrameX][FrameY + Frame_height] = 2;
	a[FrameX + 2 * Frame_width - 2][FrameY + Frame_height] = 2;
	
	for (int i = 2; i < 2 * Frame_width - 2; ++i)
	{
		gotoxy(FrameX + i, FrameY);
		printf("�T");
	}
	
	for (int i = 2; i < 2 * Frame_width - 2; ++i)
	{
		gotoxy(FrameX + i, FrameY + Frame_height);
		printf("�T");
		a[FrameX + i][FrameY + Frame_height] = 2;
	}

	for (int i = 1; i < Frame_height; i++)
	{
		gotoxy(FrameX, FrameY + i);
		printf("�U");
		a[FrameX][FrameY + i] = 2;
	}
	
	for (int i = 1; i < Frame_height; i++)
	{
		gotoxy(FrameX + 2 * Frame_width - 2, FrameY + i);
		printf("�U");
		a[FrameX + 2 * Frame_width - 2][FrameY + i] = 2;
	}
}

void MakeTetris(struct Tetris *tetris)
{
	a[tetris->x][tetris->y] = b[0];    //���ķ���λ�õ�ͼ��״̬
	switch (tetris->flag)      //��7���࣬19������
	{
		case 1:         /*���ַ��� ����
								   ����  */
		{
			color(10);
			a[tetris->x][tetris->y - 1] = b[1];
			a[tetris->x + 2][tetris->y - 1] = b[2];
			a[tetris->x + 2][tetris->y] = b[3];
			break;
		}
		case 2:         /*ֱ�߷��� ��������*/
		{
			color(13);
			a[tetris->x - 2][tetris->y] = b[1];
			a[tetris->x + 2][tetris->y] = b[2];
			a[tetris->x + 4][tetris->y] = b[3];
			break;
		}
		case 3:         /*ֱ�߷���  ��
									��
									��
									��  */
		{
			color(13);
			a[tetris->x][tetris->y - 1] = b[1];
			a[tetris->x][tetris->y - 2] = b[2];
			a[tetris->x][tetris->y + 1] = b[3];
			break;
		}
		case 4:					  /*T�ַ��� ������
							   				  ��  */
		{
			color(11);
			a[tetris->x - 2][tetris->y] = b[1];
			a[tetris->x + 2][tetris->y] = b[2];
			a[tetris->x][tetris->y + 1] = b[3];
			break;
		}
		case 5:         /* ˳ʱ��90��T�ַ���   ��
											 ����
											   ��*/
		{
			color(11);
			a[tetris->x][tetris->y - 1] = b[1];
			a[tetris->x][tetris->y + 1] = b[2];
			a[tetris->x - 2][tetris->y] = b[3];
			break;
		}
		case 6:         /* ˳ʱ��180��T�ַ���     ��
												������*/
		{
			color(11);
			a[tetris->x][tetris->y - 1] = b[1];
			a[tetris->x - 2][tetris->y] = b[2];
			a[tetris->x + 2][tetris->y] = b[3];
			break;
		}
		case 7:         /* ˳ʱ��270��T�ַ���   ��
												����
												��  */
		{
			color(11);
			a[tetris->x][tetris->y - 1] = b[1];
			a[tetris->x][tetris->y + 1] = b[2];
			a[tetris->x + 2][tetris->y] = b[3];
			break;
		}
		case 8:         /* Z�ַ���   ����
									   ����*/
		{
			color(14);
			a[tetris->x][tetris->y + 1] = b[1];
			a[tetris->x - 2][tetris->y] = b[2];
			a[tetris->x + 2][tetris->y + 1] = b[3];
			break;
		}
		case 9:         /* ˳ʱ��Z�ַ���      ��
											����
											��  */
		{
			color(14);
			a[tetris->x][tetris->y - 1] = b[1];
			a[tetris->x - 2][tetris->y] = b[2];
			a[tetris->x - 2][tetris->y + 1] = b[3];
			break;
		}
		case 10:        /* ��תZ�ַ���      ����
										  ����  */
		{
			color(14);
			a[tetris->x][tetris->y - 1] = b[1];
			a[tetris->x - 2][tetris->y - 1] = b[2];
			a[tetris->x + 2][tetris->y] = b[3];
			break;
		}
		case 11:        /* ˳ʱ��Z�ַ���    ��
				                     		����
											  ��  */
		{
			color(14);
			a[tetris->x][tetris->y + 1] = b[1];
			a[tetris->x - 2][tetris->y - 1] = b[2];
			a[tetris->x - 2][tetris->y] = b[3];
			break;
		}
		case 12:        /* 7�ַ���    ����
										��
										��  */
		{
			color(12);
			a[tetris->x][tetris->y - 1] = b[1];
			a[tetris->x][tetris->y + 1] = b[2];
			a[tetris->x - 2][tetris->y - 1] = b[3];
			break;
		}
		case 13:        /* ˳ʱ��90��7�ַ���        ��
												������*/
		{
			color(12);
			a[tetris->x - 2][tetris->y] = b[1];
			a[tetris->x + 2][tetris->y - 1] = b[2];
			a[tetris->x + 2][tetris->y] = b[3];
			break;
		}
		case 14:        /* ˳ʱ��180��7�ַ���      ��
												   ��
												   ����  */
		{
			color(12);
			a[tetris->x][tetris->y - 1] = b[1];
			a[tetris->x][tetris->y + 1] = b[2];
			a[tetris->x + 2][tetris->y + 1] = b[3];
			break;
		}
		case 15:        /* ˳ʱ��270��7�ַ���    ������
												 ��    */
		{
			color(12);
			a[tetris->x - 2][tetris->y] = b[1];
			a[tetris->x - 2][tetris->y + 1] = b[2];
			a[tetris->x + 2][tetris->y] = b[3];
			break;
		}
		case 16:        /* ��ת7�ַ���    ����
										  ��
										  ��    */
		{
			color(12);
			a[tetris->x][tetris->y + 1] = b[1];
			a[tetris->x][tetris->y - 1] = b[2];
			a[tetris->x + 2][tetris->y - 1] = b[3];
			break;
		}
		case 17:        /* ˳ʱ��ת90��7�ַ���    ������
													  ��*/
		{
			color(12);
			a[tetris->x - 2][tetris->y] = b[1];
			a[tetris->x + 2][tetris->y + 1] = b[2];
			a[tetris->x + 2][tetris->y] = b[3];
			break;
		}
		case 18:        /* ˳ʱ��ת180��7�ַ���    ��
												   ��
												 ����    */
		{
			color(12);
			a[tetris->x][tetris->y - 1] = b[1];
			a[tetris->x][tetris->y + 1] = b[2];
			a[tetris->x - 2][tetris->y + 1] = b[3];
			break;
		}
		case 19:        /* ˳ָ��ת270��7�ַ���    ��
												   ������*/
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
		b[i] = 1;         				//����b[4]��ÿ��Ԫ�ص�ֵ��Ϊ1
	}
	MakeTetris(tetris);      			//������Ϸ����
	for (i = tetris->x - 2; i <= tetris->x + 4; i += 2)
	{
		for (j = tetris->y - 2; j <= tetris->y + 1; j++)
		{
			if (a[i][j] == 1 && j>FrameY)
			{
				gotoxy(i, j);
				printf("��");     //��ӡ�߿��ڵķ���
			}
		}
	}
	//��ӡ�˵���Ϣ
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

int ifMove(struct Tetris *tetris)   //�жϸõ��Ƿ�����ƶ�
{
 	if(a[tetris->x][tetris->y]!=0)//�����ķ���λ������ͼ��ʱ������ֵΪ0���������ƶ�
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
	for (i = tetris->x - 2; i <= tetris->x + 4; i += 2)       //��X ����  XΪ���ķ���
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
	int k, del_rows = 0;  //�ֱ����ڼ�¼ĳ�з���ĸ�����ɾ������������ı���
	for (j = FrameY + Frame_height - 1; j >= FrameY + 1; j--)
	{
		k = 0;
		for (i = FrameX + 2; i<FrameX + 2 * Frame_width - 2; i += 2)
		{
			if (a[i][j] == 1) //���������δ������ϣ��������������������ж��Ƿ�����
			{
				k++;  //��¼���з���ĸ���
				if (k == Frame_width - 2)  //������� 
				{
					for (k = FrameX + 2; k<FrameX + 2 * Frame_width - 2; k += 2)//ɾ�����еķ���
					{
						a[k][j] = 0;
						gotoxy(k, j);
						printf("  ");
						//      					Sleep(1);
					}
					for (k = j - 1; k>FrameY; k--) //���ɾ�������ϵ�λ���з��飬����������ٽ���������һ��λ��
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
								printf("��");
							}
						}
					}
					j++;   //�������ƺ������ж�ɾ�����Ƿ�����
					del_rows++; //��¼ɾ�����������
				}
			}
		}
	}
	tetris->score += 10 * del_rows; //ÿɾ��һ�У���10��
	if (del_rows>0 && (tetris->score % 100 == 0 || tetris->score / 100>tetris->level - 1))
	{        //�����100�ּ��ۼ�ɾ��10�У��ٶȼӿ�30ms����һ��
		tetris->speed -= 30;
		tetris->level++;
	}
}

void Gameplay()
{
	int n;
	struct Tetris t, *tetris = &t;       					//����ṹ���ָ�벢ָ��ṹ�����
	char ch;         									//������ռ�������ı���
	tetris->number = 0;      								//��ʼ������˹������Ϊ0��
	tetris->speed = 300;      							//��ʼ�ƶ��ٶ�Ϊ300ms
	tetris->score = 0;      								//��ʼ��Ϸ�ķ���Ϊ0��
	tetris->level = 1;      								//��ʼ��ϷΪ��1��
	while (1)
	{
		Flag(tetris);										//������������
		Temp = tetris->flag;								//��ס��ǰ����˹�������
		tetris->x = FrameX + 2 * Frame_width + 6;			//���Ԥ�����淽���x����
		tetris->y = FrameY + 10;				/**/
		tetris->flag = tetris->next;						//��ȡ��һ������˹�������� 
		PrintTetris(tetris);
		tetris->x = FrameX + Frame_width;					//��ȡ�������ķ��������
		tetris->y = FrameY - 1;
		tetris->flag = Temp;								//ȡ����ǰ�Ķ���˹�������
		while (1)
		{
			label:PrintTetris(tetris);						//��ӡ����˹����
			Sleep(tetris->speed);   					//�ӻ�ʱ��
			CleanTetris(tetris);
			Temp1 = tetris->x;
			Temp2 = tetris->flag;		
			if (_kbhit())									//�жϼ�������
			{	
				ch = _getch();
				if (ch == 75)							//���Ƽ�ASCII��
				{
					tetris->x -= 2;
				}
				if (ch == 77)     							//�� ���������Ҷ������ĺ������2
				{
					tetris->x += 2;
				}
				if (ch == 72)     						//�� ���������,����ǰ����˳ʱ��ת90��
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
				if (ch == 32)     					//���ո������ͣ
				{
					PrintTetris(tetris);
					while (1)
					{
						if (_kbhit())   			//�ٰ��ո����������Ϸ
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
					memset(a, 0, 6400 * sizeof(int));       //��ʼ��BOX����
					welcom();
				}
				if (ifMove(tetris) == 0) 			//������ɶ������������Ч
				{
					tetris->x = Temp1;
					tetris->flag = Temp2;
				}
				else      						//����ɶ���ִ�в���
				{
					goto label;
				}

			}
			tetris->y++;						//û�а���tetris->y++;
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
			if (FrameY == i)				//��ʾ����
			{
				system("cls");
				gotoxy(17, 18);
				color(14);
				printf("1.����һ��");
				gotoxy(44, 18);
				printf("2.�˳�");
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
		tetris->flag = tetris->next;				//�����ұߴ���
		tetris->x = FrameX + 2 * Frame_width + 6;
		tetris->y = FrameY + 10;
		CleanTetris(tetris);
	}
}

void Replay(struct Tetris *tetris)
{
	system("cls");                  	//����
	memset(a, 0, 6400 * sizeof(int));       //��ʼ��BOX���飬���򲻻�������ʾ���飬������Ϸֱ�ӽ���
	DrwaGameframe();       	//������Ϸ����
	Gameplay(); 			//��ʼ��Ϸ
}

void explation()
{
	color(13);
	system("cls");
	gotoxy(32, 3);
	printf("����˵��");
	gotoxy(26, 6);
	printf("1:��ҿ��Ը��ݡ� ���������ƶ�����");
	gotoxy(26, 8);
	printf("2:ͨ�������任����");
	gotoxy(26, 10);
	printf("3:�ո������ͣ��Ϸ");
	gotoxy(26, 12);
	printf("4:Esc��ͣ��Ϸ");
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
	printf("��Ϸ����");
	gotoxy(20, 6);
	printf("��С������ɵĲ�ͬ��״�İ��½������Ļ�Ϸ�������");
	gotoxy(20, 8);
	printf("���ͨ����������λ�úͷ���ʹ��������Ļ�ײ�ƴ��������һ������");
	gotoxy(20, 10);
	printf("��Щ�����ĺ������漴��ʧ�������������İ���ڳ��ռ䣬���ͬʱ����ҵõ���������");
	gotoxy(20, 12);
	printf("û�б��������ķ��鲻�϶ѻ�������һ���ѵ���Ļ���ˣ���ұ���䣬��Ϸ����");
	printf("\n\n");
	system("pause");		//��ͣ����
	system("cls");
	main();
}