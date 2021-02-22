#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<vector>

#define BLACK 0
#define WHITE 1
#define EMPTY 2
using namespace std;
struct Point { //��ṹ
	int x,y;
};
struct Step { //���ṹ
	Point first,second;
	int value;
};
int Board[19][19];//�洢������Ϣ����Ԫ��ֵΪ BLACK, WHITE, EMPTY ֮һ
//3�����ж� ����ȫ�ֱ���
struct sd {
	int X;
	int Y;
	int fx;
} fuhe[2],fuhe1[1]; //�����������������¼����
// 4��5�����ж�����ȫ�ֱ���
struct a { //�ṹ�塤�����洢����һ�ӾͿ��Ի�ʤ�����
	int x;
	int y;
};
struct b { //�ṹ�塤�����洢���������Ӳ��ܻ�ʤ�����
	int x1;
	int y1;
	int x2;
	int y2;
};
vector<a> PointSet1;//�������������ֻ��һ�ӾͿ��Ի�ʤ������ļ���
vector<b> PointSet2;//��������������������ӿ��Ի�ʤ������ļ���
bool JudgeThree(int Board[19][19],int computerSide) {
	int ttt=0;
	int ttt1=0;
	int dv[4]= {0,1,1,-1};
	int dw[4]= {1,0,1,1}; //�����򣬷ֱ�Ϊ�£��ң����£�����
	for(int i=0; i<19; i++) {
		for(int j=0; j<19; j++) {
			if(Board[i][j]==computerSide) {
				for(int r=0; r<4; r++) {
					int k=0,m,n,bj=0,x,y;    //k�洢�����ɵĸ���,bjΪ���
					for(int qqq=-2; qqq<0; qqq++) { //̽�鵽�ĵ��ǰ����,������ҷ�����
						x=i+qqq*dv[r];
						y=j+qqq*dw[r];
						if(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==computerSide) {
							bj=1;
							break;
						}
					}
					if(bj==1) { //������������˳����ѭ��
						continue;
					}
					for(int qqq=-1; qqq<0; qqq++) { //̽�鵽�ĵ��ǰ1��,����ǶԷ����ӻ���
						x=i+qqq*dv[r];
						y=j+qqq*dw[r];
						if(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==1-computerSide||(x<0||y<0||x>=19||y>=19)) {
							bj=1;
							break;
						}
					}
					if(bj==1) { //������������˳����ѭ��
						continue;
					}
					int jug=0;//�ж��Ƿ�����,0Ϊ��������1Ϊ����
					for(int qqq=1; qqq<4; qqq++) { //̽���3����
						x=i+qqq*dv[r];
						y=j+qqq*dw[r];
						if(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==computerSide) {
							k++;
						}
						if(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==1-computerSide||(x<0||y<0||x>=19||y>=19)) {
							bj=1;
							break;
						}
						if(qqq==3&&(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==EMPTY)) {
							jug=1;
						}
					}
					if(bj==1) { //������������˳����ѭ��
						continue;
					}
					if(jug==0) {
						for(int qqq=4; qqq<6; qqq++) { //̽���4-5��,������ҷ����ӣ������������������
							x=i+qqq*dv[r];
							y=j+qqq*dw[r];
							if(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==computerSide) {
								bj=1;
								break;
							}
						}
						if(bj==1) { //������������˳����ѭ��
							continue;
						}
						for(int qqq=4; qqq<5; qqq++) { //̽���4����,����ǶԷ����ӻ���Ϊǽ
							x=i+qqq*dv[r];
							y=j+qqq*dw[r];
							if(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==1-computerSide||(x<0||y<0||x>=19||y>=19)) {
								bj=1;
								break;
							}
						}
						if(bj==1) { //������������˳����ѭ��
							continue;
						}
					} else {
						//����д�������Ĵ���
						int x1,y1,k1=0;
						x1=i;
						y1=j;
						while(y1>=0&&x1>=0&&y1<19&&x1<19&&Board[x][y]==EMPTY) {
							k1++;
							x1=x1-dv[r];
							y1=y1-dw[r];
						}
						x1=i+3*dv[r];
						y1=j+3*dw[r];
						while(y1>=0&&x1>=0&&y1<19&&x1<19&&Board[x][y]==EMPTY&&k1<=3) {
							k1++;
							x1=x1+dv[r];
							y1=y1+dw[r];
						}
						x1=i+3*dv[r];
						y1=j+3*dw[r];
						if(x1<0||y1<0||x1>=19||y1>=19||Board[x1][y1]==1-computerSide) {
							bj=1;         //�����һ�˱��¾ͷ��ش���
						}
						if(k1<=3) {      //��λ���������ͷ��ش���
							bj=1;
						}
					}
					if(bj==1) { //������������˳����ѭ��
						continue;
					}
					if(k==2) {
						fuhe[ttt].X=i;//��¼�·������������
						fuhe[ttt].Y=j;
						fuhe[ttt].fx=r;
						ttt++;
					}
					if(ttt==2) {
						break;
					}
				}
			}
			if(ttt==2)
				break;
		}
		if(ttt==2)
			break;
	}
	if(ttt==2)
		return true;
	if(ttt==0)
		return false;
	for(int i=0; i<19; i++) {
		for(int j=0; j<19; j++) {
			if(Board[i][j]==computerSide) {
				for(int r=0; r<4; r++) {
					int k=0,m,n,bj=0,x,y;    //k�洢�����ɵĸ���,bjΪ���
					for(int qqq=-2; qqq<0; qqq++) { //̽�鵽�ĵ��ǰ����,������ҷ�����
						x=i+qqq*dv[r];
						y=j+qqq*dw[r];
						if(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==computerSide) {
							bj=1;
							break;
						}
					}
					if(bj==1) { //������������˳����ѭ��
						continue;
					}
					int jug=0;//�ж��Ƿ�����,0Ϊ��������1Ϊ����
					for(int qqq=1; qqq<4; qqq++) { //̽���3����
						x=i+qqq*dv[r];
						y=j+qqq*dw[r];
						if(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==computerSide) {
							k++;
						}
						if(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==1-computerSide||(x<0||y<0||x>=19||y>=19)) {
							bj=1;
							break;
						}
						if(qqq==3&&(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==EMPTY)) {
							jug=1;
						}
					}
					if(bj==1) { //������������˳����ѭ��
						continue;
					}
					if(jug==0) {
						int m1,n1,m2,n2,t1=0,t2=0;    //t����ı߱���
						m1=i-dv[r];
						n1=j-dw[r];
						m2=i+4*dv[r];
						n2=j+4*dw[r];
						if(m1<0||m1>=19||n1<0||n1>=19||Board[m1][n1]==1-computerSide) {
							t1=1;
						}
						if(m2<0||m2>=19||n2<0||n2>=19||Board[m2][n2]==1-computerSide) {
							t2=1;
						}
						if((t1==1&&t2==1)||(t1==0&&t2==0)) {
							bj=1;                  //���߶����»��߶���
						} else {
							if(t1==1) {
								m2+=dv[r];
								n2+=dw[r];
								if(m2<0||m2>=19||n2<0||n2>=19||Board[m2][n2]==1-computerSide) {
									bj=1;           //�����һ�߲�������������
								}
							}
							if(t2==1) {
								m1-=dv[r];
								n1-=dw[r];
								if(m1<0||m1>=19||n1<0||n1>=19||Board[m1][n1]==1-computerSide) {
									bj=1;           //�����һ�߲�������������
								}
							}
						}
					} else {
						int m1,n1,m2,n2,t1=0,t2=0;    //t����ı߱���
						m1=i-dv[r];
						n1=j-dw[r];
						m2=i+3*dv[r];
						n2=j+3*dw[r];
						if(m1<0||m1>=19||n1<0||n1>=19||Board[m1][n1]==1-computerSide) {
							t1=1;
						}
						if(m2<0||m2>=19||n2<0||n2>=19||Board[m2][n2]==1-computerSide) {
							t2=1;
						}
						if((t1==1&&t2==1)||(t1==0&&t2==0)) {
							bj=1;                  //���߶����»��߶���
						} else {
							if(t1==1) {
								for(int i1=0; i1<3; i1++) {
									m2=i+(3+i1)*dv[r];
									n2=j+(3+i1)*dw[r];
									if(m2<0||m2>=19||n2<0||n2>=19||Board[m2][n2]==1-computerSide) {
										bj=1;           //�����һ�߲�������������
									}
								}
							}
							if(t2==1) {
								for(int i1=0; i1<3; i1++) {
									m1=i-(1+i1)*dv[r];
									n1=j-(1+i1)*dw[r];
									if(m1<0||m1>=19||n1<0||n1>=19||Board[m1][n1]==1-computerSide) {
										bj=1;           //�����һ�߲�������������
									}
								}
							}
						}
					}
					if(bj==1) { //������������˳����ѭ��
						continue;
					}
					if(k==2) {
						fuhe1[ttt1].X=i;//��¼�·������������
						fuhe1[ttt1].Y=j;
						fuhe1[ttt1].fx=r;
						ttt1++;
					}
					if(ttt1==1)
						break;
				}
			}
			if(ttt1==1)
				break;
		}
		if(ttt1==1)
			break;
	}


	if(ttt==1&&ttt1==1) {
		fuhe[1].X=fuhe1[0].X;
		fuhe[1].Y=fuhe1[0].Y;
		fuhe[1].fx=fuhe1[0].fx;
		return true;
	}
	return false;
}

