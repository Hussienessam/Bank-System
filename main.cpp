#include <iostream>

#include <cstring>

#include <ctype.h>

using namespace std;

int comma(char[],int[]);

void slicing(char[],char[],int,int);

struct Costumer
{
    char name[10];
    char street[40],neighbourhood[20],city[20];
    char letter[10];
    int balance;
    int trans[10];
};

void print1(Costumer[20],int);

void print2(Costumer[20],int);

void edit(Costumer[20],int,int);

void show(Costumer[20],int);

void change(Costumer[20],int);

void show2(Costumer[20],int);

int main()
{
    int b,tran,limit,mode,k=0;
    Costumer costumers[20];
    char address[30];
    char ans[5];
    char ans2[4]={'d','o','n','e'};
    int commas[2];
    for(int i=0;i<20;i++)
    {
        cout<<"Enter the name of the costumer"<<endl;
        cin>>costumers[i].name;
        cout<<"Enter the address of the costumer"<<"\t ex:5 omran street, dokki, giza"<<endl;
        cin.clear();
        cin.ignore(10000,'\n');
        cin.getline(address,50);
        b=comma(address,commas);
        while (b!=2 or isalpha(address[0]) or address[commas[0]+1]!=' ' or address[commas[1]+1]!=' ')
        {
            cout<<"Enter a valid address of the costumer"<<endl;
            cin.clear();
            cin.getline(address,50);
            b=comma(address,commas);
        }
        slicing(address,costumers[i].street,0,commas[0]-1);
        slicing(address,costumers[i].neighbourhood,commas[0]+2,commas[1]-1);
        slicing(address,costumers[i].city,commas[1]+2,strlen(address)-1);
        cout<<"What is the number of transactions"<<"\t (up to 10)"<<endl;
        cin>>tran;
        while (tran>10 or tran<=0)
        {
            cout<<"Enter a valid number of transactions"<<endl;
            cin.clear();
            cin.ignore(10000,'\n');
            cin>>tran;
        }
        costumers[i].balance=0;
        cout<<"Please enter "<<costumers[i].name<<"'s account transactions"<<"\t format: W or D value W or D value etc.."<<endl;
        for(int j=0;j<tran;j++)
        {
            cin>>costumers[i].letter[j];
            cin>>costumers[i].trans[j];
            while (costumers[i].trans[j]<=0 or costumers[i].letter[j]!='W' and costumers[i].letter[j]!='D')
            {
                cout<<"Invalid input please enter valid values"<<endl;
                cin.clear();
                cin.ignore(10000,'\n');
                cin>>costumers[i].letter[j];
                cin>>costumers[i].trans[j];
            }
            if (costumers[i].letter[j]=='W')
                costumers[i].balance=costumers[i].balance-costumers[i].trans[j];
            else if (costumers[i].letter[j]=='D')
                costumers[i].balance=costumers[i].balance+costumers[i].trans[j];
            if (j==tran-1 and costumers[i].balance<0)
            {
                cout<<"Not enough account balance please re enter valid transactions"<<endl;
                j=-1;
                costumers[i].balance=0;
            }
        }
        cout<<"if you have finished enter done"<<endl;
        cin.clear();
        cin.ignore(10000,'\n');
        cin.getline(ans,5);
        for(;k<4;k++)
        {
            if(ans[i]!=ans2[i])
                break;
        }
        if (k==4)
        {
            limit=i+1;
            break;
        }
    }
    cout<<"\n"<<"\n"<<"Welcome to our bank application"<<"\n"<<"1) Print all names and account balances"<<"\n";
    cout<<"2) Print specific customer's account balance"<<"\n"<<"3) Edit customer transactions"<<"\n"<<"4) Show customer with highest balance"<<"\n";
    cout<<"5) Change customer's name, transactions, balance or address"<<"\n"<<"6) Show how many customers in one city"<<endl;
    while(1)
    {
        cout<<"Enter your choice"<<endl;
        cin>>mode;
        switch(mode)
        {
            case 1:
                print1(costumers,limit);
                break;
            case 2:
                print2(costumers,limit);
                break;
            case 3:
                edit(costumers,limit,tran);
                break;
            case 4:
                show(costumers,limit);
                break;
            case 5:
                change(costumers,limit);

                break;
            case 6:
                show2(costumers,limit);
                break;
            default :
                cout<<"invalid input"<<endl;
                break;
        }
        int l=0;
        char ans4[10];
        char ans3[2]={'n','o'};
        cout<<"Do you want to continue ?"<<"\t Enter no if done"<<endl;
        cin.clear();
        cin>>ans4;
        for(;l<2;l++)
        {
            if(ans4[l]!=ans3[l])
                break;
        }
        if (l==2)
        {
            cout<<"Thanks for using my program"<<endl;
            break;
        }
    }

}

