#include<stdio.h>
#include<string.h>
#include<stdlib.h>



//structure
typedef struct account
{
    int id;
    char name[20];
    float abal;
    char bday[10];
    char addrs[50];
    float trns;

    struct transform
    {
        char mode[25];
        char transdate[10];
        float money;
        char cmnt[20];
    }trans[100];
}acc;
//create account <account operation>
void create()
{
    acc *s;
    int num;
    puts("how many account need to create:");
    scanf("%d",&num);

    s=(acc*)calloc(num,sizeof(acc));
    //file open
    FILE *fp;
    fp=fopen("bank.txt","a");
    //data storing ...
    for(int i=0;i<num;i++)
    {
        puts("Enter Below details:");
        sleep(1);
        fflush(stdin);
        s[i].trns=0.0;
        puts("Enter ID number for Account:");
        scanf("%d",&s[i].id);
        fflush(stdin);
        puts("Enter BIRTHDAY:(dd/mm/yy)");
        scanf("%10s",s[i].bday);
        puts("Enter ADDRESS:");
        scanf("%s",s[i].addrs);
        fflush(stdin);
        puts("Enter NAME for Account:");
        scanf("%[^\n]s",s[i].name);
        //fflush(stdin);




        for(int j=0;j<1;j++)
        {
            fflush(stdin);
            puts("Enter MODE of transaction:Deposite");
            //s[i].trans[j].mode=str;
            scanf("%s",s[i].trans[j].mode);
            fflush(stdin);
            puts("Enter transaction date(dd/mm/yyyy):");
            scanf("%s",s[i].trans[j].transdate);
            puts("Enter MONEY:");
            scanf("%f",&s[i].trans[j].money);
            s[i].abal=0;
            s[i].abal +=s[i].trans[j].money;
            fflush(stdin);
            puts("Enter comment(if any):");
            scanf("%s",s[i].trans[j].cmnt);
        }
        fwrite(&s[i],sizeof(acc),1,fp);
        {
                puts("\n-----Account details-----");
                printf("\nID               :%i",s[i].id);
                printf("\nName             :%s",s[i].name);
                printf("\nAvailable Balance:%.2f",s[i].abal);
                printf("\nBirthday         :%s",s[i].bday);
                printf("\nAddress          :%s",s[i].addrs);
                printf("\nTotal Transaction:%.0f\n\n",s[i].trns+1);
            }
    }
    fclose(fp);
}

//display acoount details:<account operation>
void dispaccs()
{
   acc s1;
   FILE *fp;
   fp=fopen("bank.txt","r");

    int id;
    puts("Enter ID to Detail of ACCOUNT:");
    scanf("%i",&id);
    int flag=0;
    while(fread(&s1,sizeof(acc),1,fp))
        {
            if(s1.id==id)
            {
                puts("\n-----Account details-----");
                printf("\nID               :%i",s1.id);
                printf("\nName             :%s",s1.name);
                printf("\nAvailable Balance:%.2f",s1.abal);
                printf("\nBirthday         :%s",s1.bday);
                printf("\nAddress          :%s",s1.addrs);
                printf("\nTotal Transaction:%.0f\n\n",s1.trns+1);
            }

        }
   fclose(fp);
}

//del account<account operation>
void delacc()
{
    acc s1;
    FILE *fp,*fp1;

    fp=fopen("bank.txt","r");
    fp1=fopen("temp.txt","w");


    int id;
    puts("Enter ID to DELETE:");
    scanf("%i",&id);
    int flag=0;

     while(fread(&s1,sizeof(acc),1,fp))
     {
         if(s1.id==id)
         {
             flag=1;
             printf("account id:%d is deleted!",id);
         }
         else{
            fwrite(&s1,sizeof(acc),1,fp1);
         }
     }
     fclose(fp);
     fclose(fp1);


     if(flag==1)
     {
        fp=fopen("bank.txt","w");
        fp1=fopen("temp.txt","r");
        while(fread(&s1,sizeof(acc),1,fp1))
        {
            fwrite(&s1,sizeof(acc),1,fp);
        }
        fclose(fp);
        fclose(fp1);
     }
     else
     {
         puts("data not available!");
     }

}

