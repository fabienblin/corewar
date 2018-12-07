.name		"Kevazouls everywhere"
.comment	"Isn't that terrifying?!"

begin:
	ld	%101, r2 #OK 02 90 00 00 00 65 02 (stores 101 in r2)
	ld  %42, r4
	ld	35, r3 # OK 02 d0 00 23 03
	sub r3, r4, r10 # OK
	add r5, r4, r11 # 
	live	%42 # OK
	st  r10, 142 # OK
	st  r11, 142 # OK
	and r1, r2, r12
	st r12, 140
	and -21, r2, r12
	st r12, 140
	and %42, r2, r12
	st r12, 140
	ld	%101, r2 #OK 02 90 00 00 00 65 02 (stores 101 in r2)
	ld  %42, r4
	ld	35, r3 # OK 02 d0 00 23 03
	sub r3, r4, r10 # OK
	add r5, r4, r11 # 
	live	%42 # OK
	st  r10, 142 # OK
	st  r11, 142 # OK
	ld	%101, r2 #OK 02 90 00 00 00 65 02 (stores 101 in r2)
	ld  %42, r4
	ld	35, r3 # OK 02 d0 00 23 03
	sub r3, r4, r10 # OK
	add r5, r4, r11 # 
	live	%42 # OK
	st  r10, 142 # OK
	st  r11, 142 # OK

	#st 	r3, 28