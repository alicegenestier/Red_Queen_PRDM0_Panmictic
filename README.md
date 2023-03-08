# Red_Queen_PRDM9_Panmictic

## Authors

* **Alice Genestier** _alias_ [@alicegenestier](https://github.com/alicegenestier)

## Description

This project aims to model the evolutionary dynamics of the Prdm9 gene in a panmictic population.
The files named ``model.cpp``, ``main.cpp`` and ``model.h`` correspond to the simulator.
All the files in the folder named ``graphics_and_interpretations`` correspond to files generating figures.

## Coded with

* Simulator : C++

* Figures : [jupyter-notebook](https://jupyter.org/) - Python

## Prerequisites

To be able to use the code to generate the figure, you will need to install [jupyter-notebook](https://jupyter.org/install)

## How to use it

### Simulator
To run the simulator, you will need to :
* Perform the compilation : tap ``make`` in the terminal to generate the executable named ``meiosis``
* Execute the program : for this you need to know which parameter you want to change compared to the default settings (described in main.cpp) and then tap the commande 
``./meiosis -[parameter1] [value1] -[parameter2] [value2] [filename]``. 
Here, the command works if it is executed at the same place as the executable named ``meiosis``, in any other case, you need to indicate the path to the executable. You may need to change more than 2 parameters, feel free to change as many parameters as you wish or to let all the settings as default, in this last case the command is only ``./meiosis [filename]``

### Figures
To generate the figures, you need to execute the command ``jupyter-notebook`` in a terminal to open a jupyter-notebook window. Then you can access to each file to generate the figures by executing the correcponding code.
