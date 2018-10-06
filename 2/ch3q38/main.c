//
//  main.c
//  ch3q38
//
//  Created by dmrfcoder on 2018/9/24.
//  Copyright © 2018年 dmrfcoder. All rights reserved.
//

#include <stdio.h>
//输入一个字符串，统计其中英文字符、十进制数字符、其他符号的个数并输出
int main(int argc, const char * argv[]) {
    // insert code here...
    char strs[100];
    
    printf("请输入一个字符串：");
    
    scanf("%s",strs);
    
    char  a=0,b=0,c=0;
    
    asm{
        mov esi,0;//下标
        lea eax,strs;//strs的首地址给eax
        mov cl,0;//英文字符个数
        mov ch,0;//十进制字符个数
        mov dl,0;//其他字符个数
    method1:
        mov bl,byte ptr [eax+esi];//取当前一个字节
        cmp bl ,0;
        je method2;//到达最后一个字节
        inc esi;//下标++
        cmp bl,40;
        jnbe method3;//如果大于等于40
        inc dl;//否则一定是其他字符
        jmp method1;
        
        
        
        
    method2:
        mov a,cl;
        mov b,ch;
        mov c,dl;
        ret;
        
    method3:
        cmp bl,57;
        ja method4;//如果大于57
        inc ch;//否则就是数字
        
    method4:
        cmp bl,65;
        jnbe method5;//如果大于等于65
        inc dl;//否则就是其他字符
        
    method5:
        cmp bl,90;
        ja method6;//如果大于90
        inc cl;//否则是英文字符
        
    method6:
        cmp bl,97;
        ja method7;//如果大于97
        inc dl;//否则就是其他字符
        
    method7:
        cmp bl,122;
        ja method8;//如果大于122
        jmp method9;
        
       
    method8:
        inc dl;
        jmp method1;
        
    method9:
        inc cl;//否则就是英文字符
        jmp method1;
        
        
        
        
        
        
        
    }
    
    printf("英文字符个数：%d，十进制字符个数：%d，其他字符个数：%d\n",a,b,c);
    return 0;
}
