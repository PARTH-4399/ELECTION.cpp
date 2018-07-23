#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<iomanip.h>
fstream f1,fc,fn,fp,fv,ft,ft1;
class password
{
 public:
 char pass[30];
}po;
class schoolinfo
{
 public:
 char schoolname[60],schooladd1[60],schooladd2[60],affno[15],mobile[12],phone[15];
 char acayear[12],email[30],website[30];
 int i,temp;
 void dispsi();
 void inputsi()
 {
  cout<<"\nENTER THE NAME OF SCHOOL:";
  gets(schoolname);
  cout<<"\nENTER SCHOOL ADDRESS(IN TWO LINES):";
  cout<<"\n\n\tLINE-1:";
  gets(schooladd1);
  cout<<"\n\tLINE-2:";
  gets(schooladd2);
  cout<<"\nENTER SCHOOL AFFILIATION NUMBER:";
  gets(affno);
  cout<<"\nENTER SCHOOL CONTACTS...";
  cout<<"\n\n\tENTER PHONE NUMBER:";
  gets(phone);
  cout<<"\n\tENTER MOBILE:";
  gets(mobile);
  cout<<"\nENTER THE ACADEMIC YEAR:";
  gets(acayear);
  cout<<"\nENTER SCHOOL E-MAIL:";
  gets(email);
  cout<<"\nENTER SCHOOL WEBSITE:";
  gets(website);
 }
};
 void schoolinfo :: dispsi()
 {
  cout<<"\n\n\n\n\n";
  temp=strlen(schoolname);
  for(i=0;i<((80-temp)/2);i++)
  cout<<" ";
  cout<<schoolname<<"\n\n";
  temp=strlen(schooladd1);
  for(i=0;i<((80-temp)/2);i++)
  cout<<" ";
  cout<<schooladd1<<"\n\n";
  temp=strlen(schooladd2);
  for(i=0;i<((80-temp)/2);i++)
  cout<<" ";
  cout<<schooladd2<<"\n\n";
  temp=strlen(affno);
  for(i=0;i<((61-temp)/2);i++)
  cout<<" ";
  cout<<"AFFILIATION NUMBER:"<<affno<<"\n\n";
  temp=strlen(phone);
  temp+=strlen(mobile);
  for(i=0;i<((55-temp)/2);i++)
  cout<<" ";
  cout<<"CONTACTS:"<<phone<<"(PHONE),"<<mobile<<"(MOBILE)"<<"\n\n";
  temp=strlen(acayear);
  for(i=0;i<((66-temp)/2);i++)
  cout<<" ";
  cout<<"ACADEMIC YEAR "<<acayear<<"\n\n";
  temp=strlen(email);
  for(i=0;i<((73-temp)/2);i++)
  cout<<" ";
  cout<<"E-MAIL:"<<email<<"\n\n";
  temp=strlen(website);
  for(i=0;i<((72-temp)/2);i++)
  cout<<" ";
  cout<<"WEBSITE:"<<website<<"\n\n";
  cout<<"          ";
  for(i=0;i<60;i++)
  cout<<"-";
  cout<<"\n\n                   ELECTION FOR STUDENTS MANAGEMENT COMMITTEE\n\n";
  cout<<"          ";
  for(i=0;i<60;i++)
  cout<<"-";
  cout<<"\n";
 }
