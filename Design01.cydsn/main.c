/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include "stdio.h"
void CapSense_DisplayState(void);

int main(void)
{
    char buffer[10];
    uint16_t value = 0;

    CyGlobalIntEnable; /* Enable global interrupts. */
    
    LCD_Char_1_Start();
    LCD_Char_1_Position(0u, 0u);
    
    LCD_Char_1_ClearDisplay();
    
    //LCD_Char_1_PrintString("Dziala");
    
    //sprintf(buffer, "%u", 0x8);
    //LCD_Char_1_PrintString(buffer);
    
    UART_Start();
    UART_UartPutString("Hello World\n\r");
    UART_UartPutString("dziala dziala\n\r");
    
    CapSense_1_Start();
    CapSense_1_EnableWidget(CapSense_1_PROXIMITYSENSOR0__PROX);
    UART_UartPutString("CapSense start\n\r");
    
    CapSense_1_InitializeAllBaselines();
    UART_UartPutString("InitializeAllBaselines\n\r");
    CapSense_1_ScanEnabledWidgets();
    
    PWM_1_Start();
    PWM_2_Start();
    
    UART_UartPutString("PWM_1_Start\n\r");
   
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        CapSense_1_ScanEnabledWidgets();
        
        while(CapSense_1_IsBusy() != 0) { }
        
        CapSense_DisplayState();

        CapSense_1_UpdateEnabledBaselines();
        /* Place your application code here. */
    }
}

void CapSense_DisplayState(void)
{
    static uint8_t previous_state;
    
    LCD_Char_1_Position(0u, 0u);
    
    if(CapSense_1_CheckIsWidgetActive(CapSense_1_BUTTON0__BTN))
    {
       PWM_1_WriteCompare(20); 
       LCD_Char_1_PrintString("Button_1");
       UART_UartPutString("Przycisk_1\n\r");
    
       PWM_2_WriteCompare(1700);
       CyDelay(100);
       PWM_2_WriteCompare(0); 
    }
    else if(CapSense_1_CheckIsWidgetActive(CapSense_1_BUTTON1__BTN))
    {
       PWM_1_WriteCompare(40);
       LCD_Char_1_PrintString("Button_2");
       UART_UartPutString("Przycisk_2\n\r");
    
       PWM_2_WriteCompare(1700);
       CyDelay(100);
       PWM_2_WriteCompare(0); 
    }
    else if(CapSense_1_CheckIsWidgetActive(CapSense_1_BUTTON2__BTN))
    {
       PWM_1_WriteCompare(60);
       LCD_Char_1_PrintString("Button_3");
       UART_UartPutString("Przycisk_3\n\r"); 
       
       PWM_2_WriteCompare(1700);
       CyDelay(100);
       PWM_2_WriteCompare(0); 
    
    }
    else if(CapSense_1_CheckIsWidgetActive(CapSense_1_BUTTON3__BTN))
    {
       PWM_1_WriteCompare(80); 
       LCD_Char_1_PrintString("Button_4");
       UART_UartPutString("Przycisk_4\n\r");
       
       PWM_2_WriteCompare(1700);
       CyDelay(100);
       PWM_2_WriteCompare(0); 
    }
    else if(CapSense_1_CheckIsWidgetActive(CapSense_1_BUTTON4__BTN))
    {
       PWM_1_WriteCompare(80); 
       LCD_Char_1_PrintString("Button_5");
       UART_UartPutString("Przycisk_5\n\r");
       
       PWM_2_WriteCompare(1700);
       CyDelay(100);
       PWM_2_WriteCompare(0); 
    }
    else if(CapSense_1_CheckIsWidgetActive(CapSense_1_BUTTON5__BTN))
    {
       PWM_1_WriteCompare(80); 
       LCD_Char_1_PrintString("Button_6");
       UART_UartPutString("Przycisk_6\n\r");
       
       PWM_2_WriteCompare(1700);
       CyDelay(100);
       PWM_2_WriteCompare(0); 
    }
    else if(CapSense_1_CheckIsWidgetActive(CapSense_1_BUTTON6__BTN))
    {
       PWM_1_WriteCompare(80); 
       LCD_Char_1_PrintString("Button_7");
       UART_UartPutString("Przycisk_7\n\r");
       
       PWM_2_WriteCompare(1700);
       CyDelay(100);
       PWM_2_WriteCompare(0); 
    }
    else if(CapSense_1_CheckIsWidgetActive(CapSense_1_BUTTON7__BTN))
    {
       PWM_1_WriteCompare(80); 
       LCD_Char_1_PrintString("Button_8");
       UART_UartPutString("Przycisk_8\n\r");
       
       PWM_2_WriteCompare(1700);
       CyDelay(100);
       PWM_2_WriteCompare(0); 
    }
    else if(CapSense_1_CheckIsWidgetActive(CapSense_1_PROXIMITYSENSOR0__PROX))
    {
       PWM_1_WriteCompare(80); 
       LCD_Char_1_PrintString("Proximity");
       UART_UartPutString("Proximity\n\r");
       
       PWM_2_WriteCompare(1700);
       CyDelay(100);
       PWM_2_WriteCompare(0);   
    }
    else
    {
       PWM_1_WriteCompare(0);
       PWM_2_WriteCompare(0);
       LCD_Char_1_ClearDisplay();
    }
}

/* [] END OF FILE */
