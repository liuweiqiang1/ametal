/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief RCC �����ӿ�
 *
 *  ����ֱ��ʹ���� ZLG116 ����Ĵ�������ַ�� ��ˣ��������������� ZLG116
 *
 * \internal
 * \par Modification history
 * - 1.00 17-04-11  sdy, first implementation
 * \endinternal
 */

#ifndef __AMHW_ZLG116_RCC_H
#define __AMHW_ZLG116_RCC_H

#include "am_types.h"
#include "zlg116_regbase.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * \brief �����ṹ��εĿ�ʼ
 */
#if defined(__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined(__ICCARM__)
  #pragma language=extended
#elif defined(__GNUC__)
#elif defined(__TMS470__)
#elif defined(__TASKING__)
  #pragma warning 586
#else
  #warning Not supported compiler t
#endif

/**
 * \addtogroup amhw_zlg116_if_rcc
 * \copydoc amhw_zlg116_rcc.h
 * @{
 */

/**
 * \brief CRC�Ĵ�����ṹ��
 */
typedef struct amhw_zlg116_rcc {
  __IO uint32_t cr;        /**< \brief ʱ�ӿ��ƼĴ��� */
  __IO uint32_t cfgr;      /**< \brief ʱ�����üĴ��� */
  __IO uint32_t cir;       /**< \brief ʱ���жϼĴ��� */
  __IO uint32_t apb2rstr;  /**< \brief APB2���踴λ�Ĵ��� */
  __IO uint32_t apb1rstr;  /**< \brief APB1���踴λ�Ĵ��� */
  __IO uint32_t ahbenr;    /**< \brief AHB����ʱ��ʹ�ܼĴ��� */
  __IO uint32_t apb2enr;   /**< \brief APB2����ʱ��ʹ�ܼĴ��� */
  __IO uint32_t apb1enr;   /**< \brief APB1����ʱ��ʹ�ܼĴ��� */
  __IO uint32_t bdcr;      /**< \brief ���ұ��� */
  __IO uint32_t csr;       /**< \brief ����״̬�Ĵ��� */
} amhw_zlg116_rcc_t;

/**
 * \brief ����ֱ��ʹ���� ZLG116 ����Ĵ�������ַ�� ��ˣ��������������� ZLG116
 */
#ifndef ZLG116_RCC
#define ZLG116_RCC     ((amhw_zlg116_rcc_t *)ZLG116_RCC_BASE)
#endif

/**
 * \brief ϵͳʱ��Դ
 */
typedef enum {
    AMHW_ZLG116_SYSCLK_HSI_DIV6,  /**< \brief HSI ����  6 ��Ƶ��Ϊϵͳʱ�� */
    AMHW_ZLG116_SYSCLK_HSE,       /**< \brief HSE ��Ϊϵͳʱ�� */
    AMHW_ZLG116_SYSCLK_PLL,       /**< \brief PLL �����Ϊϵͳʱ�� */
    AMHW_ZLG116_SYSCLK_LSI,       /**< \brief LSI �����Ϊϵͳʱ�� */
}amhw_zlg116_sys_clk_src;

/**
 * \brief PLLʱ��Դ
 */
typedef enum {
    AMHW_ZLG116_PLLCLK_HSI_DIV4,  /**< \brief HSI ����  4 ��Ƶ��ΪPLL����ʱ�� */
    AMHW_ZLG116_PLLCLK_HSE,       /**< \brief HSE ��ΪPLL����ʱ�� */
}amhw_zlg116_pll_clk_src;

/**
 * \brief ʱ���жϱ�־
 */
typedef enum {
    AMHW_ZLG116_CLKINT_INDEX_LSI = 0,  /**< \brief LSI��־ */
    AMHW_ZLG116_CLKINT_INDEX_HSI = 2,  /**< \brief HSI��־ */
    AMHW_ZLG116_CLKINT_INDEX_HSE,      /**< \brief HSE��־ */
    AMHW_ZLG116_CLKINT_INDEX_PLL,      /**< \brief PLL��־ */
    AMHW_ZLG116_CLKINT_INDEX_CSS = 7,  /**< \brief CSS(ʱ�Ӱ�ȫϵͳ�ж�)��־ */
}amhw_zlg116_clk_int_index;

/**
 * \brief APB2����ö��
 */
