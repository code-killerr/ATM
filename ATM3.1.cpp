//ע��ATMģ��ϵͳ
//�汾��:3.1
// ת�˹����Ż����õ��û�����
//�����������������쳣ѭ����BUG
//�Ż���ע����ɺ����µ�¼���û�����
#include<stdio.h>
#include<stdlib.h>//�ṩ��������
#include<conio.h>//����
#include<string.h>//��֤
#include<Windows.h>//����
#include<time.h>//�ṩע��ʱ��
#define B1 �й���������
#define B2 �й���������
#define B3 �й���������
#define B4 �й�����
#define B5 �й�ũҵ����
#define B6 ��������
#define B7 ��������
#define B8 �������
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
      	case 1:puts("�й���������");break;
      	case 2:puts("�й���������");break;
		case 3:puts("�й���������");break;
		case 4:puts("�й�����");break;
		case 5:puts("�й�ũҵ����");break;
		case 6:puts("��������");break;
		case 7:puts("��������");break;
		case 8:puts("�й��������");break;
	  }
}
void file()//���ݴ��� ��ȡ ע��
{
	int number,f=1;
	char pass;
	if((user_real_name=fopen("user.dat","r+"))==NULL)//������ļ�
	{
		printf("user�ļ���ʧ�ܣ���������ATM��̨������г�ʼ��");
		exit(0);
	}
	if((num=fopen("num.dat","r+"))==NULL)
	{
		printf("num�ļ���ʧ�ܣ���������ATM��̨������г�ʼ��");
		exit(0);
	}
	number=fgetc(num);
	m=number;
	 for(i=0;i<number;i++)
	  fread(&user_date[i],sizeof(struct atm),1,user_real_name);
	printf("�Ƿ���Ҫע��\nע������1�س�����");//�ж��Ƿ�Ϊ���û����ṩע��ӿ�
	 ch=getchar();
	 if(ch=='1')
	 {
	 	i=1;
	 	printf("��ѡ�񿪿�����:\n");//ȷ����������
		 printf("1.�й���������2.�й���������3.�й���������4.�й�����\n5.�й�ũҵ����6.��������7.��������8.�й��������\n");
		 while(i)
		 {
			 scanf("%d",&user_date[number].bank_type);
			 if(user_date[number].bank_type<9&&user_date[number].bank_type>0)
			 	i=0;
			 else
			    printf("������������,��������\n");
		}
	 	j=1;
	 	while(j)
	 	{
			 	A1:printf("�û���(ֻ֧������):");
			 	scanf("%d",&user_date[number].username);
			 	for(i=0;i<number;i++) //����û��Ƿ�ע��
			 	{
			 		if(user_date[number].username==user_date[i].username)
			 		{
					  printf("�˻���ע��\n");
			 		  goto A1;
				    }
				}
			printf("�����û���Ϊ:%d",user_date[number].username);
			printf("��������Y:");//�û������������ֻ��Զ�����ʾ���ɴ�ȷ��
			getchar();
			j=getchar();
			if(j=='Y'||j=='y')
			  break;
		 }
		 getchar();
		  printf("����������:");//¼������
		  i=0;
		  while((ch=getchar())!='\n')
		  {
		  	user_date[number].user_real_name[i++]=ch;
		  }
		 while(1)
		 {
		 	i=0;
		    printf("����(6λ):");//¼������
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
			printf("�ٴ���������:");//����ȷ��
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
					printf("���������������������������\n");
			    }
				else
				{
					putchar('\n');
					break;
				}
		 }
	   time_t  ticks;//�ṩʱ��
	   struct tm *t;
	   ticks = time(NULL);
	   t= localtime(&ticks);
	   strftime(user_date[number].user_time,127,"%Y-%m-%d %H:%M:%S",t);
	  user_date[number].user_money=0;
	  printf("�û���Ϣ:����:%s  ��������:",user_date[number].user_real_name);//���ȫ����Ϣ
      bank(user_date[number].bank_type);
      printf("�˺�:%d  ����:%s  ���:%f\n",user_date[number].username,user_date[number].password,user_date[number].user_money);
      printf("����ʱ��:%s.\n",user_date[number].user_time);
      fseek(user_real_name,number*sizeof(struct atm),0);
      if(fwrite(&user_date[number],sizeof(struct atm),1,user_real_name)!=1)//д������
	    MessageBox(NULL,"ע��ʧ��","ע��",0);
	  else MessageBox(NULL,"ע��ɹ�,��ر����µ�¼","ע��",0);
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
void sca()//�ж�����
{
  printf("����:");
  int f=1;
  while(f)
  {
	  i=0;
	  if(d==3)
		{
			printf("���붼���ǻ�����Ǯ\nϵͳ�ر�,������˳�");
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
					printf("��������ȷ����\n");
	                d++;
			    }
				else f=0;
  }
  MessageBox(NULL,"��½�ɹ�","��½",0);
}
void chose()//����ѡ��
{
	char x;
	float z;
	int zh=-1,sc,st;
	char mid[10];
	printf("\n��������Ҫ���������\t������������Ϊ:");
	bank(user_date[j].bank_type);
	printf("\n");
	printf("1.�й���������2.�й���������3.�й���������4.�й�����\n5.�й�ũҵ����6.��������7.��������8.�й��������\n");
	while(1)
		 {
			 scanf("%d",&st);
			 if(st<9&&st>0)
			 	break;
			 else
			    printf("������������,��������\n");
		}
	while(1)
	{
		x=0;
		system("cls");
		printf("*********************\n");
		switch(st)
      {
      	case 1:puts("ICBC �й���������");break;
      	case 2:puts("CBC �й���������");break;
		case 3:puts("PBC �й���������");break;
		case 4:puts("BC �й�����");break;
		case 5:puts("ABC �й�ũҵ����");break;
		case 6:puts("BOX ��������");break;
		case 7:puts("BOL ��������");break;
		case 8:puts("CEB �й��������");break;
	  }
		printf("����ATM\n*********************\n");
		printf("��½�ɹ�������%s��ѡ������Ҫ��ҵ��\n",user_date[j].user_real_name);
		printf("A.ȡ��  B.���  C.��ϸ��Ϣ D.�˿� E.�������� F.ת�� G.����\n");
		//getchar();//BUG���ֵ���ʱ���������ַ�������Ҫ����һ���ո����ִ��
		do
		{
		  scanf("%c",&x);
		}while(x=='\n');
		system("cls");
		if(x=='A'||x=='a')//ȡ��
		{
			printf("������ȡ����:");
			scanf("%f",&z);
			if(user_date[j].bank_type!=st)
			{
				MessageBox(NULL,"��Ϊ����ȡ���Ҫ��ȡ15%��������","��ʾ",0);
			  	if(user_date[j].user_money-(z+z*0.15)>0)
				{
				   user_date[j].user_money-=z+z*0.15;
				   printf("\nȡ��ɹ�\n");
				   printf("����ʣ%.2f,��ȡ%.2f��������",user_date[j].user_money,z*0.15);
				}
				else
					printf("\nȡ��ʧ��,��ע�����������Ϊ%.2f\n",user_date[j].user_money);
			}
			else
			{
				if(user_date[j].user_money-z>0)
				{
				   user_date[j].user_money-=z;
				   printf("ȡ��ɹ�\n");
				   printf("����ʣ%.2f",user_date[j].user_money);
				}
				else
				printf("ȡ��ʧ��,��ע�����������Ϊ%.2f\n",user_date[j].user_money);
			}
				printf("���׽��������������");
				_getch();
		}
		else if(x=='B'||x=='b')//���
		{
			printf("����������:");
			scanf("%f",&z);
			user_date[j].user_money+=z;
			printf("���ɹ�\n");
			printf("�������Ϊ:%.2f\n",user_date[j].user_money);
			printf("���׽��������������");
			_getch();
		}
		else if(x=='C'||x=='c')//�û���Ϣ
		{
			printf("%s����:���������Ϊ:%.2f\n",user_date[j].user_real_name,user_date[j].user_money);
			printf("����ʱ��:%s.\n��������:",user_date[j].user_time);
			switch(user_date[j].bank_type)
		    {
		      	case 1:puts("�й���������");break;
		      	case 2:puts("�й���������");break;
				case 3:puts("�й���������");break;
				case 4:puts("�й�����");break;
				case 5:puts("�й�ũҵ����");break;
				case 6:puts("��������");break;
				case 7:puts("��������");break;
				case 8:puts("�й��������");break;
			}
			printf("���׽��������������");
			_getch();
		}
		else if(x=='D'||x=='d')//�˿��Լ��洢������Ϣ
		{
			A3:
			printf("��ȷ�Ͽ��Ѿ��˳�\n�뱣�ܺ����Ŀ�Ƭ\n");
			printf("ȷ����Ϻ�������˳�");
			for(zh=0;zh<m;zh++)
			{
				fseek(user_real_name,zh*sizeof(struct atm),0);
				sc=fwrite(&user_date[zh],sizeof(struct atm),1,user_real_name);
		  	}
			if(sc==1)
	  		    MessageBox(NULL,"�����ɹ�","���",0);
	  		else
	            MessageBox(NULL,"����ʧ��","���",0);
			fclose(user_real_name);
			_getch();
			break;
		}
		else if(x=='E'||x=='e')//�޸�����
		{
			while(1)
		 {
		 	i=0;
		    printf("������������(6λ):");
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
			printf("�ٴ���������:");
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
					printf("���������������������������\n");
			    }
				else
				{
					printf("�޸ĳɹ������������");
					_getch();
					break;
				}
		 }

		}
		else if(x=='F'||x=='f')//ת��
		{
			z=0;
			x=0;
			while(1)
			{
				zh=-1;
				printf("������ת���˺�:");
			 	scanf("%d",&sc);
			 	for(i=0;i<m;i++)
			 	{
			 		if(sc==user_date[i].username)
			 		{
					    zh=i;
				    }
				}
				if(zh==-1)printf("��������ȷ�˺�\n");
				else
				{
					i=0;
					printf("������ת������:");
					getchar();
				    while((ch=getchar())!='\n')
				    {
				  	  mid[i++]=ch;
				    }
					if(strcmp(mid,user_date[zh].user_real_name))
						printf("��������\n");
					else
					{
						printf("��֤�ɹ�!\n");
						break;
					}
				}
			}
			i=0;
			x=0;
			if(user_date[zh].bank_type!=user_date[j].bank_type)
			{
				i=1;
				int a=MessageBox(NULL,"ע��:��⵽����ת�ˣ�����ȡ5%��������,�Ƿ����","����",MB_OKCANCEL);
				if (a==IDOK)
			    {
				}
			    else
			    {
					continue;
				}
			}
			A2:x=0;
			puts("������ת�˽��:");
			scanf("%f",&z);
			if(i)
			{
		        printf("��ȷ��ת�˽��:%.2f,����ȡ%.2f������\n",z,z*0.05);
		        int a=MessageBox(NULL,"��ȷ�Ͻ���Ƿ���ȷ","����",MB_OKCANCEL);
				if (a==IDOK)
			    {
				    	if(user_date[j].user_money-z>0)
					{
					   user_date[j].user_money-=z+z*0.05;
					   user_date[zh].user_money+=z;
					   printf("ת�˳ɹ�\n");
					   printf("����ʣ%.2f",user_date[j].user_money);
					}
					else puts("�Բ�����������");
				}
			    else
			    {
					goto A2;
				}
			}
			else
			{
	            int a=MessageBox(NULL,"��ȷ�Ͻ���Ƿ���ȷ","����",MB_OKCANCEL);
				if (a==IDOK)
			    {
				    	if(user_date[j].user_money-z>0)
					{
					   user_date[j].user_money-=z;
					   user_date[zh].user_money+=z;
					   printf("ת�˳ɹ�\n");
					   printf("����ʣ%.2f",user_date[j].user_money);
					}
					else puts("�Բ�����������");
				}
			    else
			    {
					goto A2;
				}
			}
			system("pause");
		}
		else if(x=='G'||x=='g')//���� BUG���һ���û���Ϣ��������ʾ����ʧ�ܣ�ʵ���ϲ����ɹ�
		{
			int a=MessageBox(NULL,"��ȷ����Ҫ��������������","����",MB_OKCANCEL);
		    if (a==IDOK)
		    {
		    	if((num=fopen("num.dat","r+"))==NULL)
				{
					printf("num�ļ���ʧ�ܣ���������ļ�");
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
		    	MessageBox(0,"ȡ�������ɹ�","����",0);
			}

		 }
		else//������������
		{
			printf("��Чָ��");
			 printf("���׽��������������");
			_getch();
		}
	}
}
main()//����
{
	file();
    system("cls");
	printf("CIBC �й��������е���ATM\nδͨ��������֤\n*********************\n");
	printf("�˺�ֻ֧������\n");

	while(1)
	{
	    printf("�˺�:");
		scanf("%d",&c);
		for(j=0;j<m;j++)//�����˺Ŵ���
		{
			if((int)c==user_date[j].username)
			{
				sca();
				chose();
				exit(0);
			}
		}
		printf("�˺Ŵ���\n");
		       while(getchar()!='\n');
	}

}
