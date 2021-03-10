
# e-drive-bobby-car
Bobby car with electric motor - hardware, sofware and how it was put together. 

I always wanted to refurbish a car, now I refurbished my old bobby-car adding an electric motor and some additional lights. I had a hard time finding the parts that fit together well, so over time I created different bobby-car versions. Here's a short overview:

## Version 1: Forward, Backward, Motor Control
This was my first attempt. The car essentially has, next to the stearing wheel, one major power switch for safety, an "ignition key" which turns on the front and rear lights and a trottle control. Depending on the position of the trottle the car is in "neutral" (middle), "reverse" (below neutral) or "drive" (above neutral). The distance from the middle position determines the motor speed. 

Heres the setup:
  
![BobbyCar_V1](https://user-images.githubusercontent.com/33831624/110627134-e19fdc00-81a1-11eb-9b3a-0afb23bc811d.jpg)


Forward (left) and (possibly the only true reason requiring) reverse (right): </br>
<img src="https://user-images.githubusercontent.com/33831624/110613204-47379c80-8191-11eb-9ff5-1eb19806b70b.gif" height="300" />
<img src="https://user-images.githubusercontent.com/33831624/110617289-ca5af180-8195-11eb-98bc-2534d798c904.jpg" height="300" />
<img src="https://user-images.githubusercontent.com/33831624/110613161-39821700-8191-11eb-8a53-555f46a0e734.gif" height="300" />

However, somehow the motor control did not work out very well and got super hot (which is bad as it was attached to plastic). So I created Version 2. 

## Version 2: Forward, Backward, full speed
This is essentially the above described version without motor controller, so it will only go full speed - forward and backwards. 

## Version 3: Forward, Motor Control
The potentiometer broke and essentially there is not much need for a backward gear and I still had a motor controller available. Version 3 thus lost its ability to go backwards but when going forwards you can at least control your speed. 



## Hardware parts list 
Check the subfolder 'parts' for the 3D printed additions and more details. 


|  component 	|   included in all versions |  Version 1  	| Version 2    	| Version 3    	|
|:-:	|:-:	|:-:	|:-:	|---	|
| board  	| arduino uno    	|   	|   	|   	|
| lights  	|  4 LED (front: 2 white, rear: 2 red) 	|   	|   	|   	|
| battery  	|  - 	|  12V 5Ah [Maxtuned SLA4L-BS Lead Acid] 	| 12V 5Ah [Maxtuned SLA4L-BS Lead Acid]  	| 12 V 9.8Ah [VariCore  Li-Ion] 	|
| speed control  	|  - 	| Foxnovo 6V-90V 15A DC Motor Speed Controller Switch  	|  none 	| DC Brush Motor Speed Control PWM XY-L-1240 12 V 	|
| engine 	|  12V 100 Watt 2700 RPM (7 tooth sprocket wheel) [option: 12v/24V] 	|   	|   	|   	|
|   	|   	|   	|   	|   	|


Of note: I didn't find an appropriate metal for the undercarriage and reused the available plastic (very old bobby-car classic version with thick plastic bottom). But this is not something I can recommend. A solid undercarriage is essential to allow full speed. Otherwise, depending on the drivers weight, there is too much bending force on the back axle, reducing the final speed and potentially creating heat... 
