#include <algorithm>
#include <string>
#include <iostream>

using namespace std;
#define SIZE 256    //�ַ����ַ���
void generateBadChar(char *b, int m, int *badchar)//(ģʽ���ַ�b��ģʽ������m��ģʽ���Ĺ�ϣ��)
{
    int i, ascii;
    for(i = 0; i < SIZE; ++i)
    {
        badchar[i] = -1;//��ϣ���ʼ��Ϊ-1
    }
    for(i = 0; i < m; ++i)
    {
        ascii = int(b[i]);  //�����ַ���ASCIIֵ
        badchar[ascii] = i;//�ظ��ַ������ǣ���¼���������ֵĸ��ַ���λ��
    }
}
void generateGS(char *b, int m, int *suffix, bool *prefix)//Ԥ����ģʽ�������suffix��prefix
{
    int i, j, k;
    for(i = 0; i < m; ++i)//���������ʼ��
    {
        suffix[i] = -1;
        prefix[i] = false;
    }
    for(i = 0; i < m-1; ++i)//b[0,i]
    {
        j = i;
        k = 0;//������׺�Ӵ�����(ģʽ��β��ȡk���������ֱ�Ƚ�)
        while(j >= 0 && b[j] == b[m-1-k])//��b[0,m-1]�󹫹���׺�Ӵ�
        {
            --j;
            ++k;
            suffix[k] = j+1;
            //��ͬ��׺�Ӵ�����Ϊkʱ�����Ӵ���b[0,i]�е���ʼ�±�
            // (����ж����ͬ���ȵ��Ӵ�������ֵ���ǣ���ϴ��)
        }
        if(j == -1)//���ҵ�ģʽ����ͷ����
            prefix[k] = true;//���������׺�Ӵ�Ҳ��ģʽ����ǰ׺�Ӵ�
    }
}
int moveByGS(int j, int m, int *suffix, bool *prefix)//�����j�ǻ��ַ���Ӧ��ģʽ���е��ַ��±�
{
    int k = m - 1 - j;//�ú�׺����
    if(suffix[k] != -1)//case1���ҵ����ú�׺һ����ģʽ�Ӵ�������Ļ�����Ŀ�����Ǹ����Ӵ���ʼ�±꣩��
        return j - suffix[k] + 1;
    for(int r = j + 2; r < m; ++r)//case2
    {
        if(prefix[m-r] == true)//m-r�Ǻú�׺���Ӵ��ĳ��ȣ��������ú�׺���Ӵ���ģʽ����ǰ׺�Ӵ�
            return r;//������û���ҵ���ͬ�ĺú�׺�£��ƶ�rλ������ǰ׺���ú�׺
    }
    return m;//case3,��û��ƥ��ģ��ƶ�mλ��ģʽ�����ȣ�
}
int str_bm(char *a, int n, char *b, int m)//a��ʾ��������n; b��ʾģʽ��,��m
{
    int badchar[SIZE];//��¼ģʽ����ÿ���ַ������ֵ�λ��
    generateBadChar(b,m,badchar);     //�������ַ���ϣ��
    int suffix[m];
    bool prefix[m];
    generateGS(b, m, suffix, prefix);   //Ԥ����ģʽ�������suffix��prefix
    int i = 0, j, moveLen1, moveLen2;//j��ʾ������ģʽ��ƥ��ĵ�һ���ַ�
    while(i < n-m+1)
    {
        for(j = m -1; j >= 0; --j)  //ģʽ���Ӻ���ǰƥ��
        {
            if(a[i+j] != b[j])
                break;  //���ַ���Ӧģʽ���е��±���j
        }
        if(j < 0)   //ƥ��ɹ�
        return i;   //����������ģʽ����һ��ƥ����ַ���λ��
        //�����ͬ�ڽ�ģʽ�����󻬶� j-badchar[int(a[i+j])] λ
        moveLen1 = j - badchar[int(a[i+j])];//���ջ��ַ������ƶ�����
        moveLen2 = 0;
        if(j < m-1)//����кú�׺�Ļ�
        {
            moveLen2 = moveByGS(j,m,suffix,prefix);//���պú�׺�����ƶ�����
        }
        i = i + max(moveLen1,moveLen2);//ȡ����ƶ�
    }
    return -1;
}

int main()
{
	//cbacabc;
    string a = "abcabcxxxabcabc", b = "abcabc";
    cout << a << "�е�һ�γ���" << b << "��λ��(��0��ʼ)�ǣ�" << str_bm(&a[0],a.size(),&b[0],b.size());
    return 0;
}
