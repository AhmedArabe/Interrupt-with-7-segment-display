#ifndef BIT_MATH_H
#define BIT_MATH_H


#define SET_BIT(var,bit_num)       var = var|(1<<bit_num)
#define CLR_BIT(var,bit_num)       var = var&(~(1<<bit_num))
#define TOG_BIT(var,bit_num)       var = var^(1<<bit_num)
#define GET_BIT(var,bit_num)       ((var>>bit_num)&1)



#endif
