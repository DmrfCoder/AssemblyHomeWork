//
//  main.c
//  40
//
//  Created by dmrfcoder on 2018/9/23.
//  Copyright © 2018年 dmrfcoder. All rights reserved.
//

#include <stdio.h>
//13个无符号整数，计算“奇数和”与“偶数和”差值的绝对值
int main(int argc, const char * argv[]) {
    // insert code here...
    unsigned int strs[13]={10,20,30,44,56,98,100,32,45,66,21,55,32};
    printf("13个无符号整数：\n");
    for (int i=0; i<13; i++) {
        printf("%u ",strs[i]);
    }
    printf("\n");
    
    int reult=0;
    
     
    
//    asm{
//
//        xor eax;
//        xor ebx;//奇数和
//        xor ecx;//偶数和
//        mov esi,0;//下标
//        lea ecx,strs;//strs的首地址给ecx
//
//    method1:
//        cmp esi,13;
//        jl method2;
//        jmp method3;
//
//    method2:
//        movzbl eax,byte ptr [ecx+esi];//将当前1个字节零拓展到四位寄存器eax
//        add eax,0;//给eax+0，这样执行后会改变标志位pf
//        jp method4;//偶转移
//        jmp method5;//奇转移
//
//
//    method3:
//        sub ebx,ecx;//ebx=ebx-ecx;
//        cmp ebx,0;
//        jg method6;//ebx>0
//        neg ebx;//ebx<=0,ebx=-ebx;
//        jmp method6;
//
//
//
//    method4:
//        add ecx,eax;
//        inc esi;
//
//    method5:
//        add ebx,eax;
//        inc esi;
//
//    method6:
//        mov reult,ebx;//reult=ebx
//        ret;
//
//    }
    
   // printf("奇数和与偶数和之差的绝对值：%d\n",reult);
    return 0;
}
