#ifndef LCD_H_
#define LCD_H_
#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"
#include "dio.h"

/* LCD Data bits mode configuration */
#define DATA_BITS_MODE 8

/* Use higher 4 bits in the data port */
#if (DATA_BITS_MODE == 4)
#define LOWER_PORT_PINS
#endif

/* LCD HW PINS */
#define LCD_DATA_PORT C
#define LCD_CTRL_PORT D

#define RS PD4
#define RW PD5
#define E  PD6

/* LCD COMMANDS */
#define CLEAR_COMMAND 0x01
#define FOUR_BITS_DATA_MODE 0x02
#define TWO_LINE_LCD_Four_BIT_MODE 0x28
#define TWO_LINE_LCD_Eight_BIT_MODE 0x38
#define CURSOR_OFF 0x0C
#define CURSOR_ON 0x0E
#define SET_CURSOR_LOCATION 0x80
/* Functions Prototypes*/
void LCD_sendCommand(uint8_t command);
void LCD_displayCharacter(uint8_t data);
void LCD_displayString(const uint8_t *Str);
void LCD_init(void);
void LCD_clearScreen(void);
void LCD_displayStringRowColumn(uint8_t row,uint8_t col,const uint8_t *Str);
void LCD_goToRowColumn(uint8_t row,uint8_t col);
void LCD_integerToString(uint32_t data);


#endif /* LCD_H_ */
