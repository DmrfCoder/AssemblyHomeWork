//
//  main.c
//  37
//
//  Created by dmrfcoder on 2018/9/22.
//  Copyright © 2018年 dmrfcoder. All rights reserved.
//

#include <stdio.h>


//10个字节整数，作为有符号整数统计正数和负数的个数
int main(int argc, const char * argv[]) {
    // insert code here...
    char strs[10]={10,20,30,-10,-20,-30,44,56,98,-100};
    printf("10个字节型整数转化为整形后的值为：\n");
    for (int i=0; i<10; i++) {
        printf("%d ",strs[i]);
    }
    printf("\n");
    
    
    int g=0,l=0,e=0;
    
    
    asm{
        xor eax,eax;
        xor ebx,ebx;
        xor ecx,ecx;
        xor edx,edx;
        
        lea eax,strs;//将strs的首地址给eax
        mov esi,0;//esi为下标，初始值为0
        
    method1:
        mov al,byte ptr [eax+esi];//从eax+esi的地址开始取一个字节的e内容
        cmp al,0;//将当前字节与0比较
        je method2;//如果当前字节作为整数等于0
        cmp al,0;
        jge method3;//如果当前字节作为整数比0大
        jmp method4;//当前字节作为字节比0小
        cmp esi,10;//将下标与0比较
        je method5;//如果下标等于10
        jmp method1;//否则x进行循环
        
    method2://等于0
        inc esi;
        inc edx;
        jmp method1;
        
    method3://大于0
        inc esi;
        inc ebx;
        
    method4://小于0
        inc esi;
        inc ecx;
        
    method5://下标等于10
        mov e,edx;
        mov g,ebx;
        mov l,ecx;
        ret;
        
        
    }
    
    printf("大于0的个数：%d，等于0的个数：%d，小于0的个数：%d\n",g,e,l);
    
    
    return 0;
}
