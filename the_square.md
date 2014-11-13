# The Square
## Regarding its Composition


### Software Design

The original image was that of a square with a decoupled texture. Although the image is easily rendered in software, the validity thereof as a design space provides a number of challenges. Specifically, the individual components of the square itself must be mutable, robust, and reliable.

The solution to this is an embrace of MVC design with two rendering classes: `SquareRender` and `SquareFbo`. The data necessary for the `draw()` calls is available to these classes through storing raw pointers to private members of the `SquareModel` (given to rendering classes during construction). Although `SquareRender` needs to keep a `std::shared_ptr` to an instance of `SquareFbo`, the construction of the `SquareFbo` class happens outside of the `SquareRender`.

The insurance, thus, is that these classes know *nothing* about each other. The wrapper class `SquareObject` keeps instances of all of them - abstracting its functionality into a factory method is a necessary next step as modules for levels become appropriately realized.

 