int comma(char address[30],int commas[2])
{
    int a=0;
    int y=0;
    for(int i=0;i<strlen(address);i++)
    {
        if (address[i]==',')
        {
            a=a+1;
            commas[y]=i;
            y=y+1;
        }
    }
    return a;
}

void slicing(char address[30], char sliced[20], int start, int End)
{
    int y=0;
    for(int i=start ;i<=End;i++)
    {
        sliced[y]=address[i];
        y=y+1;
    }
    sliced[y]='\0';
}

void print1(Costumer costumers[20],int limit)
{
    for(int k=0;k<limit;k++)
    {
        cout<<costumers[k].name<<" ";
        cout<<costumers[k].balance<<endl;
    }
}

void print2(Costumer costumers[20],int limit)
{
    int n=0;
    char name[10];
    cout<<"Enter the costumer's name"<<endl;
    cin.clear();
    cin.ignore(10000,'\n');
    cin.getline(name,10);
    for(int k=0;k<limit;k++)
    {
        for(;n<strlen(costumers[k].name);n++)
        {
            if(name[n]!=costumers[k].name[n])
                break;
        }
        if (n==strlen(costumers[k].name))
        {
            cout<<costumers[k].name<<"'s account balance = "<<costumers[k].balance<<endl;
        }
        else
            cout<<"There is no such costumer's name"<<endl;
    }
}

void edit(Costumer costumers[20],int limit,int tran)
{
    int n=0,tran2;
    char name[10];
    cout<<"Enter the costumer's name"<<endl;
    cin.clear();
    cin.ignore(10000,'\n');
    cin.getline(name,10);
    for(int i=0;i<limit;i++)
    {
        for(;n<strlen(costumers[i].name);n++)
        {
            if(name[n]!=costumers[i].name[n])
                break;
        }
        if (n==strlen(costumers[i].name))
        {
            cout<<"What is the number of the new transactions"<<endl;
            cin>>tran2;
            cout<<"Please enter "<<costumers[i].name<<"'s new account transactions"<<endl;
            for(int j=0;j<tran2;j++)
            {
                cin>>costumers[i].letter[j+tran];
                cin>>costumers[i].trans[j+tran];
                while (costumers[i].trans[j+tran]<0)
                {
                    cout<<"Invalid input please enter valid values"<<endl;
                    cin>>costumers[i].letter[j+tran];
                    cin>>costumers[i].trans[j+tran];
                }
                if (costumers[i].letter[j+tran]=='W')
                    costumers[i].balance=costumers[i].balance-costumers[i].trans[j+tran];
                else if (costumers[i].letter[j+tran]=='D')
                    costumers[i].balance=costumers[i].balance+costumers[i].trans[j+tran];
            }
            cout<<costumers[i].name<<"'s balance now = "<<costumers[i].balance<<endl;
        }
    }
}

void show(Costumer costumers[20],int limit)
{
    int high=0,y;
    for(int k=0;k<limit;k++)
        {
            if (costumers[k].balance>=high)
            {
                high=costumers[k].balance;
                y=k;
            }
        }
    cout<<"Customer with the highest account balance is "<<costumers[y].name<<endl;
}

