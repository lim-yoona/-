#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<iostream>
#define BLACK 0
#define WHITE 1
#define EMPTY 2
#include<vector>
using namespace std;
struct Point{ //��ṹ
	int x,y;
};
struct Step{ //���ṹ
	Point first,second;
	int value;
};
int Board[19][19];//�洢������Ϣ����Ԫ��ֵΪ BLACK, WHITE, EMPTY ֮һ

//LC���
struct a//�ṹ�塤�����洢����һ�ӾͿ��Ի�ʤ����� 
{
	int x;
	int y;
}; 
struct b//�ṹ�塤�����洢���������Ӳ��ܻ�ʤ����� 
{
	int x1;
	int y1;
	int x2;
	int y2;
};
vector<a> PointSet1;//�������������ֻ��һ�ӾͿ��Ի�ʤ������ļ��� 
vector<b> PointSet2;//��������������������ӿ��Ի�ʤ������ļ��� 
int dv[8]={0,0,1,-1,1,-1,-1,1};
int dw[8]={1,-1,0,0,1,-1,1,-1};//�����򣬷ֱ�Ϊ�£��ϣ��ң������£����ϣ����£����� 
bool JudgeFourOrFive(int colour) 
{
	cout<<"����Judje"<<endl; 
	for(int i=0;i<19;i++)
	{
		for(int j=0;j<19;j++)
		{
			if(Board[i][j]==colour)//��������ǰ���������ӵ���ɫΪcolour 
			{
				for(int r=0;r<8;r++)//�����˸����� 
				{
					int num=1; 
					for(int k=1;k<6;k++)//������ǰ�����µ��������� 
					{
						if((i+dv[r]*5)>=19||(i+dv[r]*5)<0||(j+dw[r]*5)>=19||(j+dw[r]*5)<0)//�жϰ��յ�ǰ��������������ӻ᲻��Խ�� 
						break;//���Խ�磬����ѭ��������������һ��������������� 
						if(Board[i+dv[r]*k][j+dw[r]*k]==colour)
						num++;//������ǰ��ɫ�����ӣ�num��һ 
					}
					cout<<"num"<<num<<endl;
					if(num!=4&&num!=5)//�����������������ɫΪcolour�����Ӳ���4����5�� ����ô��ô�¶�����ֱ��Ӯ 
					continue; //������һ���� 
					else if(num==5)//��������������5��colour��ɫ�����ӣ������µ��Ǹ�����ֻҪΪ�գ�����colourɫ����ͻ�Ӯ 
					{
						cout<<"5������"<<endl; 
						for(int k=1;k<6;k++)
						{
							if(Board[i+dv[r]*k][j+dw[r]*k]==2)//�ҵ�Ϊ�յ����� 
							{
								struct a* aa=new a;
								aa->x=i+dv[r]*k;
								aa->y=j+dw[r]*k;
								PointSet1.push_back(*aa);
							}
						}
					}
					else if(num==4)//��������������4��colour��ɫ�����ӣ������µ�������������Ϊ�գ���������colourɫ����ͻ�Ӯ 
					{
						struct b* bb=new b;
						int m=0;//�ж��ǰ��������x��y����x1��y1 
						int counter=0; //�ж����������������м���Ϊ�� 
						for(int k=1;k<6;k++)
						{
							if(Board[i+dv[r]*k][j+dw[r]*k]==2)
							{
								if(m==0)
								{
									counter++;
									bb->x1=i+dv[r]*k;
									bb->y1=j+dw[r]*k;
									m=1;//����x��y֮��ı�m ,�´��x1��y1���� 
								}
								else if(m==1) 
								{
									counter++; 
									bb->x2=i+dv[r]*k;
									bb->y2=j+dw[r]*k;
								}
							}
						}
						if(counter==2)//����������궼Ϊ�� 
						{
							PointSet2.push_back(*bb);
						}
					}
				} 
			}
			//else//��ǰ��������ɫ��Ϊcolour���ӵĻ�������һѭ�� 
			//continue;
		}
	}
	if(PointSet1.size()==0&&PointSet2.size()==0)//���PointSet1��PointSet2��Ϊ�գ�˵����ǰ����в����ڿ���ֱ��Ӯ����� 
	return false;
	cout<<"����***********************************"<<endl;
	/*vector<a>::iterator Point1,P;
	vector<b>::iterator Point2,H; 
	//ȥ��1�����ڱ����˰˸�����ʵ���ϣ������������õ��Ľ�����ظ��������������� 
	for(Point1=PointSet1.begin();Point1!=PointSet1.end()-1;Point1++)//ȥ�� 
	{
		for(P=Point1+1;P!=PointSet1.end();P++)
		{
			if((*Point1).x==(*P).x&&(*Point1).y==(*P).y)
			{
				PointSet1.erase(P);
				P--;
			}
		}
	}
	for(Point2=PointSet2.begin();Point2!=PointSet2.end()-1;Point2++)//ȥ�� 
	{
		for(H=Point2+1;H!=PointSet2.end();H++)
		{
			if((*Point2).x1==(*H).x1&&(*Point2).y1==(*H).y1&&(*Point2).x2==(*H).x2&&(*Point2).y2==(*H).y2)
			{
				PointSet2.erase(H);
				H--;
			}
		}
	}
	//ȥ��2������5���ӵ�������ܰ���4���ӵ�����������е�ֻ��һ����Ϳ�ʤ�������������������ʤ�����������Ҳ��¼�ˣ���ʱ�������ӵ���ؼ�¼ɾ�� 
	for(Point1=PointSet1.begin();Point1!=PointSet1.end();Point1++)
	{
		for(Point2=PointSet2.begin();Point2!=PointSet2.end();)
		{
			if(((*Point1).x==(*Point2).x1&&(*Point1).y==(*Point2).y1)||((*Point1).x==(*Point2).x2&&(*Point1).y==(*Point2).y2))
			PointSet2.erase(Point2);
			else
			Point2++;
		}
	}*/
	return true;
}
//LC��� 
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
				printf("move %c%c@@\n", step.first.x + 'A', step.first.y + 'A');//����ŷ�
			}
		}
		else if(strcmp(message,"move")==0)//����,���������
		{
			//int ooo=0;
			scanf("%s", message);//��ȡ���������ŷ�
            fflush(stdin); 
			step.first.x=message[0]-'A';		step.first.y=message[1]-'A';
			step.second.x=message[2]-'A';		step.second.y=message[3]-'A';
            //�����������
			Board[step.first.x][step.first.y] = 1 - computerSide;
			if(!(step.second.x==-1 && step.second.y==-1)) Board[step.second.x][step.second.y] = 1 - computerSide;

            /**********************************************************************************************************/
			/***�������ӵ����꣬������step�ṹ�У���1������(step.first.x,step.first.y)����2������(step.first.x,step.first.y)*****/
			/**************************************���·������룬���滻�ҵ�ʾ������*****************************************/
			//LC��� 
			//system("pause");
			int nm=0;
			PointSet1.clear();
			PointSet2.clear();
			if(JudgeFourOrFive(computerSide)) 
			{
				if(PointSet1.size()!=0)
					{
						step.first.x=PointSet1[0].x;
						step.first.y=PointSet1[0].y;
						/*int x,y;
						x = rand() % 19;	y = rand() % 19;
						while (Board[x][y] != EMPTY)
						{
							x = rand() % 19;	y = rand() % 19;
						}
						step.second.x = x;
						step.second.y = y;*/
					}
					else if(PointSet2.size()!=0)
					{
						step.first.x=PointSet2[0].x1;
						step.first.y=PointSet2[0].y1;
						step.second.x=PointSet2[0].x2;
						step.second.y=PointSet2[0].y2; 
					}
					/*Board[step.first.x][step.first.y] = computerSide;
					Board[step.second.x][step.second.y] = computerSide;*/
			}
			else if(JudgeFourOrFive(1-computerSide))
			{
				if(PointSet2.size()>=2)
				{
					step.first.x=PointSet2[0].x1;
					step.first.y=PointSet2[0].y1;
					step.second.x=PointSet2[1].x1;
					step.second.y=PointSet2[1].y1; 
				}
				else if(PointSet1.size()>=2)
				{
					step.first.x=PointSet1[0].x;
					step.first.y=PointSet1[0].y;
					step.second.x=PointSet1[1].x;
					step.second.y=PointSet1[1].y; 
				}
				else if(PointSet1.size()==1&&PointSet2.size()==1)
				{
					step.first.x=PointSet1[0].x;
					step.first.y=PointSet1[0].y;
					step.second.x=PointSet2[0].x1;
					step.second.y=PointSet2[0].y1;
				}
				else if(PointSet1.size()==1)
				{
					step.first.x=PointSet1[0].x;
					step.first.y=PointSet1[0].y;
					int x,y;
						while (Board[x][y] != EMPTY)
						{
							x = rand() % 19;	y = rand() % 19;
						}
						step.second.x = x;
						step.second.y = y;
					//nm=1;
				}
				else if(PointSet2.size()==1)
				{
					step.first.x=PointSet2[0].x1;
					step.first.y=PointSet2[0].y1;
					step.second.x=PointSet2[0].x2;
					step.second.y=PointSet2[0].y2;
					//nm=1;
				}
				/*Board[step.first.x][step.first.y] = computerSide;
				Board[step.second.x][step.second.y] = computerSide;*/
			}
			else
			{
				//cout<<"cccccccccccccccccccc"<<endl;
				int x, y;
				x = rand() % 19; y = rand() % 19;
				while (Board[x][y] != EMPTY)
				{
					x = rand() % 19;	y = rand() % 19;
				}
				step.first.x = x;
				step.first.y = y;
				x = rand() % 19;	y = rand() % 19;
				while (Board[x][y] != EMPTY)
				{
					x = rand() % 19;	y = rand() % 19;
				}
				step.second.x = x;
				step.second.y = y;
			}
			while (Board[step.first.x][step.first.y] != 2)
			{
				step.first.x = rand() % 19;	step.first.y = rand() % 19;
			}
			while (Board[step.second.x][step.second.y] != 2)
			{
				step.second.x = rand() % 19;	step.second.y = rand() % 19;
			}
			/*if(ooo==0)
			{
				step.first.x=1;
				step.first.y=1;
				step.second.x=10;
				step.second.y=10;
				ooo=1;
			}*/
			Board[step.first.x][step.first.y] = computerSide;
			Board[step.second.x][step.second.y] = computerSide;
			//���ɵ�1������λ��step.first.x��step.first.y
			/*int x, y;
			x = rand() % 19; y = rand() % 19;
			while (Board[x][y] != EMPTY)
			{
				x = rand() % 19;	y = rand() % 19;
			}
			step.first.x = x;
			step.first.y = y;
			Board[step.first.x][step.first.y] = computerSide;

			//���ɵ�2������λ��step.second.x��step.second.y	
			x = rand() % 19;	y = rand() % 19;
			while (Board[x][y] != EMPTY)
			{
				x = rand() % 19;	y = rand() % 19;
			}
			step.second.x = x;
			step.second.y = y;
			Board[step.second.x][step.second.y] = computerSide;*/ 
			
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
