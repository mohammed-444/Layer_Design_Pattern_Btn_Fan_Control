 /******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.c
 *
 * Description: Source file for the AVR GPIO driver
 *
 * Author: Mohammed Alaa
 *
 *******************************************************************************/

#include "gpio.h"
/*
 * Description :
 * configure every pin in the gpio.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_Init(const GPIO_ConfigType GPIO_ConfigPtr[])
{
    uint8 i = 0;
    for (; i < TOTAL_PINS_NUM; ++i)
    {
	if(((GPIO_ConfigPtr[i].pin_num) >= NUM_OF_PINS_PER_PORT) || ((GPIO_ConfigPtr[i].port_num )>= NUM_OF_PORTS) )
	 {
		/* Do Nothing */
	}
	else
	{

		GPIO_setupPinDirection(GPIO_ConfigPtr[i].port_num, GPIO_ConfigPtr[i].pin_num, GPIO_ConfigPtr[i].direction);

		GPIO_writePin(GPIO_ConfigPtr[i].port_num, GPIO_ConfigPtr[i].pin_num, GPIO_ConfigPtr[i].initial_value);


		if(GPIO_ConfigPtr[i].resistor == GPIO_PULL_UP)
		{
			GPIO_writePin(GPIO_ConfigPtr[i].port_num, GPIO_ConfigPtr[i].pin_num,LOGIC_HIGH);
		}
		else
		{

		}
	}
}
}
/*
 *  Description :
 *  write in a group of of pin
 */
void GPIO_ChannelGroupWrite(ChannelGroupType* ChannelID ,uint8 dataPtr[]){
    uint8 i = 0;
    uint8 id=0;
    uint8 port_num=0;
    uint8 pin_num=0;
	for(; i < ChannelID->no_of_channels; ++i)
	{
	    id= ChannelID->group_ids[i];
	    port_num = GPIO_ConfigPin[id].port_num;
	    pin_num=GPIO_ConfigPin[id].pin_num;

		if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS) )
		{
			/* Do Nothing */
		}
		else
		{


			GPIO_writePin(port_num, pin_num,dataPtr[i]);

		}
	}
}
/*
 *  Description :
 *  read in a group of of pin
 */
void GPIO_ChannelGroupRead(ChannelGroupType* ChannelID,uint8 dataPtr[]){
    uint8 i = 0;
    uint8 id=0;
    uint8 port_num=0;
    uint8 pin_num=0;
	for(; i < ChannelID->no_of_channels; ++i)
	{
		id= ChannelID->group_ids[i];
		port_num = GPIO_ConfigPin[id].port_num;
		pin_num=GPIO_ConfigPin[id].pin_num;

		if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS) )
		{
			/* Do Nothing */
		}
		else
		{

			if(GPIO_readPin(port_num, pin_num) == LOGIC_HIGH)
			{
				_delay_ms((double)30);
				if(GPIO_readPin(port_num, pin_num) == LOGIC_HIGH)
				{
				dataPtr[i] = GPIO_readPin(port_num, pin_num);
				}
			}
			else if(GPIO_readPin(port_num, pin_num) == LOGIC_LOW)
			{
				_delay_ms((double)30);
				if(GPIO_readPin(port_num, pin_num) == LOGIC_LOW)
				{
				dataPtr[i] = GPIO_readPin(port_num, pin_num);
				}
			}
			else
			{

			}

		}
	}
}


/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the pin direction as required */
		switch(port_num)
		{
		case PORTA_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRA,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRA,pin_num);
			}
			break;
		case PORTB_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRB,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRB,pin_num);
			}
			break;
		case PORTC_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRC,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRC,pin_num);
			}
			break;
		case PORTD_ID:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRD,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRD,pin_num);
			}
			break;
		default:
		    break;
		}
	}
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Write the pin value as required */
		switch(port_num)
		{
		case PORTA_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTA,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTA,pin_num);
			}
			break;
		case PORTB_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTB,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTB,pin_num);
			}
			break;
		case PORTC_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTC,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTC,pin_num);
			}
			break;
		case PORTD_ID:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTD,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTD,pin_num);
			}
			break;
		default:
		            break;
		}
	}
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)
{
	uint8 pin_value = LOGIC_LOW;

	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		/* Do Nothing */
	}
	else
	{
		/* Read the pin value as required */
		switch(port_num)
		{
		case PORTA_ID:
			if(BIT_IS_SET(PINA,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTB_ID:
			if(BIT_IS_SET(PINB,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTC_ID:
			if(BIT_IS_SET(PINC,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case PORTD_ID:
			if(BIT_IS_SET(PIND,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		default:
		            break;
		}
	}

	return pin_value;
}

/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the port direction as required */
		switch(port_num)
		{
		case PORTA_ID:
			DDRA = direction;
			break;
		case PORTB_ID:
			DDRB = direction;
			break;
		case PORTC_ID:
			DDRC = direction;
			break;
		case PORTD_ID:
			DDRD = direction;
			break;
		default:
		            break;
		}
	}
}

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
void GPIO_writePort(uint8 port_num, uint8 value)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Write the port value as required */
		switch(port_num)
		{
		case PORTA_ID:
			PORTA = value;
			break;
		case PORTB_ID:
			PORTB = value;
			break;
		case PORTC_ID:
			PORTC = value;
			break;
		case PORTD_ID:
			PORTD = value;
			break;
		default:
		            break;
		}
	}
}

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 GPIO_readPort(uint8 port_num)
{
	uint8 value = LOGIC_LOW;

	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num >= NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Read the port value as required */
		switch(port_num)
		{
		case PORTA_ID:
			value = PINA;
			break;
		case PORTB_ID:
			value = PINB;
			break;
		case PORTC_ID:
			value = PINC;
			break;
		case PORTD_ID:
			value = PIND;
			break;
		default:
		            break;
		}
	}

	return value;
}