class committee
{
 public:
 int comno;
 char comname[30];
 void disp()
 {
  cout<<comno<<"\t"<<comname<<"\n";
 }
 void input()
 {
  comno++;
  cout<<"\nENTER THE COMMITTEE'S NAME:";
  gets(comname);
 }
}co;
class nominee
{
 public:
 int count,comno,nomno,count1,vote;
 char nomname[30];
 committee co;
 nominee()
 {
 count=0;
 count1=0;
 }
 void input()
 {
  nomno++;
  cout<<"\nENTER THE NOMINEE'S NAME:";
  gets(nomname);
  cout<<"\nENTER COMMITTEE'S NUMBER:";
  cin>>comno;
  vote=0;
 }

}no,no1;
class votes
{
 public:
 int grno;
}vo;
void main()
{
 textcolor(2);
 textbackground(0);
 clrscr();
 int grno,vote,i,z,cos1,count1,cos2,j,k,count2,cos3,cos4,count=0,found=0,comno,nomno,gotov=0;
 char ch,pass[30],pass1[30];
 schoolinfo si;
 f1.open("schoolinfo.dat",ios::binary | ios::in);
 if(!f1)
 {
  f1.close();
  f1.open("schoolinfo.dat",ios::binary | ios::out);
  si.inputsi();
  f1.write((char *)&si,sizeof(schoolinfo));
  f1.close();
 }
 f1.close();
 textcolor(1);
 textbackground(7);
 clrscr();
 f1.open("schoolinfo.dat",ios::binary | ios::in);
 f1.read((char *)&si,sizeof(schoolinfo));
 si.dispsi();
 f1.close();
 getch();
 ug:
 textmode(C80);
 textcolor(14);
 clrscr();
 cout<<"          ";
 for(i=0;i<60;i++)
 cout<<"-";
 cout<<"\n                                   USER GUIDE\n";
 cout<<"          ";
 for(i=0;i<60;i++)
 cout<<"-";
 cout<<"\n\n\n\tSTEP-1:";
 cout<<"\tADD/MODIFY/DELETE/DISPLAY COMMITTEE";
 cout<<"\n\n\tSTEP-2:";
 cout<<"\tADD/MODIFY/DELETE/DISPLAY NOMINEE";
 cout<<"\n\n\tSTEP-3:";
 cout<<"\tGO FOR VOTING";
 cout<<"\n\n\tSTEP-4:";
 cout<<"\tDISPLAY RESULT";
 cout<<"\n\n\n\t\t\t\t\t\tPRESS ENTER TO PROCEED...";
 getch();
 if(gotov==2)
 goto s2;
 if(gotov==3)
 goto s3;
 if(gotov==4)
 goto s4;
 s1:
 textmode(C4350);
 textcolor(12);
 clrscr();
 cout<<"\n\n\t\t\t\t     STEP-1";
 cout<<"\n\n\n\t[1]:ADD COMMITTEE";
 cout<<"\n\n\t[2]:MODIFY COMMITTEE";
 cout<<"\n\n\t[3]:DELETE COMMITTEE";
 cout<<"\n\n\t[4]:DISPLAY COMMITTEE";
 cout<<"\n\n\t[5]:GO TO USER GUIDE";
 cout<<"\n\n\t[6]:NEXT STEP";
 cout<<"\n\n\n\tENTER YOUR CHOICE:";
 cin>>cos1;
 switch(cos1)
 {
  case 1:
  count=0;
  fc.open("committee.dat",ios::in | ios::binary);
  if(!fc)
  {
   co.comno=0;
   fc.close();
   fc.open("committee.dat",ios::out | ios::binary);
   co.input();
   fc.write((char *)&co,sizeof(committee));
   fc.close();
  }
  else
  {
   fc.close();
   fc.open("committee.dat",ios::in | ios::binary);
   while(!fc.eof())
   {
    fc.read((char *)&co,sizeof(committee));
    count++;
   }
   fc.close();
   if(count==1)
   co.comno=0;
   fc.open("committee.dat",ios::app | ios::binary);
   co.input();
   fc.write((char *)&co,sizeof(committee));
   fc.close();
  }
  break;
  case 2:
  fc.close();
  count=0;
  found=0;
  fc.open("committee.dat",ios::in | ios::binary);
  if(!fc)
  cout<<"\n\nFILE DOES NOT EXIST";
  else
  {
   while(!fc.eof())
   {
    fc.read((char *)&co,sizeof(committee));
    count++;
   }
   fc.close();
   fc.open("committee.dat",ios::in | ios::binary);
   cout<<"\n\nENTER COMMITTEE NO.";
   cin>>comno;
   fstream f2;
   f2.open("temp.dat",ios::out | ios::binary);
   for(i=1;i<count;i++)
   {
    fc.read((char *)&co,sizeof(committee));
    if(comno!=co.comno)
     f2.write((char *)&co,sizeof(committee));
    else
    {
     co.comno=comno;
     cout<<"\n\nENTER THE COMMITTEE'S NAME:";
     gets(co.comname);
     f2.write((char *)&co,sizeof(committee));
     found=1;
    }
   }
   if(found==0)
   {cout<<"\n\nRECORD DOES NOT EXIST";
   getch();}
   fc.close();
   f2.close();
   remove("committee.dat");
   rename("temp.dat","committee.dat");
  }
  break;
  case 3:
  fc.close();
  count=0;
  found=0;
  fc.open("committee.dat",ios::in | ios::binary);
  if(!fc)
  cout<<"\n\nFILE DOES NOT EXIST";
  else
  {
   while(!fc.eof())
   {
    fc.read((char *)&co,sizeof(committee));
    count++;
   }
   fc.close();
   fc.open("committee.dat",ios::in | ios::binary);
   cout<<"\n\nENTER COMMITTEE NO.";
   cin>>comno;
   fstream f2;
   f2.open("temp.dat",ios::out | ios::binary);
   for(i=1;i<count;i++)
   {
    fc.read((char *)&co,sizeof(committee));
    if(comno!=co.comno)
     f2.write((char *)&co,sizeof(committee));
    else
     found=1;
   }
   if(found==0)
   cout<<"\n\nRECORD DOES NOT EXIST";
   fc.close();
   f2.close();
   remove("committee.dat");
   rename("temp.dat","committee.dat");
  }
  break;
  case 4:
  clrscr();
  fc.close();
  count=0;
  fc.open("committee.dat",ios::in | ios::binary);
  if(!fc)
   cout<<"\n\nFILE DOES NOT EXIST";
  else
  {
   cout<<"\n\nRECORDS IN YOUR FILE...\n\n";
   while(!fc.eof())
   {
    fc.read((char *)&co,sizeof(committee));
    count++;
   }
   fc.close();
   fc.open("committee.dat",ios::in | ios::binary);
   for(i=1;i<count;i++)
   {
    fc.read((char *)&co,sizeof(committee));
    co.disp();
   }
   fc.close();
  }
  break;
  case 5:
   gotov=1;
   goto ug;
  case 6:
   goto s2;
  default:
   cout<<"\n\nWRONG CHOICE.";
 }
 getch();
 goto s1;
 s2:
 textmode(C4350);
 textcolor(12);
 clrscr();
 cout<<"\n\n\t\t\t\t     STEP-2";
 cout<<"\n\n\n\t[1]:ADD NOMINEE";
 cout<<"\n\n\t[2]:MODIFY NOMINEE";
 cout<<"\n\n\t[3]:DELETE NOMINEE";
 cout<<"\n\n\t[4]:DISPLAY NOMINEE";
 cout<<"\n\n\t[5]:PREVIOUS STEP";
 cout<<"\n\n\t[6]:NEXT STEP";
 cout<<"\n\n\t[7]:GO TO USER GUIDE";
 cout<<"\n\n\n\tENTER YOUR CHOICE:";
 cin>>cos2;
 switch(cos2)
 {
  case 1:
  count=0;
  fn.open("nominee.dat",ios::in | ios::binary);
  if(!fn)
  {
   no.nomno=0;
   fn.close();
   fn.open("nominee.dat",ios::out | ios::binary);
   no.input();
   fn.write((char *)&no,sizeof(nominee));
   fn.close();
  }
  else
  {
   fn.close();
   fn.open("nominee.dat",ios::in | ios::binary);
   while(!fn.eof())
   {
    fn.read((char *)&no,sizeof(nominee));
    count++;
   }
   fn.close();
   if(count==1)
   no.nomno=0;
   fn.open("nominee.dat",ios::app | ios::binary);
   no.input();
   fn.write((char *)&no,sizeof(nominee));
   fn.close();
  }
  break;
  case 2:
  fn.close();
  count=0;
  found=0;
  fn.open("nominee.dat",ios::in | ios::binary);
  if(!fn)
  cout<<"\n\nFILE DOES NOT EXIST";
  else
  {
   while(!fn.eof())
   {
    fn.read((char *)&no,sizeof(nominee));
    count++;
   }
   fn.close();
   fn.open("nominee.dat",ios::in | ios::binary);
   cout<<"\n\nENTER NOMINEE NO.";
   cin>>nomno;
   fstream f2;
   f2.open("temp.dat",ios::out | ios::binary);
   for(i=1;i<count;i++)
   {
    fn.read((char *)&no,sizeof(nominee));
    if(nomno!=no.nomno)
    {
     f2.write((char *)&no,sizeof(nominee));
    }
    else
    {
     no.nomno=nomno;
     cout<<"\n\nENTER THE NOMINEE'S NAME:";
     gets(no.nomname);
     cout<<"\n\nENTER THE COMMITTEE'S NO.:";
     cin>>no.comno;
     f2.write((char *)&no,sizeof(nominee));
     found=1;
    }
   }
   if(found==0)
   cout<<"\n\nRECORD DOES NOT EXIST";
   fn.close();
   f2.close();
   remove("nominee.dat");
   rename("temp.dat","nominee.dat");
  }
  break;
  case 3:
  fn.close();
  count=0;
  found=0;
  fn.open("nominee.dat",ios::in | ios::binary);
  if(!fn)
  cout<<"\n\nFILE DOES NOT EXIST";
  else
  {
   while(!fn.eof())
   {
    fn.read((char *)&no,sizeof(nominee));
    count++;
   }
   fn.close();
   fn.open("nominee.dat",ios::in | ios::binary);
   cout<<"\n\nENTER NOMINEE NO.";
   cin>>nomno;
   fstream f2;
   f2.open("temp.dat",ios::out | ios::binary);
   for(i=1;i<count;i++)
   {
    fn.read((char *)&no,sizeof(nominee));
    if(nomno!=no.nomno)
    {
     f2.write((char *)&no,sizeof(nominee));
    }
    else
    {
     found=1;
    }
   }
   if(found==0)
   cout<<"\n\nRECORD DOES NOT EXIST";
   fn.close();
   f2.close();
   remove("nominee.dat");
   rename("temp.dat","nominee.dat");
  }
  break;
  case 4:
   clrscr();
   fc.close();
   fn.close();
   count=0;
   count1=0;
   count2=0;
   fn.open("nominee.dat",ios :: in | ios :: binary);
   if(!fn)
   {
    cout<<"\n\nNO NOMINEES PRESENT";
    getch();
   }
   else
   {
   while(!fn.eof())
   {
    fn.read((char *)&no,sizeof(nominee));
    count1++;
   }
   fn.close();
   fc.open("committee.dat",ios :: in | ios :: binary);
   if(fc)
   {
   while(!fc.eof())
   {
    fc.read((char *)&co,sizeof(committee));
    count++;
   }
   fc.close();
   fc.open("committee.dat",ios :: in | ios :: binary);

   for(i=1;i<count;i++)
   {
    fn.close();
    fc.read((char *)&co,sizeof(committee));
    fn.open("nominee.dat",ios :: in | ios :: binary);
    for(j=1;j<count1;j++)
    {
     fn.read((char *)&no,sizeof(nominee));
     if(co.comno==no.comno)
     {
      count2++;
      if(count2%21==0)
      {
       cout<<"\nPress any key to continue...";
       getch();
       clrscr();
      }
      cout.setf(ios :: left);
      cout<<"\n"<<no.nomno<<"\t";
      cout<<setw(30)<<no.nomname<<"\t";
      cout<<setw(30)<<co.comname<<"\t";
     }
    }
   }
  } }
   fc.close();
   fn.close();
   break;
  case 5:
   goto s1;
  case 6:
   goto s3;
  case 7:
   gotov=2;
   goto ug;
  default:
   cout<<"\n\nWRONG CHOICE.";
 }
 getch();
 goto s2;
 s3:
 textmode(C4350);
 textcolor(12);
 clrscr();
 cout<<"\n\n\t\t\t\t     STEP-3";
 cout<<"\n\n\n\t[1]:VOTING";
 cout<<"\n\n\t[2]:PREVIOUS STEP";
 cout<<"\n\n\t[3]:NEXT STEP";
 cout<<"\n\n\t[4]:USER GUIDE";
 cout<<"\n\n\n\tENTER YOUR CHOICE:";
 cin>>cos3;
 cout<<"";
 switch(cos3)
 {
  case 1:
   fn.open("nominee.dat",ios :: in | ios :: binary);
   if(!fn)
   {
    cout<<"\nNO NOMINEES FOR VOTING\n";
    getch();
   }
   else
   {
   do
   {
   clrscr();
   count=0;
   count1=0;
   count2=0;
   fn.close();
   fc.open("committee.dat",ios :: in | ios :: binary);
   fn.open("nominee.dat",ios :: in | ios :: binary);
   while(!fc.eof())
   {
    fc.read((char *)&co,sizeof(committee));
    count++;
   }
   while(!fn.eof())
   {
    fn.read((char *)&no,sizeof(nominee));
    count1++;
   }
   fc.close();
   fn.close();
   cout<<"ENTER GR.NO.:";
   cin>>grno;
   fv.close();
   fv.open("votes.dat",ios :: in | ios :: binary);
   if(fv)
   {

    while(!fv.eof())
    {
     fv.read((char *)&vo,sizeof(votes));
     if(grno==vo.grno)
     {
      cout<<"\nYOU CANNOT VOTE AGAIN";
      goto z;
     }
    }
   }
   fv.close();
   fc.open("committee.dat",ios :: in | ios :: binary);
   for(i=1;i<count;i++)
   {
    ft.close();
    ft.open("temp.dat",ios :: out | ios :: binary);
    fn.open("nominee.dat",ios :: in | ios :: binary);
    count2=0;
    fc.read((char *)&co,sizeof(committee));
    for(j=1;j<count1;j++)
    {
     fn.read((char *)&no,sizeof(nominee));
     if(co.comno==no.comno)
     {
      ft.write((char *)&no,sizeof(nominee));
      count2++;
     }
    }
    ft.close();
    fn.close();
    if(count2==1)
    {
     fn.open("nominee.dat",ios :: in | ios :: binary);
     ft1.open("temp2.dat",ios :: app | ios :: binary);
     for(j=1;j<count1;j++)
     {
      fn.read((char *)&no,sizeof(nominee));
      if(co.comno==no.comno)
      {
       no.vote++;
       ft1.write((char *)&no,sizeof(nominee));
      }
      else
      {
       ft1.write((char *)&no,sizeof(nominee));
      }
     }
       fn.close();
       ft.close();
       ft1.close();
       remove("nominee.dat");
       rename("temp2.dat","nominee.dat");
       remove("temp.dat");
       goto y;
     }
    else if(count2>1)
    {
     cout<<"\n";
     co.disp();
     for(j=0;j<80;j++)
      cout<<"-";
     ft.open("temp.dat",ios :: in | ios :: binary);
     for(j=1;j<=count2;j++)
     {
      ft.read((char *)&no,sizeof(nominee));
      cout<<"\n"<<no.nomno<<"\t"<<no.nomname;
     }
     cout<<"\nENTER YOUR VOTE:";
     cin>>vote;
     ft.close();
     ft.open("temp.dat",ios :: in | ios :: binary);
     for(j=1;j<=count2;j++)
     {
      ft.read((char *)&no,sizeof(nominee));
      if(no.nomno==vote)
      {
       fn.close();
       fn.open("nominee.dat",ios :: in | ios :: binary);
       ft1.open("temp2.dat",ios :: app | ios :: binary);
       for(k=1;k<=count1;k++)
       {
	fn.read((char *)&no1,sizeof(nominee));
	if(no1.nomno==vote)
	{
	 no1.vote++;
	 ft1.write((char *)&no1,sizeof(nominee));
	}
	else
	{
	 ft1.write((char *)&no1,sizeof(nominee));
	}
       }
	 ft.close();
	 remove("temp.dat");
	 fn.close();
	 ft1.close();
	 remove("nominee.dat");
	 rename("temp2.dat","nominee.dat");
	 goto y;
       }
      }
     y:
     fn.close();
     ft.close();
    }
     }
    fv.open("votes.dat",ios :: in | ios :: binary);
   if(!fv)
   {
    fv.close();
    fv.open("votes.dat",ios :: out | ios :: binary);
    vo.grno=grno;
    fv.write((char *)&vo,sizeof(votes));
    fv.close();
   }
   else
   {
    fv.close();
    fv.open("votes.dat",ios :: app | ios :: binary);
    vo.grno=grno;
    fv.write((char *)&vo,sizeof(votes));
    fv.close();
   }


   fc.close();
   fn.close();
   ft.close();
   z:
   fv.close();
   cout<<"\nMORE VOTERS?[Y/N]:";
   cin>>ch;
   }while(ch=='y' || ch=='Y');
   }
   break;
  case 2:
   goto s2;
  case 3:
   goto s4;
  case 4:
   gotov=3;
   goto ug;
  default:
   cout<<"\n\nWRONG CHOICE.";
 }
getch();
 goto s3;
 s4:
 textmode(C4350);
 textcolor(12);
 clrscr();
 cout<<"\n\n\t\t\t\t     STEP-4";
 cout<<"\n\n\n\t[1]:INSERT/CHANGE PASSWORD";
 cout<<"\n\n\t[2]:RESULTS";
 cout<<"\n\n\t[3]:PREVIOUS STEP";
 cout<<"\n\n\t[4]:USER GUIDE";
 cout<<"\n\n\t[5]:FINISH";
 cout<<"\n\n\n\tENTER YOUR CHOICE:";
 cin>>cos4;
 cout<<"";
 switch(cos4)
 {
  case 1:
   z=-1;
   pass[0]='\0';
   pass1[0]='\0';
   fp.close();
   fp.open("password.dat",ios::binary | ios::in);
   if(!fp) //if password file exists
   {
    fp.close();
    cout<<"\n\nENTER PASSWORD FOR SECURITY[MAX 25 CHARACTERS]:";
    do
    {
     ch=getch();
     if(ch!=13)
     {
      if(ch==8)
      {
       if(z!=-1)
       {
       pass[z--]='\0';
       cout<<char(8)<<char(32)<<char(8);
       }
      }
      else
      {
       pass[++z]=ch;
       cout<<"*";
      }
     }
    }while(ch!=13);
    pass[++z]='\0';
    z=-1;
    cout<<"\n\nENTER PASSWORD FOR CONFORMATION:";
    do
    {
     ch=getch();
     if(ch!=13)
     {
      if(ch==8)
      {
       if(z!=-1)
       {
       pass1[z--]='\0';
       cout<<char(8)<<char(32)<<char(8);
       }
      }
      else
      {
       pass1[++z]=ch;
       cout<<"*";
      }
     }
    }while(ch!=13);
    pass1[++z]='\0';
    if(strcmp(pass,pass1)==0)
    {
     cout<<"\n\nPASSWORD CONFIRMED";
     fp.open("password.dat",ios::binary | ios::out);
     strcpy(po.pass,pass);
     fp.write((char *)&po,sizeof(password));
     fp.close();
    }
    else
    {
     cout<<"\nPASSWORDS ARE NOT MATCHED";
     getch();
    }
    fp.close();
   }
   else //if password file does not exist
   {
    fp.close();
    fp.open("password.dat",ios::binary | ios::in);
    z=-1;
    pass[0]='\0';
    pass1[0]='\0';
    cout<<"\n\nENTER PASSWORD:";

    do
    {
     ch=getch();
     if(ch!=13)
     {
      if(ch==8)
      {
       if(z!=-1)
       {
       pass1[z--]='\0';
       cout<<char(8)<<char(32)<<char(8);
       }
      }
      else
      {
       pass1[++z]=ch;
       pass1[z+1]='\0';
       cout<<"*";
      }
     }
    }while(ch!=13);
    pass1[++z]='\0';
    fp.read((char *)&po,sizeof(password));
    if(strcmp(po.pass,pass1)!=0)
    {
    cout<<"\nWRONG PASSWORD! YOU CAN NOT CHANGE PASSWORD! PLEASE TRY AGAIN\n";
    getch();
    }
    else
    {
     fp.close();
     pass[0]='\0';
     pass1[0]='\0';
     z=-1;
     cout<<"\n\nENTER PASSWORD FOR SECURITY[MAX 25 CHARACTERS]:";
     do
     {
      ch=getch();
      if(ch!=13)
      {
       if(ch==8)
       {
	if(z!=-1)
	{
	 pass[z--]='\0';
	 cout<<char(8)<<char(32)<<char(8);
	}
       }
       else
       {
	pass[++z]=ch;
	pass[z+1]='\0';
	cout<<"*";
       }
      }
     }while(ch!=13);
      pass[++z]='\0';
      z=-1;
      cout<<"\n\nENTER PASSWORD FOR CONFORMATION:";
      do
      {
       ch=getch();
       if(ch!=13)
       {
	if(ch==8)
	{
	 if(z!=-1)
	 {
	  pass1[z--]='\0';
	  cout<<char(8)<<char(32)<<char(8);
	 }
	}
       else
       {
	pass1[++z]=ch;
	pass1[z+1]='\0';
	cout<<"*";
       }
      }
     }while(ch!=13);
     pass1[++z]='\0';
     if(strcmp(pass,pass1)==0)
     {
      cout<<"\n\nPASSWORD CONFIRMED";
      ft.close();
      ft.open("temp.dat",ios::binary | ios::out);
      strcpy(po.pass,pass);
      ft.write((char *)&po,sizeof(password));
      ft.close();
      remove("password.dat");
      rename("temp.dat","password.dat");
     }
     else
     {
      cout<<"\nPASSWORDS ARE NOT MATCHED\n";
      getch();
     }
   }
  }
   break;
  case 2:
   fp.close();
   fp.open("password.dat",ios::binary | ios::in);
   if(!fp)
   {
    cout<<"\n\nPLEASE ENTER PASSWORD FIRST";
    fp.close();
   }
   else
   {
    z=-1;
    cout<<"\n\nENTER PASSWORD:";
    do
    {
     ch=getch();
     if(ch!=13)
     {
      if(ch==8)
      {
       if(z!=-1)
       {
       pass1[z--]='\0';
       cout<<char(8)<<char(32)<<char(8);
       }
      }
      else
      {
       pass1[++z]=ch;
       cout<<"*";
      }
     }
    }while(ch!=13);
    pass1[++z]='\0';
    fp.read((char *)&po,sizeof(password));
    if(strcmp(po.pass,pass1)==0)
    {
   fc.close();
   fn.close();
   fp.close();
   clrscr();
   count=0;
   count1=0;
   count2=0;
   fn.open("nominee.dat",ios :: in | ios :: binary);
   while(!fn.eof())
   {
    fn.read((char *)&no,sizeof(nominee));
    count1++;
   }
   fn.close();
   for(i=0;i<80;i++)
    cout<<"-";
   cout<<"NOM.NO\t"<<"NOMINEE\t\t\t\t"<<"COMMITTEE\t\t\t"<<"VOTES\n";
   for(i=0;i<80;i++)
    cout<<"-";
   fc.open("committee.dat",ios :: in | ios :: binary);
   if(fc)
   {
   while(!fc.eof())
   {
    fc.read((char *)&co,sizeof(committee));
    count++;
   }
   fc.close();
   fc.open("committee.dat",ios :: in | ios :: binary);

   for(i=1;i<count;i++)
   {
    fn.close();
    fc.read((char *)&co,sizeof(committee));
    fn.open("nominee.dat",ios :: in | ios :: binary);
    for(j=1;j<count1;j++)
    {
     fn.read((char *)&no,sizeof(nominee));
     if(co.comno==no.comno)
     {
      count2++;
      if(count2%21==0)
      {
       cout<<"\nPRESS ANY KEY TO CONTINUE...";
       getch();
       clrscr();
       for(k=0;k<80;k++)
	cout<<"-";
       cout<<"NOM.NO\t"<<"NOMINEE\t\t\t\t"<<"COMMITTEE\t\t"<<"VOTES\n";
       for(k=0;k<80;k++)
	cout<<"-";
      }
      cout.setf(ios :: left);
      cout<<"\n"<<no.nomno<<"\t";
      cout<<setw(30)<<no.nomname<<"\t";
      cout<<setw(30)<<co.comname<<"\t";
      cout<<no.vote;
     }
    }
   }
  }
   fc.close();
   fn.close();
   break;
    }
    else
    {
     cout<<"\n\nWRONG PASSWORD";
    }
   }
   break;
  case 3:
   goto s3;
  case 4:
   gotov=4;
   goto ug;
  case 5:
   goto f;
  default:
   cout<<"\n\nWRONG CHOICE.";
 }
 getch();
 goto s4;
 f:
 getch();
}