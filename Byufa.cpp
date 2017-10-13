#include <cstdio>
#include<iostream>
#include<string>
using namespace std;

string KT[6] = {"int","main","void","if","else","char"};
string PT[17] = {">=","<=","==","=",">","<","+","-","*","/","{","}",",",";","(",")","#"};
int state,i=0,x=0;
char tmp;
string print="";
int o;
char input[20];

void e();
void e1();
void t();
void t1();
void f();

void output()
{

    if(print[0]=='(')
        input[x]='(';
    else if(print[0]==')')
        input[x]=')';
    else if(print[0]=='#')
        input[x]='#';
    else if(print[0]=='+'||print[0]=='-')
        input[x]='+';
    else if(print[0]=='*'||print[0]=='/')
        input[x]='*';
    else if(print[0]>='0'&&print[0]<= '9'||print[0]>='a'&&print[0]<='z'||print[0]>='A'&&print[0]<='Z')
        input[x]='i';
    else
        cout<<"error";
    cout<<input[x];
    state=1;
    x++;
    print="";
}

void get()
{
    if(tmp==' '||tmp=='\n'||tmp=='\t'||tmp=='\b')
    {
        o=1;
        return;
    }
    if(state==1)
    {
        if(tmp>='a'&&tmp<='z'||tmp>='A'&&tmp<='Z')
        {
            state=2;
            print+=tmp;
            o=0;
        }
        else if(tmp>='0'&&tmp<='9')
        {
            state=3;
            print+=tmp;
            o=0;
        }
        else if(tmp=='\'')
        {
            state=9;
            print+=tmp;
            o=0;
        }
        else if(tmp=='"')
        {
            state=11;
            print+=tmp;
            o=0;
        }
        else if(tmp=='>')
        {
            state=4;
            print+=tmp;
            o=0;
        }
        else if(tmp=='<')
        {
            state=5;
            print+=tmp;
            o=0;
        }
        else if(tmp=='=')
        {
            state=6;
            print+=tmp;
            o=0;
        }
        else if(tmp=='+')
        {
            state=18;
            print+=tmp;
            o=1;
        }
        else if(tmp=='-')
        {
            state=19;
            print+=tmp;
            o=1;
        }
        else if(tmp=='*')
        {
            state=20;
            print+=tmp;
            o=1;
        }
        else if(tmp=='/')
        {
            state=21;
            print+=tmp;
            o=1;
        }
        else if(tmp=='{')
        {
            state=22;
            print+=tmp;
            o=1;
        }
        else if(tmp=='}')
        {
            state=23;
            print+=tmp;
            o=1;
        }
        else if(tmp==',')
        {
            state=24;
            print+=tmp;
            o=1;
        }
        else if(tmp==';')
        {
            state=25;
            print+=tmp;
            o=1;
        }
        else if(tmp=='(')
        {
            state=26;
            print+=tmp;
            o=1;
        }
        else if(tmp==')')
        {
            state=27;
            print+=tmp;
            o=1;
        }
        else if(tmp=='#')
        {
            state=28;
            print+=tmp;
            o=1;
        }
    }
    else if(state==2)
    {
        if(tmp>='a'&&tmp<='z'||tmp>='A'&&tmp<='Z'||tmp>='0'&&tmp<='9')
        {
            state=2;
            print+=tmp;
            o=0;
        }
        else
        {
            output();
            get();
        }
    }
    else if(state==3)
    {
        if(tmp>='0'&&tmp<='9')
        {
            state=3;
            print+=tmp;
            o=0;
        }
        else if(tmp=='.')
        {
            state=8;
            print+=tmp;
            o=0;
        }
        else
        {
            output();
            get();
        }
    }
    else if(state==8)
    {
        if(tmp>='0'&&tmp<='9')
        {
            state=7;
            print+=tmp;
            o=0;
        }
        else
            cout<<"error"<<endl;
        return;
    }
    else if(state==7)
    {
        if(tmp>='0'&&tmp<='9')
        {
            state=7;
            print+=tmp;
            o=0;
        }
        else
        {
            output();
            get();
        }
    }
    else if(state==4)
    {
        if(tmp=='=')
        {
            state=13;
            print+=tmp;
            o=0;
        }
        else
        {
            output();
            get();
        }
    }
    else if(state==5)
    {
        if(tmp=='=')
        {
            state=14;
            print+=tmp;
            o=0;
        }
        else
        {
            output();
            get();
        }
    }
    else if(state==6)
    {
        if(tmp=='=')
        {
            state=15;
            print+=tmp;
            o=0;
        }
        else
        {
            output();
            get();
        }
    }
    else if(state==9)
    {
        state=10;
        print+=tmp;
        o=0;
    }
    else if(state==10)
    {
        if(tmp=='\'')
        {
            state=16;
            print+=tmp;
            o=0;
        }
        else if((tmp>='a'&&tmp<='z')||(tmp>='A'&&tmp<='Z'))
        {
            cout<<"error"<<endl;
            return;
        }
    }
    else if(state==11)
    {
        if((tmp>='a'&&tmp<='z')||(tmp>='A'&&tmp<='Z'))
        {
            state=12;
            print+=tmp;
            o=0;
        }
    }
    else if(state==12)
    {
        if((tmp>='a'&&tmp<='z')||(tmp>='A'&&tmp<='Z'))
        {
            state=12;
            print+=tmp;
            o=0;
        }
        else if(tmp=='"')
        {
            state=17;
            print+=tmp;
            o=0;
        }
    }
    else if(state>=13&&state<=17)
    {
        output();
        get();
    }
}

void e()
{
    cout<<"E->TE'"<<endl;
    t();
    e1();
}

void e1()
{
    if(input[i]=='+')
    {
        cout<<"E'->+TE'"<<endl;
        i++;
        t();
        e1();
    }
    else if (input[i]!='#'&&input[i]!=')')
    {
        cout<<"T'->^"<<endl;
        return ;
    }
    else
        int r=0;
}

void t()
{
    cout<<"T->FT'"<<endl;
    f();
    t1();
}

void t1()
{
    if(input[i]=='*')
    {
        cout<<"T'->*FT'"<<endl;
        i++;
        f();
        t1();
    }
    else if (input[i]!='#'&&input[i]!=')'&&input[i]!='+')
    {
        cout<<"T'->^"<<endl;
        int r=0;
    }
}

void f()
{
    if(input[i]=='i')
    {
        cout<<"F->i"<<endl;
        i++;
    }
    else if(input[i]=='(')
    {
        cout<<"F->(E)"<<endl;
        i++;
        e();
        if(input[i]==')')
        {
            cout<<"F->(E)"<<endl;
            i++;
        }
        else
            int r=0;
    }
    else int r=0;
}

int main()
{
    int r;
    int j=0;
    char INPUT[50];
    cout<<"请输入要分析的字符串"<<endl;
    cin>>INPUT;
    state=1;
    while(INPUT[j]!='\0')
    {
        tmp=INPUT[j];
        j++;
        get();
        if(o==1&&print!="")
            output();
    }
    e();
    if((input[i]=='#')&&r)
        cout<<"分析成功，符合文法"<<endl;
    else
        cout<<"分析失败，存在错误"<<endl;
    return 0;

}