bool JudgeFourOrFive(int Board[19][19],int colour) {
	int dv[8]= {0,0,1,-1,1,-1,-1,1};
	int dw[8]= {1,-1,0,0,1,-1,1,-1}; //�����򣬷ֱ�Ϊ�£��ϣ��ң������£����ϣ����£�����
	for(int i=0; i<19; i++) {
		for(int j=0; j<19; j++) {
			if(Board[i][j]==colour) { //��������ǰ���������ӵ���ɫΪcolour
				for(int r=0; r<8; r++) { //�����˸�����
					int num=1;
					for(int k=1; k<6; k++) { //������ǰ�����µ���������
						if((i+dv[r]*5)>=19||(i+dv[r]*5)<0||(j+dw[r]*5)>=19||(j+dw[r]*5)<0)//�жϰ��յ�ǰ��������������ӻ᲻��Խ��
							break;//���Խ�磬����ѭ��������������һ���������������
						if(Board[i+dv[r]*k][j+dw[r]*k]==colour)
							num++;//������ǰ��ɫ�����ӣ�num��һ
					}
					if(num!=4||num!=5)//�����������������ɫΪcolour�����Ӳ���4����5�� ����ô��ô�¶�����ֱ��Ӯ
						continue; //������һ����
					else if(num==5) { //��������������5��colour��ɫ�����ӣ������µ��Ǹ�����ֻҪΪ�գ�����colourɫ����ͻ�Ӯ
						for(int k=1; k<6; k++) {
							if(Board[i+dv[r]*k][j+dw[r]*k]==2) { //�ҵ�Ϊ�յ�����
								struct a* aa=new a;
								aa->x=i+dv[r]*k;
								aa->y=j+dw[r]*k;
								PointSet1.push_back(*aa);
							}
						}
					} else if(num==4) { //��������������4��colour��ɫ�����ӣ������µ�������������Ϊ�գ���������colourɫ����ͻ�Ӯ
						struct b* bb=new b;
						int m=0;//�ж��ǰ��������x��y����x1��y1
						int counter=0; //�ж����������������м���Ϊ��
						for(int k=1; k<6; k++) {
							if(Board[i+dv[r]*k][j+dw[r]*k]==2) {
								if(m==0) {
									counter++;
									bb->x1=i+dv[r]*k;
									bb->y1=j+dw[r]*k;
									m=1;//����x��y֮��ı�m ,�´��x1��y1����
								} else if(m==1) {
									counter++;
									bb->x2=i+dv[r]*k;
									bb->y2=j+dw[r]*k;
								}
							}
						}
						if(counter==2) { //����������궼Ϊ��
							PointSet2.push_back(*bb);
						}
					}
				}
			} else //��ǰ��������ɫ��Ϊcolour���ӵĻ�������һѭ��
				continue;
		}
	}
	if(PointSet1.size()==0&&PointSet2.size()==0)//���PointSet1��PointSet2��Ϊ�գ�˵����ǰ����в����ڿ���ֱ��Ӯ�����
		return false;

	vector<a>::iterator Point1,P;
	vector<b>::iterator Point2,H;
	//ȥ��1�����ڱ����˰˸�����ʵ���ϣ������������õ��Ľ�����ظ���������������
	for(Point1=PointSet1.begin(); Point1!=PointSet1.end()-1; Point1++) { //ȥ��
		for(P=Point1+1; P!=PointSet1.end(); P++) {
			if((*Point1).x==(*P).x&&(*Point1).y==(*P).y) {
				PointSet1.erase(P);
				P--;
			}
		}
	}
	for(Point2=PointSet2.begin(); Point2!=PointSet2.end()-1; Point2++) { //ȥ��
		for(H=Point2+1; H!=PointSet2.end(); H++) {
			if((*Point2).x1==(*H).x1&&(*Point2).y1==(*H).y1&&(*Point2).x2==(*H).x2&&(*Point2).y2==(*H).y2) {
				PointSet2.erase(H);
				H--;
			}
		}
	}
	//ȥ��2������5���ӵ�������ܰ���4���ӵ�����������е�ֻ��һ����Ϳ�ʤ�������������������ʤ�����������Ҳ��¼�ˣ���ʱ�������ӵ���ؼ�¼ɾ��
	for(Point1=PointSet1.begin(); Point1!=PointSet1.end(); Point1++) {
		for(Point2=PointSet2.begin(); Point2!=PointSet2.end();) {
			if(((*Point1).x==(*Point2).x1&&(*Point1).y==(*Point2).y1)||((*Point1).x==(*Point2).x2&&(*Point1).y==(*Point2).y2))
				PointSet2.erase(Point2);
			else
				Point2++;
		}
	}
	return true;
}

