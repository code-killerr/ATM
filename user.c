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
main()//���ݴ��� ��ȡ ע�� 
{
	int number,f=1;
	char pass;
	FILE*name,*num;
	if((name=fopen("user.dat","r+"))==NULL)
	{
		printf("name�ļ���ʧ�ܣ���������ATM�������ٴ򿪺�̨");
		_getch(); 
		exit(0); 
	}
	if((num=fopen("num.dat","r+"))==NULL)
	{
		printf("num�ļ���ʧ�ܣ���������ATM�������ٴ򿪺�̨");
		_getch();
		exit(0); 
	}
	number=fgetc(num);
	//fputc(0,num);//�����û����� 
	printf("%d",number);
	 for(i=0;i<number;i++)
	  fread(&date[i],sizeof(struct atm),1,name);
for(i=0;i<number;i++)
{
      printf("�û���Ϣ:����:%s  ��������:",date[i].name);
      switch(date[i].style)
      {
      	case 1:puts("�й���������");break;
      	case 2:puts("�й���������");break;
		case 3:puts("�й���������");break;
		case 4:puts("�й�����");break;
		case 5:puts("�й�ũҵ����");break;
		case 6:puts("��������");break;
		case 7:puts("��������");break;
		case 8:puts("�������");break;
	  }
     printf("�˺�:%d  ����:%s  ���:%f\n",date[i].user,date[i].password,date[i].money);
     printf("����ʱ��:%s",date[i].tim);
 }
	 _getch();  
fclose(name);
fclose(num);
}
