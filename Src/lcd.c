#include <stdint.h>
#include "stm32f1xx_hal.h"
#include "lcd.h"

SPI_HandleTypeDef hspi1; // testing

void send_cmd(uint8_t cmd,SPI_HandleTypeDef* spi)
{
    HAL_GPIO_WritePin(GPIOB, LCD_RS,GPIO_PIN_RESET);
    HAL_Delay(5);
    HAL_SPI_Transmit(spi,&cmd,sizeof(cmd),50);
}
void send_data(uint8_t data,SPI_HandleTypeDef* spi)
{
    HAL_GPIO_WritePin(GPIOB, LCD_RS,GPIO_PIN_SET);
    HAL_Delay(5);
    HAL_SPI_Transmit(spi,&data,sizeof(data),50);
}
void reset_LCD(SPI_HandleTypeDef* spi)
{
    HAL_GPIO_WritePin(GPIOB, LCD_RESET,GPIO_PIN_RESET);
    HAL_Delay(20);
    HAL_GPIO_WritePin(GPIOB, LCD_RESET,GPIO_PIN_SET);
    HAL_Delay(20);
    send_cmd(CMD_RESET,spi);
}
void init_LCD(SPI_HandleTypeDef* spi)
{
	hspi1 = *spi;
    reset_LCD(spi);
	send_cmd(CMD_MAC,spi);
	send_data(0b00000000,spi);

	send_cmd(CMD_WAKEUP,spi);

	HAL_Delay(20);

	send_cmd(CMD_PALETTE,spi);
	send_data(0x05,spi);

	HAL_Delay(20);

	send_cmd(CMD_ENABLE,spi);
}
void draw_start(SPI_HandleTypeDef* spi)
{
	send_cmd(CMD_DRAWSTART,spi);
	HAL_GPIO_WritePin(GPIOB, LCD_RS,GPIO_PIN_SET);
}
void set_draw_area(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2,SPI_HandleTypeDef* spi)
{
    send_cmd(CMD_SETX,spi);
    send_data(x1,spi);
    send_data(x2,spi);

    send_cmd(CMD_SETY,spi);
    send_data(y1,spi);
    send_data(y2,spi);
}
