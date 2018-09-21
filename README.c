```c
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#define N  10
struct  StuInfo
{
    char id[20];
    char name[10];
    char dorm[20];
}stu[N];

int m,n;
void init(struct StuInfo *p);
void Input(struct StuInfo *p);
void Check(struct StuInfo *p,int n);
void Revise(struct StuInfo *p,int n);
void Add(struct StuInfo *p,int n);
void Delete(struct StuInfo *p,int n);
void Show(struct StuInfo *p,int n);
void Save(struct StuInfo *p,int n);
void menu(struct StuInfo *p,int n);
void Halfsearch(struct StuInfo *p,char *key,int low,int high,int mem,int count);
void Exit();
void Welcome();
int main()
{
    struct StuInfo *p=stu;
    while(1)
    {
        Welcome();
        init(p);
        system("pause");
        printf("请按任意键进入主菜单!\n");
        menu(p,n);
        system("pause");
    }
    return 0;
}
void init(struct StuInfo *p)
{
    p=NULL;
}
void sort(struct StuInfo *p,int n)
{
    int i,j;
    struct StuInfo temp;
    for(i=0;i<n-1;i++)
	{
		for(j=1;j<n-i;j++)
			if(strcmp((p+j-1)->id,(p+j)->id)>0)
		{temp=*(p+j-1); *(p+j-1)=*(p+j); *(p+j)=temp;}
	}
    Save(p,n);
}
void Halfsearch(struct StuInfo *p,char *key,int low,int high,int mem,int count)
{
    int mid;
    switch(mem)
    {
        case 1:
            if(low>high&&count==1)  printf("\n该学生不存在！");
            else if(low>high);
            else {
                mid = (low + high) / 2;
                if(strcmp((p+mid)->id,key)==0)
                    {
                        count++;
                        printf("%d .%6s %8s %8s \n",count,(p+mid)->id,(p+mid)->name,(p+mid)->dorm);
                    }
                if(strcmp((p+mid)->id,key)>0)
                    return Halfsearch(p,key,low,mid-1,mem,count);
                else return Halfsearch(p,key,mid+1,high,mem,count);
            }break;
        case 2:
            if(low>high&&count==1) printf("\n该学生不存在！");
            else if(low>high);
            else {
                mid=(low + high) / 2;
                if(strcmp((p+mid)->name,key)==0)
                {
                    count++;
                     printf("%d . %6s %8s %8s \n",count,(p+mid)->id,(p+mid)->name,(p+mid)->dorm);
                }
                if(strcmp((p+mid)->name,key)>0) return Halfsearch(p,key,low,mid-1,mem,count);
                else return Halfsearch(p,key,mid+1,high,mem,count);
                }
            break;
        case 3:
            if(low>high&&count==1) printf("\n该学生不存在！");
            else if(low>high);
            else {
                mid=(low + high) / 2;
                if(strcmp((p+mid)->dorm,key)==0)
                {
                    count++;
                     printf("%d . %6s %8s %8s \n",count,(p+mid)->id,(p+mid)->name,(p+mid)->dorm);
                }
                if(strcmp((p+mid)->dorm,key)>0) return Halfsearch(p,key,low,mid-1,mem,count);
                else return Halfsearch(p,key,mid+1,high,mem,count);
                }

    }

}
void Check(struct StuInfo *p,int n)
{
     int i,t,flag,low=0,count=0;
     char s1[30];
     system("COLOR 1f");
     printf("\n                =================================\n");
     printf("                |         1.按学号查询          |\n");
     printf("                |         2.按姓名查询          |\n");
     printf("                |         3.按宿舍查询          |\n");
     printf("                |         4.退出本菜单          |\n");
     printf("                =================================\n");
    while(1)
    {

         printf("\n                请输入子菜单编号: \n");
         scanf("%d",&t);
         switch(t)
         {
            case 1:
                i=0;
                printf("     请输入要查询的学生的学号: \n");
                scanf("%s",s1);
                printf("\n  学生学号    学生姓名    宿舍号 \n");
                printf("=================================\n\n\n");
                Halfsearch(p,s1,low,n-1,1,count);
                break;
            case 2:
                  printf("     请输入要查询的学生的姓名: \n");
                  scanf("%s",s1);
                  printf("\n学生学号    学生姓名    宿舍号 \n");
                  printf("=================================\n\n\n");
                  Halfsearch(p,s1,low,n-1,2,count);
                  break;
            case 3:
                printf("    请输入要查询的宿舍号: \n");
                scanf("%s",s1);
                printf("\n学生学号    学生姓名    宿舍号 \n");
                printf("=================================\n\n\n");
                Halfsearch(p,s1,low,n-1,3,count);
                break;
            case 4:
                system("pause");
                printf("请按任意键返回主菜单!\n");
                menu(p,n);
            default:
                printf("请在1--3之间选择\n");
                }
        }

}
void Input(struct StuInfo *p)
{
        int i,flag=1;
        while(flag)
        {
                flag=0;
                printf("  请输入需要创建信息的学生人数（1-1000):\n");
                scanf("%d",&n);
                if(n<1||n>1000)
                {
                        flag=1;
                        printf("\n\n  输入错误，检查后请重新输入!\n");
                }
         }
        for(i=0;i<n;i++)
        {
            printf("  请输入第%d个学生的基本信息:\n",i+1);
            printf("\n  请输入学号:\n\n");
            scanf("%s",(p+i)->id);
            printf("\n  请输入姓名:\n\n");
            scanf("%s",(p+i)->name);
            printf("\n  请输入宿舍号:\n");
            scanf("%s",(p+i)->dorm);
        }
        printf("完成!\n");
        system("pause");
    printf("\n请按任意键返回主菜单!\n");
    menu(p,n);
}

void Save(struct StuInfo *p,int n)
{
        int i;
        FILE *fp;
        if((fp=fopen("studentinfo.txt","w+"))==NULL)
       {
                printf("文件不能打开!\n");
                exit(0);
        }
        for(i=0;i<n;i++)
        {
            if(fwrite(&stu[i],sizeof(struct StuInfo),1,fp)!=1)
            printf("文件输入错误!\n");
        }
           fclose(fp);
}
void Add(struct StuInfo *p,int n)
{
    int i,j,a,flag;
    printf("  请输入增加的学生数目:\n");
    scanf("%d",&m);
    for(i=0;i<m;)
    {
        flag = 1;
        a=i+1+n;
        while(flag)
        {
            flag=0;
            printf("  请输入第%d个学生的学号:\n", a);
            scanf("%s",(p+a-1)->id);
            for(j=0;j<n;j++)
            {
                if(strcmp((p+a-1)->id,(p+j)->id)==0)
                {
                    printf("\n  该学号已经存在，请重新输入!\n");
                    flag=1;
                    break;
                }
            }

        }
        printf("\n  请输入第%d个学生的姓名:\n",a);
        scanf("%s",(p+a-1)->name);
        printf("\n  请输入第%d个学生的学生宿舍号:\n",a);
        scanf("%s",(p+a-1)->dorm);
      if(flag==0)i++;

    }
    n=n+m;
    printf("输入完毕!\n\n");
	system("pause");
    printf("\n请按任意键返回主菜单!\n");
    menu(p,n);

}
void Revise(struct StuInfo *p,int n)
{
    system("COLOR 6f");
    int i,num,count,t,l;
    char s1[30],s2[30];
    printf("                        请输入查询方式:\n");
    printf("             =============================================\n");
    printf("             |               1.学号                      |\n");
    printf("             |               2.姓名                      |\n");
    printf("             |               3.宿舍号                    |\n");
    printf("             |               4.返回菜单                  |\n");
    printf("             =============================================\n");
    while(1)
    {
     printf("  请输入子菜单的编号:\n");
     scanf("%d",&t);
     switch(t)
     {
        case 1:
            system("COLOR 6f");
            printf("\n  请输入要查询的学生的学号:\n");
            outside: scanf("%s",s1);
            count = -1;
            for(i=0;i<n;i++)
            {
                if(strcmp((p+i)->id,s1)==0)
                count=i;
            }
            if(count==-1)
            {
                printf("\n  该学号不存在,请输入代号:   1.重新输入   2.返回主菜单\n");
                scanf("%d",&l);
             switch(l)
             {
                case 1:
                             printf("  请输入新的学号:\n");
                             goto outside;
                             break;
                case 2:
                    system("pause");
                    printf("请按任意键返回主菜单!\n");
                    menu(p,n);
                    break;
            }}

            printf("\n             =============================================\n");
            printf("             |               1.修改姓名                  |\n");
            printf("             |               2.修改宿舍号                |\n");
            printf("             |               3.返回菜单                  |\n");
            printf("             =============================================\n");
            while(1)
            {
             printf("  请输入子菜单的编号:");
             scanf("%d",&num);
             switch(num)
             {
                case 1:
                             printf("  旧姓名:%s\n",(p+count)->name);
                             printf("  请输入新的姓名:\n");
                             scanf("%s",s2);
                            strcpy((p+count)->name,s2);
                            printf("\n修改完成!!\n");
                            break;
                case 2:
                            printf("  旧宿舍号:%s\n",(p+count)->dorm);
                            printf("  请输入新的宿舍号:\n");
                            scanf("%s",s2);
                            strcpy((p+count)->dorm,s2);
                            printf("\n修改完成!!\n");break;
               case 3:
                      menu(p,n);break;
               default:
                      printf("  请在1--3之间选择正确代号.\n");}break;
            }
            system("pause");
            printf("请按任意键返回主菜单!\n");
            menu(p,n);
            break;
    case 2:
            system("COLOR 6f");
            printf("  请输入要查询的学生的姓名:\n");
            outside1: scanf("%s",s1);count = -1;
            for(i=0;i<n;i++)
            {
                if(strcmp((p+i)->name,s1)==0)
                count=i;
            }
            if(count==-1)
            {
                printf("\n  该姓名不存在,请输入代号:   1.重新输入   2.返回主菜单\n");
                scanf("%d",&l);
             switch(l)
             {
                case 1:
                             printf("  请输入新的姓名:\n");
                             goto outside1;
                             break;
                case 2:
                    system("pause");
                    printf("请按任意键返回主菜单!\n");
                    menu(p,n);
                    break;
            }}
            printf("             =============================================\n");
            printf("             |               1.修改学号                  |\n");
            printf("             |               2.修改宿舍号                |\n");
            printf("             |               3.返回菜单                  |\n");
            printf("             =============================================\n");
            while(1)
            {
             printf("  请输入子菜单的编号:");
             scanf("%d",&num);
             switch(num)
             {
                case 1:
                    printf("  旧学号:%s\n",(p+count)->id);
                             printf("  请输入新的学号:\n");
                             scanf("%s",s2);
                            strcpy((p+count)->id,s2);printf("\n修改完成!!\n");break;
                case 2:
                    printf("  旧宿舍号:%s\n",(p+count)->dorm);
                            printf("  请输入新的宿舍号:\n");
                            scanf("%s",s2);
                            strcpy((p+count)->dorm,s2);printf("\n修改完成!!\n");break;
                case 3:
                    menu(p,n);break;
                default:
                      printf("请在1--3之间选择正确代号.\n");
                }break;
            }
            system("pause");
            printf("请按任意键返回主菜单!\n");
            menu(p,n);
            break;
    case 3:
        system("COLOR 6f");
        printf("\n  请输入要查询的学生的宿舍号:\n");
        outside2:  scanf("%s",s1);count = -1;
        for(i=0;i<n;i++)
        {
            if(strcmp((p+i)->dorm,s1)==0)
            {
                count=i;
                printf("             =============================================\n");
                printf("             |               1.修改学号                  |\n");
                printf("             |               2.修改姓名                  |\n");
                printf("             |               3.返回菜单                  |\n");
                printf("             =============================================\n");
                while(1)
                {
                 printf("  请输入子菜单的编号:\n");
                 scanf("%d",&num);
                 switch(num)
                 {
                    case 1:
                        printf("  旧学号:%s\n",(p+i)->id);
                                 printf("  请输入新的学号:\n");
                                 scanf("%s",s2);
                                strcpy((p+i)->id,s2);printf("\n修改完成!!\n");break;
                    case 2:
                        printf("  旧姓名:%s\n",(p+i)->name);
                                printf("  请输入新的姓名:\n");
                                scanf("%s",s2);
                                strcpy((p+i)->name,s2);printf("\n修改完成!!\n");break;
                    case 3:
                          system("cls");menu(p,n);break;
                    default:
                          printf("请在1--3之间选择正确代号.\n");
                   }break;
                }
                    if(count&&i!=n) printf("  请继续输入\n");
            }
        }
        if(count==-1)
        {
            printf("\n  该宿舍号不存在,请输入代号:   1.重新输入   2.返回主菜单\n");
            scanf("%d",&l);
            switch(l)
            {
                case 1:
                             printf("  请输入新的宿舍号:\n");
                             goto outside2;
                             break;
                case 2:
                    system("pause");
                    printf("请按任意键返回主菜单!\n");
                    menu(p,n);
                    break;
            }
        }
        system("pause");
        printf("请按任意键返回主菜单!\n");
        menu(p,n);
        break;
    case 4:
        system("pause");
        printf("请按任意键返回主菜单!\n");
        menu(p,n);
        break;
    default:
            printf("  请在1--4之间选择正确代号\n");}break;
    }


}
void menu(struct StuInfo *p,int n)
{
    int num;
    sort(p,n);
    system("cls");
    system("COLOR f2");
    printf(" ╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╧╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪╪\n");
    printf("\n\n                                  简易学生宿舍管理系统\n\n");
    printf("================================================================================\n");
    printf("\n");
    printf("                      ╔══════════════════════════════════════╗\n");
    printf("                        ============== 主菜单 ==============\n");
    printf("                      |======================================|\n");
    printf("                      |   1.输入学生信息     2.查询学生信息  |\n");
    printf("                      |--------------------------------------|\n");
    printf("                      |   3.编辑学生信息     4.添加学生信息  |\n");
    printf("                      |--------------------------------------|\n");
    printf("                      |   5.删除学生信息     6.显示当前信息  |\n");
    printf("                      |--------------------------------------|\n");
    printf("                      |--------------------------------------|\n");
    printf("                      |             7.退出系统               |\n");
    printf("                      |======================================|\n");
    printf("                      ╚══════════════════════════════════════╝\n");
    printf("  请选择菜单编号: ");
    scanf("%d",&num);
    switch(num)
    {
        case 1:system("cls");Input(p);break;
        case 2:system("cls");Check(p,n);break;
        case 3:system("cls");Revise(p,n);break;
        case 4:system("cls");Add(p,n);break;
        case 5:system("cls");Delete(p,n);break;
        case 6:system("cls");Show(p,n);break;
        case 7:system("cls");Exit();break;
        default:
        printf("请在1--7间输入正确代号\n");
    }
}
void Exit()
{

    system("cls");
    system("COLOR Af");
    printf("\n");
    printf("\n");
    printf("                     --------【简易学生宿舍管理系统】-------\n");
    printf("\n");
    printf("\n");
    printf("================================================================================\n");
    printf("\n");
    printf("\n");
    printf("          ★★★★★★★★★★★★★★     感谢使用   ★★★★★★★★★★★★★★\n");
    printf("\n");
    system("pause");
    system("cls");
    printf("\n\n\n请按任意键返回开始界面!\n");
    system("cls");
    Welcome();
}
void Welcome()
{
    system("cls");
    system("COLOR Af");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("           ★★★★★★★★★★★★★★       欢迎使用    ★★★★★★★★★★★★★★\n");
    printf("\n");
    printf("\n");
    printf("                             --------【简易学生宿舍管理系统】-------\n");
    printf("\n");

}
void Show(struct StuInfo *p,int n)
{
      int i;
      FILE *fp;
      if((fp=fopen("studentinfo.txt","r+"))==NULL)
     {
          printf("打开文件时错误!请按任意键退出!\n");
          system("pause");
          exit(0);
     }
      printf("       所有学生的信息为：\n \n");
      printf("\n学生学号     学生姓名      宿舍号      \n");
      printf("===================================\n");
      for(i=0;i<n;i++)
      {     fread(&stu[i],sizeof(struct StuInfo),1,fp);
            printf("%6s %7s %6s\n",(p+i)->id,(p+i)->name,(p+i)->dorm);
      }

    fclose(fp);Save(p,n);
    system("pause");
    system("cls");
    printf("\n\n\n请按任意键返回主菜单!\n");
    system("cls");
    menu(p,n);
}
void  Delete(struct StuInfo *p,int n)
{
    int i,j,flag=0;
    char num1[20];
    printf("  请输入删除的学生学号:\n");
    scanf("%s",num1);
    for(i=0;i<n;i++)
    {
        if(strcmp((p+i)->id,num1)==0)
        {
            flag=1;
            for(j=i;j<n-1;j++)
                *(p+j)=*(p+1+j);
        }
    }

    if(flag==0)
    printf("  该学号不存在!\n");
    if(flag==1)
    {
            printf("删除成功!\n");
            n--;
    }
    Save(p,n);
    system("pause");
    printf("\n\n\n请按任意键返回主菜单!\n");
    menu(p,n);
}
```
