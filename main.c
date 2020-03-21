#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
    char city [15];
    char ph_n[12];
    char email[30];
} Contact;
typedef struct
{
    char name [40];
    char id[5];
    float gpa;
    char age[3];
    Contact info;
} Student;
void add_data();
void gpa_add (Student *s,int n);
void print_all(Student *s,int n);
void stat(Student *s,int n);
void save(FILE *fptr,Student *s,int n);
void load_data(int ch);
void search_data(Student *s,int n);
void quit();
void up_g(Student *s,int n);
void del(Student *s,int n);
void normalise (Student *s ,int n);
int main()
{
    int ch,f=0;
    printf("STUDENT MANAGEMENT PROGRAM\n--------------------------");
    while(1)
        {
    printf("\n\n\n1.Add data.\n2.Query.\n3.Delete.\n4.Print.\n5.Statistics.\n6.Update score.\n7.Half load.\n8.Normalize.\n9.Quit.\n\n");
        printf("Enter no. of required operation : ");
    scanf("%d",&ch);
        while(ch<1||ch>9)
        {printf("Enter correct operation : ");
    scanf("%d",&ch);}
        switch(ch)
        {
        case 1:
            add_data();
            f=1;
            break;
        case 2:

        case 3:

        case 4:

        case 5:

        case 6:

        case 7:

        case 8:
            load_data(ch);
            f=1;
            break;
        case 9:
            quit();
            break;
        default:
            printf("Enter correct operation : ");
            scanf("%d",&ch);
            break;

        }
        printf("\t\t--------------------------");
        }
    return 0;
}
void add_data()
{
    int n,i,j,f=0,f1=0,c1;
    printf("Enter the number of students : ");
    scanf("%d",&n);
    Student s[n];
    FILE *fptr;
    fptr = fopen("stud_man.txt","a");
    if (fptr==NULL)
        exit(1);
    char c;
    printf("Enter students data :\n");
    for (i=0; i<n; i++)
    {
        printf("student no. %d : ",(i+1));
        printf("\nName : ");
        getchar();
        gets(s[i].name);
        while(1)
        {
            for(j=0; j<strlen(s[i].name); j++)
            {
                if (s[i].name[j]==' ')
                    f1=1;
                if(isdigit(s[i].name[j]))
                {
                    f=1;
                    break;
                }
            }
            if (f==1||f1==0)
            {

                printf("Enter name ( first and last names ) : ");
                gets(s[i].name);
            }
            else if(f==0&&f1==1)
                break;
            f=0;
            f1=0;
        }
        printf("ID : ");
        gets(s[i].id);
        while(1)
        {
            for(j=0; j<strlen(s[i].id); j++)
            {
                if(!isdigit(s[i].id[j]))
                {
                    f=1;
                    break;
                }
            }
            if (f==1)
            {

                printf("Enter id : ");
                gets(s[i].id);
            }
            else if(f==0)
                break;
            f=0;
        }
        printf("Grade : ");
        scanf(" %f",&s[i].gpa);
        printf("Age : ");
        getchar();
        gets(s[i].age);
        while(1)
        {
            for(j=0; j<strlen(s[i].age); j++)
            {
                if(!isdigit(s[i].age[j]))
                {
                    f=1;
                    break;
                }
            }
            if (f==1)
            {

                printf("Enter age : ");
                gets(s[i].age);
            }
            else if(f==0)
                break;
            f=0;
        }
        printf("City : ");
        gets(s[i].info.city);
        while(1)
        {
            for(j=0; j<strlen(s[i].info.city); j++)
            {
                if(isdigit(s[i].info.city[j]))
                {
                    f=1;
                    break;
                }
            }
            if (f==1)
            {

                printf("Enter city : ");
                gets(s[i].info.city);
            }
            else if(f==0)
                break;
            f=0;
        }
        printf("Phone number : ");
        gets(s[i].info.ph_n);
        while(1)
        {
            for(j=0; j<11; j++)
            {
                if(!isdigit(s[i].info.ph_n[j])||strlen(s[i].info.ph_n)!=11)
                {
                    f=1;
                    break;
                }
            }
            if (f==1)
            {

                printf("Enter phone number : ");
                gets(s[i].info.ph_n);
            }
            else if(f==0)
                break;
            f=0;
        }
        printf("Email : ");
        gets(s[i].info.email);
        while(1)
        {
            if(strstr(s[i].info.email,".com")!=NULL)
            {
            for(j=0; j<strlen(s[i].info.email); j++)
            {
                if(s[i].info.email[j]=='@')
                {
                    f=1;
                    break;
                }
            }
            }
             if (f==0)
            {

                printf("Enter email : ");
                gets(s[i].info.email);
            }
            else
                break;
            f=0;
        }
    }
    printf("Do you want to save data ? Y / N\t");
    scanf("%c",&c);
    while(c!='Y'&&c!='y'&&c!='n'&&c!='N')
    {
        printf("Enter  Y / N\t");
        getchar();
        scanf("%c",&c);
    }
    if(c=='y'||c=='Y')
    {
        save(fptr,s,n);
        printf("Changes are successfully saved. ");
    }
    fclose(fptr);
    printf("\nselect : \n1.main manu.\n2.quit. ");
    scanf("%d",&c1);
    if(c1==2)
        quit();
}
void gpa_add (Student *s,int n)
{
    int c1;
    FILE *fptr;
    char c;
    fptr = fopen("stud_man.txt","w");
    if (fptr==NULL)
        exit(1);
    int i;
    for (i=0; i<n; i++)
    {
        if (s[i].gpa<2)
            s[i].gpa+=0.2;
    }
    printf("\nDo you want to save changes ? Y / N\t ");
    getchar();
    scanf("%c",&c);
    while(c!='Y'&&c!='y'&&c!='n'&&c!='N')
    {
        printf("\nEnter  Y / N\t");
        scanf("%c",&c);
    }
    if(c=='y'||c=='Y')
    {
        save(fptr,s,n);
        printf("Changes are successfully saved. ");
    }
    fclose(fptr);
    printf("\nselect : \n1.main manu.\n2.quit. ");
    scanf("%d",&c1);
    if(c1==2)
        quit();
}

