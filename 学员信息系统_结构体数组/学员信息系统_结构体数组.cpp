#include <stdio.h>
#include <string.h>

void add_student(void);     //����ѧ����Ϣ 
void menu(void);            //�˵� 
void all_printf(void);      //��ӡȫ��ѧ����Ϣ 
void seek_student(void);    //����ѧ����Ϣ 
void delete_student(void);  //ɾ��ѧ����Ϣ
void revise_student(void);  //�޸�ѧ����Ϣ
void insert_student();      //����ѧ����Ϣ 
void sort_student(void);    //�ɼ�����

typedef struct {
	char name[25];
	int id;
	float mark;
}info;
info stu[80]={0};
int state=0;
int con_info=0;

int main()
{
//	int ret=0;
	while(1)
	{
		menu();   //��ӡ�˵��Լ�����ѡ��	
		switch(state)
		{
			case 0:
				return 0;
			break;
			case 1:
				add_student();          //����ѧ����Ϣ 
				printf("������Ϣ�ɹ�\n");
			break;
			case 2:
				seek_student();       //����ѧ����Ϣ 
			break;
			case 3:
				delete_student();    //ɾ��ѧ����Ϣ
			break;
			case 4:
				revise_student();    //�޸�ѧ����Ϣ
			break;
			case 5:
				all_printf();      //��ӡȫ��ѧ����Ϣ 
			break;
			case 6:
				sort_student();     //�ɼ�����
			break;
			case 7:
				insert_student();    //����ѧ����Ϣ 
			break;
		}
	}
}

void insert_student()          //����ѧ����Ϣ 
{
	int i=0,val=0;
	info seek_stu;
	printf("������Ҫ��ѯ��Ϣ��ѧ��������\n");
	scanf("%s",seek_stu.name);
	for(i=0;i<con_info;i++)
	{
		if(strcmp(seek_stu.name,stu[i].name)==0)
		{
			printf("���ҳɹ�����ӡ��Ϣ��\n");
			printf("����:%-25s ѧ��:%-8d �ɼ�:%.2f\n",stu[i].name,stu[i].id,stu[i].mark);
			printf("0.ǰ�����\t1.�������\n");
			scanf("%d",&val);
			i=i+val;
			for(int j = con_info; j > i; j--) 
			{
            	stu[j] = stu[j-1];
        	}
			printf("������ѧ��������ѧ�ţ��ɼ�\n");
			scanf("%s %d %f",stu[i].name,&stu[i].id,&stu[i].mark);
			con_info++;
			return; 
		}
	}
	printf("����ʧ�ܣ�δ�ҵ���ͬѧ��Ϣ\n");	
}

/*�ɼ������ӡ���Ӹ߳ɼ����ͳɼ�*/  
void sort_student(void)
{
	if(con_info == 0) 
	{
        printf("ѧ����ϢΪ�գ��޷�����\n");
        return;
    }
	for(int i = 1; i<con_info;i++) 
	{
		for(int j=0;j<con_info-i;j++) 
		{
			if (stu[j].mark < stu[j+1].mark) 
			{
				info student = stu[j];
				stu[j] = stu[j+1];
				stu[j+1] = student;
			}
		}
	}
	printf("ѧԱ��Ϣ��������\n");
	for(int i = 0; i < con_info; i++) 
	{
		printf("����:%-25s ѧ��:%-8d �ɼ�:%.2f\n",stu[i].name,stu[i].id,stu[i].mark);
	}	
} 

