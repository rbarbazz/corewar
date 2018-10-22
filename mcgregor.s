.name "Conor"
.comment "Trash talk? Smack talk? This is an American term that makes me laugh. I simply speak the truth. I'm an Irish man."

start:
	sti	r1, %:live, %1

live:
	live %1

	add r6, r6, r6

djab: #defense
	st r2, -24
	st r2, -34
	st r2, -44
	st r2, -54
	st r2, -64
	st r2, -74
	st r2, -84
	st r2, -94
	st r2, -104
	st r2, -114
	st r2, -124
	st r2, -134
	st r2, -144
	st r2, -154
	st r2, -164
	st r2, -174
	st r2, -184
	st r2, -194
	st r2, -204
	st r2, -214
	st r2, -224
	st r2, -234
	st r2, -244
	st r2, -254
	st r2, -264

	ld %57672197, r2
	fork %0

lowkick: #attack
	st r2, 1280

#by rbarbazz
