Nitin Havanoor.
USC id:  8819318264.
CSCI 580: Homework #4.

Compiling instructions:
	Open the teaPot.html file in Google Chrome and click on ‘choose file’ and select the PLOT4.ASC file. Then a dialogue box will appear. type in the type of shading that the code has to use. type “Phong” for phong shading, “flat” for flat shading and as a default case, the code takes in Gouraud shading. click ‘ok’. The teapot will be rendered on the browser.

Implementation:
The code is implemented in JavaScript.
External libraries used are the ‘Math’ library and the ‘window’ library (for animation purposes).
The teapot rendering code from homework #3 was used as the base to build the homework #4 code.
The data in the PLOT4.ASC file contains the teapot data in the model space.
The model space to screen space transformation was done using the same code as that was used in homework #3. 
To perform animation, the teapot is rotated for 360 degrees about the Z-axis in the model space. And the Zooming in and out is done by adjusting the camera FOV value.

The normals are in model space and are transformed into image space using normalized transform matrices.

Flat shading:
	Used the normal of the first vertex and generated a color value, which was used for the whole triangle.

Phong shading:
	The three transformed normals are used to calculate there color values for each triangle. Then the three color values at the three vertices are interpolated at each pixel throughout the triangle using barycentric interpolation method.

Gouraud shading:
	The three normals at the three vertices are interpolated at each pixel throughout the triangle. This interpolated normal is then used to determine the color at that pixel location.


