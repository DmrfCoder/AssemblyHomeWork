//
//  main.c
//  1
//
//  Created by dmrfcoder on 2018/9/17.
//  Copyright © 2018年 dmrfcoder. All rights reserved.
//

#include <stdio.h>
/**
 输入两个整数，把两个整数分别当作有符号数和无符号数比较大小并输出较大值，计算着两个数的差并输出其差的绝对值。
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    int X,Y;
    
    printf("请输入两个整数：\n");
    scanf("%d%d",&X,&Y);
    
    unsigned int x = (unsigned int)X;
    unsigned int y = (unsigned int)Y;
    
    printf("将X，Y转化为无符号数后的结果是:X:%d-->%u Y:%d-->%u\n\n",X,x,Y,y);
    
    
    int a1,a2,a3;
    
    
    asm{
        
        MOV  EAX, X;//将X的值移入EAZ寄存器
        
        
        
        CMP  EAX, Y;//将Y的值与EAX寄存器中的值（X）进行比较
        
        
        
        JGE NEXT ;//如果EAX（X）大于等于Y，则跳转至NEXT
        
        
        
        MOV  EAX, Y ;//如果EAX（X）小于Y，则将Y移入EAX寄存器
        
        
        
        
        
    NEXT:
        MOV a1, EAX;//将EAX的值放入X
        
    }
    
    
    asm{
        
        MOV  EAX, X;
        
        
        
        CMP  EAX, Y;
        
        
        
        JA NEXT ;//将原来的JGE指令替换成JA以实现无符号数的比较
        
        
        
        MOV  EAX, Y ;
        
        
        
    NEXT:
        MOV a2, EAX;
        
        
        
    }
    
    
    
    asm{
        
        MOV  EAX, X;//把X放入EAX寄存器
        
        MOV  EBX, Y;//把Y放入EBX寄存器
        
        SUB  EBX,EAX;//EBX=EBX-EAX(Y-X)，计算EBX-EAX
        
        CMP EBX ,0;//比较减法结果与0的比值
        
        JNL NEXT;//如果减法结果大于等于0，则跳转至NEXT
        NEG EBX;//如果减法的结果小于0，则对EBX中的内容取负（取补）
        
        
        
    NEXT:
        MOV a3 ,EBX;//将EBX的值给X
        
        
        
    }
    
    
    
    
    
    
    printf("有符号数较大值：%d\n",a1);
    printf("无符号数较大值：%d\n",a2);
    printf("绝对值：%d\n",a3);
    
    

    return 0;
}
