//
//  main.c
//  39
//
//  Created by dmrfcoder on 2018/9/23.
//  Copyright © 2018年 dmrfcoder. All rights reserved.
//

#include <stdio.h>
//10个字符型整数，按照有符号数和无符号数分别计算累加和
int main(int argc, const char * argv[]) {
    // insert code here...
    char strs[10]={10,20,30,-10,-20,-30,44,56,98,-100};
    printf("10个字节型整数转化为整形后的值为：\n");
    for (int i=0; i<10; i++) {
        printf("%d ",strs[i]);
    }
    printf("\n");
    
 
    
    int s=0,us=0;
    
    asm{
        xor eax,eax;//存放当前元素
        xor ebx,ebx;//有符号数和
        xor ecx,ecx;//无符号数和
        lea edi,strs;//将strs的首地址给eax
        mov esi,0;//数组下标
        
    method1:
        cmp esi, 10;
        jl method2;
        jmp method3;
        
    method2:
        
        movzbl eax,byte ptr [edi+esi];//将当前8位零拓展到32位
        add ecx,eax;//ecx=eax+ecx（实际上eax中只有最后8位有效，其余高24位都为0）
        
        movsbl eax,byte ptr [edi+esi];//将当前8位符号拓展到32位
        add ebx,eax;//ebx=eax+ebx
        
        inc esi;//下标+1
        
        
        
        
        
        
        
    method3:
        mov s,ebx;
        mov us,ecx;
        ret;
        
        
        
    }
    
    
    printf("作为无符号数和：%d，作为有符号数和：%d\n",us,s);
    
    return 0;
}
