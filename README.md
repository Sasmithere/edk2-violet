# EDK2 for Redmi Note 7 Pro (Violet)

This project explores creating EDK2/UEFI support for the **Redmi Note 7 Pro (codename: violet)** by leveraging resources from similar Snapdragon devices.  

## Current Progress

- Created a personalized build of **OrangeFox** for Violet.
- Reached Windows 11 logon Screen.

## Purpose of the Boot Image

- Enables the use of **parted** inside the recovery environment.  
- Allows proper partitioning of the **`/dev/block/mmcblk0`** storage device.  


## Personal takes 

- Turns out 850 drivers are compatible with sm6150 after all (lucky me). if some are not , then i'll hex patch them anyway. I aint giving up.
- below drivers from sdm845 currently injected in windows , and i have not found any issues yet :
- 
da----        15-03-2026     19:36                nt36xxx
da----        16-03-2026     22:52                qcgpio850
da----        16-03-2026     22:57                qci2c850
da----        15-03-2026     19:50                qcpmic850
da----        16-03-2026     22:53                qcpmicapps850
da----        16-03-2026     22:53                qcpmicappsext850
da----        15-03-2026     19:46                qcscm850
da----        15-03-2026     19:46                qcsmmu850
da----        16-03-2026     22:53                qcspi850
da----        15-03-2026     19:50                qcspmi850
da----        15-03-2026     19:50                QcTrEE850
da----        16-03-2026     22:54                qcusbc850
da----        16-03-2026     22:54                qcusbcucsi850
da----        16-03-2026     22:54                qcusbfn850
da----        16-03-2026     22:54                QcUsbFnSsFilter850

## Currently in need

1. To build Acpi tables to atleast draw windows gui.
2. If possible add more drivers like cellular or wifi or bt. As far as i have seen wifi and bt are possible ,

toodles