//edit account<account operation>
void editacc()
{
    acc s1;
    FILE *fp,*fp1;

    fp=fopen("bank.txt","r");
    fp1=fopen("temp.txt","w");


    int id;
    puts("Enter ID to EDIT:");
    scanf("%i",&id);
    int flag=0;

     while(fread(&s1,sizeof(acc),1,fp))
     {
         if(s1.id==id)
         {
            flag=1;
            puts("Enter Below details:");
            sleep(1);
            fflush(stdin);
            //s1.trns=;
            puts("Enter ID number for Account:");
            scanf("%d",&s1.id);
            fflush(stdin);
            puts("Enter NAME number for Account:");
            scanf("%[^\n]s",s1.name);
            fflush(stdin);
            puts("Enter ADDRESS:");
            scanf("%[^\n]s",s1.addrs);
            fflush(stdin);
            puts("Enter BIRTHDAY:(dd/mm/yy)");
            scanf("%s",s1.bday);
            fwrite(&s1,sizeof(acc),1,fp1);
            //display
            {
                puts("\n-----Account details-----");
                printf("\nID               :%i",s1.id);
                printf("\nName             :%s",s1.name);
                printf("\nAvailable Balance:%.2f",s1.abal);
                printf("\nBirthday         :%s",s1.bday);
                printf("\nAddress          :%s",s1.addrs);
                printf("\nTotal Transaction:%.0f\n\n",s1.trns+1);
            }
         }
         else{
            fwrite(&s1,sizeof(acc),1,fp1);
         }
     }
     fclose(fp);
     fclose(fp1);


     if(flag==1)
     {
        fp=fopen("bank.txt","w");
        fp1=fopen("temp.txt","r");
        while(fread(&s1,sizeof(acc),1,fp1))
        {
            fwrite(&s1,sizeof(acc),1,fp);
        }
        fclose(fp);
        fclose(fp1);
     }
     else
     {
         puts("ACCOUNT details not available!");
     }

}

//transaction detail<account operation>
void trans_det()
{
    acc s1;
    FILE *fp;

    fp=fopen("bank.txt","r");



    int id;
    puts("Enter ID to Find Transaction:");
    scanf("%i",&id);
    int flag=0;

     while(fread(&s1,sizeof(acc),1,fp))
     {
         if(s1.id==id)
         {
            flag=1;
            puts("\n-----Account details-----");
            printf("\nID               :%i",s1.id);
            printf("\nName             :%s",s1.name);
            printf("\nAvailable Balance:%.2f",s1.abal);
            printf("\nBirthday         :%s",s1.bday);
            printf("\nAddress          :%s",s1.addrs);
            printf("\nTotal Transaction:%.0f\n\n",s1.trns+1);
            puts("\n----Transaction details----");
            for(int i=0;i<s1.trns+1;i++)
            {
                printf("\t\nTransaction      :%i",i+1);
                printf("\t\nMode             :%s",s1.trans[i].mode);
                printf("\t\nTranaction money :%.2f",s1.trans[i].money);
                printf("\t\nTransaction date :%s",s1.trans[i].transdate);
                printf("\t\nComments         :%s",s1.trans[i].cmnt);
                puts("\n-----------------------------");
            }

         }
     }
     if(flag==0){
            puts("\ndata not available!");
         }
     fclose(fp);
}

//account operation
void accoper()
{
    int i;
    do
    {
        puts("\n-----ACCOUNT OPERATION-----");
        puts("\n1.CREATE ACCOUNT");
        puts("2.DELETE ACCOUNT");
        puts("3.TRANSACTION DETAILS OF ACCOUNT");
        puts("4.EDIT ACCOUNT");
        puts("5.DISPLAY ACCOUNT");
        puts("0.EXIT");
        puts("\n-----^^^^^^^^^^^^^^^-----");
        puts("Choose operation need to perform:");
        scanf("%d",&i);

        switch(i)
        {
            case 1:
            {
                create();
                break;
            }
            case 2:
            {
                delacc();
                break;
            }
            case 3:
            {
                trans_det();
                break;
            }
            case 4:
            {
                editacc();
                break;
            }
            case 5:
            {
                dispaccs();
                break;
            }
        }
    }while(i!=0);
}