void change(Costumer costumers[20],int limit)
{
    int ans,y,tran,n=0,i,b;
    char name[10];
    char address[30];
    int commas[2];
    cout<<"Enter the costumer's name"<<endl;
    cin.clear();
    cin.ignore(10000,'\n');
    cin.getline(name,10);
    for(int k=0;k<limit;k++)
    {
        for(;n<strlen(costumers[k].name);n++)
        {
            if(name[n]!=costumers[k].name[n])
                break;
        }
        if (n==strlen(costumers[k].name))
            i=k;
    cout<<"\n"<<"What do you want to change"<<endl;
    cout<<"1) Change customer's name"<<"\n";
    cout<<"2) Change customer's transactions"<<"\n"<<"3) Change customer's balance"<<"\n"<<"4) Change customer's address"<<endl;
    cin>>ans;
    switch (ans)
    {
        case 1: cout<<"Enter the new costumer's name"<<endl;
                cin>>costumers[i].name;
                cout<<"your name now is "<<costumers[i].name<<endl;
                break;
        case 2: cout<<"What is the number of the new transactions"<<endl;
                cin>>tran;
                costumers[i].balance=0;
                cout<<"Please enter "<<costumers[i].name<<"'s new account transactions"<<endl;
                for(int j=0;j<tran;j++)
                {
                    cin>>costumers[i].letter[j];
                    cin>>costumers[i].trans[j];
                    while (costumers[i].trans[j]<0)
                    {
                        cout<<"Invalid input please enter valid values"<<endl;
                        cin>>costumers[i].letter[j];
                        cin>>costumers[i].trans[j];
                    }
                    if (costumers[i].letter[j]=='W')
                        costumers[i].balance=costumers[i].balance-costumers[i].trans[j];
                    else if (costumers[i].letter[j]=='D')
                        costumers[i].balance=costumers[i].balance+costumers[i].trans[j];
                }
                cout<<"your new account balance = "<<costumers[i].balance<<endl;
                break;
        case 3: cout<<"Enter the new costumer's balance"<<endl;
                cin>>costumers[i].balance;
                cout<<costumers[i].name<<"'s balance now = "<<costumers[i].balance<<endl;
                break;
        case 4: cout<<"Enter the new address of the costumer"<<endl;
                cin.clear();
                cin.ignore(10000,'\n');
                cin.getline(address,30);
                b=comma(address,commas);
                while (b!=2 or isalpha(address[0]) or address[commas[0]+1]!=' ' or address[commas[1]+1]!=' ')
                {
                    cout<<"Enter a valid address of the costumer"<<endl;
                    cin.getline(address,30);
                    b=comma(address,commas);
                }
                slicing(address,costumers[i].street,0,commas[0]-1);
                slicing(address,costumers[i].neighbourhood,commas[0]+2,commas[1]-1);
                slicing(address,costumers[i].city,commas[1]+2,strlen(address)-1);
                cout<<costumers[i].name<<"'s address now = "<<costumers[i].street<<" "<<costumers[i].neighbourhood<<" "<<costumers[i].city<<endl;
                break;
    }
    }
}

void show2(Costumer costumers[20],int limit)
{
    char name[10];
    int n=0,y=0;
    cout<<"Enter the city"<<endl;
    cin.clear();
    cin.ignore(10000,'\n');
    cin.getline(name,10);
    for(int k=0;k<limit;k++)
    {
        for(;n<strlen(costumers[k].city);n++)
        {
            if(name[n]!=costumers[k].city[n])
                break;
        }
        if (n==strlen(costumers[k].city))
             y=y+1;
    }
    if (y==0)
        cout<<"There is no costumers in "<<name<<endl;
    else
        cout<<"The number of costumers in "<<name<<" is "<<y<<endl;
}
