#include "mlx.h"
#include <stdlib.h>

typedef struct 
{
	void *mlx;
	void *win;
} thingy;

int quit(int keycode, void *ptr)
{
	(void) keycode;
	thingy *thing = (thingy *) ptr;
	mlx_destroy_window(thing->mlx, thing->win);
	exit(0);
}

int main()
{
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 500, 500, "wo");
	thingy thing = {mlx, win};

	mlx_key_hook(win, quit, &thing);
	mlx_loop(mlx);
}
