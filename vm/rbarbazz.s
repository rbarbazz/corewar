.name "zork"
.comment "I'M ALIIIIVE"    #yeeeet


#lld :dab, r1
#aff r1

#l2:
#		sti r1, %:live, %1
#		and r1, %0, r1

live:	live %1
#lfork %:live
#add r1, r2, r3
#add r1, r3, r1
#add r1, r3, r1
#add r1, r3, r1
#dab:
#add r1, r3, r1
#aff r1
#add r1, r3, r1
#aff r1
#add r1, r3, r1
#aff r1
#add r1, r3, r1
#aff r1
#add r1, r3, r1
#aff r1
#		sub r5, r6, r7
#add r6, r6, r6 #carry -> 1
#live %1
#zjmp %:dab
#zjmp %:live
