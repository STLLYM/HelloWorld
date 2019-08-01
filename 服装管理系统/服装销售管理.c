#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include <windows.h>
#define KEY 0x86

typedef struct Adm* List1;
typedef struct Clo* List2;
typedef struct Vip* List3;
struct Adm//����Ա��Ϣ����  ����  ���� 
{
	char nam[20],password[20];
	struct Adm* next;
};
struct Clo//��װ��Ϣ����   Ʒ�� ���� ��� �ߴ� ��ɫ �۸� ���� 
{
	char brand[20],nam[20],size[20],color[20];
	float price;
	int amount,num;
	struct Clo* next;
};
struct Vip//��Ա��Ϣ����    ���� �绰 ���� 
{
	char nam[20],phone[20];
	float score; 
	int num;          //��Ա���Զ����� 
	struct Vip* next;
};
void enter0();                      //��½���� 
void Vis_window();                  //�οͽ��� 
void Adm_enter();                   //����Ա¼��
void Adm_change();                  //����Ա�޸�  
void Adm_load();                    //����Ա��¼ 1  
void Adm_manage();                  //����Ա������� 2                
void Clo_manage();                  //��װ������� 3 
void Clo_add();                     //��װ��� 
void Clo_find();                    //��װ��Ϣ��ѯ 
void Clo_finding();                 //��ǰ��������Ȳ�ѯ 
void Clo_change();                  //��װ��Ϣ�ı�  
int Clo_stat();                     //��װ������Ŀͳ�� 
void Vip_manage();                  //��Ա������� 4                
void Vip_enter();                   //��Ա��Ϣ¼��
int Vip_stat();                     //��Ա��ͳ�� 
void Vip_find();                    //��Ա��Ϣ��ѯ
void Vip_finding();                 //��ǰ��������� 
void Sale_system();                 //����ϵͳ������� 5 
void Sale_list();                   //���з�װ��ʾ 
void Sale_window();                 //���۴��� 
int Sale_stat();                    //���۷�װ������ 
void Use_history();                 //ʹ�ü�¼ 
void Data_sort();                   //������������ 

void Pro_bar()///���������� 
{
	system("cls");
	char arr[50] = {'\0'};
	const char *p = "|/-\\";
	memset(arr,0,sizeof(arr));
	int n = 50,i = 0;
	while(i<=n)
	{
		arr[i]= '=';
		printf("\t\t\t\t[%-50s][%d%%][%c]\r",arr,i*2,p[i%4]);
		fflush(stdout);
		i++;
		usleep(20000);
    }
	printf("\n");
}
void Mas_int()///���� 
{
	MessageBox(NULL, TEXT("���ƣ���װ����ϵͳ\nѧУ�������ʵ��ѧ\n���ߣ�������1801 ����"), TEXT("����"), MB_OK);
 } 
