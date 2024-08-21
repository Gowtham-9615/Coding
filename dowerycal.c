#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void display(char *name, int age,char *company,char* role, float salary,char *location,int vehicle,int flat){
        printf("\nYour name:: ");
        printf("%s",name);
        
        printf("\nYour age:: %d",age);
        printf("\nYour Company:: ");
        printf("%s",company);

        printf("\nYour Role:: ");
        printf("%s",role);

        printf("\nYour Salary:: %f",salary);

        printf("\nYour Location:: ");
        printf("%s",location);

        printf("\nYour Vehicle ::");
        if(vehicle==1){
            printf("Bike");
        }
        if(vehicle==2){
            printf("Car");
        }
        if(vehicle==3){
            printf("No Vehicle");
        }
        printf("\nYour Flat ::");
        if(flat==1){
            printf("Yes");
        }
        else{
            printf("No Flat");
        }
        
}

char* lower(char *a){
    for(int i=0; i<a[i];i++){
        a[i]=tolower(a[i]);
    }
    return a;
}
int calculate(char *name, int age,char *company,char* role, float salary,char *location,int vehicle,int flat){
    int cal;
    if(age>23 && age<30){
        cal=30000+cal;
    }
    else if(age>30){
        cal=20000+cal;
    }
    char *MNC[]={"wipro","tcs","HCL","Techmahindra","Accenture","infosys","Capgemini","Google","Apple","Microsoft","samsung"};
    int c;
    
    char *s1=lower(company);
    // for(int i=0;i<11;i++){
    //     char *s2=lower(MNC[0]);
    //     if(strcmp(s1,s2)==0){
    //         c++;
    //         cal=50000+cal;
    //     }
    // }
    if(c==0){
        cal=35000+cal;
    }
    return cal;
}
int main(){
    printf("Welcome to Dowery Calculator!\n");
    printf("Enter Your Name: ");
    char name[50];
    scanf("%s",name);

    printf("Enter your Age: ");
    int age;
    scanf("%d",&age);


    printf("Enter Your Company: ");
    char company[50];
    scanf("%s",company);


    printf("Enter Your Role: ");
    char role[50];
    scanf("%s",role);


    printf("Enter Your Salary: ");
    float salary;
    scanf("%f",&salary);


    printf("Enter Your Location: ");
    char location[50];
    scanf("%s",location);


    printf("\nChoose your Vehicle: ");
    printf("\nPress 1 for Car");
    printf("\nPress 2 for Bike");
    printf("\nPress 3 for Nothing");

    int vehicle;
    scanf("%d",&vehicle);

    printf("\nDo you have own Flat");
    printf("\npress 1 for yes");
    printf("\nPress 2 for No");

    int flat;
    scanf("%d",&flat);

    system("clear");
    printf("\nEntered Details: ");
    display(name,age,company,role,salary,location,vehicle,flat);

    printf("\n---------------------------------------------\n");
    printf("You can give upto %d\n",calculate(name,age,company,role,salary,location,vehicle,flat));
}