//
//  main.c
//  18
//
//  Created by dmrfcoder on 2018/10/6.
//  Copyright © 2018年 dmrfcoder. All rights reserved.
//

#include <stdio.h>


//输入两个字符串，将其拼接并输出

int main(int argc, const char * argv[]) {
    // insert code here...
    
    char astr[20],bstr[20];
    char targetstr[40];
    
    scanf("%s",astr);
    scanf("%s",bstr);
    int lena=0,lenb=0;
    
    
    
//    求a长度
    asm{
        xor al,al;
        lea edi,astr;
        mov ecx,-1;
        repnz scasb;
        not ecx;
        dec ecx;
        mov lena,ecx;
    }
  
    
    //    求b长度
    asm{
        xor al,al;
        lea edi,bstr;
        mov ecx,-1;
        repnz scasb;
        not ecx;
        dec ecx;
        mov lenb,ecx;
    }
    
    
    //拼接
    asm{
        lea edi,targetstr;
        lea esi,astr;
        mov ecx,lena;
        
    next:
        movsb;
        loop next;
        
        
    next2:
        lea esi,bstr;
        mov ecx,lenb;
    
    next3:
        movsb;
        loop next3;
        
        mov targetstr,edi;
        
        
    }
    
    printf("%s\n",targetstr);
    
    
    
    return 0;
}
