#include<iostream>
struct Rabota
{
	char fio[25];
	int otmet[5];
	int vozvrast;
	Rabota *next;
};
void prinh(Rabota *first)
{
	Rabota *ab=first;
	while(ab)
	{
		printf("%s || %d || ", ab->fio, ab->vozvrast);
		for(int i=0; i<5; i++)
		{
			std::cout<<ab->otmet[i]<<" ";
		}
		std::cout<<std::endl;
		ab=ab->next;
	}
}
using namespace std;
int main()
{
	char st[25];
	puts("Imput spisok rabotnikov(fio, staj, otmet)");
	Rabota *first, *tmp, *p;
	first=new Rabota;
	gets(st);
	strcpy(first->fio, st);
	cin>>first->vozvrast;
	for(int i=0;i<5;i++)
	{
		cin>>first->otmet[i];
	}
	tmp=first;
	while(cin.ignore(),gets(st), strlen(st)!=NULL)
	{
		p=new Rabota;
		tmp->next=p;
		p->next=NULL;
		strcpy(p->fio, st);
	cin>>p->vozvrast;
	for(int i=0;i<5;i++)
	{
		cin>>p->otmet[i];
	}
	}
	prinh(first);
	
}