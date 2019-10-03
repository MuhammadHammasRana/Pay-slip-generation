#include<stdio.h>
#include<conio.h>
int Basicpay(char g,int e);
void Allowance(char c,int a);
void Deduction();
int B,PI,n,rp,GP,HRA,SSB,ARA,d,it,gpf,T,N;
int  main()
{   int age,Exp; char G;
	printf("enter your grade, age and year of experience: ");
	scanf("%c %d%d",&G,&age,&Exp);
	printf("_____________________________________________________");
	if((G == 'w')||(G == 'x')||(G == 'y')||(G == 'z'))
		Basicpay(G,Exp);
	else if((G == 'W')||(G == 'X')||(G == 'Y')||(G == 'Z'))
		Basicpay(G,Exp);
	else{
		printf("grade you enter is invalid \n...");
		return 0;
	}
	Allowance(G,age);
	Deduction();
	printf("\nBasic Pay\n___________\n\nBasic Salary: %d\nnudber of Increment: %d\nRunnng pay: %d\n",B,n,rp);
	printf("\nAllowances\n___________\n\nHouse Rent Allowance: %d\nSocial Security Benefit: %d\nAdhoc Relief Allowance: %d\n\nGross pay: %d\n",HRA,SSB,ARA,GP);
	printf("\nDeductions\n___________\n\nncome Tax (at %.1f%%): %d\nGeneral Provident Fund: %d\nDonation: %d\n\nTotal Donation: %d\n\n\n\n\nnET PAY: %d\n",(double)it*100/GP,it,gpf,d,T,n);
	return 0;
}
int Basicpay(char g,int e)
{
	n=e;
	switch(g)
	{
		case 'W':
		case 'w':
			B=10000;
			PI=700;
			break;
		case 'X':
		case 'x':
			B=12900;
			PI=910;
			break;
		case 'Y':
		case 'y':
			B=21700;
			PI=1500;
			break;
		default:
			B=32600;
			PI=2800;
			break;
	}
	rp=B+n*PI;
}
void Allowance(char c,int a)
{
	HRA=rp*45/100;
	SSB=B*30/100;
	if((c=='W'||c=='w') && a>40)
		ARA=3000;
	else
		ARA=1500;
	GP=rp+HRA+SSB+ARA;
	d=GP%100;
	GP=GP-d;
}
void Deduction()
{
	if((GP*12)>=0 && (GP*12)<=400000)
	it=GP*0;
	else if((GP*12)>400000 && (GP*12)<=650000)
	it=GP*2.5/100;
	else if((GP*12)>650000 && (GP*12)<=1000000)
	it=GP*4.75/100;
	else if((GP*12)>1000000 && (GP*12)<=1500000)
	it=GP*7/100;
	else
	it=GP*11.5/100;

	gpf=(GP+d)*10/100;
	T=it+gpf+d;
	n=(GP+d)-T;
}