int main() {
	Step step;//��ʱ���ṹ
	char message[256];//ͨ����Ϣ����
	int computerSide;//����ִ����ɫ
	int start=0;//�Ծֿ�ʼ���
	srand(int(time(0)));
	//�˴����ó�ʼ������
	//...

	while (1) {	//������ѭ��
		fflush(stdout);//��Ҫɾ������䣬�������������
		scanf("%s", message);//��ȡƽ̨������Ϣ
		//��������
		if (strcmp(message, "name?") == 0) { //���սƽ̨���Ͷ���
			fflush(stdin);
			/***********��"�����"��Ϊ��Ķ�����������6�����ֻ�12��Ӣ����ĸ�������޳ɼ�************/
			/*******/		printf("name �������\n");		/**ֻ�޸�����壬��Ҫɾ��name�ո�****/
			/***********��"�����"��Ϊ��Ķ�����������6�����ֻ�12��Ӣ����ĸ�������޳ɼ�************/
		} else if (strcmp(message, "new") == 0) { //���������
			int i, j;
			scanf("%s", message);//��ȡ����ִ����ɫ
			fflush(stdin);
			if (strcmp(message, "black") == 0)	computerSide = BLACK;  //ִ��
			else  computerSide = WHITE;   //ִ��

			for (i = 0; i<19; ++i)   //��ʼ�����
				for (j = 0; j<19; ++j)
					Board[i][j] = EMPTY;
			start = 1;

			if (computerSide == BLACK) {
				/**********���ɵ�һ���ŷ�����������step�ṹ�У���������Ϊ(step.first.x,step.first.y)**********/
				/****************************���·������룬���滻�ҵ�ʾ������******************************/


				step.first.x = 9;
				step.first.y = 9;


				/******************************����������һ���������*******************************************/

				Board[step.first.x][step.first.y] = computerSide;//����������
				printf("move %c%c@@\n", step.first.x + 'A', step.first.y + 'A');//����ŷ�
			}
		} else if(strcmp(message,"move")==0) { //����,���������
			scanf("%s", message);//��ȡ���������ŷ�
			fflush(stdin);
			step.first.x=message[0]-'A';
			step.first.y=message[1]-'A';
			step.second.x=message[2]-'A';
			step.second.y=message[3]-'A';
			//�����������
			Board[step.first.x][step.first.y] = 1 - computerSide;
			if(!(step.second.x==-1 && step.second.y==-1)) Board[step.second.x][step.second.y] = 1 - computerSide;

			/**********************************************************************************************************/
			/***�������ӵ����꣬������step�ṹ�У���1������(step.first.x,step.first.y)����2������(step.first.x,step.first.y)*****/
			/**************************************���·������룬���滻�ҵ�ʾ������*****************************************/
			//���ɵ�1������λ��step.first.x��step.first.y

//			int x, y;
//			x = rand() % 19; y = rand() % 19;
//			while (Board[x][y] != EMPTY)
//			{
//				x = rand() % 19;	y = rand() % 19;
//			}
//			step.first.x = x;
//			step.first.y = y;
//			Board[step.first.x][step.first.y] = computerSide;
//
//			//���ɵ�2������λ��step.second.x��step.second.y
//			x = rand() % 19;	y = rand() % 19;
//			while (Board[x][y] != EMPTY)
//			{
//				x = rand() % 19;	y = rand() % 19;
//			}
//			step.second.x = x;
//			step.second.y = y;
//			Board[step.second.x][step.second.y] = computerSide;
			bool judge;
			judge=JudgeFourOrFive(Board,computerSide);
			if(judge==true) {
				//�����Ľ������Ӵ���

			}
			if(judge==false&&JudgeFourOrFive(Board,1-computerSide)) {
				judge=true;
				//�����ķ������Ӵ���

			}
			if(judge==false&&JudgeThree(Board,computerSide)) {
				judge=true;
				//������Ӵ���
				int dv[4]= {0,1,1,-1};
				int dw[4]= {1,0,1,1}; //�����򣬷ֱ�Ϊ�£��ң����£���
				int x,y;
				for(int i=-1; i<15; i++) {
					int bj=0;
					x=fuhe[0].X+i*dv[fuhe[0].fx];
					y=fuhe[0].Y+i*dw[fuhe[0].fx];
					if(Board[x][y]==EMPTY) {
						step.first.x=x;
						step.first.y=y;
						bj=1;
						break;
					}
					if(bj==1) {
						break;
					}
				}
				if(Board[step.first.x][step.first.y]!=EMPTY||x<0||x>=19||y<0||y>=19) {
					judge=false;
				} else {
					Board[step.first.x][step.first.y] = computerSide;
				}
				for(int i=-1; i<19; i++) {
					int bj=0;
					x=fuhe[1].X+i*dv[fuhe[1].fx];
					y=fuhe[1].Y+i*dw[fuhe[1].fx];
					if(Board[x][y]==EMPTY) {
						step.second.x=x;
						step.second.y=y;
						bj=1;
						break;
					}
					if(bj==1) {
						break;
					}
				}
				if(Board[step.second.x][step.second.y]!=EMPTY||x<0||x>=19||y<0||y>=19) {
					judge=false;
				} else {
					Board[step.second.x][step.second.y] = computerSide;
				}
			}
			if(judge==false&&JudgeThree(Board,1-computerSide)) {
				judge=true;
				//������Ӵ���
				int dv[4]= {0,1,1,-1};
				int dw[4]= {1,0,1,1}; //�����򣬷ֱ�Ϊ�£��ң����£���
				int x,y;
				for(int i=-1; i<19; i++) {
					int bj=0;
					x=fuhe[0].X+i*dv[fuhe[0].fx];
					y=fuhe[0].Y+i*dw[fuhe[0].fx];
					if(Board[x][y]==EMPTY) {
						step.first.x=x;
						step.first.y=y;
						bj=1;
						break;
					}
					if(bj==1) {
						break;
					}
				}
				if(Board[step.first.x][step.first.y]!=EMPTY||x<0||x>=19||y<0||y>=19) {
					judge=false;
				} else {
					Board[step.first.x][step.first.y] = computerSide;
				}
				for(int i=-1; i<15; i++) {
					int bj=0;
					x=fuhe[1].X+i*dv[fuhe[1].fx];
					y=fuhe[1].Y+i*dw[fuhe[1].fx];
					if(Board[x][y]==EMPTY) {
						step.second.x=x;
						step.second.y=y;
						bj=1;
						break;
					}
					if(bj==1) {
						break;
					}
				}
				if(Board[step.second.x][step.second.y]!=EMPTY||x<0||x>=19||y<0||y>=19) {
					judge=false;
				} else {
					Board[step.second.x][step.second.y] = computerSide;
				}
			}
			if(judge==false) {
				//������Ӵ���
				int dv[8]= {0,0,1,-1,1,-1,-1,1};
				int dw[8]= {1,-1,0,0,1,-1,1,-1}; //�����򣬷ֱ�Ϊ�£��ϣ��ң������£����ϣ����£�����

				int bj=0;
				for(int i=0; i<19; i++) {
					for(int j=0; j<19; j++) {
						if(Board[i][j]!=EMPTY) {
							for(int r=0; r<8; r++) {
								int x=i+dv[r];
								int y=j+dw[r];
								if(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==EMPTY) {
									step.first.x=x;
									step.first.y=y;
									bj++;
								}
								if(bj==1)
									break;
							}
						}
						if(bj==1)
							break;
					}
					if(bj==1)
						break;

				}
				Board[step.first.x][step.first.y] = computerSide;

				bj=0;
				for(int i=0; i<19; i++) {
					for(int j=0; j<19; j++) {
						if(Board[i][j]!=EMPTY) {
							for(int r=0; r<8; r++) {
								int x=i+dv[r];
								int y=j+dw[r];
								if(x>=0&&y>=0&&x<19&&y<19&&Board[x][y]==EMPTY) {
									step.second.x=x;
									step.second.y=y;
									bj++;
								}
								if(bj==1)
									break;
							}
						}
						if(bj==1)
							break;
					}
					if(bj==1)
						break;

				}
				Board[step.second.x][step.second.y] = computerSide;
			}




			/*****************************************������������******************************************************/
			/**********************************************************************************************************/

			printf("move %c%c%c%c\n",step.first.x+'A',step.first.y+'A',step.second.x+'A',step.second.y+'A');//����ŷ�
		} else if (strcmp(message, "error") == 0) { //�ŷ�����
			fflush(stdin);
		} else if (strcmp(message, "end") == 0) { //�Ծֽ���
			fflush(stdin);
			start = 0;
		} else if (strcmp(message, "quit") == 0) { //�˳�����
			fflush(stdin);
			printf("Quit!\n");
			break;
		}
	}
	return 0;
}
