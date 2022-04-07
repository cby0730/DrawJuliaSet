void drawJuliaSet( int cY, int16_t (*frame)[FRAME_WIDTH] ) {

	int16_t color;
	//RGB16 color;

	int zx, zy;
	int tmp;
	int i;
	int x, y;   // r0, r1

	for (x = 0; x < 640; x++) {
          for (y = 0; y < 480; y++) {
	    zx = ( 1500 * x - 480000) / 320;
            zy = ( 1000 * y - 240000) / 240;
	    i = 255; // r2

	    while (zx * zx + zy * zy < 4000000 && i > 0) {
              tmp = (zx * zx - zy * zy) / 1000 - 700;
              zy = (zx * zy) / 500 + cY;
              zx = tmp;
              i--;
            }
          

	    color = ( (i&0xff)<<8 ) | (i&0xff);
            color = (~color)&0xffff;
            frame[y][x] = color;
          }

	}
}