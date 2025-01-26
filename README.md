Fract-ol
Introduction
Fract-ol is a computer graphics project focused on rendering beautiful fractals using the MiniLibX library. A fractal is a mathematical object that displays self-similar patterns at every scale. This project explores fractals like the Mandelbrot set and Julia sets, enabling users to zoom infinitely and interact dynamically with these stunning visuals.

Features
Render Two Fractals:
Mandelbrot Set: A well-known fractal that visualizes the behavior of a simple mathematical formula.
Julia Sets: A family of fractals that can be customized using parameters.
Interactive Zoom:
Use the mouse wheel to zoom in and out infinitely (within hardware limits).
Dynamic Colors:
The depth of each fractal is represented using vibrant colors, enhancing the visual experience.
Window Management:
Smooth transitions between minimizing, restoring, and closing the window.
Clean Exit:
Quit the program by pressing ESC or clicking the close button.
Getting Started
Requirements
C Compiler: Ensure you have GCC or Clang installed.
MiniLibX: The graphical library used for rendering. Use the version provided by the school or compile from source.
libft: Your custom library is required for the project.
Operating System: Designed for macOS or Linux.
Installation
Clone the Repository:

bash
Copy
Edit
git clone <repository_url>
cd fract-ol
Build the Project:

Use the provided Makefile:
bash
Copy
Edit
make
The executable fractol will be generated.
Run the Program:

bash
Copy
Edit
./fractol <fractal_name> [optional_parameters]
Examples:

Render the Mandelbrot set:
bash
Copy
Edit
./fractol mandelbrot
Render a custom Julia set:
bash
Copy
Edit
./fractol julia 0.355 0.355
Controls
Key/Action	Functionality
Mouse Wheel Up	Zoom in
Mouse Wheel Down	Zoom out
Arrow Keys	Move the view (pan left/right/up/down)
ESC	Exit the program
Mouse Pointer	Zoom centers on mouse position
Code Structure
main.c: Entry point for the program. Handles arguments and initializes the fractal rendering.
fractal_render.c: Contains the logic to compute and render fractals.
events.c: Handles mouse and keyboard inputs for zooming, panning, and exiting.
math_wdakxi.c: Includes mathematical utilities, such as mapping values and complex number operations.
fract-ol_init.c: Sets up the MiniLibX environment, including window and image initialization.
libft/: Your custom library for utility functions.
Usage Examples
Mandelbrot Set:

bash
Copy
Edit
./fractol mandelbrot
Custom Julia Set:

bash
Copy
Edit
./fractol julia -0.4 0.6
Invalid Arguments:

The program will display a list of valid parameters if incorrect arguments are passed:
bash
Copy
Edit
./fractol
Error: Invalid fractal type. Available options: mandelbrot, julia
Bonus Features (125% Completion)
Additional Fractals:

Add more fractals such as:
Burning Ship: A variant of the Mandelbrot set with dramatic visual effects.
Newton Fractal: Visualizes iterative solutions to equations.
Example usage:
bash
Copy
Edit
./fractol burning_ship
Mouse-Focused Zoom:

Zoom dynamically at the position of the mouse pointer, providing precision navigation.
Dynamic Color Shifting:

Add animated color palettes for the fractal, cycling through vibrant colors to create psychedelic effects.
Smooth Panning:

Use keyboard inputs (e.g., arrow keys) to pan smoothly across the fractal.
Save Fractals as Images:

Add functionality to export rendered fractals as .bmp images for later viewing.
Multithreading:

Use multithreading to optimize rendering, dividing the work across multiple cores for faster performance.
Keyboard Shortcuts for Zoom:

Use + and - on the keyboard for precise zooming.
Real-Time Julia Set Parameter Adjustment:

Use the mouse or keyboard to adjust the c parameter in real time and instantly see changes in the Julia set.
How It Works
Rendering:

The fractals are computed using iterative mathematical formulas. The number of iterations determines the color of each pixel.
Zooming:

Adjust the ranges of the real and imaginary axes to create a zoom effect, centered on the mouse pointer.
Colors:

Colors are mapped to the iteration count, creating gradients to visualize fractal depth.
Common Issues
No Display:

Ensure MiniLibX is installed correctly and compatible with your system.
Slow Performance:

Optimize the iteration count or fractal rendering loop.
Enable multithreading if using the bonus features.
Segmentation Fault:

Check if all parameters are passed correctly, and ensure memory is properly allocated and freed.
Acknowledgments
Inspired by the works of Benoit Mandelbrot, who first introduced the concept of fractals.
The project was made possible by the tools and resources provided by 42's curriculum.
License
This project is for educational purposes and follows the guidelines set by the 42 curriculum. Redistribution or use outside of the 42 ecosystem must comply with its policies.

With the bonus features implemented, the project achieves 125% completion, offering advanced functionality and a stunning visual experience. Explore, zoom, and enjoy fractals!







