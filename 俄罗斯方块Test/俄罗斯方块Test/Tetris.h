#pragma once
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>



void gotoxy(int x, int y);			//����Ƶ�ָ��λ��
void DrwaGameframe();				//������Ϸ�߿�
void Flag(struct Tetris *);			//��������������͵����
void MakeTetris(struct Tetris *);	//��������˹����
void PrintTetris(struct Tetris *);	//��ӡ����˹����
void CleanTetris(struct Tetris *);	//�������˹����ĺۼ�
int  ifMove(struct Tetris *);		//�ж��Ƿ����ƶ�������ֵΪ1�����ƶ������򣬲����ƶ�
void Del_Fullline(struct Tetris *);	//�ж��Ƿ����У���ɾ�����еĶ���˹����
void Gameplay();					//��ʼ��Ϸ
void regulation();                  //��Ϸ����
void explation();                   //����˵��
void welcom();                      //��ӭ����
void Replay(struct Tetris *);  		//���¿�ʼ��Ϸ
void title();                       //��ӭ�����Ϸ��ı���

