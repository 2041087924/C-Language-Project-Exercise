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

INFO* Creat_Head(void);   //����һ�������ͷ�ڵ�
INFO* Creat_Node(void);   //����һ���µĽڵ�
void Add_student(INFO* head);   //��ӽڵ㣬�����и�ֵ 
int Menu(void);            //�˵� 
void All_printf(INFO* head);      //��ӡȫ��ѧ����Ϣ 
void Seek_student(INFO* head);    //����ѧ����Ϣ 
void Delete_student(INFO* head);  //ɾ��ѧ����Ϣ
void Revise_student(INFO* head);  //�޸�ѧ����Ϣ
void Insert_student(INFO* head);    //����ѧ����Ϣ 
void Sort_student(INFO* head);   //�ɼ�����

int main()
{
	int state=0;
	INFO* head=Creat_Head();
	while(1)
	{
		state=Menu();   //��ӡ�˵��Լ�����ѡ��	
		switch(state)
		{
			case 0:
				return 0;
			break;
			case 1:
				Add_student(head);    //����ѧ����Ϣ 
				printf("������Ϣ�ɹ�\n");
			break;
			case 2:
				Seek_student(head);       //����ѧ����Ϣ 
			break;
			case 3:
				Delete_student(head);    //ɾ��ѧ����Ϣ
			break;
			case 4:
				Revise_student(head);    //�޸�ѧ����Ϣ
			break;
			case 5:
				Insert_student(head);    //����ѧ����Ϣ  
			break;
			case 6:
				Sort_student(head);     //�ɼ�����
			break;
			case 7:
				All_printf(head);      //��ӡȫ��ѧ����Ϣ 
			break;
		}
	}
return 0;
}

/*����ͷ�ڵ�Ĵ���
	1.��ͨ��malloc()����,����ռ䣬��ȡͷ�ڵ�ĵ�ַ
	2.��ͷ�ڵ���г�ʼ��
*/ 
INFO* Creat_Head(void)   //����һ�������ͷ�ڵ�,���ķ���ֵ��һ����ַ 
{
	INFO* head=NULL;
	head = (INFO*)malloc(sizeof(INFO));   //����ռ� 
	if(head==NULL)
	{
		printf("����ʧ�ܣ�\n");
		return NULL; 
	}
	head->name[25]=0;
	head->sex[5]=0;
	head->id=0;
	head->mark=0;
	head->next=NULL;
	return head;
}

/*����һ���µĽڵ�
	1.ͨ��malloc(),�������пռ�ķ��䣬�õ��µĽڵ��ַ
	2.���½ڵ���г�ʼ��
*/ 
INFO* Creat_Node(void)   //����һ���µĽڵ㣬����ֵ��һ����ַ 
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
��ӽڵ�
	1.���� Creat_Node();
	2.���������ҵ�β�ڵ�
	3.���½ڵ�ĵ�ַ��ֵ��β�ڵ��next
	4.������Ϣ�����½ڵ��������ֵ
*/
void Add_student(INFO* head)   //��ӽڵ㣬�����и�ֵ 
{
	INFO* p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=Creat_Node();
	printf("����:");
	scanf("%s",p->next->name);
	printf("�Ա�:");
	scanf("%s",p->next->sex);
	printf("ѧ��:");
	scanf("%d",&(p->next->id));
	printf("����:");
	scanf("%f",&(p->next->mark));
	
}

/*�˵���ӡ���Լ�����ѡ��*/ 
int Menu(void)
{
	int state=0;
	printf("/*****��ӭʹ��ѧ����Ϣ����ϵͳ*****/\n"); 
	printf("/****       1.�����Ϣ        *****/\n"); 
	printf("/****       2.��ѯ��Ϣ        *****/\n");
	printf("/****       3.ɾ����Ϣ        *****/\n");
	printf("/****       4.�޸���Ϣ        *****/\n");
	printf("/****       5.����ѧ����Ϣ    *****/\n");
	printf("/****       6.�ɼ�����        *****/\n");
	printf("/****       7.��ӡȫ����Ϣ    *****/\n");
	printf("/****       0.�˳�            *****/\n");
	printf("������ѡ��\n");
	scanf("%d",&state);	
	return state;
}

/*��ӡȫ��ѧ����Ϣ*/
void All_printf(INFO* head)
{
	INFO* p=head->next;
	if(p == NULL)
	{
		printf("ѧ����ϢΪ��\n");
        return;
	}
	while(p != NULL) 
	{
        printf("����:%-25s �Ա�:%-8s ѧ��:%-8d �ɼ�:%.2f\n",p->name,p->sex,p->id,p->mark);
		p=p->next;
    }
	return;	
} 

/*  ��ѯѧ����Ϣ   */
void Seek_student(INFO* head)
{
	char name[25];
	INFO* p=head->next;
	if(p == NULL)
	{
		printf("ѧ����ϢΪ��\n");
        return;
	}
	printf("������Ҫ��ѯ��Ϣ��ѧ��������\n");
	scanf("%s",name);
	while(p != NULL) 
	{
		if(strcmp(name,p->name)==0)
		{
			printf("���ҳɹ�����ӡ��Ϣ��\n");
			printf("����:%-25s �Ա�:%-8s ѧ��:%-8d �ɼ�:%.2f\n",p->name,p->sex,p->id,p->mark);
			return; 
		}
		p=p->next;
    }
	printf("����ʧ�ܣ�δ�ҵ���ͬѧ��Ϣ\n");	
	return;
} 

/*ɾ��ѧ����Ϣ*/
void Delete_student(INFO* head)
{
	int n=0,sign=0;
	char name[25];
	INFO* temp=NULL;
	INFO* p=head;
	if(p == NULL)
	{
		printf("ѧ����ϢΪ�գ��޷�ɾ��\n");
        return;
	}
	printf("������Ҫɾ����Ϣ��ѧ��������\n");
	scanf("%s",name);
	while(p->next != NULL)
	{
		if(strcmp(p->next->name,name)==0)
		{
			printf("���ҳɹ�\n");
			printf("����:%-25s �Ա�:%-8s ѧ��:%-8d �ɼ�:%.2f\n",p->next->name,p->next->sex,p->next->id,p->next->mark);
			printf("�Ƿ�ɾ���� 1.ȷ��    0.ȡ��  \n");
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
		printf("����ʧ�ܣ�δ�ҵ���ͬѧ��Ϣ\n");	
	}
	else
	{
		printf("ɾ���ɹ�\n");	
	}
	return;
}

/*�޸�ѧ����Ϣ*/
void Revise_student(INFO* head)
{
	char name[25];
	INFO* p=head->next;
	if(p == NULL)
	{
		printf("ѧ����ϢΪ��\n");
        return;
	}
	printf("������Ҫ�޸���Ϣ��ѧ��������\n");
	scanf("%s",name);
	while(p != NULL)
	{
		if(strcmp(p->name,name)==0)
		{
			printf("���ҳɹ�����ӡ��Ϣ��\n");
			printf("����:%-25s �Ա�:%-8s ѧ��:%-8d �ɼ�:%.2f\n",p->name,p->sex,p->id,p->mark);
			printf("�������޸ĺ����Ϣ\n");
			printf("����:");
			scanf("%s",p->name);
			printf("�Ա�:");
			scanf("%s",p->sex);
			printf("ѧ��:");
			scanf("%d",&(p->id));
			printf("����:");
			scanf("%f",&(p->mark));
			printf("�޸���Ϣ�ɹ�\n");
			return; 
		}
	}
	printf("����ʧ�ܣ�δ�ҵ���ͬѧ��Ϣ\n");	
}

void Insert_student(INFO* head)          //����ѧ����Ϣ 
{
	char name[25];
	int val=0;
	INFO* p=head; 
	if(p->next == NULL)
	{
		printf("ѧ����ϢΪ��\n");
        return;
	}
	printf("������Ҫ��ѯ��Ϣ��ѧ��������\n");
	scanf("%s",name);
	while(p->next != NULL)
	{
		if(strcmp(name,p->next->name)==0)
		{
			printf("���ҳɹ�����ӡ��Ϣ��\n");
			printf("����:%-25s �Ա�:%-8s ѧ��:%-8d �ɼ�:%.2f\n",p->next->name,p->next->sex,p->next->id,p->next->mark);
			printf("0.ǰ�����\t1.�������\n");
			scanf("%d",&val);
			INFO* New=Creat_Node();   //����Ҫ����Ľڵ�
			if(New==NULL)
			{
				printf("�����ڵ㴴��ʧ��!\n");
				
			}
			if(val==1)
			{
				p=p->next;
			}
			New->next=p->next;
			p->next=New;
			printf("����:");
			scanf("%s",New->name);
			printf("�Ա�:");
			scanf("%s",New->sex);
			printf("ѧ��:");
			scanf("%d",&(New->id));
			printf("����:");
			scanf("%f",&(New->mark));
			printf("������Ϣ�ɹ�\n");
			return; 
		}
		p=p->next;
	}
	printf("����ʧ�ܣ�δ�ҵ���ͬѧ��Ϣ\n");	
}

/*�ɼ����򣬴Ӹ߳ɼ����ͳɼ�*/  
void Sort_student(INFO* head)
{
	INFO* tmp=head->next;   //tmpΪ��һ���ڵ�
	INFO* p=tmp->next;     //pΪ�ڶ����ڵ�
	char a[25];
	int ID;
	char s[5];
	float m;
	if(tmp == NULL)
	{
		printf("ѧ����ϢΪ��\n");
        return;
	}
	printf("�ɼ����Ӹߵ�������\n");

	while(tmp->next != NULL)
	{
		while(p != NULL)
		{
			if(tmp->mark < p->mark)
			{  //�����ŷ��� 
				strcpy(a,p->name);//�������� 
				strcpy(p->name,tmp->name);
				strcpy(tmp->name,a); 
				
				ID=p->id;//����ѧ�� 
				p->id=tmp->id;
				tmp->id=ID;
				
				m=p->mark;//�����ɼ� 
				p->mark=tmp->mark;
				tmp->mark=m;
				
				strcpy(s,p->sex);//�����Ա�
				strcpy(p->sex,tmp->sex);
				strcpy(tmp->sex,s); 	
			}
			p=p->next; 
		}
		tmp=tmp->next;
		p=tmp->next;
	}		
} 