void enter()///������� 
{
	Pro_bar();
	system("cls");
	int x0;
	char name[20];
	printf("\t\t\t\t  ***************����������*****************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  ********     1.����Ա����@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  ********      2.�οͽ���@_@    ***********\n");
	printf("\n");
	printf("\t\t\t\t  ********     3.�˳��ó���@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  ******************************** 0.���� **\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\t\t\t\t  ") ;
	scanf("%d",&x0);
	switch (x0)
	{
		case 0:
			Mas_int(); 
			enter();
			break;
		case 1:
			enter0();
			break;
		case 2:
			Vis_window();
			break;
		case 3:
			Pro_bar(); 
			system("cls");
			exit(0);
			break;
		default :
		    printf("\t\t\t\t  δ�����壬����������ص�ǰ\n") ;
		    getch();
			system("cls"); 
			enter();
    }
} 
void Vis_window()///�οͽ��봰�� 
{
	system("cls");
	int x0;
	char name[20];
	printf("\t\t\t\t  ****************�οͽ���******************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  *********     1.��װ����@_@    ***********\n");
	printf("\n");
	printf("\t\t\t\t  *********     2.��װ����@_@    ***********\n");
	printf("\n"); 
	printf("\t\t\t\t  *********     3.�����ϲ�@_@    ***********\n");
	printf("\n"); 
	printf("\t\t\t\t  ******************************************\n");
	printf("\t\t\t\t  ") ;
	scanf("%d",&x0);
	switch (x0)
	{
		case 1:
			Clo_find(x0);
			break;
		case 2:
			Sale_window();
			break;
		case 3:
			enter(); 
			break;
		default :
		    printf("\t\t\t\t  δ�����壬������������ϲ�\n") ;
		    getch();
			system("cls"); 
			enter();
	}
}
void enter0()///��һ����   ��¼���� 
{
	system("cls");
	int x0;
	char name[20];
	printf("\t\t\t\t  **************����Ա������****************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  ********     1.��ӹ���Ա@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  ********     2.����Ա�޸�@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  ********     3.����Ա��¼@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  ********     4.������һ��@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\t\t\t\t  ") ;
	scanf("%d",&x0);
	switch (x0)
	{
		case 1:
			Adm_enter();
			break;
		case 2:
			Adm_change();
			break;
		case 3:
			Adm_load();
			break;
		case 4:
			enter(); 
			break;
		default :
		    printf("\t\t\t\t  δ�����壬������������ϲ�\n") ;
		    getch();
			system("cls"); 
			enter0();
	}
}
void Adm_enter()///����Ա¼�� 
{
	system("cls");
	FILE *fp;
	int i,j=0,m;
	char nam[20],nam0[20],psword[20],psword0[20];
	fp = fopen("Adm_list.txt","r");
	if(fp == NULL)
	{
		j=1;
		fp = fopen("Adm_list.txt","a");
	} 
	fclose(fp);
	printf("\t\t\t\t  �������Ա��:");
	scanf("%s",nam);
	if(j==0);
	{
		fp = fopen("Adm_list.txt","r");
		while(!feof(fp))
		{
			fscanf(fp," %s %s\n",nam0,psword0);
			{
				if (!strcmp(nam0,nam))
				{
					printf("\t\t\t\t  �Ѵ��ڸù���Ա�������ظ�¼�룡\n");
					printf("\t\t\t\t  ����������ϲ㣡");
					getch();
					fclose(fp);
					enter0(); 
				}
			}
		}
	}
	fp = fopen("Adm_list.txt","a");
	printf("\t\t\t\t  ��������:"); 
	for(i=0; ;i++)
	{
		m=0;
		psword0[i]=getch();
		if(psword0[i]=='\r')
		{
			psword0[i]='\0';
			break;
		}
		if(psword0[i]=='\b')
		{
			m=1;
			psword0[i]='\0';
			psword0[i-1]='\0';
			i = i-2;
			printf("\b \b");
		}
		if(m==0) printf("*");
	}
	printf("\n\t\t\t\t  ���ٴ���������:");
	for(i=0; ;i++)
	{
		m=0;
		psword[i]=getch();
		if(psword[i]=='\r')
		{
			psword[i]='\0';
			break;
		}
		if(psword[i]=='\b')
		{
			m=1;
			psword[i]='\0';
			psword[i-1]='\0';
			i = i-2;
			printf("\b \b");
		}
		if(m==0) printf("*");
	}
	if(!strcmp(psword0,psword))
	{
		for (i=0;i<strlen(psword);i++)
		{
			psword0[i] = psword[i]^KEY;
			
		}
		fprintf(fp," %s %s\n",nam,psword0);
		printf("\n\t\t\t\t  ¼��ɹ�������������ϲ㣡");
	}
	else
	{
		printf("\n\t\t\t\t  ¼��ʧ�ܣ����벻һ�£�����������ϲ�:");		
	}
	getch(); 
	fclose(fp);
	enter0(); 
}
void Adm_load()///����Ա��¼ 
{
	system("cls");
	FILE *fp;
	char nam[20],nam0[20],psword[20],psword0[20];
	int flag = 0,i,j;
	fp = fopen("Adm_list.txt","r");
	if (fp == NULL)
	{
		printf("\t\t\t\t  ��δ��������Ա�������������¼��.");
		Adm_enter();
	 } 
	printf("\t\t\t\t  �����¼����Ա����:");
	scanf("%s",nam0);
	while(!feof(fp))
	{
		fscanf(fp, " %s %s\n",nam,psword);
		if (!strcmp(nam,nam0))
		{
			flag = 1;
			printf("\t\t\t\t  ��������:");
			for(i=0; ;i++)
			{
				j=0;
				psword0[i]=getch();
				if(psword0[i]=='\r')
				{
					psword0[i]='\0';
					break;
				}
				if(psword0[i]=='\b')
				{
					j=1;
					psword0[i]='\0';
					psword0[i-1]='\0';
					i = i-2;
					printf("\b \b");
				}
				if(j==0) printf("*");
			}
			for(i=0;i<strlen(psword);i++)
			{
				psword[i] = psword[i]^KEY;
			}
			if(!strcmp(psword,psword0))
			{
				Adm_manage();                           //�������Ա������� 
			}
			else
			{
				printf("\n\t\t\t\t  �����������������ϲ�:");
				getch(); 
				enter0();
				break;
			}
		}
	}
	if (flag==0)
	{
		printf("\t\t\t\t  �ù���Աδ¼�룬����������ϲ㣡");
		getch();
		enter0(); 
	}
}
void Adm_change()///����Ա�޸� 
{
	system("cls");
	printf("\t\t\t\t  *************����Ա�޸Ľ���***************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  ********     1.����Աɾ��@_@    **********\n");
	printf("\n");
	printf("\t\t\t\t  ********   2.����Ա�����޸�@_@  **********\n");
	printf("\n");
	printf("\t\t\t\t  ********      3.�����ϲ�@_@     **********\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\t\t\t\t  ") ;
	int x;
	scanf("%d",&x); 
	system("cls");
	FILE *fp;
	List1 head,p1,p2;
	char i,nam[20],psword[20];
	int j,l=0,m;
	fp = fopen("Adm_list.txt","r");
	if (fp == NULL)
	{
		printf("\t\t\t\t  ��δ¼�����Ա��\n\t\t\t\t  ����������ϲ�");
		getch();
		enter0(); 
	}
	p1 = head = (List1)malloc(sizeof(struct Adm));
	p1->next = NULL;
	while(!feof(fp))
	{
		p2 = (List1)malloc(sizeof(struct Adm));
		fscanf(fp," %s %s\n",p2->nam,p2->password);
		p1->next=p2;
		p2->next=NULL;
		p1=p2;		
	}
	fclose(fp);
	if (x==1) 
	{
		fp = fopen("Adm_list.txt","w");
		p2 = head->next;
		printf("\t\t\t\t  Ҫ���ĵĹ���Ա����Ϊ:");
		scanf("%s",nam);
		while(p2)
		{
			m=0;
			if(!strcmp(p2->nam,nam))
			{
				l=1;
				printf("\t\t\t\t  �Ƿ�ɾ���ù���Ա��\n");
				printf("\t\t\t\t  �س�ɾ������������أ�");
				i=getch();
				if (i==13)
				{
					m=1;
					p1 = p2;
					p2 = p2->next;
					free(p1);
				}
			}
			fprintf(fp," %s %s\n",p2->nam,p2->password);
			p2 = p2->next;
		}
		fclose(fp);
	}
	else if(x==2)
	{
		fp = fopen("Adm_list.txt","w");
		p2 = head->next;
		printf("\t\t\t\t  Ҫ���ĵĹ���Ա����Ϊ:");
		scanf("%s",nam);
		while(p2)
		{
			if(!strcmp(p2->nam,nam))
			{
				l=1;
				printf("\n\t\t\t\t  ���ڸù���Ա���������뽫����ԭ����");
				for(j=0; ;j++)
				{
					psword[j]=getch();
					if(psword[j]=='\r')
					{
						psword[j]='\0';
						break;
					}
					printf("*");
				}
				strcpy(p2->password,psword);
			}
			fprintf(fp," %s %s\n",p2->nam,p2->password);
			p2 = p2->next;
		}
		fclose(fp);
	}
	else if(x==3)
	{
		enter0();
	 } 
	else if(x!=1 && x!=2 && x!=3)
	{
		printf("\n\t\t\t\t  ����δ�����壬��������أ�");
		getch();
		enter0(); 
	}
	if(l==0)
	{
		printf("\n\t\t\t\t  �ù���Աδ��¼�룡\n\t\t\t\t  ����������ϲ�"); 
		getch();
		enter0();
	}
	printf("\n\t\t\t\t  ������ɣ�����������ϲ㣡");
	getch();
	enter0();
}
void Adm_manage()///�ڶ�����   ����Ա������� 
{
	system("cls");
	int x1;
	printf("\t\t\t\t  **************����Ա�������**************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  **********     1.��װ����@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  **********     2.��Ա����@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  **********     3.����ϵͳ@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  **********     4.�����ϲ�@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\t\t\t\t  ") ;
	scanf("%d",&x1);
	switch (x1)
	{
		case 1:
			Clo_manage();
			break;
		case 2:
			Vip_manage();
			break;
		case 3:
			Sale_system();
			break;
		case 4:
			enter0();
			break;
		default :
		    printf("\t\t\t\t  δ�����壬������������ϲ�\n") ;
		    getch();
			system("cls"); 
			Adm_manage();
	}
}
void Clo_manage()///��������   ��װ������� 
{
	system("cls");
	int x1;
	printf("\t\t\t\t  ****************��װ�������**************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  **********     1.��װ���@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  **********     2.��װ��ѯ@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  **********     3.��װ�޸�@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  **********     4.�����ϲ�@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\t\t\t\t  ") ;
	scanf("%d",&x1);
	switch (x1)
	{
		case 1:
			Clo_add();
			break;
		case 2:
			Clo_find(x1);
			break;
		case 3:
			Clo_change();
			break;
		case 4:
			Adm_manage();
			break;
		default :
		    printf("\t\t\t\t  δ�����壬������������ϲ�\n") ;
		    getch();
			system("cls"); 
			Clo_manage();
	}
} 
void Clo_add()///��װ��Ӻ��� 
{
	system("cls");
	FILE *fp;
	char i=13;
	int n; 
	List2 head,p1,p2;
	p1 = head = (List2)malloc(sizeof(struct Clo));
	head->next = NULL;
	fp = fopen("Clo_list.txt","a");
	n = Clo_stat();
	printf("\t\t\t\t  �밴�����¸�ʽ¼���װ��Ϣ��\n");
	while(i==13)
	{
		p2 = (List2)malloc(sizeof(struct Clo));
		printf("\t\t\t\t  Ʒ��    ����     �ߴ�     ��ɫ     �۸�     ����\n\t\t\t\t  ");
		scanf("%s %s %s %s %f %d",p2->brand,p2->nam,p2->size,p2->color,&p2->price,&p2->amount);
		p2->num = n;
		p1->next = p2;
		p2->next = NULL;
		p1 = p2; 
		printf("\t\t\t\t  �Ƿ��������?�س��������룬����������ϲ㣡\n");
		i=getch();
		n++;
	}
	p2 = head->next;
	while(p2)
	{
		fprintf(fp," %d %s %s %s %s %f %d\n",p2->num,p2->brand,p2->nam,p2->size,p2->color,p2->price,p2->amount);
		p2 = p2->next;
	}
	fclose(fp);
	Clo_manage();
 } 
