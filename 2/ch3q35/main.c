//
//  main.c
//  ch3q35
//
//  Created by dmrfcoder on 2018/9/24.
//  Copyright © 2018年 dmrfcoder. All rights reserved.
//

#include <stdio.h>
//一个无符号整数，统计该32位整数中位值为0的个数并输出
int main(int argc, const char * argv[]) {
    // insert code here...
    unsigned  int n=0;
    printf("请输入一个无符号整数：");
    scanf("%u",n);
    int count=0;
    
    asm{
        mov eax,n;//将n的值给eax
        mov esi,0;//下标
        mov ebx,0;//计数器
        
    method1:
        cmp esi,32;
        jl method2;
        jmp method3;
        
    method2:
        test al,00000001B;//检测al的最后一位是否为1
        jne method4;//如果zf为0即最后一位为1
        shr eax,1;//逻辑右移一位
        inc esi;//下标++
        jmp method1;
        
    method3:
        mov count,ebx;
        ret;
        
    method4:
        inc ebx;
        shr eax,1;//逻辑右移一位
        
        
    }
    
    printf("32位中共有：%d 个位值为1的位\n",count);
    return 0;
}
