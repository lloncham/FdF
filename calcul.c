int		bresenham()

//definir W && H
//definir x1;
//definir x2;
//definir y1;
//definir y2;
int dx;
int dy;
int xinc;
int yinc;

int	m = dy/dx;
dx = abs(x2-x1);
dy = abs(y2-y1);
xinc = (dx < 0) ? 1 : 0;
yinc = (dy < 0) ? 1 : 0;

y = 2 * x + y1 + 0,5;
	if (dx > dy)
mlx_pixel_put(mlx, win, x2, y2, OxFFFFFF);