void stat(Student *s,int n)
{
    int i=0,j,c1;
    float su=0 ;
    Student temp;
    printf("\n\nstudents data : \n");
    for(j=0; j<n-1; j++)
        for(i=0; i<n-j-1; i++)
            if(s[i+1].gpa<s[i].gpa)
            {
                temp=s[i];
                s[i]=s[i+1];
                s[i+1]=temp;

            }
    printf("\n\nthe maximum GPA students (%0.2f) : \n",s[j].gpa);
    if(n<5)
        for(i=n-1; i>=0; i--)
    {
        printf("Name: %s\nID: %s\n\n",s[i].name,s[i].id);
    }
    else
    for(i=n-1; i>n-6; i--)
    {
        printf("Name: %s\nID: %s\n\n",s[i].name,s[i].id);
    }
    printf("Min grade : %0.2f",s[0].gpa);
    printf("\nMax grade : %0.2f",s[n-1].gpa);
    for(i=0; i<n; i++)
    {
        su+=s[i].gpa;
    }
    printf("\nAverage grade : %0.2f",(su/n));
    printf("\nselect : \n1.main manu.\n2.quit. ");
    scanf("%d",&c1);
    if(c1==2)
        quit();

}
void save(FILE *fptr,Student *s,int n)
{
    int i;
    for ( i = 0; i < n; ++i)
    {
        fprintf(fptr, "%s,%s,%s,%s,%s,%s,%0.2f\n", s[i].name, s[i].id,s[i].info.city,s[i].info.ph_n,s[i].info.email,s[i].age, s[i].gpa);
    }
}
void load_data(int ch)
{
    int i=0,n=0;
    char c;

    FILE *fptr;
    fptr = fopen("stud_man.txt","r");
    if (fptr==NULL)
        exit(1);
    while(!feof(fptr))
    {
        c=getc(fptr);
        if(c=='\n')
            n++;
    }
    rewind(fptr);
    Student s[n];
    for(i=0; i<n; i++)
        fscanf(fptr,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%f\n",s[i].name,s[i].id,s[i].info.city,s[i].info.ph_n,s[i].info.email,s[i].age,&s[i].gpa);
    switch(ch)
    {
    case 2:
        search_data(s,n);
        break;
    case 3:
        del(s,n);
        break;
    case 4:
        print_all(s,n);
        break;
    case 5:
        stat(s,n);
        break;
    case 6:
        up_g(s,n);
        break;
    case 7:
        gpa_add(s,n);
        break;
    case 8:
        normalise(s,n);
        break;
    }

    fclose(fptr);
}
void print_all(Student *s,int n)
{
    int i=0,j,c1;
    Student temp;
    printf("\n\nstudents data : \n\n");
    printf("ID\t|STUDENT NAME\t\t|CITY\t\t|PHONE NO.\t|EMAIL\t\t\t\t|AGE\t|GRADE\t\n\n");
    for(j=0; j<n-1; j++)
        for(i=0; i<n-j-1; i++)
            if(strcmp(s[i+1].id,s[i].id)==-1)
            {
                temp=s[i];
                s[i]=s[i+1];
                s[i+1]=temp;

            }

    for(i=0; i<n; i++)
        printf("%s\t|%s\t\t|%s\t|%s\t|%s\t\t|%s\t\t|%0.2f\n", s[i].id, s[i].name,s[i].info.city,s[i].info.ph_n,s[i].info.email,s[i].age, s[i].gpa);
    printf("\nselect : \n1.main manu.\n2.quit. ");
    scanf("%d",&c1);
    if(c1==2)
        quit();
}
void search_data(Student *s,int n)
{
    int i,f=0,c1;
    char c,sid[5];
    while(1)
    {
        printf("Enter student ID : ");
        getchar();
        gets(sid);
        for(i=0; i<n; i++)
        {
            if(strcmp(s[i].id,sid)==0)
            {
                printf("%s,%s,%s,%s,%s,%s,%0.2f\n", s[i].name, s[i].id,s[i].info.city,s[i].info.ph_n,s[i].info.email,s[i].age, s[i].gpa);
                f=1;
                break;
            }
        }
        if(f==0)
        {
            printf("ID not found, do you want to try again ? Y / N\t");
            scanf("%c",&c);
            while(c!='Y'&&c!='y'&&c!='n'&&c!='N')
            {
                printf("Enter  Y / N\t");
                getchar();
                scanf("%c",&c);
            }
            if(c=='n'||c=='N')
                break;
        }
        else
        {
            printf("Do you want to search again ? Y / N\t");
            scanf("%c",&c);
            while(c!='Y'&&c!='y'&&c!='n'&&c!='N')
            {
                printf("Enter  Y / N\t");
                scanf("%c",&c);
            }
            if(c=='n'||c=='N')
                break;
        }
    }
    printf("\nselect : \n1.main manu.\n2.quit. ");
    scanf("%d",&c1);
    if(c1==2)
        quit();
}
void quit()
{
    exit(1);
}
void up_g(Student *s,int n)
{
    int i,f=0,c1;
    char c,sid[4];
    while(1)
    {
        printf("Enter student ID : ");
       getchar();
        gets(sid);
        for(i=0; i<n; i++)
        {
            if(strcmp(s[i].id,sid)==0)
            {
                printf("%s,%s,%s,%s,%s,%s,%0.2f\n", s[i].name, s[i].id,s[i].info.city,s[i].info.ph_n,s[i].info.email,s[i].age, s[i].gpa);
                f=1;
                break;
            }
        }
        if(f==0)
        {
            printf("ID not found, do you want to try again ? Y / N\t");
            getchar();
            scanf("%c",&c);
            while(c!='Y'&&c!='y'&&c!='n'&&c!='N')
            {
                printf("\nEnter  Y / N\t");
                scanf("%c",&c);
            }
            if(c=='n'||c=='N')
                break;
        }
        else
        {
            printf("Enter new grade : ");
            scanf("%f",&s[i].gpa);
            printf("Do you want to change another grade ? Y / N\t");
            getchar();
            scanf("%c",&c);
            while(c!='Y'&&c!='y'&&c!='n'&&c!='N')
            {
                printf("\nEnter  Y / N\t");
                scanf("%c",&c);
            }
            if(c=='n'||c=='N')
                break;
        }
    }
    FILE *fptr;
    fptr = fopen("stud_man.txt","w");
    if (fptr==NULL)
        exit(1);
    printf("\nDo you want to save changes ? Y / N ");
    getchar();
    scanf("%c",&c);
    while(c!='Y'&&c!='y'&&c!='n'&&c!='N')
    {
        printf("\nEnter  Y / N\t");
        scanf("%c",&c);
    }
    if(c=='y'||c=='Y')
    {
        save(fptr,s,n);
        printf("Changes are successfully saved. ");
    }
    fclose(fptr);
    printf("\nselect : \n1.main manu.\n2.quit. ");
    scanf("%d",&c1);
    if(c1==2)
        quit();
}
void del(Student *s,int n)
{
    int i,f=0,c1;
    char c,sid[4];

    while(1)
    {
        printf("Enter student ID : ");
        getchar();
        gets(sid);
        for(i=0; i<n; i++)
        {
            if(strcmp(s[i].id,sid)==0)
            {
                printf("%s,%s,%s,%s,%s,%s,%0.2f\n", s[i].name, s[i].id,s[i].info.city,s[i].info.ph_n,s[i].info.email,s[i].age, s[i].gpa);
                f=1;
                break;
            }
        }
        if(f==0)
        {
            printf("ID not found, do you want to try again ? Y / N\t");
            getchar();
            scanf("%c",&c);
            while(c!='Y'&&c!='y'&&c!='n'&&c!='N')
            {
                printf("\nEnter  Y / N\t");
                scanf("%c",&c);
            }
            if(c=='n'||c=='N')
                break;
        }
        else
        {
            printf("Are you sure you want to delete ? Y / N\t ");
            scanf("%c",&c);
            while(c!='Y'&&c!='y'&&c!='n'&&c!='N')
            {
                printf("\nEnter  Y / N\t");
                scanf("%c",&c);
            }
            if(c=='y'||c=='Y')
            {
                for(; i<n; i++)
                {
                    s[i]=s[i+1];
                }
                n-=1;
            }
            printf("Do you want to delete another student ? Y / N\t");
            getchar();
            scanf("%c",&c);
            while(c!='Y'&&c!='y'&&c!='n'&&c!='N')
            {
                printf("\nEnter  Y / N\t");
                scanf("%c",&c);
            }
            if(c=='n'||c=='N')
                break;
        }
    }
    FILE *fptr;
    fptr = fopen("stud_man.txt","w");
    if (fptr==NULL)
        exit(1);
    printf("\nDo you want to save changes ? Y / N\t ");
    getchar();
    scanf("%c",&c);
    while(c!='Y'&&c!='y'&&c!='n'&&c!='N')
    {
        printf("\nEnter  Y / N\t");
        scanf("%c",&c);
    }
    if(c=='y'||c=='Y')
    {
        save(fptr,s,n);
        printf("Changes are successfully saved. ");
    }
    fclose(fptr);
    printf("\nselect : \n1.main manu.\n2.quit. ");
    scanf("%d",&c1);
    if(c1==2)
        quit();
}
void normalise (Student *s, int n)
{
    FILE *fptr;
    char c;
    int i,c1;
    float su=0;
    fptr = fopen("stud_man.txt","w");
    if (fptr==NULL)
        exit(1);
    for(i=0; i<n; i++)
    {
        su+=s[i].gpa;
    }
    for (i=0; i<n; i++)
    {
        s[i].gpa+=(su/n)*0.05;
        if(s[i].gpa>4)
            s[i].gpa=4;
    }
    printf("\nDo you want to save changes ? Y / N\t ");
    getchar();
    scanf("%c",&c);
    while(c!='Y'&&c!='y'&&c!='n'&&c!='N')
    {
        printf("\nEnter  Y / N\t");
        scanf("%c",&c);
    }
    if(c=='y'||c=='Y')
    {
        save(fptr,s,n);
        printf("Changes are successfully saved. ");
    }
    fclose(fptr);
    printf("\nselect : \n1.main manu.\n2.quit. ");
    scanf("%d",&c1);
    if(c1==2)
        quit();
}

