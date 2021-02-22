/*�̵߳Ļ������� */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<windows.h>


/* ���߳�1 */
void *thread_routine1(void *arg)
{
    fprintf(stdout, "thread1: Hello world!\n");
    Sleep(1);
    return NULL;
}

/* ���߳�2 */
void *thread_routine2(void *arg)
{
    fprintf(stdout, "thraed2: I'm running...\n");
    pthread_t main_thread = (pthread_t)arg;

    /* �������� */
    pthread_detach(pthread_self());
    /* �ж��߳�1 ���߳�2 �Ƿ���� */
    if(!pthread_equal(main_thread, pthread_self())){
        fprintf(stdout, "thread2: main thread id is not equal thread2\n");
    }

    /* �ȴ��߳���ֹ */
    pthread_join(main_thread, NULL);
    fprintf(stdout, "thread2: main thread exit!\n");
    fprintf(stdout, "thread2: exit!\n");
    fprintf(stdout, "thread2: process exit!\n");

    /* ���߳�2 ��ֹ�������˳� */
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{

    /* �������߳�1 */
    pthread_t t1;
    if(pthread_create(&t1, NULL, thread_routine1, NULL)!=0)
    {
        fprintf(stderr, "create thread fail.\n");
        exit(-1);
    }

    /*�ȴ����߳�1��ֹ*/
    pthread_join(t1, NULL);
    fprintf(stdout, "main thread: thread1 terminated!\n\n");

    /* �������߳�2�� �������߳�id �������߳�2 */
    pthread_t t2;
    if(pthread_create(&t2, NULL, thread_routine2, (void *)pthread_self())!=0)
    {
        fprintf(stderr, "create thread fail.\n");
        exit(-1);
    }

    fprintf(stdout, "main thread: sleeping...\n");
    Sleep(3);

    /* ���߳�ʹ�� pthread_exit ������ֹ�����̼������� */
    fprintf(stdout,"main thread: exit!\n");
    pthread_exit(NULL);

    fprintf(stdout, "main thread: never reach here!\n");
    return 0;

}
