#ifndef LCD_H
#define LCD_H
 
#define LCD_RS GPIO_PIN_5
#define LCD_RESET GPIO_PIN_6
#define CMD_RESET 0x01
#define CMD_MAC 0x36
#define CMD_WAKEUP 0x11
#define CMD_PALETTE 0x3A
#define CMD_ENABLE 0x29
#define CMD_SETX 0x2A
#define CMD_SETY 0x2B
#define CMD_DRAWSTART 0x2C

void send_cmd(uint8_t cmd,SPI_HandleTypeDef* spi);
void send_data(uint8_t data,SPI_HandleTypeDef* spi);
void reset_LCD(SPI_HandleTypeDef* spi);
void init_LCD(SPI_HandleTypeDef* spi);
void draw_start(SPI_HandleTypeDef* spi);
void set_draw_area(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,SPI_HandleTypeDef* spi);
#endif
