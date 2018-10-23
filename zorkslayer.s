.name "zork slayer"
.comment "Live for me bitch"

######################################
## extremely efficient against zork ##
######################################

stairs:
	st r2, -7
	st r2, -17
	st r2, -27
	st r2, -37
	st r2, -47
	st r2, -57
	st r2, -67
	st r2, -77
	st r2, -87
	st r2, -97
	st r2, -107
	st r2, -117
	st r2, -127
	st r2, -137
	st r2, -147
	st r2, -157
	st r2, -167
	st r2, -177
	st r2, -187
	st r2, -197
	st r2, -207
	st r2, -217
	st r2, -227
	st r2, -237
	st r2, -247
	st r2, -257
	st r2, -267
	st r2, -277
	st r2, -287
	st r2, -297
	st r2, -307
	st r2, -317
	st r2, -327
	st r2, -337
	st r2, -347
	st r2, -357
	st r2, -367
	st r2, -377
	st r2, -387
	st r2, -397
	st r2, -407
	st r2, -417
	st r2, -427
	st r2, -437
	st r2, -447
	st r2, -457
	st r2, -467
	st r2, -477
	st r2, -487
	st r2, -497
	st r2, -507

	sti	r1, %:live, %1

live:
	live %1

	add	r6, r6, r6
	fork %:writenb
	zjmp %:live

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
	st r7, 364
	live13:
		live %1

#by rbarbazz