typedef enum {
    AMHW_ZLG116_RCC_APB2_SYSCFG = 0,  /**< \brief ϵͳ���üĴ��� */
    AMHW_ZLG116_RCC_APB2_ADC1   = 9,  /**< \brief ADC1�ӿ� */
    AMHW_ZLG116_RCC_APB2_TIM1   = 11, /**< \brief TIM1��ʱ�� */
    AMHW_ZLG116_RCC_APB2_SPI1   = 12, /**< \brief SPI1 */
    AMHW_ZLG116_RCC_APB2_UART1  = 14, /**< \brief UART1 */
    AMHW_ZLG116_RCC_APB2_CPT    = 15, /**< \brief �Ƚ��� */
    AMHW_ZLG116_RCC_APB2_TIM14  = 16, /**< \brief TIM14 */
    AMHW_ZLG116_RCC_APB2_TIM16  = 17, /**< \brief TIM16 */
    AMHW_ZLG116_RCC_APB2_TIM17  = 18, /**< \brief TIM17 */
    AMHW_ZLG116_RCC_APB2_DBGMCU = 22, /**< \brief DBGMCU */
}amhw_zlg116_apb2_peripheral;

/**
 * \brief APB1����ö��
 */
typedef enum {
    AMHW_ZLG116_RCC_APB1_TIM2   = 0,   /**< \brief TIM2��ʱ�� */
    AMHW_ZLG116_RCC_APB1_TIM3   = 1,   /**< \brief TIM3��ʱ�� */
    AMHW_ZLG116_RCC_APB1_WWDG   = 11,  /**< \brief WWDG���ڿ��Ź� */
    AMHW_ZLG116_RCC_APB1_SPI2   = 14,  /**< \brief SPI2 */
    AMHW_ZLG116_RCC_APB1_UART2  = 17,  /**< \brief UART2 */
    AMHW_ZLG116_RCC_APB1_I2C1   = 21,  /**< \brief I2C1 */
    AMHW_ZLG116_RCC_APB1_USB    = 23,  /**< \brief USB */
    AMHW_ZLG116_RCC_APB1_CAN    = 25,  /**< \brief CAN */
    AMHW_ZLG116_RCC_APB1_CRS    = 27,  /**< \brief CRS */
    AMHW_ZLG116_RCC_APB1_PWR    = 28,  /**< \brief ��Դ�ӿ� */
}amhw_zlg116_apb1_peripheral;

/**
 * \brief AHB����ö��
 */
typedef enum {
    AMHW_ZLG116_RCC_AHB_DMA   = 0,   /**< \brief DMA */
    AMHW_ZLG116_RCC_AHB_SRAM  = 2,   /**< \brief SRAM */
    AMHW_ZLG116_RCC_AHB_FLITF = 4,   /**< \brief FLITF */
    AMHW_ZLG116_RCC_AHB_AES   = 7,   /**< \brief AES */
    AMHW_ZLG116_RCC_AHB_GPIOA = 17,  /**< \brief GPIOA */
    AMHW_ZLG116_RCC_AHB_GPIOB = 18,  /**< \brief GPIOB */
    AMHW_ZLG116_RCC_AHB_GPIOC = 19,  /**< \brief GPIOC */
    AMHW_ZLG116_RCC_AHB_GPIOD = 20,  /**< \brief GPIOD */
}amhw_zlg116_ahb_peripheral;

/**
 * \brief ��λ��־ö��
 */
typedef enum { 
    AMHW_ZLG116_RCC_AHB_PINRSTF   = (1ul << 26),      /**< \brief NRST�ܽŸ�λ��־ */
    AMHW_ZLG116_RCC_AHB_PORRSTF   = (1ul << 27),      /**< \brief �ϵ�/���縴λ��־ */
    AMHW_ZLG116_RCC_AHB_SFTRSTF   = (1ul << 28),      /**< \brief ������λ��־ */
    AMHW_ZLG116_RCC_AHB_IWDGRSTF  = (1ul << 29),      /**< \brief �������Ź���λ��־ */
    AMHW_ZLG116_RCC_AHB_WWDGRSTF  = (1ul << 30),      /**< \brief ���ڿ��Ź���λ��־ */
    AMHW_ZLG116_RCC_AHB_LPWRRSTF  = (int)(1ul << 31), /**< \brief �͹��Ĺ�����λ��־ */
}amhw_zlg116_reset_flag_t;