//1.deposite<transaction_operation>
void deposite()
{
    acc s1;
    FILE *fp,*fp1;

    fp=fopen("bank.txt","r");
    fp1=fopen("temp.txt","w");


    int id;
    puts("Enter ID to DEPOSITE:");
    scanf("%i",&id);
    int flag=0;

     while(fread(&s1,sizeof(acc),1,fp))
     {
         if(s1.id==id)
         {
            flag=1;
            puts("Enter Below details:");
            for(int j=s1.trns+1;j<s1.trns+2;j++)
            {
                fflush(stdin);
                puts("Enter MODE of transaction:Deposite");
                scanf("%s",s1.trans[j].mode);
                fflush(stdin);
                puts("Enter transaction date(dd/mm/yyyy):");
                scanf("%s",s1.trans[j].transdate);
                puts("Enter MONEY:");
                scanf("%f",&s1.trans[j].money);
                s1.abal +=s1.trans[j].money;
                fflush(stdin);
                puts("Enter comment(if any):");
                scanf("%s",s1.trans[j].cmnt);
            }
            s1.trns +=1;
            fwrite(&s1,sizeof(acc),1,fp1);
            {
                puts("\n-----Account details-----");
                printf("\nID               :%i",s1.id);
                printf("\nName             :%s",s1.name);
                printf("\nAvailable Balance:%.2f",s1.abal);
                printf("\nBirthday         :%s",s1.bday);
                printf("\nAddress          :%s",s1.addrs);
                printf("\nTotal Transaction:%.0f\n\n",s1.trns+1);
            }
         }
         else{
            fwrite(&s1,sizeof(acc),1,fp1);
         }
     }
     fclose(fp);
     fclose(fp1);


     if(flag==1)
     {
        fp=fopen("bank.txt","w");
        fp1=fopen("temp.txt","r");
        while(fread(&s1,sizeof(acc),1,fp1))
        {
            fwrite(&s1,sizeof(acc),1,fp);
        }
        fclose(fp);
        fclose(fp1);
     }
     else
     {
         puts("ACCOUNT not available!");
     }

}


//withdrawoperation<transaction_operation>
void withdraw()
{
    acc s1;
    FILE *fp,*fp1;

    fp=fopen("bank.txt","r");
    fp1=fopen("temp.txt","w");


    int id;
    puts("Enter ID to WITHDRAW:");
    scanf("%i",&id);
    int flag=0;

     while(fread(&s1,sizeof(acc),1,fp))
     {
         if(s1.id==id)
         {
            flag=1;
            puts("Enter Below details:");
            for(int j=s1.trns+1;j<s1.trns+2;j++)
            {
                fflush(stdin);
                puts("Enter MODE of transaction:<WITHDRAW>");
                scanf("%s",s1.trans[j].mode);
                fflush(stdin);
                puts("Enter transaction date(dd/mm/yyyy):");
                scanf("%s",s1.trans[j].transdate);
                puts("Enter MONEY to wthdraw:");
                scanf("%f",&s1.trans[j].money);
                if(s1.abal >= s1.trans[j].money +500)
                {
                    s1.abal -=s1.trans[j].money;
                }
                else
                {
                    puts("your are not ENTITLED to withdraw check your balance its crossing minimum balance");
                    break;
                }

                fflush(stdin);
                puts("Enter comment(if any):");
                scanf("%s",s1.trans[j].cmnt);
            }
            s1.trns +=1;
            {
                puts("\n-----Account details-----");
                printf("\nID               :%i",s1.id);
                printf("\nName             :%s",s1.name);
                printf("\nAvailable Balance:%.2f",s1.abal);
                printf("\nBirthday         :%s",s1.bday);
                printf("\nAddress          :%s",s1.addrs);
                printf("\nTotal Transaction:%.0f\n\n",s1.trns+1);
            }
            fwrite(&s1,sizeof(acc),1,fp1);
         }
         else{
            fwrite(&s1,sizeof(acc),1,fp1);
         }
     }
     fclose(fp);
     fclose(fp1);


     if(flag==1)
     {
        fp=fopen("bank.txt","w");
        fp1=fopen("temp.txt","r");
        while(fread(&s1,sizeof(acc),1,fp1))
        {
            fwrite(&s1,sizeof(acc),1,fp);
        }
        fclose(fp);
        fclose(fp1);
     }
     else
     {
         puts("ACCOUNT details not available!");
     }

}


