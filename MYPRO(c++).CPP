//dont touch :| its kinda personal
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
int f=0;
int v_f=0,h_f=0,ptr=100;
struct node
{
	int data;
	struct node *n1,*n2,*next;
}*start=NULL,*v_start=NULL;
struct node *ne,*n1,*n2,*cu,*v_ne,*v_n1,*v_n2,*v_cu,*t1,*t2,*v_t1,*v_t2;
class f_pro
{
	    public:
	char c;
	    void linesec();
	    void h_fun();//for h function
	    void ashow();//for line in scr
	    void n_board();//for color
	    void v_fun();
}ob1;
void f_pro::h_fun()
{      int i=1;
	while(i!=3)
	{
		ne=new node;
		cout<<"enter your two h no";
		cin>>ne->data;
		ne->next=NULL;
		if(start==NULL)
		{
		 start=ne;
		 cu=ne;
		 n1=cu;
		 n2=cu;
		}
		else
		{
		 cu->next=ne;
		 cu=ne;
		}
		i++;
		clrscr();
		ob1.n_board();
	}
cout<<"want more press y else n";
cin>>c;
if(c=='y')
ob1.linesec();
else
if(c=='n')
//ob1.rule();
ob1.ashow();
}
void f_pro::v_fun()
{      int i=1;
	while(i!=3)
	{
		v_ne=new node;
		cout<<"enter your two h no";
		cin>>v_ne->data;
		v_ne->next=NULL;
		if(v_start==NULL)
		{
		 v_start=v_ne;
		 v_cu=v_ne;
		 v_n1=v_cu;
		 v_n2=v_cu;
		}
		else
		{
		 v_cu->next=v_ne;
		 v_cu=v_ne;
		}
		i++;
			clrscr();
		ob1.n_board();


	}
cout<<"want more press y else n";
cin>>c;
if(c=='y')
ob1.linesec();
else
if(c=='n')
ob1.ashow();
}

void f_pro::ashow()  //prototype V4.0
{ clrscr();
    while(ptr!=300)
      {
	while(n2!=NULL)
	{
	 if(ptr==n2->data)
	    {
	 h_f++;

		if(h_f==1)
		t1=n2;
		else if(h_f==2)
		t2=n2;
	    }
	n2=n2->next;
	}
	 while(v_n2!=NULL )
	 {
	 if(ptr==v_n2->data)
	   {
	 v_f++;
		if(v_f==1) v_t1=v_n2;
		else if(v_f==2) v_t2=v_n2;
	   }
	v_n2=v_n2->next;
	}
	if(v_f==0&&h_f>0)
	{
	if(h_f==1)
	cout<<"********";
	else if(h_f==2)
	cout<<"****";
	}
	else
	{
	if(h_f==1)
	cout<<"|*******";
	else if(h_f==2)
	cout<<"|   ";
	else if(h_f==0&&v_f>0)
	cout<<"|";
	}
	if(h_f==2||h_f==0)
	{
	if(h_f==2)
	cout<<"    ";
	else if(h_f==0&&v_f>0)
	cout<<"       ";
	else if(h_f==0)
	cout<<"        ";
	}
	if(h_f>0)
	{
	  if(h_f==1)
	   t1->data+=1;
	 else if(h_f==2){
		  t2->data=0;
		  t1->data=0;
		  }
	}
	if(v_f>0)
	{
		if(v_f==1)
		v_t1->data+=10;
	       else if(v_f==2){
			v_t2->data=0;
			v_t1->data=0;
			}
	}
	h_f=0;
	v_f=0;
	n2=n1;
	v_n2=v_n1;
       ptr++;
      }
}
void f_pro::n_board()
{
clrscr();
	for(int i=100;i<280;i++)
	{
	while(n2!=NULL)
	{
	if(n2->data==i)
	{
	textcolor(RED);
	cprintf(".%d",i);cout<<"    ";
	textcolor(WHITE);
	f++;
	}
	n2=n2->next;
	}
	while(v_n2!=NULL)
	{
	if(v_n2->data==i)
	{
	if(f!=1)
	{
	textcolor(GREEN);
	cprintf(".%d",i);cout<<"    ";
	textcolor(WHITE);
	f=2;
	}
	}
	v_n2=v_n2->next;
	}
	if(f==0)
	cout<<"."<<i<<"    ";
	f=0;
	n2=n1;
	v_n2=v_n1;
}
}

void f_pro::linesec()
{
	int n;
	cout<<"\n1>hline\n2>vline\n*.*enter your line no....\n";
	cin>>n;
	switch(n)
	{
	case 1:
		n_board();
		ob1.h_fun();
		break;
	case 2:
		n_board();
		ob1.v_fun();
		break;
	case 3:
		exit(0);
		break;
	}

}
void main()
{
	clrscr();
	ob1.linesec();
	getch();
}