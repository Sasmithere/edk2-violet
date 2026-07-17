# EDK2 for Redmi Note 7 Pro (Violet)

This project explores creating EDK2/UEFI support for the **Redmi Note 7 Pro (codename: violet)** by leveraging resources from similar Snapdragon devices.  

## Current Progress

- Created a personalized build of **OrangeFox** for Violet.
- Reached Windows 11 logon Screen.

## Purpose of the Boot Image

- Enables the use of **parted** inside the recovery environment.  
- Allows proper partitioning of the **`/dev/block/mmcblk0`** storage device.  


## Personal takes 

drivers used , 95% drivers from sm8150, others were from 
1. qcsmmu850 - due to smmu bank size
2. qciommu850 - mutual exclusive to qcsmmu
3. qcglink7180 - no slpi
4. qcipa7180 - ipa version
5. qcgsi7180 - mutually exclusive to qcipa
6. qcpep7180 - better compatibility and heavlily patched, i had to yank out slpi and spss because sm6150 aop doesnt understand what it means,
   replaced CBAR RGCR root clocks, halt reg and start reg of specific clocks which were mismatched , PLL fabia isnt compatible so i made it return early,
7. qcdxkm7180 - graphics family close to a612

## Currently needs development on

1. Software rendering
2. gpu/graphics
toodles
