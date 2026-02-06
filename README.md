# Fract-ol 🌀

Fract-ol is a small C program to visualize **fractal sets** like **Mandelbrot** and **Julia** using **MiniLibX**.  
It allows interactive exploration with zoom and custom Julia parameters.

---

## 🎨 Screenshots

**Mandelbrot**  
![Mandelbrot](mandelbrot.png)  

**Julia Set**  
![Julia](julia.png)  

**Julia Set Variant**  
![Julia 2](julia_2.png)  

---

## 🎥 Demo Video

[Watch the fractal in action](video.webm)

---

## 🚀 Features
- Display **Mandelbrot** and **Julia** fractals  
- Zoom in/out using mouse scroll  
- Interactive exploration in a 900x900 window  
- Custom Julia parameters (-2 to 2)  

---

## 💻 Requirements
- Linux (tested on Ubuntu)  
- `gcc` or `clang`  
- `X11` development libraries (`libx11-dev`)  
- **MiniLibX** included in the repo (`mlx_linux`)  

---

## ⚡ Build

Clone the repository and build:

```bash
git clone <your-repo-url>
cd fractol
make
🎮 Usage
Mandelbrot
./fractol mandelbrot

Julia (with custom parameters)
./fractol julia 0.285 0.01


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