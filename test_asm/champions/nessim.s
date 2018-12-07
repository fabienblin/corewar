.name "NESSMAN"
.comment "I'm the beeeeeest"

start:
	st		r1, 11
	st		r14, -5

live_fork:
	live	%1
	lfork	%2012
	ld		%0, r15
	zjmp	%:live_fork
