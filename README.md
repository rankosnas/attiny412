# attiny412
Atmel attiny412
CLKCTRL are write protected, if what to change them first:<br/>
```C CCP = 0xD8;    // unlock before writing to the registers within 4 instructions<br/>
```

![grafik](https://user-images.githubusercontent.com/91413908/134805540-2e6a7c3c-00de-4452-b1e7-7f5188bbbe26.png)
(Using the SpancerKonde Image)
