# EDK2 for Redmi Note 7 Pro (Violet)

This project explores creating EDK2/UEFI support for the **Redmi Note 7 Pro (codename: violet)** by leveraging resources from similar Snapdragon devices.  

## Current Progress

- Based on **dipper.img** (from Xiaomi Mi 8 / Dipper).
- Created a personalized build of **TWRP** for Violet.
- The custom boot image is available here: [Download Boot Image](https://drive.google.com/file/d/16m368vs2o2zdPc7LbIuRtGFFJkHyeXgZ/view?usp=sharing)

## Purpose of the Boot Image

- Enables the use of **parted** inside the recovery environment.  
- Allows proper partitioning of the **`/dev/block/mmcblk0`** storage device.  

## Next Steps

- Validate partition layout for compatibility with EDK2 boot requirements.  
- Extend build scripts to simplify flashing and testing.  
- Begin drafting drivers for Violet-specific hardware.  

## Currently in need

- of uefi img for redmi note 7 pro
- made a uefi image but for now gpio work but no touch i'll probe it more
- i2c bus for touch controller is not enabled, which usually sits on i2c-1 for this device


now some asked the dipper-violet image i made is not working, so i am giving another approach to mod,
download unmkbootimg binary from somewhere then use it to unpack the "dipper" image as well as "boot" image from your own device
```
./unmkbootimg dipper.img
```
it will spew out two things - 1. initramfs.cpio.gz
                              2. zImage
now what you need to do is use initramfs.cpio.gz of your own boot img and zImage of dipper
recompile them using mkbootimg

a sample simulation can be:

```
./unmkbootimg boot.img
unmkbootimg version 1.2 - Mikael Q Kuisma <kuisma@ping.se>
Kernel size 15024828
Kernel address 0x8000
Ramdisk size 336936
Ramdisk address 0x1000000
Secondary size 0
Secondary address 0xf00000
Kernel tags address 0x100
Flash page size 4096
Board name is ""
Command line "console=ttyMSM0,115200n8 androidboot.hardware=qcom androidboot.console=ttyMSM0 androidboot.memcg=1 lpm_levels.sleep_disabled=1 video=vfb:640x400,bpp=32,memsize=3072000 msm_rtb.filter=0x237 service_locator.enable=1 swiotlb=1 androidboot.usbcontroller=a600000.dwc3 earlycon=msm_geni_serial,0x880000 loop.max_part=7 buildvariant=user"
This image is built using standard mkbootimg
Extracting kernel to file zImage ...
Extracting root filesystem to file initramfs.cpio.gz ...
All done.
---------------
To recompile this image, use:
  mkbootimg --kernel zImage --ramdisk initramfs.cpio.gz --base 0x0 --cmdline 'console=ttyMSM0,115200n8 androidboot.hardware=qcom androidboot.console=ttyMSM0 androidboot.memcg=1 lpm_levels.sleep_disabled=1 video=vfb:640x400,bpp=32,memsize=3072000 msm_rtb.filter=0x237 service_locator.enable=1 swiotlb=1 androidboot.usbcontroller=a600000.dwc3 earlycon=msm_geni_serial,0x880000 loop.max_part=7 buildvariant=user' --pagesize 4096 -o new_boot.img
```

use the exact mkbootimg compile command as above output.
with 1. initramfs.cpio.gz of your phones "boot" img 
     2. zImage of dipper

congrats now you can use the new boot image to separate partitions etc , all features provided by dipper in WOA , note: the "msc" command may not work for all devices, so i recommend you track/find the msc binary then perform the operations related to you mobile yourselves or edit it whatever . 
note 2: i dont know if its universal or not it worked for redmi note 7 pro here so i cant say for sure

toodles
