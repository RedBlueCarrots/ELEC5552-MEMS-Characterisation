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
static const char *ng0 = "/home/redbluecarrots/Documents/University/ELEC5552/ELEC5552-MEMS-Characterisation/fpga/DDS_Lookup/BigLookUp_tb.vhd";
extern char *IEEE_P_2592010699;
extern char *STD_TEXTIO;
extern char *IEEE_P_3564397177;
extern char *IEEE_P_1242562249;

int ieee_p_1242562249_sub_17802405650254020620_1035706684(char *, char *, char *);
unsigned char ieee_p_2592010699_sub_2763492388968962707_503743352(char *, char *, unsigned int , unsigned int );
void ieee_p_3564397177_sub_2250825304603680424_91900896(char *, char *, char *, char *, char *, unsigned char , int );
void ieee_p_3564397177_sub_2258168291854845616_91900896(char *, char *, char *, char *, char *, unsigned char , int );


static void work_a_2693927352_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    int64 t8;

LAB0:    t1 = (t0 + 3400U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(73, ng0);
    t2 = (t0 + 4376);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(74, ng0);
    t2 = (t0 + 2128U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 3208);
    xsi_process_wait(t2, t8);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(75, ng0);
    t2 = (t0 + 4376);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(76, ng0);
    t2 = (t0 + 2128U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 3208);
    xsi_process_wait(t2, t8);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}

