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

double Calculate(StackChar S,StackDouble s,char str[]){
    int j = 0;
    int i = 0;
    int k = 0;
    char str2[MAXBUFFER];
    char c,e,m;
    double a,b,d;

    printf("请输入一个需要计算的多项式，以输入=表示结束:\n");
    scanf("%c",&c);

    while(c != '='){
        if((c >= '0'&&c <= '9')||c == '.'){
            str[i++] = c;
        }
        else if('+' == c||'-' == c){
            GetChar(S,&e);
            if(LenChar(S) == 0||'(' == e){
                PushChar(&S,c);
                str[i++] = ' ';
            }
            else{
                do{
                    PopChar(&S,&e);
                    str[i++] = ' ';
                    str[i++] = e;
                }while(LenChar(S) != 0);
                PushChar(&S,c);
                str[i++] = ' ';
            }
        }
        else if('*' == c||'/' == c){
            GetChar(S,&e);
            if(LenChar(S) == 0||'(' == e){
                PushChar(&S,c);
                str[i++] = ' ';
            }
            else{
                if('*' == e||'/' == e){
                    PopChar(&S,&e);
                    str[i++] = ' ';
                    str[i++] = e;
                    PushChar(&S,c);
                    str[i++] = ' ';
                }
                else{
                    PushChar(&S,c);
                    str[i++] = ' ';
                }
            }
        }
        else if('(' == c){
            PushChar(&S,c);
        }
        else if(')' == c){
            do{
                PopChar(&S,&e);
                if(e != '('){
                    str[i++] = ' ';
                    str[i++] = e;
                }
            }while(e != '(');
        }

        scanf("%c",&c);
    }
    while(LenChar(S) != 0){
        PopChar(&S,&e);
        str[i++] = ' ';
        str[i++] = e;
    }

    m = str[j];
    while(j <= i){
        while((m >= '0'&&m <= '9')||m == '.'){
            str2[k] = m;
            str2[++k] = '\0';

            m = str[++j];
            if(' ' == m){
                d = atof(str2);
                PushDouble(&s,d);
                k = 0;
            }
        }
        switch(m){
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

        m = str[++j];
    }

    PopDouble(&s,&d);

    return d;
}
