/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/redbluecarrots/Documents/University/ELEC5552/ELEC5552-MEMS-Characterisation/fpga/DDS_Lookup/BigLookUp.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_1006216973935652998_1035706684(char *, char *, char *, char *, int );
char *ieee_p_2592010699_sub_16439767405979520975_503743352(char *, char *, char *, char *, char *, char *);
char *ieee_p_2592010699_sub_16439989832805790689_503743352(char *, char *, char *, char *, char *, char *);
unsigned char ieee_p_2592010699_sub_2763492388968962707_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_3192134911_1516540902_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned int t3;
    unsigned int t4;
    unsigned int t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;

LAB0:    xsi_set_current_line(59, ng0);

LAB3:    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t3 = (15 - 13);
    t4 = (t3 * 1U);
    t5 = (0 + t4);
    t1 = (t2 + t5);
    t6 = (t0 + 5768);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 14U);
    xsi_driver_first_trans_fast_port(t6);

LAB2:    t11 = (t0 + 5592);
    *((int *)t11) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3192134911_1516540902_p_1(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t4;
    unsigned int t5;
    char *t6;
    char *t7;
    char *t8;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    unsigned char t18;
    unsigned int t19;
    char *t20;
    char *t21;
    char *t22;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    unsigned char t32;
    unsigned int t33;
    char *t34;
    char *t35;
    char *t36;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    char *t49;
    char *t50;

LAB0:    xsi_set_current_line(60, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t1 = (t0 + 10167);
    t4 = 1;
    if (2U == 2U)
        goto LAB5;

LAB6:    t4 = 0;

LAB7:    if (t4 != 0)
        goto LAB3;

LAB4:    t15 = (t0 + 1512U);
    t16 = *((char **)t15);
    t15 = (t0 + 10173);
    t18 = 1;
    if (2U == 2U)
        goto LAB13;

LAB14:    t18 = 0;

LAB15:    if (t18 != 0)
        goto LAB11;

LAB12:    t29 = (t0 + 1512U);
    t30 = *((char **)t29);
    t29 = (t0 + 10179);
    t32 = 1;
    if (2U == 2U)
        goto LAB21;

LAB22:    t32 = 0;

LAB23:    if (t32 != 0)
        goto LAB19;

LAB20:
LAB27:    t43 = (t0 + 10185);
    t45 = (t0 + 5832);
    t46 = (t45 + 56U);
    t47 = *((char **)t46);
    t48 = (t47 + 56U);
    t49 = *((char **)t48);
    memcpy(t49, t43, 4U);
    xsi_driver_first_trans_fast(t45);

LAB2:    t50 = (t0 + 5608);
    *((int *)t50) = 1;

LAB1:    return;
LAB3:    t8 = (t0 + 10169);
    t10 = (t0 + 5832);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t8, 4U);
    xsi_driver_first_trans_fast(t10);
    goto LAB2;

LAB5:    t5 = 0;

LAB8:    if (t5 < 2U)
        goto LAB9;
    else
        goto LAB7;

LAB9:    t6 = (t2 + t5);
    t7 = (t1 + t5);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB6;

LAB10:    t5 = (t5 + 1);
    goto LAB8;

LAB11:    t22 = (t0 + 10175);
    t24 = (t0 + 5832);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    memcpy(t28, t22, 4U);
    xsi_driver_first_trans_fast(t24);
    goto LAB2;

LAB13:    t19 = 0;

LAB16:    if (t19 < 2U)
        goto LAB17;
    else
        goto LAB15;

LAB17:    t20 = (t16 + t19);
    t21 = (t15 + t19);
    if (*((unsigned char *)t20) != *((unsigned char *)t21))
        goto LAB14;

LAB18:    t19 = (t19 + 1);
    goto LAB16;

LAB19:    t36 = (t0 + 10181);
    t38 = (t0 + 5832);
    t39 = (t38 + 56U);
    t40 = *((char **)t39);
    t41 = (t40 + 56U);
    t42 = *((char **)t41);
    memcpy(t42, t36, 4U);
    xsi_driver_first_trans_fast(t38);
    goto LAB2;

LAB21:    t33 = 0;

LAB24:    if (t33 < 2U)
        goto LAB25;
    else
        goto LAB23;

LAB25:    t34 = (t30 + t33);
    t35 = (t29 + t33);
    if (*((unsigned char *)t34) != *((unsigned char *)t35))
        goto LAB22;

LAB26:    t33 = (t33 + 1);
    goto LAB24;

LAB28:    goto LAB2;

}