//acc_to_acc_transfer<transaction_operation>
void acc_to_acc_transfer()
{
    //withdraw account
    acc s1;
    FILE *fp,*fp1;
    float mon;
    fp=fopen("bank.txt","r");
    fp1=fopen("temp.txt","w");


    int id;
    puts("Enter ID to WITHDRAW:");
    scanf("%i",&id);
    int flag=0;

     while(fread(&s1,sizeof(acc),1,fp))
     {
         if(s1.id==id)
         {

            puts("Enter Below details:");
            for(int j=s1.trns+1;j<s1.trns+2;j++)
            {
                fflush(stdin);
                puts("Enter MODE of transaction:<WITHDRAW>");
                scanf("%s",s1.trans[j].mode);
                fflush(stdin);
                puts("Enter transaction date(dd/mm/yyyy):");
                scanf("%s",s1.trans[j].transdate);
                puts("Enter MONEY to wthdraw:");
                scanf("%f",&mon);
                s1.trans[j].money=mon;
                if(s1.abal >= s1.trans[j].money +500)
                {
                    s1.abal -=s1.trans[j].money;
                    flag=1;
                }
                else
                {
                    puts("your are not ENTITLED to withdraw check your balance its crossing minimum balance");
                    break;
                }

                fflush(stdin);
                puts("Enter comment(if any):");
                scanf("%s",s1.trans[j].cmnt);
            }
            s1.trns +=1;
            {
                puts("\n-----Account details-----");
                printf("\nID               :%i",s1.id);
                printf("\nName             :%s",s1.name);
                printf("\nAvailable Balance:%.2f",s1.abal);
                printf("\nBirthday         :%s",s1.bday);
                printf("\nAddress          :%s",s1.addrs);
                printf("\nTotal Transaction:%.0f\n\n",s1.trns+1);
            }
            fwrite(&s1,sizeof(acc),1,fp1);
         }
         else{
            fwrite(&s1,sizeof(acc),1,fp1);
         }
     }
     fclose(fp);
     fclose(fp1);


     if(flag==1)
     {
        fp=fopen("bank.txt","w");
        fp1=fopen("temp.txt","r");
        while(fread(&s1,sizeof(acc),1,fp1))
        {
            fwrite(&s1,sizeof(acc),1,fp);
        }
        fclose(fp);
        fclose(fp1);
     }
     else
     {
         puts("ACCOUNT details not available!");
     }

    //deposite
    //acc s1;
    //FILE *fp,*fp1;

    fp=fopen("bank.txt","r");
    fp1=fopen("temp.txt","w");


    //int id;
    if(flag==1)
    {
          puts("Enter ID to DEPOSITE:");
        scanf("%i",&id);
        //int flag=0;

         while(fread(&s1,sizeof(acc),1,fp))
         {
             if(s1.id==id)
             {
                flag=1;
                puts("Enter Below details:");
                for(int j=s1.trns+1;j<s1.trns+2;j++)
                {
                    fflush(stdin);
                    puts("Enter MODE of transaction:Deposite");
                    scanf("%s",s1.trans[j].mode);
                    fflush(stdin);
                    puts("Enter transaction date(dd/mm/yyyy):");
                    scanf("%s",s1.trans[j].transdate);
                    //puts("Enter MONEY:");
                    //scanf("%f",&s1.trans[j].money);
                    s1.trans[j].money=mon;
                    s1.abal +=s1.trans[j].money;
                    fflush(stdin);
                    puts("Enter comment(if any):");
                    scanf("%s",s1.trans[j].cmnt);
                }
                s1.trns +=1;
                {
                    puts("\n-----Account details-----");
                    printf("\nID               :%i",s1.id);
                    printf("\nName             :%s",s1.name);
                    printf("\nAvailable Balance:%.2f",s1.abal);
                    printf("\nBirthday         :%s",s1.bday);
                    printf("\nAddress          :%s",s1.addrs);
                    printf("\nTotal Transaction:%.0f\n\n",s1.trns+1);
                }
                fwrite(&s1,sizeof(acc),1,fp1);
             }
             else{
                fwrite(&s1,sizeof(acc),1,fp1);
             }
         }
         fclose(fp);
         fclose(fp1);


         if(flag==1)
         {
            fp=fopen("bank.txt","w");
            fp1=fopen("temp.txt","r");
            while(fread(&s1,sizeof(acc),1,fp1))
            {
                fwrite(&s1,sizeof(acc),1,fp);
            }
            fclose(fp);
            fclose(fp1);
         }
         /*else
         {
             puts("ACCOUNT not available!");
         }*/
    }

}

