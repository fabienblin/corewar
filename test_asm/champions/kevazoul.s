.name		"Kevazouls everywhere"
.comment	"Isn't that terrifying?!"

begin:
sti  r4,-401,%0
	zjmp %3 # Foire
	ld %42, r3
	#ld %42, r2

	sub r3, r2, r10 # OK
	zjmp %3 # Foire
	sti	r3, 3, %10 #OK 02 90 00 00 00 65 02 (stores 101 in r2)
	st r2, -40
	lld	%3, r2
	zjmp %3 # Foire
	sti	r3, %23, %1000000000
	zjmp %3 # Foire
	sti r3, %0, %10
	zjmp %3 # Foire
	sti r3,-200, %10
	lld %3, r3
	st r3, -72
	st r7,8
	#zjmp %200 # Foire
	
	lld	400, r3 # OK 02 d0 00 23 03
	zjmp %3 # Foire
	ld	400, r3 # OK 02 d0 00 23 03
	#zjmp %200 # Passe !!! 
	sti r12, -240, r3
	zjmp %200
	sub r3, r2, r10 # OK
	zjmp %3
	live	%42 # OK
	lld -500, r12
	zjmp %3 # Foire
	st r12, 160
	sub r4, r5, r11 # 
	st  r11, 142 # OK
	st  r5, 142 # OK
	st  r1, 142 # OK
	zjmp %3
	sti r12, -21, r2
	st r12, 160
	zjmp %3
	ld	%101, r2 #OK 02 90 00 00 00 65 02 (stores 101 in r2)
	ld  %42, r4
	sti	r3, 35, %-246 # OK 02 d0 00 23 03
	zjmp %3 # Foire
	sti r3, r4, %10 # OK
	zjmp %3 # Foire
	sti r5, r4, r11 #
	zjmp %3 # Foire 
	live	%42 # OK
	st  r10, 142 # OK
	st  r11, 142 # OK
	ld	%101, r2 #OK 02 90 00 00 00 65 02 (stores 101 in r2)
	ld  %42, r4
	ld	35, r3 # OK 02 d0 00 23 03
	st  r5, 142 # OK
	st  r4, 142 # OK
	sub r4, r4, r10 # OK
	zjmp %3 # Foire
	add r5, r4, r11 # 
	live	%42 # OK
	st  r10, 142 # OK
	st  r5, 142 # OK
	st  r11, 142 # OK
	zjmp %200

	#st 	r3, 28