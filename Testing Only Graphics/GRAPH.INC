unsigned char far *vbuf=(unsigned char far *)0xA0000000L;

void setpal() {
	outp(0x3C8,0);
	outp(0x3C9,100);
	outp(0x3C9,0);
	outp(0x3C9,0);
	for (int k=1; k<250; k++) {
		outp(0x3C8,k);
		outp(0x3C9,k/4);
		outp(0x3C9,k/4);
		outp(0x3C9,k/4);
	}
	outp(0x3C8,250);outp(0x3C9,250);outp(0x3C9,0);outp(0x3C9,0);
	outp(0x3C8,251);outp(0x3C9,250);outp(0x3C9,125);outp(0x3C9,0);
	outp(0x3C8,252);outp(0x3C9,250);outp(0x3C9,250);outp(0x3C9,0);
	outp(0x3C8,253);outp(0x3C9,0);outp(0x3C9,250);outp(0x3C9,0);
	outp(0x3C8,254);outp(0x3C9,0);outp(0x3C9,0);outp(0x3C9,250);
	outp(0x3C8,255);outp(0x3C9,250);outp(0x3C9,0);outp(0x3C9,250);
}

void pset(int xx, int yy, int cc) {
	vbuf[xx+(yy*320)]=cc;
}

int pget(int xx, int yy) {
	return vbuf[xx+(yy*320)];
}

void graph(void) {
	 asm{
		mov ax, 0x13
		int 0x10
	 }
}

void txt(void) {
	asm{
		mov ax, 0x03
		int 0x10
	 }
}