/**
 * \brief �ڲ�����ʱ��ʹ��
 *
 * \return ��
 *
 */
am_static_inline
void amhw_zlg116_rcc_hsion_enable (void)
{
    ZLG116_RCC->cr |= 1ul;
}

/**
 * \brief �ڲ�����ʱ�ӽ���
 *
 * \return ��
 *
 */
am_static_inline
void amhw_zlg116_rcc_hsion_disable (void)
{
    ZLG116_RCC->cr &= ~1ul;
}

/**
 * \brief �ڲ�����ʱ�Ӿ�����־��ȡ
 *
 * \retval TRUE  : �ڲ� 8MHzʱ��û�о���
 * \retval FALSE : �ڲ� 8MHzʱ�Ӿ���
 */
am_static_inline
am_bool_t amhw_zlg116_rcc_hsirdy_read (void)
{
    return (am_bool_t)((ZLG116_RCC->cr & 0x2ul) ? AM_TRUE : AM_FALSE);
}

/**
 * \brief �ڲ�����ʱ��(48MHz)�¶�У׼ʹ��
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_hsiten_enable (void)
{
    ZLG116_RCC->cr |= (1ul << 2);
}

/**
 * \brief �ⲿ����ʱ��(HSE ����)ʹ��
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_hseon_enable (void)
{
    ZLG116_RCC->cr |= (1ul << 16);
}

/**
 * \brief �ⲿ����ʱ�Ӿ�����־��ȡ
 *
 * \retval TRUE  : �ⲿʱ��û�о���
 * \retval FALSE : �ⲿʱ�Ӿ���
 */
am_static_inline
am_bool_t amhw_zlg116_rcc_hserdy_read (void)
{
    return (am_bool_t)((ZLG116_RCC->cr & (1ul << 17)) ? AM_TRUE : AM_FALSE);
}

/**
 * \brief �ⲿ����ʱ����·ʹ��
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_hsebyp_enable (void)
{
    ZLG116_RCC->cr |= (1ul << 18);
}

/**
 * \brief ʱ�Ӱ�ȫϵͳʹ��
 *
 * \details ����ⲿ 8-24MHz����������ʱ�Ӽ����������
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_ccson_enable (void)
{
    ZLG116_RCC->cr |= (1ul << 19);
}

/**
 * \brief PLL��Ƶϵ������
 *
 * \param[in]  div ����Ƶֵ
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_plldm_set (uint8_t div)
{

    ZLG116_RCC->cr = ((div & 0x7ul) << 20) |
                            (ZLG116_RCC->cr & ~(0x7ul << 20));
}

/**
 * \brief PLL��Ƶϵ������
 *
 * \param[in]  mul ����Ƶֵ
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_plldn_set (uint8_t mul)
{

    ZLG116_RCC->cr = ((mul & 0x3ful) << 26) |
                            (ZLG116_RCC->cr & ~(0x3ful << 26));
}

/**
 * \brief PLL ʹ��
 *
 * \details �����������ֹͣģʽʱ����λ��Ӳ�����㡣
 *          �� PLL ʱ�ӱ�������ѡ��Ҫ��Ϊϵͳʱ��ʱ,
 *          ��λ���ܱ����㡣
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_pll_enable (void)
{
    ZLG116_RCC->cr |= (1ul << 24);
}

/**
 * \brief PLL ����
 *
 * \details �����������ֹͣģʽʱ����λ��Ӳ�����㡣
 *          �� PLL ʱ�ӱ�������ѡ��Ҫ��Ϊϵͳʱ��ʱ,
 *          ��λ���ܱ����㡣
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_pll_disable (void)
{
    ZLG116_RCC->cr &= ~(1ul << 24);
}

/**
 * \brief PLL ʱ�Ӿ�����־��ȡ
 *
 * \retval TRUE  : PLL δ����
 * \retval FALSE : PLL ����
 */
am_static_inline
am_bool_t amhw_zlg116_rcc_pllrdy_read (void)
{
    return (am_bool_t)((ZLG116_RCC->cr & (1ul << 25)) ? AM_TRUE : AM_FALSE);
}