static void work_a_2693927352_2372691052_p_1(char *t0)
{
    char *t1;
    char *t2;
    int64 t3;
    char *t4;
    int64 t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    t1 = (t0 + 3648U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(83, ng0);
    t3 = (100 * 1000LL);
    t2 = (t0 + 3456);
    xsi_process_wait(t2, t3);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(86, ng0);
    t2 = (t0 + 2128U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t5 = (t3 * 20);
    t2 = (t0 + 3456);
    xsi_process_wait(t2, t5);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    xsi_set_current_line(89, ng0);
    t2 = (t0 + 8161);
    t6 = (t0 + 4440);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 2U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(90, ng0);
    t2 = (t0 + 2128U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t5 = (t3 * 20);
    t2 = (t0 + 3456);
    xsi_process_wait(t2, t5);

LAB14:    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

LAB12:    xsi_set_current_line(93, ng0);
    t2 = (t0 + 8163);
    t6 = (t0 + 4440);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 2U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(94, ng0);
    t2 = (t0 + 8165);
    t6 = (t0 + 4504);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 2U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(95, ng0);
    t2 = (t0 + 2128U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t5 = (t3 * 40);
    t2 = (t0 + 3456);
    xsi_process_wait(t2, t5);

LAB18:    *((char **)t1) = &&LAB19;
    goto LAB1;

LAB13:    goto LAB12;

LAB15:    goto LAB13;

LAB16:    xsi_set_current_line(98, ng0);
    t2 = (t0 + 8167);
    t6 = (t0 + 4440);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 2U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(99, ng0);
    t2 = (t0 + 8169);
    t6 = (t0 + 4504);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 2U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(100, ng0);
    t2 = (t0 + 2128U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t5 = (t3 * 160);
    t2 = (t0 + 3456);
    xsi_process_wait(t2, t5);

LAB22:    *((char **)t1) = &&LAB23;
    goto LAB1;

LAB17:    goto LAB16;

LAB19:    goto LAB17;

LAB20:    xsi_set_current_line(103, ng0);
    if ((unsigned char)0 == 0)
        goto LAB24;

LAB25:    xsi_set_current_line(104, ng0);

LAB28:    *((char **)t1) = &&LAB29;
    goto LAB1;

LAB21:    goto LAB20;

LAB23:    goto LAB21;

LAB24:    t2 = (t0 + 8171);
    xsi_report(t2, 54U, (unsigned char)0);
    goto LAB25;

LAB26:    goto LAB2;

LAB27:    goto LAB26;

LAB29:    goto LAB27;

}

static void work_a_2693927352_2372691052_p_2(char *t0)
{
    char t9[16];
    char t16[8];
    char t17[8];
    char t18[16];
    char t19[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    char *t6;
    char *t7;
    char *t8;
    char *t10;
    char *t11;
    int t12;
    unsigned int t13;
    int64 t14;
    int64 t15;

LAB0:    xsi_set_current_line(112, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_2763492388968962707_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 4216);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(114, ng0);
    t3 = (t0 + 2248U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    if (t5 != 0)
        goto LAB5;

LAB7:
LAB6:    xsi_set_current_line(121, ng0);
    t1 = (t0 + 3704);
    t3 = (t0 + 2752U);
    t14 = xsi_get_sim_current_time();
    t15 = (1 * 1000LL);
    t12 = (t14 / t15);
    std_textio_write5(STD_TEXTIO, t1, t3, t12, (unsigned char)0, 0);
    xsi_set_current_line(122, ng0);
    t1 = (t0 + 3704);
    t3 = (t0 + 2752U);
    t4 = (t0 + 8288);
    t7 = (t9 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 1;
    t8 = (t7 + 4U);
    *((int *)t8) = 1;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t12 = (1 - 1);
    t13 = (t12 * 1);
    t13 = (t13 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t13;
    std_textio_write7(STD_TEXTIO, t1, t3, t4, t9, (unsigned char)0, 0);
    xsi_set_current_line(123, ng0);
    t1 = (t0 + 3704);
    t3 = (t0 + 2752U);
    t4 = (t0 + 1192U);
    t6 = *((char **)t4);
    memcpy(t16, t6, 2U);
    t4 = (t0 + 7960U);
    ieee_p_3564397177_sub_2250825304603680424_91900896(IEEE_P_3564397177, t1, t3, t16, t4, (unsigned char)0, 0);
    xsi_set_current_line(124, ng0);
    t1 = (t0 + 3704);
    t3 = (t0 + 2752U);
    t4 = (t0 + 8289);
    t7 = (t9 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 1;
    t8 = (t7 + 4U);
    *((int *)t8) = 1;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t12 = (1 - 1);
    t13 = (t12 * 1);
    t13 = (t13 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t13;
    std_textio_write7(STD_TEXTIO, t1, t3, t4, t9, (unsigned char)0, 0);
    xsi_set_current_line(125, ng0);
    t1 = (t0 + 3704);
    t3 = (t0 + 2752U);
    t4 = (t0 + 1352U);
    t6 = *((char **)t4);
    memcpy(t17, t6, 2U);
    t4 = (t0 + 7976U);
    ieee_p_3564397177_sub_2250825304603680424_91900896(IEEE_P_3564397177, t1, t3, t17, t4, (unsigned char)0, 0);
    xsi_set_current_line(126, ng0);
    t1 = (t0 + 3704);
    t3 = (t0 + 2752U);
    t4 = (t0 + 8290);
    t7 = (t9 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 1;
    t8 = (t7 + 4U);
    *((int *)t8) = 1;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t12 = (1 - 1);
    t13 = (t12 * 1);
    t13 = (t13 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t13;
    std_textio_write7(STD_TEXTIO, t1, t3, t4, t9, (unsigned char)0, 0);
    xsi_set_current_line(127, ng0);
    t1 = (t0 + 3704);
    t3 = (t0 + 2752U);
    t4 = (t0 + 1832U);
    t6 = *((char **)t4);
    memcpy(t18, t6, 11U);
    t4 = (t0 + 8008U);
    ieee_p_3564397177_sub_2258168291854845616_91900896(IEEE_P_3564397177, t1, t3, t18, t4, (unsigned char)0, 0);
    xsi_set_current_line(128, ng0);
    t1 = (t0 + 3704);
    t3 = (t0 + 2752U);
    t4 = (t0 + 8291);
    t7 = (t9 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 1;
    t8 = (t7 + 4U);
    *((int *)t8) = 1;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t12 = (1 - 1);
    t13 = (t12 * 1);
    t13 = (t13 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t13;
    std_textio_write7(STD_TEXTIO, t1, t3, t4, t9, (unsigned char)0, 0);
    xsi_set_current_line(129, ng0);
    t1 = (t0 + 3704);
    t3 = (t0 + 2752U);
    t4 = (t0 + 1672U);
    t6 = *((char **)t4);
    memcpy(t19, t6, 14U);
    t4 = (t0 + 7992U);
    ieee_p_3564397177_sub_2258168291854845616_91900896(IEEE_P_3564397177, t1, t3, t19, t4, (unsigned char)0, 0);
    xsi_set_current_line(130, ng0);
    t1 = (t0 + 3704);
    t3 = (t0 + 2752U);
    t4 = (t0 + 8292);
    t7 = (t9 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 1;
    t8 = (t7 + 4U);
    *((int *)t8) = 1;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t12 = (1 - 1);
    t13 = (t12 * 1);
    t13 = (t13 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t13;
    std_textio_write7(STD_TEXTIO, t1, t3, t4, t9, (unsigned char)0, 0);
    xsi_set_current_line(131, ng0);
    t1 = (t0 + 3704);
    t3 = (t0 + 2752U);
    t4 = (t0 + 1672U);
    t6 = *((char **)t4);
    t4 = (t0 + 7992U);
    t12 = ieee_p_1242562249_sub_17802405650254020620_1035706684(IEEE_P_1242562249, t6, t4);
    std_textio_write5(STD_TEXTIO, t1, t3, t12, (unsigned char)0, 0);
    xsi_set_current_line(134, ng0);
    t1 = (t0 + 3704);
    t3 = (t0 + 2576U);
    t4 = (t0 + 2752U);
    std_textio_writeline(STD_TEXTIO, t1, t3, t4);
    goto LAB3;

LAB5:    xsi_set_current_line(115, ng0);
    t3 = (t0 + 3704);
    t6 = (t0 + 2752U);
    t7 = (t0 + 8225);
    t10 = (t9 + 0U);
    t11 = (t10 + 0U);
    *((int *)t11) = 1;
    t11 = (t10 + 4U);
    *((int *)t11) = 63;
    t11 = (t10 + 8U);
    *((int *)t11) = 1;
    t12 = (63 - 1);
    t13 = (t12 * 1);
    t13 = (t13 + 1);
    t11 = (t10 + 12U);
    *((unsigned int *)t11) = t13;
    std_textio_write7(STD_TEXTIO, t3, t6, t7, t9, (unsigned char)0, 0);
    xsi_set_current_line(116, ng0);
    t1 = (t0 + 3704);
    t3 = (t0 + 2576U);
    t4 = (t0 + 2752U);
    std_textio_writeline(STD_TEXTIO, t1, t3, t4);
    xsi_set_current_line(117, ng0);
    t1 = (t0 + 2248U);
    t3 = *((char **)t1);
    t1 = (t3 + 0);
    *((unsigned char *)t1) = (unsigned char)0;
    goto LAB6;

}


extern void work_a_2693927352_2372691052_init()
{
	static char *pe[] = {(void *)work_a_2693927352_2372691052_p_0,(void *)work_a_2693927352_2372691052_p_1,(void *)work_a_2693927352_2372691052_p_2};
	xsi_register_didat("work_a_2693927352_2372691052", "isim/BigLookUp_tb_isim_beh.exe.sim/work/a_2693927352_2372691052.didat");
	xsi_register_executes(pe);
}
