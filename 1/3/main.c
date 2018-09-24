//
//  main.c
//  3
//
//  Created by dmrfcoder on 2018/9/17.
//  Copyright © 2018年 dmrfcoder. All rights reserved.
//

#include <stdio.h>
/**
输入一个字符串，判断并打印字符串的长度
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    
    char str[100];
    scanf("%s", str);
    int sum=0;
    asm {
        LEA EAX,str;
        MOV EBX,0
        
        
    NEXT:
        MOV AH,[EAX+EBX];
        ADD EBX,1;
        
        CMP AH,0;
        JNE NEXT;//如果AH不等于0（\0）
        
        SUB EBX,1;
        MOV sum,EBX;
    }
    printf("字符串长度%d\n",sum);
}
