#include <i2c_lcd.h>
#include <stdio.h>
#include <string.h>

I2C_HandleTypeDef hi2c1;

int main(void){
    /*
        HAL INIT code
       */
    char buffer[100] = {0};
    uint64_t count = 0;

    I2C_LCD_HandleTypeDef hi2clcd1;
    hi2clcd1.hi2c = &hi2c1;
    hi2clcd1.i2c_addr = 0x27;
    hi2clcd1.backlight = true;
    hi2clcd1.col_count = 16;
    hi2clcd1.row_count = 2;

    lcd_init(&hi2clcd1);
    lcd_set_cursor(&hi2clcd1, 0, 0);

    while (1){
        sprintf(buffer, "%ld", count++);
        lcd_clear(&hi2clcd1);
        lcd_write_string(&hi2clcd1, buffer);
        HAL_Delay(200);
    }
}

