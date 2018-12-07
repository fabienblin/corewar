.name		"Kevazouls everywhere"
.comment	"Isn't that terrifying?!"

begin:
	ld	%101, r2 #OK 02 90 00 00 00 65 02 (stores 101 in r2)
	ld  %42, r4
	st	r2, 101 # OK 03 70 02 00 2a (delete instr value on map and do nothing else)
	ld	35, r3 # OK 02 d0 00 23 03
	add r3, r4, r10 # OK
	add r5, r4, r11 # 
	st  r10, 142 # OK
	st  r11, 142 # OK
	st  r3, 100
	st  r4, 58 # OK
	st  r4, -221 # OK
	st  r4, r2 # OK
	live	%42 # OK
	st  r2, 51 # OK
	st  r3, 100 # OK
	st  r4, 100 # OK
	st  r10, 100 # OK
	add r3, r4, r10 # OK
	add r5, r4, r11 # 
	st  r10, 42 # OK
	st  r11, 42 # OK

	#st 	r3, 28