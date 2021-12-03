#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declare the self-defined data type
typedef char* obj_name; 
typedef int obj_id;
typedef void (* obj_steps) (void);

//declare the self-defined struct with self-defined data type
struct SOP
{
    obj_name name;
    obj_id ID;
    obj_steps one;
    obj_steps two;
    obj_steps three;
    obj_steps four;
};

//declare the constructor to initialize members for SOP
void SOPinit(struct SOP *sop_obj, obj_name input_name, obj_id input_ID, 
             obj_steps input_func1, obj_steps input_func2, 
             obj_steps input_func3, obj_steps input_func4)
{
    sop_obj->name = input_name;
    sop_obj->ID = input_ID;
    sop_obj->one = input_func1;
    sop_obj->two = input_func2;
    sop_obj->three = input_func3;
    sop_obj->four = input_func4;
}

//declare the function to execute all related functions for SOP
void SOPexecute(struct SOP sop_obj)
{
    printf("the obj name is %s\n",sop_obj.name);
    printf("the obj ID is %d\n", sop_obj.ID);
    sop_obj.one(); 
    sop_obj.two(); 
    sop_obj.three(); 
    sop_obj.four();
}

//------

void CarStep1(void){ printf("get on the car\n"); }
void CarStep2(void){ printf("calibrate the mirror\n"); }
void CarStep3(void){ printf("settle the belt\n"); }
void CarStep4(void){ printf("engine start & go\n"); }

void PlaneStep1(void){ printf("get aboard the plane\n"); }
void PlaneStep2(void){ printf("machine check\n"); }
void PlaneStep3(void){ printf("settle the belt\n"); }
void PlaneStep4(void){ printf("engine start & throttle push\n"); }

int main()
{
    printf("Here to driving...\n");
    struct SOP car;
    char car_name[]={"my favorite car"};    
    SOPinit(&car, car_name, 1, CarStep1, CarStep2, CarStep3, CarStep4);
    SOPexecute(car);

    printf("---\n");

    printf("Here to fly a plane...\n");
    struct SOP plane;
    char plane_name[]={"my favorite plane"};
    SOPinit(&plane, plane_name, 99, PlaneStep1, PlaneStep2, PlaneStep3, PlaneStep4);
    SOPexecute(plane);
    
    return 0;
}