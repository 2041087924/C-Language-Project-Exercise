#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
typedef struct info{
	char name[25];
	char sex[5];
	int id;
	float mark;
	struct info* next;
}INFO;

INFO* Creat_Head(void);   //创建一个链表的头节点
INFO* Creat_Node(void);   //创建一个新的节点
void Add_student(INFO* head);   //添加节点，并进行赋值 
int Menu(void);            //菜单 
void All_printf(INFO* head);      //打印全部学生信息 
void Seek_student(INFO* head);    //查找学生信息 
void Delete_student(INFO* head);  //删除学生信息
void Revise_student(INFO* head);  //修改学生信息
void Insert_student(INFO* head);    //插入学生信息 
void Sort_student(INFO* head);   //成绩排序

int main()
{
	int state=0;
	INFO* head=Creat_Head();
	while(1)
	{
		state=Menu();   //打印菜单以及输入选择	
		switch(state)
		{
			case 0:
				return 0;
			break;
			case 1:
				Add_student(head);    //增加学生信息 
				printf("输入信息成功\n");
			break;
			case 2:
				Seek_student(head);       //查找学生信息 
			break;
			case 3:
				Delete_student(head);    //删除学生信息
			break;
			case 4:
				Revise_student(head);    //修改学生信息
			break;
			case 5:
				Insert_student(head);    //插入学生信息  
			break;
			case 6:
				Sort_student(head);     //成绩排序
			break;
			case 7:
				All_printf(head);      //打印全部学生信息 
			break;
		}
	}
return 0;
}

/*链表头节点的创建
	1.先通过malloc()函数,分配空间，获取头节点的地址
	2.将头节点进行初始化
*/ 
INFO* Creat_Head(void)   //创建一个链表的头节点,它的返回值是一个地址 
{
	INFO* head=NULL;
	head = (INFO*)malloc(sizeof(INFO));   //分配空间 
	if(head==NULL)
	{
		printf("创建失败！\n");
		return NULL; 
	}
	head->name[25]=0;
	head->sex[5]=0;
	head->id=0;
	head->mark=0;
	head->next=NULL;
	return head;
}

/*创建一个新的节点
	1.通过malloc(),函数进行空间的分配，得到新的节点地址
	2.对新节点进行初始化
*/ 
INFO* Creat_Node(void)   //创建一个新的节点，返回值是一个地址 
{
	INFO* New=NULL;
	New=(INFO*)malloc(sizeof(INFO));
	if(New==NULL)
	{
		return NULL;
	}
	New->name[25]=0;
	New->sex[5]=0;
	New->id=0;
	New->mark=0;
	New->next=NULL;
	return New;
}

/*
添加节点
	1.调用 Creat_Node();
	2.遍历链表找到尾节点
	3.把新节点的地址赋值给尾节点的next
	4.输入信息，对新节点的数据域赋值
*/
void Add_student(INFO* head)   //添加节点，并进行赋值 
{
	INFO* p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=Creat_Node();
	printf("姓名:");
	scanf("%s",p->next->name);
	printf("性别:");
	scanf("%s",p->next->sex);
	printf("学号:");
	scanf("%d",&(p->next->id));
	printf("分数:");
	scanf("%f",&(p->next->mark));
	
}

/*菜单打印，以及输入选择*/ 
int Menu(void)
{
	int state=0;
	printf("/*****欢迎使用学生信息管理系统*****/\n"); 
	printf("/****       1.添加信息        *****/\n"); 
	printf("/****       2.查询信息        *****/\n");
	printf("/****       3.删除信息        *****/\n");
	printf("/****       4.修改信息        *****/\n");
	printf("/****       5.插入学生信息    *****/\n");
	printf("/****       6.成绩排序        *****/\n");
	printf("/****       7.打印全部信息    *****/\n");
	printf("/****       0.退出            *****/\n");
	printf("请输入选择：\n");
	scanf("%d",&state);	
	return state;
}

/*打印全部学生信息*/
void All_printf(INFO* head)
{
	INFO* p=head->next;
	if(p == NULL)
	{
		printf("学生信息为空\n");
        return;
	}
	while(p != NULL) 
	{
        printf("姓名:%-25s 性别:%-8s 学号:%-8d 成绩:%.2f\n",p->name,p->sex,p->id,p->mark);
		p=p->next;
    }
	return;	
} 

/*  查询学生信息   */
void Seek_student(INFO* head)
{
	char name[25];
	INFO* p=head->next;
	if(p == NULL)
	{
		printf("学生信息为空\n");
        return;
	}
	printf("请输入要查询信息的学生姓名：\n");
	scanf("%s",name);
	while(p != NULL) 
	{
		if(strcmp(name,p->name)==0)
		{
			printf("查找成功，打印信息：\n");
			printf("姓名:%-25s 性别:%-8s 学号:%-8d 成绩:%.2f\n",p->name,p->sex,p->id,p->mark);
			return; 
		}
		p=p->next;
    }
	printf("查找失败，未找到该同学信息\n");	
	return;
} 

