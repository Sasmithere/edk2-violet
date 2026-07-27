# EDK2 for Redmi Note 7 Pro (Violet)

This project explores creating EDK2/UEFI support for the **Redmi Note 7 Pro (codename: violet)** by leveraging resources from similar Snapdragon devices.  

## Current Progress

- Created a personalized build of **OrangeFox** for Violet.
- Reached Windows 11 Desktop

## Purpose of the Boot Image

- Enables the use of **parted** inside the recovery environment.  
- Allows proper partitioning of the **`/dev/block/mmcblk0`** storage device.


## Mount Windows and Esp
use parted or gdisk to get the esp and windows partition name 

```
setprop sys.usb.config none
mkdir -p /config/usb_gadget/g1/configs/b.1/mass_storage.0/lun.1
echo "/dev/block/mmcblk(win)" > /config/usb_gadget/g1/configs/b.1/mass_storage.0/lun.0/file
echo "/dev/block/mmcblk(esp)" > /config/usb_gadget/g1/configs/b.1/mass_storage.0/lun.1/file
ln -s /config/usb_gadget/g1/functions/mass_storage.0/ /config/usb_gadget/g1/configs/b.1/
echo "a600000.dwc3" > /config/usb_gadget/g1/UDC
```

Use Dism++ from the renegade team to install or use dism command to install
if Esp and Windows are on same partition then well , i havent tried that yet, 
what i did was install Windows on win partiton and esp on separate partition , which is the Esp mounted
Dont worry about the mbr partition boot table , technically its GPT on phone , but windows when mounted as Mass Storage , it highlights it as mbr 
Just make sure that windows is on different partition and same for esp 
then use
```
bcdboot D:\Windows /s E: /f UEFI
```
where D: is the letter assigned to your main Windows partition and E: is the letter assigned to your Esp partition

Since this isnt a final end of this project, you need to use kdnet , use below set of bcd commands, i did made a touch driver for whatever reasons its sensing the touch coordinates slow
probably because of software rendering , i might be wrong
```
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {default} bootstatuspolicy IgnoreAllFailures
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {default} recoveryenabled No
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {bootmgr} device locate=\EFI\Microsoft\Boot\bootmgfw.efi
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {bootmgr} flightsigning Yes
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {default} device locate=\Windows\System32\winload.efi
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {default} osdevice locate=\Windows
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {default} loadoptions EEM
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {default} recoveryenabled No
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {default} nointegritychecks Yes
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {default} testsigning Yes
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {default} allowedinmemorysettings 0x15000075
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {default} nx OptIn
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {default} bootmenupolicy Standard
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {default} bootstatuspolicy DisplayAllFailures
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {default} hypervisorlaunchtype Auto
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {default} hypervisoriommupolicy Enable
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {default} quietboot No
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {default} bootlog Yes
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {default} sos Yes
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {default} debug Yes
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {default} disableelamdrivers Yes
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {dbgsettings} busparams 1
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {dbgsettings} key 1.2.3.4
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {dbgsettings} debugtype NET
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {dbgsettings} baudrate 115200
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {dbgsettings} hostip 169.254.255.255
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {dbgsettings} port 50000
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {dbgsettings} dhcp No
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {hypervisorsettings} hypervisordebugtype Serial
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {hypervisorsettings} hypervisordebugport 1
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {hypervisorsettings} hypervisorbaudrate 115200
bcdedit /store E:\EFI\Microsoft\Boot\BCD /set {emssettings} bootems No
```

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

