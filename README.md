## InTheBox

Connect your mailbox to be notified as soon as you receive mail.
InTheBox is also able to detect and warn you of suspicious behaviors around your mailbox.

### Supplies
#### Circuit
- [Tags 13.56MHz](https://fr.aliexpress.com/item/33026471651.html?spm=a2g0o.productlist.0.0.75c069ddw83bRu&algo_pvid=ab91e0cd-ffda-4191-869f-4a24e6d478df&algo_expid=ab91e0cd-ffda-4191-869f-4a24e6d478df-8&btsid=0ab6d67915913501571721219e6dc5&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_) 
- [RFID module 13.56MHz](https://fr.aliexpress.com/item/32803014822.html?src=google&src=google&albch=shopping&acnt=494-037-6276&isdl=y&slnk=&plac=&mtctp=&albbt=Gploogle_7_shopping&aff_atform=google&aff_short_key=UneMJZVf&&albagn=888888&albcp=6459793138&albag=77316928277&trgt=743612850714&crea=fr32803014822&netw=u&device=c&albpg=743612850714&albpd=fr32803014822&gclid=CjwKCAjw2uf2BRBpEiwA31VZj15SBT9k4zWprWGvA08QRypcRU5SLWlCRy1HjtnLlpRtY_WDJ9jsShoCzpwQAvD_BwE&gclsrc=aw.ds)
- [Arduino Uno](https://fr.aliexpress.com/item/32665372585.html?spm=a2g0o.productlist.0.0.e9cf3738ncVT2S&algo_pvid=072eefcd-ebc6-4b39-8c3e-908fbe483ac0&algo_expid=072eefcd-ebc6-4b39-8c3e-908fbe483ac0-0&btsid=0ab6f83915913519748057530e0c87&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
- [FSR 406](https://fr.aliexpress.com/item/32652992847.html?spm=a2g0o.productlist.0.0.16c345b7lMzcur&s=p&ad_pvid=202006050305404316102348313040005490484_1&algo_pvid=6eb514e7-2e48-46fd-9c0a-1b1126191425&algo_expid=6eb514e7-2e48-46fd-9c0a-1b1126191425-7&btsid=0ab6f83915913515405917944e0c87&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
- [HC-SR04](https://fr.aliexpress.com/item/32973373842.html?spm=a2g0o.productlist.0.0.40064b01f9nmNX&algo_pvid=e5332c4e-b142-4f0d-abb1-e1f802277021&algo_expid=e5332c4e-b142-4f0d-abb1-e1f802277021-4&btsid=0ab6f83915913513983241719e0c87&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)
- [Buzzer](https://fr.aliexpress.com/item/4000012077642.html?src=google&src=google&albch=shopping&acnt=494-037-6276&isdl=y&slnk=&plac=&mtctp=&albbt=Gploogle_7_shopping&aff_atform=google&aff_short_key=UneMJZVf&&albagn=888888&albcp=6459793138&albag=77316928277&trgt=743612850714&crea=fr4000012077642&netw=u&device=c&albpg=743612850714&albpd=fr4000012077642&gclid=CjwKCAjw2uf2BRBpEiwA31VZjwK-2mUgZ_0cJfUReg0XUHlpaVi1ulF6boBbpej_1uCHOifUqY6-5BoC1kEQAvD_BwE&gclsrc=aw.ds)

#### Scale
- 1 board 30 x 41 x 0.5 cm
- [Pressure Sensor Pad GreenS40](https://fr.aliexpress.com/item/4000416208703.html?spm=a2g0o.productlist.0.0.16c345b7lMzcur&algo_pvid=6eb514e7-2e48-46fd-9c0a-1b1126191425&algo_expid=6eb514e7-2e48-46fd-9c0a-1b1126191425-8&btsid=0ab6f83915913515405917944e0c87&ws_ab_test=searchweb0_0,searchweb201602_,searchweb201603_)

#### Dummy soil
- 1 board 30 x 41 x 1 cm
- 2 boards 35 x 41 x 1 cm
- 1 board 35 x 28 x 1 cm
- 1 cylinder 35 cm x 1 cm radius
- screws / glue
- Something to cut out of the board 



### Step 1 - Tags initialization
### Step 2 - Assembly of the components
Fritzing schema:

### Step 3 - Mailbox measurement
We need to know the dimensions of the mailbox in order to build the layout and configure the distance sensor.
Measures the inner width and depth.

### Step 4 - Arduino code and component testing
The code is available on this TinkerCAD simulation: https://www.tinkercad.com/things/1rgmoFdLwcb
Copy it to your arduino, then modify this line to indicate the depth of your mailbox in millimetres:
```
#define MAIL_BOX_DEPTH 500
```

### Step 5 - Fabrication of dummy soil
The plan has been calculated for a letterbox with the dimensions 30 x 41 x 30 cm (L x W x H).
To readjust the plan to the dimensions of your letterbox, make sure that the false floor board (initially 30 x 41 x 1 cm) passes through the door horizontally before assembling.
![plan cache](https://user-images.githubusercontent.com/17204777/83879310-bc2b0100-a73d-11ea-934b-9e559700a643.png)
Follow these these assembly instructions:

### Step 6 - Arrangement of the letter box 
1. Place the arduino and its components at the bottom of the mailbox. The RFID sensor must be placed on the front or rear lock side. Its location will have an impact on the quality of authentication, and you will need to retrieve mail from this side only. 
2. Place the dummy soil in the mailbox, slot towards the back door. Be careful not to crush any components with the support foot of the dummy soil.
3. Fix the FSR sensor in the center of the dummy soil, tab towards the slot so the wires slide beneath. Pass the HC-SR04 sensor through the slot, we will fix it later at the back of the mailbox.
![Capture d’écran du 2020-06-05 13-12-44](https://user-images.githubusercontent.com/17204777/83879701-5ab76200-a73e-11ea-8a84-c3ef2c3c58fa.png)
4. Fix the pressure pad on the FSR sensor.
![Capture d’écran du 2020-06-05 13-13-01](https://user-images.githubusercontent.com/17204777/83879705-5be88f00-a73e-11ea-9e56-46c7001e8394.png)
5. Place the 30 x 41 x 0.5 cm board on top to make the scale.
![Capture d’écran du 2020-06-05 13-26-51](https://user-images.githubusercontent.com/17204777/83879708-5c812580-a73e-11ea-9466-3175d8b6dac3.png)
6. Place the HC-SR04 sensor at the back of the mailbox on the side where the lock of the front door is located, and do some tests!
7. Then you can fix the HC-SR04 sensor
