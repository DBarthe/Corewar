.name "zork"
.comment "just a basic living prog"


:l2
l2:	sti	r1,%:live,%0x2a

	and	r1,%0,r1
live:	live	%1
	zjmp	%:live