static void work_a_3192134911_1516540902_p_2(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t4;
    unsigned int t5;
    char *t6;
    char *t7;
    char *t8;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    unsigned char t18;
    unsigned int t19;
    char *t20;
    char *t21;
    char *t22;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    unsigned char t32;
    unsigned int t33;
    char *t34;
    char *t35;
    char *t36;
    char *t38;
    char *t39;
    char *t40;
    char *t41;
    char *t42;
    char *t43;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    char *t49;
    char *t50;

LAB0:    xsi_set_current_line(64, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t1 = (t0 + 10189);
    t4 = 1;
    if (2U == 2U)
        goto LAB5;

LAB6:    t4 = 0;

LAB7:    if (t4 != 0)
        goto LAB3;

LAB4:    t15 = (t0 + 1512U);
    t16 = *((char **)t15);
    t15 = (t0 + 10195);
    t18 = 1;
    if (2U == 2U)
        goto LAB13;

LAB14:    t18 = 0;

LAB15:    if (t18 != 0)
        goto LAB11;

LAB12:    t29 = (t0 + 1512U);
    t30 = *((char **)t29);
    t29 = (t0 + 10201);
    t32 = 1;
    if (2U == 2U)
        goto LAB21;

LAB22:    t32 = 0;

LAB23:    if (t32 != 0)
        goto LAB19;

LAB20:
LAB27:    t43 = (t0 + 10207);
    t45 = (t0 + 5896);
    t46 = (t45 + 56U);
    t47 = *((char **)t46);
    t48 = (t47 + 56U);
    t49 = *((char **)t48);
    memcpy(t49, t43, 4U);
    xsi_driver_first_trans_fast(t45);

LAB2:    t50 = (t0 + 5624);
    *((int *)t50) = 1;

LAB1:    return;
LAB3:    t8 = (t0 + 10191);
    t10 = (t0 + 5896);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t8, 4U);
    xsi_driver_first_trans_fast(t10);
    goto LAB2;

LAB5:    t5 = 0;

LAB8:    if (t5 < 2U)
        goto LAB9;
    else
        goto LAB7;

LAB9:    t6 = (t2 + t5);
    t7 = (t1 + t5);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB6;

LAB10:    t5 = (t5 + 1);
    goto LAB8;

LAB11:    t22 = (t0 + 10197);
    t24 = (t0 + 5896);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    memcpy(t28, t22, 4U);
    xsi_driver_first_trans_fast(t24);
    goto LAB2;

LAB13:    t19 = 0;

LAB16:    if (t19 < 2U)
        goto LAB17;
    else
        goto LAB15;

LAB17:    t20 = (t16 + t19);
    t21 = (t15 + t19);
    if (*((unsigned char *)t20) != *((unsigned char *)t21))
        goto LAB14;

LAB18:    t19 = (t19 + 1);
    goto LAB16;

LAB19:    t36 = (t0 + 10203);
    t38 = (t0 + 5896);
    t39 = (t38 + 56U);
    t40 = *((char **)t39);
    t41 = (t40 + 56U);
    t42 = *((char **)t41);
    memcpy(t42, t36, 4U);
    xsi_driver_first_trans_fast(t38);
    goto LAB2;

LAB21:    t33 = 0;

LAB24:    if (t33 < 2U)
        goto LAB25;
    else
        goto LAB23;

LAB25:    t34 = (t30 + t33);
    t35 = (t29 + t33);
    if (*((unsigned char *)t34) != *((unsigned char *)t35))
        goto LAB22;

LAB26:    t33 = (t33 + 1);
    goto LAB24;

LAB28:    goto LAB2;

}