/**
 * \brief ϵͳʱ���л�
 *
 * \param[in]  src ��ϵͳʱ��Դ
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_sys_clk_set (amhw_zlg116_sys_clk_src src)
{

    ZLG116_RCC->cfgr = ((src & 0x3ul) << 0) |
                              (ZLG116_RCC->cfgr & ~(0x3ul << 0));
}

/**
 * \brief ��ǰϵͳʱ�ӻ�ȡ
 *
 * \return ��ǰϵͳʱ��Դ
 */
am_static_inline
amhw_zlg116_sys_clk_src amhw_zlg116_rcc_sys_clk_get (void)
{

    return (amhw_zlg116_sys_clk_src)((ZLG116_RCC->cfgr >> 2ul) & 0x3ul);
}

/**
 * \brief ����AHB Ԥ��Ƶ
 *
 * \param[in]  div ��Ԥ��Ƶֵ
 *
 *       - 0-7 �� ����Ƶ
 *       - 8   �� 2��Ƶ
 *       - 9   �� 4��Ƶ
 *       - 10  �� 8��Ƶ
 *       - 11  �� 16��Ƶ
 *       - 12  �� 64��Ƶ
 *       - 13  �� 128��Ƶ
 *       - 14  �� 256��Ƶ
 *       - 15  �� 512��Ƶ
 *
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_ahb_div_set (uint8_t div)
{

    ZLG116_RCC->cfgr = ((div & 0xful) << 4) |
                              (ZLG116_RCC->cfgr & ~(0xful << 4));
}

/**
 * \brief ���� ���� APB Ԥ��Ƶ��APB1��
 *
 * \param[in]  div ��Ԥ��Ƶֵ
 *
 *       - 0-3 �� ����Ƶ
 *       - 4   �� 2��Ƶ
 *       - 5   �� 4��Ƶ
 *       - 6   �� 8��Ƶ
 *       - 7   �� 16��Ƶ
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_apb1_div_set (uint8_t div)
{

    ZLG116_RCC->cfgr = ((div & 0x7ul) << 8) |
                              (ZLG116_RCC->cfgr & ~(0x7ul << 8));
}

/**
 * \brief ��ȡ ���� APB Ԥ��Ƶ��APB1��
 *
 * \return Ԥ��Ƶֵ
 *       - 0-3 �� ����Ƶ
 *       - 4   �� 2��Ƶ
 *       - 5   �� 4��Ƶ
 *       - 6   �� 8��Ƶ
 *       - 7   �� 16��Ƶ
 */
am_static_inline
uint8_t amhw_zlg116_rcc_apb1_div_get (void)
{

    return (uint8_t)((ZLG116_RCC->cfgr >> 8) & 0x7ul);
}

/**
 * \brief ���� ���� APB Ԥ��Ƶ��APB2��
 *
 * \param[in]  div ��Ԥ��Ƶֵ
 *
 *       - 0-3 �� ����Ƶ
 *       - 4   �� 2��Ƶ
 *       - 5   �� 4��Ƶ
 *       - 6   �� 8��Ƶ
 *       - 7   �� 16��Ƶ
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_apb2_div_set (uint8_t div)
{

    ZLG116_RCC->cfgr = ((div & 0x7ul) << 11) |
                              (ZLG116_RCC->cfgr & ~(0x7ul << 11));
}

/**
 * \brief ��ȡ ���� APB Ԥ��Ƶ��APB2��
 *
 * \return Ԥ��Ƶֵ
 *       - 0-3 �� ����Ƶ
 *       - 4   �� 2��Ƶ
 *       - 5   �� 4��Ƶ
 *       - 6   �� 8��Ƶ
 *       - 7   �� 16��Ƶ
 */
am_static_inline
uint8_t amhw_zlg116_rcc_apb2_div_get (void)
{

    return (uint8_t)((ZLG116_RCC->cfgr >> 11) & 0x7ul);
}

/**
 * \brief PLL����ʱ��ѡ��
 *
 * \param[in]  src ��PLL����ʱ��Դ
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_pll_clk_set (amhw_zlg116_pll_clk_src src)
{

    ZLG116_RCC->cfgr = ((src & 0x3ul) << 16) |
                              (ZLG116_RCC->cfgr & ~(0x3ul << 16));
}

/**
 * \brief ��ǰPLL����ʱ�ӻ�ȡ
 *
 * \return ��ǰPLL����ʱ��Դ
 */
