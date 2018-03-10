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
		printf("name文件打开失败，请先启动ATM主程序再打开后台");
		_getch(); 
		exit(0); 
	}
	if((num=fopen("num.dat","r+"))==NULL)
	{
		printf("num文件打开失败，请先启动ATM主程序再打开后台");
		_getch();
		exit(0); 
	}
	number=fgetc(num);
	//fputc(0,num);//重置用户数量 
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
	 _getch();  
fclose(name);
fclose(num);
}
