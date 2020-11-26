#include "compute.h"

void InitChar(StackChar *s){
    s->base = (ElemType *)malloc(STACKSIZE * sizeof(ElemType));
    if(! s->base){
        exit(0);
    }

    s->top = s->base;
    s->StackSize = STACKSIZE;
}

void InitDouble(StackDouble *s){
    s->base = (DataType *)malloc(STACKSIZE * sizeof(DataType));
    if(! s->base){
        exit(0);
    }

    s->top = s->base;
    s->StackSize = STACKSIZE;
}

void PushChar(StackChar *s,ElemType e){
    if(s->top - s->base >= s->StackSize){
        s->base = (ElemType *)realloc(s->base,(s->StackSize + STACKINCREMENT) * sizeof(ElemType));
        if(!s->base){
            exit(0);
        }
    }

    *(s->top) = e;
    s->top++;
}

void PushDouble(StackDouble *s,DataType e){
    if(s->top - s->base >= s->StackSize){
        s->base = (DataType *)realloc(s->base,(s->StackSize + STACKINCREMENT) * sizeof(DataType));
        if(!s->base){
            exit(0);
        }
    }

    *(s->top) = e;
    s->top++;
}

void PopChar(StackChar *s,ElemType *e){
    if(s->top == s->base){
        return;
    }

    *e = *--(s->top);
}

void PopDouble(StackDouble *s,DataType *e){
    if(s->top == s->base){
        return;
    }

    *e = *--(s->top);
}

int LenChar(StackChar s){
    return(s.top - s.base);
}

int LenDouble(StackDouble s){
    return(s.top - s.base);
}

void GetChar(StackChar s,ElemType *e){
    if(s.top == s.base){
        return;
    }

    PopChar(&s,e);
    PushChar(&s,*e);
}

void Transform(StackChar s){
    int j;
    char c,e;

    printf("请输入一个需要计算的多项式，以输入=表示结束:\n");
    scanf("%c",&c);

    while(c != '='){
        if((c >= '0'&&c <= '9')||c == '.'){
            str[i++] = c;
        }
        else if('+' == c||'-' == c){
            GetChar(s,&e);
            if(LenChar(s) == 0||'(' == e){
                PushChar(&s,c);
                str[i++] = ' ';
            }
            else{
                do{
                    PopChar(&s,&e);
                    str[i++] = ' ';
                    str[i++] = e;
                }while(LenChar(s) != 0);
                PushChar(&s,c);
                str[i++] = ' ';
            }
        }
        else if('*' == c||'/' == c){
            GetChar(s,&e);
            if(LenChar(s) == 0||'(' == e){
                PushChar(&s,c);
                str[i++] = ' ';
            }
            else{
                if('*' == e||'/' == e){
                    PopChar(&s,&e);
                    str[i++] = ' ';
                    str[i++] = e;
                    PushChar(&s,c);
                    str[i++] = ' ';
                }
                else{
                    PushChar(&s,c);
                    str[i++] = ' ';
                }
            }
        }
        else if('(' == c){
            PushChar(&s,c);
        }
        else if(')' == c){
            do{
                PopChar(&s,&e);
                if(e != '('){
                    str[i++] = ' ';
                    str[i++] = e;
                }
            }while(e != '(');
        }

        scanf("%c",&c);
    }
    while(LenChar(s) != 0){
        PopChar(&s,&e);
        str[i++] = ' ';
        str[i++] = e;
    }

}

double Calculate(StackDouble s,char str[]){
    int j = 0;
    char str2[MAXBUFFER];
    int k = 0;
    char c;
    double a,b,d;

    c = str[j];
    while(j <= i){
        while((c >= '0'&&c <= '9')||c == '.'){
            str2[k] = c;
            str2[++k] = '\0';

            c = str[++j];
            if(' ' == c){
                d = atof(str2);
                PushDouble(&s,d);
                k = 0;
            }
        }
        switch(c){
            case '+':
                PopDouble(&s,&a);
                PopDouble(&s,&b);
                PushDouble(&s,b + a);
                break;
            case '-':
                PopDouble(&s,&a);
                PopDouble(&s,&b);
                PushDouble(&s,b - a);
                break;
            case '*':
                PopDouble(&s,&a);
                PopDouble(&s,&b);
                PushDouble(&s,b * a);
                break;
            case '/':
                PopDouble(&s,&a);
                PopDouble(&s,&b);
                if(0 == a){
                    printf("\n出错，除数不能为零!\n");
                }
                else{
                    PushDouble(&s,b / a);
                }
                break;
        }

        c = str[++j];
    }

    PopDouble(&s,&d);

    return d;
}