am_static_inline
amhw_zlg116_pll_clk_src amhw_zlg116_rcc_pll_clk_get (void)
{

    return (amhw_zlg116_pll_clk_src)((ZLG116_RCC->cfgr >> 16ul) & 0x3ul);
}

/**
 * \brief ѡ�� HSE ��Ƶ����Ϊ PLL ����
 *
 * \param[in]  div ����Ƶֵ
 *
 *      - 0  �� ����Ƶ
 *      - 1  �� 2��Ƶ
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_hseforpll_set (uint8_t div)
{

    ZLG116_RCC->cfgr = ((div & 0x1ul) << 17) |
                              (ZLG116_RCC->cfgr & ~(0x1ul << 17));
}

/**
 * \brief ѡ�� USB Ԥ��Ƶ
 *
 * \param[in]  div ����Ƶֵ
 *
 *      - 0  �� PLL ʱ��ֱ����Ϊ USB ʱ��
 *      - 1  �� PLL ʱ��2 ��Ƶ��Ϊ USBʱ��
 *      - 2  �� PLL ʱ��3 ��Ƶ��Ϊ USBʱ��
 *      - 3  �� PLL ʱ��4 ��Ƶ��Ϊ USBʱ��
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_pllforusb_set (uint8_t div)
{

    ZLG116_RCC->cfgr = ((div & 0x3ul) << 22) |
                              (ZLG116_RCC->cfgr & ~(0x3ul << 22));
}

/**
 * \brief USB Ԥ��Ƶ��ȡ
 *
 * \retval  0  �� PLL ʱ��ֱ����Ϊ USB ʱ��
 * \retval  1  �� PLL ʱ��2 ��Ƶ��Ϊ USBʱ��
 * \retval  2  �� PLL ʱ��3 ��Ƶ��Ϊ USBʱ��
 * \retval  3  �� PLL ʱ��4 ��Ƶ��Ϊ USBʱ��
 */
am_static_inline
uint8_t amhw_zlg116_rcc_pllforusb_get (void)
{

    return (uint8_t)((ZLG116_RCC->cfgr >> 22ul) & 0x3ul);
}

/**
 * \brief ΢������ʱ�����ѡ��
 *
 * \details 1.��ʱ��������������л� MCO ʱ��Դʱ���ܻᱻ�ض�,
 *          2.��ϵͳʱ����Ϊ����� MCO �ܽ�ʱ���뱣֤���ʱ��Ƶ
 *            �ʲ����� 50MHz��IO�����Ƶ�ʣ�
 *
 * \param[in]  src ��ʱ��Դ
 *
 *      - 0-1 �� û��ʱ�����
 *      - 2   �� LSI ʱ�����
 *      - 3   �� ����
 *      - 4   �� ϵͳʱ�ӣ�SYSCLK�����
 *      - 5   �� HSI ʱ�����
 *      - 6   �� HSE ʱ�����
 *      - 7   �� PLL ʱ��2 ��Ƶ�����
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_mco_src_set (uint8_t src)
{

    ZLG116_RCC->cfgr = ((src & 0x7ul) << 24ul) |
                              (ZLG116_RCC->cfgr & ~(0x7ul << 24ul));
}

/**
 * \brief �����ж�ʹ��
 *
 * \param[in]  index ��������־
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_clkint_enable (amhw_zlg116_clk_int_index index)
{

    ZLG116_RCC->cir |= ((index & 0x1Dul) << 8);
}

/**
 * \brief �����жϽ���
 *
 * \param[in]  index ��������־
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_clkint_disable (amhw_zlg116_clk_int_index index)
{

    ZLG116_RCC->cir &= ~((index & 0x1Dul) << 8);
}

/**
 * \brief ��ȡ�жϱ�־
 *
 * \return �жϱ�־
 */
am_static_inline
amhw_zlg116_clk_int_index amhw_zlg116_rcc_clkint_flag_read (void)
{

    return (amhw_zlg116_clk_int_index)(ZLG116_RCC->cir & 0x9Dul);
}

