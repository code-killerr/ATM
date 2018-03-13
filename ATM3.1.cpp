//注册ATM模拟系统
//版本号:3.1
// 转账功能优化更好的用户体验
//解决了主界面会陷入异常循环的BUG
//优化了注册完成后重新登录的用户体验
#include<stdio.h>
#include<stdlib.h>//提供密码输入
#include<conio.h>//清屏
#include<string.h>//验证
#include<Windows.h>//弹窗
#include<time.h>//提供注册时间
#define B1 中国工商银行
#define B2 中国建设银行
#define B3 中国人民银行
#define B4 中国银行
#define B5 中国农业银行
#define B6 西安银行
#define B7 兰州银行
#define B8 光大银行
struct atm
{
	int username;
	char password[6];
	float user_money;
	char user_real_name[10];
	int bank_type;
	char user_time[20];
};
struct atm user_date[100];
int i=0,j,k,d=0,c,m;
char ch,b[6];
FILE*user_real_name,*num;
void bank(int i)
{

    switch(i)
      {
      	case 1:puts("中国工商银行");break;
      	case 2:puts("中国建设银行");break;
		case 3:puts("中国人民银行");break;
		case 4:puts("中国银行");break;
		case 5:puts("中国农业银行");break;
		case 6:puts("西安银行");break;
		case 7:puts("兰州银行");break;
		case 8:puts("中国光大银行");break;
	  }
}
void file()//数据储存 读取 注册
{
	int number,f=1;
	char pass;
	if((user_real_name=fopen("user.dat","r+"))==NULL)//打开相关文件
	{
		printf("user文件打开失败，请先启动ATM后台程序进行初始化");
		exit(0);
	}
	if((num=fopen("num.dat","r+"))==NULL)
	{
		printf("num文件打开失败，请先启动ATM后台程序进行初始化");
		exit(0);
	}
	number=fgetc(num);
	m=number;
	 for(i=0;i<number;i++)
	  fread(&user_date[i],sizeof(struct atm),1,user_real_name);
	printf("是否需要注册\n注册输入1回车跳过");//判断是否为新用户，提供注册接口
	 ch=getchar();
	 if(ch=='1')
	 {
	 	i=1;
	 	printf("请选择开卡银行:\n");//确定开卡银行
		 printf("1.中国工商银行2.中国建设银行3.中国人民银行4.中国银行\n5.中国农业银行6.西安银行7.兰州银行8.中国光大银行\n");
		 while(i)
		 {
			 scanf("%d",&user_date[number].bank_type);
			 if(user_date[number].bank_type<9&&user_date[number].bank_type>0)
			 	i=0;
			 else
			    printf("代码输入有误,重新输入\n");
		}
	 	j=1;
	 	while(j)
	 	{
			 	A1:printf("用户名(只支持数字):");
			 	scanf("%d",&user_date[number].username);
			 	for(i=0;i<number;i++) //检测用户是否注册
			 	{
			 		if(user_date[number].username==user_date[i].username)
			 		{
					  printf("账户已注册\n");
			 		  goto A1;
				    }
				}
			printf("您的用户名为:%d",user_date[number].username);
			printf("无误输入Y:");//用户如果输入非数字会自动不显示，由此确认
			getchar();
			j=getchar();
			if(j=='Y'||j=='y')
			  break;
		 }
		 getchar();
		  printf("请输入姓名:");//录入姓名
		  i=0;
		  while((ch=getchar())!='\n')
		  {
		  	user_date[number].user_real_name[i++]=ch;
		  }
		 while(1)
		 {
		 	i=0;
		    printf("密码(6位):");//录入密码
			while(1)
			{
				pass=_getch();
				if(pass=='\b')
			   {
			   	 printf("\b \b");
			   	 i--;
			   }
			   else
				{
					user_date[number].password[i]=pass;
					printf("*");
					i++;
				}
				if(i>=6)
				break;
			}
			i=0;
			printf("再次输入密码:");//二次确认
			while(1)
			{
				pass=_getch();
			   if(pass=='\b')
			   {
			   	 printf("\b \b");
			   	 i--;
			   }
			   else
			   {
				   b[i]=pass;
				   printf("*");
				   i++;
			   }
			   if(i>=6)
			   break;
			}

		    if(strcmp(b,user_date[number].password))
				{
					printf("二次密码错误重新设置您的密码\n");
			    }
				else
				{
					putchar('\n');
					break;
				}
		 }
	   time_t  ticks;//提供时间
	   struct tm *t;
	   ticks = time(NULL);
	   t= localtime(&ticks);
	   strftime(user_date[number].user_time,127,"%Y-%m-%d %H:%M:%S",t);
	  user_date[number].user_money=0;
	  printf("用户信息:姓名:%s  开卡银行:",user_date[number].user_real_name);//输出全部信息
      bank(user_date[number].bank_type);
      printf("账号:%d  密码:%s  余额:%f\n",user_date[number].username,user_date[number].password,user_date[number].user_money);
      printf("开卡时间:%s.\n",user_date[number].user_time);
      fseek(user_real_name,number*sizeof(struct atm),0);
      if(fwrite(&user_date[number],sizeof(struct atm),1,user_real_name)!=1)//写入数据
	    MessageBox(NULL,"注册失败","注册",0);
	  else MessageBox(NULL,"注册成功,请关闭重新登录","注册",0);
	  number+=1;
	  rewind(num);
	  fputc(number,num);
      fclose(user_real_name);
      fclose(num);
      ShellExecute(0,"open","ATM3.1.exe",0,0,1);
	  exit(0);
	 }
	 fclose(num);
}
void sca()//判断密码
{
  printf("密码:");
  int f=1;
  while(f)
  {
	  i=0;
	  if(d==3)
		{
			printf("密码都不记还来存钱\n系统关闭,任意键退出");
			_getch();
		   exit(0);
	    }
	  while(1)
	  {
		ch=_getch();
			if(i<0)
			i=0;
			else if(ch=='\b')
		   {
		   	 printf("\b \b");
		   	 i--;
		   }
		   else
		   {
			   b[i]=ch;
			   printf("*");
			   i++;
		   }
		   if(i==6)
		   break;
	  }
				 if(strcmp(b,user_date[j].password))
				{
					printf("请输入正确密码\n");
	                d++;
			    }
				else f=0;
  }
  MessageBox(NULL,"登陆成功","登陆",0);
}
void chose()//功能选项
{
	char x;
	float z;
	int zh=-1,sc,st;
	char mid[10];
	printf("\n请输入想要进入的银行\t您开卡的银行为:");
	bank(user_date[j].bank_type);
	printf("\n");
	printf("1.中国工商银行2.中国建设银行3.中国人民银行4.中国银行\n5.中国农业银行6.西安银行7.兰州银行8.中国光大银行\n");
	while(1)
		 {
			 scanf("%d",&st);
			 if(st<9&&st>0)
			 	break;
			 else
			    printf("代码输入有误,重新输入\n");
		}
	while(1)
	{
		x=0;
		system("cls");
		printf("*********************\n");
		switch(st)
      {
      	case 1:puts("ICBC 中国工商银行");break;
      	case 2:puts("CBC 中国建设银行");break;
		case 3:puts("PBC 中国人民银行");break;
		case 4:puts("BC 中国银行");break;
		case 5:puts("ABC 中国农业银行");break;
		case 6:puts("BOX 西安银行");break;
		case 7:puts("BOL 兰州银行");break;
		case 8:puts("CEB 中国光大银行");break;
	  }
		printf("盗版ATM\n*********************\n");
		printf("登陆成功，您好%s请选择您需要的业务\n",user_date[j].user_real_name);
		printf("A.取款  B.存款  C.详细信息 D.退卡 E.更改密码 F.转账 G.销户\n");
		//getchar();//BUG出现弹窗时输入其它字符出现需要输入一个空格才能执行
		do
		{
		  scanf("%c",&x);
		}while(x=='\n');
		system("cls");
		if(x=='A'||x=='a')//取款
		{
			printf("请输入取款金额:");
			scanf("%f",&z);
			if(user_date[j].bank_type!=st)
			{
				MessageBox(NULL,"您为跨行取款，需要收取15%的手续费","提示",0);
			  	if(user_date[j].user_money-(z+z*0.15)>0)
				{
				   user_date[j].user_money-=z+z*0.15;
				   printf("\n取款成功\n");
				   printf("您还剩%.2f,收取%.2f的手续费",user_date[j].user_money,z*0.15);
				}
				else
					printf("\n取款失败,请注意您可用余额为%.2f\n",user_date[j].user_money);
			}
			else
			{
				if(user_date[j].user_money-z>0)
				{
				   user_date[j].user_money-=z;
				   printf("取款成功\n");
				   printf("您还剩%.2f",user_date[j].user_money);
				}
				else
				printf("取款失败,请注意您可用余额为%.2f\n",user_date[j].user_money);
			}
				printf("交易结束，任意键返回");
				_getch();
		}
		else if(x=='B'||x=='b')//存款
		{
			printf("请输入存款金额:");
			scanf("%f",&z);
			user_date[j].user_money+=z;
			printf("存款成功\n");
			printf("您的余额为:%.2f\n",user_date[j].user_money);
			printf("交易结束，任意键返回");
			_getch();
		}
		else if(x=='C'||x=='c')//用户信息
		{
			printf("%s您好:，您的余额为:%.2f\n",user_date[j].user_real_name,user_date[j].user_money);
			printf("开卡时间:%s.\n开卡银行:",user_date[j].user_time);
			switch(user_date[j].bank_type)
		    {
		      	case 1:puts("中国工商银行");break;
		      	case 2:puts("中国建设银行");break;
				case 3:puts("中国人民银行");break;
				case 4:puts("中国银行");break;
				case 5:puts("中国农业银行");break;
				case 6:puts("西安银行");break;
				case 7:puts("兰州银行");break;
				case 8:puts("中国光大银行");break;
			}
			printf("交易结束，任意键返回");
			_getch();
		}
		else if(x=='D'||x=='d')//退卡以及存储更改信息
		{
			A3:
			printf("请确认卡已经退出\n请保管好您的卡片\n");
			printf("确认完毕后，任意键退出");
			for(zh=0;zh<m;zh++)
			{
				fseek(user_real_name,zh*sizeof(struct atm),0);
				sc=fwrite(&user_date[zh],sizeof(struct atm),1,user_real_name);
		  	}
			if(sc==1)
	  		    MessageBox(NULL,"操作成功","金额",0);
	  		else
	            MessageBox(NULL,"操作失败","金额",0);
			fclose(user_real_name);
			_getch();
			break;
		}
		else if(x=='E'||x=='e')//修改密码
		{
			while(1)
		 {
		 	i=0;
		    printf("请输入新密码(6位):");
			while(1)
			{
				ch=_getch();
				if(i<0)
				i=0;
				else if(ch=='\b')
			   {
			   	 printf("\b \b");
			   	 i--;
			   }
			   else
				{
					user_date[j].password[i]=ch;
					printf("*");
					i++;
				}
				if(i>=6)
				break;
			}
			i=0;
			printf("再次输入密码:");
			while(1)
			{
				ch=_getch();
				if(i<0)
				i=0;
				else if(ch=='\b')
			   {
			   	 printf("\b \b");
			   	 i--;
			   }
			   else
			   {
				   b[i]=ch;
				   printf("*");
				   i++;
			   }
			   if(i>=6)
			   break;
			}

		    if(strcmp(b,user_date[j].password))
				{
					printf("二次密码错误重新设置您的密码\n");
			    }
				else
				{
					printf("修改成功，任意键返回");
					_getch();
					break;
				}
		 }

		}
		else if(x=='F'||x=='f')//转账
		{
			z=0;
			x=0;
			while(1)
			{
				zh=-1;
				printf("请输入转账账号:");
			 	scanf("%d",&sc);
			 	for(i=0;i<m;i++)
			 	{
			 		if(sc==user_date[i].username)
			 		{
					    zh=i;
				    }
				}
				if(zh==-1)printf("请输入正确账号\n");
				else
				{
					i=0;
					printf("请输入转账姓名:");
					getchar();
				    while((ch=getchar())!='\n')
				    {
				  	  mid[i++]=ch;
				    }
					if(strcmp(mid,user_date[zh].user_real_name))
						printf("姓名错误\n");
					else
					{
						printf("验证成功!\n");
						break;
					}
				}
			}
			i=0;
			x=0;
			if(user_date[zh].bank_type!=user_date[j].bank_type)
			{
				i=1;
				int a=MessageBox(NULL,"注意:检测到跨行转账，需收取5%的手续费,是否继续","警告",MB_OKCANCEL);
				if (a==IDOK)
			    {
				}
			    else
			    {
					continue;
				}
			}
			A2:x=0;
			puts("请输入转账金额:");
			scanf("%f",&z);
			if(i)
			{
		        printf("请确认转账金额:%.2f,需收取%.2f手续费\n",z,z*0.05);
		        int a=MessageBox(NULL,"请确认金额是否正确","警告",MB_OKCANCEL);
				if (a==IDOK)
			    {
				    	if(user_date[j].user_money-z>0)
					{
					   user_date[j].user_money-=z+z*0.05;
					   user_date[zh].user_money+=z;
					   printf("转账成功\n");
					   printf("您还剩%.2f",user_date[j].user_money);
					}
					else puts("对不起，您的余额不足");
				}
			    else
			    {
					goto A2;
				}
			}
			else
			{
	            int a=MessageBox(NULL,"请确认金额是否正确","警告",MB_OKCANCEL);
				if (a==IDOK)
			    {
				    	if(user_date[j].user_money-z>0)
					{
					   user_date[j].user_money-=z;
					   user_date[zh].user_money+=z;
					   printf("转账成功\n");
					   printf("您还剩%.2f",user_date[j].user_money);
					}
					else puts("对不起，您的余额不足");
				}
			    else
			    {
					goto A2;
				}
			}
			system("pause");
		}
		else if(x=='G'||x=='g')//销户 BUG最后一个用户信息销户会提示操作失败，实际上操作成功
		{
			int a=MessageBox(NULL,"请确认您要进行销户操作吗？","警告",MB_OKCANCEL);
		    if (a==IDOK)
		    {
		    	if((num=fopen("num.dat","r+"))==NULL)
				{
					printf("num文件打开失败，请检查相关文件");
					exit(0);
				}
				m=fgetc(num);
				for(i=j;i<m;i++)
				{
					user_date[i]=user_date[i+1];
				}
				rewind(num);
				m-=1;
				fputc(m,num);
				fclose(num);
				goto A3;
			}
		    else
		    {
		    	MessageBox(0,"取消操作成功","警告",0);
			}

		 }
		else//其它操作处理
		{
			printf("无效指令");
			 printf("交易结束，任意键返回");
			_getch();
		}
	}
}
main()//主体
{
	file();
    system("cls");
	printf("CIBC 中国工商银行盗版ATM\n未通过国家认证\n*********************\n");
	printf("账号只支持数字\n");

	while(1)
	{
	    printf("账号:");
		scanf("%d",&c);
		for(j=0;j<m;j++)//检验账号处理
		{
			if((int)c==user_date[j].username)
			{
				sca();
				chose();
				exit(0);
			}
		}
		printf("账号错误\n");
		       while(getchar()!='\n');
	}

}
