#include <stdio.h> 
#include <string.h> //strcpy

struct course //struct definition
{
    int id;
    char title[40];
    float hours;
};

typedef struct courses //define type (struct course), (course) can be ignored
{
    int id;
    char title[20];
    float hours;
}icourse, *pcourse; //name of type defined, not name of variable here

typedef struct
{
    int x,y;
}point;

typedef struct
{
    float radius;
    point center; //structure within structure
}circle;

struct student
{
    char name[50];
    int number;
    int age;
};

void showStudentData(struct student *st) //pointer to structure
{
    printf("Name %s\n",st->name);
    printf("Number %d\n",st->number);
    printf("Age %d\n",st->age);
}

void update_icourse(icourse *class) //modify data truely
{
    class->id=111;
    strcpy(class->title,"C++ Fundamental");
    class->hours=12.30;
}

void display_icourse(icourse class) //using a copy of struct
{
    printf("%d\t%s\t%f\n",class.id,class.title,class.hours);
}

typedef struct
{
    int h,w,l;
}box;

/******************************************/

/*union use the same memory location for members and only one can occupy at a time*/
union val //union definition
{
    int int_num;
    float fl_num;
    char str[20];
};

typedef struct //structure with union
{
    char make[20];
    int model_year;
    int id_type;
    union id_member
    {
        int id_num;
        char VIN[20];
    }id; //union definition & declare
}vehicle;

union idt
{
    int id_num;
    char name[20];
};
void set_idt(union idt *item){item->id_num=42;} //modify data truely
void show_idt(union idt item){printf("ID %d\n",item.id_num);} //using a copy of union

union Coins 
{ //easy to use the name and indexes
    struct 
    {
        int quarter;
        int dime;
        int nickel;
        int penny;
    }; //anonymous struct
    int coins[4];
};

/******************************************/

int main()
{
    struct course math; //struct declare
    math=(struct course){115,"math",40.0}; //struct initialize by type casting
    struct course science={112,"science",40.0}; //struct declare & initialize directly
    struct course english=
            {
                .id=114,
                .title="english",
                .hours=40.0
            }; //using member to declare & initialize
    struct course important=math; //assign a structure
    //modify value of member
    math.hours=50.0;
    strcpy(math.title,"mathematics"); 
    printf("%d\t%s\t%f\n",math.id,math.title,math.hours);
    printf("%d\t%s\t%f\n",important.id,important.title,important.hours);

    icourse cs1;// using typedef to simplify
    icourse cs2={110,"chinese",40.0};
    printf("%d\t%s\t%f\n",cs2.id,cs2.title,cs2.hours);
    pcourse p_cs3; //using typedef pointer to simplify
    pcourse p_cs4=&cs2;
    printf("%d\t%s\t%f\n",p_cs4->id,p_cs4->title,p_cs4->hours);
    printf("%c %c ",p_cs4->title[0], (p_cs4->title)[1]);
    printf("%c %c\n",(*p_cs4).title[2], ((*p_cs4).title)[3]);

    circle c={4.5,{1,3}}; //structure with structure
    printf("%f at %d,%d\n",c.radius,c.center.x,c.center.y);

    struct student stu={"Ken",5,21};
    showStudentData(&stu); //pointer to structure

    icourse cs5;
    update_icourse(&cs5); //argument by pointer
    display_icourse(cs5); //argument by value

    box boxes[3]={{2,6,8},{4,6,6},{2,6,9}}; //array of struct
    for(int i=0;i<3;i++){printf("box %d\tvolume %d\n",i,boxes[i].h*boxes[i].w*boxes[i].l);}

/******************************************/

    /*union for memory management*/
    union val u1; //union declare
    u1.int_num=123; //union intialize by assignment
    u1.fl_num=98.76;
    strcpy(u1.str,"hello"); //the last assignment override previous assignment
    union val u2;
    u2=u1; //assign an union
    printf("%d\n",u1.int_num); //got error from previous assignment of member 
    printf("%f\n",u1.fl_num);
    printf("%s\n",u1.str); //only got correct from the last assignment of member
    printf("%d\n",u2.int_num);
    printf("%f\n",u2.fl_num);
    printf("%s\n",u2.str);

    vehicle car1;
    strcpy(car1.make,"Ford");
    car1.model_year=2017;
    car1.id_type=0;
    car1.id.id_num=123098; //if union in struct not declare, access its member directly
    printf("Make %s\n",car1.make);
    printf("model year %d\n",car1.model_year);
    if(car1.id_type==0){printf("ID num %d\n",car1.id.id_num);}
    else{printf("VIN %s\n",car1.id.VIN);} //only one kind of id exists in union of struct

    union val *ptr=NULL; //declare pointer to union
    ptr=&u2; //assign pointer to union
    ptr->int_num=10; //modify by pointer
    printf("%d\n",(*ptr).int_num);
    printf("%d\n",ptr->int_num);

    union idt idtu;
    set_idt(&idtu); //argument by pointer
    show_idt(idtu); //argument by value

    union val num[10]; //array of union in the same data type
    for(int i=0;i<10;i++){num[i].int_num=i;}
    for(int i=0;i<10;i++){printf("%d\t",num[i].int_num);}
    printf("\n");
    union val diff[3]; //array of union in different data type
    diff[0].int_num=123;
    diff[1].fl_num=98.76;
    strcpy(diff[2].str,"hello");
    printf("%d\n",diff[0].int_num);
    printf("%f\n",diff[1].fl_num);
    printf("%s\n",diff[2].str);

    union Coins total;
    total.quarter=5; //directly use the memeber of anonymous struct
    total.dime=6;
    total.nickel=7;
    total.penny=8;
    for(int i=0;i<sizeof(union Coins)/sizeof(int);i++)
    {
        printf("%d: %d; \t",i,total.coins[i]);
    }
    printf("\n");

/******************************************/

    return 0;
}