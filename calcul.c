int		bresenham()
{
	//definir W && H
	//definir x1;
	//definir x2;
	//definir y1;
	//definir y2;
	int dx;
	int dy;
	int a;
	
	dx = x2-x1;
	dy = y2-y1;
	a = abs(dy)/abs(dx);

	if (dx > dy)
	{
		(dx > 0) ? x++ : x--;
		(dy > 0) ? y += a : y -= a;
	}
	else
	{
		(dy > 0) ? y++ : y--;
		(dx > 0) ? x += a : x -= a;
	}
