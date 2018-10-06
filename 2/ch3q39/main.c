//
//  main.c
//  ch3q39
//
//  Created by dmrfcoder on 2018/9/24.
//  Copyright © 2018年 dmrfcoder. All rights reserved.
//

#include <stdio.h>
//输入一个字符串，逆序排列字符后输出

int main(int argc, const char * argv[]) {
    // insert code here...
    char strs[100];
    char strs2[100];
    
    printf("请输入一个字符串：abcde\n");
   
    
    scanf("%s",strs);
    
    
    asm{
        lea eax,strs;//strs的首地址给eax
        lea ebx,strs2;g
        mov esi,0;//下标
        
    method1:
        
        mov cl,byte ptr [eax+esi];//获取当前字符
        cmp cl,0;
        je method2;//如果当前字符为最后一位
        push cl;
        inc esi;
        
        
        
    method2:
        dec esi;
        cmp esi,0;
        jge method3;
        jmp method4;
        jmp method2;
        
        
    method3:
        pop cl;
        mov [ebx+esi],cl;
        
    method4:
        ret;
    
    }
    
    
    printf("逆序之后的字符串：%s\n",strs2);
    return 0;
}