/**
 * \brief ����жϱ�־
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_clkint_flag_clear (amhw_zlg116_clk_int_index index)
{

    ZLG116_RCC->cir |= ((index & 0x9Dul) << 16);
}

/**
 * \brief ��λAPB2����
 *
 * \param[in]  reset ����Ҫ��λ������
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_apb2_reset (amhw_zlg116_apb2_peripheral reset)
{

    ZLG116_RCC->apb2rstr |= (1ul << reset);
}

/**
 * \brief ֹͣ��λAPB2����
 *
 * \param[in]  reset ����Ҫ��λ������
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_apb2_reset_stop (amhw_zlg116_apb2_peripheral reset)
{

    ZLG116_RCC->apb2rstr &= ~(1ul << reset);
}

/**
 * \brief ��λAPB1����
 *
 * \param[in]  reset ����Ҫ��λ������
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_apb1_reset (amhw_zlg116_apb1_peripheral reset)
{

    ZLG116_RCC->apb1rstr |= (1ul << reset);
}

/**
 * \brief ֹͣ��λAPB1����
 *
 * \param[in]  reset ����Ҫ��λ������
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_apb1_reset_stop (amhw_zlg116_apb1_peripheral reset)
{

    ZLG116_RCC->apb1rstr &= ~(1ul << reset);
}

/**
 * \brief ʹ��APB1����
 *
 * \param[in]  peri ����Ҫʹ�ܵ�����
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_apb1_enable (amhw_zlg116_apb1_peripheral peri)
{

    ZLG116_RCC->apb1enr |= (1ul << peri);
}

/**
 * \brief ����APB1����
 *
 * \param[in]  peri ����Ҫ���ܵ�����
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_apb1_disable (amhw_zlg116_apb1_peripheral peri)
{

    ZLG116_RCC->apb1enr &= ~(1ul << peri);
}

/**
 * \brief ʹ��APB2����
 *
 * \param[in]  peri ����Ҫʹ�ܵ�����
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_apb2_enable (amhw_zlg116_apb2_peripheral peri)
{

    ZLG116_RCC->apb2enr |= (1ul << peri);
}

/**
 * \brief ����APB2����
 *
 * \param[in]  peri ����Ҫ���ܵ�����
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_apb2_disable (amhw_zlg116_apb2_peripheral peri)
{

    ZLG116_RCC->apb2enr &= ~(1ul << peri);
}

/**
 * \brief ʹ��AHB����
 *
 * \param[in]  peri ����Ҫʹ�ܵ�����
 *
 * \return ��
 */
void amhw_zlg116_rcc_ahb_enable (amhw_zlg116_ahb_peripheral peri);

/**
 * \brief ����AHB����
 *
 * \param[in]  peri ����Ҫ���ܵ�����
 *
 * \return ��
 *
 */
void amhw_zlg116_rcc_ahb_disable (amhw_zlg116_ahb_peripheral peri);

/**
 * \brief ʹ��LSI
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_lsi_enable (void)
{

    ZLG116_RCC->csr |= (1ul << 0);
}

/**
 * \brief ����LSI
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_lsi_disable (void)
{

    ZLG116_RCC->csr &= ~(1ul << 0);
}

/**
 * \brief �ڲ�����ʱ�Ӿ�����־��ȡ
 *
 * \retval TRUE  : �ڲ� 40kHz ����ʱ�Ӿ���
 * \retval FALSE : �ڲ� 40kHz ����ʱ��δ����
 */
am_static_inline
am_bool_t amhw_zlg116_rcc_lsirdy_read (void)
{
    return (am_bool_t)((ZLG116_RCC->csr & (1ul << 1)) ? AM_TRUE : AM_FALSE);
}

/**
 * \brief ��ȡ��λ��־
 *
 * \return ��λ��־
 */
am_static_inline
amhw_zlg116_reset_flag_t amhw_zlg116_rcc_reset_flag (void)
{

    return (amhw_zlg116_reset_flag_t)(ZLG116_RCC->csr & 0xfc000000);
}

/**
 * \brief �����λ��־
 *
 * \return ��
 */
am_static_inline
void amhw_zlg116_rcc_reset_flag_clear (void)
{

    ZLG116_RCC->csr |= (1ul << 24);
}

/**
 * @}
 */
/*
 * \brief �����ṹ��εĽ���
 */

#if defined(__CC_ARM)
  #pragma pop
#elif defined(__ICCARM__)
#elif defined(__GNUC__)
#elif defined(__TMS470__)
#elif defined(__TASKING__)
  #pragma warning restore
#else
  #warning Not supported compiler t
#endif

#ifdef __cplusplus
}
#endif /* __AMHW_ZLG116_RCC_H */

#endif

/* end of file */