void Clo_find(int u)///��װ���Һ��� 
{
	system("cls");
	Sale_list(); 
	FILE *fp;
	List2 head,p1,p2;
    char key1[20];
	p1 = head = (List2)malloc(sizeof(struct Clo));
	head->next = NULL;
	fp = fopen("Clo_list.txt","r");
	if (fp == NULL )
	{
		printf("\t\t\t\t  ��δ������װĿ¼����������أ�");
		getch(); 
		Clo_manage();
	}
	while(!feof(fp))
	{
		p2 = (List2)malloc(sizeof(struct Clo));
		fscanf(fp," %d %s %s %s %s %f %d\n",&p2->num,p2->brand,p2->nam,p2->size,p2->color,&p2->price,&p2->amount);
		p1->next=p2;
		p2->next=NULL;
		p1=p2;
	}
	fclose(fp);
	printf("\t\t\t\t  �����ѯ��������ѡ�� ���� Ʒ�� �ߴ� ��ɫ���߹ؼ���\n\t\t\t\t  ");
	scanf("%s",key1);
	Clo_finding(key1,head,u);	
} 
void Clo_finding(char* key,List2 headold,int u)///���������� 
{
	system("cls");
	char i,keyy[20];
	int j=0;
	List2 p,head,p1,p2;
	p = headold->next;
	p1 = head = (List2)malloc(sizeof(struct Clo));
	head->next = NULL;
	while (p)
	{
		if(!strcmp(p->size,key) ||!strcmp(p->color,key) ||!strcmp(p->brand,key) ||!strcmp(p->nam,key) ||strstr(p->nam,key) ||strstr(p->brand,key))
		{
			j=1;
			printf("\n\t\t\t\t  *********************************************************************\n");
			printf("\n\t\t\t\t  ���      Ʒ��           ����      �ߴ�      ��ɫ      �۸�      ����\n");
			printf("\t\t\t\t  %-10d%-15s%-10s%-10s%-10s%-10.2f%-10d\n",p->num,p->brand,p->nam,p->size,p->color,p->price,p->amount);
			p2 = (List2)malloc(sizeof(struct Clo));
			strcpy(p2->brand,p->brand);
			strcpy(p2->nam,p->nam);
			strcpy(p2->size,p->size);
			strcpy(p2->color,p->color);
			p2->num = p->num;
			p2->price = p->price;
			p2->amount = p->amount;
			p2->next = NULL;
			p1->next = p2;
			p1 = p2;
			p2=p2->next;
		}
		p=p->next;
	}
	if(j==0)
	{
		printf("\t\t\t\t  �޶�Ӧ��װ������������ϲ㣡");
		getch();
		if(u==2)
		Clo_manage(); 
		else
		Vis_window();
	}
	printf("\n\t\t\t\t  �Ƿ������ѯ���س��ڵ�ǰ�����¼�����ѯ������������ϲ�\n\t\t\t\t  ");
	i = getch();
	if (i==13)
	{
		printf("�����ѯ��������ѡ�� ���� ��� �ߴ� ��ɫ\n\t\t\t\t  ");
		scanf("%s",keyy);
		Clo_finding(keyy,head,u);
	} 
	if(u==2)
	Clo_manage(); 
	else
	Vis_window();
	
}
void Clo_change()///��װ�޸ĺ���
{
	system("cls");
	printf("\t\t\t\t  **************��װ�޸Ľ���****************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  **********     1.��װɾ��@_@    **********\n");
	printf("\n");
	printf("\t\t\t\t  **********   2.��װ�����޸�@_@  **********\n");
	printf("\n");
	printf("\t\t\t\t  **********     3.�����ϲ�@_@    **********\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\t\t\t\t  ") ;
	int x,y,m,l;
	scanf("%d",&x); 
	system("cls");
	FILE *fp;
	fp = fopen("Clo_list.txt","r");
	List2 head,p1,p2;
	char i,key[20];
	p1 = head = (List2)malloc(sizeof(struct Clo));
	head->next = NULL;	
	while(!feof(fp))
	{
		p2 = (List2)malloc(sizeof(struct Clo));
		fscanf(fp," %d %s %s %s %s %f %d\n",&p2->num,p2->brand,p2->nam,p2->size,p2->color,&p2->price,&p2->amount);
		p1->next=p2;
		p2->next=NULL;
		p1=p2;
	}	
	if (x==1) 
	{
		fp = fopen("Clo_list.txt","w");
		p2 = head->next;
		printf("\t\t\t\t  Ҫ���ĵķ�װ����Ϊ:");
		printf("\t\t\t\t  ������������Ϣ���ȷ����ϲ���ң�\n�س������ϲ㣬�����������");
		i = getch();
		if (i==13) Clo_manage();
		scanf("%s",key);
		while(p2)
		{
			m=0;
			if(!strcmp(p2->nam,key))
			{
				l=1;
				printf("\t\t\t\t  �Ƿ�ɾ���÷�װ�����Ϣ��\n");
				printf("\t\t\t\t  �س�ɾ������������أ�");
				i=getch();
				if (i==13)
				{
					m=1;
					p1 = p2;
					p2 = p2->next;
					free(p1);
				}
			}
			fprintf(fp," %d %s %s %s %s %f %d\n",p2->num,p2->brand,p2->nam,p2->size,p2->color,p2->price,p2->amount);
			p2 = p2->next;
		}
		fclose(fp);
	}
	else if(x==2)
	{
		fp = fopen("Clo_list.txt","w");
		p2 = head->next;
		printf("\t\t\t\t  Ҫ���ĵķ�װ����Ϊ:");
		printf("\t\t\t\t  ������������Ϣ���ȷ����ϲ���ң�\n�س������ϲ㣬�����������");
		i = getch();
		if (i==13) Clo_manage();
		scanf("%s",key);
		while(p2)
		{
			if(!strcmp(p2->nam,key))
			{
				l=1;
				printf("\t\t\t\t  Ŀǰ�÷�װ��ϢΪ��\n");
				printf("\t\t\t\t    ���    Ʒ��    ����     �ߴ�     ��ɫ     �۸�     ����\n");
				printf("\t\t\t\t   %-10d%-10s%-10s %-10s %-10s %-10f %-10d\n",p2->num,p2->brand,p2->nam,p2->size,p2->color,p2->price,p2->amount);
				printf("\n\t\t\t\t  ���ڸ÷�װ�����������ĵ���Ŀ���\n");
				printf("\t\t\t\t  ps:���� �۸�ֻ���������֣�����ֻ��������������\n");
				printf("\t\t\t\t  �ɸ���Ŀ��1.���� 2.Ʒ�� 3.�ߴ� 4.��ɫ 5.�۸� 6.����\n");
				scanf("%d",&y);
				printf("\t\t\t\t  ����ĺ����ݣ�");
				scanf("%s",key);
				switch(y)
				{
					case 1:
						printf("\t\t\t\t  ���ݱ仯Ϊ%s -> %s",p2->nam,key);
						strcpy(p2->nam,key);
						break;
					case 2:
						printf("\t\t\t\t  ���ݱ仯Ϊ%s -> %s",p2->brand,key);
						strcpy(p2->brand,key);
						break;
					case 3:
						printf("\t\t\t\t  ���ݱ仯Ϊ%s -> %s",p2->size,key);
						strcpy(p2->size,key);
						break;
					case 4:
						printf("\t\t\t\t  ���ݱ仯Ϊ%s -> %s",p2->color,key);
						strcpy(p2->color,key);
						break;
					case 5:
						y = atoi(key);
						printf("\t\t\t\t  ���ݱ仯Ϊ%f -> %f",p2->price,y);
						p2->price = y;
						break;
					case 6:
						y = atoi(key);
						printf("\t\t\t\t  ���ݱ仯Ϊ%d -> %d",p2->amount,y);
						p2->amount = y;
						break;
					default :
					    printf("\t\t\t\t  δ�����壬������������ϲ�\n") ;
					    getch();
						system("cls"); 
						Clo_manage();						 
				}
			}
			fprintf(fp," %d %s %s %s %s %f %d\n",p2->num,p2->brand,p2->nam,p2->size,p2->color,p2->price,p2->amount);
			p2 = p2->next;
		}
		fclose(fp);
	}
	else if(x==3)
	{
		Clo_manage(); 		
	}
	else if(x!=1 && x!=2 && x!=3)
	{
		printf("\t\t\t\t  ����δ�����壬��������أ�");
		getch();
		Clo_manage(); 
	}
	if(l==0)
	{
		printf("\t\t\t\t  �÷�װδ��¼�룡\n\t\t\t\t  ����������ϲ�"); 
		getch();
		Clo_manage();
	}
	printf("\t\t\t\t  ������ɣ�����������ϲ㣡");
	getch();
	Clo_manage();
} 
int Clo_stat()///��װ������ͳ��
{
	FILE *fp;
	fp = fopen("Clo_list.txt","r");
	char nam[20],size[20],color[20],brand[20];
	int amount,sum=0,num;
	float price;
	while(!feof(fp))
	{
		fscanf(fp," %d %s %s %s %s %f %d",&num,brand,nam,size,color,&price,&amount);
		sum++;
	} 
	fclose(fp);
	return sum;
} 
void Vip_manage()///���Ľ���   ��Ա������� 
{
	system("cls");
	int x1;
	printf("\t\t\t\t  ****************��Ա�������**************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  **********     1.��Ա¼��@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  **********     2.��Ϣ��ѯ@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  **********     3.�����ϲ�@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\t\t\t\t  ") ;
	scanf("%d",&x1);
	switch (x1)
	{
		case 1:
			Vip_enter();
			break;
		case 2:
			Vip_find();
			break;
		case 3:
			Adm_manage();
			break;
		default :
		    printf("\t\t\t\t  δ�����壬������������ϲ�\n") ;
		    getch();
			system("cls"); 
			Adm_manage();
	}
}
void Vip_enter()///��Ա¼�� 
{
	system("cls");
	FILE *fp;
	int i=0,j=0,k=0,num=0;
	char nam[20]={"********"},nam0[20],phone[20]={"***********"},phone0[20],num0[20];
	float price=0,l=0;
	fp = fopen("Vip_list.txt","r");
	if(fp == NULL)
	{
		j=1;
		fp = fopen("Vip_list.txt","a");
		fprintf(fp," %d %s %s %f\n",num,nam,phone,price);
	} 
	fclose(fp);
	printf("\t\t\t\t  �����Ա��:");
	scanf("%s",nam);
	if(j==0);
	{
		fp = fopen("Vip_list.txt","r");
		while(!feof(fp))
		{
			fscanf(fp," %d %s %s %f\n",&num,nam0,phone0,&price);
			{
				if (!strcmp(nam0,nam))
				{
					i=1;
					printf("\t\t\t\t  �Ѵ��ڸû�Ա��������������ֻ���ȷ���Ƿ�Ϊͬһ��\n");
					printf("\t\t\t\t  �����ֻ���:\n\t\t\t\t  ");
					scanf("%s",phone);
					if(!strcmp(phone0,phone))
					{
						printf("\t\t\t\t  �û�Ա�Ѵ��ڣ�����������ϲ㣡");
						getch();
						Vip_manage(); 
					} 
					break;
				}
			}
		}
	}
	if (i==0)
	{
		printf("\t\t\t\t  �����ֻ��ţ�");
		scanf("%s",phone);
		printf("\t\t\t\t  ���ٴ������ֻ��ţ�");
		scanf("%s",phone0); 
		if (strcmp(phone,phone0))
		{
			printf("\t\t\t\t  �����ֻ��������벻һ��,����������ϲ㣡");
			getch();
			Vip_manage();
		}
	}
	num = Vip_stat();
	fp = fopen("Vip_list.txt","a");
	fprintf(fp," %d %s %s %f\n",num,nam,phone,l);
	fclose(fp);
	printf("\n\t\t\t\t  ¼��ɹ�������������ϲ㣡");
	getch();
	Vip_manage(); 
 } 
