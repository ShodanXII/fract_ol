# Fract'ol - 42 Project

## Table of Contents
1. Introduction
2. Features
3. Installation
4. Usage
5. Bonus Features
6. Project Validation
7. Contributing
8. License

## Introduction
Fract'ol is a captivating project developed as part of the 42 curriculum, designed to explore the fascinating world of fractals. This project leverages the power of graphical programming to render intricate fractal patterns in real-time, providing an interactive experience for users. The project includes the implementation of several well-known fractals, including the Mandelbrot set, Julia set, and the Burning Ship fractal as a bonus.

## Features
* **Real-time rendering** of fractals with smooth zoom and pan functionality
* **Multiple fractal types**:
  * Mandelbrot Set
  * Julia Set
  * Burning Ship (Bonus)
* **Interactive controls**:
  * Zoom in/out with mouse scroll or touchpad
  * Pan around the fractal with mouse drag
  * Adjust iteration depth for more detailed rendering
  * Change color schemes dynamically
* **High-performance rendering** using optimized algorithms and multi-threading where applicable
* **User-friendly interface** with on-screen instructions and controls

## Installation
To install and run Fract'ol on your local machine, follow these steps:

1. **Clone the repository**:
```bash
git clone https://github.com/your-username/fract_ol.git
cd fract_ol
```

2. **Compile the project**:
```bash
make
```

3. **Run the executable**:
```bash
./fractol [fractal_type]
```

Replace `[fractal_type]` with one of the following:
* `mandelbrot` for the Mandelbrot set
* `julia` for the Julia set
* `burningship` for the Burning Ship fractal

## Usage
Once the program is running, you can interact with the fractal using the following controls:
* **Mouse Scroll**: Zoom in and out
* **Mouse Drag**: Pan around the fractal
* **Arrow Keys**: Move the fractal in small increments
* **Spacebar**: Reset the view to the default position
* **C**: Cycle through different color schemes
* **I**: Increase the number of iterations for more detail
* **D**: Decrease the number of iterations for faster rendering
* **R**: Randomize the Julia set parameters (only for Julia set)
* **ESC**: Exit the program

## Bonus Features
In addition to the mandatory requirements, this project includes several bonus features that enhance the user experience and demonstrate advanced programming techniques:
* **Burning Ship Fractal**: A visually stunning fractal that resembles a ship on fire, implemented as a bonus feature
* **Dynamic Color Schemes**: Multiple color palettes that can be cycled through during runtime, providing a variety of visual experiences
* **Interactive Julia Set**: The ability to dynamically change the parameters of the Julia set by clicking on the Mandelbrot set, creating a seamless connection between the two fractals
* **Performance Optimization**: The use of multi-threading and optimized algorithms ensures smooth rendering even at high zoom levels

## Project Validation
This project has been validated with an outstanding score of **125/100**, reflecting the high quality of implementation, attention to detail, and the inclusion of bonus features that go above and beyond the basic requirements.

## Contributing
Contributions to Fract'ol are welcome! If you have any suggestions, bug reports, or feature requests, please open an issue or submit a pull request. For major changes, please discuss your ideas first via issues.

## License
This project is licensed under the MIT License - see the LICENSE file for details.

**Fract'ol** is a project that not only meets the requirements but also pushes the boundaries of what is expected, delivering a visually stunning and technically impressive exploration of fractals. Enjoy the journey into the infinite complexity of these mathematical wonders!