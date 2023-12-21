//
//  smm_object.c
//  SMMarble
//
//  Created by Juyeop Kim on 2023/11/05.
//

#include "smm_common.h"
#include "smm_object.h"
#include <string.h>

#define MAX_NODETYPE    7
#define MAX_GRADE       9
#define MAX_NODE        100

//(10) ���ڿ� ��ȯ API �Լ� 
static char smmNodeName[SMMNODE_TYPE_MAX][MAX_CHARNAME] = {
       "����",
       "�Ĵ�",
       "�����",
       "��",
       "����Ƿ��̵�",
       "��������",
       "�����ð�"
};

char* smmObj_getTypeName(int type)
{
      return (char*)smmNodeName[type];
}


typedef enum smmObjGrade {
    smmObjGrade_Ap = 0,
    smmObjGrade_A0,
    smmObjGrade_Am,
    smmObjGrade_Bp,
    smmObjGrade_B0,
    smmObjGrade_Bm,
    smmObjGrade_Cp,
    smmObjGrade_C0,
    smmObjGrade_Cm
} smmObjGrade_e;

//1. ����ü ���� ����
typedef struct smmObject {
       char name[MAX_CHARNAME];
       smmObjType_e objType; 
       int type;
       int credit;
       int energy;
       smmObjGrade_e grade;
} smmObject_t; //(10) ������ ĸ��ȭ�� ���� ����ü ���� 

static smmObject_t smm_node[MAX_NODE]; //(10) ���� �迭 
static int smmObj_noNode = 0; 

typedef struct smmFoodCard {
    char name[MAX_CHARNAME];
    smmObjType_e objType;
    int type;
    int energy;
} smmFoodCard_t;

static smmFoodCard_t smm_food_cards[MAX_NODE];

typedef struct smmFestivalCard {
    char name[MAX_CHARNAME];
    smmObjType_e objType;
    int type;
} smmFestivalCard_t;

static smmFestivalCard_t smm_festival_cards[MAX_NODE];

//3. ���� �Լ� ���� 
//object generation (10) ���Ͽ��� �о�� ������ ���� 
void* smmObj_genObject(char* name, smmObjType_e objType, int type, int credit, int energy, smmObjGrade_e grade)
{    
    smmObject_t* ptr;
    
    ptr = (smmObject_t*)malloc(sizeof(smmObject_t));
    
    strcpy(ptr->name, name);
    ptr->objType = objType;
    ptr->type = type;
    ptr->credit = credit;
    ptr->energy = energy;
    ptr->grade = grade;
    
    return ptr;
}

//(10) get �Լ� ���� 
char* smmObj_getNodeName(void* obj)
{
    smmObject_t* ptr = (smmObject_t*)obj;
    
    return ptr->name;
}

int smmObj_getNodeType(int node_nr)
{
    return smm_node[node_nr].type;
}

int smmObj_getNodeCredit(int node_nr)
{
    return smm_node[node_nr].credit;
}

int smmObj_getNodeEnergy(int node_nr)
{
    return smm_node[node_nr].energy;
}
 
//(10) food���Ͽ��� �о�� ������ ���� 
void smmObj_genObject(char* name, smmObjType_e objType, int type, int credit, int energy, smmObjGrade_e grade) 
{
    smm_food_cards[food_nr].objType = objType;
    smm_food_cards[food_nr].type = type;
    smm_food_cards[food_nr].energy = energy;
    strcpy(smm_food_cards[food_nr].name, name);
    
    smmdb_addTail(LISTNO_NODE, &smm_food_cards[food_nr]);

    food_nr++;
}

//(10) get �Լ� ���� 
char* smmObj_getFoodCardName(int card_nr) {
    return smm_food_cards[card_nr].name;
}

int smmObj_getFoodCardEnergy(int card_nr) {
    return smm_food_cards[card_nr].energy;
}

void smmObj_genObject(char* name, smmObjType_e objType, int type, int credit, int energy, smmObjGrade_e grade) 
{
    smm_festival_cards[festival_nr].objType = objType;
    smm_festival_cards[festival_nr].type = type;
    strcpy(smm_festival_cards[festival_nr].name, name);

    smmdb_addTail(LISTNO_NODE, &smm_festival_cards[festival_nr]);

    festival_nr++;
}

char* smmObj_getFestivalCardName(int card_nr) {
    return smm_festival_cards[card_nr].name;
}