static void work_a_3192134911_1516540902_p_3(char *t0)
{
    char t5[16];
    char t7[16];
    char t12[16];
    char t13[16];
    char t23[16];
    char t25[16];
    char t30[16];
    char t37[16];
    char t44[16];
    char t46[16];
    char *t1;
    char *t3;
    char *t4;
    char *t6;
    char *t8;
    char *t9;
    int t10;
    unsigned int t11;
    char *t14;
    char *t15;
    char *t16;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    char *t24;
    char *t26;
    char *t27;
    int t28;
    unsigned int t29;
    char *t31;
    int t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t38;
    char *t39;
    char *t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    char *t45;
    char *t47;
    char *t48;
    int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned char t55;
    char *t56;
    char *t57;
    char *t58;
    char *t59;
    char *t60;
    char *t61;

LAB0:    xsi_set_current_line(68, ng0);

LAB3:    t1 = (t0 + 10211);
    t3 = (t0 + 1672U);
    t4 = *((char **)t3);
    t6 = ((IEEE_P_2592010699) + 4000);
    t8 = (t7 + 0U);
    t9 = (t8 + 0U);
    *((int *)t9) = 0;
    t9 = (t8 + 4U);
    *((int *)t9) = 0;
    t9 = (t8 + 8U);
    *((int *)t9) = 1;
    t10 = (0 - 0);
    t11 = (t10 * 1);
    t11 = (t11 + 1);
    t9 = (t8 + 12U);
    *((unsigned int *)t9) = t11;
    t9 = (t0 + 10000U);
    t3 = xsi_base_array_concat(t3, t5, t6, (char)97, t1, t7, (char)97, t4, t9, (char)101);
    t14 = (t0 + 2472U);
    t15 = *((char **)t14);
    t14 = (t0 + 10080U);
    t16 = (t0 + 10212);
    t18 = (t0 + 1992U);
    t19 = *((char **)t18);
    t11 = (6 - 6);
    t20 = (t11 * 1U);
    t21 = (0 + t20);
    t18 = (t19 + t21);
    t24 = ((IEEE_P_2592010699) + 4000);
    t26 = (t25 + 0U);
    t27 = (t26 + 0U);
    *((int *)t27) = 0;
    t27 = (t26 + 4U);
    *((int *)t27) = 0;
    t27 = (t26 + 8U);
    *((int *)t27) = 1;
    t28 = (0 - 0);
    t29 = (t28 * 1);
    t29 = (t29 + 1);
    t27 = (t26 + 12U);
    *((unsigned int *)t27) = t29;
    t27 = (t30 + 0U);
    t31 = (t27 + 0U);
    *((int *)t31) = 6;
    t31 = (t27 + 4U);
    *((int *)t31) = 4;
    t31 = (t27 + 8U);
    *((int *)t31) = -1;
    t32 = (4 - 6);
    t29 = (t32 * -1);
    t29 = (t29 + 1);
    t31 = (t27 + 12U);
    *((unsigned int *)t31) = t29;
    t22 = xsi_base_array_concat(t22, t23, t24, (char)97, t16, t25, (char)97, t18, t30, (char)101);
    t31 = ieee_p_2592010699_sub_16439767405979520975_503743352(IEEE_P_2592010699, t13, t15, t14, t22, t23);
    t33 = (t0 + 2632U);
    t34 = *((char **)t33);
    t33 = (t0 + 10096U);
    t35 = ieee_p_2592010699_sub_16439989832805790689_503743352(IEEE_P_2592010699, t12, t31, t13, t34, t33);
    t38 = ((IEEE_P_2592010699) + 4000);
    t36 = xsi_base_array_concat(t36, t37, t38, (char)97, t3, t5, (char)97, t35, t12, (char)101);
    t39 = (t0 + 1992U);
    t40 = *((char **)t39);
    t29 = (6 - 3);
    t41 = (t29 * 1U);
    t42 = (0 + t41);
    t39 = (t40 + t42);
    t45 = ((IEEE_P_2592010699) + 4000);
    t47 = (t46 + 0U);
    t48 = (t47 + 0U);
    *((int *)t48) = 3;
    t48 = (t47 + 4U);
    *((int *)t48) = 0;
    t48 = (t47 + 8U);
    *((int *)t48) = -1;
    t49 = (0 - 3);
    t50 = (t49 * -1);
    t50 = (t50 + 1);
    t48 = (t47 + 12U);
    *((unsigned int *)t48) = t50;
    t43 = xsi_base_array_concat(t43, t44, t45, (char)97, t36, t37, (char)97, t39, t46, (char)101);
    t50 = (1U + 2U);
    t48 = (t12 + 12U);
    t51 = *((unsigned int *)t48);
    t52 = (1U * t51);
    t53 = (t50 + t52);
    t54 = (t53 + 4U);
    t55 = (11U != t54);
    if (t55 == 1)
        goto LAB5;

LAB6:    t56 = (t0 + 5960);
    t57 = (t56 + 56U);
    t58 = *((char **)t57);
    t59 = (t58 + 56U);
    t60 = *((char **)t59);
    memcpy(t60, t43, 11U);
    xsi_driver_first_trans_fast(t56);

LAB2:    t61 = (t0 + 5640);
    *((int *)t61) = 1;

LAB1:    return;
LAB4:    goto LAB2;

LAB5:    xsi_size_not_matching(11U, t54, 0);
    goto LAB6;

}

