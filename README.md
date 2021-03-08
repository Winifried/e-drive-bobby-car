# e-drive-bobby-car
Bobby car with electric motor - hardware, sofware and how it was put together. 

I always wanted to refurbish a car, now I refurbished my old bobby-car adding an electric motor and some additional lights. I really had a hard time finding the parts that fit together well, so over time I created different versions. Here's a short overview:

## Version 1: Forward, Backward, Motor Control
This was my first attempt. The car essentially has, next to the stearing wheel, one major power switch for safety, an "ignition key" which turns on the front and rear lights and a trottle control. Depending on the position of the trottle the car is in "neutral" (middle), "reverse" (below neutral) or "drive" (above neutral). The distance from the middle position determines the motor speed. 

Heres the setup:

However, somehow the motor control did not work out very well and got super hot (which is bad as it was attached to plastic). So I created Version 2. 

## Version 2: Forward, Backward, full speed
This is essentially the above described version without motor controller, so it will only go full speed - forward and backwards. 

## Version 3: Forward, Motor Control
The potentiometer broke and essentially there is not much need for a backward gear and I still had a motor controller available. Version 3 thus lost its ability to go backwards but when going forwards you can at least control your speed. 



## Parts list 
|  included in all versions 	|   Version 1	|  Version 2  	| Version 3    	|   	|
|:-:	|:-:	|:-:	|:-:	|---	|
| arduino uno   	|   	|   	|   	|   	|
|   	|   	|   	|   	|   	|
|   	|   	|   	|   	|   	|


Of note: I didn't find an appropriate metal for the undercarriage and reused the available plastic (very old bobby-car version with thick plastic bottom). But this is not something I can recommend. A solid undercarriage is essential to allow full speed. Otherwise, depending on the drivers weight, there is too much bending force on the back axle, reducing the final speed. 
