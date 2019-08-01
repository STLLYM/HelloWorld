#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include <windows.h>
#define KEY 0x86

typedef struct Adm* List1;
typedef struct Clo* List2;
typedef struct Vip* List3;
struct Adm//管理员信息包括  名字  密码 
{
	char nam[20],password[20];
	struct Adm* next;
};
struct Clo//服装信息包括   品牌 名字 编号 尺寸 颜色 价格 总数 
{
	char brand[20],nam[20],size[20],color[20];
	float price;
	int amount,num;
	struct Clo* next;
};
struct Vip//会员信息包括    姓名 电话 积分 
{
	char nam[20],phone[20];
	float score; 
	int num;          //会员号自动分配 
	struct Vip* next;
};
void enter0();                      //登陆界面 
void Vis_window();                  //游客界面 
void Adm_enter();                   //管理员录入
void Adm_change();                  //管理员修改  
void Adm_load();                    //管理员登录 1  
void Adm_manage();                  //管理员管理界面 2                
void Clo_manage();                  //服装管理界面 3 
void Clo_add();                     //服装添加 
void Clo_find();                    //服装信息查询 
void Clo_finding();                 //当前条件下深度查询 
void Clo_change();                  //服装信息改变  
int Clo_stat();                     //服装种类数目统计 
void Vip_manage();                  //会员管理界面 4                
void Vip_enter();                   //会员信息录入
int Vip_stat();                     //会员数统计 
void Vip_find();                    //会员信息查询
void Vip_finding();                 //当前条件下深查 
void Sale_system();                 //销售系统管理界面 5 
void Sale_list();                   //所有服装显示 
void Sale_window();                 //销售窗口 
int Sale_stat();                    //销售服装种类数 
void Use_history();                 //使用记录 
void Data_sort();                   //本次销售排序 

void Pro_bar()///进度条程序 
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
void Mas_int()///关于 
{
	MessageBox(NULL, TEXT("名称：服装销售系统\n学校：西安邮电大学\n作者：大数据1801 孙涛"), TEXT("关于"), MB_OK);
 } 
