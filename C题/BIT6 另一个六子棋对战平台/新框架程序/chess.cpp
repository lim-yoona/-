#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<vector>
using namespace std;

#define BLACK 0
#define WHITE 1
#define EMPTY 2

struct Point{ //��ṹ
	int x,y;
};
struct Step{ //���ṹ
	Point first,second;
	int value;
};
int Board[19][19];//�洢������Ϣ����Ԫ��ֵΪ BLACK, WHITE, EMPTY ֮һ
vector<Point>PointSet1;
vector<Point>PointSet2; 
vector<Point>PointSet3;
vector<Point>PointSet4; 
void FindPosition(int Board[19][19],int sigh,vector<Point>&PointSet1,vector<Point>&PointSet2)
//PointSet1����ֻ����һ�����ӾͿ�ʤ���������PointSet2������Ҫ���°��ŵ����Ӳ���Ӯ����� 
{
	for(int i=0;i<19;i++)//��һ��ѭ������ 
	{
		int num=0;//����ӵ��sigh�����ӵĸ��� 
		int First=19;//���е�һ��sigh�����ӵ�λ�� 
		int Last=-1;//�������һ��sigh�����ӵ�λ�� 
		for(int j=0;j<19;j++)//�ҵ���ǰ�е�num��First��Last 
		{
			if(Board[i][j]==sigh)
			{
				if(j<First)
				First=j;
				if(j>Last)
				Last=j;
				num++;
			}
		}
		if(num<4)//���������ĿС��4���Ǳز������ڵ�ǰ��ʤ�� 
		continue;//�������п���һ�� 
		if(First-Last==4)//����������������һ�𣬿�������ӵ�ǰһ��λ���Ƿ�Ϊ�� 
		{
			if(First>=1&&Board[i][First-1]==2)
			{
				struct Point* a=new Point;
				a->x=i;
				a->y=First-1;
				PointSet1.push_back(&a);
			}
			continue;
		}
		if(First-Last==3)//�����������һ�𣬿��ĸ����ӵ�ǰ����λ���Ƿ�Ϊ�� 
		{
			if(First>=2&&Board[i][First-1]==2&&Board[i][First-2]==2)
			{
				struct Point* a=new Point;
				struct Point* b=new Point;
				a->x=i;
				b->x=i;
				a->y=First-1;
				b->y=First-2;
				PointSet2.push_back(&a);
				PointSet2.push_back(&b);
			}
			continue; 
		}
		int k=0;
		int F=19;
		int L=-1;
		while(k<19)
		{
			/*if(Board[i][k]!=sigh)
			{
				k++;
				continue;
			}*/
			
			if(Board[i][k]==sigh)
			{
				if(k<F)
				F=k;
				if(k>L)
				L=k;
				k++;
			}
			else if(k>=1&&Board[i][k-1]==sigh&&F+6<=19)
			{
				FF=F;
				LL=L;
				F=19;
				L=-1;
				if(Board[i][k]==2)
				{
					int kk=0;
					for(int mm=1;mm<=6-(FF-LL+1)-1;mm++)
					{
						if(Board[i][k+mm]!=sigh)
						{
							kk=1;
							break;
						}
					}
					if(kk==0)
					{
						//���Ͼ�������һ������ 
						struct Point* a=new Point;
						a->x=i;
						a->y=k;
						PointSet1.push_back(&a);
						k++;
						continue;
					}
					else if(kk==1)
					{
						k++;
						continue;
					}
					if(Board[i][k+1]==2)
					{
						int kkk=0;
						for(int mmm=1;mmm<=6-(FF-LL+1)-2;mmm++)
						{
							if(Board[i][k+1+mmm]!=sigh)
							{
								kkk=1;
								break;
							}
						}
						if(kkk==0)
						{
							//�����������������ӿ����������� 
							struct Point* a=new Point;
							struct Point* b=new Point;
							a->x=i;
							b->x=i;
							a->y=k;
							b->y=k+1;
							PointSet2.push_back(&a);
							PointSet2.push_back(&b);
							k=k+2;
						}
						else if(kkk==1)
						{
							k=k+2;
						}
					}
				}
			}
			else
			{
				F=19;
				L=-1;
				k++;
			}
		}
	}
	for(int i=0;i<19;i++)//�ڶ���ѭ������ 
	{
		int num=0;//����ӵ��sigh�����ӵĸ��� 
		int First=19;//���е�һ��sigh�����ӵ�λ�� 
		int Last=-1;//�������һ��sigh�����ӵ�λ�� 
		for(int j=0;j<19;j++)//�ҵ���ǰ�е�num��First��Last 
		{
			if(Board[j][i]==sigh)
			{
				if(j<First)
				First=j;
				if(j>Last)
				Last=j;
				num++;
			}
		}
		if(num<4)//���������ĿС��4���Ǳز������ڵ�ǰ��ʤ�� 
		continue;//�������п���һ�� 
		if(First-Last==4)//����������������һ�𣬿�������ӵ�ǰһ��λ���Ƿ�Ϊ�� 
		{
			if(First>=1&&Board[First-1][i]==2)
			{
				struct Point* a=new Point;
				a->y=i;
				a->x=First-1;
				PointSet1.push_back(&a);
			}
			continue;
		}
		if(First-Last==3)//�����������һ�𣬿��ĸ����ӵ�ǰ����λ���Ƿ�Ϊ�� 
		{
			if(First>=2&&Board[First-1][i]==2&&Board[First-2][i]==2)
			{
				struct Point* a=new Point;
				struct Point* b=new Point;
				a->y=i;
				b->y=i;
				a->x=First-1;
				b->x=First-2;
				PointSet2.push_back(&a);
				PointSet2.push_back(&b);
			}
			continue; 
		}
		int k=0;
		int F=19;
		int L=-1;
		while(k<19)
		{
			/*if(Board[i][k]!=sigh)
			{
				k++;
				continue;
			}*/
			
			if(Board[k][i]==sigh)
			{
				if(k<F)
				F=k;
				if(k>L)
				L=k;
				k++;
			}
			else if(k>=1&&Board[k-1][i]==sigh&&F+6<=19)
			{
				FF=F;
				LL=L;
				F=19;
				L=-1;
				if(Board[k][i]==2)
				{
					int kk=0;
					for(int mm=1;mm<=6-(FF-LL+1)-1;mm++)
					{
						if(Board[k+mm][i]!=sigh)
						{
							kk=1;
							break;
						}
					}
					if(kk==0)
					{
						//���Ͼ�������һ������ 
						struct Point* a=new Point;
						a->y=i;
						a->x=k;
						PointSet1.push_back(&a);
						k++;
						continue;
					}
					else if(kk==1)
					{
						k++;
						continue;
					}
					if(Board[k+1][i]==2)
					{
						int kkk=0;
						for(int mmm=1;mmm<=6-(FF-LL+1)-2;mmm++)
						{
							if(Board[k+1+mmm][i]!=sigh)
							{
								kkk=1;
								break;
							}
						}
						if(kkk==0)
						{
							//�����������������ӿ����������� 
							struct Point* a=new Point;
							struct Point* b=new Point;
							a->y=i;
							b->y=i;
							a->x=k;
							b->x=k+1;
							PointSet2.push_back(&a);
							PointSet2.push_back(&b);
							k=k+2;
						}
						else if(kkk==1)
						{
							k=k+2;
						}
					}
				}
			}
			else
			{
				F=19;
				L=-1;
				k++;
			}
		}
	}
	
}
int main()
{
	Step step;//��ʱ���ṹ
	char message[256];//ͨ����Ϣ����
    int computerSide;//����ִ����ɫ
    int start=0;//�Ծֿ�ʼ���
	srand(int(time(0)));
	//�˴����ó�ʼ������
    //...
    
	while (1)	//������ѭ��
	{
		fflush(stdout);//��Ҫɾ������䣬�������������
		scanf("%s", message);//��ȡƽ̨������Ϣ
        //��������
		if (strcmp(message, "name?") == 0)//���սƽ̨���Ͷ���
		{
			fflush(stdin);
			/***********��"�����"��Ϊ��Ķ�����������6�����ֻ�12��Ӣ����ĸ�������޳ɼ�************/
			/*******/		printf("name �����\n");		/**ֻ�޸�����壬��Ҫɾ��name�ո�****/
			/***********��"�����"��Ϊ��Ķ�����������6�����ֻ�12��Ӣ����ĸ�������޳ɼ�************/
		}
		else if (strcmp(message, "new") == 0)//���������
		{
			int i, j;
			scanf("%s", message);//��ȡ����ִ����ɫ
			fflush(stdin);
			if (strcmp(message, "black") == 0)	computerSide = BLACK;  //ִ��
			else  computerSide = WHITE;   //ִ��

			for (i = 0; i<19; ++i)   //��ʼ�����
				for (j = 0; j<19; ++j)
					Board[i][j] = EMPTY;
			start = 1;

			if (computerSide == BLACK)
			{
				/**********���ɵ�һ���ŷ�����������step�ṹ�У���������Ϊ(step.first.x,step.first.y)**********/
				/****************************���·������룬���滻�ҵ�ʾ������******************************/


				step.first.x = 9;
				step.first.y = 9;


				/******************************����������һ���������*******************************************/

				Board[step.first.x][step.first.y] = computerSide;//����������
				//printf("move %c%c@@\n", step.first.x + 'A', step.first.y + 'A');//����ŷ�
				printf("move %c%c\n", step.first.x + 'A', step.first.y + 'A');//����ŷ�
			}
		}
		else if(strcmp(message,"move")==0)//����,���������
		{
			scanf("%s", message);//��ȡ���������ŷ�
            fflush(stdin); 
			int len = strlen(message);
			
			step.first.x=message[0]-'A';		step.first.y=message[1]-'A';
			if(len==4)
			{
				step.second.x=message[2]-'A';		step.second.y=message[3]-'A';
			}
            //�����������
			Board[step.first.x][step.first.y] = 1 - computerSide;
			//if(!(step.second.x==-1 && step.second.y==-1)) Board[step.second.x][step.second.y] = 1 - computerSide;
			if (len == 4) Board[step.second.x][step.second.y] = 1 - computerSide;
            /**********************************************************************************************************/
			/***�������ӵ����꣬������step�ṹ�У���һ������(step.first.x,step.first.y)����һ������(step.first.x,step.first.y)***/
			/**************************************���·������룬���滻�ҵ�ʾ������*****************************************/
			FindPosition(Board,0,PointSet1,PointSet2);
			FindPosition(Board,1,PointSet3,PointSet4);
			//���ɵ�1������λ��step.first.x��step.first.y
			int x, y;
			int ll=0;
			int jj=0;
			x = rand() % 19; y = rand() % 19;
			while (Board[x][y] != EMPTY)
			{
				x = rand() % 19;	y = rand() % 19;
			}
			step.first.x = x;
			step.first.y = y;
			//Board[step.first.x][step.first.y] = computerSide;
			if(PointSet1.size()!=0||PointSet2.size()!=0)
			{
				if(PointSet2.size()!=0)
				{
					step.first.x=PointSet2[0].x;
					step.first.y=PointSet2[0].y;
				}
				else if(PointSet1.size()!=0)
				{
					step.first.x=PointSet1[0].x;
					step.first.y=PointSet1[0].y;
					ll=1;
				}
			}
			else if(PointSet3.size()!=0||PointSet4.size()!=0)
			{
				if(PointSet3.size()!=0)
				{
					step.first.x=PointSet3[0].x;
					step.first.y=PointSet3[0].y;
				}
				else if(PointSet4.size()!=0)
				{
					step.first.x=PointSet4[0].x
					step.first.y=PointSet4[0].y;
					jj=1;
				}
			}
			Board[step.first.x][step.first.y] = computerSide;

			//���ɵ�2������λ��step.second.x��step.second.y	
			x = rand() % 19;	y = rand() % 19;
			while (Board[x][y] != EMPTY)
			{
				x = rand() % 19;	y = rand() % 19;
			}
			step.second.x = x;
			step.second.y = y;
			//Board[step.second.x][step.second.y] = computerSide;
			if(PointSet1.size()!=0||PointSet2.size()!=0)
			{
				if(PointSet2.size()>2)
				{
					step.second.x=PointSet2[2].x;
					step.second.y=PointSet2[2].y;
				}
				else if(PointSet1.size()!=0)
				{
					if(ll==0)
					{
						step.second.y=PointSet1[0].y;
						step.second.x=PointSet1[0].x;
					}
					//step.second.y=PointSet1[0];
					else
					{
						step.second.y=PointSet1[1].y;
						step.second.x=PointSet1[1].x;
					}
				}
			}
			else if(PointSet3.size()!=0||PointSet4.size()!=0)
			{
				if(PointSet4.size()!=0)
				{
					if(jj==1)
					{
						step.first.x=PointSet4[1].x
						step.first.y=PointSet4[1].y;
					}
				}
			}
			/*****************************************������������******************************************************/
			/**********************************************************************************************************/

			printf("move %c%c%c%c\n",step.first.x+'A',step.first.y+'A',step.second.x+'A',step.second.y+'A');//����ŷ�
		}
        else if (strcmp(message, "error") == 0)//�ŷ�����
        {
            fflush(stdin);
        }
		else if (strcmp(message, "end") == 0)//�Ծֽ���
		{
            fflush(stdin);
			start = 0;
		}
		else if (strcmp(message, "quit") == 0)//�˳�����
		{
            fflush(stdin);
			printf("Quit!\n");
			break;
		}
	}
	return 0;
}
