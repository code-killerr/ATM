//提供了可以清空用户数据的功能 
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<Windows.h>
struct atm
{
	int user;
	char password[6];
	float money;
	char name[10];
	int style;
	char tim[20];
};
struct atm date[100];
int i=0,j,k,d=0,c;
char ch,b[6];
main()//数据储存 读取 注册 
{
	int number,f=1;
	char pass;
	FILE*name,*num;
	if((name=fopen("user.dat","r+"))==NULL)
	{
		printf("user文件创建");
		if((fopen("user.dat","a+"))==NULL) 
			{
				printf("失败");
				_getch();
				exit(0);
			}
			else
				printf("成功");
	}
	if((num=fopen("num.dat","r+"))==NULL)
	{
		printf("创建num文件");
		if((num=fopen("num.dat","a+"))==NULL)
			printf("失败");
		else
		    {
		    	printf("成功"); 
		   		fputc(0,num);//重置用户数量
		   		fclose(num);
			}
		_getch();
		exit(0);
	}
	number=fgetc(num);	 
	printf("%d",number);
	 for(i=0;i<number;i++)
	  fread(&date[i],sizeof(struct atm),1,name);
for(i=0;i<number;i++)
{
      printf("用户信息:姓名:%s  开卡银行:",date[i].name);
      switch(date[i].style)
      {
      	case 1:puts("中国工商银行");break;
      	case 2:puts("中国建设银行");break;
		case 3:puts("中国人民银行");break;
		case 4:puts("中国银行");break;
		case 5:puts("中国农业银行");break;
		case 6:puts("西安银行");break;
		case 7:puts("兰州银行");break;
		case 8:puts("光大银行");break;
	  }
     printf("账号:%d  密码:%s  余额:%f\n",date[i].user,date[i].password,date[i].money);
     printf("开卡时间:%s",date[i].tim);
 }
 printf("输入c清空数据");
	 if(_getch()=='c')
	 {
	 	int a=MessageBox(NULL,"是否确认要清空全部数据","警告",MB_OKCANCEL);
			if (a==IDOK)
			{
				if((num=fopen("num.dat","w+"))==NULL)
						printf("num清除失败");
					else
					{
						printf("num清除成功");
						fputc(0,num);//重置用户信息 
					 } 
				if((fopen("user.dat","w+"))==NULL)
						printf("user清除失败");
					else
					{
						printf("user清除成功");
						fputc(0,num);//重置用户信息 
					 } 
			    
			}
	 }
fclose(name);
fclose(num);
}
