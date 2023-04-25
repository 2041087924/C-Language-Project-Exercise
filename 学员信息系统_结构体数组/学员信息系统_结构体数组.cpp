#include <stdio.h>
#include <string.h>

void add_student(void);     //增加学生信息 
void menu(void);            //菜单 
void all_printf(void);      //打印全部学生信息 
void seek_student(void);    //查找学生信息 
void delete_student(void);  //删除学生信息
void revise_student(void);  //修改学生信息
void insert_student();      //插入学生信息 
void sort_student(void);    //成绩排序

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
		menu();   //打印菜单以及输入选择	
		switch(state)
		{
			case 0:
				return 0;
			break;
			case 1:
				add_student();          //增加学生信息 
				printf("输入信息成功\n");
			break;
			case 2:
				seek_student();       //查找学生信息 
			break;
			case 3:
				delete_student();    //删除学生信息
			break;
			case 4:
				revise_student();    //修改学生信息
			break;
			case 5:
				all_printf();      //打印全部学生信息 
			break;
			case 6:
				sort_student();     //成绩排序
			break;
			case 7:
				insert_student();    //插入学生信息 
			break;
		}
	}
}

void insert_student()          //插入学生信息 
{
	int i=0,val=0;
	info seek_stu;
	printf("请输入要查询信息的学生姓名：\n");
	scanf("%s",seek_stu.name);
	for(i=0;i<con_info;i++)
	{
		if(strcmp(seek_stu.name,stu[i].name)==0)
		{
			printf("查找成功，打印信息：\n");
			printf("姓名:%-25s 学号:%-8d 成绩:%.2f\n",stu[i].name,stu[i].id,stu[i].mark);
			printf("0.前面插入\t1.后面插入\n");
			scanf("%d",&val);
			i=i+val;
			for(int j = con_info; j > i; j--) 
			{
            	stu[j] = stu[j-1];
        	}
			printf("请输入学生姓名，学号，成绩\n");
			scanf("%s %d %f",stu[i].name,&stu[i].id,&stu[i].mark);
			con_info++;
			return; 
		}
	}
	printf("查找失败，未找到该同学信息\n");	
}

/*成绩排序打印，从高成绩到低成绩*/  
void sort_student(void)
{
	if(con_info == 0) 
	{
        printf("学生信息为空，无法排序\n");
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
	printf("学员信息排序结果：\n");
	for(int i = 0; i < con_info; i++) 
	{
		printf("姓名:%-25s 学号:%-8d 成绩:%.2f\n",stu[i].name,stu[i].id,stu[i].mark);
	}	
} 

/*删除学生信息*/
void delete_student(void)
{
	int i=0,n=0,sign=0;
	info delete_stu;
	if(con_info == 0) 
	{
        printf("学生信息为空，无法删除\n");
        return;
    }
	printf("请输入要删除信息的学生姓名：\n");
	scanf("%s",delete_stu.name);
	for(i=0;i<con_info;i++)
	{
		if(strcmp(delete_stu.name,stu[i].name)==0)
		{
			printf("查找成功\n");
			printf("姓名:%-25s 学号:%-8d 成绩:%.2f\n",stu[i].name,stu[i].id,stu[i].mark);
			printf("是否删除： 1.确定    0.取消  \n");
			scanf("%d",&n);
			if(n==1)
			{
				for(int j = i; j < con_info - 1; j++) 
				{
                	stu[j] = stu[j+1];
            	}
				con_info=con_info-1;  //将此时的信息数量减一 
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
		printf("查找失败，未找到该同学信息\n");	
	}
	else
	{
		printf("删除成功\n");	
	}
	return;
}

/*修改学生信息*/
void revise_student(void)
{
	int i=0;
	info revise_stu;
	if(con_info == 0) 
	{
        printf("学生信息为空，无法修改\n");
        return;
    }
	printf("请输入要修改信息的学生姓名：\n");
	scanf("%s",revise_stu.name);
	for(i=0;i<con_info;i++)
	{
		if(strcmp(revise_stu.name,stu[i].name)==0)
		{
			printf("查找成功，打印信息：\n");
			printf("姓名:%-25s 学号:%-8d 成绩:%.2f\n",stu[i].name,stu[i].id,stu[i].mark);
			printf("请输入修改后的信息\n");
			scanf("%s %d %f",stu[i].name,&stu[i].id,&stu[i].mark);
			printf("修改信息成功\n");
			return; 
		}
	}
	printf("查找失败，未找到该同学信息\n");	
}

/*查询学生信息*/
void seek_student(void)
{
	int i=0;
	info seek_stu;
	printf("请输入要查询信息的学生姓名：\n");
	scanf("%s",seek_stu.name);
	for(i=0;i<con_info;i++)
	{
		if(strcmp(seek_stu.name,stu[i].name)==0)
		{
			printf("查找成功，打印信息：\n");
			printf("姓名:%-25s 学号:%-8d 成绩:%.2f\n",stu[i].name,stu[i].id,stu[i].mark);
			return; 
		}
	}
	printf("查找失败，未找到该同学信息\n");	
} 

/*打印全部学生信息*/
void all_printf(void)
{
	int i=0;
	if(con_info == 0) 
	{
        printf("学生信息为空\n");
        return;
    }
	for(i=0;i<con_info;i++)
	{
		printf("姓名:%-25s 学号:%-8d 成绩:%.2f\n",stu[i].name,stu[i].id,stu[i].mark);
	}
} 

/*输入学生信息*/
void add_student(void)
{
	printf("请输入学生姓名，学号，成绩\n");
	scanf("%s %d %f",stu[con_info].name,&stu[con_info].id,&stu[con_info].mark);
	con_info++;
}

/*菜单打印，以及输入选择*/ 
void menu(void)
{
	printf("/*****欢迎使用学生信息管理系统*****/\n"); 
	printf("/****       1.添加信息        *****/\n"); 
	printf("/****       2.查询信息        *****/\n");
	printf("/****       3.删除信息        *****/\n");
	printf("/****       4.修改信息        *****/\n");
	printf("/****       5.打印全部信息    *****/\n");
	printf("/****       6.成绩排序        *****/\n");
	printf("/****       7.插入学生信息    *****/\n");
	printf("/****       0.退出            *****/\n");
	printf("请输入选择：\n");
	scanf("%d",&state);	
}
