#include<iostream>
using namespace std;
int Find_Substr(string str1, string str2) {
	int m=str1.size();
	int n=str2.size();
	int i=0,j=0;//iָ��Դ����λ jָ���Ӵ���λ
	int k;
	int m=n;//��һ��ƥ��ʱ Դ���в���ƥ���Ԫ�ص���һλ

	for(; i<m;) {
		if(str1[i]!=str2[j]) {
			for(k=n-1; k>=0; k--) { //�������Ҵ�ʱ�Ӵ���Դ��[i+n+1]��ȵ�����λ��
				if(str2[k]==str1[m])
					break;
			}
			i=m-k;//iΪ��һ��ƥ��Դ����ʼ��λ Sunday�㷨���ģ�����޶�������ͬԪ��
			j=0;//j��ȻΪ�Ӵ���λ
			m=i+n;//mΪ��һ�β���ƥ���Դ�����һλԪ�ص���һλ
			if(m>m)//����һ�β���ƥ���Դ�����������һλ����һλ����Դ������ʱ
				return -1;
		} else {
			if(j==n-1)//��jΪ�Ӵ�ĩλ ƥ��ɹ� ����Դ����ʱƥ����λ
				return i-j;
			i++;
			j++;
		}
	}
	return -1;//������Դ������ʱ
}


int Find_good_postfix(string s) {
	int n=s.size();
	int Array[100000];
	int i=0;
	int j=n-1;
	int mm=0;
	for(int k=1; k<=n-1; k++) {
		string str1=s.substr(n-k,k);
		string str2=s.substr(0,n-1);
		if(strStr(str2,str1)!=-1) {
			Array[mm]=k;
			mm++;
		}
	}
	if(mm==0)
		return 0;
	else
		return Array[mm-1];
}
int main () {
	string str;//������ַ��������Ȳ�����100000
	cin>>str;
	cout<<Find_good_postfix(str)<<endl;
}
