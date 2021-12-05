## Warning : multibrot not yet implemented
## About 
This is a small program to display fractals ([julia sets](https://en.wikipedia.org/wiki/Julia_set)
 and the [mandelbrot set](https://en.wikipedia.org/wiki/Mandelbrot_set)). <br>
It is a school project of 19 school.
## Compiling
On nixes that use the X window system this should do the trick :
* Make sure you have the [minilibx](https://github.com/ilkou/minilibx) installed.
* Then edit the `makefile` so that `MLX_DIR` is where you've installed it.
* Then `make`
## Running the program 
run with one of :
* `./fractol` : same as `./fractol -mandelbrot`
* `./fractol -mandelbrot` : to display the madelbrot set
* `./fractol -julia x y` : to dispaly the julia set of the function `z -> z^2 + c` where `c = x/1000 + i.y/1000`
* `./fractol -multibrot d` : with `d > 1000` to display the multibrot set for `z -> z^(d/1000) + c` 
* `./fractol -help` : to print this help box 
## Using the program 
* esc : exit
* mouse scroll : zoom
* arrows : move around
* left click : redraw with more detail
* space : change color scheme
#### Julia only :
* j/k : rotate the constant anti/clockwise by a *tiny* angle
* p : print the constant to stdout (eg so you can input it later)
* right click : go to previous view of the mandelbrot set (or multibrot). This loses the Julia fractal view. (1)
#### Multi/Mandelbrot only : 
* right click : display julia fractal for `z^2 + c` (multi : `z^d + c`) where c is where you clicked (1)
## Tips
* The prettiest julia fractals tend to be close to the edge of the madelbrot set.
* `cool_consts.txt` contains constants for julia fractals I find pretty.
* The program will be noticeably laggy, especially if there is a lot of non-diverging points on the screen (light colored in most schemes).
