.name "Miaouss"
.comment "UN PTIT CHAAAAAAAAAT
Nous sommes de retour
Pour vous jouer un mauvais tour
Afin de préserver le monde de la dévastation
Afin de rallier tous les peuples à notre nation"
		
ld %0, r16
zjmp %:main
lives:
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	ld %0, r16
	zjmp %:lives
main:
	st r1, -49
	st r1, -49
	st r1, -49
	st r1, -49
	st r1, -49
	st r1, -49
	st r1, -49
	st r1, -49
	ld %268435456, r2
	st r2, -101
	sti r1, %:shoot_init, %1
	fork %:lives
	ld %0, r16
shoot_init:
	live %1
	ld %0, r16
	fork %:shoot
	live %1
	fork %:shoot
	live %1
	ld %0, r16
	zjmp %:shoot_init
shoot:
	live %1
	ld %0, r16
	zjmp %500
