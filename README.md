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