//transaction_operation
void transaction_operation()
{
   int i;
    do
    {
        puts("\n-----TRANSACTION OPERATION-----");
        puts("\n1.DEPOSITE ACCOUNT");
        puts("2.WITHDRAW ACCOUNT");
        puts("3.ACCOUNT TO ACCOUNT TRANSFER");
        puts("0.EXIT");
        puts("\n-----^^^^^^^^^^^^^^^-----");
        puts("Choose Operation Need To Perform:");
        scanf("%d",&i);

        switch(i)
        {
            case 1:
            {
                deposite();
                break;
            }
            case 2:
            {
                withdraw();
                break;
            }
            case 3:
            {
                acc_to_acc_transfer();
                break;
            }

        }
    }while(i!=0);
}

//short_byBal<filter>
void short_byBal()
{
   acc *s,s1;
   FILE *fp;

   fp=fopen("bank.txt","r");
   fseek(fp,0,SEEK_END);
   int n=ftell(fp)/sizeof(acc);
   rewind(fp);

   s=(acc*)calloc(n,sizeof(acc)) ;

   for(int i=0;i<n;i++)
   {
       fread(&s[i],sizeof(acc),1,fp);
   }
   fclose(fp);

   for(int i=1;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           if(s[i].abal>s[j].abal)
           {
               s1=s[j];
               s[j]=s[i];
               s[i]=s1;
           }
       }
   }
   //print shorted
    for(int i=0;i<n;i++)
    {
        puts("\n-----Account details-----");
        printf("\nID               :%i",s[i].id);
        printf("\nName             :%s",s[i].name);
        printf("\nAvailable Balance:%.2f",s[i].abal);
        printf("\nBirthday         :%s",s[i].bday);
        printf("\nAddress          :%s",s[i].addrs);
        printf("\nTotal Transaction:%.0f\n\n",s[i].trns+1);
    }
    }

//short_byName<filter>
void short_byName()
{
    acc *s,s1;
   FILE *fp;

   fp=fopen("bank.txt","r");
   fseek(fp,0,SEEK_END);
   int n=ftell(fp)/sizeof(acc);
   rewind(fp);

   s=(acc*)calloc(n,sizeof(acc)) ;

   for(int i=0;i<n;i++)
   {
       fread(&s[i],sizeof(acc),1,fp);
   }
   fclose(fp);

   for(int i=1;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           if(s[i].name[0]>s[j].name[0])
           //if(strcmp(s[i].name,s[j].name)>0)
           //if(strcmp(s[i]name,s[j].name)>0)
           {
               //strcmp
               s1=s[j];
               s[j]=s[i];
               s[i]=s1;
           }
       }
   }
   //print shorted
    for(int i=0;i<n;i++)
    {
        puts("\n-----Account details-----");
        printf("\nID               :%i",s[i].id);
        printf("\nName             :%s",s[i].name);
        printf("\nAvailable Balance:%.2f",s[i].abal);
        printf("\nBirthday         :%s",s[i].bday);
        printf("\nAddress          :%s",s[i].addrs);
        printf("\nTotal Transaction:%.0f\n\n",s[i].trns+1);
    }
}

//short_byTransaction<filter>
void short_byTransaction()
{
    acc *s,s1;
   FILE *fp;

   fp=fopen("bank.txt","r");
   fseek(fp,0,SEEK_END);
   int n=ftell(fp)/sizeof(acc);
   rewind(fp);

   s=(acc*)calloc(n,sizeof(acc)) ;

   for(int i=0;i<n;i++)
   {
       fread(&s[i],sizeof(acc),1,fp);
   }
   fclose(fp);

   for(int i=1;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           if(s[i].trns>s[j].trns)
           {
               s1=s[j];
               s[j]=s[i];
               s[i]=s1;
           }
       }
   }
   //print shorted
    for(int i=0;i<n;i++)
    {
        puts("\n-----Account details-----");
        printf("\nID               :%i",s[i].id);
        printf("\nName             :%s",s[i].name);
        printf("\nAvailable Balance:%.2f",s[i].abal);
        printf("\nBirthday         :%s",s[i].bday);
        printf("\nAddress          :%s",s[i].addrs);
        printf("\nTotal Transaction:%.0f\n\n",s[i].trns+1);
    }
}