int Vip_stat()///��Ա��ͳ�� 
{
	FILE *fp;
	fp = fopen("Vip_list.txt","r");
	int sum=0,n;
	float price;
	if (fp == NULL)
	{
		sum = 0;
		return sum;
	}
	char nam[20],phone[20];
	while(!feof(fp))
	{
		fscanf(fp," %d %s %s %f\n",&n,nam,phone,&price);
		sum++;
	}
	fclose(fp);
	return sum;
 } 
void Vip_find()///��Ա��Ϣ��ѯ 
{
	system("cls");
	FILE *fp;
	List3 head,p1,p2;
    char key1[20];
	p1 = head = (List3)malloc(sizeof(struct Vip));
	head->next = NULL;
	fp = fopen("Vip_list.txt","r");
	if (fp == NULL )
	{
		printf("\t\t\t\t  ��δ������ԱĿ¼����������أ�");
		getch(); 
		Vip_manage();
	}
	while(!feof(fp))
	{
		p2 = (List3)malloc(sizeof(struct Vip));
		fscanf(fp," %d %s %s %f\n",&p2->num,p2->nam,p2->phone,&p2->score);
		p1->next=p2;
		p2->next=NULL;
		p1=p2;
	}
	fclose(fp);
	printf("\t\t\t\t  �����ѯ�������������������ֻ���\n\t\t\t\t  ");
	scanf("%s",key1);
	Vip_finding(key1,head);	
}
void Vip_use(char *key,float money)///����ʱʹ�� 
{
	FILE *fp;
	int i,j=0,flag = 0;
	List3 head,p1,p2;
	fp = fopen("Vip_list.txt","r");
	p1 = head = (List3)malloc(sizeof(struct Vip));
	head->next=NULL;
	while(!feof(fp))
	{
		p2 = (List3)malloc(sizeof(struct Vip));
		fscanf(fp," %d %s %s %f\n",&p2->num,p2->nam,p2->phone,&p2->score);
		p1->next=p2;
		p2->next=NULL;
		p1 = p2;
	}
	fclose(fp);
	fp = fopen("Vip_list.txt","w");
	p2 = head->next;
	while (p2)
	{
		i = 0; 
		if(!strcmp(p2->phone,key))
		{
			i=1;
			flag = 1;
			fprintf(fp," %d %s %s %f\n",p2->num,p2->nam,p2->phone,money); 
		}
		if(i==0)
		{
			fprintf(fp," %d %s %s %f\n",p2->num,p2->nam,p2->phone,p2->score); 
		}
		p2 = p2->next;
	}
	fclose(fp);
	if(flag == 0)
	{
		printf("\t\t\t\t  ��Աδ��¼�룬��¼����´�ʹ�ã�\n"); 
	}
	printf("\t\t\t\t  ���ֳɹ�!"); 
}
void Vip_finding(char *key,List3 headold)///��ǰ������Ȳ�ѯ 
{
	system("cls");
	char i,keyy[20];
	int j=0;
	List3 p,head,p1,p2;
	p = headold->next;
	p1 = head = (List3)malloc(sizeof(struct Vip));
	head->next = NULL;
	while (p)
	{
		if(!strcmp(p->nam,key) ||!strcmp(p->phone,key))
		{
			j=1;
			printf("\t\t\t\t  ���      ����       �ֻ�����    ����\n");
			printf("\t\t\t\t  ----------------------------------------\n");
			printf("\t\t\t\t  %-10d%-10s %-10s %-10.2f\n",p->num,p->nam,p->phone,p->score);
			p2 = (List3)malloc(sizeof(struct Vip));
			p2->num = p->num;
			strcpy(p2->nam,p->nam);
			strcpy(p2->phone,p->phone);
			p2->score = p->score;
			p2->next = NULL;
			p1->next = p2;
			p1 = p2;
			p2=p2->next;
		}
		p=p->next;
	}
	if(j==0)
	{
		printf("\t\t\t\t  �޶�Ӧ��Ա������������ϲ㣡");
		getch();
		Vip_find(); 
	}
	printf("\n\t\t\t\t  �Ƿ������ѯ���س��ڵ�ǰ�����¼�����ѯ������������ϲ�\n");
	i = getch();
	if (i==13)
	{
		printf("\t\t\t\t  �����ѯ��������ѡ�� ���� ��� �ߴ� ��ɫ\n");
		scanf("%s",keyy);
		Vip_finding(keyy,head);
	} 
	Vip_manage(); 
 } 
