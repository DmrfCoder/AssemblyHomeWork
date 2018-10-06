//
//  main.c
//  ch3q36
//
//  Created by dmrfcoder on 2018/9/24.
//  Copyright © 2018年 dmrfcoder. All rights reserved.
//

#include <stdio.h>
//输入两个字符，将他们视为两个8位数据，合并成一个16位数据，合并格式：a1b1a2b3a3b3a4b4a5b5a6b6a7b7a8b8
int main(int argc, const char * argv[]) {
    // insert code here...
    char c1,c2;
    printf("请连续输入两个字符：\n");
    scanf("%c%c",&c1,&c2);
  
    short result=0;//16位，存放结果
    
    asm{
        mov al,c1;
        mov bl,c2;
        mov esi,0;
        mov ecx,0;//存放最终结果
        
    method1:
        cmp esi ,8;
        jl method2;
        jmp method3;
        
    method2:
        sal ecx,1;//向左移一位，保证最后一位为0
        test al,10000000B;//检测al第一位是否为1
        jne method4;//如果zf为0即第一位为1
        and ecx,11111111B;
        
        
        sal ecx,1;//向左移一位，保证最后一位为0
        test bl,10000000B;//检测bl第一位是否为1
        jne method4;//如果zf为0即第一位为1
        and ecx,11111111B;
        
        
        
        
        
        
        
    method3:
        mov result ,cx;
        ret;
        
        
    method4:
        and ecx,11111110B;
        
    }
    
    
    printf("结果：%hd\n",result);
    
    return 0;
}
