#include<iostream>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
char A[20];                                          /*����ջ*/
char B[20];                                          /*ʣ�മ*/
char v1[20]= {'i','+','*','(',')','#'};              /*�ս��*/
char v2[20]= {'E','G','T','S','F'};                  /*���ս��*/
int j=0,b=0,top=0,l;                                 /*LΪ���봮����*/
class type                                           /*����ʽ���Ͷ���*/
{
public:
    char origin;                                     /*��д�ַ�*/
    char array[5];                                   /*����ʽ�ұ��ַ� */
    int length;                                      /*�ַ�����*/
};
type e,t,g,g1,s,s1,f,f1;                             /*�����*/
type C[10][10];                                      /*������*/
int main()
{
    int m,n,k=0,flag=0,finish=0;
    char ch,x;
    type cha;                                        /*��������C[m][n]*/
    /*���ķ�����ʽ��ֵ�ṹ��*/
    e.origin='E';
    strcpy(e.array,"TG");
    e.length=2;
    t.origin='T';
    strcpy(t.array,"FS");
    t.length=2;
    g.origin='G';
    strcpy(g.array,"+TG");
    g.length=3;
    g1.origin='G';
    g1.array[0]='^';
    g1.length=1;
    s.origin='S';
    strcpy(s.array,"*FS");
    s.length=3;
    s1.origin='S';
    s1.array[0]='^';
    s1.length=1;
    f.origin='F';
    strcpy(f.array,"(E)");
    f.length=3;
    f1.origin='F';
    f1.array[0]='i';
    f1.length=1;
    for(m=0; m<=4; m++)
        for(n=0; n<=5; n++)
            C[m][n].origin='N';
    C[0][0]=e;
    C[0][3]=e;
    C[1][1]=g;
    C[1][4]=g1;
    C[1][5]=g1;
    C[2][0]=t;
    C[2][3]=t;
    C[3][1]=s1;
    C[3][2]=s;
    C[3][4]=C[3][5]=s1;
    C[4][0]=f1;
    C[4][3]=f;
    cout<<"�����ַ���:";
    bool flag1=0;
    bool flag2=0;
    bool flag3=0;
    do/*���������*/
    {
        cin>>ch;
        if(ch=='-')
        {
            ch='+';
        }

        if(ch=='/')
        {
            ch='*';
        }

        if(((ch>='0'&&ch<= '9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))&&(flag3==0))
        {
            if(ch>='0'&&ch<= '9')
                flag2=1;
            ch='i';
            if(flag1==1)
            {
                continue;
            }
            flag1=1;
        }
        else if(flag3==1)
        {
            flag1=1;
            flag3=0;
            continue;
        }
        else if(ch!='.')
            flag1=0;

        if((ch=='.')&&(flag2==1))
        {
            flag2=0;
            flag3=1;
            continue;
        }

        B[j]=ch;
        j++;
    }
    while(ch!='#');
    l=j;//����
    ch=B[0];//��ǰ�ַ�
    A[top]='#';
    A[++top]='E';
    do
    {
        x=A[top--];/*xΪ��ǰջ���ַ�*/
        for(j=0; j<=5; j++)
            if(x==v1[j])
            {
                flag=1;
                break;
            }
        if(flag==1)
        {
            if(x=='#')
            {
                finish=1;
                cout<<"����!\n";
                return 0;
            }
            if(x==ch)
            {
                ch=B[++b];
                flag=0;
            }
            else
            {
                cout<<"����\n"<<ch;//����
                exit(1);
            }
        }
        else
        {
            for(j=0; j<=4; j++)
                if(x==v2[j])
                {
                    m=j;/*�к�*/
                    break;
                }
            for(j=0; j<=5; j++)
                if(ch==v1[j])
                {
                    n=j;/*�к�*/
                    break;
                }
            cha=C[m][n];
            if(cha.origin!='N')/*�ж��Ƿ�Ϊ��*/
            {
                for(j=(cha.length-1); j>=0; j--)            /*����ʽ������ջ*/
                    A[++top]=cha.array[j];
                if(A[top]=='^')/*Ϊ�ղ���ջ*/
                    top--;
            }
            else
            {
                cout<<"����"<<x;//����
                exit(1);
            }
        }
    }
    while(finish==0);
    return 0;
}
