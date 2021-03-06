#ifndef LCD_H
#define LCD_H

#ifdef __cplusplus
extern "C" {
#endif

#include "apb.h"

/* Standard LCD state */
typedef struct lcd_cntrl_state {
    uint32_t timing[4];

    uint32_t control;     /* Control register */
    uint32_t imsc;        /* Interrupt mask set/clear register */
    uint32_t mis;
    uint32_t ris;

    uint32_t upbase;        /* Upper panel frame base address register */
    uint32_t lpbase;        /* Lower panel frame base address register */
    uint32_t upcurr;        /* Upper panel current frame address register */
    uint32_t lpcurr;        /* Lower panel current frame address register */

    /* 256x16-bit color palette registers */
    /* 256 palette entries organized as 128 locations of two entries per word (+1 for sanitation) */
    uint16_t palette[0x101];


    /* Cursor image RAM registers (TODO) */
    /* 256-word wide values defining images overlaid by the hw cursor mechanism */
    int cursorimage[0x101];
    uint32_t crsrCtrl;           /* Cursor control register */
    uint32_t crsrConfig;         /* Cursor configuration register */
    uint32_t crsrPalette0;       /* Cursor palette registers */
    uint32_t crsrPalette1;
    uint32_t crsrXY;             /* Cursor XY position register */
    uint32_t crsrClip;           /* Cursor clip position register */
    uint32_t crsrimsc;           /* Cursor interrupt mask set/clear register */
    uint32_t crsricr;            /* Cursor interrupt clear register */
    uint32_t crsrris;            /* Cursor raw interrupt status register - const */
    uint32_t crsrmis;            /* Cursor masked interrupt status register - const */
} lcd_cntrl_state_t;

/* Global LCD state */
extern lcd_cntrl_state_t lcd;

/* Available Functions */
void lcd_reset(void);
eZ80portrange_t init_lcd(void);

void lcd_write(const uint16_t, const uint8_t);
uint8_t lcd_read(const uint16_t);
void lcd_drawframe(uint16_t *buffer, uint32_t *bitfields);

#ifdef __cplusplus
}
#endif

#endif
