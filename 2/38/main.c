//
//  main.c
//  38
//
//  Created by dmrfcoder on 2018/9/23.
//  Copyright © 2018年 dmrfcoder. All rights reserved.
//

#include <stdio.h>
//20个字节型整数，连续2个字节拼在一起有10个字数据，连续4个字节拼在一起有5个32位数据，统计10个数据作为16位整数的正数个数与5个数据作为32位s整数负数的个数
int main(int argc, const char * argv[]) {
    // insert code here...
    char strs[20]={10,20,30,40,50,60,70,80,90,100,-100,-90,-80,-70,-60,-50,-40,-30,-20,-10};
    
    printf("20个字符型整数：");
    for (int i=0; i<20; i++) {
        printf("%d ",strs[i]);
    }
    
    printf("\n ");
    
    int g=0,l=0;
    
    
    asm{
        xor eax,eax;//首地址
        xor ebx,ebx;//2字节整数（bx）
        xor ecx,ecx;//4字节整数
        xor edx,edx;//正数个数
        xor esp,esp;//负数个数
        lea eax,strs;//将strs的首地址给eax
        mov esi,0;//esi为下标
        
    method1:
        cmp esi ,10;
        jl method2;
        jmp method3;
        
        
        
        
        
    method2:
        mov bx ,word ptr [eax+esi*2];//连续2个字节
        cmp bx,0;
        jg method4;//如果bx大于0
        
        
        
        
        
        
    method3:
        mov g,edx;
        mov l,esp;
        ret;
        
    method4:
        inc edx;//edx++
        cmp esi,5;//如果下标i小于5
        jl method6;
        jmp method5;
        inc esi;
        jmp method1;
        
        
        
    method5:
        
    method6:
        mov ecx,dword ptr [eax+esi*4];//连续4个字节
        cmp ecx,0;
        jg method7;
        
    method7:
        inc esp;//esp++
    }
    
    
    printf("正数个数：%d，负数个数：%d\n",g,l);
    
    
    
    return 0;
}