/*ɾ��ѧ����Ϣ*/
void delete_student(void)
{
	int i=0,n=0,sign=0;
	info delete_stu;
	if(con_info == 0) 
	{
        printf("ѧ����ϢΪ�գ��޷�ɾ��\n");
        return;
    }
	printf("������Ҫɾ����Ϣ��ѧ��������\n");
	scanf("%s",delete_stu.name);
	for(i=0;i<con_info;i++)
	{
		if(strcmp(delete_stu.name,stu[i].name)==0)
		{
			printf("���ҳɹ�\n");
			printf("����:%-25s ѧ��:%-8d �ɼ�:%.2f\n",stu[i].name,stu[i].id,stu[i].mark);
			printf("�Ƿ�ɾ���� 1.ȷ��    0.ȡ��  \n");
			scanf("%d",&n);
			if(n==1)
			{
				for(int j = i; j < con_info - 1; j++) 
				{
                	stu[j] = stu[j+1];
            	}
				con_info=con_info-1;  //����ʱ����Ϣ������һ 
	            sign = 1;
	            break;
			}
			else
			{
				return;
			}	 
		}
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
void revise_student(void)
{
	int i=0;
	info revise_stu;
	if(con_info == 0) 
	{
        printf("ѧ����ϢΪ�գ��޷��޸�\n");
        return;
    }
	printf("������Ҫ�޸���Ϣ��ѧ��������\n");
	scanf("%s",revise_stu.name);
	for(i=0;i<con_info;i++)
	{
		if(strcmp(revise_stu.name,stu[i].name)==0)
		{
			printf("���ҳɹ�����ӡ��Ϣ��\n");
			printf("����:%-25s ѧ��:%-8d �ɼ�:%.2f\n",stu[i].name,stu[i].id,stu[i].mark);
			printf("�������޸ĺ����Ϣ\n");
			scanf("%s %d %f",stu[i].name,&stu[i].id,&stu[i].mark);
			printf("�޸���Ϣ�ɹ�\n");
			return; 
		}
	}
	printf("����ʧ�ܣ�δ�ҵ���ͬѧ��Ϣ\n");	
}

/*��ѯѧ����Ϣ*/
void seek_student(void)
{
	int i=0;
	info seek_stu;
	printf("������Ҫ��ѯ��Ϣ��ѧ��������\n");
	scanf("%s",seek_stu.name);
	for(i=0;i<con_info;i++)
	{
		if(strcmp(seek_stu.name,stu[i].name)==0)
		{
			printf("���ҳɹ�����ӡ��Ϣ��\n");
			printf("����:%-25s ѧ��:%-8d �ɼ�:%.2f\n",stu[i].name,stu[i].id,stu[i].mark);
			return; 
		}
	}
	printf("����ʧ�ܣ�δ�ҵ���ͬѧ��Ϣ\n");	
} 

/*��ӡȫ��ѧ����Ϣ*/
void all_printf(void)
{
	int i=0;
	if(con_info == 0) 
	{
        printf("ѧ����ϢΪ��\n");
        return;
    }
	for(i=0;i<con_info;i++)
	{
		printf("����:%-25s ѧ��:%-8d �ɼ�:%.2f\n",stu[i].name,stu[i].id,stu[i].mark);
	}
} 

/*����ѧ����Ϣ*/
void add_student(void)
{
	printf("������ѧ��������ѧ�ţ��ɼ�\n");
	scanf("%s %d %f",stu[con_info].name,&stu[con_info].id,&stu[con_info].mark);
	con_info++;
}

/*�˵���ӡ���Լ�����ѡ��*/ 
void menu(void)
{
	printf("/*****��ӭʹ��ѧ����Ϣ����ϵͳ*****/\n"); 
	printf("/****       1.�����Ϣ        *****/\n"); 
	printf("/****       2.��ѯ��Ϣ        *****/\n");
	printf("/****       3.ɾ����Ϣ        *****/\n");
	printf("/****       4.�޸���Ϣ        *****/\n");
	printf("/****       5.��ӡȫ����Ϣ    *****/\n");
	printf("/****       6.�ɼ�����        *****/\n");
	printf("/****       7.����ѧ����Ϣ    *****/\n");
	printf("/****       0.�˳�            *****/\n");
	printf("������ѡ��\n");
	scanf("%d",&state);	
}
