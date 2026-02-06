# Fract-ol 🌀

Fract-ol is a graphical program written in **C** that visualizes famous **fractal sets** such as the **Mandelbrot** and **Julia** sets using **MiniLibX**.  
The project focuses on complex numbers, mathematical visualization, event handling, and low-level graphics programming in C.

## 🎨 Screenshots

### Mandelbrot
![Mandelbrot](mandelbrot.png)

### Julia Set
![Julia](julia.png)

### Julia Set Variant
![Julia 2](julia_2.png)

## 🎥 Demo

[Watch the fractal in action](video.webm)

## Features

- Display Mandelbrot and Julia fractals
- Smooth zoom in/out using mouse scroll
- Interactive exploration in a 900x900 window
- Custom Julia parameters via command line
- Clean window and resource management

## 💻 Requirements

- Linux (tested on Ubuntu)
- gcc or clang
- make
- X11 development libraries (`libx11-dev`)
- MiniLibX (included in the repository)

## ⚡ Build

Clone the repository and compile the project:

```bash
git clone git@github.com:LeenAlmahthi/Fract-ol-.git
cd Fract-ol-
make
````

<<<<<<< HEAD
This will generate the executable:

```bash
./fractol
```

Rebuild everything from scratch:

```bash
make re
```

Clean object files:

```bash
make clean
```

## 🎮 Usage

Run the program by specifying the fractal type.

Mandelbrot:

```bash
./fractol mandelbrot
```

Julia (real and imaginary parts must be between -2 and 2):

```bash
./fractol julia 0.285 0.01
```

## 🕹️ Controls

Mouse:

* Scroll Up → Zoom in
* Scroll Down → Zoom out

Keyboard:

* ESC → Close the window

## 👤 Author

**Leen Almahthi** – 42 School

## 📌 Notes

* MiniLibX is included, no external installation required
* Zoom is centered on the mouse position
* Written according to 42 Norm
* Use `make re` if build issues occur

## ⭐ Example

```bash
./fractol julia -0.8 0.156
```
=======
Julia (with custom parameters)
./fractol julia 0.4 0.6


Mouse Controls:

Scroll up: Zoom in

Scroll down: Zoom out

Keyboard Controls:

ESC: Close window

📂 Project Structure
fractol/
├─ fract_ol.h          # Header with structs & function prototypes
├─ main.c              # Main function & hooks
├─ fractol.c           # Fractal drawing functions
├─ close_win.c         # Window close & free resources
├─ uni_libft.c         # Custom utility functions
├─ mlx_linux/          # MiniLibX library for Linux
├─ Makefile            # Build system
├─ julia.png           # Julia fractal screenshot
├─ julia_2.png         # Julia variant screenshot
├─ mandelbrot.png      # Mandelbrot screenshot
└─ video.webm          # Demo video

👤 Author

Leen Ghnaim – 42 School

⚡ Notes

The project includes MiniLibX, so no extra installation is required.

All Julia numbers must be in the range -2 to 2.

Use make re to rebuild everything from scratch.


---

✅ **Instructions to make it GitHub-ready:**  
1. Copy everything above.  
2. In your `fractol` folder, create a file called `README.md`.  
3. Paste the content inside.  
4. Commit and push to GitHub:

```bash
git add README.md
git commit -m "Add README for fractol project"
git push
>>>>>>> 1ad854c (done)
