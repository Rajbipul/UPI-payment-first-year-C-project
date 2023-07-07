#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define black "\033[0;30m"
#define bblack "\033[0;90m"
#define red "\033[0;31m"
#define bred "\033[0;91m"
#define green "\033[0;32m"
#define bgreen "\033[0;92m"
#define yellow "\033[0;33m"
#define byellow "\033[0;93m"
#define blue "\033[0;34m"
#define bblue "\033[0;94m"
#define magenta "\033[0;35m"
#define bmagenta "\033[0;95m"
#define cyan "\033[0;36m"
#define bcyan "\033[0;96m"
#define white "\033[0;37m"
#define bwhite "\033[0;97m"
#define re "\033[0m"
// https://drive.google.com/file/d/1_7KmxMBcrdjlr7K9c7vZLIEL64sF56sJ/view?usp=drive_link

// Struct to store all data of a specific user.
typedef struct
{
    char *phone;
    char *pas;
    char *accnt;
    char *name;
    char *gend;
    char *pin;
    char *balance;
    char *t1amt;
    char *t1paysen;
    char *t1pho;
    char *t1dat;
    char *t2amt;
    char *t2paysen;
    char *t2pho;
    char *t2dat;
    char *t3amt;
    char *t3paysen;
    char *t3pho;
    char *t3dat;
} data;


void filldata(data *n, char *pho, char *pasw);
void registe();
void intoch(int n, char * a);
void cpass(data *n);
void fpass();
void transaction(data *n);
void option(data *n);
void login1();
void loading(int a);
int temp9, temp8=0;



