//
//  main.c
//  2
//
//  Created by dmrfcoder on 2018/9/17.
//  Copyright © 2018年 dmrfcoder. All rights reserved.
//

#include <stdio.h>
/**
 用户输入4个字符，将这四个字符（字节）分别拼接成两个字数据和一个双字数据并输出。
 */
int main(int argc, const char * argv[]) {
    // insert code here...

    
    printf("请连续输入四个字符:\n");
    char a,b,c,d;
    scanf("%c%c%c%c",&a,&b,&c,&d);
    int A1,A3,A4;
    asm{
        MOV AH,a;
        MOV AL,b;
        SAL EAX,16;
        MOV AH,c;
        MOV AL,d;
        MOV A1,EAX;
       
        MOV CH,a;
        MOV CL,b;
        MOV A3,ECX;
        
        MOV DH,c;
        MOV DL,d;
        MOV A4,EDX;

    }
    
    printf("拼接成两个单字数据：\n");
    printf("a1:%08xh %d\n",A3,A3);
    printf("a2:%08xh %d\n",A4,A4);

     printf("拼接成一个双字数据：\n");
           
    printf("a1:%08xh %d\n",A1,A1);
   
    
    
    return 0;

}
