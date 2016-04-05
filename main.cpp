/*
 * main.cpp
 *
 *  Created on: 28/03/2016
 *      Author: puc
 */


#include <avr/io.h>
#include <util/delay.h>


void setup(){

	DDRB = 0b11111111;

}

/**
 * 0: vermelho carro
 * 1: amarelo carro
 * 2: verde carro
 * 3: vermelho pedestre
 * 4: verde pedestre
 */
void loop(){

	//verde carro
	PORTB = 0b00000000;
	PORTB |= 0b00001100; //carro verde | vermelho pedestre
	_delay_ms(8000);

	//amarelo carro
	PORTB &= 0b00000000; //desliga todos
	PORTB |= 0b00001010; //amarelo carro | vermelho pedestre
	_delay_ms(2000);


	//vermelho carro
	PORTB &= 0b00000000;
	PORTB |= 0b00010001; //carro vermelho | verde pedestre
	_delay_ms(8000);

	//Faz piscar o vermelho do pedestre
	PORTB &= 0b00000001;
	PORTB |= 0b00001001;
	_delay_ms(660);

	PORTB &= 0b00000001;
	_delay_ms(660);

	PORTB |= 0b00001001;
	_delay_ms(660);

	PORTB &= 0b00000001;
	_delay_ms(660);

}


int main(void){

	setup();

	while(true){
		loop();
	}

	return 0;

}