/*删除学生信息*/
void Delete_student(INFO* head)
{
	int n=0,sign=0;
	char name[25];
	INFO* temp=NULL;
	INFO* p=head;
	if(p == NULL)
	{
		printf("学生信息为空，无法删除\n");
        return;
	}
	printf("请输入要删除信息的学生姓名：\n");
	scanf("%s",name);
	while(p->next != NULL)
	{
		if(strcmp(p->next->name,name)==0)
		{
			printf("查找成功\n");
			printf("姓名:%-25s 性别:%-8s 学号:%-8d 成绩:%.2f\n",p->next->name,p->next->sex,p->next->id,p->next->mark);
			printf("是否删除： 1.确定    0.取消  \n");
			scanf("%d",&n);
			if(n==1)
			{
				temp=p->next;
				p->next=p->next->next;
				free(temp);
				temp=NULL;
				break;
			}
			else
			{
				return;
			}	
		}
		p=p->next;
	}
	if(sign == 0)
	{
		printf("查找失败，未找到该同学信息\n");	
	}
	else
	{
		printf("删除成功\n");	
	}
	return;
}

/*修改学生信息*/
void Revise_student(INFO* head)
{
	char name[25];
	INFO* p=head->next;
	if(p == NULL)
	{
		printf("学生信息为空\n");
        return;
	}
	printf("请输入要修改信息的学生姓名：\n");
	scanf("%s",name);
	while(p != NULL)
	{
		if(strcmp(p->name,name)==0)
		{
			printf("查找成功，打印信息：\n");
			printf("姓名:%-25s 性别:%-8s 学号:%-8d 成绩:%.2f\n",p->name,p->sex,p->id,p->mark);
			printf("请输入修改后的信息\n");
			printf("姓名:");
			scanf("%s",p->name);
			printf("性别:");
			scanf("%s",p->sex);
			printf("学号:");
			scanf("%d",&(p->id));
			printf("分数:");
			scanf("%f",&(p->mark));
			printf("修改信息成功\n");
			return; 
		}
	}
	printf("查找失败，未找到该同学信息\n");	
}

void Insert_student(INFO* head)          //插入学生信息 
{
	char name[25];
	int val=0;
	INFO* p=head; 
	if(p->next == NULL)
	{
		printf("学生信息为空\n");
        return;
	}
	printf("请输入要查询信息的学生姓名：\n");
	scanf("%s",name);
	while(p->next != NULL)
	{
		if(strcmp(name,p->next->name)==0)
		{
			printf("查找成功，打印信息：\n");
			printf("姓名:%-25s 性别:%-8s 学号:%-8d 成绩:%.2f\n",p->next->name,p->next->sex,p->next->id,p->next->mark);
			printf("0.前面插入\t1.后面插入\n");
			scanf("%d",&val);
			INFO* New=Creat_Node();   //创建要插入的节点
			if(New==NULL)
			{
				printf("新增节点创建失败!\n");
				
			}
			if(val==1)
			{
				p=p->next;
			}
			New->next=p->next;
			p->next=New;
			printf("姓名:");
			scanf("%s",New->name);
			printf("性别:");
			scanf("%s",New->sex);
			printf("学号:");
			scanf("%d",&(New->id));
			printf("分数:");
			scanf("%f",&(New->mark));
			printf("插入信息成功\n");
			return; 
		}
		p=p->next;
	}
	printf("查找失败，未找到该同学信息\n");	
}

/*成绩排序，从高成绩到低成绩*/  
void Sort_student(INFO* head)
{
	INFO* tmp=head->next;   //tmp为第一个节点
	INFO* p=tmp->next;     //p为第二个节点
	char a[25];
	int ID;
	char s[5];
	float m;
	if(tmp == NULL)
	{
		printf("学生信息为空\n");
        return;
	}
	printf("成绩将从高到低排序\n");

	while(tmp->next != NULL)
	{
		while(p != NULL)
		{
			if(tmp->mark < p->mark)
			{  //降序排分数 
				strcpy(a,p->name);//交换名字 
				strcpy(p->name,tmp->name);
				strcpy(tmp->name,a); 
				
				ID=p->id;//交换学号 
				p->id=tmp->id;
				tmp->id=ID;
				
				m=p->mark;//交换成绩 
				p->mark=tmp->mark;
				tmp->mark=m;
				
				strcpy(s,p->sex);//交换性别
				strcpy(p->sex,tmp->sex);
				strcpy(tmp->sex,s); 	
			}
			p=p->next; 
		}
		tmp=tmp->next;
		p=tmp->next;
	}		
} 




