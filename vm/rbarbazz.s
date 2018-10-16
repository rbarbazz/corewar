.name "zork"
.comment "I'M ALIIIIVE"    #yeeeet

start:
add r1, r2, r3
aff r3
sub r3, r1, r5
aff r5
live %-1
ld :start, r8
aff r8
st r8, r12
st r12, -98888500
ld 982, r9 #load what st previously stored
sti r8, 0, %50
add r6, r6, r6 # carry 1
zjmp %3
lld 0, r9
st r9, r12
st r12, -98888500
ldi 2, %0, r4
fork %65
