# fdf
First graphics project at We Think Code.

The idea is to read co-ordinates from a file and map them out as a 3D wireframe image using the mlx gfx library.

I have added several bonus features to my fdf.

## Running fdf
Type `./fdf` followed by a map name, there are several maps in the `maps` folder.
```
./fdf maps/42.fdf
```
if you run
```
./fdf cube
```
It will run a hard coded 3D model of a cube
## Controls
### Rotation
<kbd>W</kbd> / <kbd>S</kbd> : x-axis rotation

<kbd>A</kbd> / <kbd>D</kbd> : y-axis rotation

<kbd>Q</kbd> / <kbd>E</kbd> : z-axis rotation

<kbd>1</kbd> : rotate 90° on the x-axis

<kbd>2</kbd> : rotate 90° on the y-axis

<kbd>3</kbd> : rotate 90° on the z-axis

### Movement/Panning
<kbd>&#8593;</kbd> : pan up

<kbd>&#8595;</kbd> : pan down

<kbd>&#8592;</kbd> : pan left

<kbd>&#8594;</kbd> : pan right

### Zooming
<kbd>+</kbd> : zoom-in

<kbd>-</kbd> : zoom-out

### Colour
Numpad <kbd>1</kbd> / <kbd>4</kbd> : change the red value

Numpad <kbd>2</kbd> / <kbd>5</kbd> : change the green value

Numpad <kbd>3</kbd> / <kbd>6</kbd> : change the blue value

Numpad <kbd>0</kbd> : make white

Numpad <kbd>.</kbd> : make black


### Misc.
<kbd>ESC</kbd> : quit

<kbd>`</kbd> : reset rotation

<kbd>Space</kbd> : toggle auto rotate

<kbd>X</kbd> : toggle x-axis auto rotate

<kbd>Y</kbd> : toggle x-axis auto rotate

<kbd>Z</kbd> : toggle x-axis auto rotate

### Fun Stuff

<kbd>Enter</kbd> : toggle colour seizure

<kbd>Backspace</kbd> : toggle image clearing

<kbd>N</kbd> : toggle normalization

## Installation
I have included an executable fdf file but if you would like to recompile you can do so by running
```
make
```
This will build all the libraries and create the fdf executable.
(You may run into issues with mlx)


## Screenshots
![Alt text](/screenshots/1.jpg?raw=true)

![Alt text](/screenshots/2.jpg?raw=true)

![Alt text](/screenshots/3.jpg?raw=true)

![Alt text](/screenshots/4.jpg?raw=true)

![Alt text](/screenshots/5.jpg?raw=true)
