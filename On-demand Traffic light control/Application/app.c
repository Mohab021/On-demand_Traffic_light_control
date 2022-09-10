#include "app.h"

void APP_start(void){
	/*  Step1: Configure D2 as Button input */
	/*  Step2: Configure A0, A1 and A2 as Car LEDs */
	/*  Step3: Configure B0, B1 and B2 as Pedestrian LEDs */
	/*  Step4: Start with Normal mode */
	/*  Step5: Still in Normal mode through while loop, from Green to Blink Yellow to Red to Blink Yellow again to Green and etc.. */
	/*  Step6: When button is pressed, INT0 will change mode to Pedestrian mode */
	/*  Step7: Start execution of Pedestrian mode through while loop according to the last state from Normal mode and go on until back to Normal mode again */
	
	BUTTON_interrupt(D, 2); //Step1
	LED_init(A, Green); //Step2
	LED_init(A, Yellow);
	LED_init(A, Red);
	LED_init(B, Green); //Step3
	LED_init(B, Yellow);
	LED_init(B, Red);
		
	Current_Mode = Normal; //Step4
		
	while (1)
	{
		//Normal Mode
		if(Current_Mode == Normal){ //Step5
			LED_on_time(A, Green, 5);
			Car_State = Green;
		}
		if(Current_Mode == Normal){
			LED_blink_time(A, Yellow, 5);
			Car_State = Yellow;
		}
		if(Current_Mode == Normal){
			LED_on_time(A, Red, 5);
			Car_State = Red;
		}
		if(Current_Mode == Normal){
			LED_blink_time(A, Yellow, 5);
			Car_State = Yellow;
		}
			
			
		//Pedestrian Mode
		if(Current_Mode == Pedestrian){ //Step7
			if(Car_State == Green){
				LED_on(B, Red);
				Car_State = Yellow; //Go to next case
			}
			if(Car_State == Yellow){
				LED_on(B, Red);
				LED_double_blink_time(A, 1, B, 1, 5);
				Car_State = Red; //Go to next case
			}
			if(Car_State == Red){
				LED_off(B, Red);
				LED_on(A, Red);
				LED_on_time(B, Green, 5);
				LED_on(B, Green);
				LED_off(A, Red);
				LED_double_blink_time(A, Yellow, B, Yellow, 5);
				LED_off(B, Green);
				LED_on(B, Red);
				Car_State = Green; //Back to Normal Mode
			}
			Current_Mode = Normal; //Change to Normal Mode
		}
	}
}

//Interrupt Service Routine for Interrupt 0 - INT0
ISR(INT0_vect) //Trigger when sensing rising edge on INT0
{
	//Change to Pedestrian Mode
	Current_Mode = Pedestrian; //Step6
}