void enter()///进入界面 
{
	Pro_bar();
	system("cls");
	int x0;
	char name[20];
	printf("\t\t\t\t  ***************程序主界面*****************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  ********     1.管理员界面@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  ********      2.游客界面@_@    ***********\n");
	printf("\n");
	printf("\t\t\t\t  ********     3.退出该程序@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  ******************************** 0.关于 **\n");
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
		    printf("\t\t\t\t  未被定义，按任意键返回当前\n") ;
		    getch();
			system("cls"); 
			enter();
    }
} 
void Vis_window()///游客进入窗口 
{
	system("cls");
	int x0;
	char name[20];
	printf("\t\t\t\t  ****************游客界面******************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  *********     1.服装查找@_@    ***********\n");
	printf("\n");
	printf("\t\t\t\t  *********     2.服装购买@_@    ***********\n");
	printf("\n"); 
	printf("\t\t\t\t  *********     3.返回上层@_@    ***********\n");
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
		    printf("\t\t\t\t  未被定义，按任意键返回上层\n") ;
		    getch();
			system("cls"); 
			enter();
	}
}
void enter0()///第一界面   登录界面 
{
	system("cls");
	int x0;
	char name[20];
	printf("\t\t\t\t  **************管理员主界面****************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  ********     1.添加管理员@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  ********     2.管理员修改@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  ********     3.管理员登录@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  ********     4.返回上一层@_@   ***********\n");
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
		    printf("\t\t\t\t  未被定义，按任意键返回上层\n") ;
		    getch();
			system("cls"); 
			enter0();
	}
}
void Adm_enter()///管理员录入 
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
	printf("\t\t\t\t  输入管理员名:");
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
					printf("\t\t\t\t  已存在该管理员，无需重复录入！\n");
					printf("\t\t\t\t  任意键返回上层！");
					getch();
					fclose(fp);
					enter0(); 
				}
			}
		}
	}
	fp = fopen("Adm_list.txt","a");
	printf("\t\t\t\t  输入密码:"); 
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
	printf("\n\t\t\t\t  请再次输入密码:");
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
		printf("\n\t\t\t\t  录入成功，任意键返回上层！");
	}
	else
	{
		printf("\n\t\t\t\t  录入失败，密码不一致，任意键返回上层:");		
	}
	getch(); 
	fclose(fp);
	enter0(); 
}
void Adm_load()///管理员登录 
{
	system("cls");
	FILE *fp;
	char nam[20],nam0[20],psword[20],psword0[20];
	int flag = 0,i,j;
	fp = fopen("Adm_list.txt","r");
	if (fp == NULL)
	{
		printf("\t\t\t\t  尚未创建管理员，任意键创建并录入.");
		Adm_enter();
	 } 
	printf("\t\t\t\t  输入登录管理员名称:");
	scanf("%s",nam0);
	while(!feof(fp))
	{
		fscanf(fp, " %s %s\n",nam,psword);
		if (!strcmp(nam,nam0))
		{
			flag = 1;
			printf("\t\t\t\t  输入密码:");
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
				Adm_manage();                           //进入管理员管理界面 
			}
			else
			{
				printf("\n\t\t\t\t  密码错误，任意键返回上层:");
				getch(); 
				enter0();
				break;
			}
		}
	}
	if (flag==0)
	{
		printf("\t\t\t\t  该管理员未录入，任意键返回上层！");
		getch();
		enter0(); 
	}
}
void Adm_change()///管理员修改 
{
	system("cls");
	printf("\t\t\t\t  *************管理员修改界面***************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  ********     1.管理员删除@_@    **********\n");
	printf("\n");
	printf("\t\t\t\t  ********   2.管理员密码修改@_@  **********\n");
	printf("\n");
	printf("\t\t\t\t  ********      3.返回上层@_@     **********\n");
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
		printf("\t\t\t\t  尚未录入管理员！\n\t\t\t\t  任意键返回上层");
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
		printf("\t\t\t\t  要更改的管理员姓名为:");
		scanf("%s",nam);
		while(p2)
		{
			m=0;
			if(!strcmp(p2->nam,nam))
			{
				l=1;
				printf("\t\t\t\t  是否删除该管理员？\n");
				printf("\t\t\t\t  回车删除，任意键返回！");
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
		printf("\t\t\t\t  要更改的管理员姓名为:");
		scanf("%s",nam);
		while(p2)
		{
			if(!strcmp(p2->nam,nam))
			{
				l=1;
				printf("\n\t\t\t\t  存在该管理员，继续输入将覆盖原密码");
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
		printf("\n\t\t\t\t  按键未被定义，任意键返回！");
		getch();
		enter0(); 
	}
	if(l==0)
	{
		printf("\n\t\t\t\t  该管理员未被录入！\n\t\t\t\t  任意键返回上层"); 
		getch();
		enter0();
	}
	printf("\n\t\t\t\t  操作完成，任意键返回上层！");
	getch();
	enter0();
}
void Adm_manage()///第二界面   管理员管理界面 
{
	system("cls");
	int x1;
	printf("\t\t\t\t  **************管理员管理界面**************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  **********     1.服装管理@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  **********     2.会员管理@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  **********     3.售卖系统@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  **********     4.返回上层@_@   ***********\n");
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
		    printf("\t\t\t\t  未被定义，按任意键返回上层\n") ;
		    getch();
			system("cls"); 
			Adm_manage();
	}
}
void Clo_manage()///第三界面   服装管理界面 
{
	system("cls");
	int x1;
	printf("\t\t\t\t  ****************服装管理界面**************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  **********     1.服装添加@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  **********     2.服装查询@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  **********     3.服装修改@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  **********     4.返回上层@_@   ***********\n");
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
		    printf("\t\t\t\t  未被定义，按任意键返回上层\n") ;
		    getch();
			system("cls"); 
			Clo_manage();
	}
} 
void Clo_add()///服装添加函数 
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
	printf("\t\t\t\t  请按照以下格式录入服装信息：\n");
	while(i==13)
	{
		p2 = (List2)malloc(sizeof(struct Clo));
		printf("\t\t\t\t  品牌    名称     尺寸     颜色     价格     总数\n\t\t\t\t  ");
		scanf("%s %s %s %s %f %d",p2->brand,p2->nam,p2->size,p2->color,&p2->price,&p2->amount);
		p2->num = n;
		p1->next = p2;
		p2->next = NULL;
		p1 = p2; 
		printf("\t\t\t\t  是否继续输入?回车继续输入，任意键返回上层！\n");
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
void Clo_find(int u)///服装查找函数 
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
		printf("\t\t\t\t  尚未创建服装目录，任意键返回！");
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
	printf("\t\t\t\t  输入查询条件，可选择 名字 品牌 尺寸 颜色或者关键字\n\t\t\t\t  ");
	scanf("%s",key1);
	Clo_finding(key1,head,u);	
} 
void Clo_finding(char* key,List2 headold,int u)///多条件查找 
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
			printf("\n\t\t\t\t  编号      品牌           名称      尺寸      颜色      价格      总数\n");
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
		printf("\t\t\t\t  无对应服装，任意键返回上层！");
		getch();
		if(u==2)
		Clo_manage(); 
		else
		Vis_window();
	}
	printf("\n\t\t\t\t  是否继续查询，回车在当前条件下继续查询，任意键返回上层\n\t\t\t\t  ");
	i = getch();
	if (i==13)
	{
		printf("输入查询条件，可选择 名字 编号 尺寸 颜色\n\t\t\t\t  ");
		scanf("%s",keyy);
		Clo_finding(keyy,head,u);
	} 
	if(u==2)
	Clo_manage(); 
	else
	Vis_window();
	
}
void Clo_change()///服装修改函数
{
	system("cls");
	printf("\t\t\t\t  **************服装修改界面****************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  **********     1.服装删除@_@    **********\n");
	printf("\n");
	printf("\t\t\t\t  **********   2.服装数据修改@_@  **********\n");
	printf("\n");
	printf("\t\t\t\t  **********     3.返回上层@_@    **********\n");
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
		printf("\t\t\t\t  要更改的服装姓名为:");
		printf("\t\t\t\t  如果遗忘相关信息可先返回上层查找！\n回车返回上层，任意键继续！");
		i = getch();
		if (i==13) Clo_manage();
		scanf("%s",key);
		while(p2)
		{
			m=0;
			if(!strcmp(p2->nam,key))
			{
				l=1;
				printf("\t\t\t\t  是否删除该服装相关信息？\n");
				printf("\t\t\t\t  回车删除，任意键返回！");
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
		printf("\t\t\t\t  要更改的服装姓名为:");
		printf("\t\t\t\t  如果遗忘相关信息可先返回上层查找！\n回车返回上层，任意键继续！");
		i = getch();
		if (i==13) Clo_manage();
		scanf("%s",key);
		while(p2)
		{
			if(!strcmp(p2->nam,key))
			{
				l=1;
				printf("\t\t\t\t  目前该服装信息为：\n");
				printf("\t\t\t\t    编号    品牌    名称     尺寸     颜色     价格     总数\n");
				printf("\t\t\t\t   %-10d%-10s%-10s %-10s %-10s %-10f %-10d\n",p2->num,p2->brand,p2->nam,p2->size,p2->color,p2->price,p2->amount);
				printf("\n\t\t\t\t  存在该服装，输入欲更改的条目编号\n");
				printf("\t\t\t\t  ps:其中 价格只能输入数字，总数只能输入整形数字\n");
				printf("\t\t\t\t  可改条目有1.名字 2.品牌 3.尺寸 4.颜色 5.价格 6.总数\n");
				scanf("%d",&y);
				printf("\t\t\t\t  输入改后数据：");
				scanf("%s",key);
				switch(y)
				{
					case 1:
						printf("\t\t\t\t  数据变化为%s -> %s",p2->nam,key);
						strcpy(p2->nam,key);
						break;
					case 2:
						printf("\t\t\t\t  数据变化为%s -> %s",p2->brand,key);
						strcpy(p2->brand,key);
						break;
					case 3:
						printf("\t\t\t\t  数据变化为%s -> %s",p2->size,key);
						strcpy(p2->size,key);
						break;
					case 4:
						printf("\t\t\t\t  数据变化为%s -> %s",p2->color,key);
						strcpy(p2->color,key);
						break;
					case 5:
						y = atoi(key);
						printf("\t\t\t\t  数据变化为%f -> %f",p2->price,y);
						p2->price = y;
						break;
					case 6:
						y = atoi(key);
						printf("\t\t\t\t  数据变化为%d -> %d",p2->amount,y);
						p2->amount = y;
						break;
					default :
					    printf("\t\t\t\t  未被定义，按任意键返回上层\n") ;
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
		printf("\t\t\t\t  操作未被定义，任意键返回！");
		getch();
		Clo_manage(); 
	}
	if(l==0)
	{
		printf("\t\t\t\t  该服装未被录入！\n\t\t\t\t  任意键返回上层"); 
		getch();
		Clo_manage();
	}
	printf("\t\t\t\t  操作完成，任意键返回上层！");
	getch();
	Clo_manage();
} 
int Clo_stat()///服装种类数统计
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
void Vip_manage()///第四界面   会员管理界面 
{
	system("cls");
	int x1;
	printf("\t\t\t\t  ****************会员管理界面**************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  **********     1.会员录入@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  **********     2.信息查询@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  **********     3.返回上层@_@   ***********\n");
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
		    printf("\t\t\t\t  未被定义，按任意键返回上层\n") ;
		    getch();
			system("cls"); 
			Adm_manage();
	}
}
void Vip_enter()///会员录入 
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
	printf("\t\t\t\t  输入会员名:");
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
					printf("\t\t\t\t  已存在该会员名，请继续输入手机号确认是否为同一人\n");
					printf("\t\t\t\t  输入手机号:\n\t\t\t\t  ");
					scanf("%s",phone);
					if(!strcmp(phone0,phone))
					{
						printf("\t\t\t\t  该会员已存在！任意键返回上层！");
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
		printf("\t\t\t\t  输入手机号：");
		scanf("%s",phone);
		printf("\t\t\t\t  请再次输入手机号：");
		scanf("%s",phone0); 
		if (strcmp(phone,phone0))
		{
			printf("\t\t\t\t  两次手机号码输入不一致,任意键返回上层！");
			getch();
			Vip_manage();
		}
	}
	num = Vip_stat();
	fp = fopen("Vip_list.txt","a");
	fprintf(fp," %d %s %s %f\n",num,nam,phone,l);
	fclose(fp);
	printf("\n\t\t\t\t  录入成功，任意键返回上层！");
	getch();
	Vip_manage(); 
 } 
int Vip_stat()///会员数统计 
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
void Vip_find()///会员信息查询 
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
		printf("\t\t\t\t  尚未创建会员目录，任意键返回！");
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
	printf("\t\t\t\t  输入查询条件，可输入姓名或手机号\n\t\t\t\t  ");
	scanf("%s",key1);
	Vip_finding(key1,head);	
}
void Vip_use(char *key,float money)///购买时使用 
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
		printf("\t\t\t\t  会员未被录入，请录入后下次使用！\n"); 
	}
	printf("\t\t\t\t  积分成功!"); 
}
void Vip_finding(char *key,List3 headold)///当前条件深度查询 
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
			printf("\t\t\t\t  编号      姓名       手机号码    积分\n");
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
		printf("\t\t\t\t  无对应会员，任意键返回上层！");
		getch();
		Vip_find(); 
	}
	printf("\n\t\t\t\t  是否继续查询，回车在当前条件下继续查询，任意键返回上层\n");
	i = getch();
	if (i==13)
	{
		printf("\t\t\t\t  输入查询条件，可选择 名字 编号 尺寸 颜色\n");
		scanf("%s",keyy);
		Vip_finding(keyy,head);
	} 
	Vip_manage(); 
 } 