//filter
void shortr()
{
   int i;
    do
    {
        puts("\n-----SHORT OPERATION-----");
        puts("\n1.SHORT BY BALANCE");
        puts("2.SHORT BY NAME");
        puts("3.SHORT BY TRANSACTION");
        puts("0.EXIT");
        puts("\n-----^^^^^^^^^^^^^^^-----");
        puts("Choose operation need to perform:");
        scanf("%d",&i);

        switch(i)
        {
            case 1:
            {
                short_byBal();
                break;
            }
            case 2:
            {
                short_byName();
                break;
            }
            case 3:
            {
                short_byTransaction();
                break;
            }
            case 4:
            {
                editacc();
                break;
            }
            case 5:
            {
                dispaccs();
                break;
            }
        }
    }while(i!=0);
}

//account_data<branch_det>
void account_data()
{
    acc s1;
   FILE *fp;
   fp=fopen("bank.txt","r");


  while(fread(&s1,sizeof(acc),1,fp))
    {

         {
            //flag=1;
            puts("\n-----Account details-----");
            printf("\nID               :%i",s1.id);
            printf("\nName             :%s",s1.name);
            printf("\nAvailable Balance:%.2f",s1.abal);
            printf("\nBirthday         :%s",s1.bday);
            printf("\nAddress          :%s",s1.addrs);
            printf("\nTotal Transaction:%.0f\n\n",s1.trns+1);
            puts("\n----Transaction details----");
            for(int i=0;i<s1.trns+1;i++)
            {
                printf("\t\t\nTransaction      :%i",i+1);
                printf("\t\t\nMode             :%s",s1.trans[i].mode);
                printf("\t\t\nTranaction money :%.2f",s1.trans[i].money);
                printf("\t\t\nTransaction date :%s",s1.trans[i].transdate);
                printf("\t\t\nComments         :%s",s1.trans[i].cmnt);
                puts("\t\t\n-----------------------------");
            }

         }
    }
   fclose(fp);
}


//avail_bal<branch_det>
void avail_bal()
{
  acc s1;
   FILE *fp;
   fp=fopen("bank.txt","r");
    float total_avlbal=0;

  while(fread(&s1,sizeof(acc),1,fp))
    {

        total_avlbal +=s1.abal;

    }
    puts("\n-----AVILABLE BALANCE-----");
    printf("\nTotal AVILABLE BALANCE:%.2f\n\n",total_avlbal);
    puts("\n-----^^^^^^^^^^^^^^^-----");
   fclose(fp);
}


//total_avail_accounts<branch_det>
void total_avail_accounts()
{
    acc *s,s1;
   FILE *fp;

   fp=fopen("bank.txt","r");
   fseek(fp,0,SEEK_END);
   int n=ftell(fp)/sizeof(acc);
   puts("\n-----AVILABLE BALANCE-----");
    printf("\nTotal AVILABLE ACCOUNT:%i\n\n",n);
    puts("\n-----^^^^^^^^^^^^^^^-----");
   fclose(fp);

}

//branch_det
void branch_det()
{
    int i;
    do
    {
        puts("\n-----BRANCH DETAILS-----");
        puts("\n1.ACCOUNT DATA");
        puts("2.TOTAL AVILABLE BALANCE");
        puts("3.TOTAL AVILABLE ACCOUNT");
        puts("0.EXIT");
        puts("\n-----^^^^^^^^^^^^^^^-----");
        puts("Choose operation need to perform:");
        scanf("%d",&i);

        switch(i)
        {
            case 1:
            {
                account_data();
                break;
            }
            case 2:
            {
                avail_bal();
                break;
            }
            case 3:
            {
                total_avail_accounts();
                break;
            }
            case 4:
            {
                editacc();
                break;
            }
            case 5:
            {
                dispaccs();
                break;
            }
        }
    }while(i!=0);
}

int main()
{
    puts("------- WELCOME -------");
    int ch;//option chooser
    do
    {
        //menu starts
        puts("\n-----BANK OPERATION-----");
        puts("1.ACCOUNT OPERATION");
        puts("2.TRANSACTION OPERATION");
        puts("3.SHORT OPERATION");
        puts("4.BRANCH DETAILS");
        ///puts("5.OTHERS");
        puts("0.EXIT");//menu ends
        puts("\n-----^^^^^^^^^^^^^^^-----");
        puts("Choose operation need to perform:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            {
                accoper();
                break;
            }
        case 2:
            {
                transaction_operation();
                break;
            }
        case 3:
            {
                shortr();
                break;
            }
        case 4:
            {
                branch_det();
                break;
            }

        }


    }while(ch !=0);

    return 0;
}