void Sale_system()///�������   ���۹������ 
{
	system("cls");
	int x4;
	printf("\t\t\t\t  ****************���۹������**************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  ***********    1.ʹ�ü�¼@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  ***********  2.���۲�Ʒ����@_@ ***********\n");
	printf("\n");
	printf("\t\t\t\t  ***********    3.�����ϲ�@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\t\t\t\t  ") ;
	scanf("%d",&x4);
	switch (x4)
	{
		case 1:
			Use_history();
			break;
		case 2:
			Data_sort();
			break;
		case 3:
			Adm_manage();
			break;
		default :
		    printf("\n\t\t\t\t  δ�����壬������������ϲ�\n") ;
		    getch();
			system("cls"); 
			Adm_manage();
	}
}
void Sale_list()///���з�װ������
{
	FILE *fp;
	printf("\t\t\t\t  ��ǰ�������з�װ��Ϣ�У�\n") ;
	printf("\t\t\t\t ***********************************************************************\n");
	printf("\t\t\t\t *���      Ʒ��           ����      �ߴ�      ��ɫ      �۸�      ����*\n");
	fp = fopen("Clo_list.txt","r");
	List2 head,p1,p2;
	p1 = head = (List2)malloc(sizeof(struct Clo));
	head ->next = NULL;
	while(!feof(fp))
	{
		p2 = (List2)malloc(sizeof(struct Clo));
		fscanf(fp," %d %s %s %s %s %f %d\n",&p2->num,p2->brand,p2->nam,p2->size,p2->color,&p2->price,&p2->amount);
		p1->next=p2;
		p2->next=NULL;
		p1=p2;
	}	
	p2 = head->next;
	while(p2)
	{
		printf("\t\t\t\t *---------------------------------------------------------------------*\n");
		printf("\t\t\t\t *%-10d%-15s%-10s%-10s%-10s%-10.2f%-4d*\n",p2->num,p2->brand,p2->nam,p2->size,p2->color,p2->price,p2->amount);
		p2 = p2->next;
	}
	fclose(fp);
	printf("\t\t\t\t ***********************************************************************\n");
} 
void Sale_window()///���۴��� 
{
	system("cls");
	Sale_list();
	FILE *fp1,*fp2;
	char key[20],j,brand[20],nam[20];
	int many,i,num,flag=0;
	float money;
	List2 head,p1,p2;
	fp1 = fopen("Clo_list.txt","r");
	if(fp1 == NULL)
	{
		printf("\n\t\t\t\t  ���޷�װ�����ۣ���������أ�");
		getch();
		Sale_system(); 
	}
	fp2 = fopen("Sale_history.txt","a");
	p1 = head = (List2)malloc(sizeof(struct Clo));
	head->next = NULL;
	while (!feof(fp1))
	{
		p2 = (List2)malloc(sizeof(struct Clo));
		fscanf(fp1," %d %s %s %s %s %f %d\n",&p2->num,p2->brand,p2->nam,p2->size,p2->color,&p2->price,&p2->amount);
		p2->next = NULL;
		p1->next = p2;
		p1 = p2;
	}
	fclose(fp1);
	printf("\t\t\t\t  �����������װ��š����ơ���ɫ��Ʒ�ƣ���Ҳ���������ֻ�Ʒ�ƹؼ��֣�");
	scanf("%s",key);
	p2 = head->next;
	while(p2)
	{
		flag = 0;
		if(!strcmp(p2->nam,key) || !strcmp(p2->color,key) || !strcmp(p2->brand,key) ||strstr(p2->brand,key)||strstr(p2->color,key)||strstr(p2->nam,key)||atoi(key) == p2->num)
		{
			fp1 = fopen("Clo_list.txt","w"); 
			break;
		}
		else
		{
			flag = 1;
		}
		p2 = p2->next;	
	}
	if(flag == 1)
	{
		printf("\t\t\t\t  ���޴˷�װ���ͣ��������������������");
		getch();
		Sale_window(); 
	}
	p2 = head->next;
	while(p2)
	{
		i=0;
		if(!strcmp(p2->nam,key) || !strcmp(p2->color,key) || !strcmp(p2->brand,key) || strstr(p2->nam,key) ||strstr(p2->brand,key) ||atoi(key) == p2->num)
		{
			printf("\t\t\t\t  �÷�װ��ϢΪ��\n\t\t\t\t  ���      Ʒ��           ����      �ߴ�      ��ɫ      �۸�      ����\n");
			printf("\t\t\t\t  %-10d%-15s%-10s%-10s%-10s%-10.2f%-10d\n",p2->num,p2->brand,p2->nam,p2->size,p2->color,p2->price,p2->amount);
			printf("\t\t\t\t  �Ƿ���\n\t\t\t\t  �س�������������������ñ�š���������ɫ��Ʒ�Ƶķ�װ!\n");
			j = getch();
			if(j==13)		
			{
				i=1;
				printf("\t\t\t\t  ���빺��������");
				scanf("%d",&many);
				p2->amount = p2->amount-many;
				while(p2->amount<0)
				{
					printf("\t\t\t\t  ��治�㣬����ٹ�������");
					p2->amount = p2->amount+many;
					scanf("%d",&many);
					if(p2->amount-many<0)
					{
						printf("\t\t\t\t  ������˼���÷�װ��ʱȱ����\n\t\t\t\t  �������ϲ㣡");
						getch();
						Sale_window(); 
						break;
					}
					p2->amount = p2->amount-many;
				}
				money = many*p2->price; 
				fprintf(fp2," %d %s %s %s %s %.2f %d\n",p2->num,p2->brand,p2->nam,p2->size,p2->color,money,many);	
				printf("\t\t\t\t  �Ƿ�ʹ�û�Ա���л��֣�\n\t\t\t\t  �س�ʹ�ã����������.");
				j = getch();
				{
					if(j==13)
					{
						printf("\n\t\t\t\t  ����绰���룺"); 
						scanf("%s",key);
						Vip_use(key,money);
					}
				} 		
			}		 
		}
		fprintf(fp1," %d %s %s %s %s %.2f %d\n",p2->num,p2->brand,p2->nam,p2->size,p2->color,p2->price,p2->amount);
		if(p2->next==NULL)
		{
			printf("\n\t\t\t\t  ������ϣ��޸��������Ϣ��\n\n\t\t\t\t  �س����½��й�����������أ�\n\t\t\t\t  "); 
		}
		p2 = p2->next;	
	}
	fclose(fp1);
	fclose(fp2);
	j = getch();
	if(j==13)
	{
		Sale_window();
	} 
	Vis_window();
}
void Use_history()///ʹ����ʷ 
{
	FILE *fp1;
	int i=0,j=1,sum=0,n=Clo_stat();
	float in_all=0;
	struct Clo sale_data[n];
	List2 head, p1 , p2;
	p1 = head =(List2)malloc(sizeof(struct Clo));
	head->next = NULL;
	fp1 = fopen("Sale_history.txt","r");
	printf("\t\t\t\t  ��ǰ���۳��ķ�װ������ϢΪ:\n");
	printf("\t\t\t\t ************************************************************************\n");
	printf("\t\t\t\t *���      Ʒ��       ����      �ߴ�      ��ɫ      �۸�      ����     *\n"); 
	while(!feof(fp1))
	{
		p2 = (List2)malloc(sizeof(struct Clo));
		fscanf(fp1," %d %s %s %s %s %f %d\n",&p2->num,p2->brand,p2->nam,p2->size,p2->color,&p2->price,&p2->amount);
		printf("\t\t\t\t *%-10d%-10s%-10s%-10s%-10s%-10.2f%-10d*\n",p2->num,p2->brand,p2->nam,p2->size,p2->color,p2->price,p2->amount);
		printf("\t\t\t\t *----------------------------------------------------------------------*\n");
		sum+=p2->amount;
		in_all+=p2->price;
		p2->next = NULL;
		p1->next = p2;
		p1 = p2;
	}
	printf("\t\t\t\t ************************************************************************\n");
	printf("\t\t\t\t  ��������Ϊ%d�������۶�Ϊ%.2f ",sum,in_all);
	fclose(fp1);
	for (i=0;i<n;i++)
	{
		sale_data[i].num = 0;
		sale_data[i].price = 0;
		sale_data[i].amount = 0;
		strcpy(sale_data[i].nam,"******");
		strcpy(sale_data[i].size,"******");
	}
	p2 = head->next;
	while(p2)
	{
		for(i=0;i<n;i++)
		{
			if(!strcmp(sale_data[i].nam,"******"))
			{
				strcpy(sale_data[i].nam,p2->nam);
				strcpy(sale_data[i].brand,p2->brand);
				strcpy(sale_data[i].color,p2->color);
				strcpy(sale_data[i].size,p2->size);
				sale_data[i].num = p2->num;
				break;
			}	
			if(!strcmp(sale_data[i].nam,p2->nam))	
			{
				if(p2->num==sale_data[i].num)
				{
					strcpy(sale_data[i].nam,p2->nam);
					strcpy(sale_data[i].brand,p2->brand);
					strcpy(sale_data[i].color,p2->color);
					strcpy(sale_data[i].size,p2->size);
					sale_data[i].num = p2->num;
					break;
				}
				else
				{
					strcpy(sale_data[i+j].nam,p2->nam);
					strcpy(sale_data[i+j].brand,p2->brand);
					strcpy(sale_data[i+j].color,p2->color);
					strcpy(sale_data[i+j].size,p2->size);
					sale_data[i+j].num = p2->num;
					j++;
					break;
				}
			}			
		}
		p2 = p2->next;
	}
	p2 = head->next;
	while(p2)
	{
		for(i=0;i<n;i++)
		{
			
			if((p2->num==sale_data[i].num))
			{
				sale_data[i].price+=p2->price;
				sale_data[i].amount+=p2->amount;
			}
		}
		p2 = p2->next;
	}
	system("cls"); 
	fp1 = fopen("Sale_clear.txt","w");
	printf("\n\t\t\t\t  ÿ�ַ�װ����״��Ϊ��\n");
	printf("\t\t\t\t ************************************************************************\n");
	printf("\t\t\t\t *���      Ʒ��       ����      �ߴ�      ��ɫ      �۸�      ����     *\n");
	for (i=0;i<n;i++)
	{
		if(!strcmp(sale_data[i].nam,"******"))
		{
			break;
		}
		fprintf(fp1," %d %s %s %s %s %.2f %d\n",sale_data[i].num,sale_data[i].brand,sale_data[i].nam,sale_data[i].size,sale_data[i].color,sale_data[i].price,sale_data[i].amount);
		printf("\t\t\t\t *----------------------------------------------------------------------*\n");
		printf("\t\t\t\t *%-10d%-10s%-10s%-10s%-10s%-10.2f%-10d*\n",sale_data[i].num,sale_data[i].brand,sale_data[i].nam,sale_data[i].size,sale_data[i].color,sale_data[i].price,sale_data[i].amount);
	}
	fclose(fp1);
	printf("\t\t\t\t ************************************************************************\n");
	printf("\t\t\t\t  ����������ϲ㣡");
	getch();
	Sale_system();
}
int Sale_stat()///��¼���۷�װ������ 
{
	FILE *fp;
	fp = fopen("Sale_clear.txt","r");
	char nam[20],brand[20],size[20],color[20];
	int amount,sum=0,num;
	float price;
	while(!feof(fp))
	{
		fscanf(fp," %d %s %s %s %s %f %d\n",&num,brand,nam,size,color,&price,&amount);
		sum++;
	} 
	fclose(fp);
	return sum;
}
void Data_sort()///�������� 
{
	system("cls"); 
	FILE *fp;
	fp = fopen("Sale_clear.txt","r");
	int i=0,j,k,n = Sale_stat();
	List2 head,p1,p2,l,group[n];
	p1 = head = (List2)malloc(sizeof(struct Clo));
	head->next = NULL;
	while(!feof(fp))
	{
		p2 = (List2)malloc(sizeof(struct Clo));
		group[i] = (List2)malloc(sizeof(struct Clo));
		fscanf(fp," %d %s %s %s %s %f %d\n",&p2->num,p2->brand,p2->nam,p2->size,p2->color,&p2->price,&p2->amount);
		group[i] = p2;
		p2->next = NULL;
		p1->next = p2;
		p1 = p2;
		i++;
	}
	fclose(fp);
	printf("\t\t\t\t  ���۸����������У�\n");
	printf("\t\t\t\t ************************************************************************\n");
	printf("\t\t\t\t *���      Ʒ��       ����      �ߴ�      ��ɫ      �۸�     ����      *\n"); 
	for (j=0;j<n;j++)
	{
		for (k=0;k<n-1-j;k++)
		{
			if( group[k]->price < group[k+1]->price )
			{
				l = (List2)malloc(sizeof(struct Clo));
				l=group[k+1];
				group[k+1]=group[k];
				group[k]=l;
			}
		}		
	} 
	for(i=0;i<n;i++)
	{
		printf("\t\t\t\t *%-10d%-10s%-10s%-10s%-10s%-10.2f%-10d*\n",group[i]->num,group[i]->brand,group[i]->nam,group[i]->size,group[i]->color,group[i]->price,group[i]->amount);
	} 
	printf("\t\t\t\t ************************************************************************\n\n");
	printf("\t\t\t\t  ����������Ϊ��\n");
	printf("\t\t\t\t ************************************************************************\n");
	printf("\t\t\t\t *���      Ʒ��       ����      �ߴ�      ��ɫ      �۸�     ����      *\n"); 
	l = (List2)malloc(sizeof(struct Clo));
	for (j=0;j<n;j++)
	{
		for (k=0;k<n-1-j;k++)
		{
			if( (group[k]->amount) < (group[k+1]->amount) )
			{
				l=group[k+1];
				group[k+1]=group[k];
				group[k]=l;
			}
		}		
	}  
	for(i=0;i<n;i++)
	{
		printf("\t\t\t\t *%-10d%-10s%-10s%-10s%-10s%-10.2f%-10d*\n",group[i]->num,group[i]->brand,group[i]->nam,group[i]->size,group[i]->color,group[i]->price,group[i]->amount);
	} 
	printf("\t\t\t\t ************************************************************************\n\n");
	printf("\t\t\t\t  ������ߵķ�װ��ϢΪ��\n");
	printf("\t\t\t\t ************************************************************************\n");
	printf("\t\t\t\t *���      Ʒ��       ����      �ߴ�      ��ɫ      �۸�     ����      *\n"); 
	for (i=0;i<3;i++)
	{
		printf("\t\t\t\t *%-10d%-10s%-10s%-10s%-10s%-10.2f%-10d*\n",group[i]->num,group[i]->brand,group[i]->nam,group[i]->size,group[i]->color,group[i]->price,group[i]->amount);	
	}
	printf("\t\t\t\t ************************************************************************\n\n");
	printf("\t\t\t\t  ����������ϲ㣡");
	getch();
	Sale_system();	
}
main()
{ 
	system("color 3F");
	enter();
}
