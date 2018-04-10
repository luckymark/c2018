#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#define N 100

void logo(void)
{
    printf("************************************************\n");
    printf("*********String encrypter and decrypter*********\n");
    printf("************************************************\n");
    printf("\n");
    printf("Press 'k' to generate keys\n");
    printf("Press 'e' to encrypt a string\n");
    printf("Press 'd' to decrypt a string\n");
    printf("Press 'q' to quit\n");
}

int num=0,e=0,d=0,n=0;
char s[N];
char s1[N];
int s2[N];
int get(char ch)
{
    if(ch=='p')
    {
        while(1)
        {
            printf("Please input your private key.\n");
            fflush(stdin);
            scanf("%d*%d",&d,&n);
            if((d!=0)&&(n!=0))
            break;
            else
            printf("Invalid key!!!\n");
            fflush(stdin);
        }
    }
    else if(ch=='k')
    {
        while(1)
        {
            printf("Please input your public key.\n");
            fflush(stdin);
            scanf("%d*%d",&e,&n);
            if((e!=0)&&(n!=0))
            break;
            else
            printf("Invalid key!!!\n");
            fflush(stdin);
        }
    }
    else if(ch=='a')
    {
        loop:while(1)
        {
            printf("Please input your string.\n");
            fflush(stdin);
            gets(s);
            num=0;
            while(s[++num]!='\0');
            int i;
            for(i=0;i<num;i++)
            {
                if(s[i]<0||s[i]>254)
                {
                    printf("不支持中文~~~\n");
                    goto loop; 
                }
                else;
            }
            break;
        }
    }
    else if(ch=='b')
    {
        while(1)
        {
            printf("Please input your string.\n");
            fflush(stdin);
            gets(s1);
            if(s1[0]!='*')
            {
                printf("Invalid string!!!\n");
                continue;
            }
            else
            {
                int i=1,p,q,r,s;
                num=0;
                while(s1[i])
                {
                    if(s1[i]>='0'&&s1[i]<='9'&&s1[i+1]>='0'&&s1[i+1]<='9'&&s1[i+2]>='0'&&s1[i+2]<='9')
                    {
                        p=s1[i]-'0';
                        q=s1[i+1]-'0';
                        r=s1[i+2]-'0';
                        s2[num]=r+10*q+100*p;
                        num++;
                        i=i+3;
                        continue;
                    }
                    else if(s1[i]>='0'&&s1[i]<='9'&&s1[i+1]>='0'&&s1[i+1]<='9'&&s1[i+2]=='*')
                    {
                        q=s1[i]-'0';
                        r=s1[i+1]-'0';
                        s2[num]=r+10*q;
                        num++;
                        i=i+2;
                        continue;
                    }
                    else if(s1[i]>='0'&&s1[i]<='9'&&s1[i+1]=='*')
                    {
                        r=s1[i]-'0';
                        s2[num]=r;
                        num++;
                        i++;
                        continue;
                    }
                    else if(s1[i]=='*')
                    {
                        i++;
                        continue;
                    }
                    else
                    i++;    
                }
            }
        /*while(1)
        {
            printf("please input your string.\n");
            fflush(stdin);
            char ch;
            scanf("%c",&ch);
            if(ch!='*')
            {
                printf("Invalid string!!!\n");
                continue;
            }
            else
            {
                num=0;
                while(kbhit())
                {
                    scanf("%d*",&s1[num]); 
                    if(s1[num]!=0)
                    {
                        num++;
                        continue;
                    }
                    else
                    break;
                }
            }
            break;
        }*/
        break;
        }
    }
    else;
}

int prime(void)
{
    int pri,i,mod;
    srand(time(NULL));
    pri=rand()%50+10;
    while(1)
    {
        i=2;
        do
        {
            mod=(pri%i);
            i++;
        }while(mod!=0);
        if(i>=pri)
        return pri;
        else
        pri--;
    }
}

int gcd(int a,int b)
{
    int c;
    while(1)
    {
        c=a%b;
        if(c==0)
        return b;
        else
        {
            a=b;
            b=c;
        }
    }
}

/*double char2num(char *ch1)
{
    double a=atof(ch1);
    return a; 
}*/ 

int mod(int a,int b,int p)
{  
    int t=1;
    while(b>0)  
    { 
        if(b&1)
        t=(t%p)*(a%p)%p;
        a=(a%p)*(a%p)%p; 
        b/=2;
    }
    return (int)(t%p);
}

void key(void)
{
    int p,q,n,n1,e,d;
    printf("Processing...\n");
    while(1)
    {
        while(1)
        {
            p=prime();
            q=prime();
            if(p!=q)
            break;
            else;
        }
        n=p*q;
        n1=(p-1)*(q-1);
        srand(time(NULL));
        while(1)
        {
            e=rand()%n1+1;
            if(gcd(e,n1)==1)
            break;
            else;
        }
        for(d=0;;d++)
        {
            if((d*e)%n1==1)
            break;
            else;
        }
        if(d!=e&&d>2&&e>2&&n<1000)
        break;
        else;
    }
    printf("your private key is %d*%d\n",d,n);
    printf("your public key is %d*%d\n",e,n);
    printf("Press any key to continue.\n");
    while (!getch());
    logo();
}

void encrypt(void) 
{
    double s_e[N];
    get('k');
    get('a');
    int i;
    for(i=0;i<num;i++)
    //s_e[i]=fmod(pow((double)s[i],(double)e),(double)n); 容易溢出得不到正确值 
    s_e[i]=mod(s[i],e,n);
    printf("Encrypted string is\n*");
    for(i=0;i<num;i++)
    printf("%.f*",s_e[i]);
    printf("\n");
    printf("Press any key to continue.\n");
    while (!getch());
    logo();
}
 
void decrypt(void)
{
    int s_d[N];
    get('p');
    get('b');
    int i=0; 
    for(i=0;i<num;i++)
    //s_d[i]=fmod(pow(temp1,(double)d),(double)n); 容易溢出得不到正确值
    s_d[i]=mod(s2[i],d,n);
    printf("Decrypted string is\n");
    for(i=0;i<num;i++)
    printf("%c",s_d[i]);
    printf("\n");
    printf("Press any key to continue.\n");
    while (!getch());
    logo();
}

int main(void)
{
    logo();
    while(1)
    {
        
        char ch;
        ch=getch();
        if(ch=='k')
        {
            key();
            continue;
        }
        else if(ch=='e')
        {
            encrypt();
            continue;
        }
        else if(ch=='d')
        {
            decrypt();
            continue;
        }
        else if(ch=='q')
        {
            exit(0);
        }
        else;
    }
    getchar();
    return 0;
}
