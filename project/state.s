	.arhc msp430g2553
	.p2align 1,0
	.text

	.global case_one
case_one:
	mov 0,&green_on
	mov 0,&red_on
	mov 0,r12
	call buzzer_set_period