static void work_a_3192134911_1516540902_p_4(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(69, ng0);

LAB3:    t1 = (t0 + 2152U);
    t2 = *((char **)t1);
    t1 = (t0 + 6024);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 11U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 5656);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3192134911_1516540902_p_5(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(70, ng0);

LAB3:    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 6088);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 5672);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3192134911_1516540902_p_6(char *t0)
{
    char t22[16];
    char t23[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned int t5;
    unsigned int t6;
    unsigned int t7;
    char *t8;
    char *t9;
    unsigned char t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned char t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    int t24;

LAB0:    xsi_set_current_line(73, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5688);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(74, ng0);
    t3 = (t0 + 1992U);
    t4 = *((char **)t3);
    t5 = (6 - 3);
    t6 = (t5 * 1U);
    t7 = (0 + t6);
    t3 = (t4 + t7);
    t8 = (t0 + 10213);
    t10 = 1;
    if (4U == 4U)
        goto LAB8;

LAB9:    t10 = 0;

LAB10:    if (t10 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(78, ng0);
    t1 = (t0 + 1992U);
    t3 = *((char **)t1);
    t5 = (6 - 3);
    t6 = (t5 * 1U);
    t7 = (0 + t6);
    t1 = (t3 + t7);
    t4 = (t23 + 0U);
    t8 = (t4 + 0U);
    *((int *)t8) = 3;
    t8 = (t4 + 4U);
    *((int *)t8) = 0;
    t8 = (t4 + 8U);
    *((int *)t8) = -1;
    t24 = (0 - 3);
    t11 = (t24 * -1);
    t11 = (t11 + 1);
    t8 = (t4 + 12U);
    *((unsigned int *)t8) = t11;
    t8 = ieee_p_1242562249_sub_1006216973935652998_1035706684(IEEE_P_1242562249, t22, t1, t23, 1);
    t9 = (t0 + 6152);
    t12 = (t9 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t8, 4U);
    xsi_driver_first_trans_delta(t9, 3U, 4U, 0LL);

LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(75, ng0);
    t14 = (t0 + 10217);
    t16 = (4U != 4U);
    if (t16 == 1)
        goto LAB14;

LAB15:    t17 = (t0 + 6152);
    t18 = (t17 + 56U);
    t19 = *((char **)t18);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t14, 4U);
    xsi_driver_first_trans_delta(t17, 3U, 4U, 0LL);
    xsi_set_current_line(76, ng0);
    t1 = (t0 + 1992U);
    t3 = *((char **)t1);
    t5 = (6 - 6);
    t6 = (t5 * 1U);
    t7 = (0 + t6);
    t1 = (t3 + t7);
    t4 = (t23 + 0U);
    t8 = (t4 + 0U);
    *((int *)t8) = 6;
    t8 = (t4 + 4U);
    *((int *)t8) = 4;
    t8 = (t4 + 8U);
    *((int *)t8) = -1;
    t24 = (4 - 6);
    t11 = (t24 * -1);
    t11 = (t11 + 1);
    t8 = (t4 + 12U);
    *((unsigned int *)t8) = t11;
    t8 = ieee_p_1242562249_sub_1006216973935652998_1035706684(IEEE_P_1242562249, t22, t1, t23, 1);
    t9 = (t0 + 6152);
    t12 = (t9 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t8, 3U);
    xsi_driver_first_trans_delta(t9, 0U, 3U, 0LL);
    goto LAB6;

LAB8:    t11 = 0;

LAB11:    if (t11 < 4U)
        goto LAB12;
    else
        goto LAB10;

LAB12:    t12 = (t3 + t11);
    t13 = (t8 + t11);
    if (*((unsigned char *)t12) != *((unsigned char *)t13))
        goto LAB9;

LAB13:    t11 = (t11 + 1);
    goto LAB11;

LAB14:    xsi_size_not_matching(4U, 4U, 0);
    goto LAB15;

}


extern void work_a_3192134911_1516540902_init()
{
	static char *pe[] = {(void *)work_a_3192134911_1516540902_p_0,(void *)work_a_3192134911_1516540902_p_1,(void *)work_a_3192134911_1516540902_p_2,(void *)work_a_3192134911_1516540902_p_3,(void *)work_a_3192134911_1516540902_p_4,(void *)work_a_3192134911_1516540902_p_5,(void *)work_a_3192134911_1516540902_p_6};
	xsi_register_didat("work_a_3192134911_1516540902", "isim/BigLookUp_tb_isim_beh.exe.sim/work/a_3192134911_1516540902.didat");
	xsi_register_executes(pe);
}
