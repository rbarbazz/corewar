.name "zork slayer"
.comment "Live for me bitch"

######################################
## extremely efficient against zork ##
######################################

	sti	r1, %:live, %1

live:
	live %1
	add	r8, r8, r8
	fork %:live

writenb:
	sti	r1, %:live2, %1
	sti	r1, %:live3, %1
	sti	r1, %:live4, %1
	sti	r1, %:live5, %1
	sti	r1, %:live6, %1
	sti	r1, %:live7, %1
	sti	r1, %:live8, %1
	sti	r1, %:live9, %1
	sti	r1, %:live10, %1
	sti	r1, %:live11, %1
	sti	r1, %:live12, %1
	sti	r1, %:live13, %1

	st r2, -340

live2:
	live %1
live3:
	live %1
live4:
	live %1
live5:
	live %1
live6:
	live %1
live7:
	live %1
live8:
	live %1
live9:
	live %1
live10:
	live %1
live11:
	live %1
live12:
	live %1

	ld %57673475, r7
	st r7, 361
	st r7, 292
	st r7, 223
	st r7, 154
	st r7, 85
	st r7, 16


live13:
	live %1

#by rbarbazz
