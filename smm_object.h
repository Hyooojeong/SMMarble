//
//  smm_object.h
//  SMMarble object
//
//  Created by Juyeop Kim on 2023/11/05.
//

#ifndef smm_object_h
#define smm_object_h

//(10) ��� ���� ����  
#define SMMNODE_TYPE_LECTURE            0
#define SMMNODE_TYPE_RESTAURANT         1
#define SMMNODE_TYPE_LABORATORY         2
#define SMMNODE_TYPE_HOME               3
#define SMMNODE_TYPE_GOTOLAB            4
#define SMMNODE_TYPE_FOODCHANCE         5
#define SMMNODE_TYPE_FESTIVAL           6

#define SMMNODE_TYPE_MAX                7

//(10) ���� ���� ����
#define SMMNODE_TYPE_FOODCHANCE         8

//(10) ���� ���� ���� 
#define SMMNODE_TYPE_FESTIVAL           9
 

typedef enum smmObjType {
    smmObjType_board = 0,
    smmObjType_card,
    smmObjType_grade
} smmObjType_e;

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



//object generation
void smmObj_genObject(char* name, smmObjType_e objType, int type, int credit, int energy, smmObjGrade_e grade);

//member retrieving
char* smmObj_getNodeName(int node_nr);
int smmObj_getNodeType(int node_nr);
int smmObj_getNodeCredit(int node_nr);
int smmObj_getNodeEnergy(int node_nr);

char* smmObj_getTypeName(int type);

//element to string
char* smmObj_getTypeName(int type);


#endif /* smm_object_h */