void Sale_system()///第五界面   销售管理界面 
{
	system("cls");
	int x4;
	printf("\t\t\t\t  ****************销售管理界面**************\n");
	printf("\n");
	printf("\t\t\t\t  ******************************************\n");
	printf("\n");
	printf("\t\t\t\t  ***********    1.使用记录@_@   ***********\n");
	printf("\n");
	printf("\t\t\t\t  ***********  2.销售产品排序@_@ ***********\n");
	printf("\n");
	printf("\t\t\t\t  ***********    3.返回上层@_@   ***********\n");
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
		    printf("\n\t\t\t\t  未被定义，按任意键返回上层\n") ;
		    getch();
			system("cls"); 
			Adm_manage();
	}
}
void Sale_list()///所有服装的罗列
{
	FILE *fp;
	printf("\t\t\t\t  当前店铺所有服装信息有：\n") ;
	printf("\t\t\t\t ***********************************************************************\n");
	printf("\t\t\t\t *编号      品牌           名称      尺寸      颜色      价格      总数*\n");
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
void Sale_window()///销售窗口 
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
		printf("\n\t\t\t\t  暂无服装可销售，任意键返回！");
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
	printf("\t\t\t\t  输入欲购买服装编号、名称、颜色或品牌：（也可输入名字或品牌关键字）");
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
		printf("\t\t\t\t  查无此服装类型，请重新输入查找条件：");
		getch();
		Sale_window(); 
	}
	p2 = head->next;
	while(p2)
	{
		i=0;
		if(!strcmp(p2->nam,key) || !strcmp(p2->color,key) || !strcmp(p2->brand,key) || strstr(p2->nam,key) ||strstr(p2->brand,key) ||atoi(key) == p2->num)
		{
			printf("\t\t\t\t  该服装信息为：\n\t\t\t\t  编号      品牌           名称      尺寸      颜色      价格      总数\n");
			printf("\t\t\t\t  %-10d%-15s%-10s%-10s%-10s%-10.2f%-10d\n",p2->num,p2->brand,p2->nam,p2->size,p2->color,p2->price,p2->amount);
			printf("\t\t\t\t  是否购买？\n\t\t\t\t  回车购买，任意键继续检索该编号、名、称颜色或品牌的服装!\n");
			j = getch();
			if(j==13)		
			{
				i=1;
				printf("\t\t\t\t  输入购买数量：");
				scanf("%d",&many);
				p2->amount = p2->amount-many;
				while(p2->amount<0)
				{
					printf("\t\t\t\t  库存不足，请减少购买数量");
					p2->amount = p2->amount+many;
					scanf("%d",&many);
					if(p2->amount-many<0)
					{
						printf("\t\t\t\t  不好意思，该服装暂时缺货。\n\t\t\t\t  将返回上层！");
						getch();
						Sale_window(); 
						break;
					}
					p2->amount = p2->amount-many;
				}
				money = many*p2->price; 
				fprintf(fp2," %d %s %s %s %s %.2f %d\n",p2->num,p2->brand,p2->nam,p2->size,p2->color,money,many);	
				printf("\t\t\t\t  是否使用会员进行积分？\n\t\t\t\t  回车使用，任意键跳过.");
				j = getch();
				{
					if(j==13)
					{
						printf("\n\t\t\t\t  输入电话号码："); 
						scanf("%s",key);
						Vip_use(key,money);
					}
				} 		
			}		 
		}
		fprintf(fp1," %d %s %s %s %s %.2f %d\n",p2->num,p2->brand,p2->nam,p2->size,p2->color,p2->price,p2->amount);
		if(p2->next==NULL)
		{
			printf("\n\t\t\t\t  检索完毕，无更多相关信息，\n\n\t\t\t\t  回车重新进行购买，任意键返回！\n\t\t\t\t  "); 
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
void Use_history()///使用历史 
{
	FILE *fp1;
	int i=0,j=1,sum=0,n=Clo_stat();
	float in_all=0;
	struct Clo sale_data[n];
	List2 head, p1 , p2;
	p1 = head =(List2)malloc(sizeof(struct Clo));
	head->next = NULL;
	fp1 = fopen("Sale_history.txt","r");
	printf("\t\t\t\t  当前销售出的服装及其信息为:\n");
	printf("\t\t\t\t ************************************************************************\n");
	printf("\t\t\t\t *编号      品牌       名称      尺寸      颜色      价格      总数     *\n"); 
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
	printf("\t\t\t\t  总销售量为%d，总销售额为%.2f ",sum,in_all);
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
	printf("\n\t\t\t\t  每种服装销售状况为：\n");
	printf("\t\t\t\t ************************************************************************\n");
	printf("\t\t\t\t *编号      品牌       名称      尺寸      颜色      价格      总数     *\n");
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
	printf("\t\t\t\t  任意键返回上层！");
	getch();
	Sale_system();
}
int Sale_stat()///记录销售服装种类数 
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
void Data_sort()///数据排序 
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
	printf("\t\t\t\t  按价格收入排序有：\n");
	printf("\t\t\t\t ************************************************************************\n");
	printf("\t\t\t\t *编号      品牌       名称      尺寸      颜色      价格     总数      *\n"); 
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
	printf("\t\t\t\t  按销量排序为：\n");
	printf("\t\t\t\t ************************************************************************\n");
	printf("\t\t\t\t *编号      品牌       名称      尺寸      颜色      价格     总数      *\n"); 
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
	printf("\t\t\t\t  销量最高的服装信息为：\n");
	printf("\t\t\t\t ************************************************************************\n");
	printf("\t\t\t\t *编号      品牌       名称      尺寸      颜色      价格     总数      *\n"); 
	for (i=0;i<3;i++)
	{
		printf("\t\t\t\t *%-10d%-10s%-10s%-10s%-10s%-10.2f%-10d*\n",group[i]->num,group[i]->brand,group[i]->nam,group[i]->size,group[i]->color,group[i]->price,group[i]->amount);	
	}
	printf("\t\t\t\t ************************************************************************\n\n");
	printf("\t\t\t\t  任意键返回上层！");
	getch();
	Sale_system();	
}
main()
{ 
	system("color 3F");
	enter();
}