int main()
{
    system("clear");
login:
    printf(bblack"\n\n---------- "re);
    printf("WELCOME TO ");printf(bblue"P"re);printf(red"E"re);printf(yellow"Y"re);printf(bblue" U"re);printf(green"P"re);printf(red"I"re);
    printf(bblack" -----------\n-------- "re);
    printf("PLEASE LOGIN TO CONINUE");
    printf(bblack" -------- \n\n"re);
    printf(bblue "Enter 1 to SIGNUP\nEnter 2 to LOGIN\nEnter 3 to Reset Password\nEnter 4 to Exit\n\n"re);
    printf(bblue"Input: "re);
    int a, c;
    scanf("%d", &a);
    system("clear");
    switch (a)
    {
    case 1:
        registe();
        printf(bblue"Enter 1 to go back to Login page or 0 to Exit: "re);
        int r;
        scanf("%d", &r);
        system("clear");
        if (r==1){
        goto login;}
        printf(green"Thankyou for your visit!\n"re);
        break;
    case 2:
        login1();
        goto login;
        break;
    case 3:
        fpass();
        printf(bblue"Enter 1 to go back or 0 to Exit: "re);
        scanf("%d", &c);
        if (c==1)
        {
            system("clear");
            goto login;
        }
        system("clear");
        printf(green"Thankyou for your visit!\n"re);
        break;
    case 4:
        system("clear");
        printf(green"Thankyou for your visit!\n"re);
        exit(0);
    default:
        printf(bblue"Please Enter a correct value: "re);
        scanf("%d", &a);
        goto login;
        break;
    }
}
// Function to input data of user from string to structure.
void filldata(data *n, char *pho, char *pasw)
{
    n->phone = pho;
    n->pas = pasw;
    n->accnt = strtok(NULL, ",");
    n->name = strtok(NULL, ",");
    n->gend = strtok(NULL, ",");
    n->pin = strtok(NULL, ",");
    n->balance = strtok(NULL, ",");
    n->t1amt = strtok(NULL, ",");
    n->t1paysen = strtok(NULL, ",");
    n->t1pho = strtok(NULL, ",");
    n->t1dat = strtok(NULL, ",");
    n->t2amt = strtok(NULL, ",");
    n->t2paysen = strtok(NULL, ",");
    n->t2pho = strtok(NULL, ",");
    n->t2dat = strtok(NULL, ",");
    n->t3amt = strtok(NULL, ",");
    n->t3paysen = strtok(NULL, ",");
    n->t3pho = strtok(NULL, ",");
    n->t3dat = strtok(NULL, ",");
}
// Function To login data of the user defined in csv file.open option (n) where n contains the data of the logged in user.
void login1()
{
    FILE *fp = fopen("proj.csv", "r");
    if (fp == 0)
    {
        printf(red"Can't open"re);
    }
    else
    {
        char line[10000];
        system("clear");
        printf(bblue "Enter Phone Number: " re);
        char ph[11];
    again:
        scanf("%s", ph);
        int c;
        int count = 0;
        char *sp;
        char pas[12];
        fgets(line, 10000, fp);
        while (fgets(line, 10000, fp) != NULL)
        {
            c = 0;
            data *mydata = (data *)malloc(sizeof(data));
            sp = strtok(line, ",");
            if (!strcmp(sp, ph))
            {
                c++;
                char sp1[12];
                sp = strtok(NULL, ",");
                printf(bblue"ENTER PASSWORD: " re);
            again1:
                scanf("%s", pas);
                count++;
                if (strcmp(pas, "101") == 0)
                {
                    fclose(fp);
                    fpass();
                    login1();
                }
                else if (strcmp(pas, sp) == 0)
                {
                    system("clear");
                    filldata(mydata, ph, pas);
                    fclose(fp);
                    option(mydata);
                }
                else if (count == 3)
                {
                    system("clear");
                    printf(red"You Have Made 3 incorrect attemps, Please Try again After Some Time\n"re);
                    break;
                }
                else
                {
                    system("clear");
                    printf(red"Passowrd Didnt Match. Please try Again. Enter 101 to reset password  :\n"re);
                    printf(bblue"Input: "re);
                    goto again1;
                }
                break;
            }
        }
        if (c == 0)
        {
            system("clear");
            printf(red"No record found.\n"re);
            printf(bblue"Please Enter A valid Phone Number: "re);
            rewind(fp);
            goto again;
        }
    }
}
// Function To traverse  data mentioned in csv file  of a specific user.
void option(data *n)
{
    int op, pp=0;
    if (strcmp(n->gend, "F")){
        printf(bblack"----"re);
        printf(green"Welcome Back "re);
        printf("Mr. %s", n->name);
        printf(bblack"----\n\n"re);
    }
    else{
        printf(black"----"re);
        printf(green"Welcome Back "re);
        printf("Mrs. %s", n->name);
        printf(black"----\n\n"re);
    }
again74:
    printf(bblue"Select one from them following: \n"re);
    printf("1 to check Balance\n2 to change Password\n3 to send money on any registered mobile number\n");
    printf("4 to show your last 3 Transactions\n5 to Logout \n\n");
    printf(bblue"Input: "re);
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        system("clear");
        printf(bblue"Enter UPI Pin: "re);
        char sp[4];
        int count = 0;
    again2:
        scanf("%s", sp);
        if (!strcmp(sp, n->pin))
        {
            system("clear");
            printf(yellow"Your Account Balance is: "re);printf("Rs %s/-\n\n", n->balance);
            printf(bblue"Enter 1 to Go Back or 0 to Logout: "re);
            int ch;
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                system("clear");
                option(n);
                break;

            default:
                system("clear");
                printf(green"Thankyou for your visit!\n"re);
                break;
            }
        }
        else if (count == 3)
        {
            system("clear");
            printf(red"You have made 3 incorrect attempts, Please try again after some time. "re);
        }

        else
        {
            count++;
            system("clear");
            printf(red"Incorrect UPI pin."re);
            printf(bblue"Please Try Again: "re);
            goto again2;
        }

        break;
    case 2:
        temp9=1;
        cpass(n);
        break;
    case 3:
        transaction(n);
        break;
    case 4:
        printf("\n");
        if (!strcmp(n->t1amt,"NULL"))
        {
            system("clear");
            printf(red"No Records Found\n"re);
        }
        else
        {
            system("clear");
            printf("-------------------------------------------------------------------------------------------------\n");
            printf("| TXN   |    AMOUNT    |               NAME               |    PHONE    |       DATE-TIME       |\n");
            printf("-------------------------------------------------------------------------------------------------\n");
            printf("| TXN-1 | Rs %9s | %32s | %11s | %21s |\n", n->t1amt, n->t1paysen, n->t1pho, n->t1dat);
            printf("-------------------------------------------------------------------------------------------------\n");

            if (!strcmp(n->t2amt,"NULL"))
            {
                printf(red"\nOnly 1 record Found\n"re);
            }
            else
            {

                printf("| TXN-2 | Rs %9s | %32s | %11s | %21s |\n", n->t2amt, n->t2paysen, n->t2pho, n->t2dat);
                printf("-------------------------------------------------------------------------------------------------\n");
                if (!strcmp(n->t3amt,"NULL"))
                {
                    printf(red"Only 2 record Found\n"re);
                }
                else
                {
                    char tmp[21];
                    strcpy(tmp, n->t3dat);
                    tmp[20]='\0';
                    printf("| TXN-3 | Rs %9s | %32s | %11s | %21s |\n", n->t3amt, n->t3paysen, n->t3pho, tmp);
                    printf("-------------------------------------------------------------------------------------------------\n");
                }
            }
        }
        printf(bblue"Enter 1 to go back or 0 to Logout: "re);
        scanf("%d", &pp);
        if (pp==1){
        system("clear");
        option(n);}
        else{
        system("clear");}
        break;
    case 5:
        system("clear");
        break;
    default:
        system("clear");
        printf(red"NO CASE FOUND\n\n");
        goto again74;
        break;
    }
}
// Function To Register new user in bank's database.Appends new user to proj.csv.
void registe()
{
    FILE * fp = fopen ("proj.csv", "r");
    char line[500], temp1[50], *sp;
    char ph[15], pas[24], acc[30], name[100], gen[4], pin[6];
    int c, a;
    long long int temp;
diff:
    c=0;
    system("clear");
    printf(bblue"Enter Phone Number: "re);
    scanf("%s", ph);
    while (fgets(line, 500, fp)!=NULL)
    {
        sp = strtok(line, ",");
        if (!strcmp(ph, sp))
        {c++;}
    }
    if (c)
    {
        system("clear");
        printf(red"Phone Number already exists, Login to proceed further.\nEnter 1 to register different user or 0 to go to Login page.\n"re);
        scanf("%d", &a);
        if (a==1)
        {goto diff;}
        else
        {exit(0);}
    }
    else if (strlen(ph)>10)
    {
        system("clear");
        printf(red"Input Phone Number is Invalid. Try again.\n"re);
        goto diff;
    }
    
    fclose(fp);
    int otp, iotp;
    wotp2:
    // set seed for rand() based on time
    srand(time(NULL)*369);
    otp = (rand() % (9999 - 1000 + 1)) + 1000;
    system("clear");
    printf(bblue"Enter OTP sent to "re);printf("%s\n", ph);printf("[Random OTP: %d]\n", otp);printf(bblue"Input: "re);
    scanf("%d", &iotp);
    if (otp!=iotp)
    {
        system("clear");
        printf(red"Wrong OTP, Try again.\n"re);
        goto wotp2;
    }
    system("clear");
    printf(bblue"First Name: "re);
    scanf("%s", name);
    system("clear");
    printf(bblue"Last Name: [Enter 0 if you don't have a last name.]\n"re);
    scanf("%s", temp1);
    if (strcmp(temp1, "0"))
    {
        strcat(name, " ");
        strcat(name, temp1);
    }
    system("clear");
    printf(bblue"Enter your Gender: [M/F] "re);
again8:
    scanf("%s", gen);
    if ((strcmp(gen, "M")!=0)&&(strcmp(gen, "F")!=0))
    {
        system("clear");
        printf(bblue"Enter appropriate Gender: [M/F] "re);
        goto again8;
    }
    system("clear");
again9:
    printf(bblue"Enter Password: "re);
    scanf("%s", pas);
    system("clear");
    printf(bblue"Reenter password: "re);
    scanf("%s", temp1);
    if (strcmp(temp1, pas)!=0)
    {
        system("clear");
        printf(red"Both password are not same. Try again.\n"re);
        goto again9;
    }
    FILE * gp = fopen ("proj.csv", "r");
again10:
    temp = (rand() % (99999999 - 10000000 + 1)) + 10000000;
    intoch(temp, acc);
    while (fgets(line, 500, gp)!=NULL){
        sp = strtok(line, ",");
        sp = strtok(NULL, ",");
        sp = strtok(NULL, ",");
        if (strcmp(temp1, sp)==0)
        {goto again10;}
    }
    fclose(gp);
    system("clear");
again11:
    printf(bblue"Enter UPI PIN: "re);
    scanf("%s", pin);
    system("clear");
    printf(bblue"Reenter UPI PIN: "re);
    scanf("%s", temp1);
    if (strcmp(temp1, pin))
    {
        system("clear");
        printf(red"Both UPI PIN are not same. Try again.\n"re);
        goto again11;
    }
    FILE * tp = fopen("proj.csv", "a");
    sprintf(line, "%s,%s,%s,%s,%s,%s,0,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL", ph, pas, acc, name, gen, pin);
    fputs("\n", tp);
    fputs(line, tp);
    // inputs the data of new user in csv with zero balance.
    system("clear");
    fclose(tp);
    printf(green"User "re);printf("%s", name);printf(green" registered successfully!\nYour Account No is: "re);printf("%s\n\n",acc);
}
// Function to convert input integer data type into character data type.
void intoch(int n, char * a){
    int k=10, p;
    char op[24];
    while (n>(k*10))
    k*=10;
    int i = 0;
    for (; k!=0; i++)
    {
        p=n/k;
        n=n%k;
        k/=10;
        a[i]= (char)(p+48);
    }
    a[i]='\0';
}
// Function To change password of the user. Rename proj.csv to temp.csv.makes new file proj.csv and puts modified data in it.And then deletes temp.csv
void cpass(data *n)
{
    int a =rename("proj.csv", "temp.csv");
    FILE * fp = fopen("temp.csv", "r");
    if (a==-1)
    {
        printf(red"Can't rename.\n"re);
        exit(0);
        }
    FILE * tp = fopen("proj.csv", "w");
    char pas[21], line[500], *sp, temp[21], ph[11], *rp;
    int c=0;
    strcpy(ph, n->phone);
    data* p= (data*)malloc(sizeof(data));
    data* kp= (data*)malloc(sizeof(data));
    // loop to extract data from proj.csv to string line
    while (fgets(line, 1000, fp)!=NULL)
    {
        sp = strtok(line, ",");
        if (!strcmp(sp, ph)&&(temp9))
        {
            system("clear");
            printf(bblue"Enter Your Old Password: "re);
            sp = strtok(NULL, ",");
        wpass:
            scanf("%s", temp);
            if (!strcmp(temp, "0"))
            {
                temp9=0;
                c++;
                fprintf(tp,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", n->phone, n->pas, n->accnt, n->name,n->gend, n->pin, n->balance, n->t1amt, n->t1paysen, n->t1pho, n->t1dat, n->t2amt, n->t2paysen, n->t2pho, n->t2dat, n->t3amt, n->t3paysen, n->t3pho, n->t3dat );
                if (temp8)
                fprintf(tp, "\n");
                
            }
            
            else if (!strcmp(temp, sp))
            {
                char buffer[500];
                system("clear");
                printf(bblue"Enter Your New Password: "re);
                scanf("%s", pas);
                sprintf(buffer,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", n->phone, pas, n->accnt, n->name,n->gend, n->pin, n->balance, n->t1amt, n->t1paysen, n->t1pho, n->t1dat, n->t2amt, n->t2paysen, n->t2pho, n->t2dat, n->t3amt, n->t3paysen, n->t3pho, n->t3dat );
                fputs(buffer,tp);
                // inputs the data with new password of the active user into csv.
                if (temp8)
                fprintf(tp, "\n");
                
                rp = strtok(buffer, ",");
                rp = strtok(NULL, ",");
                filldata(kp, buffer, rp);
                
                c++;
            }
            else
            {
                system("clear");
                printf(red"Input password is wrong.\n");
                printf(bblue"Try Again or Enter 0 to Go Back: "re);
                goto wpass;
            }
        }
        else
        {
            // inputs the data of the other user into csv.
            sp = strtok(NULL, ",");
            filldata(p, line, sp);
            fprintf(tp,"%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", p->phone, p->pas, p->accnt, p->name,p->gend, p->pin, p->balance, p->t1amt, p->t1paysen, p->t1pho, p->t1dat, p->t2amt, p->t2paysen, p->t2pho, p->t2dat, p->t3amt, p->t3paysen, p->t3pho, p->t3dat );
        }
    }
    fclose(tp);
    fclose(fp);
    if (c==0)
    {
        remove("proj.csv");
        rename("temp.csv", "proj.csv");
        printf(red"Phone number not found\nEnter 1 to Try Again or 0 to Exit\nInput: "re);
        int a;
        scanf("%d", &a);
        if (a==1)
        {cpass(n);}
        else
        return;
    }
    else
    {
        system("clear");
        remove("temp.csv");
        int tpo;
        if (temp9){
        printf(green"Password changed successfully!\n"re);
        printf(bblue"\nEnter 1 to Go Back to options or 0 to Exit: "re);
        scanf("%d", &tpo);
        system("clear");
        if (tpo==1)
        option(kp);}
        else
        option(n);
        return;
    }
}
// Function To reset the password of a user in case of forget password. Rename proj.csv to temp.csv.makes new file proj.csv and put s modified data in it.And then deletes temp.csv
void fpass()
{
    int a =rename("proj.csv", "temp.csv");
    FILE * fp = fopen("temp.csv", "r");
    if (a==-1)
    {
        printf(red"Can't rename.\n"re);
        exit(0);
        }
    FILE * tp = fopen("proj.csv", "w");
    char pas[21], line[500], *sp, temp[21], buffer[500], ph[11];
    int c=0;
    system("clear");
    printf(bblue"Enter your phone number: "re);
    scanf("%s", ph);
    data* p= (data*)malloc(sizeof(data));
    while (fgets(line, 1000, fp)!=NULL)
    {
        sp = strtok(line, ",");
        if (!strcmp(sp, ph))
        {
            c++;
            sp = strtok(NULL, ",");
            int otp, iotp;
            system("clear");
        wotp:
        // set seed for rand() based on time
            srand(time(NULL)*369);
            otp = (rand() % (9999 - 1000 + 1)) + 1000;
            printf(bblue"Enter OTP sent to %s\n[Random OTP: %d]\n"re, ph, otp);
            scanf("%d", &iotp);
            if (iotp==otp)
            {
                system("clear");
                printf(bblue"Now enter your new password: "re);
                scanf("%s", pas);
                filldata(p, ph, pas);
                sprintf(buffer, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", p->phone, p->pas, p->accnt, p->name,p->gend, p->pin, p->balance, p->t1amt, p->t1paysen, p->t1pho, p->t1dat, p->t2amt, p->t2paysen, p->t2pho, p->t2dat, p->t3amt, p->t3paysen, p->t3pho, p->t3dat );
                fputs(buffer, tp);
                // inputs the data with new password of the active user into csv.
            }
            else
            {
                system("clear");
                printf(red"Wrong OTP, Try again.\n"re);
                goto wotp;
            }
            
        }
        else
        {
            sp = strtok(NULL, ",");
            filldata(p, line, sp);
            sprintf(buffer, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", p->phone, p->pas, p->accnt, p->name,p->gend, p->pin, p->balance, p->t1amt, p->t1paysen, p->t1pho, p->t1dat, p->t2amt, p->t2paysen, p->t2pho, p->t2dat, p->t3amt, p->t3paysen, p->t3pho, p->t3dat );
            fputs(buffer, tp);
            // inputs the data of the other user into csv.
        }
    } 
    fclose(tp);
    fclose(fp);
    if (c==0)
    {
        int b = remove("temp.csv");
        system("clear");
        printf(red"Phone number not found.\nEnter 1 to Try Again or any other key to Exit.\nInput: "re);
        int a;
        scanf("%d", &a);
        if (a==1)
        {fpass();}
        else
        return;
    }
    else
    {
        remove("temp.csv");
        system("clear");
        printf(green "Password changes successfully!\n"re);
    }
}
// Function To transact amount in another user's account. Rename proj.csv to temp.csv.makes new file proj.csv and puts modified data in it. And then deletes temp.csv
void transaction( data *n)
{
    char rec[11];
    char line[1000], tmp1[500], *tp;
    char *seaph;
    data *reciever = (data *)malloc(sizeof(data));
    data * mp = (data*)malloc(sizeof(data));
    int flag = 0;
    system("clear");
label2:
    ;FILE*fp=fopen("proj.csv","r");
    printf(bblue"ENTER RECEIVER'S PHONE NO: "re);
    scanf("%s", rec);
    if (strcmp(rec, n->phone)==0)
    {
        system("clear");
        printf(red"You can't pay yourself. Try again.\n"re);
        fclose(fp);
        goto label2;
    }
    
    fgets(line, 1000, fp);
    while (fgets(line, 1000, fp))
    {
        seaph = strtok(line, ",");
        if (!strcmp(seaph, rec))
        {
            char *po = strtok(NULL, ",");
            filldata(reciever, seaph, po);
            flag = 1;
            break;
        }
    }
    fclose(fp);
    if (!flag)
    {
        system("clear");
        printf(red"NO USER FOUND\n\n"re);
        printf(bblue"ENTER 1 TO TRY AGAIN\nENTER 2 TO GO BACK TO MENU\nENTER 3 TO LOGOUT\n\nInput:"re);
        int choice;
        scanf("%d", &choice);
        system("clear");
        switch (choice)
        {
        case 1:
            system("clear");
            goto label2;
            break;
        case 2:
            system("clear");
            option(n);
        default:
            break;
        }
    }
    else
    {
        system("clear");
        printf(bblue"Name: "re);printf("%s\n", reciever->name);printf(bblue"Ph:   "re);printf("%s\n\n", reciever->phone);printf(bblue"ENTER AMOUNT: "re);
        int amt;
        scanf("%d", &amt);
        if (amt > atoi(n->balance))
        {
            system("clear");
            printf(red"Not Sufficient Balance\nGoing Back to Options\n\n"re);
            option(n);
        }
        else
        {
            int pi;
            int countp = 0;
            system("clear");
            printf(bblue"Enter UPI PIN: "re);
        label3:
            scanf("%d", &pi);
            if (pi != atoi(n->pin))
            {
                countp++;
                if (countp == 3)
                {
                    system("clear");
                    printf(red"3 Incorrect Attempts made, Please Try Again Later.\n"re);
                }
                else
                {
                    system("clear");
                    printf(red"INCORRECT PIN \nTRY AGAIN: "re);
                    goto label3;
                }
            }
            else
            {
                time_t no = time(NULL);
                struct tm *ctime = localtime(&no);
                char timetr[40];
                sprintf(timetr, "%02d-%02d-%04d  %02d:%02d:%02d", ctime->tm_mday, ctime->tm_mon + 1, ctime->tm_year + 1900, ctime->tm_hour, ctime->tm_min, ctime->tm_sec);
                rename("proj.csv","temp.csv");

                FILE *fp1 = fopen("proj.csv", "w");
                FILE *fp2 = fopen("temp.csv", "r");
                char line1[1000];
                int c=0;
                while (fgets(line1, 1000, fp2))
                {
                    char *pine = strtok(line1, ",");
                    if (atoi(pine) == atoi(n->phone))
                    {
                        if (c)
                        fprintf(fp1, "\n");
                        c=0;
                        sprintf(tmp1, "%s,%s,%s,%s,%s,%s,%d,%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", n->phone, n->pas, n->accnt, n->name, n->gend, n->pin, atoi(n->balance)-amt, -amt, reciever->name, reciever->phone, timetr, n->t1amt, n->t1paysen, n->t1pho, n->t1dat, n->t2amt, n->t2paysen, n->t2pho, n->t2dat);
                        fputs(tmp1,fp1);
                        // inputs the new data of the sender user in csv.
                        tp = strtok(tmp1, ",");
                        tp = strtok(NULL, ",");
                        filldata(mp, tmp1, n->pas);
                        c++;
                    }
                    else if (atoi(pine) == atoi(reciever->phone))
                    {
                        if (c)
                        fprintf(fp1, "\n");
                        // inputs the new data of receiver into csv.
                        c=0;
                        fprintf(fp1, "%s,%s,%s,%s,%s,%s,%d,%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", reciever->phone, reciever->pas, reciever->accnt, reciever->name, reciever->gend, reciever->pin, atoi(reciever->balance)+amt,amt, n->name, n->phone, timetr, reciever->t1amt, reciever->t1paysen, reciever->t1pho, reciever->t1dat, reciever->t2amt, reciever->t2paysen, reciever->t2pho, reciever->t2dat);
                        c++;
                    }
                    else
                    {
                        char phoe[100];
                        char *tok1;
                        strcpy(phoe, pine);
                        char passs[100];
                        tok1 = strtok(NULL, ",");
                        strcpy(passs, tok1);
                        data *dot = (data *)malloc(sizeof(data));
                        filldata(dot, phoe, passs);
                        if (c)
                        fprintf(fp1, "\n");
                        c=0;
                        fprintf(fp1, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", dot->phone, dot->pas, dot->accnt, dot->name, dot->gend, dot->pin, dot->balance, dot->t1amt, dot->t1paysen, dot->t1pho, dot->t1dat, dot->t2amt, dot->t2paysen, dot->t2pho, dot->t2dat, dot->t3amt, dot->t3paysen, dot->t3pho, dot->t3dat);
                        //  inputs the data of the other user into csv.
                    }
                }
                fclose(fp1);
                fclose(fp2);
                remove("temp.csv");
                char gt[20], ht[20];
                strcpy(gt, reciever->name);
                strcpy(ht, mp->name);
                gt[19]='\0';ht[19]='\0';
                system("clear");
                loading(2);
                printf("-----------------------------------------------------------------------------\n");
                printf("| <                                ");printf(bblue"P"re);printf(red"E"re);printf(yellow"Y"re);printf(bblue" U"re);printf(green"P"re);printf(red"I"re);printf("                              ... |\n");
                printf("|                                                                           |\n");
                printf("|                          ");printf(bblue"To"re);printf(" %20s                          |\n", reciever->name);
                printf("|                          -----------------------                          |\n");
                printf("|                               ");printf(bblue"Rs "re);printf("%9d/-                              |\n", amt);
                printf("|                               --------------                              |\n");
                printf("|                                  |    ");printf(green"/"re);printf(" |                                 |\n");
                printf("|                                  |   ");printf(green"/"re);printf("  |                                 |\n");
                printf("|                                  | ");printf(green"\\/"re);printf("   |                                 |\n");
                printf("|                                  --------                                 |\n");
                printf("| ");printf(bblue"FROM: "re);printf("%20s                                                |\n", ht);
                printf("| ");printf(bblue"PH: "re);printf("%10s                                                            |\n", mp->phone);
                printf("-----------------------------------------------------------------------------\n\n");
                printf("Enter 1 to Go Back or 0 to Logout: ");
                temp8=1;
                int e;
                scanf("%d", &e);
                system("clear");
                if (e==1)
                option(mp);
            }
        }
    }
}
// Function to show processing
void loading(int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("Payment Processing");
        sleep(1);
        printf(".");
        sleep(1);
        printf(".");
        sleep(1);
        printf(".");
        sleep(1);
        system("clear");
    }
}
