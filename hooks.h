#ifndef HOOKS_H
# define HOOKS_H

# include "keycodes.h"
# include "ft_complex.h"
# include "im_buffer.h"
# include "mapcomplex.h"
# include "views.h"
# include "hookable.h"

// bunch of magic numbers
# define DEF_DETAIL 40
# define MV_SPEED 50
# define DTHETA 0.004
# define DETAIL_INCR 75
# define ZOOM 1.2
# define WIN_SZ 900

int	ft_kbd_hook(int keycode, void *state);
int	ft_ms_hook(int button, int x, int y, void *state);
int	ft_redraw_as_needed(void *state);

#endif
