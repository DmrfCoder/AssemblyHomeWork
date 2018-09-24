//
//  main.c
//  ch3q37
//
//  Created by dmrfcoder on 2018/9/24.
//  Copyright © 2018年 dmrfcoder. All rights reserved.
//
//输入两个整数，分别取其绝对值作为新数据，交换这两个新数据的高16位得到两个新的整数，分别输出这两个新的整数
#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int a=0,b=0;
    printf("请输入两个整数：");
    scanf("%d%d",&a,&b);
    
    asm{
        mov eax,a;
        mov ebx,b;
        mov esi,0;
        
    method1:
        cmp eax,0;
        jge method2;
        neg eax;
        jmp method2;
        
        cmp ebx,0;
        jge method3;
        neg ebx;
        jmp method3;
        
        mov bx,cx;//将eax原来的低16位给ebx（新的a是ebx）
        mov ax,dx;//将ebx原来的低16位给eax(新的b是eax)
        
        mov a,ebx;
        mov b,eax;
        
        ret;
        
        
        
        
        
        
    method2:
        mov cx,ax;//将eax的低16位放到cx
        
    method3:
        mov dx,bx;//将ebx的低16位放到dx
        
    }
    
    printf("新的两个整数：%d %d\n",a,b);
    return 0;
}
