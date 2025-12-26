typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef pointer32 ImageBaseOffset32;

typedef long long    longlong;
typedef unsigned long long    qword;
typedef unsigned int    uint;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    word;
typedef unsigned short    wchar16;
typedef struct IMAGE_OPTIONAL_HEADER64 IMAGE_OPTIONAL_HEADER64, *PIMAGE_OPTIONAL_HEADER64;

typedef struct IMAGE_DATA_DIRECTORY IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

struct IMAGE_DATA_DIRECTORY {
    ImageBaseOffset32 VirtualAddress;
    dword Size;
};

struct IMAGE_OPTIONAL_HEADER64 {
    word Magic;
    byte MajorLinkerVersion;
    byte MinorLinkerVersion;
    dword SizeOfCode;
    dword SizeOfInitializedData;
    dword SizeOfUninitializedData;
    ImageBaseOffset32 AddressOfEntryPoint;
    ImageBaseOffset32 BaseOfCode;
    pointer64 ImageBase;
    dword SectionAlignment;
    dword FileAlignment;
    word MajorOperatingSystemVersion;
    word MinorOperatingSystemVersion;
    word MajorImageVersion;
    word MinorImageVersion;
    word MajorSubsystemVersion;
    word MinorSubsystemVersion;
    dword Win32VersionValue;
    dword SizeOfImage;
    dword SizeOfHeaders;
    dword CheckSum;
    word Subsystem;
    word DllCharacteristics;
    qword SizeOfStackReserve;
    qword SizeOfStackCommit;
    qword SizeOfHeapReserve;
    qword SizeOfHeapCommit;
    dword LoaderFlags;
    dword NumberOfRvaAndSizes;
    struct IMAGE_DATA_DIRECTORY DataDirectory[16];
};

typedef struct IMAGE_SECTION_HEADER IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

typedef union Misc Misc, *PMisc;

typedef enum SectionFlags {
    IMAGE_SCN_TYPE_NO_PAD=8,
    IMAGE_SCN_RESERVED_0001=16,
    IMAGE_SCN_CNT_CODE=32,
    IMAGE_SCN_CNT_INITIALIZED_DATA=64,
    IMAGE_SCN_CNT_UNINITIALIZED_DATA=128,
    IMAGE_SCN_LNK_OTHER=256,
    IMAGE_SCN_LNK_INFO=512,
    IMAGE_SCN_RESERVED_0040=1024,
    IMAGE_SCN_LNK_REMOVE=2048,
    IMAGE_SCN_LNK_COMDAT=4096,
    IMAGE_SCN_GPREL=32768,
    IMAGE_SCN_MEM_16BIT=131072,
    IMAGE_SCN_MEM_PURGEABLE=131072,
    IMAGE_SCN_MEM_LOCKED=262144,
    IMAGE_SCN_MEM_PRELOAD=524288,
    IMAGE_SCN_ALIGN_1BYTES=1048576,
    IMAGE_SCN_ALIGN_2BYTES=2097152,
    IMAGE_SCN_ALIGN_4BYTES=3145728,
    IMAGE_SCN_ALIGN_8BYTES=4194304,
    IMAGE_SCN_ALIGN_16BYTES=5242880,
    IMAGE_SCN_ALIGN_32BYTES=6291456,
    IMAGE_SCN_ALIGN_64BYTES=7340032,
    IMAGE_SCN_ALIGN_128BYTES=8388608,
    IMAGE_SCN_ALIGN_256BYTES=9437184,
    IMAGE_SCN_ALIGN_512BYTES=10485760,
    IMAGE_SCN_ALIGN_1024BYTES=11534336,
    IMAGE_SCN_ALIGN_2048BYTES=12582912,
    IMAGE_SCN_ALIGN_4096BYTES=13631488,
    IMAGE_SCN_ALIGN_8192BYTES=14680064,
    IMAGE_SCN_LNK_NRELOC_OVFL=16777216,
    IMAGE_SCN_MEM_DISCARDABLE=33554432,
    IMAGE_SCN_MEM_NOT_CACHED=67108864,
    IMAGE_SCN_MEM_NOT_PAGED=134217728,
    IMAGE_SCN_MEM_SHARED=268435456,
    IMAGE_SCN_MEM_EXECUTE=536870912,
    IMAGE_SCN_MEM_READ=1073741824,
    IMAGE_SCN_MEM_WRITE=2147483648
} SectionFlags;

union Misc {
    dword PhysicalAddress;
    dword VirtualSize;
};

struct IMAGE_SECTION_HEADER {
    char Name[8];
    union Misc Misc;
    ImageBaseOffset32 VirtualAddress;
    dword SizeOfRawData;
    dword PointerToRawData;
    dword PointerToRelocations;
    dword PointerToLinenumbers;
    word NumberOfRelocations;
    word NumberOfLinenumbers;
    enum SectionFlags Characteristics;
};

typedef struct IMAGE_NT_HEADERS64 IMAGE_NT_HEADERS64, *PIMAGE_NT_HEADERS64;

typedef struct IMAGE_FILE_HEADER IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

struct IMAGE_FILE_HEADER {
    word Machine; // 43620
    word NumberOfSections;
    dword TimeDateStamp;
    dword PointerToSymbolTable;
    dword NumberOfSymbols;
    word SizeOfOptionalHeader;
    word Characteristics;
};

struct IMAGE_NT_HEADERS64 {
    char Signature[4];
    struct IMAGE_FILE_HEADER FileHeader;
    struct IMAGE_OPTIONAL_HEADER64 OptionalHeader;
};

typedef struct IMAGE_DEBUG_DIRECTORY IMAGE_DEBUG_DIRECTORY, *PIMAGE_DEBUG_DIRECTORY;

struct IMAGE_DEBUG_DIRECTORY {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    dword Type;
    dword SizeOfData;
    dword AddressOfRawData;
    dword PointerToRawData;
};

typedef struct IMAGE_DOS_HEADER IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

struct IMAGE_DOS_HEADER {
    char e_magic[2]; // Magic number
    word e_cblp; // Bytes of last page
    word e_cp; // Pages in file
    word e_crlc; // Relocations
    word e_cparhdr; // Size of header in paragraphs
    word e_minalloc; // Minimum extra paragraphs needed
    word e_maxalloc; // Maximum extra paragraphs needed
    word e_ss; // Initial (relative) SS value
    word e_sp; // Initial SP value
    word e_csum; // Checksum
    word e_ip; // Initial IP value
    word e_cs; // Initial (relative) CS value
    word e_lfarlc; // File address of relocation table
    word e_ovno; // Overlay number
    word e_res[4][4]; // Reserved words
    word e_oemid; // OEM identifier (for e_oeminfo)
    word e_oeminfo; // OEM information; e_oemid specific
    word e_res2[10][10]; // Reserved words
    dword e_lfanew; // File address of new exe header
    byte e_program[3608]; // Actual DOS program
};

typedef struct PdbInfo PdbInfo, *PPdbInfo;

struct PdbInfo {
    char signature[4];
    dword offset;
    dword sig;
    dword age;
    char pdbpath[188];
};



undefined8 DAT_00016008;
undefined8 .data;
longlong DAT_00016e88;
undefined *PTR_LAB_00006308;
undefined8 DAT_00017258;
undefined8 DAT_00017260;
longlong DAT_00017260;
undefined FUN_00002940;
undefined FUN_00002a40;
undefined FUN_00002d44;
undefined FUN_00002b70;
undefined8 DAT_00016470;
undefined *DAT_00016478;
undefined8 DAT_00016468;
undefined8 DAT_00016498;
undefined1 *DAT_000164a0;
undefined8 DAT_00016f48;
undefined4 DAT_00016f20;
undefined1 DAT_0001723c;
undefined8 DAT_00016f40;
undefined8 DAT_00016d30;
undefined4 DAT_00016d20;
undefined4 DAT_00016d24;
undefined8 DAT_00016d78;
undefined8 DAT_00016d80;
undefined1 *DAT_00016d70;
undefined8 DAT_00016d68;
undefined8 DAT_00016e10;
undefined1 *DAT_00016e18;
undefined1 DAT_00016f30;
IMAGE_DOS_HEADER IMAGE_DOS_HEADER_00000000;
undefined LAB_00002354;
undefined FUN_00002e30;
undefined LAB_00002848;
undefined LAB_00002cdc;
undefined LAB_00002ec8;
undefined LAB_00002ecc;
undefined DAT_00011ddc;
undefined DAT_000160a8;
undefined DAT_000160b8;
undefined DAT_000160c8;
undefined DAT_000160d8;
undefined DAT_000161c8;
undefined DAT_000161d8;
undefined DAT_000161e8;
undefined DAT_000161f8;
undefined DAT_00016208;
undefined DAT_00016238;
undefined4 DAT_000163a8;
undefined DAT_000163c0;
undefined8 DAT_000164a8;
undefined DAT_00016788;
undefined DAT_00016cf0;
undefined8 DAT_00016f28;
undefined8 DAT_00016f38;
undefined DAT_00016f50;
undefined DAT_00016f58;
undefined DAT_00016f60;
undefined4 DAT_00016f68;
undefined DAT_00016fb4;
undefined DAT_00017078;
undefined DAT_000171f8;
undefined FUN_000038c0;
char DAT_0001723c;
undefined4 DAT_00017238;
uint DAT_00017238;
char DAT_0001723e;
uint DAT_00016f20;
undefined8 *DAT_00017220;
char DAT_00017230;
undefined8 *DAT_00017228;
undefined8 *DAT_00017218;
undefined8 *DAT_00017210;
undefined DAT_000186a0;
int DAT_00016f7c;
undefined4 DAT_00016fa8;
int DAT_00016f6c;
undefined4 DAT_00016f74;
char DAT_00016fac;
longlong DAT_00016d30;
char DAT_00016f30;
undefined8 DAT_00016d28;
undefined DAT_000162d8;
undefined DAT_00016d38;
longlong DAT_00017220;
undefined1 DAT_0001723f;
undefined8 DAT_00017240;
int DAT_00017238;
char DAT_0001723f;
undefined8 *DAT_00017240;
undefined DAT_00016e48;
undefined DAT_00011f40;
undefined DAT_00011f50;
undefined DAT_0359a000;
undefined DAT_03d98000;
undefined DAT_01fc8004;
undefined DAT_00016278;
undefined LAB_000042c0;
undefined FUN_000042b8;
undefined FUN_000042b0;
undefined8 DAT_00017248;
longlong DAT_00017248;
undefined DAT_00012112;
longlong DAT_00017250;
longlong DAT_00017258;
uint DAT_00017268;
undefined8 *DAT_00017270;
undefined8 *DAT_00017278;
undefined8 *DAT_00017280;
longlong DAT_00017288;
undefined8 DAT_00017290;
undefined DAT_00016128;
undefined1 DAT_00017298;
longlong DAT_000172a0;
undefined LAB_00005894;
undefined8 DAT_000172a8;
undefined8 DAT_000172b0;
undefined FUN_000058a4;
undefined8 DAT_000172b8;
char DAT_000172c0;
undefined DAT_000162b8;
undefined1 DAT_000172c0;
undefined LAB_00005b4c;
undefined8 DAT_000172c8;
undefined8 DAT_000172d0;
undefined FUN_00005b6c;
undefined8 *DAT_000172b8;
undefined DAT_00016018;
undefined8 DAT_000172d8;
undefined DAT_00016138;
pointer PTR_LOOP_00016e60;
undefined8 DAT_000172e8;
undefined DAT_00013244;
byte DAT_000172e0;
ulonglong DAT_000172f0;
ulonglong DAT_000172e8;
ulonglong DAT_00017300;
ulonglong DAT_000172f8;
char *DAT_00017320;
uint DAT_00017328;
char DAT_00017310;
int DAT_00017314;
byte DAT_00017308;
undefined LAB_00006fc4;
undefined UNK_000135b0;
undefined DAT_00017348;
longlong DAT_00017330;
uint DAT_00017314;
undefined DAT_00013362;
undefined DAT_00017338;
int DAT_00017318;
undefined1 DAT_00017311;
undefined1 DAT_00017308;
undefined8 DAT_00017320;
undefined4 DAT_00017328;
undefined UNK_00013e28;
undefined DAT_00013e68;
undefined DAT_000177b4;
undefined DAT_000175a0;
undefined DAT_00017838;
undefined DAT_000177a0;
byte DAT_00017648;
byte DAT_0001764b;
byte DAT_0001764d;
int DAT_00016e90;
undefined8 DAT_000178a8;
undefined DAT_000140a0;
undefined DAT_000140c0;
undefined DAT_000140e0;
undefined1 DAT_00017a48;
undefined1 DAT_00017a28;
uint DAT_00017a2c;
ulonglong DAT_00017a30;
uint *DAT_00017a38;
uint DAT_00017a40;
char DAT_00017a28;
int DAT_00017a40;
uint DAT_00018400;
undefined DAT_000146a0;
undefined DAT_000146e0;
undefined DAT_00014700;
undefined DAT_000177a4;
longlong DAT_000183f8;
undefined DAT_000162c8;
undefined1 DAT_000183f0;
undefined FUN_0000c710;
undefined LAB_0000d0cc;
undefined DAT_000161b8;
undefined DAT_000183e8;
char DAT_000183f0;
pointer PTR_DAT_00014870;
pointer PTR_DAT_00014960;
longlong DAT_00018408;
undefined1 DAT_00018404;
undefined FUN_0000d30c;
undefined4 DAT_00018400;
char DAT_00018404;
int DAT_00018400;
undefined UNK_0001533d;
undefined UNK_00015340;
undefined *PTR_s_Success_00015348;
undefined8 DAT_00018410;
longlong DAT_00018410;
byte DAT_00018418;
longlong DAT_00018420;
undefined DAT_00016ea8;
undefined8 DAT_00018420;
undefined1 DAT_00018418;
undefined DAT_00016258;
pointer PTR_s_gcc_sdcc1_apps_clk_00016ea0;
pointer PTR_s_gcc_sdcc1_ahb_clk_00016eb0;
undefined DAT_00016eb8;
undefined DAT_000160e8;
undefined DAT_000160f8;
undefined DAT_00016268;
undefined DAT_000162a8;
undefined DAT_00016288;
undefined DAT_00016118;
int *DAT_00018430;
uint DAT_00018428;
undefined4 DAT_00018494;
undefined8 DAT_00018438;
undefined8 DAT_00018440;
undefined8 DAT_00018450;
undefined8 DAT_00018458;
undefined DAT_00018471;

void entry(longlong param_1,char *param_2)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  
  if (param_1 != 0) {
    if ((((param_2 == (char *)0x0) || (*param_2 != 'I')) || (param_2[1] != 'B')) ||
       (param_2[2] != 'I')) {
      FUN_000010f4();
    }
    else {
      lVar2 = *(longlong *)(param_2 + 0x68);
      plVar1 = *(longlong **)(param_2 + 0x70);
      do {
        plVar3 = plVar1;
        if (lVar2 == 0) {
          FUN_000010f4();
          (**(code **)(*(longlong *)(param_2 + 0x60) + 0xc0))(&DAT_00016008,_data);
          goto LAB_000010bc;
        }
        lVar2 = lVar2 + -1;
        plVar1 = plVar3 + 3;
      } while (*plVar3 != DAT_00016008);
      _data = plVar3[2];
    }
  }
LAB_000010bc:
  FUN_00001150(param_1,(longlong)param_2);
  return;
}



// WARNING: Removing unreachable block (ram,0x000010ec)

void FUN_000010d8(void)

{
                    // WARNING: Do nothing block with infinite loop
  do {
  } while( true );
}



void FUN_000010f4(void)

{
  _data = thunk_FUN_000062ec();
  return;
}



void thunk_FUN_000062ec(void)

{
                    // WARNING: Could not recover jumptable at 0x00006304. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)((longlong)&PTR_LAB_00006308 + DAT_00016e88))();
  return;
}



longlong FUN_00001114(void)

{
  longlong lVar1;
  
  lVar1 = FUN_000015b0();
  if (-1 < lVar1) {
    FUN_000014cc();
  }
  return lVar1;
}



// WARNING: Removing unreachable block (ram,0x000011a4)
// WARNING: Removing unreachable block (ram,0x000011cc)
// WARNING: Removing unreachable block (ram,0x000011f8)
// WARNING: Removing unreachable block (ram,0x00001174)
// WARNING: Removing unreachable block (ram,0x00001180)

longlong FUN_00001150(longlong param_1,longlong param_2)

{
  longlong lVar1;
  
  FUN_0000123c(param_1,param_2);
  lVar1 = thunk_FUN_00003014();
  if (lVar1 < 0) {
    FUN_000014cc();
  }
  return lVar1;
}



ulonglong FUN_0000123c(longlong param_1,longlong param_2)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  lVar2 = FUN_00005480(param_1,param_2);
  if (lVar2 < 0) {
    FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
    FUN_0000464c();
  }
  lVar2 = thunk_FUN_00005510();
  if (lVar2 < 0) {
    FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
    FUN_0000464c();
  }
  lVar2 = FUN_000055f0(param_1,param_2);
  if (lVar2 < 0) {
    FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
    FUN_0000464c();
  }
  lVar2 = FUN_00005630();
  if (lVar2 < 0) {
    FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
    FUN_0000464c();
  }
  lVar2 = FUN_00005808();
  if (lVar2 < 0) {
    FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
    FUN_0000464c();
  }
  lVar2 = FUN_000058e0();
  if (lVar2 < 0) {
    FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
    FUN_0000464c();
  }
  lVar2 = FUN_00005b8c();
  if (lVar2 < 0) {
    FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
    FUN_0000464c();
  }
  lVar2 = FUN_00005ed8();
  if (lVar2 < 0) {
    FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
    FUN_0000464c();
  }
  lVar2 = FUN_00005fc4();
  if (lVar2 < 0) {
    FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
    FUN_0000464c();
  }
  uVar3 = FUN_00006068();
  if (-1 < (longlong)uVar3) {
    return uVar3;
  }
  FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
  uVar1 = FUN_0000464c();
  return (ulonglong)uVar1;
}



ulonglong FUN_000014cc(void)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  lVar2 = FUN_000061c4();
  if (lVar2 < 0) {
    FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
    FUN_0000464c();
  }
  lVar2 = FUN_00005c78();
  if (lVar2 < 0) {
    FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
    FUN_0000464c();
  }
  uVar3 = FUN_00005a18();
  if (-1 < (longlong)uVar3) {
    return uVar3;
  }
  FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
  uVar1 = FUN_0000464c();
  return (ulonglong)uVar1;
}



longlong thunk_FUN_00003014(void)

{
  bool bVar1;
  longlong lVar2;
  longlong lVar3;
  undefined *puVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  undefined8 *puVar8;
  undefined *puVar9;
  undefined4 *puVar10;
  undefined *puVar11;
  undefined8 *puVar12;
  undefined4 *puVar13;
  undefined *puVar14;
  undefined4 *puVar15;
  undefined8 uStack_70;
  undefined8 uStack_68;
  
  uStack_70 = 0;
  uStack_68 = 0;
  FUN_00004728((undefined8 *)&DAT_00016f68,IMAGE_DOS_HEADER_00000000.e_program + 0xc);
  lVar2 = (**(code **)(DAT_00017260 + 0x140))(&DAT_000160d8,0,&uStack_68);
  if (lVar2 != 0) {
    bVar1 = FUN_000042e8();
    if (bVar1) {
      puVar12 = (undefined8 *)&DAT_00017078;
      puVar13 = (undefined4 *)&DAT_00016fb4;
      puVar14 = &DAT_00011ddc;
      puVar15 = &DAT_000163a8;
      for (lVar2 = 0; lVar2 != 8; lVar2 = lVar2 + 1) {
        *(undefined8 *)(puVar15 + 4) = 0;
        puVar8 = (undefined8 *)(puVar15 + 0x12);
        *(undefined8 *)(puVar15 + 0x16) = 0;
        *(undefined8 *)(puVar15 + 0x18) = 0;
        *(undefined8 *)(puVar15 + 0x12) = 0x10003;
        *(undefined1 **)(puVar15 + 0x14) = &LAB_00002354;
        *puVar15 = 0x63636473;
        puVar15[1] = 0;
        if (lVar2 == 3) {
          FUN_0000dabc(0x16788,0x11d90,0x38);
        }
        else {
          FUN_0000dabc((longlong)(puVar15 + 6),0x16350,0x30);
          FUN_0000dabc((longlong)(puVar15 + 0x40),0x16380,0x28);
          *(undefined8 **)(puVar15 + 8) = puVar12;
          *(undefined8 **)(puVar15 + 0x40) = puVar12;
          FUN_000047cc(puVar12,(undefined8 *)&DAT_00016cf0,0x30);
          *(code **)(puVar15 + 0x2c) = FUN_00002940;
          *(code **)(puVar15 + 0x2e) = FUN_00002a40;
          *(undefined8 *)(puVar15 + 0x28) = 0x10000;
          *(undefined1 **)(puVar15 + 0x2a) = &LAB_00002848;
          if (lVar2 == 0) {
            DAT_00016470 = 0x200;
            DAT_00016478 = FUN_00002b70;
            DAT_00016468 = 0x2003c;
            DAT_00016498 = 0x10000;
            DAT_000164a0 = &LAB_00002cdc;
          }
        }
        FUN_0000dabc((longlong)puVar13,0x11dc8,0x14);
        FUN_0000dabc((longlong)(puVar13 + 1),(longlong)puVar14,0x10);
        *(undefined1 *)(puVar13 + 5) = 0x7f;
        *(undefined1 *)((longlong)puVar13 + 0x17) = 0;
        *(undefined1 *)((longlong)puVar13 + 0x16) = 4;
        *(undefined1 *)((longlong)puVar13 + 0x15) = 0xff;
        lVar3 = FUN_0000213c((longlong)puVar15,(uint)lVar2);
        puVar14 = puVar14 + 0x10;
        if (lVar3 == 0) {
          puVar10 = puVar13;
          if (lVar2 == 0) {
            puVar6 = (undefined4 *)&DAT_000163c0;
            puVar8 = &DAT_000164a8;
            puVar4 = &DAT_000161c8;
            puVar7 = &DAT_000161d8;
            puVar9 = &DAT_000161e8;
            puVar11 = &DAT_000161f8;
          }
          else if (lVar2 == 3) {
            puVar4 = &DAT_000161e8;
            puVar7 = &DAT_000161f8;
            puVar9 = &DAT_00016208;
            puVar11 = (undefined *)0x0;
            puVar6 = puVar13;
            puVar10 = (undefined4 *)&DAT_00016788;
          }
          else {
            puVar6 = puVar15 + 6;
            puVar8 = (undefined8 *)(puVar15 + 0x40);
            puVar4 = &DAT_000161c8;
            puVar7 = &DAT_000161d8;
            puVar9 = &DAT_000161e8;
            puVar11 = &DAT_000161f8;
          }
          lVar3 = (**(code **)(DAT_00017260 + 0x148))
                            (puVar15 + 2,puVar4,puVar6,puVar7,puVar8,puVar9,puVar10,puVar11);
          if (lVar3 < 0) {
            FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
            FUN_0000464c();
          }
        }
        puVar12 = puVar12 + 6;
        puVar13 = puVar13 + 6;
        puVar15 = puVar15 + 0x4a;
      }
      lVar2 = FUN_0000d0ec();
      if (lVar2 != 0) {
        pcVar5 = "Failed to allocate memory for RPMB listener\n";
LAB_00003370:
        FUN_00004548(0x80000000,(byte *)pcVar5);
        return lVar2;
      }
      lVar2 = FUN_0000c4e4();
      if (lVar2 != 0) {
        pcVar5 = "Failed to allocate memory for GPT listener\n";
        goto LAB_00003370;
      }
      lVar2 = (**(code **)(DAT_00017260 + 0x140))(&DAT_00016238,0,&uStack_70);
      if (lVar2 == 0) {
        FUN_00002e30(0,0x163c0);
      }
      else {
        lVar2 = (**(code **)(DAT_00017260 + 0x50))(0x200,8,FUN_00002e30,&DAT_000163c0,&DAT_00016f48)
        ;
        if (lVar2 < 0) {
          FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
          FUN_0000464c();
        }
        lVar2 = (**(code **)(DAT_00017260 + 0xa8))(&DAT_00016238,DAT_00016f48,&DAT_00016f50);
        if (lVar2 < 0) {
          FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
          FUN_0000464c();
        }
      }
      DAT_00016f20 = 0;
      DAT_0001723c = 1;
      lVar2 = FUN_00003d4c((undefined8 *)&DAT_000171f8,0x80);
      if ((lVar2 != 0) ||
         (lVar2 = (**(code **)(DAT_00017260 + 0x50))(0x80000200,8,FUN_000038c0,0,&DAT_00016f28),
         lVar2 < 0)) {
        DAT_0001723c = 0;
      }
    }
    DAT_00016d30 = DAT_00016f40;
    DAT_00016d20 = 0x63636473;
    DAT_00016d24 = 1;
    FUN_0000dabc(0x16d38,0x16320,0x30);
    DAT_00016d78 = 0;
    DAT_00016d80 = 0;
    DAT_00016d70 = &LAB_00002354;
    DAT_00016d68 = 0x10003;
    DAT_00016e10 = 0x10000;
    DAT_00016e18 = &LAB_00002cdc;
    lVar2 = (**(code **)(DAT_00017260 + 0x170))(0x200,8,FUN_00002d44,0,&DAT_000160a8,&DAT_00016f38);
    if (lVar2 < 0) {
      FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
      FUN_0000464c();
    }
    DAT_00016f30 = 1;
    lVar2 = (**(code **)(DAT_00017260 + 0x170))(0x200,8,&LAB_00002ec8,0,&DAT_000160b8,&DAT_00016f58)
    ;
    if (lVar2 < 0) {
      FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
      FUN_0000464c();
    }
    lVar2 = (**(code **)(DAT_00017260 + 0x170))(0x200,8,&LAB_00002ecc,0,&DAT_000160c8,&DAT_00016f60)
    ;
    if (-1 < lVar2) {
      return 0;
    }
    FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
    FUN_0000464c();
  }
  return 0;
}



undefined8 FUN_000015b0(void)

{
  return 0;
}



longlong FUN_000015c0(int *param_1,int param_2,ulonglong param_3,ulonglong param_4,
                     undefined4 *param_5)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  ulonglong uVar4;
  longlong lVar5;
  longlong lVar6;
  longlong *plVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  
  lVar6 = -0x7ffffffffffffffe;
  lVar5 = -0x7ffffffffffffffe;
  if (((param_1 != (int *)0x0) && (lVar5 = lVar6, param_5 != (undefined4 *)0x0)) &&
     (piVar3 = *(int **)(param_1 + 2), piVar3 != (int *)0x0)) {
    uVar4 = (ulonglong)(uint)piVar3[3];
    uVar9 = 0;
    if (uVar4 != 0) {
      uVar9 = param_4 / uVar4;
    }
    if (param_4 == uVar9 * uVar4) {
      if ((piVar3[3] != 0) && (param_3 <= *(ulonglong *)(piVar3 + 6))) {
        if (*piVar3 == param_2) {
          piVar3 = param_1 + -6;
          if (param_1[-6] != 0x63636473) {
            FUN_0000464c();
            piVar3 = param_1;
          }
          plVar7 = *(longlong **)(piVar3 + 4);
          lVar5 = *(longlong *)(piVar3 + 8);
          if ((plVar7 != (longlong *)0x0) || (*(char *)(lVar5 + 4) == '\0')) {
            if (param_4 == 0) {
              uVar9 = FUN_00007884(plVar7);
              if ((uVar9 & 0xff) == 0) {
                FUN_00007650(plVar7);
                piVar3[4] = 0;
                piVar3[5] = 0;
                *(undefined1 *)(*(longlong *)(piVar3 + 8) + 5) = 0;
                return -0x7ffffffffffffff4;
              }
            }
            else {
              uVar1 = *(uint *)(lVar5 + 0xc);
              uVar9 = 0;
              if ((ulonglong)uVar1 != 0) {
                uVar9 = param_4 / uVar1;
              }
              if (*(longlong *)(lVar5 + 0x18) + 1U < uVar9 + param_3) {
                return -0x7ffffffffffffffe;
              }
              while (uVar8 = (uint)uVar9, uVar8 != 0) {
                uVar10 = uVar8;
                if (0x3fff < uVar8) {
                  uVar10 = 0x4000;
                }
                uVar2 = FUN_0000791c(plVar7,(int)param_3,param_5,uVar10);
                param_3 = param_3 + uVar10;
                uVar9 = (ulonglong)(uVar8 - uVar10);
                param_5 = (undefined4 *)((longlong)param_5 + (ulonglong)(uVar10 * uVar1));
                if (uVar2 != 0) {
                  FUN_00001c1c(uVar2);
                  if ((uVar2 < 0x1c) && ((1 << (ulonglong)(uVar2 & 0x1f) & 0x8200004U) != 0)) {
                    FUN_00007650(plVar7);
                    piVar3[4] = 0;
                    piVar3[5] = 0;
                    *(undefined1 *)(*(longlong *)(piVar3 + 8) + 5) = 0;
                    return -0x7ffffffffffffff4;
                  }
                  if (uVar2 == 0x14) {
                    return -0x7ffffffffffffffe;
                  }
                  return -0x7ffffffffffffff9;
                }
              }
            }
            return 0;
          }
          lVar5 = FUN_0000213c((longlong)piVar3,0);
          if (lVar5 != 0) {
            return lVar5;
          }
          (**(code **)(DAT_00017260 + 0x88))
                    (*(undefined8 *)(piVar3 + 2),&DAT_000161c8,piVar3 + 6,piVar3 + 6);
        }
        lVar5 = -0x7ffffffffffffff3;
      }
    }
    else {
      lVar5 = -0x7ffffffffffffffc;
    }
  }
  return lVar5;
}



undefined8
FUN_000017c4(int *param_1,int param_2,ulonglong param_3,ulonglong param_4,undefined4 *param_5)

{
  undefined8 uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  longlong *plVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  
  uVar6 = 0x8000000000000002;
  if (((param_1 != (int *)0x0) && (param_5 != (undefined4 *)0x0)) &&
     (piVar4 = *(int **)(param_1 + 2), piVar4 != (int *)0x0)) {
    uVar5 = (ulonglong)(uint)piVar4[3];
    uVar9 = 0;
    if (uVar5 != 0) {
      uVar9 = param_4 / uVar5;
    }
    if (param_4 == uVar9 * uVar5) {
      if ((piVar4[3] != 0) &&
         (param_3 <= *(ulonglong *)(piVar4 + 6) && uVar9 + param_3 <= *(ulonglong *)(piVar4 + 6) + 1
         )) {
        if (*piVar4 == param_2) {
          piVar4 = param_1 + -6;
          if (param_1[-6] != 0x63636473) {
            FUN_0000464c();
            piVar4 = param_1;
          }
          plVar7 = *(longlong **)(piVar4 + 4);
          if (plVar7 != (longlong *)0x0) {
            uVar2 = *(uint *)(*(longlong *)(piVar4 + 8) + 0xc);
            uVar9 = 0;
            if ((ulonglong)uVar2 != 0) {
              uVar9 = param_4 / uVar2;
            }
            do {
              uVar8 = (uint)uVar9;
              if (uVar8 == 0) {
                return 0;
              }
              uVar10 = uVar8;
              if (0x3fff < uVar8) {
                uVar10 = 0x4000;
              }
              uVar3 = FUN_00007a74(plVar7,(int)param_3,param_5,uVar10);
              param_3 = param_3 + uVar10;
              uVar9 = (ulonglong)(uVar8 - uVar10);
              param_5 = (undefined4 *)((longlong)param_5 + (ulonglong)(uVar10 * uVar2));
            } while (uVar3 == 0);
            FUN_00001c1c(uVar3);
            if ((uVar3 < 0x1c) && ((1 << (ulonglong)(uVar3 & 0x1f) & 0x8200004U) != 0)) {
              FUN_00007650(plVar7);
              piVar4[4] = 0;
              piVar4[5] = 0;
              *(undefined1 *)(*(longlong *)(piVar4 + 8) + 5) = 0;
              uVar6 = 0x800000000000000c;
            }
            else {
              uVar1 = 0x8000000000000008;
              if (uVar3 != 0x1d) {
                uVar1 = 0x8000000000000007;
              }
              if (uVar3 != 0x14) {
                uVar6 = uVar1;
              }
            }
          }
        }
        else {
          uVar6 = 0x800000000000000d;
        }
      }
    }
    else {
      uVar6 = 0x8000000000000004;
    }
  }
  return uVar6;
}



longlong FUN_00001a9c(int *param_1,int param_2,ulonglong param_3,longlong *param_4,ulonglong param_5
                     ,undefined4 *param_6)

{
  undefined8 uVar1;
  longlong lVar2;
  
  uVar1 = (**(code **)(DAT_00017260 + 0x18))(8);
  if (DAT_0001723c == '\0') {
    lVar2 = -0x7ffffffffffffff7;
  }
  else {
    DAT_00017238 = 2;
    lVar2 = FUN_00001e2c(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  (**(code **)(DAT_00017260 + 0x20))(uVar1);
  return lVar2;
}



longlong FUN_00001b58(int *param_1,int param_2,ulonglong param_3,longlong *param_4,ulonglong param_5
                     ,undefined4 *param_6)

{
  undefined8 uVar1;
  longlong lVar2;
  
  uVar1 = (**(code **)(DAT_00017260 + 0x18))(8);
  if (DAT_0001723c == '\0') {
    lVar2 = -0x7ffffffffffffff7;
  }
  else {
    DAT_00017238 = 3;
    lVar2 = FUN_00001e2c(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  (**(code **)(DAT_00017260 + 0x20))(uVar1);
  return lVar2;
}



void FUN_00001c1c(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    return;
  case 1:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_UNKNOWN\n");
    return;
  case 2:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_CMD_TIMEOUT\n");
    return;
  case 3:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_TIMEOUT\n");
    return;
  case 4:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_CMD_CRC_FAIL\n");
    return;
  case 5:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_DATA_CRC_FAIL\n");
    return;
  case 6:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_CMD_SENT\n");
    return;
  case 7:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_PROG_DONE\n");
    return;
  case 8:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_CARD_READY\n");
    return;
  case 9:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_INVALID_TX_STATE\n");
    return;
  case 10:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_SET_BLKSZ\n");
    return;
  case 0xb:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_SDIO_R5_RESP\n");
    return;
  case 0xc:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_DMA\n");
    return;
  case 0xd:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_READ_FIFO\n");
    return;
  case 0xe:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_WRITE_FIFO\n");
    return;
  case 0xf:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_ERAE\n");
    return;
  case 0x10:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_SDIO\n");
    return;
  case 0x11:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_SDIO_READ\n");
    return;
  case 0x12:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_SDIO_WRITE\n");
    return;
  case 0x13:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_SWITCH\n");
    return;
  case 0x14:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_INVALID_PARAM\n");
    return;
  case 0x15:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_CARD_UNDETECTED\n");
    return;
  case 0x16:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_FEATURE_UNSUPPORTED\n");
    return;
  case 0x17:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_SECTURE_COMMAND_IN_PROGRESS\n");
    return;
  case 0x18:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_CMD_NOT_ALLOWED\n");
    return;
  case 0x19:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_READ_SEC_CMD\n");
    return;
  case 0x1a:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_CARD_INIT\n");
    return;
  case 0x1b:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_CARD_REMOVED\n");
    return;
  case 0x1c:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_PWR_ON_WRITE_PROTECT \n");
    return;
  case 0x1d:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_WP_VIOLATION\n");
    return;
  case 0x1e:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns ERR_SPS_MODE\n");
    return;
  default:
    FUN_00004548(0x80000000,(byte *)"SDCC driver returns error that can not be decoded.\n");
    return;
  }
}



longlong FUN_00001e2c(int *param_1,int param_2,ulonglong param_3,longlong *param_4,ulonglong param_5
                     ,undefined4 *param_6)

{
  ulonglong uVar1;
  uint uVar2;
  int *piVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined4 uStack_54;
  
  if ((DAT_00017238 | 1) == 1) {
    if (DAT_0001723e == '\x01') {
      (**(code **)(DAT_00017260 + 0x58))(DAT_00016f28,0,0);
    }
    uVar2 = FUN_0000a650(DAT_00016f20,&uStack_54);
    if (uVar2 == 3) {
      lVar5 = -0x7ffffffffffffff9;
    }
    else if (*(char *)((longlong)DAT_00017220 + 0x34) == '\0') {
      if (DAT_00017238 == 0) {
        lVar5 = FUN_000015c0(param_1,param_2,param_3,param_5,param_6);
      }
      else {
        lVar5 = FUN_000017c4(param_1,param_2,param_3,param_5,param_6);
      }
      if (DAT_0001723e == '\x01') {
        (**(code **)(DAT_00017260 + 0x58))(DAT_00016f28,1,&DAT_000186a0);
      }
    }
    else {
      lVar5 = FUN_00003690(param_1,param_2,param_3,param_5,param_6);
      if (DAT_0001723e == '\x01') {
        (**(code **)(DAT_00017260 + 0x58))(DAT_00016f28,1,&DAT_000186a0);
      }
    }
  }
  else {
    lVar5 = -0x7ffffffffffffffe;
    if ((((param_1 != (int *)0x0) && (param_6 != (undefined4 *)0x0)) && (param_4 != (longlong *)0x0)
        ) && ((piVar3 = *(int **)param_1, piVar3 != (int *)0x0 && (*param_4 != 0)))) {
      uVar4 = (ulonglong)(uint)piVar3[3];
      uVar1 = 0;
      if (uVar4 != 0) {
        uVar1 = param_5 / uVar4;
      }
      if (param_5 == uVar1 * uVar4) {
        if (piVar3[3] == 0) {
          return -0x7ffffffffffffffe;
        }
        if (*(ulonglong *)(piVar3 + 6) < param_3) {
          return -0x7ffffffffffffffe;
        }
        if (*piVar3 != param_2) {
          return -0x7ffffffffffffff3;
        }
        if (param_5 != 0) {
          piVar3 = param_1 + -0x40;
          if (param_1[-0x40] != 0x63636473) {
            FUN_0000464c();
            piVar3 = param_1;
          }
          uVar4 = (ulonglong)*(uint *)(*(longlong *)(piVar3 + 8) + 0xc);
          uVar1 = 0;
          if (uVar4 != 0) {
            uVar1 = param_5 / uVar4;
          }
          if (*(longlong *)(*(longlong *)(piVar3 + 8) + 0x18) + 1U < uVar1 + param_3) {
            return -0x7ffffffffffffffe;
          }
          FUN_00005710((undefined8 *)&DAT_000171f8);
          if (DAT_00017230 == '\x01') {
            FUN_00005794(0x171f8);
            return -0x7ffffffffffffff7;
          }
          DAT_00017228[3] = param_4;
          *DAT_00017228 = param_1;
          *(int *)(DAT_00017228 + 1) = param_2;
          DAT_00017228[2] = param_3;
          DAT_00017228[4] = param_5;
          uVar2 = DAT_00017238;
          DAT_00017228[5] = param_6;
          *(uint *)(DAT_00017228 + 6) = (uint)(uVar2 != 2);
          DAT_00017228 = DAT_00017228 + 7;
          if (DAT_00017228 == DAT_00017218) {
            DAT_00017228 = DAT_00017210;
          }
          if (DAT_00017228 == DAT_00017220) {
            DAT_00017230 = '\x01';
          }
          FUN_00005794(0x171f8);
          FUN_000038c0();
          return 0;
        }
      }
      lVar5 = -0x7ffffffffffffffc;
    }
  }
  return lVar5;
}



// WARNING: Removing unreachable block (ram,0x000022cc)

undefined8 FUN_0000213c(longlong param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  longlong *plVar4;
  ulonglong uVar5;
  int *piVar6;
  
  if (7 < param_2) {
    return 0x8000000000000002;
  }
  if (*(longlong *)(param_1 + 0x10) == 0) {
    iVar1 = *(int *)(param_1 + 4);
    plVar4 = FUN_000074dc((short)iVar1,param_2);
    if (plVar4 == (longlong *)0x0) {
      if (iVar1 != 1) {
        FUN_00004548(0x80000000,(byte *)"Card Detection FAILED! Handle %x, Slot %x\n");
      }
      *(undefined8 *)(param_1 + 0x10) = 0;
      if (param_2 != 3) {
        *(undefined1 *)(*(longlong *)(param_1 + 0x20) + 5) = 0;
        return 0x800000000000000c;
      }
      return 0x800000000000000c;
    }
    if (param_2 == 0) {
      piVar6 = (int *)(*plVar4 + 0x24);
    }
    else if (param_2 - 1 < 2) {
      piVar6 = (int *)(*plVar4 + 0x80);
    }
    else if (param_2 == 3) {
      piVar6 = (int *)(*plVar4 + 0x60);
    }
    else {
      if ((param_2 & 0xfffffffc) != 4) {
        *(undefined8 *)(param_1 + 0x10) = 0;
        goto LAB_00002348;
      }
      piVar6 = (int *)(*plVar4 + (ulonglong)(param_2 - 4) * 4 + 0x84);
    }
    if (*piVar6 == 0) {
      *(undefined8 *)(param_1 + 0x10) = 0;
      if (param_2 == 3) {
        return 0x800000000000000c;
      }
LAB_00002348:
      *(undefined1 *)(*(longlong *)(param_1 + 0x20) + 5) = 0;
      return 0x800000000000000c;
    }
    uVar5 = FUN_000076b8(plVar4,&DAT_00016f68);
    if ((int)uVar5 != 0) {
      FUN_00004548(0x80000000,(byte *)"Get Card Info FAILED! Status %x. Slot %x\n\n\n");
      return 0x8000000000000007;
    }
    *(longlong **)(param_1 + 0x10) = plVar4;
    if (param_2 == 3) {
      iVar1 = 2;
      if (DAT_00016f7c != 1) {
        iVar1 = DAT_00016f7c;
      }
      *(int *)(param_1 + 0x70) = iVar1;
      uVar2 = DAT_00016fa8;
      *(undefined4 *)(param_1 + 0x98) = 0x4000;
      *(undefined4 *)(param_1 + 0x74) = uVar2;
    }
    else {
      *(undefined1 *)(*(longlong *)(param_1 + 0x20) + 5) = 1;
      *(ulonglong *)(*(longlong *)(param_1 + 0x20) + 0x18) = (ulonglong)(DAT_00016f6c - 1);
      *(undefined4 *)(*(longlong *)(param_1 + 0x20) + 0xc) = DAT_00016f74;
      *(undefined1 *)(*(longlong *)(param_1 + 0x20) + 7) = 0;
      *(undefined1 *)(*(longlong *)(param_1 + 0x20) + 5) = 1;
      if (((param_2 == 0) &&
          (DAT_00016fac == '\0' && *(char *)(*(longlong *)(param_1 + 0x20) + 4) == '\0')) &&
         (uVar3 = FUN_00007dc4(plVar4), uVar3 != 0)) {
        FUN_00004548(0x80000000,(byte *)"Failed to enable Hw Reset \n");
        return 0x8000000000000007;
      }
    }
  }
  return 0;
}



undefined4 FUN_00002588(int *param_1,longlong param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  int *piVar3;
  undefined4 uVar4;
  
  uVar4 = 8;
  uVar2 = (**(code **)(DAT_00017260 + 0x18))(8);
  if (((param_1 != (int *)0x0) && (param_2 != 0)) && (param_3 != (undefined4 *)0x0)) {
    piVar3 = param_1 + -0x1a;
    if (param_1[-0x1a] != 0x63636473) {
      FUN_0000464c();
      piVar3 = param_1;
    }
    if (*(longlong **)(piVar3 + 4) == (longlong *)0x0) {
      uVar4 = 8;
    }
    else {
      uVar1 = FUN_0000ae74(*(longlong **)(piVar3 + 4),param_2,1,0,param_3);
      if (uVar1 == 0) {
        uVar4 = 0;
      }
      else {
        FUN_00001c1c(uVar1);
        uVar4 = 1;
      }
    }
  }
  (**(code **)(DAT_00017260 + 0x20))(uVar2);
  return uVar4;
}



undefined8 FUN_00002940(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined8 uVar2;
  int *piVar3;
  undefined8 uVar4;
  
  uVar4 = 0x8000000000000002;
  uVar2 = (**(code **)(DAT_00017260 + 0x18))(8);
  if (param_1 != (int *)0x0) {
    piVar3 = param_1 + -0x28;
    if (param_1[-0x28] != 0x63636473) {
      FUN_0000464c();
      piVar3 = param_1;
    }
    if (*(longlong **)(piVar3 + 4) != (longlong *)0x0) {
      uVar1 = FUN_00007e7c(*(longlong **)(piVar3 + 4),param_2,param_3);
      if (uVar1 == 0) {
        uVar4 = 0;
      }
      else if (uVar1 == 0x14) {
        FUN_00004548(0x80000000,(byte *)"Write Protect:: Invalid Parameter. %x\n\n\n");
      }
      else {
        FUN_00004548(0x80000000,(byte *)"Failed to write protect. Sector = %x. Error = %x\n\n\n");
        uVar4 = 0x8000000000000007;
      }
    }
  }
  (**(code **)(DAT_00017260 + 0x20))(uVar2);
  return uVar4;
}



undefined8 FUN_00002a40(int *param_1,int param_2,uint *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  int *piVar3;
  undefined8 uVar4;
  longlong *plVar5;
  undefined8 uStack_68;
  longlong local_48;
  
  local_48 = _data;
  uVar4 = 0x8000000000000002;
  uVar2 = (**(code **)(DAT_00017260 + 0x18))(8);
  if ((param_1 != (int *)0x0) && (param_3 != (uint *)0x0)) {
    piVar3 = param_1 + -0x28;
    if (param_1[-0x28] != 0x63636473) {
      FUN_0000464c();
      piVar3 = param_1;
    }
    plVar5 = *(longlong **)(piVar3 + 4);
    if (plVar5 != (longlong *)0x0) {
      FUN_00004788(&uStack_68,8,0);
      uVar1 = FUN_00007f50(plVar5,param_2,&uStack_68);
      if (uVar1 == 0) {
        uVar4 = 0;
        *param_3 = uStack_68._7_1_ & 3;
      }
      else {
        FUN_00004548(0x80000000,(byte *)"Failed to write protect Sector = %x. Error = %x\n\n\n");
        uVar4 = 0x8000000000000007;
      }
    }
  }
  (**(code **)(DAT_00017260 + 0x20))(uVar2);
  if (_data == local_48) {
    return uVar4;
  }
                    // WARNING: Subroutine does not return
  FUN_000010d8();
}



undefined8
FUN_00002b70(int *param_1,int param_2,ulonglong param_3,undefined8 *param_4,ulonglong param_5)

{
  uint uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  int *piVar4;
  undefined8 uVar5;
  
  uVar5 = 0x8000000000000002;
  uVar2 = (**(code **)(DAT_00017260 + 0x18))(8);
  if ((param_1 != (int *)0x0) && (param_5 != 0)) {
    piVar4 = *(int **)(param_1 + 2);
    if (*(ulonglong *)(piVar4 + 6) < param_3) {
      return 0x8000000000000002;
    }
    if (piVar4[3] == 0) {
      return 0x8000000000000002;
    }
    if (*piVar4 != param_2) {
      return 0x800000000000000d;
    }
    piVar4 = param_1 + -6;
    if (param_1[-6] != 0x63636473) {
      FUN_0000464c();
      piVar4 = param_1;
    }
    if (*(longlong **)(piVar4 + 4) != (longlong *)0x0) {
      uVar1 = 0;
      if ((ulonglong)*(uint *)(*(longlong *)(param_1 + 2) + 0xc) != 0) {
        uVar1 = (uint)(param_5 / *(uint *)(*(longlong *)(param_1 + 2) + 0xc));
      }
      uVar3 = FUN_00007bbc(*(longlong **)(piVar4 + 4),(uint)param_3,uVar1);
      if ((int)uVar3 == 0) {
        uVar5 = 0;
      }
      else if ((int)uVar3 == 0x14) {
        FUN_00004548(0x80000000,
                     (byte *)
                     "Emmc Erase: Invalid Parameter. SectorStart = 0x%xCount = 0x%x, handle = 0x%x\n"
                    );
      }
      else {
        FUN_00004548(0x80000000,
                     (byte *)"Failed to Erase. SectorStart = 0x%x. Count = 0x%x. Error = 0x%x\n\n");
        uVar5 = 0x8000000000000007;
      }
    }
  }
  if (param_4 != (undefined8 *)0x0) {
    *param_4 = 0;
    param_4[1] = uVar5;
  }
  (**(code **)(DAT_00017260 + 0x20))(uVar2);
  return uVar5;
}



ulonglong FUN_00002d44(ulonglong param_1)

{
  uint uVar1;
  undefined8 local_28;
  
  local_28 = 0;
  if ((DAT_00016d30 == 0) && (param_1 = FUN_0000213c(0x16d20,0), param_1 == 0)) {
    param_1 = (**(code **)(DAT_00017260 + 0x148))
                        (&local_28,&DAT_000161c8,&DAT_00016d38,&DAT_000161e8,&DAT_000162d8,
                         &DAT_000161f8,&DAT_00016d68,0);
    if ((longlong)param_1 < 0) {
      FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
      uVar1 = FUN_0000464c();
      param_1 = (ulonglong)uVar1;
    }
    DAT_00016d28 = local_28;
    if (DAT_00016f30 == '\x01') {
      param_1 = (**(code **)(DAT_00017260 + 0x70))(DAT_00016f38);
      DAT_00016f30 = '\0';
    }
  }
  return param_1;
}



void FUN_00002e30(undefined8 param_1,longlong param_2)

{
  longlong lVar1;
  
  if ((param_2 != 0) && (*(int **)(param_2 + 8) != (int *)0x0)) {
    lVar1 = FUN_0000d1a4(**(int **)(param_2 + 8));
    if (lVar1 != 0) {
      FUN_00004548(0x80000000,(byte *)"Failed to initialize RPMB Listener, Status 0x%08x\n");
    }
    lVar1 = FUN_0000c5a0(param_2);
    if (lVar1 != 0) {
      FUN_00004548(0x80000000,(byte *)"Failed to initialize GPT Listener, Status 0x%08x\n");
    }
    lVar1 = FUN_00007488();
    if (lVar1 != 0) {
      FUN_00004548(0x80000000,(byte *)"Failed to initialize Partition config, Status 0x%08x\n");
      return;
    }
  }
  return;
}



longlong FUN_00003014(void)

{
  bool bVar1;
  longlong lVar2;
  longlong lVar3;
  undefined *puVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  undefined8 *puVar8;
  undefined *puVar9;
  undefined4 *puVar10;
  undefined *puVar11;
  undefined8 *puVar12;
  undefined4 *puVar13;
  undefined *puVar14;
  undefined4 *puVar15;
  undefined8 local_70;
  undefined8 uStack_68;
  
  local_70 = 0;
  uStack_68 = 0;
  FUN_00004728((undefined8 *)&DAT_00016f68,IMAGE_DOS_HEADER_00000000.e_program + 0xc);
  lVar2 = (**(code **)(DAT_00017260 + 0x140))(&DAT_000160d8,0,&uStack_68);
  if (lVar2 != 0) {
    bVar1 = FUN_000042e8();
    if (bVar1) {
      puVar12 = (undefined8 *)&DAT_00017078;
      puVar13 = (undefined4 *)&DAT_00016fb4;
      puVar14 = &DAT_00011ddc;
      puVar15 = &DAT_000163a8;
      for (lVar2 = 0; lVar2 != 8; lVar2 = lVar2 + 1) {
        *(undefined8 *)(puVar15 + 4) = 0;
        puVar8 = (undefined8 *)(puVar15 + 0x12);
        *(undefined8 *)(puVar15 + 0x16) = 0;
        *(undefined8 *)(puVar15 + 0x18) = 0;
        *(undefined8 *)(puVar15 + 0x12) = 0x10003;
        *(undefined1 **)(puVar15 + 0x14) = &LAB_00002354;
        *puVar15 = 0x63636473;
        puVar15[1] = 0;
        if (lVar2 == 3) {
          FUN_0000dabc(0x16788,0x11d90,0x38);
        }
        else {
          FUN_0000dabc((longlong)(puVar15 + 6),0x16350,0x30);
          FUN_0000dabc((longlong)(puVar15 + 0x40),0x16380,0x28);
          *(undefined8 **)(puVar15 + 8) = puVar12;
          *(undefined8 **)(puVar15 + 0x40) = puVar12;
          FUN_000047cc(puVar12,(undefined8 *)&DAT_00016cf0,0x30);
          *(code **)(puVar15 + 0x2c) = FUN_00002940;
          *(code **)(puVar15 + 0x2e) = FUN_00002a40;
          *(undefined8 *)(puVar15 + 0x28) = 0x10000;
          *(undefined1 **)(puVar15 + 0x2a) = &LAB_00002848;
          if (lVar2 == 0) {
            DAT_00016470 = 0x200;
            DAT_00016478 = FUN_00002b70;
            DAT_00016468 = 0x2003c;
            DAT_00016498 = 0x10000;
            DAT_000164a0 = &LAB_00002cdc;
          }
        }
        FUN_0000dabc((longlong)puVar13,0x11dc8,0x14);
        FUN_0000dabc((longlong)(puVar13 + 1),(longlong)puVar14,0x10);
        *(undefined1 *)(puVar13 + 5) = 0x7f;
        *(undefined1 *)((longlong)puVar13 + 0x17) = 0;
        *(undefined1 *)((longlong)puVar13 + 0x16) = 4;
        *(undefined1 *)((longlong)puVar13 + 0x15) = 0xff;
        lVar3 = FUN_0000213c((longlong)puVar15,(uint)lVar2);
        puVar14 = puVar14 + 0x10;
        if (lVar3 == 0) {
          puVar10 = puVar13;
          if (lVar2 == 0) {
            puVar6 = (undefined4 *)&DAT_000163c0;
            puVar8 = &DAT_000164a8;
            puVar4 = &DAT_000161c8;
            puVar7 = &DAT_000161d8;
            puVar9 = &DAT_000161e8;
            puVar11 = &DAT_000161f8;
          }
          else if (lVar2 == 3) {
            puVar4 = &DAT_000161e8;
            puVar7 = &DAT_000161f8;
            puVar9 = &DAT_00016208;
            puVar11 = (undefined *)0x0;
            puVar6 = puVar13;
            puVar10 = (undefined4 *)&DAT_00016788;
          }
          else {
            puVar6 = puVar15 + 6;
            puVar8 = (undefined8 *)(puVar15 + 0x40);
            puVar4 = &DAT_000161c8;
            puVar7 = &DAT_000161d8;
            puVar9 = &DAT_000161e8;
            puVar11 = &DAT_000161f8;
          }
          lVar3 = (**(code **)(DAT_00017260 + 0x148))
                            (puVar15 + 2,puVar4,puVar6,puVar7,puVar8,puVar9,puVar10,puVar11);
          if (lVar3 < 0) {
            FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
            FUN_0000464c();
          }
        }
        puVar12 = puVar12 + 6;
        puVar13 = puVar13 + 6;
        puVar15 = puVar15 + 0x4a;
      }
      lVar2 = FUN_0000d0ec();
      if (lVar2 != 0) {
        pcVar5 = "Failed to allocate memory for RPMB listener\n";
LAB_00003370:
        FUN_00004548(0x80000000,(byte *)pcVar5);
        return lVar2;
      }
      lVar2 = FUN_0000c4e4();
      if (lVar2 != 0) {
        pcVar5 = "Failed to allocate memory for GPT listener\n";
        goto LAB_00003370;
      }
      lVar2 = (**(code **)(DAT_00017260 + 0x140))(&DAT_00016238,0,&local_70);
      if (lVar2 == 0) {
        FUN_00002e30(0,0x163c0);
      }
      else {
        lVar2 = (**(code **)(DAT_00017260 + 0x50))(0x200,8,FUN_00002e30,&DAT_000163c0,&DAT_00016f48)
        ;
        if (lVar2 < 0) {
          FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
          FUN_0000464c();
        }
        lVar2 = (**(code **)(DAT_00017260 + 0xa8))(&DAT_00016238,DAT_00016f48,&DAT_00016f50);
        if (lVar2 < 0) {
          FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
          FUN_0000464c();
        }
      }
      DAT_00016f20 = 0;
      DAT_0001723c = 1;
      lVar2 = FUN_00003d4c((undefined8 *)&DAT_000171f8,0x80);
      if ((lVar2 != 0) ||
         (lVar2 = (**(code **)(DAT_00017260 + 0x50))(0x80000200,8,FUN_000038c0,0,&DAT_00016f28),
         lVar2 < 0)) {
        DAT_0001723c = 0;
      }
    }
    DAT_00016d30 = DAT_00016f40;
    DAT_00016d20 = 0x63636473;
    DAT_00016d24 = 1;
    FUN_0000dabc(0x16d38,0x16320,0x30);
    DAT_00016d78 = 0;
    DAT_00016d80 = 0;
    DAT_00016d70 = &LAB_00002354;
    DAT_00016d68 = 0x10003;
    DAT_00016e10 = 0x10000;
    DAT_00016e18 = &LAB_00002cdc;
    lVar2 = (**(code **)(DAT_00017260 + 0x170))(0x200,8,FUN_00002d44,0,&DAT_000160a8,&DAT_00016f38);
    if (lVar2 < 0) {
      FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
      FUN_0000464c();
    }
    DAT_00016f30 = 1;
    lVar2 = (**(code **)(DAT_00017260 + 0x170))(0x200,8,&LAB_00002ec8,0,&DAT_000160b8,&DAT_00016f58)
    ;
    if (lVar2 < 0) {
      FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
      FUN_0000464c();
    }
    lVar2 = (**(code **)(DAT_00017260 + 0x170))(0x200,8,&LAB_00002ecc,0,&DAT_000160c8,&DAT_00016f60)
    ;
    if (-1 < lVar2) {
      return 0;
    }
    FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
    FUN_0000464c();
  }
  return 0;
}



longlong FUN_00003690(int *param_1,int param_2,ulonglong param_3,ulonglong param_4,
                     undefined4 *param_5)

{
  undefined8 uVar1;
  longlong lVar2;
  uint unaff_w25;
  uint uVar3;
  int local_64;
  
  local_64 = 0;
  for (uVar3 = 0; uVar3 < 5000000; uVar3 = uVar3 + 100) {
    unaff_w25 = FUN_0000a6e0((ulonglong)DAT_00016f20,&local_64);
    if ((unaff_w25 | 2) == 3) break;
    FUN_00003f30(100);
  }
  if (local_64 == 0) {
    if (unaff_w25 != 0) {
      FUN_0000a888();
    }
    if (DAT_00017238 == 0) {
      lVar2 = FUN_000015c0(param_1,param_2,param_3,param_4,param_5);
    }
    else {
      lVar2 = FUN_000017c4(param_1,param_2,param_3,param_4,param_5);
    }
    if (lVar2 == 0) {
      if (*(longlong *)(DAT_00017220 + 0x20) == 0) {
        *(undefined8 *)(*(longlong *)(DAT_00017220 + 0x18) + 8) = 0;
        DAT_00017240 = *(undefined8 *)(DAT_00017220 + 0x18);
        DAT_0001723f = 1;
        FUN_00003850((undefined8 *)&DAT_000171f8);
      }
      lVar2 = 0;
      *(undefined1 *)(DAT_00017220 + 0x34) = 0;
    }
    else {
      uVar1 = 0;
      if (*(longlong *)(DAT_00017220 + 0x20) != 0) {
        uVar1 = 0x8000000000000007;
      }
      *(undefined8 *)(*(longlong *)(DAT_00017220 + 0x18) + 8) = uVar1;
      DAT_00017240 = *(undefined8 *)(DAT_00017220 + 0x18);
      DAT_0001723f = 1;
      FUN_00003850((undefined8 *)&DAT_000171f8);
    }
  }
  else {
    lVar2 = -0x7ffffffffffffff9;
    *(undefined8 *)(*(longlong *)(DAT_00017220 + 0x18) + 8) = 0x8000000000000007;
    DAT_00017240 = *(undefined8 *)(DAT_00017220 + 0x18);
    DAT_0001723f = 1;
    FUN_00003850((undefined8 *)&DAT_000171f8);
  }
  return lVar2;
}



void FUN_00003850(undefined8 *param_1)

{
  longlong lVar1;
  bool bVar2;
  
  FUN_00005710(param_1);
  FUN_00004788((longlong *)param_1[5],0x38,0);
  bVar2 = FUN_00003ab8((longlong)param_1);
  if (bVar2) {
    if (*(char *)(param_1 + 7) == '\x01') {
      *(undefined1 *)(param_1 + 7) = 0;
    }
    lVar1 = param_1[5];
    param_1[5] = lVar1 + 0x38;
    if (lVar1 + 0x38 == param_1[4]) {
      param_1[5] = param_1[3];
    }
  }
  FUN_00005794((longlong)param_1);
  return;
}



void FUN_000038c0(void)

{
  longlong lVar1;
  bool bVar2;
  uint uVar3;
  undefined8 *puVar4;
  uint local_24;
  
  local_24 = 0;
  FUN_00005710((undefined8 *)&DAT_00016e48);
  bVar2 = FUN_00003ab8(0x171f8);
  if ((bVar2) && (*(char *)(DAT_00017220 + 0x34) != '\0')) {
    uVar3 = FUN_0000a6e0((ulonglong)DAT_00016f20,&local_24);
  }
  else {
    uVar3 = FUN_0000a650(DAT_00016f20,&local_24);
    if (uVar3 == 1) {
      FUN_00004548(0x80000000,
                   (byte *)"Blkio2: TRANSFER_DONE when queue is empty or transfer not started!\n");
      FUN_0000464c();
      do {
                    // WARNING: Do nothing block with infinite loop
      } while( true );
    }
  }
  switch(uVar3) {
  case 0:
    bVar2 = FUN_00003ab8(0x171f8);
    if (!bVar2) {
      FUN_00003dc0();
      break;
    }
    if (*(char *)(DAT_00017220 + 0x34) != '\0') {
      FUN_00004548(0x80000000,(byte *)"Blkio2: Warning transfer started but DEVICE_IDLE\n ");
      FUN_0000464c();
      do {
                    // WARNING: Do nothing block with infinite loop
      } while( true );
    }
    goto LAB_000039ec;
  case 1:
    FUN_0000a888();
    if (*(longlong *)(DAT_00017220 + 0x20) == 0) {
      puVar4 = *(undefined8 **)(DAT_00017220 + 0x18);
      FUN_00003850((undefined8 *)&DAT_000171f8);
      bVar2 = FUN_00003ab8(0x171f8);
      if (bVar2) {
        FUN_00003bc0((undefined8 *)&DAT_000171f8);
      }
      else {
        FUN_00003dc0();
      }
      lVar1 = DAT_00017260;
      puVar4[1] = 0;
      (**(code **)(lVar1 + 0x68))(*puVar4);
      break;
    }
LAB_000039ec:
    FUN_00003bc0((undefined8 *)&DAT_000171f8);
    break;
  case 2:
    if (DAT_0001723f == '\x01') {
      DAT_0001723f = '\0';
      (**(code **)(DAT_00017260 + 0x68))(*DAT_00017240);
    }
    break;
  case 3:
    FUN_00003adc((undefined8 *)&DAT_000171f8,local_24);
    break;
  default:
    FUN_00004548(0x80000000,(byte *)"UNKNOWN_STATE!\n");
  }
  FUN_00005794(0x16e48);
  return;
}



bool FUN_00003ab8(longlong param_1)

{
  if (*(char *)(param_1 + 0x38) == '\x01') {
    return true;
  }
  return *(longlong *)(param_1 + 0x30) != *(longlong *)(param_1 + 0x28);
}



void FUN_00003adc(undefined8 *param_1,uint param_2)

{
  bool bVar1;
  undefined8 uVar2;
  
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x800000000000000c;
    FUN_00001c1c(param_2);
    if (((0x1b < param_2) || ((1 << (ulonglong)(param_2 & 0x1f) & 0x8200004U) == 0)) &&
       (uVar2 = 0x8000000000000002, param_2 != 0x14)) {
      uVar2 = 0x8000000000000007;
    }
  }
  if (DAT_0001723f == '\x01') {
    DAT_0001723f = '\0';
    (**(code **)(DAT_00017260 + 0x68))(*DAT_00017240);
  }
  bVar1 = FUN_00003ab8((longlong)param_1);
  if (bVar1) {
    *(undefined8 *)(*(longlong *)(param_1[5] + 0x18) + 8) = uVar2;
    (**(code **)(DAT_00017260 + 0x68))(**(undefined8 **)(param_1[5] + 0x18));
    FUN_00003850(param_1);
  }
  FUN_00003dc0();
  return;
}



void FUN_00003bc0(undefined8 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  int *piVar6;
  longlong *plVar7;
  ulonglong uVar8;
  longlong lVar9;
  ulonglong uVar10;
  
  plVar7 = (longlong *)param_1[5];
  uVar10 = plVar7[4];
  if (uVar10 == 0) {
    uVar5 = 0x14;
  }
  else {
    lVar9 = plVar7[2];
    uVar8 = plVar7[5];
    lVar4 = plVar7[6];
    piVar6 = (int *)(*plVar7 + -0x100);
    if (*piVar6 != 0x63636473) {
      FUN_0000464c();
      piVar6 = *(int **)param_1[5];
    }
    uVar2 = *(uint *)(*(longlong *)(piVar6 + 8) + 0xc);
    uVar3 = 0;
    if ((ulonglong)uVar2 != 0) {
      uVar3 = (uint)(uVar10 / uVar2);
    }
    uVar1 = uVar3;
    if (0x3fff < uVar3) {
      uVar1 = 0x4000;
    }
    uVar5 = FUN_0000a950(*(longlong **)(piVar6 + 4),(int)lVar9,uVar8,uVar1,(int)lVar4);
    *(ulonglong *)(param_1[5] + 0x20) = (ulonglong)((uVar3 - uVar1) * uVar2);
    *(ulonglong *)(param_1[5] + 0x10) = lVar9 + (ulonglong)uVar1;
    *(ulonglong *)(param_1[5] + 0x28) = uVar8 + uVar1 * uVar2;
    *(undefined1 *)(param_1[5] + 0x34) = 1;
    if (uVar5 == 0) {
      if (DAT_0001723e == '\0') {
        DAT_0001723e = '\x01';
        (**(code **)(DAT_00017260 + 0x58))(DAT_00016f28,1,&DAT_000186a0);
      }
      if (DAT_0001723f == '\x01') {
        DAT_0001723f = 0;
                    // WARNING: Could not recover jumptable at 0x00003d10. Too many branches
                    // WARNING: Treating indirect jump as call
        (**(code **)(DAT_00017260 + 0x68))(*DAT_00017240);
        return;
      }
      return;
    }
  }
  FUN_00003adc(param_1,uVar5);
  return;
}



undefined8 FUN_00003d4c(undefined8 *param_1,longlong param_2)

{
  longlong lVar1;
  undefined8 uVar2;
  
  *param_1 = 8;
  param_1[1] = 4;
  param_1[2] = 1;
  lVar1 = FUN_00004090((undefined1 *)(param_2 * 0x38));
  param_1[3] = lVar1;
  if (lVar1 == 0) {
    uVar2 = 0x8000000000000009;
  }
  else {
    param_1[5] = lVar1;
    param_1[6] = lVar1;
    uVar2 = 0;
    *(undefined1 *)(param_1 + 7) = 0;
    param_1[4] = lVar1 + param_2 * 0x38;
  }
  return uVar2;
}



void FUN_00003dc0(void)

{
  if (DAT_0001723e == '\x01') {
    DAT_0001723e = '\0';
    (**(code **)(DAT_00017260 + 0x58))(DAT_00016f28,0,&DAT_000186a0);
  }
  if (DAT_0001723f == '\x01') {
    DAT_0001723f = 0;
                    // WARNING: Could not recover jumptable at 0x00003e34. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(DAT_00017260 + 0x68))(*DAT_00017240);
    return;
  }
  return;
}



void FUN_00003e44(void)

{
  return;
}



undefined8 FUN_00003e48(undefined4 *param_1)

{
  *param_1 = 0x7c4000;
  param_1[1] = 0x8804000;
  return 0;
}



undefined4 FUN_00003e68(uint param_1)

{
  if (3 < param_1) {
    return 0;
  }
  return *(undefined4 *)(&DAT_00011f40 + (ulonglong)param_1 * 4);
}



undefined4 FUN_00003e88(uint param_1)

{
  if (3 < param_1) {
    return 0;
  }
  return *(undefined4 *)(&DAT_00011f50 + (ulonglong)param_1 * 4);
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined8 FUN_00003ea8(undefined8 param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (uVar1 < 4 && (uVar1 | 1) != 3) {
    if (uVar1 == 1) {
      _DAT_03d98000 = 0x1fe4;
      return 0;
    }
    if (uVar1 == 0) {
      _DAT_0359a000 = 0x9fe4;
      return param_1;
    }
  }
  return 2;
}



undefined4 FUN_00003ef4(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 200000000;
  if (param_1 != 1) {
    uVar2 = 0;
  }
  uVar1 = 384000000;
  if (param_1 != 0) {
    uVar1 = uVar2;
  }
  return uVar1;
}



undefined8 FUN_00003f18(void)

{
  return 192000000;
}



undefined8 FUN_00003f24(void)

{
  return 384000000;
}



void FUN_00003f30(undefined4 param_1)

{
                    // WARNING: Could not recover jumptable at 0x00003f40. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(DAT_00017260 + 0xf8))(param_1);
  return;
}



void FUN_00003f44(int param_1,ulonglong param_2,uint param_3)

{
  if (param_1 == 0) {
    FUN_00004248(param_2,(ulonglong)param_3);
    return;
  }
  if (param_1 == 1) {
    FUN_000041c8(param_2,(ulonglong)param_3);
    return;
  }
  return;
}



void thunk_FUN_000042c8(void)

{
  DataMemoryBarrier(3,3);
  return;
}



undefined8 FUN_00003f78(void)

{
  return 4;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

undefined4 FUN_00003f80(undefined4 param_1)

{
  longlong lVar1;
  int local_30 [4];
  longlong local_18;
  
  local_18 = 0;
  lVar1 = (**(code **)(DAT_00017260 + 0x140))(&DAT_00016278,0,&local_18);
  if ((lVar1 == 0) && (lVar1 = (**(code **)(local_18 + 8))(local_18,local_30), lVar1 == 0)) {
    if (local_30[0] != 0xf) {
      return param_1;
    }
  }
  else if (_DAT_01fc8004 != 1) {
    return param_1;
  }
  return 3;
}



undefined8 FUN_0000400c(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined8 local_18;
  
  lVar1 = (**(code **)(DAT_00017260 + 0x40))(param_1,param_2,&local_18);
  if (lVar1 < 0) {
    local_18 = 0;
  }
  return local_18;
}



void FUN_0000404c(undefined8 param_1)

{
  FUN_0000400c(4,param_1);
  return;
}



void FUN_0000405c(undefined8 param_1,undefined1 *param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)FUN_0000400c(param_1,param_2);
  if (puVar1 != (undefined8 *)0x0) {
    FUN_00004728(puVar1,param_2);
    return;
  }
  return;
}



void FUN_00004090(undefined1 *param_1)

{
  FUN_0000405c(4,param_1);
  return;
}



undefined8 *
FUN_000040a0(undefined8 param_1,undefined1 *param_2,undefined1 *param_3,undefined8 *param_4)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)FUN_0000405c(param_1,param_3);
  if ((param_4 != (undefined8 *)0x0) && (puVar1 != (undefined8 *)0x0)) {
    if (param_3 <= param_2) {
      param_2 = param_3;
    }
    FUN_000047cc(puVar1,param_4,(ulonglong)param_2);
    FUN_00004100();
  }
  return puVar1;
}



ulonglong FUN_00004100(void)

{
  uint uVar1;
  ulonglong uVar2;
  
  uVar2 = (**(code **)(DAT_00017260 + 0x48))();
  if (-1 < (longlong)uVar2) {
    return uVar2;
  }
  FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
  uVar1 = FUN_0000464c();
  return (ulonglong)uVar1;
}



void FUN_00004158(undefined1 *param_1,undefined1 *param_2,undefined8 *param_3)

{
  FUN_000040a0(4,param_1,param_2,param_3);
  return;
}



void FUN_00004178(ulonglong param_1,longlong param_2,undefined *param_3,longlong param_4)

{
  ulonglong uVar1;
  
  for (uVar1 = -param_4 & param_1; uVar1 < param_1 + param_2; uVar1 = uVar1 + param_4) {
    (*(code *)param_3)(uVar1);
  }
  FUN_000042d0();
  FUN_000042d8();
  return;
}



ulonglong FUN_000041c8(ulonglong param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = FUN_00004288();
  FUN_00004178(param_1,param_2,&LAB_000042c0,(ulonglong)uVar1);
  return param_1;
}



ulonglong FUN_00004208(ulonglong param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = FUN_00004288();
  FUN_00004178(param_1,param_2,FUN_000042b8,(ulonglong)uVar1);
  return param_1;
}



ulonglong FUN_00004248(ulonglong param_1,longlong param_2)

{
  uint uVar1;
  
  uVar1 = FUN_00004288();
  FUN_00004178(param_1,param_2,FUN_000042b0,(ulonglong)uVar1);
  return param_1;
}



int FUN_00004288(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_000042a8();
  return 4 << (ulonglong)((uint)uVar1 >> 0x10 & 0xf);
}



undefined8 FUN_000042a8(void)

{
  undefined8 uVar1;
  
  uVar1 = ctr_el0;
  return uVar1;
}



void FUN_000042b0(undefined8 param_1)

{
  DC_IVAC(param_1);
  return;
}



void FUN_000042b8(undefined8 param_1)

{
  DC_CVAC(param_1);
  return;
}



void FUN_000042c8(void)

{
  DataMemoryBarrier(3,3);
  return;
}



void FUN_000042d0(void)

{
  DataSynchronizationBarrier(3,3,0);
  return;
}



void FUN_000042d8(void)

{
  InstructionSynchronizationBarrier();
  return;
}



undefined8 FUN_000042e0(void)

{
  return 1;
}



bool FUN_000042e8(void)

{
  bool bVar1;
  longlong lVar2;
  undefined8 local_20;
  uint local_14;
  
  local_14 = 0x7fffffff;
  local_20 = 0;
  lVar2 = (**(code **)(DAT_00017260 + 0x140))(&DAT_000160d8,0,&local_20);
  if (lVar2 == 0) {
    bVar1 = true;
  }
  else {
    lVar2 = FUN_000043c4(&local_14);
    if (lVar2 != 0) {
      FUN_00004548(0x80000000,(byte *)"ERROR: Failed to Get Shared Imem Boot Device type \n");
    }
    bVar1 = local_14 == 5;
  }
  return bVar1;
}



undefined8 FUN_00004360(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  int iVar4;
  
  uVar3 = 0x8000000000000002;
  if ((param_1 != (int *)0x0) && (param_2 != (int *)0x0)) {
    iVar4 = 0x7fffffff;
    *param_2 = 0x7fffffff;
    iVar1 = *param_1;
    iVar2 = 1;
    switch(iVar1) {
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
switchD_00004398_caseD_0:
      iVar2 = iVar1;
    case 1:
      iVar4 = iVar2;
      *param_2 = iVar4;
      break;
    default:
      if (iVar1 == 0x7fffffff) goto switchD_00004398_caseD_0;
    }
    uVar3 = 0x8000000000000003;
    if (iVar4 != 0x7fffffff) {
      uVar3 = 0;
    }
  }
  return uVar3;
}



longlong FUN_000043c4(uint *param_1)

{
  longlong lVar1;
  longlong lVar2;
  int *piVar3;
  int local_2c;
  uint local_28;
  uint local_24;
  
  local_28 = 0;
  local_24 = 0;
  local_2c = 0x7fffffff;
  if (param_1 == (uint *)0x0) {
    lVar2 = -0x7ffffffffffffffe;
  }
  else {
    lVar1 = FUN_000044e4("SharedIMEMBaseAddr",&local_24);
    lVar2 = -0x7ffffffffffffff2;
    if ((lVar1 == 0) && (piVar3 = (int *)(ulonglong)local_24, local_24 != 0)) {
      if (*piVar3 == -0x3e0724c0) {
        lVar2 = -0x7fffffffffffffe8;
        if (2 < (uint)piVar3[1]) {
          local_2c = piVar3[0x14];
          lVar2 = FUN_00004360(&local_2c,(int *)param_1);
          if (lVar2 == 0) {
            lVar2 = FUN_000044e4("OverRideSharedImemBootCfg",&local_28);
            if ((lVar2 == 0) && (local_28 < 0xc)) {
              lVar2 = 0;
              *param_1 = local_28;
            }
            else {
              lVar2 = 0;
            }
          }
        }
      }
      else {
        lVar2 = -0x7fffffffffffffe8;
      }
    }
  }
  return lVar2;
}



undefined8 FUN_000044a0(void)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_000105d0();
  if (lVar1 != 0) {
                    // WARNING: Could not recover jumptable at 0x000044d0. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar2 = (**(code **)(lVar1 + 0x10))("UEFI Config Lib",0,&DAT_00017248);
    return uVar2;
  }
  return 0x8000000000000006;
}



undefined8 FUN_000044e4(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (DAT_00017248 == 0) {
    FUN_000044a0();
    if (DAT_00017248 == 0) {
      return 0x8000000000000006;
    }
  }
                    // WARNING: Could not recover jumptable at 0x0000452c. Too many branches
                    // WARNING: Treating indirect jump as call
  uVar1 = (**(code **)(DAT_00017248 + 0x18))(param_1,param_2);
  return uVar1;
}



void FUN_00004548(uint param_1,byte *param_2)

{
  ulonglong uVar1;
  char acStack_228 [512];
  longlong local_28;
  
  local_28 = _data;
  if (param_2 == (byte *)0x0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  if ((param_1 & 0x80000400) != 0) {
    FUN_0000e0e4(acStack_228,0x200,param_2,(longlong *)&stack0xfffffffffffffd98);
    if ((param_1 & 0x80000402) != 0) {
      uVar1 = FUN_00004f08(acStack_228);
      FUN_0000f4e0(acStack_228,uVar1);
    }
  }
  if (_data == local_28) {
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_000010d8();
}



undefined4 FUN_0000464c(void)

{
  char cVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  char acStack_238 [512];
  longlong local_38;
  
  local_38 = _data;
  FUN_00005e04();
  cVar1 = FUN_00005e14();
  if (cVar1 == '\0') {
    FUN_00005e24();
  }
  else {
    FUN_00005e34(2,0x3000007);
  }
  FUN_0000f5a0();
  FUN_0000f5e4();
  FUN_0000e124(acStack_238,0x200,(byte *)"ASSERT %a +%d: %a\n");
  uVar3 = FUN_00004f08(acStack_238);
  FUN_0000f4e0(acStack_238,uVar3);
  FUN_0000f5a0();
  FUN_0000f4e0(&DAT_00012112,1);
  FUN_0000f5a0();
  FUN_0000e0b0();
  uVar2 = FUN_00004c58();
  if (_data == local_38) {
    return uVar2;
  }
                    // WARNING: Subroutine does not return
  FUN_000010d8();
}



void FUN_00004728(undefined8 *param_1,undefined1 *param_2)

{
  if (param_2 == (undefined1 *)0x0) {
    return;
  }
  if (param_1 != (undefined8 *)0x0) {
    if ((undefined1 *)-(longlong)param_1 < param_2) {
      FUN_0000464c();
      do {
                    // WARNING: Do nothing block with infinite loop
      } while( true );
    }
    FUN_00004864(param_1,param_2);
    return;
  }
  FUN_0000464c();
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void FUN_00004788(longlong *param_1,ulonglong param_2,undefined1 param_3)

{
  if (param_2 == 0) {
    return;
  }
  if (~(ulonglong)param_1 < param_2 - 1) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  FUN_0000486c(param_1,param_2,param_3);
  return;
}



void FUN_000047cc(undefined8 *param_1,undefined8 *param_2,ulonglong param_3)

{
  if (param_3 != 0) {
    if (~(ulonglong)param_1 < param_3 - 1) {
      FUN_0000464c();
      do {
                    // WARNING: Do nothing block with infinite loop
      } while( true );
    }
    if (~(ulonglong)param_2 < param_3 - 1) {
      FUN_0000464c();
      do {
                    // WARNING: Do nothing block with infinite loop
      } while( true );
    }
    if (param_1 != param_2) {
      FUN_00004bac(param_1,param_2,param_3);
      return;
    }
  }
  return;
}



void FUN_00004864(undefined8 *param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  bool bVar4;
  uint uVar5;
  undefined1 *puVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  ulonglong uVar11;
  
  puVar1 = (undefined1 *)((longlong)param_1 + (longlong)param_2);
  if (IMAGE_DOS_HEADER_00000000.e_program + 0x20 < param_2) {
    uVar8 = (ulonglong)param_1 & 0xfffffffffffffff0;
    param_1[1] = 0;
    *param_1 = 0;
    if (IMAGE_DOS_HEADER_00000000.e_program + 0xbf < param_2) {
      uVar2 = dczid_el0;
      if (((uint)uVar2 >> 4 & 1) == 0) {
        uVar5 = (uint)uVar2 & 0xf;
        if (uVar5 == 4) {
          *(undefined8 *)(uVar8 + 0x18) = 0;
          *(undefined8 *)(uVar8 + 0x10) = 0;
          *(undefined8 *)(uVar8 + 0x28) = 0;
          *(undefined8 *)(uVar8 + 0x20) = 0;
          *(undefined8 *)(uVar8 + 0x38) = 0;
          *(undefined8 *)(uVar8 + 0x30) = 0;
          uVar8 = (ulonglong)param_1 & 0xffffffffffffffc0;
          *(undefined8 *)(uVar8 + 0x48) = 0;
          *(undefined8 *)(uVar8 + 0x40) = 0;
          *(undefined8 *)(uVar8 + 0x58) = 0;
          *(undefined8 *)(uVar8 + 0x50) = 0;
          *(undefined8 *)(uVar8 + 0x68) = 0;
          *(undefined8 *)(uVar8 + 0x60) = 0;
          *(undefined8 *)(uVar8 + 0x78) = 0;
          *(undefined8 *)(uVar8 + 0x70) = 0;
          puVar6 = puVar1 + (-0x100 - uVar8);
          puVar10 = (undefined8 *)(uVar8 + 0x80);
          do {
            puVar9 = puVar10;
            DC_ZVA(puVar9);
            bVar4 = (undefined1 *)0x3f < puVar6;
            puVar6 = puVar6 + -0x40;
            puVar10 = puVar9 + 8;
          } while (bVar4 && puVar6 != (undefined1 *)0x0);
          puVar9[9] = 0;
          puVar9[8] = 0;
          puVar9[0xb] = 0;
          puVar9[10] = 0;
          puVar9[0xd] = 0;
          puVar9[0xc] = 0;
          puVar9[0xf] = 0;
          puVar9[0xe] = 0;
          *(undefined8 *)(puVar1 + -0x38) = 0;
          *(undefined8 *)(puVar1 + -0x40) = 0;
          *(undefined8 *)(puVar1 + -0x28) = 0;
          *(undefined8 *)(puVar1 + -0x30) = 0;
          *(undefined8 *)(puVar1 + -0x18) = 0;
          *(undefined8 *)(puVar1 + -0x20) = 0;
          *(undefined8 *)(puVar1 + -8) = 0;
          *(undefined8 *)(puVar1 + -0x10) = 0;
          return;
        }
        if (uVar5 == 5) {
          *(undefined8 *)(uVar8 + 0x18) = 0;
          *(undefined8 *)(uVar8 + 0x10) = 0;
          *(undefined8 *)(uVar8 + 0x28) = 0;
          *(undefined8 *)(uVar8 + 0x20) = 0;
          *(undefined8 *)(uVar8 + 0x38) = 0;
          *(undefined8 *)(uVar8 + 0x30) = 0;
          *(undefined8 *)(uVar8 + 0x48) = 0;
          *(undefined8 *)(uVar8 + 0x40) = 0;
          *(undefined8 *)(uVar8 + 0x58) = 0;
          *(undefined8 *)(uVar8 + 0x50) = 0;
          *(undefined8 *)(uVar8 + 0x68) = 0;
          *(undefined8 *)(uVar8 + 0x60) = 0;
          *(undefined8 *)(uVar8 + 0x78) = 0;
          *(undefined8 *)(uVar8 + 0x70) = 0;
          uVar8 = (ulonglong)param_1 & 0xffffffffffffff80;
          puVar6 = puVar1 + (-0x100 - uVar8);
          do {
            uVar8 = uVar8 + 0x80;
            DC_ZVA(uVar8);
            bVar4 = (undefined1 *)0x7f < puVar6;
            puVar6 = puVar6 + -0x80;
          } while (bVar4 && puVar6 != (undefined1 *)0x0);
          *(undefined8 *)(puVar1 + -0x78) = 0;
          *(undefined8 *)(puVar1 + -0x80) = 0;
          *(undefined8 *)(puVar1 + -0x68) = 0;
          *(undefined8 *)(puVar1 + -0x70) = 0;
          *(undefined8 *)(puVar1 + -0x58) = 0;
          *(undefined8 *)(puVar1 + -0x60) = 0;
          *(undefined8 *)(puVar1 + -0x48) = 0;
          *(undefined8 *)(puVar1 + -0x50) = 0;
          *(undefined8 *)(puVar1 + -0x38) = 0;
          *(undefined8 *)(puVar1 + -0x40) = 0;
          *(undefined8 *)(puVar1 + -0x28) = 0;
          *(undefined8 *)(puVar1 + -0x30) = 0;
          *(undefined8 *)(puVar1 + -0x18) = 0;
          *(undefined8 *)(puVar1 + -0x20) = 0;
          *(undefined8 *)(puVar1 + -8) = 0;
          *(undefined8 *)(puVar1 + -0x10) = 0;
          return;
        }
        uVar11 = (ulonglong)(uint)(4 << (ulonglong)uVar5);
        if ((undefined1 *)(uVar11 + 0x40) <= param_2) {
          uVar7 = (uVar8 + uVar11) - (longlong)(uVar8 + 0x10);
          puVar10 = (undefined8 *)(uVar8 + uVar11 & (uVar11 - 1 ^ 0xffffffffffffffff));
          puVar9 = (undefined8 *)(uVar8 + 0x10);
          if (uVar7 != 0) {
            do {
              puVar9[1] = 0;
              *puVar9 = 0;
              puVar9[3] = 0;
              puVar9[2] = 0;
              puVar9[5] = 0;
              puVar9[4] = 0;
              puVar9[7] = 0;
              puVar9[6] = 0;
              bVar4 = 0x3f < uVar7;
              uVar7 = uVar7 - 0x40;
              puVar9 = puVar9 + 8;
            } while (bVar4 && uVar7 != 0);
          }
          uVar8 = ((longlong)puVar1 - (longlong)puVar10) - uVar11;
          uVar7 = (longlong)puVar1 - (longlong)puVar10;
          while (uVar3 = uVar8, uVar11 <= uVar7) {
            DC_ZVA(puVar10);
            puVar10 = (undefined8 *)((longlong)puVar10 + uVar11);
            uVar8 = uVar3 - uVar11;
            uVar7 = uVar3;
          }
          puVar6 = (undefined1 *)(uVar3 + uVar11);
          goto LAB_0000491c;
        }
      }
    }
    puVar6 = puVar1 + (-0x50 - uVar8);
    puVar9 = (undefined8 *)(uVar8 + 0x10);
    do {
      puVar10 = puVar9 + 8;
      puVar9[1] = 0;
      *puVar9 = 0;
      puVar9[3] = 0;
      puVar9[2] = 0;
      puVar9[5] = 0;
      puVar9[4] = 0;
      puVar9[7] = 0;
      puVar9[6] = 0;
LAB_0000491c:
      bVar4 = (undefined1 *)0x3f < puVar6;
      puVar6 = puVar6 + -0x40;
      puVar9 = puVar10;
    } while (bVar4 && puVar6 != (undefined1 *)0x0);
    *(undefined8 *)(puVar1 + -0x38) = 0;
    *(undefined8 *)(puVar1 + -0x40) = 0;
    *(undefined8 *)(puVar1 + -0x28) = 0;
    *(undefined8 *)(puVar1 + -0x30) = 0;
    *(undefined8 *)(puVar1 + -0x18) = 0;
    *(undefined8 *)(puVar1 + -0x20) = 0;
    *(undefined8 *)(puVar1 + -8) = 0;
    *(undefined8 *)(puVar1 + -0x10) = 0;
    return;
  }
  uVar5 = (uint)param_2;
  if ((undefined1 *)((longlong)&IMAGE_DOS_HEADER_00000000.e_ss + 1) < param_2) {
    param_1[1] = 0;
    *param_1 = 0;
    if ((uVar5 >> 6 & 1) == 0) {
      *(undefined8 *)(puVar1 + -8) = 0;
      *(undefined8 *)(puVar1 + -0x10) = 0;
      if ((uVar5 >> 5 & 1) != 0) {
        param_1[3] = 0;
        param_1[2] = 0;
        *(undefined8 *)(puVar1 + -0x18) = 0;
        *(undefined8 *)(puVar1 + -0x20) = 0;
      }
      return;
    }
    param_1[3] = 0;
    param_1[2] = 0;
    param_1[5] = 0;
    param_1[4] = 0;
    param_1[7] = 0;
    param_1[6] = 0;
    *(undefined8 *)(puVar1 + -0x18) = 0;
    *(undefined8 *)(puVar1 + -0x20) = 0;
    *(undefined8 *)(puVar1 + -8) = 0;
    *(undefined8 *)(puVar1 + -0x10) = 0;
    return;
  }
  if ((uVar5 >> 3 & 1) != 0) {
    *param_1 = 0;
    *(undefined8 *)(puVar1 + -8) = 0;
    return;
  }
  if ((uVar5 >> 2 & 1) != 0) {
    *(undefined4 *)param_1 = 0;
    *(undefined4 *)(puVar1 + -4) = 0;
    return;
  }
  if ((param_2 != (undefined1 *)0x0) && (*(undefined1 *)param_1 = 0, (uVar5 >> 1 & 1) != 0)) {
    *(undefined2 *)(puVar1 + -2) = 0;
  }
  return;
}



void FUN_0000486c(longlong *param_1,ulonglong param_2,undefined1 param_3)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined4 uVar3;
  bool bVar4;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  ulonglong uVar9;
  undefined8 *puVar10;
  undefined8 *puVar11;
  
  uVar3 = CONCAT13(param_3,CONCAT12(param_3,CONCAT11(param_3,param_3)));
  lVar2 = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,uVar3))));
  if (0x60 < param_2) {
    uVar8 = (ulonglong)param_1 & 0xfffffffffffffff0;
    param_1[1] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(
                                                  param_3,CONCAT12(param_3,CONCAT11(param_3,param_3)
                                                                  ))))));
    *param_1 = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
    if (0xff < param_2 && lVar2 == 0) {
      uVar1 = dczid_el0;
      if (((uint)uVar1 >> 4 & 1) == 0) {
        uVar5 = (uint)uVar1 & 0xf;
        if (uVar5 == 4) {
          *(ulonglong *)(uVar8 + 0x18) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar8 + 0x10) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar8 + 0x28) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar8 + 0x20) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar8 + 0x38) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar8 + 0x30) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          uVar9 = (ulonglong)param_1 & 0xffffffffffffffc0;
          *(ulonglong *)(uVar9 + 0x48) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar9 + 0x40) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar9 + 0x58) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar9 + 0x50) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar9 + 0x68) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar9 + 0x60) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar9 + 0x78) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar9 + 0x70) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          uVar8 = (longlong)param_1 + (param_2 - uVar9) + -0x100;
          puVar11 = (undefined8 *)(uVar9 + 0x80);
          do {
            puVar10 = puVar11;
            DC_ZVA(puVar10);
            bVar4 = 0x3f < uVar8;
            uVar8 = uVar8 - 0x40;
            puVar11 = puVar10 + 8;
          } while (bVar4 && uVar8 != 0);
          puVar10[9] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(
                                                  param_3,CONCAT12(param_3,CONCAT11(param_3,param_3)
                                                                  ))))));
          puVar10[8] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(
                                                  param_3,CONCAT12(param_3,CONCAT11(param_3,param_3)
                                                                  ))))));
          puVar10[0xb] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,
                                                  CONCAT13(param_3,CONCAT12(param_3,CONCAT11(param_3
                                                  ,param_3)))))));
          puVar10[10] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13
                                                  (param_3,CONCAT12(param_3,CONCAT11(param_3,param_3
                                                                                    )))))));
          puVar10[0xd] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,
                                                  CONCAT13(param_3,CONCAT12(param_3,CONCAT11(param_3
                                                  ,param_3)))))));
          puVar10[0xc] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,
                                                  CONCAT13(param_3,CONCAT12(param_3,CONCAT11(param_3
                                                  ,param_3)))))));
          puVar10[0xf] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,
                                                  CONCAT13(param_3,CONCAT12(param_3,CONCAT11(param_3
                                                  ,param_3)))))));
          puVar10[0xe] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,
                                                  CONCAT13(param_3,CONCAT12(param_3,CONCAT11(param_3
                                                  ,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 0x38)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 0x40)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 0x28)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 0x30)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 0x18)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 0x20)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 8)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 0x10)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          return;
        }
        if (uVar5 == 5) {
          *(ulonglong *)(uVar8 + 0x18) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar8 + 0x10) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar8 + 0x28) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar8 + 0x20) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar8 + 0x38) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar8 + 0x30) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar8 + 0x48) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar8 + 0x40) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar8 + 0x58) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar8 + 0x50) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar8 + 0x68) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar8 + 0x60) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar8 + 0x78) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)(uVar8 + 0x70) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          uVar9 = (ulonglong)param_1 & 0xffffffffffffff80;
          uVar8 = (longlong)param_1 + (param_2 - uVar9) + -0x100;
          do {
            uVar9 = uVar9 + 0x80;
            DC_ZVA(uVar9);
            bVar4 = 0x7f < uVar8;
            uVar8 = uVar8 - 0x80;
          } while (bVar4 && uVar8 != 0);
          *(ulonglong *)((longlong)param_1 + (param_2 - 0x78)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 0x80)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 0x68)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 0x70)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 0x58)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 0x60)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 0x48)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 0x50)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 0x38)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 0x40)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 0x28)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 0x30)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 0x18)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 0x20)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 8)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          *(ulonglong *)((longlong)param_1 + (param_2 - 0x10)) =
               CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
          return;
        }
        uVar9 = (ulonglong)(uint)(4 << (ulonglong)uVar5);
        if (uVar9 + 0x40 <= param_2) {
          uVar7 = (uVar8 + uVar9) - (longlong)(uVar8 + 0x10);
          puVar11 = (undefined8 *)(uVar8 + uVar9 & (uVar9 - 1 ^ 0xffffffffffffffff));
          puVar10 = (undefined8 *)(uVar8 + 0x10);
          if (uVar7 != 0) {
            do {
              puVar10[1] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,
                                                  CONCAT13(param_3,CONCAT12(param_3,CONCAT11(param_3
                                                  ,param_3)))))));
              *puVar10 = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,
                                                  CONCAT13(param_3,CONCAT12(param_3,CONCAT11(param_3
                                                  ,param_3)))))));
              puVar10[3] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,
                                                  CONCAT13(param_3,CONCAT12(param_3,CONCAT11(param_3
                                                  ,param_3)))))));
              puVar10[2] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,
                                                  CONCAT13(param_3,CONCAT12(param_3,CONCAT11(param_3
                                                  ,param_3)))))));
              puVar10[5] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,
                                                  CONCAT13(param_3,CONCAT12(param_3,CONCAT11(param_3
                                                  ,param_3)))))));
              puVar10[4] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,
                                                  CONCAT13(param_3,CONCAT12(param_3,CONCAT11(param_3
                                                  ,param_3)))))));
              puVar10[7] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,
                                                  CONCAT13(param_3,CONCAT12(param_3,CONCAT11(param_3
                                                  ,param_3)))))));
              puVar10[6] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,
                                                  CONCAT13(param_3,CONCAT12(param_3,CONCAT11(param_3
                                                  ,param_3)))))));
              bVar4 = 0x3f < uVar7;
              uVar7 = uVar7 - 0x40;
              puVar10 = puVar10 + 8;
            } while (bVar4 && uVar7 != 0);
          }
          uVar7 = (longlong)param_1 + (param_2 - (longlong)puVar11);
          uVar8 = uVar7 - uVar9;
          while (uVar6 = uVar8, uVar9 <= uVar7) {
            DC_ZVA(puVar11);
            puVar11 = (undefined8 *)((longlong)puVar11 + uVar9);
            uVar8 = uVar6 - uVar9;
            uVar7 = uVar6;
          }
          uVar6 = uVar6 + uVar9;
          goto LAB_0000491c;
        }
      }
    }
    uVar6 = (longlong)param_1 + (param_2 - uVar8) + -0x50;
    puVar10 = (undefined8 *)(uVar8 + 0x10);
    do {
      puVar11 = puVar10 + 8;
      puVar10[1] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(
                                                  param_3,CONCAT12(param_3,CONCAT11(param_3,param_3)
                                                                  ))))));
      *puVar10 = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(
                                                  param_3,CONCAT12(param_3,CONCAT11(param_3,param_3)
                                                                  ))))));
      puVar10[3] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(
                                                  param_3,CONCAT12(param_3,CONCAT11(param_3,param_3)
                                                                  ))))));
      puVar10[2] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(
                                                  param_3,CONCAT12(param_3,CONCAT11(param_3,param_3)
                                                                  ))))));
      puVar10[5] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(
                                                  param_3,CONCAT12(param_3,CONCAT11(param_3,param_3)
                                                                  ))))));
      puVar10[4] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(
                                                  param_3,CONCAT12(param_3,CONCAT11(param_3,param_3)
                                                                  ))))));
      puVar10[7] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(
                                                  param_3,CONCAT12(param_3,CONCAT11(param_3,param_3)
                                                                  ))))));
      puVar10[6] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(
                                                  param_3,CONCAT12(param_3,CONCAT11(param_3,param_3)
                                                                  ))))));
LAB_0000491c:
      bVar4 = 0x3f < uVar6;
      uVar6 = uVar6 - 0x40;
      puVar10 = puVar11;
    } while (bVar4 && uVar6 != 0);
    *(ulonglong *)((longlong)param_1 + (param_2 - 0x38)) =
         CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
    *(ulonglong *)((longlong)param_1 + (param_2 - 0x40)) =
         CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
    *(ulonglong *)((longlong)param_1 + (param_2 - 0x28)) =
         CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
    *(ulonglong *)((longlong)param_1 + (param_2 - 0x30)) =
         CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
    *(ulonglong *)((longlong)param_1 + (param_2 - 0x18)) =
         CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
    *(ulonglong *)((longlong)param_1 + (param_2 - 0x20)) =
         CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
    *(ulonglong *)((longlong)param_1 + (param_2 - 8)) =
         CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
    *(ulonglong *)((longlong)param_1 + (param_2 - 0x10)) =
         CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
    return;
  }
  uVar5 = (uint)param_2;
  if (0xf < param_2) {
    param_1[1] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(
                                                  param_3,CONCAT12(param_3,CONCAT11(param_3,param_3)
                                                                  ))))));
    *param_1 = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
    if ((uVar5 >> 6 & 1) != 0) {
      param_1[3] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(
                                                  param_3,CONCAT12(param_3,CONCAT11(param_3,param_3)
                                                                  ))))));
      param_1[2] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(
                                                  param_3,CONCAT12(param_3,CONCAT11(param_3,param_3)
                                                                  ))))));
      param_1[5] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(
                                                  param_3,CONCAT12(param_3,CONCAT11(param_3,param_3)
                                                                  ))))));
      param_1[4] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(
                                                  param_3,CONCAT12(param_3,CONCAT11(param_3,param_3)
                                                                  ))))));
      param_1[7] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(
                                                  param_3,CONCAT12(param_3,CONCAT11(param_3,param_3)
                                                                  ))))));
      param_1[6] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(
                                                  param_3,CONCAT12(param_3,CONCAT11(param_3,param_3)
                                                                  ))))));
      *(ulonglong *)((longlong)param_1 + (param_2 - 0x18)) =
           CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
      *(ulonglong *)((longlong)param_1 + (param_2 - 0x20)) =
           CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
      *(ulonglong *)((longlong)param_1 + (param_2 - 8)) =
           CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
      *(ulonglong *)((longlong)param_1 + (param_2 - 0x10)) =
           CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
      return;
    }
    *(ulonglong *)((longlong)param_1 + (param_2 - 8)) =
         CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
    *(ulonglong *)((longlong)param_1 + (param_2 - 0x10)) =
         CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
    if ((uVar5 >> 5 & 1) != 0) {
      param_1[3] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(
                                                  param_3,CONCAT12(param_3,CONCAT11(param_3,param_3)
                                                                  ))))));
      param_1[2] = CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(
                                                  param_3,CONCAT12(param_3,CONCAT11(param_3,param_3)
                                                                  ))))));
      *(ulonglong *)((longlong)param_1 + (param_2 - 0x18)) =
           CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
      *(ulonglong *)((longlong)param_1 + (param_2 - 0x20)) =
           CONCAT17(param_3,CONCAT16(param_3,CONCAT15(param_3,CONCAT14(param_3,CONCAT13(param_3,
                                                  CONCAT12(param_3,CONCAT11(param_3,param_3)))))));
    }
    return;
  }
  if ((uVar5 >> 3 & 1) == 0) {
    if ((uVar5 >> 2 & 1) == 0) {
      if ((param_2 != 0) && (*(undefined1 *)param_1 = param_3, (uVar5 >> 1 & 1) != 0)) {
        *(ushort *)((longlong)param_1 + (param_2 - 2)) = CONCAT11(param_3,param_3);
      }
      return;
    }
    *(undefined4 *)param_1 = uVar3;
    *(undefined4 *)((longlong)param_1 + (param_2 - 4)) = uVar3;
    return;
  }
  *param_1 = lVar2;
  *(longlong *)((longlong)param_1 + (param_2 - 8)) = lVar2;
  return;
}



void FUN_00004bac(undefined8 *param_1,undefined8 *param_2,ulonglong param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  longlong lVar8;
  bool bVar9;
  ulonglong uVar10;
  undefined8 *puVar11;
  ulonglong uVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  uint uVar18;
  undefined8 uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  
  if (0x60 < param_3 && (ulonglong)((longlong)param_1 - (longlong)param_2) < param_3) {
    if (param_1 != param_2) {
      uVar10 = (longlong)param_1 + param_3;
      uVar12 = uVar10 & 0xf;
      uVar17 = *(undefined8 *)((longlong)param_2 + (param_3 - 8));
      lVar8 = param_3 - uVar12;
      uVar15 = *(undefined8 *)((longlong)param_2 + lVar8 + -0x10);
      uVar16 = *(undefined8 *)((longlong)param_2 + lVar8 + -8);
      *(undefined8 *)(uVar10 - 0x10) = *(undefined8 *)((longlong)param_2 + (param_3 - 0x10));
      *(undefined8 *)(uVar10 - 8) = uVar17;
      uVar17 = *(undefined8 *)((longlong)param_2 + lVar8 + -0x20);
      uVar19 = *(undefined8 *)((longlong)param_2 + lVar8 + -0x18);
      uVar20 = *(undefined8 *)((longlong)param_2 + lVar8 + -0x30);
      uVar21 = *(undefined8 *)((longlong)param_2 + lVar8 + -0x28);
      puVar13 = (undefined8 *)((longlong)param_2 + lVar8 + -0x40);
      uVar22 = *puVar13;
      uVar23 = *(undefined8 *)((longlong)param_2 + lVar8 + -0x38);
      puVar14 = (undefined8 *)(uVar10 - uVar12);
      uVar10 = (param_3 - uVar12) - 0x80;
      puVar11 = puVar14;
      if (0x7f < param_3 - uVar12 && uVar10 != 0) {
        do {
          puVar11[-2] = uVar15;
          puVar11[-1] = uVar16;
          uVar15 = puVar13[-2];
          uVar16 = puVar13[-1];
          puVar11[-4] = uVar17;
          puVar11[-3] = uVar19;
          uVar17 = puVar13[-4];
          uVar19 = puVar13[-3];
          puVar11[-6] = uVar20;
          puVar11[-5] = uVar21;
          uVar20 = puVar13[-6];
          uVar21 = puVar13[-5];
          puVar14 = puVar11 + -8;
          *puVar14 = uVar22;
          puVar11[-7] = uVar23;
          uVar22 = puVar13[-8];
          uVar23 = puVar13[-7];
          bVar9 = 0x3f < uVar10;
          uVar10 = uVar10 - 0x40;
          puVar13 = puVar13 + -8;
          puVar11 = puVar14;
        } while (bVar9 && uVar10 != 0);
      }
      uVar1 = param_2[6];
      uVar4 = param_2[7];
      puVar14[-2] = uVar15;
      puVar14[-1] = uVar16;
      uVar15 = param_2[4];
      uVar16 = param_2[5];
      puVar14[-4] = uVar17;
      puVar14[-3] = uVar19;
      uVar17 = param_2[2];
      uVar19 = param_2[3];
      puVar14[-6] = uVar20;
      puVar14[-5] = uVar21;
      uVar20 = *param_2;
      uVar21 = param_2[1];
      puVar14[-8] = uVar22;
      puVar14[-7] = uVar23;
      param_1[6] = uVar1;
      param_1[7] = uVar4;
      param_1[4] = uVar15;
      param_1[5] = uVar16;
      param_1[2] = uVar17;
      param_1[3] = uVar19;
      *param_1 = uVar20;
      param_1[1] = uVar21;
    }
    return;
  }
  Hint_Prefetch(param_2,0,0,0);
  if (param_3 < 0x11) {
    if (7 < param_3) {
      uVar15 = *(undefined8 *)((longlong)param_2 + (param_3 - 8));
      *param_1 = *param_2;
      *(undefined8 *)((longlong)param_1 + (param_3 - 8)) = uVar15;
      return;
    }
    if (((uint)param_3 >> 2 & 1) != 0) {
      uVar5 = *(undefined4 *)((longlong)param_2 + (param_3 - 4));
      *(undefined4 *)param_1 = *(undefined4 *)param_2;
      *(undefined4 *)((longlong)param_1 + (param_3 - 4)) = uVar5;
      return;
    }
    if (param_3 != 0) {
      uVar7 = *(undefined1 *)((longlong)param_2 + (param_3 - 1));
      uVar6 = *(undefined1 *)((longlong)param_2 + (param_3 >> 1));
      *(undefined1 *)param_1 = *(undefined1 *)param_2;
      *(undefined1 *)((longlong)param_1 + (param_3 >> 1)) = uVar6;
      *(undefined1 *)((longlong)param_1 + (param_3 - 1)) = uVar7;
    }
    return;
  }
  if (0x60 < param_3) {
    uVar12 = (ulonglong)param_1 & 0xf;
    puVar14 = (undefined8 *)((ulonglong)param_1 & 0xfffffffffffffff0);
    uVar17 = param_2[1];
    uVar15 = *(undefined8 *)((longlong)param_2 + (0x10 - uVar12));
    uVar16 = *(undefined8 *)((longlong)param_2 + (0x18 - uVar12));
    *param_1 = *param_2;
    param_1[1] = uVar17;
    uVar17 = *(undefined8 *)((longlong)param_2 + (0x20 - uVar12));
    uVar19 = *(undefined8 *)((longlong)param_2 + (0x28 - uVar12));
    uVar20 = *(undefined8 *)((longlong)param_2 + (0x30 - uVar12));
    uVar21 = *(undefined8 *)((longlong)param_2 + (0x38 - uVar12));
    puVar13 = (undefined8 *)((longlong)param_2 + (0x40 - uVar12));
    uVar22 = *puVar13;
    uVar23 = *(undefined8 *)((longlong)param_2 + (0x48 - uVar12));
    uVar10 = (param_3 + uVar12) - 0x90;
    puVar11 = puVar14;
    if (0x8f < param_3 + uVar12 && uVar10 != 0) {
      do {
        puVar11[2] = uVar15;
        puVar11[3] = uVar16;
        uVar15 = puVar13[2];
        uVar16 = puVar13[3];
        puVar11[4] = uVar17;
        puVar11[5] = uVar19;
        uVar17 = puVar13[4];
        uVar19 = puVar13[5];
        puVar11[6] = uVar20;
        puVar11[7] = uVar21;
        uVar20 = puVar13[6];
        uVar21 = puVar13[7];
        puVar14 = puVar11 + 8;
        *puVar14 = uVar22;
        puVar11[9] = uVar23;
        uVar22 = puVar13[8];
        uVar23 = puVar13[9];
        bVar9 = 0x3f < uVar10;
        uVar10 = uVar10 - 0x40;
        puVar13 = puVar13 + 8;
        puVar11 = puVar14;
      } while (bVar9 && uVar10 != 0);
    }
    uVar1 = *(undefined8 *)((longlong)param_2 + (param_3 - 0x40));
    uVar4 = *(undefined8 *)((longlong)param_2 + (param_3 - 0x38));
    puVar14[2] = uVar15;
    puVar14[3] = uVar16;
    uVar15 = *(undefined8 *)((longlong)param_2 + (param_3 - 0x30));
    uVar16 = *(undefined8 *)((longlong)param_2 + (param_3 - 0x28));
    puVar14[4] = uVar17;
    puVar14[5] = uVar19;
    uVar17 = *(undefined8 *)((longlong)param_2 + (param_3 - 0x20));
    uVar19 = *(undefined8 *)((longlong)param_2 + (param_3 - 0x18));
    puVar14[6] = uVar20;
    puVar14[7] = uVar21;
    uVar20 = *(undefined8 *)((longlong)param_2 + (param_3 - 0x10));
    uVar21 = *(undefined8 *)((longlong)param_2 + (param_3 - 8));
    puVar14[8] = uVar22;
    puVar14[9] = uVar23;
    *(undefined8 *)((longlong)param_1 + (param_3 - 0x40)) = uVar1;
    *(undefined8 *)((longlong)param_1 + (param_3 - 0x38)) = uVar4;
    *(undefined8 *)((longlong)param_1 + (param_3 - 0x30)) = uVar15;
    *(undefined8 *)((longlong)param_1 + (param_3 - 0x28)) = uVar16;
    *(undefined8 *)((longlong)param_1 + (param_3 - 0x20)) = uVar17;
    *(undefined8 *)((longlong)param_1 + (param_3 - 0x18)) = uVar19;
    *(undefined8 *)((longlong)param_1 + (param_3 - 0x10)) = uVar20;
    *(undefined8 *)((longlong)param_1 + (param_3 - 8)) = uVar21;
    return;
  }
  uVar18 = (uint)param_3 - 1;
  uVar15 = *param_2;
  uVar17 = param_2[1];
  if ((uVar18 >> 6 & 1) == 0) {
    uVar20 = *(undefined8 *)((longlong)param_2 + (param_3 - 0x10));
    uVar22 = *(undefined8 *)((longlong)param_2 + (param_3 - 8));
    if ((uVar18 >> 5 & 1) != 0) {
      uVar19 = param_2[3];
      uVar16 = *(undefined8 *)((longlong)param_2 + (param_3 - 0x20));
      uVar21 = *(undefined8 *)((longlong)param_2 + (param_3 - 0x18));
      param_1[2] = param_2[2];
      param_1[3] = uVar19;
      *(undefined8 *)((longlong)param_1 + (param_3 - 0x20)) = uVar16;
      *(undefined8 *)((longlong)param_1 + (param_3 - 0x18)) = uVar21;
    }
    *param_1 = uVar15;
    param_1[1] = uVar17;
    *(undefined8 *)((longlong)param_1 + (param_3 - 0x10)) = uVar20;
    *(undefined8 *)((longlong)param_1 + (param_3 - 8)) = uVar22;
    return;
  }
  uVar20 = param_2[2];
  uVar23 = param_2[3];
  uVar22 = param_2[4];
  uVar1 = param_2[5];
  uVar16 = param_2[6];
  uVar4 = param_2[7];
  uVar19 = *(undefined8 *)((longlong)param_2 + (param_3 - 0x20));
  uVar2 = *(undefined8 *)((longlong)param_2 + (param_3 - 0x18));
  uVar21 = *(undefined8 *)((longlong)param_2 + (param_3 - 0x10));
  uVar3 = *(undefined8 *)((longlong)param_2 + (param_3 - 8));
  *param_1 = uVar15;
  param_1[1] = uVar17;
  param_1[2] = uVar20;
  param_1[3] = uVar23;
  param_1[4] = uVar22;
  param_1[5] = uVar1;
  param_1[6] = uVar16;
  param_1[7] = uVar4;
  *(undefined8 *)((longlong)param_1 + (param_3 - 0x20)) = uVar19;
  *(undefined8 *)((longlong)param_1 + (param_3 - 0x18)) = uVar2;
  *(undefined8 *)((longlong)param_1 + (param_3 - 0x10)) = uVar21;
  *(undefined8 *)((longlong)param_1 + (param_3 - 8)) = uVar3;
  return;
}



// WARNING: Removing unreachable block (ram,0x00004c74)

undefined4 FUN_00004c58(void)

{
  FUN_0000e0b0();
  do {
  } while( true );
}



ulonglong FUN_00004c80(short *param_1)

{
  ulonglong uVar1;
  
  if (param_1 == (short *)0x0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  if (((ulonglong)param_1 & 1) != 0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  uVar1 = 0;
  while( true ) {
    if (*param_1 == 0) {
      return uVar1;
    }
    if (999999 < uVar1) break;
    param_1 = param_1 + 1;
    uVar1 = uVar1 + 1;
  }
  FUN_0000464c();
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



longlong FUN_00004d1c(short *param_1)

{
  ulonglong uVar1;
  
  uVar1 = FUN_00004c80(param_1);
  return uVar1 * 2 + 2;
}



longlong FUN_00004d38(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  longlong lVar2;
  
  lVar2 = FUN_00004d1c((short *)param_1);
  if (lVar2 == 0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  lVar2 = FUN_00004d1c((short *)param_2);
  if (lVar2 == 0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  while( true ) {
    uVar1 = *param_1;
    if ((uVar1 == 0) || (uVar1 != *param_2)) break;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return (ulonglong)uVar1 - (ulonglong)*param_2;
}



longlong FUN_00004dc4(ushort *param_1,ushort *param_2,ulonglong param_3)

{
  ushort uVar1;
  ushort uVar2;
  longlong lVar3;
  
  if (param_3 == 0) {
    lVar3 = 0;
  }
  else {
    lVar3 = FUN_00004d1c((short *)param_1);
    if (lVar3 == 0) {
      FUN_0000464c();
      do {
                    // WARNING: Do nothing block with infinite loop
      } while( true );
    }
    lVar3 = FUN_00004d1c((short *)param_2);
    if (lVar3 == 0) {
      FUN_0000464c();
      do {
                    // WARNING: Do nothing block with infinite loop
      } while( true );
    }
    if (1000000 < param_3) {
      FUN_0000464c();
      do {
                    // WARNING: Do nothing block with infinite loop
      } while( true );
    }
    while( true ) {
      uVar1 = *param_1;
      uVar2 = *param_2;
      if (((uVar1 == 0) || (uVar2 == 0)) || (param_3 < 2 || uVar1 != uVar2)) break;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      param_3 = param_3 - 1;
    }
    lVar3 = (ulonglong)uVar1 - (ulonglong)uVar2;
  }
  return lVar3;
}



bool FUN_00004ea8(char param_1)

{
  return (byte)(param_1 - 0x30U) < 10;
}



bool FUN_00004ebc(byte param_1)

{
  if ((byte)(param_1 - 0x30) < 10) {
    return true;
  }
  return (byte)((param_1 & 0xdf) + 0xbf) < 6;
}



longlong FUN_00004ef0(char *param_1)

{
  ulonglong uVar1;
  
  uVar1 = FUN_00004f08(param_1);
  return uVar1 + 1;
}



ulonglong FUN_00004f08(char *param_1)

{
  ulonglong uVar1;
  
  if (param_1 == (char *)0x0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  uVar1 = 0;
  while( true ) {
    if (*param_1 == '\0') {
      return uVar1;
    }
    if (999999 < uVar1) break;
    param_1 = param_1 + 1;
    uVar1 = uVar1 + 1;
  }
  FUN_0000464c();
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



uint FUN_00004f84(byte param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)param_1;
  uVar1 = uVar2 + 0xe0;
  if (0x19 < (uVar2 - 0x61 & 0xff)) {
    uVar1 = uVar2;
  }
  return uVar1;
}



longlong FUN_00004fa0(uint param_1)

{
  longlong lVar1;
  
  if (((param_1 & 0xff) - 0x30 & 0xffff) < 10) {
    lVar1 = -0x30;
  }
  else {
    param_1 = FUN_00004f84((byte)param_1);
    lVar1 = -0x37;
  }
  return lVar1 + (ulonglong)(param_1 & 0xff);
}



longlong FUN_00004fdc(byte *param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  
  lVar4 = FUN_00004ef0((char *)param_1);
  if (lVar4 == 0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  lVar4 = FUN_00004ef0((char *)param_2);
  if (lVar4 == 0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  while( true ) {
    bVar1 = *param_1;
    uVar2 = FUN_00004f84(bVar1);
    uVar3 = FUN_00004f84(*param_2);
    if ((bVar1 == 0) || ((uVar2 & 0xff) != (uVar3 & 0xff))) break;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return (ulonglong)(uVar2 & 0xff) - (ulonglong)(uVar3 & 0xff);
}



ulonglong FUN_00005090(byte *param_1)

{
  ulonglong local_18;
  
  FUN_00005184(param_1,(undefined8 *)0x0,&local_18);
  return local_18;
}



ulonglong FUN_000050b8(byte *param_1)

{
  ulonglong local_18;
  
  FUN_000052e4(param_1,(undefined8 *)0x0,&local_18);
  return local_18;
}



ulonglong FUN_000050e0(short *param_1,ulonglong param_2)

{
  ulonglong uVar1;
  
  if (((ulonglong)param_1 & 1) != 0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  uVar1 = 0;
  if ((param_1 != (short *)0x0) && (param_2 != 0)) {
    uVar1 = 0;
    while (*param_1 != 0) {
      if (param_2 - 1 <= uVar1) {
        return param_2;
      }
      uVar1 = uVar1 + 1;
      param_1 = param_1 + 1;
    }
  }
  return uVar1;
}



ulonglong FUN_00005148(char *param_1,ulonglong param_2)

{
  ulonglong uVar1;
  
  uVar1 = 0;
  if ((param_1 != (char *)0x0) && (param_2 != 0)) {
    uVar1 = 0;
    while (*param_1 != '\0') {
      if (param_2 - 1 <= uVar1) {
        return param_2;
      }
      uVar1 = uVar1 + 1;
      param_1 = param_1 + 1;
    }
  }
  return uVar1;
}



undefined8 FUN_00005184(byte *param_1,undefined8 *param_2,ulonglong *param_3)

{
  byte *pbVar1;
  byte bVar2;
  bool bVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  
  if (param_1 == (byte *)0x0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  if (param_3 == (ulonglong *)0x0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  uVar4 = FUN_00005148((char *)param_1,0xf4241);
  if (1000000 < uVar4) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = param_1;
  }
  for (; (bVar2 = *param_1, bVar2 == 9 || (bVar2 == 0x20)); param_1 = param_1 + 1) {
  }
  while (bVar2 == 0x30) {
    pbVar1 = param_1 + 1;
    param_1 = param_1 + 1;
    bVar2 = *pbVar1;
  }
  *param_3 = 0;
  do {
    bVar3 = FUN_00004ea8(*param_1);
    if (!bVar3) {
      if (param_2 == (undefined8 *)0x0) {
        uVar5 = 0;
      }
      else {
        uVar5 = 0;
LAB_000052c4:
        *param_2 = param_1;
      }
      return uVar5;
    }
    bVar2 = *param_1;
    if ((0x2f - (ulonglong)bVar2) / 10 < *param_3) {
      uVar5 = 0x8000000000000003;
      *param_3 = 0xffffffffffffffff;
      if (param_2 == (undefined8 *)0x0) {
        return 0x8000000000000003;
      }
      goto LAB_000052c4;
    }
    param_1 = param_1 + 1;
    *param_3 = ((ulonglong)bVar2 + *param_3 * 10) - 0x30;
  } while( true );
}



undefined8 FUN_000052e4(byte *param_1,undefined8 *param_2,ulonglong *param_3)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  ulonglong uVar4;
  longlong lVar5;
  undefined8 uVar6;
  byte *pbVar7;
  ulonglong uVar8;
  
  if (param_1 == (byte *)0x0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  if (param_3 == (ulonglong *)0x0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  uVar4 = FUN_00005148((char *)param_1,0xf4241);
  if (1000000 < uVar4) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = param_1;
  }
  do {
    do {
      pbVar7 = param_1 + 1;
      bVar1 = *param_1;
      param_1 = pbVar7;
    } while (bVar1 == 9);
  } while (bVar1 == 0x20);
  while (bVar1 == 0x30) {
    bVar1 = *pbVar7;
    pbVar7 = pbVar7 + 1;
  }
  uVar3 = FUN_00004f84(bVar1);
  if ((uVar3 & 0xff) == 0x58) {
    if (pbVar7[-2] != 0x30) {
      *param_3 = 0;
      return 0;
    }
  }
  else {
    pbVar7 = pbVar7 + -1;
  }
  *param_3 = 0;
  do {
    bVar2 = FUN_00004ebc(*pbVar7);
    if (!bVar2) {
      if (param_2 == (undefined8 *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = 0;
LAB_00005440:
        *param_2 = pbVar7;
      }
      return uVar6;
    }
    uVar8 = *param_3;
    uVar4 = FUN_00004fa0((uint)*pbVar7);
    if ((uVar4 >> 4 ^ 0xfffffffffffffff) < uVar8) {
      uVar6 = 0x8000000000000003;
      *param_3 = 0xffffffffffffffff;
      if (param_2 == (undefined8 *)0x0) {
        return 0x8000000000000003;
      }
      goto LAB_00005440;
    }
    uVar4 = *param_3;
    lVar5 = FUN_00004fa0((uint)*pbVar7);
    *param_3 = lVar5 + uVar4 * 0x10;
    pbVar7 = pbVar7 + 1;
  } while( true );
}



ulonglong FUN_0000545c(ulonglong param_1,uint param_2,int *param_3)

{
  int iVar1;
  ulonglong uVar2;
  
  if (param_3 != (int *)0x0) {
    iVar1 = 0;
    if ((ulonglong)param_2 != 0) {
      iVar1 = (int)(param_1 / param_2);
    }
    *param_3 = (int)param_1 - iVar1 * param_2;
  }
  uVar2 = 0;
  if ((ulonglong)param_2 != 0) {
    uVar2 = param_1 / param_2;
  }
  return uVar2;
}



undefined8 FUN_00005480(longlong param_1,longlong param_2)

{
  DAT_00017250 = param_1;
  if (param_1 == 0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  DAT_00017258 = param_2;
  if (param_2 != 0) {
    DAT_00017260 = *(longlong *)(param_2 + 0x60);
    if (DAT_00017260 != 0) {
      return 0;
    }
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  FUN_0000464c();
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



undefined8 FUN_00005510(void)

{
  DAT_00017270 = (undefined8 *)
                 FUN_00004158((undefined1 *)((ulonglong)DAT_00017268 << 4),
                              (undefined1 *)((ulonglong)(DAT_00017268 + 0x10) << 4),DAT_00017270);
  if (DAT_00017270 != (undefined8 *)0x0) {
    DAT_00017278 = (undefined8 *)
                   FUN_00004158((undefined1 *)((ulonglong)DAT_00017268 << 3),
                                (undefined1 *)((ulonglong)(DAT_00017268 + 0x10) << 3),DAT_00017278);
    if ((DAT_00017278 != (undefined8 *)0x0) &&
       (DAT_00017280 = (undefined8 *)
                       FUN_00004158((undefined1 *)((ulonglong)DAT_00017268 << 3),
                                    (undefined1 *)((ulonglong)(DAT_00017268 + 0x10) << 3),
                                    DAT_00017280), DAT_00017280 != (undefined8 *)0x0)) {
      DAT_00017268 = DAT_00017268 + 0x10;
      return 0;
    }
    if (DAT_00017270 != (undefined8 *)0x0) {
      FUN_00004100();
    }
  }
  if (DAT_00017278 != (undefined8 *)0x0) {
    FUN_00004100();
  }
  if (DAT_00017280 != (undefined8 *)0x0) {
    FUN_00004100();
  }
  return 0x8000000000000009;
}



undefined8 thunk_FUN_00005510(void)

{
  DAT_00017270 = (undefined8 *)
                 FUN_00004158((undefined1 *)((ulonglong)DAT_00017268 << 4),
                              (undefined1 *)((ulonglong)(DAT_00017268 + 0x10) << 4),DAT_00017270);
  if (DAT_00017270 != (undefined8 *)0x0) {
    DAT_00017278 = (undefined8 *)
                   FUN_00004158((undefined1 *)((ulonglong)DAT_00017268 << 3),
                                (undefined1 *)((ulonglong)(DAT_00017268 + 0x10) << 3),DAT_00017278);
    if ((DAT_00017278 != (undefined8 *)0x0) &&
       (DAT_00017280 = (undefined8 *)
                       FUN_00004158((undefined1 *)((ulonglong)DAT_00017268 << 3),
                                    (undefined1 *)((ulonglong)(DAT_00017268 + 0x10) << 3),
                                    DAT_00017280), DAT_00017280 != (undefined8 *)0x0)) {
      DAT_00017268 = DAT_00017268 + 0x10;
      return 0;
    }
    if (DAT_00017270 != (undefined8 *)0x0) {
      FUN_00004100();
    }
  }
  if (DAT_00017278 != (undefined8 *)0x0) {
    FUN_00004100();
  }
  if (DAT_00017280 != (undefined8 *)0x0) {
    FUN_00004100();
  }
  return 0x8000000000000009;
}



undefined8 FUN_000055f0(undefined8 param_1,longlong param_2)

{
  DAT_00017288 = *(longlong *)(param_2 + 0x58);
  if (DAT_00017288 != 0) {
    return 0;
  }
  FUN_0000464c();
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



undefined8 FUN_00005630(void)

{
  return 0;
}



undefined8 FUN_00005638(longlong *param_1,undefined8 *param_2)

{
  longlong lVar1;
  bool bVar2;
  ulonglong uVar3;
  longlong lVar4;
  
  lVar1 = DAT_00017258;
  if (param_1 == (longlong *)0x0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  if (param_2 != (undefined8 *)0x0) {
    uVar3 = 0;
    lVar4 = 0x10;
    *param_2 = 0;
    while( true ) {
      if (*(ulonglong *)(lVar1 + 0x68) <= uVar3) {
        return 0x800000000000000e;
      }
      bVar2 = FUN_000106d8(param_1,(undefined8 *)(*(longlong *)(lVar1 + 0x70) + lVar4 + -0x10));
      if (bVar2) break;
      uVar3 = uVar3 + 1;
      lVar4 = lVar4 + 0x18;
    }
    *param_2 = *(undefined8 *)(*(longlong *)(lVar1 + 0x70) + lVar4);
    return 0;
  }
  FUN_0000464c();
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void FUN_00005710(undefined8 *param_1)

{
  undefined8 uVar1;
  
  if (param_1 == (undefined8 *)0x0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  if (*(int *)(param_1 + 2) == 1) {
    uVar1 = (**(code **)(DAT_00017260 + 0x18))(*param_1);
    param_1[1] = uVar1;
    *(undefined4 *)(param_1 + 2) = 2;
    return;
  }
  FUN_0000464c();
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void FUN_00005794(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = DAT_00017260;
  if (param_1 == 0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  if (*(int *)(param_1 + 0x10) == 2) {
    *(undefined4 *)(param_1 + 0x10) = 1;
                    // WARNING: Could not recover jumptable at 0x000057cc. Too many branches
                    // WARNING: Treating indirect jump as call
    (**(code **)(lVar1 + 0x20))(*(undefined8 *)(param_1 + 8));
    return;
  }
  FUN_0000464c();
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



longlong FUN_00005808(void)

{
  longlong lVar1;
  
  lVar1 = FUN_00005638((longlong *)&DAT_00016128,&DAT_00017290);
  if (lVar1 < 0) {
    FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
    FUN_0000464c();
  }
  if (DAT_00017290 != 0) {
    return lVar1;
  }
  FUN_0000464c();
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void FUN_000058a4(void)

{
  FUN_000058d0();
  DAT_00017298 = 1;
  return;
}



void FUN_000058d0(void)

{
                    // WARNING: Could not recover jumptable at 0x000058dc. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)(DAT_00017288 + 0x40))();
  return;
}



longlong FUN_000058e0(void)

{
  longlong lVar1;
  
  if (DAT_00017288 == 0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  if (DAT_00017260 != 0) {
    DAT_000172a0 = DAT_00017288;
    lVar1 = (**(code **)(DAT_00017260 + 0x170))(0x200,8,FUN_000058a4,0,&DAT_000160c8,&DAT_000172a8);
    if (lVar1 < 0) {
      FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
      FUN_0000464c();
    }
    lVar1 = (**(code **)(DAT_00017260 + 0x170))(0x200,8,&LAB_00005894,0,&DAT_000160b8,&DAT_000172b0)
    ;
    if (lVar1 < 0) {
      FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
      FUN_0000464c();
    }
    return lVar1;
  }
  FUN_0000464c();
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



longlong FUN_00005a18(void)

{
  longlong lVar1;
  
  if (DAT_00017260 != 0) {
    lVar1 = (**(code **)(DAT_00017260 + 0x70))(DAT_000172a8);
    if (lVar1 < 0) {
      FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
      FUN_0000464c();
    }
    lVar1 = (**(code **)(DAT_00017260 + 0x70))(DAT_000172b0);
    if (lVar1 < 0) {
      FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
      FUN_0000464c();
    }
    return lVar1;
  }
  FUN_0000464c();
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



void FUN_00005ae8(void)

{
  longlong lVar1;
  
  if ((((DAT_000172b8 == 0) && (DAT_000172c0 == '\0')) && (DAT_00017260 != 0)) &&
     ((*(code **)(DAT_00017260 + 0x140) != (code *)0x0 &&
      (lVar1 = (**(code **)(DAT_00017260 + 0x140))(&DAT_000162b8,0,&DAT_000172b8), lVar1 < 0)))) {
    DAT_000172b8 = 0;
  }
  return;
}



void FUN_00005b6c(void)

{
  FUN_00005ae8();
  DAT_000172c0 = 1;
  return;
}



undefined8 FUN_00005b8c(void)

{
  longlong lVar1;
  
  FUN_00005ae8();
  lVar1 = (**(code **)(DAT_00017260 + 0x170))
                    (0x200,0x10,&LAB_00005b4c,0,&DAT_000160c8,&DAT_000172c8);
  if (lVar1 < 0) {
    FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
    FUN_0000464c();
  }
  lVar1 = (**(code **)(DAT_00017260 + 0x170))(0x200,0x10,FUN_00005b6c,0,&DAT_000160b8,&DAT_000172d0)
  ;
  if (lVar1 < 0) {
    FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
    FUN_0000464c();
  }
  return 0;
}



undefined8 FUN_00005c78(void)

{
  longlong lVar1;
  
  if (DAT_00017260 != 0) {
    lVar1 = (**(code **)(DAT_00017260 + 0x70))(DAT_000172c8);
    if (lVar1 < 0) {
      FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
      FUN_0000464c();
    }
    lVar1 = (**(code **)(DAT_00017260 + 0x70))(DAT_000172d0);
    if (lVar1 < 0) {
      FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
      FUN_0000464c();
    }
    return 0;
  }
  FUN_0000464c();
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



undefined8
FUN_00005d48(uint param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
            undefined8 param_5)

{
  char cVar1;
  undefined8 uVar2;
  
  cVar1 = FUN_00005e14();
  if (((((param_1 & 0xff) == 2) && (cVar1 != '\0')) ||
      ((cVar1 = FUN_00005e24(), (param_1 & 0xff) == 3 && (cVar1 != '\0')))) &&
     (FUN_00005ae8(), DAT_000172b8 != (undefined8 *)0x0)) {
                    // WARNING: Could not recover jumptable at 0x00005de8. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar2 = (*(code *)*DAT_000172b8)(param_1,param_2,param_3,param_4,param_5);
    return uVar2;
  }
  return 0x8000000000000003;
}



undefined4 FUN_00005e04(void)

{
  return 0;
}



undefined1 FUN_00005e14(void)

{
  return 1;
}



undefined1 FUN_00005e24(void)

{
  return 1;
}



void FUN_00005e34(uint param_1,undefined4 param_2)

{
  FUN_00005d48(param_1,param_2,0,&DAT_00016018,0);
  return;
}



void FUN_00005e48(void)

{
  longlong lVar1;
  
  if (DAT_000172d8 == 0) {
    lVar1 = FUN_00005638((longlong *)&DAT_00016138,&DAT_000172d8);
    if (lVar1 < 0) {
      FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
      FUN_0000464c();
    }
    if (DAT_000172d8 == 0) {
      FUN_0000464c();
      do {
                    // WARNING: Do nothing block with infinite loop
      } while( true );
    }
  }
  return;
}



undefined8 FUN_00005ed8(void)

{
  FUN_00005e48();
  return 0;
}



short * FUN_00005ef0(short param_1,short *param_2)

{
  if (param_2 == (short *)0x0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  while( true ) {
    if (*param_2 == -1) {
      return (short *)0x0;
    }
    if (*param_2 == param_1) break;
    param_2 = (short *)((longlong)param_2 + (ulonglong)(ushort)param_2[1]);
  }
  return param_2;
}



short * FUN_00005f4c(longlong *param_1,short *param_2)

{
  bool bVar1;
  short *psVar2;
  
  while ((psVar2 = FUN_00005ef0(4,param_2), psVar2 != (short *)0x0 &&
         (bVar1 = FUN_000106d8(param_1,(undefined8 *)(psVar2 + 4)), !bVar1))) {
    param_2 = (short *)((longlong)psVar2 + (ulonglong)(ushort)psVar2[1]);
  }
  return psVar2;
}



void FUN_00005f9c(longlong *param_1)

{
  short *psVar1;
  
  psVar1 = (short *)FUN_00005e48();
  FUN_00005f4c(param_1,psVar1);
  return;
}



// WARNING: Removing unreachable block (ram,0x00006030)
// WARNING: Removing unreachable block (ram,0x00006048)

undefined8 FUN_00005fc4(void)

{
  longlong lVar1;
  
  lVar1 = FUN_000042e0();
  if (lVar1 == 0) {
    FUN_00004548(0x80000000,
                 (byte *)
                 "ARM Architectural Timer is not available in the CPU, hence this library cannot be used.\n"
                );
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  lVar1 = thunk_FUN_00011370();
  if (lVar1 == 0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  return 0;
}



undefined8 FUN_00006068(void)

{
  FUN_00004208(0x60b8,0x108);
  return 0;
}



undefined8 FUN_000061c4(void)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  
  ppuVar1 = (undefined **)PTR_LOOP_00016e60;
  if ((undefined **)PTR_LOOP_00016e60 != &PTR_LOOP_00016e60) {
    do {
      ppuVar2 = (undefined **)*ppuVar1;
      if (*(char *)((longlong)ppuVar1 + -4) == '\0') {
        (**(code **)(DAT_00017260 + 0x30))(ppuVar1[-4],ppuVar1[-2]);
        FUN_00010a30((longlong *)ppuVar1);
        FUN_00004100();
      }
      ppuVar1 = ppuVar2;
    } while (ppuVar2 != &PTR_LOOP_00016e60);
  }
  return 0;
}



void FUN_000062ec(void)

{
                    // WARNING: Could not recover jumptable at 0x00006304. Too many branches
                    // WARNING: Treating indirect jump as call
  (**(code **)((longlong)&PTR_LAB_00006308 + DAT_00016e88))();
  return;
}



void FUN_000063d0(uint param_1,char param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)((&DAT_000172e8)[param_1] + 0x20c);
  uVar1 = uVar2 | 2;
  if (param_2 == '\0') {
    uVar1 = uVar2 & 0xfffffffd;
  }
  *(uint *)((&DAT_000172e8)[param_1] + 0x20c) = uVar1;
  return;
}



void FUN_000063f8(ulonglong param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  ulonglong uVar5;
  uint uVar6;
  
  uVar5 = param_1 & 0xffffffff;
  lVar4 = (&DAT_000172e8)[param_1 & 0xffffffff];
  *(char *)(lVar4 + 0x2f) = (char)param_2;
  if ((param_2 == 1) && ((*(byte *)(lVar4 + 0x29) & 1) != 0)) {
    iVar2 = 10000;
    do {
      lVar4 = (&DAT_000172e8)[uVar5];
      uVar6 = *(uint *)(lVar4 + 0x240);
      if (uVar6 != 0) goto LAB_00006460;
      FUN_00010c0c(1);
      bVar1 = iVar2 != 0;
      iVar2 = iVar2 + -1;
    } while (bVar1);
    lVar4 = (&DAT_000172e8)[uVar5];
    uVar6 = 0;
LAB_00006460:
    *(uint *)(lVar4 + 0x248) = uVar6;
    iVar2 = 10000;
    do {
      lVar4 = (&DAT_000172e8)[uVar5];
      if (*(int *)(lVar4 + 0x240) == 0) goto LAB_0000648c;
      FUN_00010c0c(1);
      bVar1 = iVar2 != 0;
      iVar2 = iVar2 + -1;
    } while (bVar1);
    lVar4 = (&DAT_000172e8)[uVar5];
LAB_0000648c:
    uVar3 = 4;
    if ((uVar6 & 3) != 0) {
      uVar3 = 1;
    }
    *(undefined4 *)(lVar4 + 0x24c) = uVar3;
  }
  iVar2 = 10000;
  do {
    if (iVar2 == 0) {
      return;
    }
    iVar2 = iVar2 + -1;
  } while ((*(byte *)((&DAT_000172e8)[uVar5] + 0x2f) & param_2) != 0);
  return;
}



void FUN_000064cc(ulonglong param_1)

{
  bool bVar1;
  longlong lVar2;
  int iVar3;
  undefined4 uVar4;
  ulonglong uVar5;
  uint uVar6;
  
  uVar5 = param_1 & 0xffffffff;
  iVar3 = 10000;
  do {
    lVar2 = (&DAT_000172e8)[uVar5];
    uVar6 = *(uint *)(lVar2 + 0x240);
    if (uVar6 != 0) goto LAB_00006514;
    FUN_00010c0c(1);
    bVar1 = iVar3 != 0;
    iVar3 = iVar3 + -1;
  } while (bVar1);
  lVar2 = (&DAT_000172e8)[uVar5];
  uVar6 = 0;
LAB_00006514:
  *(uint *)(lVar2 + 0x248) = uVar6;
  iVar3 = 10000;
  do {
    lVar2 = (&DAT_000172e8)[uVar5];
    if (*(int *)(lVar2 + 0x240) == 0) goto LAB_00006540;
    FUN_00010c0c(1);
    bVar1 = iVar3 != 0;
    iVar3 = iVar3 + -1;
  } while (bVar1);
  lVar2 = (&DAT_000172e8)[uVar5];
LAB_00006540:
  uVar4 = 4;
  if ((uVar6 & 3) != 0) {
    uVar4 = 1;
  }
  *(undefined4 *)(lVar2 + 0x24c) = uVar4;
  return;
}



void FUN_00006560(uint param_1,int param_2)

{
  *(uint *)((&DAT_000172e8)[param_1] + 0x200) =
       *(uint *)((&DAT_000172e8)[param_1] + 0x200) & 0xf8ffffff | param_2 << 0x18;
  return;
}



void FUN_00006580(uint param_1,char param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)((&DAT_000172e8)[param_1] + 0x200);
  uVar1 = uVar2 | 0x40000000;
  if (param_2 == '\0') {
    uVar1 = uVar2 & 0xbfffffff;
  }
  uVar2 = uVar1 | 0x20000000;
  if (param_2 == '\0') {
    uVar2 = uVar1 & 0xdfffffff;
  }
  *(uint *)((&DAT_000172e8)[param_1] + 0x200) = uVar2;
  return;
}



void FUN_000065b4(uint param_1)

{
  *(uint *)((&DAT_000172e8)[param_1] + 0x200) =
       *(uint *)((&DAT_000172e8)[param_1] + 0x200) | 0x10000;
  return;
}



void FUN_000065d0(uint param_1)

{
  *(uint *)((&DAT_000172e8)[param_1] + 0x200) =
       *(uint *)((&DAT_000172e8)[param_1] + 0x200) | 0x40000;
  return;
}



void FUN_000065ec(uint param_1,char param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)((&DAT_000172e8)[param_1] + 0x200);
  uVar1 = uVar2 | 0x20000;
  if (param_2 == '\0') {
    uVar1 = uVar2 & 0xfffdffff;
  }
  *(uint *)((&DAT_000172e8)[param_1] + 0x200) = uVar1;
  return;
}



int FUN_00006614(ulonglong param_1)

{
  int iVar1;
  
  iVar1 = 0x32;
  do {
    if ((*(uint *)((&DAT_000172e8)[param_1 & 0xffffffff] + 0x208) >> 7 & 1) != 0) break;
    FUN_00010c0c(1);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return -(uint)(iVar1 == 0);
}



undefined4 FUN_00006668(ulonglong param_1,char param_2)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  int iVar4;
  
  iVar4 = 0x32;
  uVar3 = param_1 & 0xffffffff;
  uVar1 = *(uint *)((&DAT_000172e8)[param_1 & 0xffffffff] + 0x200);
  *(uint *)((&DAT_000172e8)[param_1 & 0xffffffff] + 0x200) =
       uVar1 & 0xfff00000 | uVar1 & 0xffff | 0x90000;
  do {
    lVar2 = (&DAT_000172e8)[uVar3];
    if ((*(uint *)(lVar2 + 0x200) >> 0x12 & 1) == 0) {
      iVar4 = 0x32;
      *(uint *)(lVar2 + 0x200) =
           *(uint *)(lVar2 + 0x200) & 0xff0fffff | (uint)(byte)(&DAT_00013244)[param_2] << 0x14;
      *(uint *)((&DAT_000172e8)[uVar3] + 0x200) =
           *(uint *)((&DAT_000172e8)[uVar3] + 0x200) | 0x40000;
      do {
        lVar2 = (&DAT_000172e8)[uVar3];
        if ((*(uint *)(lVar2 + 0x200) >> 0x12 & 1) != 0) {
          *(uint *)(lVar2 + 0x200) = *(uint *)(lVar2 + 0x200) & 0xfff5ffff | 0x20000;
          return 0;
        }
        FUN_00010c0c(1);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      return 0xffffffff;
    }
    FUN_00010c0c(1);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return 0xffffffff;
}



void FUN_00006750(uint param_1,byte *param_2)

{
  *(ushort *)((&DAT_000172e8)[param_1] + 0xe) =
       (ushort)param_2[1] << 6 | (ushort)*param_2 << 8 | (ushort)param_2[2] << 5 |
       (ushort)param_2[3] << 4 | (ushort)param_2[4] << 3 | (ushort)param_2[5];
  return;
}



void FUN_00006794(uint param_1,undefined2 param_2)

{
  *(undefined2 *)((&DAT_000172e8)[param_1] + 4) = param_2;
  return;
}



void FUN_000067a8(uint param_1,undefined2 param_2)

{
  *(undefined2 *)((&DAT_000172e8)[param_1] + 6) = param_2;
  return;
}



void FUN_000067bc(uint param_1,undefined4 param_2)

{
  *(undefined4 *)((&DAT_000172e8)[param_1] + 8) = param_2;
  return;
}



void FUN_000067d0(uint param_1,byte *param_2)

{
  *(ushort *)((&DAT_000172e8)[param_1] + 0xc) =
       ((ushort)param_2[1] << 4 | (ushort)*param_2 << 5 | (ushort)param_2[2] << 2 |
       (ushort)param_2[3] << 1) & 0xfe | (ushort)param_2[4];
  return;
}



void FUN_00006810(uint param_1,int *param_2,char param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)((&DAT_000172e8)[param_1] + 0x10);
  *param_2 = iVar1;
  if (param_3 == '\x01') {
    iVar2 = *(int *)((&DAT_000172e8)[param_1] + 0x14);
    param_2[1] = iVar2;
    iVar3 = *(int *)((&DAT_000172e8)[param_1] + 0x18);
    param_2[2] = iVar3;
    uVar4 = *(undefined4 *)((&DAT_000172e8)[param_1] + 0x1c);
    param_2[2] = (int)(CONCAT44(iVar2,iVar1) >> 0x18);
    param_2[3] = iVar1 << 8;
    *param_2 = (int)(CONCAT44(uVar4,iVar3) >> 0x18);
    param_2[1] = (int)(CONCAT44(iVar3,iVar2) >> 0x18);
  }
  return;
}



undefined4 FUN_00006870(ulonglong param_1)

{
  return *(undefined4 *)((&DAT_000172e8)[param_1 & 0xffffffff] + 0x20);
}



void FUN_00006884(uint param_1,undefined4 param_2)

{
  *(undefined4 *)((&DAT_000172e8)[param_1] + 0x20) = param_2;
  return;
}



undefined4 FUN_00006898(ulonglong param_1)

{
  return *(undefined4 *)((&DAT_000172e8)[param_1 & 0xffffffff] + 0x24);
}



void FUN_000068ac(uint param_1,int param_2)

{
  byte bVar1;
  
  bVar1 = *(byte *)((&DAT_000172e8)[param_1] + 0x28);
  if (param_2 == 2) {
    bVar1 = bVar1 | 0x20;
  }
  else if (param_2 == 1) {
    bVar1 = bVar1 & 0xdd | 2;
  }
  else {
    if (param_2 != 0) {
      return;
    }
    bVar1 = bVar1 & 0xdd;
  }
  *(byte *)((&DAT_000172e8)[param_1] + 0x28) = bVar1;
  return;
}



void FUN_000068f8(uint param_1,char param_2)

{
  byte bVar1;
  
  bVar1 = 0x18;
  if (param_2 == '\0') {
    bVar1 = 0;
  }
  *(byte *)((&DAT_000172e8)[param_1] + 0x28) =
       bVar1 | *(byte *)((&DAT_000172e8)[param_1] + 0x28) & 0xe7;
  return;
}



void FUN_00006928(uint param_1,byte param_2)

{
  *(byte *)((&DAT_000172e8)[param_1] + 0x29) =
       *(byte *)((&DAT_000172e8)[param_1] + 0x29) & 0xf1 | param_2;
  return;
}



void FUN_0000694c(uint param_1,byte param_2)

{
  *(byte *)((&DAT_000172e8)[param_1] + 0x29) =
       *(byte *)((&DAT_000172e8)[param_1] + 0x29) & 0xfe | param_2;
  return;
}



byte FUN_0000696c(ulonglong param_1)

{
  return *(byte *)((&DAT_000172e8)[param_1 & 0xffffffff] + 0x29) & 0xf;
}



void FUN_00006984(uint param_1,uint param_2)

{
  *(ushort *)((&DAT_000172e8)[param_1] + 0x2c) =
       (ushort)(param_2 >> 2) & 0xc0 | (ushort)(param_2 << 8) | 1;
  return;
}



void FUN_000069a8(uint param_1,char param_2)

{
  *(byte *)((&DAT_000172e8)[param_1] + 0x2c) =
       *(byte *)((&DAT_000172e8)[param_1] + 0x2c) & 0xfb | param_2 << 2;
  return;
}



byte FUN_000069cc(ulonglong param_1)

{
  return *(byte *)((&DAT_000172e8)[param_1 & 0xffffffff] + 0x2c) >> 1 & 1;
}



void FUN_000069e4(uint param_1,undefined1 param_2)

{
  *(undefined1 *)((&DAT_000172e8)[param_1] + 0x2e) = param_2;
  return;
}



undefined4 FUN_000069f8(ulonglong param_1)

{
  return *(undefined4 *)((&DAT_000172e8)[param_1 & 0xffffffff] + 0x30);
}



void FUN_00006a0c(ulonglong param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = 10000;
  do {
    *(uint *)((&DAT_000172e8)[param_1 & 0xffffffff] + 0x30) = param_2 & 0x7ff003f;
    if ((*(uint *)((&DAT_000172e8)[param_1 & 0xffffffff] + 0x30) & param_2 & 0x7ff003f) == 0) {
      return;
    }
    FUN_00010c0c(1);
    bVar1 = iVar2 != 0;
    iVar2 = iVar2 + -1;
  } while (bVar1);
  return;
}



void FUN_00006a74(ulonglong param_1,uint param_2,char param_3)

{
  uint uVar1;
  longlong lVar2;
  ulonglong uVar3;
  int iVar4;
  
  lVar2 = (&DAT_000172e8)[param_1 & 0xffffffff];
  uVar1 = *(uint *)(lVar2 + 0x34) & (param_2 ^ 0xffffffff);
  if (param_3 == '\0') {
    *(uint *)(lVar2 + 0x34) = uVar1;
  }
  else {
    uVar3 = param_1 & 0xffffffff;
    *(uint *)(lVar2 + 0x34) = uVar1 | param_2;
    if ((param_2 & (*(uint *)((&DAT_000172e8)[uVar3] + 0x34) ^ 0xffffffff)) != 0) {
      iVar4 = 10000;
      do {
        FUN_00010c0c(1);
        if (iVar4 == 0) {
          return;
        }
        iVar4 = iVar4 + -1;
        *(uint *)((&DAT_000172e8)[uVar3] + 0x34) = param_2;
      } while ((param_2 & (*(uint *)((&DAT_000172e8)[uVar3] + 0x34) ^ 0xffffffff)) != 0);
    }
  }
  return;
}



void FUN_00006b04(uint param_1,uint param_2,char param_3)

{
  uint uVar1;
  
  uVar1 = param_2;
  if (param_3 == '\0') {
    uVar1 = 0;
  }
  *(uint *)((&DAT_000172e8)[param_1] + 0x38) =
       *(uint *)((&DAT_000172e8)[param_1] + 0x38) & (param_2 ^ 0xffffffff) | uVar1;
  return;
}



void FUN_00006b2c(uint param_1,ushort param_2)

{
  *(ushort *)((&DAT_000172e8)[param_1] + 0x3e) =
       *(ushort *)((&DAT_000172e8)[param_1] + 0x3e) & 0xfff8 | param_2;
  return;
}



void FUN_00006b4c(uint param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)((&DAT_000172e8)[param_1] + 0x40);
  param_2[1] = *(undefined4 *)((&DAT_000172e8)[param_1] + 0x44);
  return;
}



void FUN_00006b70(uint param_1,undefined4 param_2)

{
  *(undefined4 *)((&DAT_000172e8)[param_1] + 0x58) = param_2;
  return;
}



void FUN_00006b84(uint param_1,undefined4 param_2)

{
  *(undefined4 *)((&DAT_000172e8)[param_1] + 0x5c) = param_2;
  return;
}



void FUN_00006b98(uint param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)((&DAT_000172e8)[param_1] + 0x200);
  *(uint *)((&DAT_000172e8)[param_1] + 0x200) = uVar1 | 0x20000000;
  *(uint *)((&DAT_000172e8)[param_1] + 0x200) = uVar1 | 0x60000000;
  return;
}



void FUN_00006bc0(uint param_1)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  
  lVar3 = (&DAT_000172e8)[param_1];
  uVar1 = *(uint *)(lVar3 + 0x40) | 0x280000;
  uVar2 = *(uint *)(lVar3 + 0x44) | 7;
  if (1 < param_1) {
    uVar1 = *(uint *)(lVar3 + 0x40);
    uVar2 = *(uint *)(lVar3 + 0x44);
  }
  if (param_1 == 0) {
    uVar4 = uVar1 & 0x28fb00ff | 0x5404c800;
  }
  else {
    uVar4 = uVar1 & 0x39ffffff | 0x6000000;
    if (param_1 != 1) {
      uVar4 = uVar1;
    }
  }
  *(uint *)(lVar3 + 0x21c) = uVar4;
  *(uint *)((&DAT_000172e8)[param_1] + 0x220) =
       *(uint *)((&DAT_000172e8)[param_1] + 0x220) & 0xff000000 | uVar2 & 0xffffff;
  return;
}



void FUN_00006c64(uint param_1)

{
  *(uint *)((&DAT_000172e8)[param_1] + 0x200) = *(uint *)((&DAT_000172e8)[param_1] + 0x200) | 1;
  return;
}



void FUN_00006c80(uint param_1)

{
  *(uint *)((&DAT_000172e8)[param_1] + 0x224) = *(uint *)((&DAT_000172e8)[param_1] + 0x224) | 2;
  return;
}



void FUN_00006c9c(uint param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)((&DAT_000172e8)[param_1] + 0x20c) & 0xffc7ffff | param_2 << 0x13;
  *(uint *)((&DAT_000172e8)[param_1] + 0x20c) = uVar1;
  *(uint *)((&DAT_000172e8)[param_1] + 0x20c) = uVar1 | 0x40000;
  return;
}



void FUN_00006cc8(uint param_1)

{
  *(uint *)((&DAT_000172e8)[param_1] + 0x20c) =
       *(uint *)((&DAT_000172e8)[param_1] + 0x20c) & 0xfffbffff;
  return;
}



void FUN_00006ce4(uint param_1,int param_2)

{
  *(uint *)((&DAT_000172e8)[param_1] + 0x20c) =
       *(uint *)((&DAT_000172e8)[param_1] + 0x20c) & 0xfffffcff | param_2 << 8;
  return;
}



void FUN_00006d04(uint param_1,uint param_2)

{
  *(uint *)((&DAT_000172e8)[param_1] + 0x25c) =
       *(uint *)((&DAT_000172e8)[param_1] + 0x25c) & 0xfffffe00 | param_2 & 0xff;
  return;
}



void FUN_00006d24(uint param_1,uint param_2)

{
  *(uint *)((&DAT_000172e8)[param_1] + 0x254) =
       *(uint *)((&DAT_000172e8)[param_1] + 0x254) & 0xfffffffe | param_2 & 0xff;
  return;
}



uint FUN_00006d48(ulonglong param_1)

{
  return *(uint *)((&DAT_000172e8)[param_1 & 0xffffffff] + 0x208) >> 0xb & 1;
}



void FUN_00006d60(uint param_1,uint param_2)

{
  *(uint *)((&DAT_000172e8)[param_1] + 0x250) =
       *(uint *)((&DAT_000172e8)[param_1] + 0x250) & 0xfffffff7 | (param_2 & 0xff) << 3;
  return;
}



void FUN_00006d84(uint param_1)

{
  *(uint *)((&DAT_000172e8)[param_1] + 0x250) =
       *(uint *)((&DAT_000172e8)[param_1] + 0x250) & 0xfffffbff;
  return;
}



void FUN_00006da0(uint param_1,char param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)((&DAT_000172e8)[param_1] + 0x254);
  uVar1 = uVar2 & 0xffdfffff;
  if (param_2 == '\0') {
    uVar1 = uVar2 | 0x200000;
  }
  *(uint *)((&DAT_000172e8)[param_1] + 0x254) = uVar1;
  return;
}



void FUN_00006dc8(void)

{
  ulonglong local_30;
  ulonglong uStack_28;
  
  local_30 = 0;
  uStack_28 = 0;
  if ((DAT_000172e0 & 1) == 0) {
    FUN_00003e48((undefined4 *)&local_30);
    DAT_000172e8 = local_30 & 0xffffffff;
    DAT_000172f0 = local_30 >> 0x20;
    DAT_000172f8 = uStack_28 & 0xffffffff;
    DAT_00017300 = uStack_28 >> 0x20;
    DAT_000172e0 = 1;
  }
  return;
}



longlong FUN_00006e44(uint *param_1,undefined8 *param_2)

{
  longlong lVar1;
  uint uVar2;
  longlong lVar3;
  ulonglong uVar4;
  longlong local_58;
  
  lVar3 = (**(code **)(DAT_00017260 + 0x140))(&DAT_00016208,0,&local_58);
  if (lVar3 == 0) {
    uVar2 = *(uint *)(local_58 + 0xc);
    lVar3 = -(ulonglong)(uVar2 < 0x20000);
    if (uVar2 >> 0x12 != 0) {
      lVar3 = 1;
    }
    lVar1 = 2;
    if (uVar2 >> 0x13 == 0) {
      lVar1 = lVar3;
    }
    lVar3 = 3;
    if (uVar2 >> 0x14 == 0) {
      lVar3 = lVar1;
    }
    do {
      if (lVar3 < 0) {
        return -0x7ffffffffffffffd;
      }
      uVar4 = FUN_00010c50(DAT_00017320,DAT_00017328,(undefined8 *)0x0);
      if ((longlong)uVar4 < 0) {
        FUN_00004548(0x80000000,(byte *)"ConfigRpmbStorPartitions: OpenParser failed\n");
        return -0x7fffffffffffffff;
      }
      FUN_0001118c(uVar4,*(byte **)(&UNK_000135b0 + lVar3 * 8),&LAB_00006fc4);
      FUN_0001121c(uVar4);
      lVar3 = lVar3 + -1;
    } while (DAT_00017310 != '\x01');
    DAT_00017310 = '\0';
    if (DAT_00017314 == 3) {
      FUN_000047cc(param_2,(undefined8 *)&DAT_00017348,(ulonglong)DAT_00017308 * 0x28);
      lVar3 = 0;
      *param_1 = (uint)DAT_00017308;
    }
    else {
      lVar3 = -0x7ffffffffffffffe;
    }
  }
  else {
    FUN_00004548(0x80000000,(byte *)"ConfigRpmbStorPartitions: Failed to find RPMB Protocol\n");
  }
  return lVar3;
}



undefined8 FUN_0000722c(undefined8 *param_1,uint *param_2,undefined8 *param_3,longlong param_4)

{
  ulonglong uVar1;
  undefined8 uVar2;
  
  uVar2 = 0x8000000000000002;
  if ((((param_1 != (undefined8 *)0x0) && (param_2 != (uint *)0x0)) &&
      (param_3 != (undefined8 *)0x0)) && (param_4 != 0)) {
    uVar1 = FUN_00010c50(DAT_00017320,DAT_00017328,(undefined8 *)0x0);
    if ((longlong)uVar1 < 0) {
      FUN_00004548(0x80000000,(byte *)"ConfigGptStorPartitions: OpenParser failed\n");
      uVar2 = 0x8000000000000001;
    }
    else {
      FUN_000047cc((undefined8 *)&DAT_00017338,param_1,0x10);
      DAT_00017330 = param_4;
      FUN_0001118c(uVar1,&DAT_00013362,&LAB_00006fc4);
      if (DAT_00017310 == '\x01') {
        DAT_00017310 = '\0';
        if (DAT_00017314 != 3 && DAT_00017314 < 0x10) {
          FUN_000047cc(param_3,(undefined8 *)&DAT_00017348,(ulonglong)DAT_00017308 * 0x28);
          uVar2 = 0;
          *param_2 = (uint)DAT_00017308;
        }
      }
      else {
        uVar2 = 0x8000000000000003;
      }
      FUN_0001121c(uVar1);
    }
  }
  return uVar2;
}



longlong FUN_00007344(int param_1,undefined8 *param_2,int param_3,uint *param_4,undefined8 *param_5,
                     longlong param_6)

{
  ulonglong uVar1;
  longlong lVar2;
  
  lVar2 = -0x7ffffffffffffffe;
  if ((param_4 != (uint *)0x0) && (param_5 != (undefined8 *)0x0)) {
    uVar1 = FUN_00010c50(DAT_00017320,DAT_00017328,(undefined8 *)0x0);
    if ((longlong)uVar1 < 0) {
      FUN_00004548(0x80000000,(byte *)"ConfigStorPartitions: OpenParser failed\n");
      lVar2 = -0x7fffffffffffffff;
    }
    else {
      FUN_0001118c(uVar1,(byte *)"VersionNum",&LAB_00006fc4);
      if (DAT_00017310 == '\x01') {
        DAT_00017310 = '\0';
        if (DAT_00017318 == param_3) {
          FUN_00004788((longlong *)&DAT_00017348,600,0);
          DAT_00017311 = 0;
          DAT_00017308 = 0;
          if (param_1 == 3) {
            lVar2 = FUN_00006e44(param_4,param_5);
          }
          else {
            lVar2 = FUN_0000722c(param_2,param_4,param_5,param_6);
          }
        }
        else {
          FUN_00004548(0x80000000,(byte *)"ConfigStorPartitions: Config file version mismatch\n");
        }
      }
      else {
        lVar2 = -0x7ffffffffffffffd;
      }
      FUN_0001121c(uVar1);
    }
  }
  return lVar2;
}



longlong FUN_00007488(void)

{
  longlong lVar1;
  
  lVar1 = FUN_0001034c((ushort *)L"SecParti.cfg",&DAT_00017320,(undefined8 *)&DAT_00017328);
  if (lVar1 != 0) {
    FUN_00004548(0x80000000,(byte *)"Failed to load partiapp.cfg!Status = (0x%x)\r\n");
  }
  return lVar1;
}



longlong * FUN_000074dc(short param_1,undefined4 param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  longlong *plVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  char *pcVar9;
  
  uVar4 = (uint)param_1;
  if ((int)uVar4 < 4) {
    uVar2 = FUN_00009a04(uVar4);
    if ((uVar2 & 0xff) != 0) {
      lVar5 = FUN_0000b620(uVar4);
      if (lVar5 == 0) {
        FUN_00004548(0x80000000,(byte *)"sdcc_handle_open: can\'t get slot handle\n");
        return (longlong *)0x0;
      }
      puVar1 = (uint *)(lVar5 + 8);
      plVar6 = FUN_00009838(param_1,param_2);
      if (plVar6 == (longlong *)0x0) {
        uVar8 = FUN_000099bc((longlong)puVar1);
        if ((uVar8 & 0xff) != 0) {
          return (longlong *)0x0;
        }
        FUN_0000b958((longlong)puVar1);
        return (longlong *)0x0;
      }
      if ((*(uint *)(lVar5 + 0x14) < 7) &&
         ((1 << (ulonglong)(*(uint *)(lVar5 + 0x14) & 0x1f) & 0x66U) != 0)) {
        return plVar6;
      }
      uVar7 = FUN_0000b0e8(plVar6);
      iVar3 = (int)uVar7;
      *(int *)(lVar5 + 0x14) = iVar3;
      *(int *)(lVar5 + 0x28) = iVar3;
      if (iVar3 != 0) {
        uVar4 = FUN_0000b204(puVar1);
        if (uVar4 == 0) {
          uVar4 = FUN_0000b9c4(puVar1);
          if (uVar4 == 0) {
            FUN_0000b668(puVar1,1);
            uVar8 = FUN_0000b2a8(puVar1);
            if ((int)uVar8 == 0) {
              *(undefined1 *)(lVar5 + 0xd8) = 0;
              *(undefined4 *)(lVar5 + 0x18) = 2;
              return plVar6;
            }
            *(int *)(lVar5 + 0x20) = (int)uVar8;
            *(undefined4 *)(lVar5 + 0x14) = 0;
            goto LAB_00007610;
          }
          pcVar9 = "Failed to get memory card info.\n";
        }
        else {
          pcVar9 = "Failed to initialize the card.\n";
        }
        FUN_00004548(0x80000000,(byte *)pcVar9);
        *(uint *)(lVar5 + 0x20) = uVar4;
      }
LAB_00007610:
      FUN_00007650(plVar6);
      return (longlong *)0x0;
    }
    pcVar9 = "Failed to initialize drive number %d";
  }
  else {
    pcVar9 = "Invalid Drive Number: %d";
  }
  FUN_00004548(0x80000000,(byte *)pcVar9);
  return (longlong *)0x0;
}



undefined8 FUN_00007650(longlong *param_1)

{
  ulonglong uVar1;
  undefined8 uVar2;
  longlong lVar3;
  longlong *local_18;
  
  local_18 = param_1;
  if ((param_1 == (longlong *)0x0) || (lVar3 = *param_1, lVar3 == 0)) {
    FUN_00004548(0x80000000,(byte *)"Invalid SDCC handle");
    uVar2 = 0x14;
  }
  else {
    FUN_000098e4(&local_18);
    uVar1 = FUN_000099bc(lVar3);
    if ((uVar1 & 0xff) == 0) {
      uVar2 = FUN_0000b958(lVar3);
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}



ulonglong FUN_000076b8(longlong *param_1,uint *param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint local_38;
  uint local_34;
  
  local_38 = 0;
  local_34 = 0;
  if ((param_1 == (longlong *)0x0) || (puVar8 = (uint *)*param_1, puVar8 == (uint *)0x0)) {
    pcVar5 = "Invalid SDCC handle";
  }
  else {
    uVar7 = *puVar8;
    if (3 < uVar7) {
      FUN_00004548(0x80000000,(byte *)"Invalid drive number %d");
      return 0x14;
    }
    if (param_2 != (uint *)0x0) {
      FUN_00004788((longlong *)param_2,0x4c,0);
      if (puVar8[3] != 0) {
        lVar1 = param_1[1];
        *param_2 = puVar8[3];
        param_2[3] = puVar8[0xb];
        uVar2 = FUN_00003e68(uVar7);
        *(byte *)(param_2 + 6) = (byte)uVar2 & 1;
        if ((puVar8[3] | 4) == 6) {
          uVar3 = FUN_000091c8(param_1,(int *)&local_34,&local_38);
          uVar3 = uVar3 & 0xffffffff;
          param_2[1] = local_34;
          param_2[4] = (uint)(byte)puVar8[0x1f];
          param_2[5] = puVar8[0xd];
          uVar4 = FUN_00009754(param_1);
          *(char *)(param_2 + 9) = (char)uVar4;
          param_2[0x10] = puVar8[0x18];
          *(char *)((longlong)param_2 + 0x45) = (char)puVar8[0x1d];
          param_2[2] = puVar8[10];
          *(char *)(param_2 + 0x11) = (char)puVar8[0x19];
          param_2[0x12] = puVar8[0x1a];
          uVar6 = local_38;
        }
        else {
          if ((int)lVar1 + 1U < 2) {
            uVar7 = puVar8[9];
            uVar3 = 0;
          }
          else {
            uVar7 = 0;
            uVar3 = 0x16;
          }
          param_2[1] = uVar7;
          uVar6 = 0;
          uVar7 = puVar8[0x1f];
          *(undefined1 *)(param_2 + 9) = 0;
          param_2[4] = (uint)(byte)uVar7;
          param_2[5] = 0;
        }
        param_2[8] = uVar6;
        param_2[7] = puVar8[0xf];
        *(undefined2 *)((longlong)param_2 + 0x26) = *(undefined2 *)((longlong)puVar8 + 0x46);
        *(short *)(param_2 + 10) = (short)puVar8[0x12];
        FUN_000047cc((undefined8 *)((longlong)param_2 + 0x2a),
                     (undefined8 *)((longlong)puVar8 + 0x4a),7);
        *(undefined1 *)((longlong)param_2 + 0x31) = *(undefined1 *)((longlong)puVar8 + 0x51);
        param_2[0xd] = puVar8[0x15];
        FUN_000047cc((undefined8 *)(param_2 + 0xe),(undefined8 *)(puVar8 + 0x16),8);
        return uVar3;
      }
      return 0x15;
    }
    pcVar5 = "Passed in NULL sdcc_pmem_info pointer";
  }
  FUN_00004548(0x80000000,(byte *)pcVar5);
  return 0x14;
}



undefined8 FUN_00007884(undefined8 *param_1)

{
  uint uVar1;
  uint *puVar2;
  
  if ((param_1 == (undefined8 *)0x0) || (puVar2 = (uint *)*param_1, puVar2 == (uint *)0x0)) {
    FUN_00004548(0x80000000,(byte *)"Invalid SDCC handle 0x%x");
  }
  else if (*puVar2 < 4) {
    if ((*(char *)(*(longlong *)(puVar2 + 0x30) + 0xd8) == '\0') && (puVar2[3] != 0)) {
      uVar1 = FUN_0000b87c(puVar2);
      if (uVar1 == 9) {
        puVar2[3] = 0;
        return 0;
      }
      return 1;
    }
  }
  else {
    FUN_00004548(0x80000000,(byte *)"Invalid drive number %d");
  }
  return 0;
}



uint FUN_0000791c(longlong *param_1,int param_2,undefined4 *param_3,uint param_4)

{
  uint uVar1;
  uint *puVar2;
  undefined4 local_58;
  int local_54;
  undefined4 local_50;
  undefined4 local_3c;
  undefined4 local_34;
  
  if ((param_1 == (longlong *)0x0) || (puVar2 = (uint *)*param_1, puVar2 == (uint *)0x0)) {
    FUN_00004548(0x80000000,(byte *)"Invalid SDCC handle 0x%x");
  }
  else if (*puVar2 < 4) {
    if (*(char *)(*(longlong *)(puVar2 + 0x30) + 0xd8) != '\0') {
      FUN_00004548(0x80000000,(byte *)"Slot %d state changed");
      return 0x1b;
    }
    if ((int)param_1[1] != 3) {
      uVar1 = puVar2[3];
      if (uVar1 < 7) {
        if ((1 << (ulonglong)(uVar1 & 0x1f) & 0x66U) != 0) {
          uVar1 = FUN_0000b440(param_1);
          if (uVar1 != 0) {
            return uVar1;
          }
          local_3c = 0;
          local_34 = 2;
          local_58 = 0x11;
          if ((param_4 & 0xffff) != 1) {
            local_58 = 0x12;
          }
          local_50 = 1;
          if (1 < puVar2[3] - 5) {
            param_2 = puVar2[0xb] * param_2;
          }
          local_54 = param_2;
          uVar1 = thunk_FUN_00009d84(puVar2,(longlong)&local_58,param_3,param_4);
          return uVar1;
        }
        if (uVar1 == 0) {
          return 0x15;
        }
      }
      FUN_00004548(0x80000000,(byte *)"Operation not supported on SDIO card");
      return 0x10;
    }
  }
  else {
    FUN_00004548(0x80000000,(byte *)"Invalid drive number %d");
  }
  return 0x14;
}



uint FUN_00007a74(longlong *param_1,int param_2,undefined4 *param_3,uint param_4)

{
  uint uVar1;
  uint *puVar2;
  undefined4 local_58;
  int local_54;
  undefined4 local_50;
  undefined4 local_3c;
  undefined4 local_34;
  
  if ((param_1 == (longlong *)0x0) || (puVar2 = (uint *)*param_1, puVar2 == (uint *)0x0)) {
    FUN_00004548(0x80000000,(byte *)"Invalid SDCC handle 0x%x");
  }
  else {
    if (*puVar2 < 4) {
      if (*(char *)(*(longlong *)(puVar2 + 0x30) + 0xd8) != '\0') {
        FUN_00004548(0x80000000,(byte *)"Slot %d state changed");
        return 0x1b;
      }
      uVar1 = puVar2[3];
      if (uVar1 < 7) {
        if ((1 << (ulonglong)(uVar1 & 0x1f) & 0x66U) != 0) {
          uVar1 = FUN_0000b440(param_1);
          if (uVar1 != 0) {
            return uVar1;
          }
          local_3c = 0;
          local_34 = 1;
          local_58 = 0x18;
          if ((param_4 & 0xffff) != 1) {
            local_58 = 0x19;
          }
          local_50 = 1;
          if (1 < puVar2[3] - 5) {
            param_2 = puVar2[0xb] * param_2;
          }
          local_54 = param_2;
          uVar1 = thunk_FUN_00009d84(puVar2,(longlong)&local_58,param_3,param_4);
          return uVar1;
        }
        if (uVar1 == 0) {
          return 0x15;
        }
      }
      FUN_00004548(0x80000000,(byte *)"Operation not supported on SDIO card");
      return 0x10;
    }
    FUN_00004548(0x80000000,(byte *)"Invalid drive number %d");
  }
  return 0x14;
}



ulonglong FUN_00007bbc(longlong *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  uint *puVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined4 uVar7;
  uint local_68;
  uint local_64;
  undefined4 uStack_60;
  uint local_5c;
  undefined4 local_4c;
  undefined4 local_44;
  
  if ((param_1 == (longlong *)0x0) || (puVar4 = (uint *)*param_1, puVar4 == (uint *)0x0)) {
    FUN_00004548(0x80000000,(byte *)"Invalid SDCC handle 0x%x");
    return 0x14;
  }
  if (3 < *puVar4) {
    FUN_00004548(0x80000000,(byte *)"Invalid drive number %d");
    return 0x14;
  }
  if ((puVar4[3] | 4) != 6) {
    FUN_00004548(0x80000000,(byte *)"Erase not supported for the inserted card");
    return 0x16;
  }
  uVar2 = puVar4[0x1a];
  uVar5 = 5000000;
  uVar1 = 0;
  if (uVar2 != 0) {
    uVar1 = param_2 / uVar2;
  }
  if (param_2 == uVar1 * uVar2) {
    uVar1 = 0;
    if (uVar2 != 0) {
      uVar1 = param_3 / uVar2;
    }
    if (param_3 == uVar1 * uVar2) {
      if (puVar4[0x2b] != 0) {
        uVar5 = puVar4[0x2b] * uVar1 * 1000;
      }
      uVar7 = 0;
      goto LAB_00007c58;
    }
  }
  uVar1 = 0;
  if (uVar2 != 0) {
    uVar1 = param_3 / uVar2;
  }
  uVar7 = 1;
  if (param_3 != uVar1 * uVar2) {
    uVar1 = uVar1 + 1;
  }
  if (puVar4[0x2c] != 0) {
    uVar5 = puVar4[0x2c] * uVar1 * 1000;
  }
LAB_00007c58:
  uVar2 = FUN_0000b440(param_1);
  uVar6 = (ulonglong)uVar2;
  if (uVar2 == 0) {
    local_4c = 0;
    local_44 = 0;
    uStack_60 = 1;
    local_68 = 0x23;
    local_64 = param_2;
    uVar2 = FUN_0000b868(puVar4,&local_68);
    uVar6 = (ulonglong)uVar2;
    if (uVar2 == 0) {
      local_4c = 0;
      local_44 = 0;
      local_64 = param_2 + param_3 + -1;
      if (puVar4[3] != 6) {
        local_64 = param_2 + param_3 * 0x200 + -0x200;
      }
      local_68 = 0x24;
      uVar2 = FUN_0000b868(puVar4,&local_68);
      uVar6 = (ulonglong)uVar2;
      if (uVar2 == 0) {
        local_44 = 0;
        local_4c = 1;
        local_68 = 0x26;
        local_64 = uVar7;
        uVar2 = FUN_0000b868(puVar4,&local_68);
        uVar6 = (ulonglong)uVar2;
        if ((local_5c & 0xfdff8000) == 0) {
          if (uVar2 == 7) {
            uVar3 = FUN_0000b8d0(puVar4,uVar5);
            uVar6 = uVar3 & 0xffffffff;
            if ((int)uVar3 != 0) {
              FUN_00004548(0x80000000,(byte *)"sdcc_erase failed\n");
            }
          }
        }
        else {
          uVar6 = 0xf;
        }
      }
    }
  }
  return uVar6;
}



uint FUN_00007dc4(undefined8 *param_1)

{
  uint uVar1;
  uint *puVar2;
  
  if ((param_1 == (undefined8 *)0x0) || (puVar2 = (uint *)*param_1, puVar2 == (uint *)0x0)) {
    FUN_00004548(0x80000000,(byte *)"Invalid SDCC handle 0x%x");
    uVar1 = 0x14;
  }
  else if (*puVar2 < 4) {
    if (puVar2[3] == 6) {
      uVar1 = FUN_000080d0(puVar2,0x3a20100);
      if (uVar1 != 0) {
        FUN_00004548(0x80000000,(byte *)"Failed in changing bus width %d");
      }
    }
    else {
      FUN_00004548(0x80000000,(byte *)"Function not supported by inserted card");
      uVar1 = 0x16;
    }
  }
  else {
    FUN_00004548(0x80000000,(byte *)"Invalid drive number %d");
    uVar1 = 0x14;
  }
  return uVar1;
}



uint FUN_00007e7c(longlong *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  
  if ((param_1 == (longlong *)0x0) || (lVar3 = *param_1, lVar3 == 0)) {
    FUN_00004548(0x80000000,(byte *)"Invalid SDCC handle");
  }
  else if (**(uint **)(lVar3 + 0xc0) < 4) {
    if ((7 < *(uint *)(param_1 + 1)) ||
       ((1 << (ulonglong)(*(uint *)(param_1 + 1) & 0x1f) & 0xf1U) == 0)) {
LAB_00007edc:
      if (((*(uint *)(lVar3 + 0xc) | 4) == 6) && (*(char *)(lVar3 + 0x74) == '\x01')) {
        uVar2 = FUN_00009314(param_1,param_2,param_3);
        return uVar2;
      }
      FUN_00004548(0x80000000,(byte *)"Write protect feature not supported in driveno %d");
      return 0x16;
    }
    uVar2 = *(uint *)(lVar3 + 0x28);
    uVar1 = 0;
    if (uVar2 != 0) {
      uVar1 = param_3 / uVar2;
    }
    if (param_3 == uVar1 * uVar2) {
      uVar1 = 0;
      if (uVar2 != 0) {
        uVar1 = param_2 / uVar2;
      }
      if (param_2 == uVar1 * uVar2) goto LAB_00007edc;
    }
  }
  else {
    FUN_00004548(0x80000000,(byte *)"Invalid drive number %d");
  }
  return 0x14;
}



uint FUN_00007f50(longlong *param_1,int param_2,longlong *param_3)

{
  uint uVar1;
  longlong lVar2;
  
  if (param_1 != (longlong *)0x0) {
    if (param_3 == (longlong *)0x0) {
      return 0x14;
    }
    lVar2 = *param_1;
    if (lVar2 == 0) {
      return 0x14;
    }
    if (**(uint **)(lVar2 + 0xc0) < 4) {
      if (((*(uint *)(lVar2 + 0xc) | 4) == 6) && (*(char *)(lVar2 + 0x74) == '\x01')) {
        uVar1 = FUN_000095dc(param_1,param_2,param_3);
        return uVar1;
      }
      FUN_00004548(0x80000000,(byte *)"Write protect not supported in driveno %d");
      return 0x16;
    }
    FUN_00004548(0x80000000,(byte *)"Invalid drive number %d");
  }
  return 0x14;
}



undefined8 FUN_00007fe0(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    if (uVar3 == 2) {
      return 0;
    }
    if (uVar3 == 0) {
      bVar1 = FUN_000042e8();
      if (bVar1) {
LAB_00008030:
        FUN_00003ea8((ulonglong)uVar3);
        FUN_0000fa64(uVar3);
        FUN_0000f5f0(uVar3);
        FUN_00006dc8();
        iVar2 = FUN_00003ef4(uVar3);
        if (iVar2 != 0) {
          FUN_0000f8bc(uVar3,iVar2);
          FUN_00009c40(uVar3,0);
        }
        FUN_0000f978(uVar3);
        FUN_0000694c(uVar3,1);
        FUN_000063f8((ulonglong)uVar3,1);
        FUN_00006bc0(uVar3);
        if (uVar3 == 0) {
          FUN_00006cc8(0);
        }
      }
    }
    else if (uVar3 == 1) goto LAB_00008030;
    uVar3 = uVar3 + 1;
  } while( true );
}



uint FUN_000080d0(uint *param_1,int param_2)

{
  uint uVar1;
  uint local_80;
  int iStack_7c;
  undefined4 local_78;
  undefined4 local_64;
  undefined4 local_5c;
  uint local_58;
  int iStack_54;
  undefined4 local_50;
  uint local_4c;
  undefined4 local_3c;
  undefined4 local_34;
  
  local_5c = 0;
  local_80 = 6;
  local_78 = 1;
  local_64 = 1;
  iStack_7c = param_2;
  uVar1 = FUN_0000b868(param_1,&local_80);
  if (uVar1 == 0) {
    if (param_2 == 0x3af0100) {
      FUN_00003f30(1000);
    }
    local_3c = 0;
    local_34 = 0;
    iStack_54 = (uint)(ushort)param_1[5] << 0x10;
    local_50 = 1;
    local_58 = 0xd;
    uVar1 = FUN_0000b868(param_1,&local_58);
    if (uVar1 == 0) {
      if ((local_4c & 0x1e00) == 0x800) {
        if ((local_4c >> 7 & 1) == 0) {
          return 0;
        }
        FUN_00004548(0x80000000,(byte *)"Switch error occurs");
        uVar1 = 0x13;
      }
      else {
        FUN_00004548(0x80000000,(byte *)"eMMC is not ready");
        uVar1 = 8;
      }
    }
    else {
      FUN_00004548(0x80000000,(byte *)"Failed to get card status");
    }
    FUN_00004548(0x80000000,(byte *)"Failed %d in switching to 0x%x");
  }
  return uVar1;
}



undefined8 FUN_000081ec(undefined8 *param_1)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint local_68 [7];
  undefined4 local_4c;
  undefined4 local_44;
  
  local_68[0] = 0;
  puVar2 = (uint *)*param_1;
  local_68[1] = 0;
  local_68[2] = 0;
  local_4c = 0;
  local_44 = 0;
  FUN_0000b868(puVar2,local_68);
  uVar3 = 0;
  while( true ) {
    if (499 < uVar3) {
      return 0;
    }
    local_68[0] = 1;
    local_68[1] = 0x40ff8000;
    local_68[2] = 1;
    local_4c = 0;
    local_44 = 0;
    uVar1 = FUN_0000b868(puVar2,local_68);
    if (uVar1 != 0) break;
    if ((int)local_68[3] < 0) {
      if ((local_68[3] & 0x60000000) != 0x40000000) {
        return 2;
      }
      return 6;
    }
    FUN_00003f30(2000);
    uVar3 = uVar3 + 1;
  }
  return 0;
}



uint FUN_000082b4(uint *param_1)

{
  uint uVar1;
  char cVar2;
  ulonglong *puVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  uint uVar8;
  uint uVar9;
  longlong lVar10;
  char cVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  byte bVar16;
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined4 local_84;
  byte local_7e;
  undefined4 local_7c;
  char local_78 [16];
  longlong local_68;
  
  local_68 = _data;
  local_78[0] = '\0';
  local_78[1] = '\0';
  local_78[2] = '\0';
  local_78[3] = '\0';
  local_78[4] = '\0';
  local_78[5] = '\0';
  local_78[6] = '\0';
  local_78[7] = '\0';
  local_78[8] = '\0';
  local_78[9] = '\0';
  local_78[10] = '\0';
  local_78[0xb] = '\0';
  local_78[0xc] = '\0';
  local_78[0xd] = '\0';
  local_78[0xe] = '\0';
  local_78[0xf] = '\0';
  if (param_1[0x33] - 7 < 2) {
    uVar9 = 1;
    if (*(char *)((longlong)param_1 + 0xc9) != '\0') {
      uVar8 = FUN_00003e68(*param_1);
      *(undefined1 *)((longlong)param_1 + 0xca) = 1;
      puVar3 = (ulonglong *)&UNK_00013e28;
      if ((uVar8 & 4) != 0) {
        puVar3 = (ulonglong *)&DAT_00013e68;
      }
      uVar9 = FUN_000085cc(param_1);
      if (uVar9 == 0) {
        bVar4 = 0;
        uVar8 = (uVar8 & 4) * 0x10 + 0x40;
        bVar7 = (char)param_1[0x32] == -1;
        if (!bVar7) {
          bVar16 = (byte)param_1[0x32];
          goto LAB_000083d4;
        }
LAB_000083c8:
        bVar16 = 0;
LAB_000083d4:
        do {
          FUN_00004788((longlong *)&DAT_000177b4,(ulonglong)uVar8,0);
          uVar9 = FUN_00008650(param_1,bVar16);
          if (uVar9 != 0) goto LAB_00008350;
          local_a0 = 0x15;
          uStack_9c = 0;
          local_98 = 1;
          local_84 = 0;
          local_7c = 2;
          param_1[0x1b] = 0;
          uVar9 = thunk_FUN_00009d84(param_1,(longlong)&local_a0,(undefined4 *)&DAT_000177b4,uVar8);
          param_1[0x1b] = 1;
          if (uVar9 == 0) {
            lVar10 = FUN_00010728((ulonglong *)&DAT_000177b4,puVar3,(ulonglong)uVar8);
            if (lVar10 == 0) {
              if (!bVar7) {
                *(undefined1 *)((longlong)param_1 + 0xca) = 0;
                goto LAB_0000859c;
              }
              bVar4 = bVar4 + 1;
              local_78[bVar16] = '\x01';
            }
            else {
              local_78[bVar16] = '\0';
              if (!bVar7) goto LAB_0000849c;
            }
          }
          else {
            if ((local_7e & 0x7f) == 0) goto LAB_00008350;
            FUN_00003f30(2000);
          }
          bVar16 = bVar16 + 1;
          if (0xf < bVar16) {
            if (bVar4 == 0) {
              FUN_00004548(0x80000000,(byte *)"No tuning point found\n");
              uVar9 = 1;
              goto LAB_00008350;
            }
            if (param_1 != (uint *)0x0) {
              uVar8 = 0;
              uVar15 = 0;
              uVar9 = 0;
              uVar13 = 0;
              iVar12 = 0;
              uVar14 = 0;
              goto LAB_00008538;
            }
            uVar9 = 0x14;
            goto LAB_00008350;
          }
        } while( true );
      }
      FUN_00004548(0x80000000,(byte *)"Error reset tuning block:error code %d\n");
LAB_00008350:
      *(undefined1 *)((longlong)param_1 + 0xca) = 0;
    }
  }
  else {
    uVar9 = 0x16;
  }
LAB_0000835c:
  if (_data == local_68) {
    return uVar9;
  }
                    // WARNING: Subroutine does not return
  FUN_000010d8();
LAB_0000849c:
  bVar7 = true;
  goto LAB_000083c8;
LAB_00008538:
  cVar11 = (char)iVar12;
  if (bVar4 <= uVar8) goto LAB_00008540;
  uVar5 = uVar13;
  iVar6 = iVar12;
  if (local_78[uVar9] == '\x01') {
    uVar1 = uVar15 + 1;
    if (uVar9 == 0xf) {
      if (uVar14 != 0) {
        if (uVar13 <= uVar14 + uVar1) {
          uVar13 = uVar14 + uVar1;
          cVar11 = '\x0f' - (char)uVar15;
        }
        goto LAB_00008540;
      }
      uVar8 = uVar1 + uVar8;
      uVar5 = uVar1;
      iVar6 = 0xf - uVar15;
      if (uVar1 <= uVar13) {
        uVar5 = uVar13;
        iVar6 = iVar12;
      }
    }
  }
  else {
    uVar1 = uVar15;
    if (uVar9 - uVar15 != 0) {
      uVar1 = uVar14;
    }
    uVar8 = uVar15 + uVar8;
    uVar14 = uVar1;
    uVar1 = 0;
    if (uVar13 < uVar15) {
      uVar5 = uVar15;
      iVar6 = uVar9 - uVar15;
    }
  }
  uVar15 = uVar1;
  iVar12 = iVar6;
  uVar13 = uVar5;
  uVar9 = uVar9 + 1;
  goto LAB_00008538;
LAB_00008540:
  uVar9 = uVar13 * 3 >> 2;
  cVar2 = '\0';
  if (uVar9 != 0) {
    cVar2 = (char)uVar9 + '\x0f';
  }
  bVar4 = cVar2 + cVar11 & 0xf;
  *(byte *)(param_1 + 0x32) = bVar4;
  uVar9 = FUN_00008650(param_1,bVar4);
  *(undefined1 *)((longlong)param_1 + 0xca) = 0;
  if (uVar9 == 0) {
LAB_0000859c:
    uVar9 = 0;
    *(undefined1 *)((longlong)param_1 + 0xcb) = 1;
  }
  goto LAB_0000835c;
}



int FUN_000085cc(uint *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *param_1;
  FUN_000063d0(uVar1,'\0');
  FUN_00006580(uVar1,'\x01');
  FUN_000097a8(param_1);
  FUN_00006580(uVar1,'\0');
  FUN_000065b4(uVar1);
  FUN_000065d0(uVar1);
  FUN_00006da0(uVar1,'\x01');
  iVar2 = FUN_00006614((ulonglong)uVar1);
  FUN_000063d0(uVar1,'\x01');
  return iVar2;
}



undefined4 FUN_00008650(uint *param_1,char param_2)

{
  undefined4 uVar1;
  
  if (((-1 < param_2) && (param_1 != (uint *)0x0)) && (param_2 < '\x10')) {
    uVar1 = FUN_00006668((ulonglong)*param_1,param_2);
    return uVar1;
  }
  return 0x14;
}



ulonglong FUN_00008674(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ulonglong uVar4;
  longlong lVar5;
  uint *puVar6;
  uint uVar7;
  int *piVar8;
  undefined8 uStack_a0;
  byte local_95;
  byte local_93;
  byte local_92;
  byte local_91;
  byte local_90;
  uint local_8c;
  byte local_7e;
  char local_7c;
  char local_76;
  byte local_74;
  byte local_58;
  char local_57;
  undefined1 local_4f;
  int local_4c [7];
  
  uVar2 = *param_1;
  FUN_00004788(&uStack_a0,0x70,0);
  uVar1 = FUN_00008c20(param_1,(undefined4 *)&DAT_000175a0);
  if (uVar1 != 0) {
    return (ulonglong)uVar1;
  }
  FUN_00008c8c(0x175a0,(undefined1 *)&uStack_a0);
  if ((param_1[3] == 6) && (local_8c == 0)) {
    return 1;
  }
  if (local_7c == '\x06') {
    *(undefined1 *)((longlong)param_1 + 0x72) = 1;
    *(byte *)((longlong)param_1 + 0x73) = uStack_a0._7_1_ >> 6 & 1;
  }
  if ((local_8c != 0) && (0x3fffff < param_1[9] - 1)) {
    param_1[9] = local_8c;
  }
  if (local_91 != 0) {
    param_1[0xd] = (uint)local_91;
  }
  uVar1 = local_74 >> 3 & 7;
  if ((7 < uVar1) || ((1 << (ulonglong)uVar1 & 0x87U) == 0)) {
    FUN_00004548(0x80000000,(byte *)"Invalid boot partition enable value 0x%x");
    return 0x14;
  }
  *(char *)(param_1 + 0x25) = (char)uVar1;
  uVar1 = FUN_00008eb8(param_1,'\0');
  if (uVar1 != 0) {
    return (ulonglong)uVar1;
  }
  uVar1 = FUN_00003f80(2);
  uVar1 = uVar1 & 0xff;
  if (uVar1 == 2) {
    if ((local_7e >> 6 & 1) != 0) {
      param_1[0x33] = 8;
      if (local_76 == '\0') {
        uVar2 = FUN_00008f3c(param_1);
        if (uVar2 != 0) {
          return (ulonglong)uVar2;
        }
        FUN_00006b98(*param_1);
        FUN_00009cd0(param_1,0);
        uVar2 = FUN_000080d0(param_1,0x3b90100);
        if (uVar2 != 0) {
          return (ulonglong)uVar2;
        }
        uVar2 = FUN_000080d0(param_1,0x3b70600);
        if (uVar2 != 0) {
          return (ulonglong)uVar2;
        }
        uVar2 = FUN_000080d0(param_1,0x3b90300);
        if (uVar2 != 0) {
          return (ulonglong)uVar2;
        }
        FUN_00006c9c(*param_1,6);
        param_1[0x1e] = 6;
        *(undefined1 *)((longlong)param_1 + 0xc9) = 1;
        FUN_0000b668(param_1,8);
        if (param_1[0x33] != 8) {
          return 0x14;
        }
        uVar2 = *param_1;
        iVar3 = FUN_000085cc(param_1);
        if (iVar3 != 0) {
          return 1;
        }
        iVar3 = FUN_00006668((ulonglong)uVar2,(char)param_1[0x32]);
        if (iVar3 != 0) {
          return 1;
        }
        FUN_00006c64(uVar2);
        FUN_00006d04(uVar2,0x73);
        FUN_00006d24(uVar2,1);
        iVar3 = 0x32;
        while (uVar1 = FUN_00006d48((ulonglong)uVar2), (uVar1 & 0xff) == 0) {
          iVar3 = iVar3 + -1;
          if (iVar3 == 0) {
            return 3;
          }
          FUN_00003f30(1000);
        }
      }
      else {
        uVar2 = *param_1;
        uVar1 = FUN_000080d0(param_1,0x3b90200);
        if (uVar1 != 0) {
          return (ulonglong)uVar1;
        }
        FUN_00009cd0(param_1,0);
        uVar1 = FUN_000080d0(param_1,0x3b90100);
        if (uVar1 != 0) {
          return (ulonglong)uVar1;
        }
        uVar1 = FUN_000080d0(param_1,0x3b78600);
        if (uVar1 != 0) {
          return (ulonglong)uVar1;
        }
        uVar1 = FUN_000080d0(param_1,0x3b90300);
        if (uVar1 != 0) {
          return (ulonglong)uVar1;
        }
        FUN_00006c9c(uVar2,6);
        param_1[0x1e] = 6;
        *(undefined1 *)((longlong)param_1 + 0xc9) = 1;
        FUN_0000b668(param_1,8);
        FUN_000063d0(uVar2,'\0');
        FUN_00006580(uVar2,'\x01');
        FUN_000097a8(param_1);
        FUN_00006580(uVar2,'\0');
        FUN_000065b4(uVar2);
        FUN_000065d0(uVar2);
        FUN_00006da0(uVar2,'\x01');
        FUN_00006d04(uVar2,0x68);
        FUN_00006c80(uVar2);
        FUN_00006d24(uVar2,1);
        iVar3 = 0x32;
        while (uVar1 = FUN_00006d48((ulonglong)uVar2), (uVar1 & 0xff) == 0) {
          iVar3 = iVar3 + -1;
          if (iVar3 == 0) {
            return 3;
          }
          FUN_00003f30(1000);
        }
      }
      FUN_00006d60(uVar2,0);
      goto LAB_00008964;
    }
LAB_00008920:
    param_1[0x1e] = (local_7e >> 1 & 1) + 3;
    uVar2 = FUN_00008ff8(param_1);
    if (uVar2 != 0) {
      return (ulonglong)uVar2;
    }
    uVar2 = FUN_00008eb8(param_1,'\0');
joined_r0x00008960:
    uVar4 = (ulonglong)uVar2;
  }
  else {
    if (uVar1 == 1) {
      if ((local_7e >> 4 & 1) == 0) goto LAB_00008920;
      param_1[0x33] = 7;
      uVar2 = FUN_00008f3c(param_1);
      goto joined_r0x00008960;
    }
    if ((((uVar1 != 0) || (uVar2 = FUN_00003e68(uVar2), (uVar2 >> 4 & 1) != 0)) ||
        (*(char *)((longlong)param_1 + 6) == '\0')) || ((local_7e >> 2 & 1) == 0))
    goto LAB_00008920;
    param_1[0x1e] = 4;
    param_1[0x33] = 6;
    uVar2 = FUN_00008ff8(param_1);
    if (uVar2 != 0) {
      return (ulonglong)uVar2;
    }
    uVar2 = FUN_00008eb8(param_1,'\x01');
    if (uVar2 != 0) {
      return (ulonglong)uVar2;
    }
    uVar4 = FUN_00009cd0(param_1,4);
    uVar2 = (uint)uVar4;
  }
  if (uVar2 != 0) {
    return uVar4;
  }
LAB_00008964:
  if ((char)param_1[0x1d] == '\x01') {
    if ((char)param_1[0x1c] == '\0') {
      param_1[10] = 0;
      *(undefined1 *)(param_1 + 0x1d) = 0;
    }
    else if (((local_93 != 0) && (local_90 != 0)) &&
            (uVar2 = FUN_000080d0(param_1,0x3af0100), uVar2 == 0)) {
      param_1[10] = (uint)local_93 * (uint)local_90 * 0x400;
    }
  }
  if ((char)param_1[0x1c] == '\0') {
    param_1[0x1a] = 0;
  }
  else if (((local_93 != 0) && (local_90 != 0)) &&
          (uVar2 = FUN_000080d0(param_1,0x3af0100), uVar2 == 0)) {
    param_1[0x1a] = (uint)local_93 << 10;
    param_1[0x2b] = (uint)local_92 * 300;
    param_1[0x2c] = (uint)uStack_a0._6_1_ * 300;
  }
  param_1[0x26] = 1;
  if (local_95 == 0) {
    uVar2 = 2;
    *(undefined1 *)((longlong)param_1 + 0x7d) = 0;
    uVar1 = 9;
    uVar7 = 1;
  }
  else {
    *(undefined1 *)((longlong)param_1 + 0x7d) = 1;
    uVar2 = 4;
    param_1[0x20] = (uint)local_95 << 7;
    uVar1 = 0xf;
    uVar7 = 3;
    param_1[0x26] = 7;
  }
  param_1[0xf] = uVar7;
  if (local_58 != 0) {
    param_1[0xf] = uVar2;
    param_1[0x26] = uVar1;
    param_1[0x18] = (uint)local_58 << 0x11;
  }
  puVar6 = param_1 + 0x21;
  piVar8 = local_4c;
  for (lVar5 = 0; lVar5 != 4; lVar5 = lVar5 + 1) {
    iVar3 = *piVar8;
    if (iVar3 != 0) {
      param_1[0xf] = param_1[0xf] + 1;
      param_1[0x26] = param_1[0x26] | 0x10 << (ulonglong)((uint)lVar5 & 0x1f);
      *puVar6 = param_1[10] * iVar3;
    }
    piVar8 = piVar8 + 1;
    puVar6 = puVar6 + 1;
  }
  if (local_57 != '\0') {
    *(char *)(param_1 + 0x19) = local_57;
  }
  *(undefined1 *)(param_1 + 0x27) = local_4f;
  return 0;
}



uint FUN_00008c20(uint *param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  undefined4 local_2c;
  undefined4 local_24;
  
  local_2c = 0;
  local_48 = 8;
  uStack_44 = 0;
  local_40 = 1;
  local_24 = 2;
  uVar1 = thunk_FUN_00009d84(param_1,(longlong)&local_48,param_2,1);
  if (uVar1 == 0) {
    FUN_00008c8c((longlong)param_2,&DAT_00017838);
  }
  return uVar1;
}



undefined8 FUN_00008c8c(longlong param_1,undefined1 *param_2)

{
  byte bVar1;
  ushort uVar2;
  uint3 uVar3;
  uint uVar4;
  ulonglong uVar5;
  uint uVar6;
  byte *pbVar7;
  longlong lVar8;
  ulonglong uVar9;
  
  if (param_2 != (undefined1 *)0x0) {
    *(uint *)(param_2 + 0x54) = (uint)*(uint3 *)(param_1 + 0x8f);
    *(uint *)(param_2 + 0x58) = (uint)*(uint3 *)(param_1 + 0x92);
    *(uint *)(param_2 + 0x5c) = (uint)*(uint3 *)(param_1 + 0x95);
    *(uint *)(param_2 + 0x60) = (uint)*(uint3 *)(param_1 + 0x98);
    param_2[0x51] = *(undefined1 *)(param_1 + 0x9b);
    param_2[0x4a] = *(undefined1 *)(param_1 + 0xa0);
    param_2[0x49] = *(byte *)(param_1 + 0xa2) & 3;
    param_2[0x48] = *(undefined1 *)(param_1 + 0xa8);
    param_2[0x2f] = *(undefined1 *)(param_1 + 0xad);
    param_2[0x30] = *(undefined1 *)(param_1 + 0xae);
    param_2[0x2e] = *(undefined1 *)(param_1 + 0xaf);
    param_2[0x2c] = *(undefined1 *)(param_1 + 0xb3);
    param_2[0x2a] = *(undefined1 *)(param_1 + 0xb8);
    param_2[0x26] = *(undefined1 *)(param_1 + 0xbd);
    param_2[0x25] = *(undefined1 *)(param_1 + 0xbf);
    param_2[0x24] = *(undefined1 *)(param_1 + 0xc0);
    param_2[0x23] = *(undefined1 *)(param_1 + 0xc2);
    param_2[0x22] = *(undefined1 *)(param_1 + 0xc4);
    param_2[0x21] = *(undefined1 *)(param_1 + 200);
    param_2[0x20] = *(undefined1 *)(param_1 + 0xc9);
    param_2[0x1f] = *(undefined1 *)(param_1 + 0xca);
    param_2[0x1e] = *(undefined1 *)(param_1 + 0xcb);
    param_2[0x1d] = *(undefined1 *)(param_1 + 0xcd);
    param_2[0x1c] = *(undefined1 *)(param_1 + 0xce);
    param_2[0x1b] = *(undefined1 *)(param_1 + 0xcf);
    param_2[0x1a] = *(undefined1 *)(param_1 + 0xd0);
    param_2[0x19] = *(undefined1 *)(param_1 + 0xd1);
    param_2[0x18] = *(undefined1 *)(param_1 + 0xd2);
    bVar1 = *(byte *)(param_1 + 0xd4);
    *(uint *)(param_2 + 0x14) = (uint)bVar1;
    uVar2 = CONCAT11(*(undefined1 *)(param_1 + 0xd5),bVar1);
    *(uint *)(param_2 + 0x14) = (uint)uVar2;
    uVar3 = CONCAT12(*(undefined1 *)(param_1 + 0xd6),uVar2);
    *(uint *)(param_2 + 0x14) = (uint)uVar3;
    *(uint *)(param_2 + 0x14) = CONCAT13(*(undefined1 *)(param_1 + 0xd7),uVar3);
    param_2[0x10] = *(undefined1 *)(param_1 + 0xdd);
    param_2[0xf] = *(undefined1 *)(param_1 + 0xde);
    param_2[0xe] = *(undefined1 *)(param_1 + 0xdf);
    param_2[0xd] = *(undefined1 *)(param_1 + 0xe0);
    param_2[0xb] = *(undefined1 *)(param_1 + 0xe2);
    param_2[7] = *(undefined1 *)(param_1 + 0xe7);
    param_2[6] = *(undefined1 *)(param_1 + 0xe8);
    *param_2 = *(undefined1 *)(param_1 + 0x1f8);
    param_2[0x34] = *(undefined1 *)(param_1 + 0x1a);
    param_2[0x33] = *(undefined1 *)(param_1 + 0x1e);
    param_2[0x32] = *(undefined1 *)(param_1 + 0xaa);
    uVar9 = 8;
    uVar5 = (ulonglong)*(byte *)(param_1 + 0xfe);
    pbVar7 = (byte *)(param_1 + 0xff);
    for (lVar8 = 1; *(ulonglong *)(param_2 + 0x40) = uVar5, lVar8 != 8; lVar8 = lVar8 + 1) {
      uVar5 = (ulonglong)*pbVar7 << (uVar9 & 0x3f) | uVar5;
      uVar9 = uVar9 + 8;
      pbVar7 = pbVar7 + 1;
    }
    uVar4 = (uint)*(byte *)(param_1 + 0x1e7);
    uVar6 = 8;
    pbVar7 = (byte *)(param_1 + 0x1e8);
    for (lVar8 = 1; *(uint *)(param_2 + 0x38) = uVar4, lVar8 != 4; lVar8 = lVar8 + 1) {
      uVar4 = (uint)*pbVar7 << (ulonglong)(uVar6 & 0x1f) | uVar4;
      uVar6 = uVar6 + 8;
      pbVar7 = pbVar7 + 1;
    }
    param_2[0x31] = *(undefined1 *)(param_1 + 0x1ed);
    return 1;
  }
  return 0;
}



uint FUN_00008eb8(uint *param_1,char param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == (uint *)0x0) {
    uVar2 = 0x14;
  }
  else {
    uVar1 = *param_1;
    uVar2 = FUN_00003e68(uVar1);
    iVar3 = 6;
    iVar4 = 5;
    if (param_2 != '\x01') {
      iVar4 = 1;
      iVar3 = 2;
    }
    if ((uVar2 & 4) != 0) {
      iVar4 = iVar3;
    }
    uVar2 = FUN_000080d0(param_1,iVar4 << 8 | 0x3b70000);
    if (uVar2 == 0) {
      uVar2 = FUN_0000a3a4(uVar1,iVar4);
    }
  }
  return uVar2;
}



uint FUN_00008f3c(uint *param_1)

{
  uint uVar1;
  
  if ((param_1 == (uint *)0x0) || (1 < param_1[0x33] - 7)) {
    return 0x14;
  }
  uVar1 = FUN_000080d0(param_1,0x3b90200);
  if (uVar1 != 0) {
    return uVar1;
  }
  FUN_000069a8(*param_1,'\0');
  if (param_1[0x33] == 7) {
    uVar1 = 5;
  }
  else {
    if (param_1[0x33] != 8) goto LAB_00008fc0;
    FUN_00006ce4(*param_1,3);
    uVar1 = 6;
  }
  param_1[0x1e] = uVar1;
LAB_00008fc0:
  *(undefined1 *)((longlong)param_1 + 0xc9) = 1;
  FUN_00006b2c(*param_1,3);
  FUN_00006c9c(*param_1,4);
  FUN_0000b668(param_1,param_1[0x33]);
  uVar1 = FUN_000082b4(param_1);
  return uVar1;
}



uint FUN_00008ff8(uint *param_1)

{
  uint uVar1;
  
  if (param_1 == (uint *)0x0) {
    uVar1 = 0x14;
  }
  else {
    uVar1 = FUN_000080d0(param_1,0x3b90100);
    if (uVar1 == 0) {
      FUN_0000b668(param_1,1);
      uVar1 = 0;
    }
  }
  return uVar1;
}



undefined8 FUN_00009044(undefined8 *param_1,longlong param_2)

{
  undefined1 uVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined1 *puVar4;
  longlong lVar5;
  
  uVar2 = 0;
  if ((param_1 != (undefined8 *)0x0) && (param_2 != 0)) {
    FUN_00004788((longlong *)&DAT_000177a0,4,0);
    FUN_000047cc((undefined8 *)&DAT_000177a0,param_1,4);
    *(ushort *)(param_2 + 0x46) = (ushort)*(byte *)((longlong)param_1 + 3);
    *(byte *)(param_2 + 0x70) = (byte)*(undefined2 *)((longlong)param_1 + 2) & 3;
    *(ushort *)(param_2 + 0x48) = (ushort)((uint)*(undefined4 *)param_1 >> 8) & 0xff;
    *(char *)(param_2 + 0x4a) = (char)*(undefined4 *)param_1;
    uVar3 = *(uint *)((longlong)param_1 + 4);
    puVar4 = (undefined1 *)(param_2 + 0x4e);
    lVar5 = 4;
    while (0 < lVar5) {
      *puVar4 = (char)uVar3;
      uVar3 = uVar3 >> 8;
      puVar4 = puVar4 + -1;
      lVar5 = lVar5 + -1;
    }
    uVar1 = *(undefined1 *)((longlong)param_1 + 0xb);
    uVar2 = 1;
    *(undefined1 *)(param_2 + 0x50) = 0;
    *(undefined1 *)(param_2 + 0x4f) = uVar1;
    *(char *)(param_2 + 0x51) = (char)*(undefined2 *)((longlong)param_1 + 10);
    *(int *)(param_2 + 0x54) =
         (int)(CONCAT44(*(undefined4 *)(param_1 + 1),*(undefined4 *)((longlong)param_1 + 0xc)) >>
              0x10);
  }
  return uVar2;
}



uint FUN_0000910c(undefined8 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
  uVar2 = *(uint *)(param_1 + 1);
  puVar3 = (uint *)*param_1;
  if (uVar2 + 1 < 2) {
    uVar2 = 0;
  }
  else if (*(char *)((longlong)puVar3 + 0x7d) == '\0') {
    FUN_00004548(0x80000000,(byte *)"Partition not supported");
    return 0x16;
  }
  if ((1 << (ulonglong)(uVar2 & 0x1f) & puVar3[0x26]) == 0) {
    uVar1 = 0x14;
  }
  else {
    uVar1 = FUN_000080d0(puVar3,(uVar2 | (uint)(byte)puVar3[0x25] << 3) << 8 | 0x3b30000);
    if (uVar1 == 0) {
      puVar3[2] = uVar2;
    }
    else {
      FUN_00004548(0x80000000,(byte *)"Failed to set EMMC partition %d access, rc %d");
    }
  }
  return uVar1;
}



undefined8 FUN_000091c8(longlong *param_1,int *param_2,undefined4 *param_3)

{
  longlong lVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = *(uint *)(param_1 + 1);
  lVar1 = *param_1;
  if (uVar2 + 1 < 2) {
    uVar2 = 0;
  }
  else if (*(char *)(lVar1 + 0x7d) == '\0') {
    FUN_00004548(0x80000000,(byte *)"Partition is not supported");
    return 0x16;
  }
  if ((1 << (ulonglong)(uVar2 & 0x1f) & *(uint *)(lVar1 + 0x98)) != 0) {
    if (uVar2 == 0) {
      *param_2 = *(int *)(lVar1 + 0x24);
      *param_3 = 0;
      return 0;
    }
    if (uVar2 - 1 < 2) {
      uVar3 = 1;
      if (uVar2 != 1) {
        uVar3 = 2;
      }
      *param_2 = (*(uint *)(lVar1 + 0x80) & 0x3fffff) << 1;
      *param_3 = uVar3;
      return 0;
    }
    switch(uVar2) {
    case 3:
      *param_2 = (uint)DAT_00017648 << 8;
      *param_3 = 3;
      return 0;
    case 4:
      *param_2 = *(int *)(lVar1 + 0x84);
      *param_3 = 4;
      return 0;
    case 5:
      *param_2 = *(int *)(lVar1 + 0x88);
      *param_3 = 5;
      return 0;
    case 6:
      *param_2 = *(int *)(lVar1 + 0x8c);
      *param_3 = 6;
      return 0;
    case 7:
      *param_2 = *(int *)(lVar1 + 0x90);
      *param_3 = 7;
      return 0;
    }
  }
  return 0x14;
}



uint FUN_00009314(longlong *param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  uint *puVar4;
  uint uVar5;
  longlong lVar6;
  uint local_a0;
  int local_9c;
  undefined4 local_98;
  int local_94;
  undefined4 local_84;
  undefined4 local_7c;
  uint local_78;
  int iStack_74;
  undefined4 local_70;
  int local_6c;
  undefined4 local_5c;
  undefined4 local_54;
  
  lVar6 = *param_1;
  uVar2 = FUN_0000b440(param_1);
  if (uVar2 != 0) {
    return uVar2;
  }
  if (*(uint *)(lVar6 + 8) < 8) {
    uVar2 = 1 << (ulonglong)(*(uint *)(lVar6 + 8) & 0x1f);
    if ((uVar2 & 0xf1) == 0) {
      if ((uVar2 & 6) == 0) goto LAB_00009480;
      puVar4 = (uint *)*param_1;
      FUN_00004788((longlong *)&DAT_000175a0,0x200,0);
      uVar2 = FUN_00008c20(puVar4,(undefined4 *)&DAT_000175a0);
      if (uVar2 != 0) {
        return uVar2;
      }
      if ((DAT_0001764d >> 6 & 1) == 0) {
        if ((DAT_0001764d >> 2 & 1) == 0) {
          if ((DAT_0001764d & 1) != 0) {
            return 0;
          }
          uVar2 = FUN_000080d0(puVar4,0x1ad0100);
          if (uVar2 == 0) {
            return 0;
          }
          pcVar3 = "Failed in enabling boot power-on write protect %d";
          goto LAB_00009458;
        }
        pcVar3 = "Boot permanent WP has been enabled";
        goto LAB_000094b8;
      }
    }
    else {
      if (param_3 == 0) {
        FUN_00004548(0x80000000,(byte *)"Invalid number of blocks for enabling power-on WP");
        return 0x14;
      }
      puVar4 = (uint *)*param_1;
      FUN_00004788((longlong *)&DAT_000175a0,0x200,0);
      uVar2 = FUN_00008c20(puVar4,(undefined4 *)&DAT_000175a0);
      if (uVar2 != 0) {
        return uVar2;
      }
      if ((DAT_0001764b >> 3 & 1) == 0) {
        if ((DAT_0001764b >> 2 & 1) == 0) {
          uVar2 = FUN_000080d0(puVar4,0x1ab0100);
          if (uVar2 != 0) {
            pcVar3 = "Failed in enabling user power-on write protect %d";
LAB_00009458:
            FUN_00004548(0x80000000,(byte *)pcVar3);
            return uVar2;
          }
          uVar2 = puVar4[10];
          if (uVar2 != 0) {
            uVar1 = 0;
            if (uVar2 != 0) {
              uVar1 = param_3 / uVar2;
            }
            uVar5 = 0;
            local_7c = 0;
            local_a0 = 0x1c;
            if (param_3 != uVar1 * uVar2) {
              uVar1 = uVar1 + 1;
            }
            local_98 = 1;
            local_84 = 1;
            while( true ) {
              if (uVar1 <= uVar5) {
                return 0;
              }
              local_9c = param_2 + puVar4[10] * uVar5;
              if (1 < puVar4[3] - 5) {
                local_9c = puVar4[0xb] * local_9c;
              }
              uVar2 = FUN_0000b868(puVar4,&local_a0);
              if (uVar2 != 0) break;
              if (local_94 < 0) {
                pcVar3 = "CMD28 response with address out of range";
                goto LAB_000094b8;
              }
              local_70 = 1;
              local_5c = 0;
              local_54 = 0;
              iStack_74 = (uint)(ushort)puVar4[5] << 0x10;
              local_78 = 0xd;
              uVar2 = FUN_0000b868(puVar4,&local_78);
              if (uVar2 != 0) {
LAB_000095c4:
                FUN_00004548(0x80000000,(byte *)"CMD28 failed with address 0x%x");
                return uVar2;
              }
              if (local_6c < 0) {
                FUN_00004548(0x80000000,(byte *)"Address out of range");
                uVar2 = 0x1c;
                goto LAB_000095c4;
              }
              uVar5 = uVar5 + 1;
            }
            pcVar3 = "CMD28 failed %d";
            goto LAB_00009458;
          }
          pcVar3 = "Write protect group size is 0";
        }
        else {
          pcVar3 = "User permanent WP has been enabled";
        }
      }
      else {
        pcVar3 = "Use of user power-on WP has been disabled";
      }
LAB_000094b8:
      FUN_00004548(0x80000000,(byte *)pcVar3);
    }
    uVar2 = 0x1c;
  }
  else {
LAB_00009480:
    FUN_00004548(0x80000000,(byte *)"RPMB is not supported");
    uVar2 = 0x16;
  }
  return uVar2;
}



uint FUN_000095dc(longlong *param_1,int param_2,longlong *param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  longlong lVar4;
  undefined4 local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_4c;
  undefined4 local_44;
  
  lVar4 = *param_1;
  if (*(char *)(lVar4 + 0xa8) == '\x01') {
    FUN_00004788(param_3,8,0xff);
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_0000b440(param_1);
    if (uVar1 == 0) {
      uVar1 = *(uint *)(lVar4 + 8);
      if (uVar1 < 8) {
        uVar1 = 1 << (ulonglong)(uVar1 & 0x1f);
        if ((uVar1 & 0xf1) != 0) {
          puVar3 = (uint *)*param_1;
          local_4c = 0;
          local_44 = 2;
          local_68 = 0x1f;
          local_60 = 1;
          if (1 < puVar3[3] - 5) {
            param_2 = puVar3[0xb] * param_2;
          }
          uVar1 = puVar3[0x1b];
          puVar3[0x1b] = 0;
          local_64 = param_2;
          uVar2 = thunk_FUN_00009d84(puVar3,(longlong)&local_68,(undefined4 *)param_3,8);
          FUN_00003f30(5);
          puVar3[0x1b] = uVar1;
          return uVar2;
        }
        if ((uVar1 & 6) != 0) {
          puVar3 = (uint *)*param_1;
          FUN_00004788((longlong *)&DAT_000175a0,0x200,0);
          uVar1 = FUN_00008c20(puVar3,(undefined4 *)&DAT_000175a0);
          if (uVar1 != 0) {
            return uVar1;
          }
          if ((DAT_0001764d >> 2 & 1) == 0) {
            *(byte *)((longlong)param_3 + 7) = (DAT_0001764d & 1) << 1;
            return 0;
          }
          *(undefined1 *)((longlong)param_3 + 7) = 3;
          return 0;
        }
      }
      FUN_00004548(0x80000000,(byte *)"RPMB is not supported");
      uVar1 = 0x16;
    }
  }
  return uVar1;
}



undefined8 FUN_00009754(longlong *param_1)

{
  int iVar1;
  char cVar2;
  
  cVar2 = *(char *)(*param_1 + 0x94);
  iVar1 = 0;
  if ((int)param_1[1] != -1) {
    iVar1 = (int)param_1[1];
  }
  if (cVar2 == '\x01') {
    if (iVar1 == 1) {
      return 1;
    }
  }
  else if (cVar2 == '\x02') {
    if (iVar1 == 2) {
      return 1;
    }
  }
  else if (cVar2 == '\a' && iVar1 == 0) {
    return 1;
  }
  return 0;
}



void FUN_000097a8(uint *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = param_1[0x2d];
  iVar3 = 6;
  if (0x2da78 < uVar2) {
    iVar3 = 7;
  }
  iVar1 = 5;
  if (0x2ab98 < uVar2) {
    iVar1 = iVar3;
  }
  iVar3 = 4;
  if (0x278d0 < uVar2) {
    iVar3 = iVar1;
  }
  iVar1 = 3;
  if (150000 < uVar2) {
    iVar1 = iVar3;
  }
  iVar3 = 2;
  if (0x21728 < uVar2) {
    iVar3 = iVar1;
  }
  if (uVar2 < 0x1e849) {
    iVar3 = 1;
  }
  iVar1 = 0;
  if (0x1b580 < uVar2) {
    iVar1 = iVar3;
  }
  FUN_00006560(*param_1,iVar1);
  return;
}



longlong * FUN_00009838(short param_1,undefined4 param_2)

{
  longlong lVar1;
  char *pcVar2;
  longlong *plVar3;
  
  if (DAT_00016e90 < 1) {
    pcVar2 = "SDCC Client handle list is full";
LAB_000098c4:
    FUN_00004548(0x80000000,(byte *)pcVar2);
  }
  else {
    for (plVar3 = &DAT_000178a8; plVar3 < (longlong *)0x17a11; plVar3 = plVar3 + 3) {
      if (*plVar3 == 0) {
        lVar1 = FUN_0000b620((int)param_1);
        if (lVar1 != 0) {
          *(undefined4 *)(plVar3 + 1) = param_2;
          *plVar3 = lVar1 + 8;
          DAT_00016e90 = DAT_00016e90 + -1;
          return plVar3;
        }
        pcVar2 = "sdcc_register_client_handle: can\'t get slot handle\n";
        goto LAB_000098c4;
      }
    }
  }
  return (longlong *)0x0;
}



void FUN_000098e4(undefined8 *param_1)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)*param_1;
  if (puVar2 == (undefined8 *)0x0) {
    FUN_00004548(0x80000000,(byte *)"Handle already de-registered");
    return;
  }
  if (((int *)*puVar2)[3] == 0) {
    iVar1 = *(int *)*puVar2;
    puVar2 = &DAT_000178a8;
    do {
      if ((undefined8 *)0x17a10 < puVar2) break;
      if (((int *)*puVar2 != (int *)0x0) && (*(int *)*puVar2 == iVar1)) {
        FUN_0000999c(puVar2);
      }
      puVar2 = puVar2 + 3;
    } while (DAT_00016e90 != 0x10);
  }
  else {
    FUN_0000999c(puVar2);
  }
  *param_1 = 0;
  return;
}



void FUN_0000999c(undefined8 *param_1)

{
  *param_1 = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  param_1[2] = 0;
  DAT_00016e90 = DAT_00016e90 + 1;
  return;
}



undefined8 FUN_000099bc(longlong param_1)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  
  if (DAT_00016e90 != 0x10) {
    plVar1 = &DAT_000178a8;
    while (plVar1 < (longlong *)0x17a11) {
      plVar2 = plVar1 + 3;
      lVar3 = *plVar1;
      plVar1 = plVar2;
      if ((lVar3 != 0) && (lVar3 == param_1)) {
        return 1;
      }
    }
  }
  return 0;
}



undefined4 FUN_00009a04(uint param_1)

{
  uint uVar1;
  byte bVar2;
  uint *puVar3;
  longlong lVar4;
  byte bVar5;
  
  puVar3 = (uint *)FUN_0000b620(param_1);
  if (puVar3 == (uint *)0x0) {
    FUN_00004548(0x80000000,(byte *)"sdcc_init_sdhci_mode: can\'t get slot handle\n");
    return 0;
  }
  *(uint **)(puVar3 + 0x32) = puVar3;
  if (puVar3[6] - 1 < 2) {
    return 1;
  }
  if ((char)puVar3[1] == '\0') {
    FUN_00004788((longlong *)(puVar3 + 2),0xd0,0);
    *(uint **)(puVar3 + 0x32) = puVar3;
    puVar3[2] = param_1;
    *puVar3 = param_1;
    *(undefined1 *)(puVar3 + 1) = 1;
  }
  FUN_00003ea8((ulonglong)param_1);
  FUN_0000fa64(param_1);
  FUN_0000f5f0(param_1);
  FUN_00006dc8();
  FUN_0000b668(puVar3 + 2,5);
  puVar3[2] = param_1;
  puVar3[6] = 1;
  puVar3[0x1d] = 1;
  puVar3[0x34] = 0xff;
  if (param_1 == 0) {
    FUN_00006cc8(0);
  }
  FUN_0000694c(param_1,1);
  FUN_000063f8((ulonglong)param_1,1);
  FUN_00006bc0(param_1);
  FUN_00003e44();
  FUN_00006b4c(param_1,puVar3 + 0x37);
  lVar4 = FUN_0000b620(param_1);
  if (lVar4 == 0) {
    FUN_00004548(0x80000000,(byte *)"sdcc_hc_set_power_mode: can\'t get slot handle\n");
  }
  else {
    uVar1 = *(uint *)(lVar4 + 0xdc);
    if ((uVar1 >> 0x18 & 1) == 0) {
      if ((uVar1 >> 0x19 & 1) == 0) {
        if ((uVar1 >> 0x1a & 1) == 0) goto LAB_00009b9c;
        bVar5 = 10;
      }
      else {
        bVar5 = 0xc;
      }
    }
    else {
      bVar5 = 0xe;
    }
    bVar2 = FUN_0000696c((ulonglong)param_1);
    if ((bVar5 | 1) != bVar2) {
      FUN_0000694c(param_1,0);
      FUN_00006928(param_1,bVar5);
      FUN_0000694c(param_1,1);
      FUN_000064cc((ulonglong)param_1);
    }
  }
LAB_00009b9c:
  FUN_00006b04(param_1,0x7ff003f,'\0');
  FUN_00006a74((ulonglong)param_1,0x7ff003f,'\x01');
  FUN_00006a0c((ulonglong)param_1,0x7ff003f);
  *(byte *)((longlong)puVar3 + 0xe) = (byte)(puVar3[0x38] >> 2) & 1;
  if ((*(byte *)((longlong)puVar3 + 0xde) >> 3 & 1) == 0) {
    *(undefined1 *)((longlong)puVar3 + 0xd) = 0;
    FUN_000068f8(param_1,'\0');
    FUN_00006d84(param_1);
    return 1;
  }
  *(undefined1 *)((longlong)puVar3 + 0xd) = 1;
  FUN_000068f8(param_1,'\x01');
  return 1;
}



undefined8 FUN_00009c40(uint param_1,uint param_2)

{
  bool bVar1;
  byte bVar2;
  undefined8 uVar3;
  int iVar4;
  
  if (param_1 < 4) {
    FUN_00006984(param_1,param_2);
    iVar4 = 5000000;
    do {
      bVar2 = FUN_000069cc((ulonglong)param_1);
      if (bVar2 == 1) {
        FUN_000069a8(param_1,'\x01');
        return 0;
      }
      FUN_00003f30(1);
      bVar1 = iVar4 != 0;
      iVar4 = iVar4 + -1;
    } while (bVar1);
    uVar3 = 3;
  }
  else {
    FUN_00004548(0x80000000,(byte *)"sdcc_hc_set_clock: Invalid Drive Number:%d");
    uVar3 = 0x14;
  }
  return uVar3;
}



undefined8 FUN_00009cd0(uint *param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 != (uint *)0x0) {
    uVar1 = *param_1;
    FUN_000069a8(uVar1,'\0');
    if ((param_2 < 5) && ((0x1bU >> (ulonglong)(param_2 & 0x1f) & 1) != 0)) {
      uVar2 = *(undefined4 *)(&DAT_000140c0 + (longlong)(int)param_2 * 4);
      iVar3 = *(int *)(&DAT_000140e0 + (longlong)(int)param_2 * 4);
      param_1[0x1e] = *(uint *)(&DAT_000140a0 + (longlong)(int)param_2 * 4);
      FUN_00006b2c(uVar1,(ushort)param_2);
      FUN_00006c9c(uVar1,iVar3);
      FUN_0000b668(param_1,uVar2);
      return 0;
    }
  }
  return 0x14;
}



uint FUN_00009d84(uint *param_1,longlong param_2,undefined4 *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint local_90 [7];
  uint local_74;
  undefined4 local_6c;
  uint local_64;
  
  uVar2 = *param_1;
  local_64 = 0;
  if (param_1[0x1b] == 0) {
    uVar7 = param_4 & 0xffff;
  }
  else {
    uVar7 = param_1[0xb];
  }
  uVar1 = param_4 & 0xffff;
  if (param_1[0x1b] == 0) {
    uVar1 = 1;
  }
  *(undefined1 *)((longlong)param_1 + 0x16) = *(undefined1 *)((longlong)param_1 + 5);
  uVar4 = uVar1 * uVar7;
  uVar6 = FUN_000069f8((ulonglong)uVar2);
  local_64 = uVar6;
  if (((uVar6 & 0x7ff003f) != 0) &&
     (FUN_00006a0c((ulonglong)uVar2,0x7ff003f), (uVar6 & 0x7ff0000) != 0)) {
    FUN_000063f8((ulonglong)uVar2,6);
  }
  if (*(char *)((longlong)param_1 + 0x16) == '\x01') {
    FUN_0000a144(uVar2,(ulonglong)param_3,uVar4);
  }
  FUN_00006794(uVar2,(short)uVar7);
  FUN_000067a8(uVar2,(ushort)uVar1);
  FUN_0000a284(param_1,param_2,(ushort)uVar1);
  if ((*(byte *)(param_2 + 0x24) >> 2 & 1) == 0) {
    uVar7 = FUN_0000b868(param_1,(uint *)param_2);
  }
  else {
    uVar7 = FUN_0000b4c0((longlong)param_1,param_2);
  }
  if (uVar7 != 0) {
LAB_00009e94:
    thunk_FUN_000069f8((ulonglong)uVar2);
    FUN_000063f8((ulonglong)uVar2,2);
    FUN_000063f8((ulonglong)uVar2,4);
    FUN_00006a0c((ulonglong)uVar2,0x7ff003f);
    return uVar7;
  }
  if (*(char *)((longlong)param_1 + 0x16) == '\0') {
    uVar6 = *param_1;
    local_90[0] = 0;
    if (param_1[0x1b] == 1) {
      uVar7 = param_1[0xb];
      uVar9 = 0;
      if (uVar7 != 0) {
        uVar9 = uVar4 / uVar7;
      }
    }
    else {
      uVar9 = 1;
      uVar7 = uVar4;
    }
    if ((*(uint *)(param_2 + 0x24) >> 1 & 1) == 0) {
      if ((*(uint *)(param_2 + 0x24) & 1) == 0) {
        uVar7 = 1;
        goto LAB_00009e94;
      }
      uVar12 = 0x10;
    }
    else {
      uVar12 = 0x20;
    }
    uVar3 = uVar7 + 3 >> 2;
    puVar11 = param_3;
    do {
      bVar5 = FUN_0000a304(uVar6,uVar12,local_90);
      uVar7 = (uint)bVar5;
      if (bVar5 != 0) {
        *(uint *)(param_2 + 0x20) = local_90[0];
        goto LAB_00009e94;
      }
      FUN_00006a0c((ulonglong)uVar6,uVar12);
      if ((*(uint *)(param_2 + 0x24) >> 1 & 1) == 0) {
        if ((*(uint *)(param_2 + 0x24) & 1) != 0) {
          puVar10 = puVar11;
          for (uVar7 = 0; uVar7 != uVar3; uVar7 = uVar7 + 1) {
            FUN_00006884(uVar6,*puVar10);
            puVar10 = puVar10 + 1;
          }
          puVar11 = puVar11 + uVar3;
        }
      }
      else {
        puVar10 = puVar11;
        for (uVar7 = 0; uVar7 != uVar3; uVar7 = uVar7 + 1) {
          uVar8 = FUN_00006870((ulonglong)uVar6);
          *puVar10 = uVar8;
          puVar10 = puVar10 + 1;
        }
        puVar11 = puVar11 + uVar3;
      }
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
    uVar7 = 2;
  }
  else {
    uVar7 = 0x2000002;
  }
  bVar5 = FUN_0000a304(uVar2,uVar7,&local_64);
  uVar7 = (uint)bVar5;
  if (bVar5 != 0) {
    *(uint *)(param_2 + 0x20) = local_64;
    if ((*(char *)((longlong)param_1 + 0x16) == '\0') || ((local_64 >> 0x19 & 1) == 0)) {
      if ((local_64 & 0x300000) != 0) {
        if ((*(char *)((longlong)param_1 + 0xc9) == '\0') ||
           (*(char *)((longlong)param_1 + 0xca) != '\0')) {
          uVar7 = 3;
        }
        else {
          uVar7 = 3;
          *(undefined1 *)((longlong)param_1 + 0xcb) = 0;
        }
      }
    }
    else {
      FUN_00004548(0x80000000,(byte *)"SDCC: DATA ADMA ERROR %d\n");
      uVar7 = 0xc;
    }
    goto LAB_00009e94;
  }
  if ((local_64 >> 1 & 1) != 0) {
    FUN_00006a0c((ulonglong)uVar2,2);
    uVar7 = *(uint *)(param_2 + 0x24);
    if (((uVar7 >> 2 & 1) == 0) && ((uVar2 != 0 || (param_1[2] != 3)))) {
      if (1 < uVar1) {
        local_6c = 0;
        local_74 = uVar7 & 1;
        local_90[0] = 0xc;
        local_90[1] = 0;
        local_90[2] = 1;
        uVar7 = FUN_0000b868(param_1,local_90);
        if ((local_90[3] >> 0x1a & 1) != 0) {
          return 0x1d;
        }
        goto LAB_0000a0f8;
      }
      if ((uVar7 & 1) != 0) {
        uVar7 = FUN_0000b55c((longlong)param_1);
        goto LAB_0000a0f8;
      }
    }
  }
  uVar7 = 0;
LAB_0000a0f8:
  if (((*(byte *)(param_2 + 0x24) >> 1 & 1) != 0) && (*(char *)((longlong)param_1 + 0x16) == '\x01')
     ) {
    thunk_FUN_000042c8();
    FUN_00003f44(0,(ulonglong)param_3,uVar4);
    thunk_FUN_000042c8();
  }
  FUN_000063f8((ulonglong)uVar2,6);
  return uVar7;
}



void FUN_0000a144(uint param_1,ulonglong param_2,uint param_3)

{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  byte bVar4;
  
  thunk_FUN_000042c8();
  FUN_00003f44(1,param_2,param_3);
  thunk_FUN_000042c8();
  uVar1 = param_3 >> 0x10;
  if ((param_3 & 0xffff) != 0) {
    uVar1 = uVar1 + 1;
  }
  pbVar2 = &DAT_00017a48;
  FUN_00004788((longlong *)&DAT_00017a48,(ulonglong)(uVar1 * 0xc),0);
  do {
    if (param_3 == 0) {
LAB_0000a244:
      thunk_FUN_000042c8();
      FUN_00003f44(1,0x17a48,uVar1 * 0xc);
      thunk_FUN_000042c8();
      FUN_00006b84(param_1,0);
      FUN_00006b70(param_1,0x17a48);
      return;
    }
    uVar3 = param_3;
    if (0xffff < param_3) {
      uVar3 = 0x10000;
    }
    pbVar2[4] = (byte)param_2;
    pbVar2[7] = (byte)(param_2 >> 0x18);
    pbVar2[6] = (byte)(param_2 >> 0x10);
    pbVar2[8] = (byte)(param_2 >> 0x20);
    pbVar2[0xb] = (byte)(param_2 >> 0x38);
    pbVar2[10] = (byte)(param_2 >> 0x30);
    param_3 = param_3 - uVar3;
    bVar4 = 0x21;
    if (uVar3 == 0) {
      bVar4 = 1;
    }
    pbVar2[2] = (byte)uVar3;
    pbVar2[1] = 0;
    pbVar2[9] = (byte)(param_2 >> 0x28);
    pbVar2[5] = (byte)(param_2 >> 8);
    pbVar2[3] = (byte)(uVar3 >> 8);
    *pbVar2 = bVar4;
    if (param_3 == 0) {
      pbVar2[1] = 0;
      *pbVar2 = bVar4 | 2;
      goto LAB_0000a244;
    }
    param_2 = param_2 + uVar3;
    pbVar2 = pbVar2 + 0xc;
  } while( true );
}



void FUN_0000a284(uint *param_1,longlong param_2,ushort param_3)

{
  byte local_28 [8];
  
  FUN_00004788((longlong *)local_28,5,0);
  if ((*(byte *)(param_2 + 0x24) >> 1 & 1) != 0) {
    local_28[1] = 1;
  }
  if (1 < param_3) {
    local_28[0] = 1;
  }
  local_28[4] = *(undefined1 *)((longlong)param_1 + 0x16);
  local_28[2] = 0;
  local_28[3] = 1;
  FUN_000067d0(*param_1,local_28);
  return;
}



undefined1 FUN_0000a304(uint param_1,uint param_2,uint *param_3)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_2 & 0x7ff003f) == 0) {
    uVar1 = 0x14;
  }
  else {
    for (uVar3 = 0; uVar3 < 5000000; uVar3 = uVar3 + 100) {
      uVar2 = FUN_000069f8((ulonglong)param_1);
      if ((uVar2 & (param_2 | 0x8000)) != 0) {
        *param_3 = uVar2;
        return (uVar2 & 0x7ff0000) != 0;
      }
      FUN_00003f30(100);
    }
    uVar1 = 3;
  }
  return uVar1;
}



undefined4 thunk_FUN_000069f8(ulonglong param_1)

{
  return *(undefined4 *)((&DAT_000172e8)[param_1 & 0xffffffff] + 0x30);
}



undefined4 FUN_0000a3a4(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0x14;
  switch(param_2) {
  case 0:
    iVar1 = 0;
    break;
  case 1:
  case 5:
    iVar1 = 1;
    break;
  case 2:
  case 6:
    iVar1 = 2;
    break;
  default:
    goto switchD_0000a3c8_caseD_3;
  }
  FUN_000068ac(param_1,iVar1);
  uVar2 = 0;
switchD_0000a3c8_caseD_3:
  return uVar2;
}



uint FUN_0000a3f4(uint *param_1,uint *param_2)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  byte local_50 [5];
  char local_4b;
  uint local_44;
  
  uVar1 = *param_1;
  local_44 = 0;
  FUN_00004788((longlong *)local_50,6,0);
  uVar5 = 0;
  while( true ) {
    if (0x270 < uVar5 >> 4) {
      return 3;
    }
    uVar4 = FUN_00006898((ulonglong)uVar1);
    if ((uVar4 & 3) == 0) break;
    FUN_00003f30(100);
    uVar5 = uVar5 + 100;
  }
  if ((((*(char *)((longlong)param_1 + 0xc9) != '\0') &&
       (*(char *)((longlong)param_1 + 0xca) == '\0')) &&
      (*(char *)((longlong)param_1 + 0xcb) == '\0')) &&
     ((param_1[0x33] == 7 && (uVar5 = FUN_000082b4(param_1), uVar5 != 0)))) {
    return uVar5;
  }
  FUN_000069e4(uVar1,0xf);
  FUN_000067bc(uVar1,param_2[1]);
  if (param_1[0x33] - 7 < 2) {
    if ((*param_2 < 0x16) && ((1 << (ulonglong)(*param_2 & 0x1f) & 0x260000U) != 0)) {
      cVar3 = '\x01';
    }
    else {
      cVar3 = '\0';
    }
    FUN_000065ec(uVar1,cVar3);
  }
  uVar5 = param_2[9];
  local_50[1] = 0;
  local_50[2] = (uVar5 & 3) != 0;
  local_50[0] = (byte)*param_2;
  if (param_2[2] == 4) {
    cVar3 = '\x01';
  }
  else {
    cVar3 = '\0';
    if ((param_2[2] == 1) && (cVar3 = '\x02', param_2[7] != 0)) {
      cVar3 = '\x03';
    }
  }
  local_4b = cVar3;
  FUN_00006750(uVar1,local_50);
  bVar2 = FUN_0000a304(uVar1,1,&local_44);
  if (bVar2 != 0) {
    param_2[8] = local_44;
    if (((*(char *)((longlong)param_1 + 0xc9) != '\0') && ((local_44 & 0x220000) != 0)) &&
       (*(char *)((longlong)param_1 + 0xcb) != '\0')) {
      *(undefined1 *)((longlong)param_1 + 0xcb) = 0;
      *(undefined1 *)(param_1 + 0x32) = 0xff;
    }
    FUN_000063f8((ulonglong)uVar1,2);
    return (uint)bVar2;
  }
  FUN_00006a0c((ulonglong)uVar1,1);
  if (cVar3 != '\0') {
    FUN_00004788((longlong *)(param_2 + 3),0x10,0);
    FUN_00006810(uVar1,(int *)(param_2 + 3),param_2[2] == 4);
  }
  if ((uVar5 & 3) != 0) {
    return 0;
  }
  if (param_2[7] == 0) {
    return 0;
  }
  cVar3 = FUN_0000a304(uVar1,2,&local_44);
  if (cVar3 != '\0') {
    param_2[8] = local_44;
    return 7;
  }
  FUN_00006a0c((ulonglong)uVar1,2);
  return 0;
}



uint FUN_0000a650(uint param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 < 4) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0;
      uVar1 = FUN_000069f8((ulonglong)param_1);
      if ((uVar1 & 0x7ff0000) != 0) {
        *param_2 = 1;
        return 3;
      }
      uVar2 = FUN_00006898((ulonglong)param_1);
      if ((uVar2 & 0x303) == 0) {
        return uVar1 >> 1 & 1;
      }
      return 2;
    }
    FUN_00004548(0x80000000,(byte *)"sdcc_get_device_status_sdhci_mode: rc is NULL \n");
  }
  return 3;
}



int FUN_0000a6e0(ulonglong param_1,undefined4 *param_2)

{
  uint uVar1;
  
  if ((uint)param_1 < 4) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0;
      uVar1 = FUN_000069f8(param_1);
      if ((uVar1 & 0x7ff0000) != 0) {
        *param_2 = 1;
        return 3;
      }
      return 2 - (uVar1 >> 1 & 1);
    }
    FUN_00004548(0x80000000,(byte *)"sdcc_sdhci_check_transfer_status: rc is NULL \n");
  }
  return 3;
}



uint FUN_0000a74c(uint *param_1,uint *param_2,ulonglong param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = *param_1;
  if (param_1[0x1b] == 0) {
    uVar4 = param_4 & 0xffff;
  }
  else {
    uVar4 = param_1[0xb];
  }
  uVar1 = param_4 & 0xffff;
  if (param_1[0x1b] == 0) {
    uVar1 = 1;
  }
  *(undefined1 *)((longlong)param_1 + 0x16) = *(undefined1 *)((longlong)param_1 + 5);
  uVar3 = FUN_000069f8((ulonglong)uVar2);
  if (((uVar3 & 0x7ff003f) != 0) &&
     (FUN_00006a0c((ulonglong)uVar2,0x7ff003f), (uVar3 & 0x7ff0000) != 0)) {
    FUN_000063f8((ulonglong)uVar2,6);
  }
  if (*(char *)((longlong)param_1 + 0x16) == '\x01') {
    FUN_0000a144(uVar2,param_3,uVar1 * uVar4);
  }
  FUN_00006794(uVar2,(short)uVar4);
  FUN_000067a8(uVar2,(ushort)uVar1);
  FUN_0000a284(param_1,(longlong)param_2,(ushort)uVar1);
  uVar3 = FUN_0000a3f4(param_1,param_2);
  if (uVar3 == 0) {
    DAT_00017a28 = 1 < uVar1;
    DAT_00017a40 = (param_2[9] >> 1 ^ 0xffffffff) & 1;
    DAT_00017a2c = uVar1 * uVar4;
    DAT_00017a30 = param_3;
    DAT_00017a38 = param_1;
  }
  else {
    thunk_FUN_000069f8((ulonglong)uVar2);
  }
  return uVar3;
}



void FUN_0000a888(void)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  uint *puVar4;
  uint local_68 [7];
  uint local_4c;
  undefined4 local_44;
  
  puVar4 = DAT_00017a38;
  uVar3 = DAT_00017a30;
  uVar2 = DAT_00017a2c;
  uVar1 = *DAT_00017a38;
  FUN_00006a0c((ulonglong)uVar1,2);
  if (DAT_00017a28 == '\x01') {
    local_44 = 0;
    local_68[0] = 0xc;
    local_68[1] = 0;
    local_68[2] = 1;
    local_4c = (uint)(DAT_00017a40 == 1);
    FUN_0000a3f4(puVar4,local_68);
  }
  if ((DAT_00017a40 == 0) && (*(char *)((longlong)puVar4 + 0x16) == '\x01')) {
    thunk_FUN_000042c8();
    FUN_00003f44(0,uVar3,uVar2);
    thunk_FUN_000042c8();
  }
  FUN_000063f8((ulonglong)uVar1,6);
  return;
}



uint thunk_FUN_0000a74c(uint *param_1,uint *param_2,ulonglong param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = *param_1;
  if (param_1[0x1b] == 0) {
    uVar4 = param_4 & 0xffff;
  }
  else {
    uVar4 = param_1[0xb];
  }
  uVar1 = param_4 & 0xffff;
  if (param_1[0x1b] == 0) {
    uVar1 = 1;
  }
  *(undefined1 *)((longlong)param_1 + 0x16) = *(undefined1 *)((longlong)param_1 + 5);
  uVar3 = FUN_000069f8((ulonglong)uVar2);
  if (((uVar3 & 0x7ff003f) != 0) &&
     (FUN_00006a0c((ulonglong)uVar2,0x7ff003f), (uVar3 & 0x7ff0000) != 0)) {
    FUN_000063f8((ulonglong)uVar2,6);
  }
  if (*(char *)((longlong)param_1 + 0x16) == '\x01') {
    FUN_0000a144(uVar2,param_3,uVar1 * uVar4);
  }
  FUN_00006794(uVar2,(short)uVar4);
  FUN_000067a8(uVar2,(ushort)uVar1);
  FUN_0000a284(param_1,(longlong)param_2,(ushort)uVar1);
  uVar3 = FUN_0000a3f4(param_1,param_2);
  if (uVar3 == 0) {
    DAT_00017a28 = 1 < uVar1;
    DAT_00017a40 = (param_2[9] >> 1 ^ 0xffffffff) & 1;
    DAT_00017a2c = uVar1 * uVar4;
    DAT_00017a30 = param_3;
    DAT_00017a38 = param_1;
  }
  else {
    thunk_FUN_000069f8((ulonglong)uVar2);
  }
  return uVar3;
}



uint FUN_0000a950(longlong *param_1,int param_2,ulonglong param_3,uint param_4,int param_5)

{
  uint uVar1;
  uint *puVar2;
  uint local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_4c;
  undefined4 local_44;
  
  if ((param_1 == (longlong *)0x0) || (puVar2 = (uint *)*param_1, puVar2 == (uint *)0x0)) {
    FUN_00004548(0x80000000,(byte *)"Invalid SDCC handle 0x%x");
    return 0x14;
  }
  if (3 < *puVar2) {
    FUN_00004548(0x80000000,(byte *)"Invalid drive number %d");
    return 0x14;
  }
  if (*(char *)(*(longlong *)(puVar2 + 0x30) + 0xd8) != '\0') {
    FUN_00004548(0x80000000,(byte *)"Slot %d state changed");
    return 0x1b;
  }
  uVar1 = puVar2[3];
  if (6 < uVar1) {
LAB_0000aa58:
    FUN_00004548(0x80000000,(byte *)"Operation not supported on SDIO card");
    return 0x10;
  }
  if ((1 << (ulonglong)(uVar1 & 0x1f) & 0x66U) == 0) {
    if (uVar1 == 0) {
      return 0x15;
    }
    goto LAB_0000aa58;
  }
  uVar1 = FUN_0000b440(param_1);
  if (uVar1 != 0) {
    return uVar1;
  }
  if (param_5 == 1) {
    local_68 = 0x18;
    if ((param_4 & 0xffff) != 1) {
      local_68 = 0x19;
    }
    local_44 = 1;
  }
  else {
    if (param_5 != 0) goto LAB_0000aa98;
    local_68 = 0x11;
    if ((param_4 & 0xffff) != 1) {
      local_68 = 0x12;
    }
    local_44 = 2;
  }
  local_4c = 0;
  local_60 = 1;
LAB_0000aa98:
  if (1 < puVar2[3] - 5) {
    param_2 = puVar2[0xb] * param_2;
  }
  local_64 = param_2;
  uVar1 = thunk_FUN_0000a74c(puVar2,&local_68,param_3,param_4);
  return uVar1;
}



uint FUN_0000aacc(longlong *param_1,undefined4 *param_2)

{
  uint uVar1;
  char *pcVar2;
  uint *puVar3;
  undefined2 local_278 [2];
  ushort local_274 [2];
  undefined4 local_270;
  undefined4 local_26c;
  undefined4 uStack_268;
  undefined4 local_254;
  undefined4 local_24c;
  longlong alStack_248 [63];
  undefined1 auStack_4a [10];
  
  auStack_4a._2_8_ = _data;
  if (((param_1 == (longlong *)0x0) || (param_2 == (undefined4 *)0x0)) ||
     (puVar3 = (uint *)*param_1, puVar3 == (uint *)0x0)) {
    FUN_00004548(0x80000000,(byte *)"rpmb_read_counter_pkt: Invalid Parameter. \n");
    uVar1 = 0x14;
    goto LAB_0000abec;
  }
  if ((puVar3[3] | 4) != 6) {
    FUN_00004548(0x80000000,(byte *)"rpmb_read_counter_pkt: Unknown Card Type \n");
    uVar1 = 0x15;
    goto LAB_0000abec;
  }
  uVar1 = FUN_0000b440(param_1);
  if (uVar1 == 0) {
    uVar1 = FUN_0000b520(puVar3,1);
    if (uVar1 == 0) {
      FUN_00004788(alStack_248,0x200,0);
      local_278[0] = 0x200;
      FUN_000047cc((undefined8 *)auStack_4a,(undefined8 *)local_278,2);
      local_26c = 0;
      uStack_268 = 1;
      local_254 = 0;
      local_24c = 1;
      local_270 = 0x19;
      uVar1 = thunk_FUN_00009d84(puVar3,(longlong)&local_270,(undefined4 *)alStack_248,1);
      if (uVar1 == 0) {
        uVar1 = FUN_0000b520(puVar3,1);
        if (uVar1 != 0) goto LAB_0000ab74;
        local_26c = 0;
        uStack_268 = 1;
        local_254 = 0;
        local_270 = 0x12;
        local_24c = 2;
        uVar1 = thunk_FUN_00009d84(puVar3,(longlong)&local_270,param_2,1);
        if (uVar1 == 0) {
          FUN_000047cc((undefined8 *)local_274,(undefined8 *)((longlong)param_2 + 0x1fe),2);
          local_274[0] = local_274[0] >> 8 | local_274[0] << 8;
          if (local_274[0] == 0x200) {
            FUN_000047cc((undefined8 *)local_274,(undefined8 *)(param_2 + 0x7f),2);
            local_274[0] = local_274[0] >> 8 | local_274[0] << 8;
            if (local_274[0] == 0) {
              uVar1 = 0;
            }
            else {
              FUN_00004548(0x80000000,(byte *)"rpmb_read_counter_pkt: Bad Result field = 0x%x \n");
              uVar1 = 0x20;
            }
          }
          else {
            FUN_00004548(0x80000000,(byte *)"rpmb_read_counter: Bad Response field = 0x%x \n");
            uVar1 = 0x1f;
          }
          goto LAB_0000abec;
        }
        pcVar2 = "rpmb_read_counter_pkt: sdcc_rpmb_do_transfer read failed";
      }
      else {
        pcVar2 = "rpmb_read_counter_pkt: sdcc_rpmb_do_transfer write failed";
      }
    }
    else {
LAB_0000ab74:
      pcVar2 = "rpmb_read_counter_pkt: Set Block Count failed";
    }
  }
  else {
    pcVar2 = "rpmb_read_counter_pkt: Failed to switch to RPMB partition \n";
  }
  FUN_00004548(0x80000000,(byte *)pcVar2);
LAB_0000abec:
  if (_data == auStack_4a._2_8_) {
    return uVar1;
  }
                    // WARNING: Subroutine does not return
  FUN_000010d8();
}



uint FUN_0000acf4(longlong *param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  longlong lVar2;
  char *pcVar3;
  uint *puVar4;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_4c;
  undefined4 local_44;
  
  lVar2 = FUN_0000404c((ulonglong)(param_3 << 9));
  if ((((param_1 == (longlong *)0x0) || (param_4 == (undefined4 *)0x0)) ||
      (param_2 == (undefined4 *)0x0)) || (puVar4 = (uint *)*param_1, puVar4 == (uint *)0x0)) {
    FUN_00004548(0x80000000,(byte *)"rpmb_read_sectors: Invalid Handle");
    return 0x14;
  }
  if ((puVar4[3] | 4) != 6) {
    FUN_00004548(0x80000000,(byte *)"rpmb_read_sectors: Unknown Card Type \n");
    return 0x15;
  }
  uVar1 = FUN_0000b440(param_1);
  if (uVar1 == 0) {
    FUN_0000b520(puVar4,1);
    local_64 = 0;
    local_60 = 1;
    local_4c = 0;
    local_44 = 1;
    local_68 = 0x19;
    uVar1 = thunk_FUN_00009d84(puVar4,(longlong)&local_68,param_2,1);
    if (uVar1 == 0) {
      uVar1 = FUN_0000b520(puVar4,param_3);
      if (uVar1 == 0) {
        local_4c = 0;
        local_68 = 0x12;
        local_64 = 0;
        local_60 = 1;
        local_44 = 2;
        uVar1 = thunk_FUN_00009d84(puVar4,(longlong)&local_68,param_4,param_3);
        if (uVar1 == 0) goto LAB_0000ae64;
        pcVar3 = "rpmb_read_sectors: sdcc_rpmb_do_transfer read failed \n";
      }
      else {
        pcVar3 = "rpmb_read_sectors: Set Block Count failed \n";
      }
    }
    else {
      pcVar3 = "rpmb_read_sectors: sdcc_rpmb_do_transfer write failed \n";
    }
  }
  else {
    pcVar3 = "rpmb_read_sectors: Failed to switch to RPMP partition \n";
  }
  FUN_00004548(0x80000000,(byte *)pcVar3);
LAB_0000ae64:
  if (lVar2 != 0) {
    FUN_00004100();
  }
  return uVar1;
}



uint FUN_0000ae74(longlong *param_1,longlong param_2,uint param_3,undefined8 param_4,
                 undefined4 *param_5)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  char *pcVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  undefined2 local_294 [2];
  undefined4 local_290;
  undefined4 local_28c;
  undefined4 local_288;
  undefined4 local_274;
  undefined4 local_26c;
  longlong alStack_268 [63];
  undefined8 uStack_6a;
  
  lVar2 = _data;
  if ((((param_1 == (longlong *)0x0) || (param_5 == (undefined4 *)0x0)) || (param_2 == 0)) ||
     (puVar5 = (uint *)*param_1, puVar5 == (uint *)0x0)) {
    FUN_00004548(0x80000000,(byte *)"rpmb_write_sectors: Invalid Handle");
    uVar3 = 0x14;
  }
  else if ((puVar5[3] | 4) == 6) {
    uVar3 = FUN_0000b440(param_1);
    if (uVar3 == 0) {
      if (DAT_00018400 == 0) {
        DAT_00018400 = puVar5[0xd];
        if (DAT_00018400 == 1) {
          DAT_00018400 = 2;
        }
      }
      uVar3 = 0;
      if (DAT_00018400 != 0) {
        uVar3 = param_3 / DAT_00018400;
      }
      uVar1 = DAT_00018400;
      if (param_3 != uVar3 * DAT_00018400) {
        uVar1 = 1;
      }
      uVar6 = -uVar1;
      uVar7 = 0;
      do {
        uVar6 = uVar6 + uVar1;
        if (param_3 <= uVar6) {
          uVar3 = FUN_0000b520(puVar5,1);
          if (uVar3 != 0) {
            pcVar4 = "rpmb_write_sectors: Set Block Count failed \n";
            goto LAB_0000b024;
          }
          FUN_00004788(alStack_268,0x200,0);
          local_294[0] = 0x500;
          FUN_000047cc(&uStack_6a,(undefined8 *)local_294,2);
          local_288 = 1;
          local_274 = 0;
          local_26c = 1;
          local_290 = 0x19;
          local_28c = 0;
          uVar3 = thunk_FUN_00009d84(puVar5,(longlong)&local_290,(undefined4 *)alStack_268,1);
          if (uVar3 == 0) {
            FUN_0000b520(puVar5,1);
            local_28c = 0;
            local_288 = 1;
            local_274 = 0;
            local_290 = 0x12;
            local_26c = 2;
            uVar3 = thunk_FUN_00009d84(puVar5,(longlong)&local_290,param_5,1);
            if (uVar3 == 0) goto LAB_0000af08;
            pcVar4 = "rpmb_write_sectors: failed sdcc_rpmb_do_transfer read \n";
            goto LAB_0000aee8;
          }
          break;
        }
        FUN_0000b520(puVar5,uVar1 | 0x80000000);
        local_288 = 1;
        local_274 = 0;
        local_26c = 1;
        local_290 = 0x19;
        local_28c = 0;
        uVar3 = thunk_FUN_00009d84(puVar5,(longlong)&local_290,
                                   (undefined4 *)(param_2 + (ulonglong)uVar7),uVar1);
        uVar7 = uVar7 + uVar1 * 0x200;
      } while (uVar3 == 0);
      pcVar4 = "rpmb_write_sectors: failed sdcc_rpmb_do_transfer write \n";
LAB_0000b024:
      FUN_00004548(0x80000000,(byte *)pcVar4);
    }
    else {
      pcVar4 = "rpmb_write_sectors: Failed to switch to RPMB partition \n";
LAB_0000aee8:
      FUN_00004548(0x80000000,(byte *)pcVar4);
    }
  }
  else {
    FUN_00004548(0x80000000,(byte *)"rpmb_write_sectors: Unknown Card Type \n");
    uVar3 = 0x15;
  }
LAB_0000af08:
  if (_data == lVar2) {
    return uVar3;
  }
                    // WARNING: Subroutine does not return
  FUN_000010d8();
}



undefined8 FUN_0000b0e8(undefined8 *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar2 = *(uint *)*param_1;
  if (uVar2 < 4) {
    FUN_0000694c(uVar2,1);
    FUN_000063d0(uVar2,'\0');
    FUN_00003f30(1000);
    FUN_000063d0(uVar2,'\x01');
    FUN_0000b668((uint *)*param_1,0);
    uVar1 = FUN_00003e68(uVar2);
    if ((uVar1 & 1) != 0) {
      uVar3 = FUN_000081ec(param_1);
      return uVar3;
    }
    uVar2 = FUN_00003e68(uVar2);
    if ((uVar2 >> 1 & 1) != 0) {
      uVar3 = FUN_0000be18(param_1);
      return uVar3;
    }
  }
  else {
    FUN_00004548(0x80000000,(byte *)"Invalid Drive Number:%d");
  }
  return 0;
}



undefined2 FUN_0000b19c(uint *param_1)

{
  uint local_38 [3];
  undefined2 local_2a;
  undefined4 local_1c;
  undefined4 local_14;
  
  local_1c = 0;
  local_14 = 0;
  local_38[0] = 3;
  local_38[2] = 1;
  if ((param_1[3] | 4) == 6) {
    local_38[1] = 0x20000;
    FUN_0000b868(param_1,local_38);
    local_2a = 2;
  }
  else {
    local_38[1] = 0;
    FUN_0000b868(param_1,local_38);
  }
  return local_2a;
}



uint FUN_0000b204(uint *param_1)

{
  undefined2 uVar1;
  uint uVar2;
  ulonglong uVar3;
  uint local_48 [3];
  undefined8 auStack_3c [2];
  undefined4 local_2c;
  undefined4 local_24;
  
  local_2c = 0;
  local_24 = 0;
  local_48[0] = 2;
  local_48[1] = 0;
  local_48[2] = 4;
  uVar2 = FUN_0000b868(param_1,local_48);
  if (uVar2 != 0) {
    return uVar2;
  }
  if ((param_1[3] | 4) == 6) {
    uVar3 = FUN_00009044(auStack_3c,(longlong)param_1);
    if ((uVar3 & 0xff) == 0) {
      return 0x14;
    }
  }
  else {
    uVar2 = FUN_0000c478((undefined4 *)auStack_3c,(longlong)param_1);
    if ((uVar2 & 0xff) == 0) {
      return 0x14;
    }
  }
  uVar1 = FUN_0000b19c(param_1);
  *(undefined2 *)(param_1 + 5) = uVar1;
  return 0;
}



ulonglong FUN_0000b2a8(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_4c;
  undefined4 local_44;
  
  uVar2 = *param_1;
  uVar1 = FUN_0000bd10(param_1,1);
  if (uVar1 != 0) {
    return (ulonglong)uVar1;
  }
  param_1[0x1b] = 1;
  param_1[4] = 2;
  local_60 = 1;
  local_68 = 0x10;
  local_64 = 0x200;
  local_4c = 0;
  local_44 = 0;
  uVar1 = FUN_0000b868(param_1,&local_68);
  uVar4 = (ulonglong)uVar1;
  if (uVar1 == 0) {
    param_1[0xb] = 0x200;
    FUN_00006794(*param_1,0x200);
  }
  switch(param_1[3]) {
  case 1:
  case 5:
    param_1[0xf] = 1;
    FUN_00004788((longlong *)&local_68,5,0);
    uVar1 = FUN_0000bf64(param_1,(byte *)&local_68);
    if (uVar1 != 0) {
      return (ulonglong)uVar1;
    }
    if ((char)local_64 == '\x05') {
      uVar2 = FUN_0000c3f8(param_1);
      if (uVar2 != 0) {
        return (ulonglong)uVar2;
      }
    }
    else {
      FUN_0000a3a4(uVar2,0);
    }
    uVar2 = FUN_0000c3ac(param_1);
    if (uVar2 != 0) {
      return (ulonglong)uVar2;
    }
    if (local_68._1_1_ != '\0') {
      FUN_0000c114(param_1);
    }
    uVar4 = 0;
    break;
  case 2:
  case 6:
    if (*(byte *)((longlong)param_1 + 0x71) < 4) {
      uVar2 = FUN_0000a3a4(uVar2,0);
      uVar4 = (ulonglong)uVar2;
      if (uVar2 != 0) {
        FUN_00004548(0x80000000,(byte *)"SDCC failed to configure bus width %d in SDHCi mode");
        return uVar4;
      }
    }
    else {
      uVar3 = FUN_00008674(param_1);
      uVar4 = uVar3 & 0xffffffff;
      if ((int)uVar3 != 0) {
        return uVar4;
      }
    }
  }
  uVar2 = FUN_0000b87c(param_1);
  if (uVar2 != 4) {
    uVar4 = 9;
  }
  return uVar4;
}



uint FUN_0000b440(longlong *param_1)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == (longlong *)0x0) {
    FUN_00004548(0x80000000,(byte *)"Invalid NULL handle");
    uVar2 = 0x14;
  }
  else {
    iVar1 = 0;
    if ((int)param_1[1] != -1) {
      iVar1 = (int)param_1[1];
    }
    uVar2 = 0;
    if (iVar1 != *(int *)(*param_1 + 8) || iVar1 == 2) {
      if ((*(uint *)(*param_1 + 0xc) | 4) == 6) {
        uVar2 = FUN_0000910c(param_1);
        return uVar2;
      }
      FUN_00004548(0x80000000,(byte *)"Set partition region not supported on card type %d");
      uVar2 = 0x16;
    }
  }
  return uVar2;
}



uint FUN_0000b4c0(longlong param_1,uint *param_2)

{
  uint uVar1;
  uint local_48;
  int iStack_44;
  undefined4 local_40;
  undefined4 local_2c;
  undefined4 local_24;
  
  local_2c = 0;
  local_24 = 0;
  local_40 = 1;
  iStack_44 = (uint)*(ushort *)(param_1 + 0x14) << 0x10;
  local_48 = 0x37;
  FUN_0000b868((uint *)param_1,&local_48);
  uVar1 = FUN_0000b868((uint *)param_1,param_2);
  return uVar1;
}



uint thunk_FUN_00009d84(uint *param_1,longlong param_2,undefined4 *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint auStack_90 [7];
  uint uStack_74;
  undefined4 uStack_6c;
  uint uStack_64;
  
  uVar2 = *param_1;
  uStack_64 = 0;
  if (param_1[0x1b] == 0) {
    uVar7 = param_4 & 0xffff;
  }
  else {
    uVar7 = param_1[0xb];
  }
  uVar1 = param_4 & 0xffff;
  if (param_1[0x1b] == 0) {
    uVar1 = 1;
  }
  *(undefined1 *)((longlong)param_1 + 0x16) = *(undefined1 *)((longlong)param_1 + 5);
  uVar4 = uVar1 * uVar7;
  uVar6 = FUN_000069f8((ulonglong)uVar2);
  uStack_64 = uVar6;
  if (((uVar6 & 0x7ff003f) != 0) &&
     (FUN_00006a0c((ulonglong)uVar2,0x7ff003f), (uVar6 & 0x7ff0000) != 0)) {
    FUN_000063f8((ulonglong)uVar2,6);
  }
  if (*(char *)((longlong)param_1 + 0x16) == '\x01') {
    FUN_0000a144(uVar2,(ulonglong)param_3,uVar4);
  }
  FUN_00006794(uVar2,(short)uVar7);
  FUN_000067a8(uVar2,(ushort)uVar1);
  FUN_0000a284(param_1,param_2,(ushort)uVar1);
  if ((*(byte *)(param_2 + 0x24) >> 2 & 1) == 0) {
    uVar7 = FUN_0000b868(param_1,(uint *)param_2);
  }
  else {
    uVar7 = FUN_0000b4c0((longlong)param_1,param_2);
  }
  if (uVar7 != 0) {
LAB_00009e94:
    thunk_FUN_000069f8((ulonglong)uVar2);
    FUN_000063f8((ulonglong)uVar2,2);
    FUN_000063f8((ulonglong)uVar2,4);
    FUN_00006a0c((ulonglong)uVar2,0x7ff003f);
    return uVar7;
  }
  if (*(char *)((longlong)param_1 + 0x16) == '\0') {
    uVar6 = *param_1;
    auStack_90[0] = 0;
    if (param_1[0x1b] == 1) {
      uVar7 = param_1[0xb];
      uVar9 = 0;
      if (uVar7 != 0) {
        uVar9 = uVar4 / uVar7;
      }
    }
    else {
      uVar9 = 1;
      uVar7 = uVar4;
    }
    if ((*(uint *)(param_2 + 0x24) >> 1 & 1) == 0) {
      if ((*(uint *)(param_2 + 0x24) & 1) == 0) {
        uVar7 = 1;
        goto LAB_00009e94;
      }
      uVar12 = 0x10;
    }
    else {
      uVar12 = 0x20;
    }
    uVar3 = uVar7 + 3 >> 2;
    puVar11 = param_3;
    do {
      bVar5 = FUN_0000a304(uVar6,uVar12,auStack_90);
      uVar7 = (uint)bVar5;
      if (bVar5 != 0) {
        *(uint *)(param_2 + 0x20) = auStack_90[0];
        goto LAB_00009e94;
      }
      FUN_00006a0c((ulonglong)uVar6,uVar12);
      if ((*(uint *)(param_2 + 0x24) >> 1 & 1) == 0) {
        if ((*(uint *)(param_2 + 0x24) & 1) != 0) {
          puVar10 = puVar11;
          for (uVar7 = 0; uVar7 != uVar3; uVar7 = uVar7 + 1) {
            FUN_00006884(uVar6,*puVar10);
            puVar10 = puVar10 + 1;
          }
          puVar11 = puVar11 + uVar3;
        }
      }
      else {
        puVar10 = puVar11;
        for (uVar7 = 0; uVar7 != uVar3; uVar7 = uVar7 + 1) {
          uVar8 = FUN_00006870((ulonglong)uVar6);
          *puVar10 = uVar8;
          puVar10 = puVar10 + 1;
        }
        puVar11 = puVar11 + uVar3;
      }
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
    uVar7 = 2;
  }
  else {
    uVar7 = 0x2000002;
  }
  bVar5 = FUN_0000a304(uVar2,uVar7,&uStack_64);
  uVar7 = (uint)bVar5;
  if (bVar5 != 0) {
    *(uint *)(param_2 + 0x20) = uStack_64;
    if ((*(char *)((longlong)param_1 + 0x16) == '\0') || ((uStack_64 >> 0x19 & 1) == 0)) {
      if ((uStack_64 & 0x300000) != 0) {
        if ((*(char *)((longlong)param_1 + 0xc9) == '\0') ||
           (*(char *)((longlong)param_1 + 0xca) != '\0')) {
          uVar7 = 3;
        }
        else {
          uVar7 = 3;
          *(undefined1 *)((longlong)param_1 + 0xcb) = 0;
        }
      }
    }
    else {
      FUN_00004548(0x80000000,(byte *)"SDCC: DATA ADMA ERROR %d\n");
      uVar7 = 0xc;
    }
    goto LAB_00009e94;
  }
  if ((uStack_64 >> 1 & 1) != 0) {
    FUN_00006a0c((ulonglong)uVar2,2);
    uVar7 = *(uint *)(param_2 + 0x24);
    if (((uVar7 >> 2 & 1) == 0) && ((uVar2 != 0 || (param_1[2] != 3)))) {
      if (1 < uVar1) {
        uStack_6c = 0;
        uStack_74 = uVar7 & 1;
        auStack_90[0] = 0xc;
        auStack_90[1] = 0;
        auStack_90[2] = 1;
        uVar7 = FUN_0000b868(param_1,auStack_90);
        if ((auStack_90[3] >> 0x1a & 1) != 0) {
          return 0x1d;
        }
        goto LAB_0000a0f8;
      }
      if ((uVar7 & 1) != 0) {
        uVar7 = FUN_0000b55c((longlong)param_1);
        goto LAB_0000a0f8;
      }
    }
  }
  uVar7 = 0;
LAB_0000a0f8:
  if (((*(byte *)(param_2 + 0x24) >> 1 & 1) != 0) && (*(char *)((longlong)param_1 + 0x16) == '\x01')
     ) {
    thunk_FUN_000042c8();
    FUN_00003f44(0,(ulonglong)param_3,uVar4);
    thunk_FUN_000042c8();
  }
  FUN_000063f8((ulonglong)uVar2,6);
  return uVar7;
}



uint FUN_0000b520(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  uint local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 local_1c;
  undefined4 local_14;
  
  local_1c = 0;
  local_14 = 0;
  local_38 = 0x17;
  local_30 = 1;
  uStack_34 = param_2;
  uVar1 = FUN_0000b868(param_1,&local_38);
  return uVar1;
}



uint thunk_FUN_00009d84(uint *param_1,longlong param_2,undefined4 *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint auStack_90 [7];
  uint uStack_74;
  undefined4 uStack_6c;
  uint uStack_64;
  
  uVar2 = *param_1;
  uStack_64 = 0;
  if (param_1[0x1b] == 0) {
    uVar7 = param_4 & 0xffff;
  }
  else {
    uVar7 = param_1[0xb];
  }
  uVar1 = param_4 & 0xffff;
  if (param_1[0x1b] == 0) {
    uVar1 = 1;
  }
  *(undefined1 *)((longlong)param_1 + 0x16) = *(undefined1 *)((longlong)param_1 + 5);
  uVar4 = uVar1 * uVar7;
  uVar6 = FUN_000069f8((ulonglong)uVar2);
  uStack_64 = uVar6;
  if (((uVar6 & 0x7ff003f) != 0) &&
     (FUN_00006a0c((ulonglong)uVar2,0x7ff003f), (uVar6 & 0x7ff0000) != 0)) {
    FUN_000063f8((ulonglong)uVar2,6);
  }
  if (*(char *)((longlong)param_1 + 0x16) == '\x01') {
    FUN_0000a144(uVar2,(ulonglong)param_3,uVar4);
  }
  FUN_00006794(uVar2,(short)uVar7);
  FUN_000067a8(uVar2,(ushort)uVar1);
  FUN_0000a284(param_1,param_2,(ushort)uVar1);
  if ((*(byte *)(param_2 + 0x24) >> 2 & 1) == 0) {
    uVar7 = FUN_0000b868(param_1,(uint *)param_2);
  }
  else {
    uVar7 = FUN_0000b4c0((longlong)param_1,param_2);
  }
  if (uVar7 != 0) {
LAB_00009e94:
    thunk_FUN_000069f8((ulonglong)uVar2);
    FUN_000063f8((ulonglong)uVar2,2);
    FUN_000063f8((ulonglong)uVar2,4);
    FUN_00006a0c((ulonglong)uVar2,0x7ff003f);
    return uVar7;
  }
  if (*(char *)((longlong)param_1 + 0x16) == '\0') {
    uVar6 = *param_1;
    auStack_90[0] = 0;
    if (param_1[0x1b] == 1) {
      uVar7 = param_1[0xb];
      uVar9 = 0;
      if (uVar7 != 0) {
        uVar9 = uVar4 / uVar7;
      }
    }
    else {
      uVar9 = 1;
      uVar7 = uVar4;
    }
    if ((*(uint *)(param_2 + 0x24) >> 1 & 1) == 0) {
      if ((*(uint *)(param_2 + 0x24) & 1) == 0) {
        uVar7 = 1;
        goto LAB_00009e94;
      }
      uVar12 = 0x10;
    }
    else {
      uVar12 = 0x20;
    }
    uVar3 = uVar7 + 3 >> 2;
    puVar11 = param_3;
    do {
      bVar5 = FUN_0000a304(uVar6,uVar12,auStack_90);
      uVar7 = (uint)bVar5;
      if (bVar5 != 0) {
        *(uint *)(param_2 + 0x20) = auStack_90[0];
        goto LAB_00009e94;
      }
      FUN_00006a0c((ulonglong)uVar6,uVar12);
      if ((*(uint *)(param_2 + 0x24) >> 1 & 1) == 0) {
        if ((*(uint *)(param_2 + 0x24) & 1) != 0) {
          puVar10 = puVar11;
          for (uVar7 = 0; uVar7 != uVar3; uVar7 = uVar7 + 1) {
            FUN_00006884(uVar6,*puVar10);
            puVar10 = puVar10 + 1;
          }
          puVar11 = puVar11 + uVar3;
        }
      }
      else {
        puVar10 = puVar11;
        for (uVar7 = 0; uVar7 != uVar3; uVar7 = uVar7 + 1) {
          uVar8 = FUN_00006870((ulonglong)uVar6);
          *puVar10 = uVar8;
          puVar10 = puVar10 + 1;
        }
        puVar11 = puVar11 + uVar3;
      }
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
    uVar7 = 2;
  }
  else {
    uVar7 = 0x2000002;
  }
  bVar5 = FUN_0000a304(uVar2,uVar7,&uStack_64);
  uVar7 = (uint)bVar5;
  if (bVar5 != 0) {
    *(uint *)(param_2 + 0x20) = uStack_64;
    if ((*(char *)((longlong)param_1 + 0x16) == '\0') || ((uStack_64 >> 0x19 & 1) == 0)) {
      if ((uStack_64 & 0x300000) != 0) {
        if ((*(char *)((longlong)param_1 + 0xc9) == '\0') ||
           (*(char *)((longlong)param_1 + 0xca) != '\0')) {
          uVar7 = 3;
        }
        else {
          uVar7 = 3;
          *(undefined1 *)((longlong)param_1 + 0xcb) = 0;
        }
      }
    }
    else {
      FUN_00004548(0x80000000,(byte *)"SDCC: DATA ADMA ERROR %d\n");
      uVar7 = 0xc;
    }
    goto LAB_00009e94;
  }
  if ((uStack_64 >> 1 & 1) != 0) {
    FUN_00006a0c((ulonglong)uVar2,2);
    uVar7 = *(uint *)(param_2 + 0x24);
    if (((uVar7 >> 2 & 1) == 0) && ((uVar2 != 0 || (param_1[2] != 3)))) {
      if (1 < uVar1) {
        uStack_6c = 0;
        uStack_74 = uVar7 & 1;
        auStack_90[0] = 0xc;
        auStack_90[1] = 0;
        auStack_90[2] = 1;
        uVar7 = FUN_0000b868(param_1,auStack_90);
        if ((auStack_90[3] >> 0x1a & 1) != 0) {
          return 0x1d;
        }
        goto LAB_0000a0f8;
      }
      if ((uVar7 & 1) != 0) {
        uVar7 = FUN_0000b55c((longlong)param_1);
        goto LAB_0000a0f8;
      }
    }
  }
  uVar7 = 0;
LAB_0000a0f8:
  if (((*(byte *)(param_2 + 0x24) >> 1 & 1) != 0) && (*(char *)((longlong)param_1 + 0x16) == '\x01')
     ) {
    thunk_FUN_000042c8();
    FUN_00003f44(0,(ulonglong)param_3,uVar4);
    thunk_FUN_000042c8();
  }
  FUN_000063f8((ulonglong)uVar2,6);
  return uVar7;
}



undefined4 FUN_0000b55c(longlong param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint local_78;
  int iStack_74;
  undefined4 local_70;
  uint local_6c;
  undefined4 local_5c;
  undefined4 local_54;
  
  local_5c = 0;
  uVar2 = 0;
  local_54 = 0;
  uVar4 = 9;
  local_70 = 1;
  iStack_74 = (uint)*(ushort *)(param_1 + 0x14) << 0x10;
  local_78 = 0xd;
  for (uVar3 = 0; uVar3 < 5000000; uVar3 = uVar3 + 10) {
    uVar1 = FUN_0000b868((uint *)param_1,&local_78);
    if (uVar1 == 0) {
      if ((local_6c & 0x4000000) != 0) {
        uVar2 = 0x1d;
      }
      uVar4 = local_6c >> 9 & 0xf;
      if (uVar4 == 4) break;
    }
    FUN_00003f30(10);
  }
  if (uVar4 != 4) {
    uVar2 = 8;
  }
  return uVar2;
}



longlong FUN_0000b620(uint param_1)

{
  if (param_1 < 4) {
    return (ulonglong)param_1 * 0xe8 + 0x18048;
  }
  FUN_00004548(0x80000000,(byte *)"Invalid Drive Number:%d");
  return 0;
}



void FUN_0000b668(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar1 = *param_1;
  uVar2 = 20000000;
  uVar6 = 20000000;
  uVar5 = param_1[3];
  uVar3 = FUN_00003ef4(uVar1);
  uVar7 = uVar2;
  switch(param_2) {
  case 0:
    param_1[0x1e] = 2;
    uVar7 = 400000;
    break;
  case 4:
    if ((uVar5 | 4) == 5) {
      param_1[0x1e] = 1;
    }
    else if ((uVar5 | 4) == 6) {
      param_1[0x1e] = 4;
    }
  case 1:
  case 2:
  case 3:
    if ((uVar5 | 4) == 5) {
      uVar7 = 50000000;
      if (param_1[0x1e] != 1) {
        uVar7 = 25000000;
      }
    }
    else {
      uVar7 = uVar6;
      if ((uVar5 | 4) == 6) {
        uVar5 = 25000000;
        if (param_1[0x1e] != 3) {
          uVar5 = uVar2;
        }
        uVar7 = 50000000;
        if (param_1[0x1e] != 4) {
          uVar7 = uVar5;
        }
      }
    }
    break;
  case 6:
    uVar7 = uVar6;
    if (((uVar5 | 4) == 6) && (param_1[0x1e] == 4)) {
      uVar7 = 100000000;
    }
    break;
  case 7:
    uVar7 = uVar6;
    if (((uVar5 | 4) == 6) && (param_1[0x1e] == 5)) {
      uVar4 = FUN_00003f18();
      uVar7 = (uint)uVar4;
    }
    break;
  case 8:
    if (((uVar5 | 4) == 6) && (uVar7 = uVar6, param_1[0x1e] == 6)) {
      uVar4 = FUN_00003f24();
      uVar7 = (uint)uVar4;
    }
  }
  if (uVar3 < uVar7) {
    FUN_00004548(0x80000000,
                 (byte *)"sdcc_config_clk: WARNING!! SDCC mclk exceeds max supported clock.\n");
    FUN_00004548(0x80000000,(byte *)"Lower SDCC mclk to max supported clock: %d \n");
    uVar7 = uVar3;
  }
  if (uVar1 == 0) {
    FUN_0000f8bc(0,uVar7);
    FUN_00009c40(0,0);
    param_1[0x2d] = uVar7 / 1000;
    return;
  }
  uVar5 = param_1[0x2d];
  if (uVar5 == 0) {
    FUN_0000f8bc(uVar1,uVar3);
    uVar5 = uVar3 / 1000;
    param_1[0x2d] = uVar5;
  }
  uVar2 = 0;
  if (uVar7 << 1 != 0) {
    uVar2 = (uVar5 * 1000) / (uVar7 << 1);
  }
  FUN_00009c40(uVar1,uVar2);
  return;
}



uint FUN_0000b868(uint *param_1,uint *param_2)

{
  uint uVar1;
  
  if ((param_1 != (uint *)0x0) && (param_2 != (uint *)0x0)) {
    uVar1 = FUN_0000a3f4(param_1,param_2);
    return uVar1;
  }
  return 0x14;
}



uint FUN_0000b87c(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint local_38;
  int iStack_34;
  undefined4 local_30;
  uint local_2c;
  undefined4 local_1c;
  undefined4 local_14;
  
  local_1c = 0;
  local_14 = 0;
  local_30 = 1;
  iStack_34 = (uint)(ushort)param_1[5] << 0x10;
  local_38 = 0xd;
  uVar2 = FUN_0000b868(param_1,&local_38);
  uVar1 = local_2c >> 9 & 0xf;
  if (uVar2 != 0) {
    uVar1 = 9;
  }
  return uVar1;
}



undefined8 FUN_0000b8d0(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  
  uVar3 = 0;
  uVar1 = *param_1;
  do {
    if (param_2 <= uVar3) {
      uVar3 = FUN_0000b87c(param_1);
      if (uVar3 == 4) {
LAB_0000b940:
        uVar4 = 0;
      }
      else {
        uVar4 = 7;
      }
      return uVar4;
    }
    uVar2 = FUN_000069f8((ulonglong)uVar1);
    if ((uVar2 >> 1 & 1) != 0) {
      FUN_00006a0c((ulonglong)uVar1,2);
      goto LAB_0000b940;
    }
    FUN_00003f30(10);
    uVar3 = uVar3 + 10;
  } while( true );
}



undefined8 FUN_0000b958(longlong param_1)

{
  uint uVar1;
  uint *puVar2;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    puVar2 = *(uint **)(param_1 + 0xc0);
    if ((char)puVar2[1] != '\0') {
      uVar1 = *puVar2;
      FUN_0000694c(uVar1,0);
      FUN_00003ea8((ulonglong)uVar1);
      FUN_0000f81c(uVar1);
      *(undefined1 *)(puVar2 + 1) = 0;
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0xb4) = 0;
  }
  return 0;
}



uint FUN_0000b9c4(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte local_80;
  byte local_7f;
  byte local_7e;
  byte local_7d;
  char local_7c;
  byte local_78;
  uint local_70;
  byte local_68;
  byte local_67;
  byte local_66;
  byte local_65;
  char local_64;
  byte local_62;
  undefined1 local_5d;
  uint local_58;
  int iStack_54;
  undefined4 local_50;
  uint local_4c;
  uint local_48;
  ushort local_42;
  undefined4 local_3c;
  undefined4 local_34;
  
  uVar3 = FUN_0000b87c(param_1);
  if (uVar3 != 3) {
    return 9;
  }
  local_3c = 0;
  local_34 = 0;
  local_50 = 4;
  iStack_54 = (uint)(ushort)param_1[5] << 0x10;
  local_58 = 9;
  uVar3 = FUN_0000b868(param_1,&local_58);
  if (uVar3 != 0) {
    return uVar3;
  }
  FUN_00004788((longlong *)&local_80,0x28,0);
  FUN_00004788((longlong *)&DAT_000177a4,0x10,0);
  FUN_000047cc((undefined8 *)&DAT_000177a4,(undefined8 *)&local_4c,0x10);
  local_80 = (byte)(local_4c >> 0x1e);
  if ((param_1[3] | 4) == 5) {
    if (local_4c >> 0x1e == 1) {
      local_7d = 0;
      local_7c = (char)local_4c;
      local_78 = 9;
      local_70 = (uint)local_42 | (local_48 & 0x3f) << 0x10;
      local_7e = 0xe;
      local_62 = 2;
    }
    else {
      FUN_0000bd6c((longlong)param_1,&local_4c,(longlong)&local_80);
    }
  }
  else {
    FUN_0000bd6c((longlong)param_1,&local_4c,(longlong)&local_80);
    *(byte *)((longlong)param_1 + 0x71) = local_7f;
    if ((local_7f < 3) || (local_64 == '\0')) {
      *(undefined1 *)(param_1 + 0x1d) = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x1d) = 1;
      *(undefined1 *)(param_1 + 0x2a) = local_5d;
      param_1[10] = ((uint)local_65 * 0x200 + 0x200) * (local_67 + 1) * (local_66 + 1) >> 9;
    }
    if (2 < local_7f) {
      param_1[0x1a] = (local_66 + 1) * (local_67 + 1);
    }
  }
  uVar3 = 50000;
  if (param_1[0x2d] != 0) {
    uVar3 = param_1[0x2d];
  }
  uVar1 = param_1[3];
  if (uVar1 - 1 < 5) {
    iVar4 = *(int *)(&DAT_00014700 + (longlong)(int)(uVar1 - 1) * 4);
  }
  else {
    iVar4 = 10;
  }
  uVar2 = 0;
  if (uVar3 != 0) {
    uVar2 = ((((uVar3 / 100) *
              ((uint)(*(int *)(&DAT_000146e0 + (ulonglong)(local_7e & 7) * 4) *
                     *(int *)(&DAT_000146a0 + (ulonglong)(local_7e >> 3 & 0xf) * 4)) / 100)) / 1000
             + (uint)local_7d * 100) * iVar4) / uVar3;
  }
  uVar3 = uVar2 << (ulonglong)(local_62 & 0x1f);
  param_1[0x28] = uVar2;
  param_1[0x29] = uVar3;
  if (uVar1 == 6) {
    uVar3 = 2;
    if (local_7c == '2') {
      uVar3 = 3;
    }
    param_1[0x1e] = uVar3;
    return 0;
  }
  if (uVar1 == 5) {
LAB_0000bc18:
    param_1[0x28] = 100;
  }
  else {
    if (uVar1 != 1) goto LAB_0000bc74;
    if (100 < uVar2) goto LAB_0000bc18;
  }
  if ((uVar1 == 5) || (0xfa < uVar3)) {
    param_1[0x29] = 0xfa;
  }
  if ((uVar1 | 4) == 5) {
    if (local_80 == 1) {
      uVar3 = (uint)(1L << ((ulonglong)local_78 & 0x3f));
      param_1[0xb] = uVar3;
      param_1[9] = (local_70 + 1) * (uVar3 & 0x3fffff) * 2;
    }
    else {
      FUN_0000bcdc((longlong)param_1,(uint)local_78,(uint)local_68,local_70);
    }
    param_1[0x1e] = 0;
    return 0;
  }
LAB_0000bc74:
  FUN_0000bcdc((longlong)param_1,(uint)local_78,(uint)local_68,local_70);
  uVar3 = 2;
  if (local_7c == '2') {
    uVar3 = 3;
  }
  param_1[0x1e] = uVar3;
  return 0;
}



void FUN_0000bcdc(longlong param_1,uint param_2,uint param_3,int param_4)

{
  ulonglong uVar1;
  
  uVar1 = 1L << ((ulonglong)param_2 & 0x3f);
  *(int *)(param_1 + 0x2c) = (int)uVar1;
  *(uint *)(param_1 + 0x24) =
       (param_4 + 1) * (int)(4L << ((ulonglong)(param_3 & 0xff) & 0x3f)) *
       ((uint)(uVar1 >> 9) & 0x7fffff);
  return;
}



uint FUN_0000bd10(uint *param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  uint local_48;
  uint uStack_44;
  undefined4 local_40;
  undefined4 local_2c;
  undefined4 local_24;
  
  uStack_44 = (uint)param_2;
  if (param_2 != 0) {
    uStack_44 = (uint)(ushort)param_1[5] << 0x10;
  }
  local_2c = 0;
  local_24 = 0;
  local_48 = 7;
  local_40 = 1;
  uVar2 = FUN_0000b868(param_1,&local_48);
  uVar1 = 0;
  if (param_2 != 0) {
    uVar1 = uVar2;
  }
  return uVar1;
}



void FUN_0000bd6c(longlong param_1,undefined4 *param_2,longlong param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  
  if (param_3 != 0) {
    uVar1 = *param_2;
    if ((*(uint *)(param_1 + 0xc) | 4) == 6) {
      *(byte *)(param_3 + 1) = (byte)((uint)uVar1 >> 0x1a) & 0xf;
    }
    *(char *)(param_3 + 4) = (char)uVar1;
    *(char *)(param_3 + 2) = (char)((uint)uVar1 >> 0x10);
    *(char *)(param_3 + 3) = (char)((uint)uVar1 >> 8);
    uVar2 = param_2[1];
    *(byte *)(param_3 + 8) = (byte)(uVar2 >> 0x10) & 0xf;
    uVar3 = param_2[2];
    *(uint *)(param_3 + 0x10) = uVar3 >> 0x1e | (uVar2 & 0x3ff) << 2;
    *(byte *)(param_3 + 0x18) = (byte)(uVar3 >> 0xf) & 7;
    if (((*(uint *)(param_1 + 0xc) | 4) == 6) && (2 < *(byte *)(param_3 + 1))) {
      *(byte *)(param_3 + 0x19) = (byte)(uVar3 >> 10) & 0x1f;
      *(byte *)(param_3 + 0x1a) = (byte)(uVar3 >> 5) & 0x1f;
      *(byte *)(param_3 + 0x1b) = (byte)uVar3 & 0x1f;
    }
    uVar2 = param_2[3];
    bVar4 = (byte)(uVar2 >> 0x18);
    *(byte *)(param_3 + 0x1c) = bVar4 >> 7;
    *(byte *)(param_3 + 0x1e) = bVar4 >> 2 & 7;
    *(byte *)(param_3 + 0x23) = (byte)(uVar2 >> 0xd) & 1;
  }
  return;
}



undefined8 FUN_0000be18(undefined8 *param_1)

{
  uint uVar1;
  uint *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint local_78;
  undefined4 local_74;
  undefined4 local_70;
  uint local_6c;
  undefined4 local_5c;
  undefined4 local_54;
  
  local_78 = 0;
  puVar2 = (uint *)*param_1;
  local_74 = 0;
  local_70 = 0;
  local_5c = 0;
  local_54 = 0;
  FUN_0000b868(puVar2,&local_78);
  uVar4 = 0;
  do {
    if (2 < uVar4) {
      uVar3 = 0xff8000;
LAB_0000bebc:
      uVar4 = 0;
      while( true ) {
        if (199 < uVar4) {
          return 0;
        }
        local_78 = 0x37;
        local_74 = 0;
        local_70 = 1;
        local_5c = 0;
        local_54 = 0;
        uVar1 = FUN_0000b868(puVar2,&local_78);
        if (uVar1 != 0) {
          return 0;
        }
        local_78 = 0x29;
        local_70 = 1;
        local_5c = 0;
        local_54 = 0;
        local_74 = uVar3;
        uVar1 = FUN_0000b868(puVar2,&local_78);
        if (uVar1 != 0) {
          return 0;
        }
        if ((int)local_6c < 0) break;
        FUN_00003f30(5000);
        uVar4 = uVar4 + 1;
      }
      if ((local_6c >> 0x1e & 1) != 0) {
        return 5;
      }
      return 1;
    }
    local_78 = 8;
    local_74 = 0x1aa;
    local_70 = 1;
    local_5c = 0;
    local_54 = 0;
    uVar1 = FUN_0000b868(puVar2,&local_78);
    if (uVar1 == 0) {
      if (local_6c != 0x1aa) {
        return 0;
      }
      uVar3 = 0x40ff8000;
      goto LAB_0000bebc;
    }
    FUN_00003f30(1000);
    uVar4 = uVar4 + 1;
  } while( true );
}



uint FUN_0000bf64(uint *param_1,byte *param_2)

{
  uint uVar1;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 local_3c;
  undefined4 local_34;
  
  FUN_00004788((longlong *)&DAT_000177b4,8,0);
  local_3c = 0;
  local_58 = 0x33;
  uStack_54 = 0;
  local_50 = 1;
  local_34 = 6;
  param_1[0x1b] = 0;
  uVar1 = thunk_FUN_00009d84(param_1,(longlong)&local_58,(undefined4 *)&DAT_000177b4,8);
  param_1[0x1b] = 1;
  if (uVar1 == 0) {
    FUN_0000c000(&DAT_000177b4,param_2);
  }
  return uVar1;
}



undefined8 FUN_0000c000(byte *param_1,byte *param_2)

{
  byte bVar1;
  
  if (param_2 != (byte *)0x0) {
    bVar1 = *param_1;
    *param_2 = bVar1 >> 4;
    param_2[1] = bVar1 & 0xf;
    bVar1 = param_1[1];
    param_2[2] = bVar1 >> 7;
    param_2[3] = bVar1 >> 4 & 7;
    param_2[4] = bVar1 & 0xf;
    return 1;
  }
  return 0;
}



uint FUN_0000c044(uint *param_1,byte *param_2)

{
  uint uVar1;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 local_3c;
  undefined4 local_34;
  
  FUN_00004788((longlong *)&DAT_000177b4,0x40,0);
  local_3c = 0;
  local_58 = 0xd;
  uStack_54 = 0;
  local_50 = 1;
  local_34 = 6;
  param_1[0x1b] = 0;
  uVar1 = thunk_FUN_00009d84(param_1,(longlong)&local_58,(undefined4 *)&DAT_000177b4,0x40);
  param_1[0x1b] = 1;
  if (uVar1 == 0) {
    FUN_0000c0e0(&DAT_000177b4,param_2);
  }
  return uVar1;
}



undefined8 FUN_0000c0e0(byte *param_1,byte *param_2)

{
  if (param_2 != (byte *)0x0) {
    *param_2 = *param_1 >> 6;
    param_2[8] = param_1[8];
    param_2[10] = param_1[10] >> 4;
    return 1;
  }
  return 0;
}



uint FUN_0000c114(uint *param_1)

{
  uint uVar1;
  char *pcVar2;
  undefined8 local_80;
  char local_72;
  char local_6c;
  short local_6a;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_3c;
  undefined4 local_34;
  
  FUN_00004788((longlong *)&DAT_000177b4,0x40,0);
  local_3c = 0;
  local_58 = 6;
  local_54 = 0xffff01;
  local_50 = 1;
  local_34 = 2;
  param_1[0x1b] = 0;
  uVar1 = thunk_FUN_00009d84(param_1,(longlong)&local_58,(undefined4 *)&DAT_000177b4,0x40);
  param_1[0x1b] = 1;
  if (uVar1 != 0) {
    return uVar1;
  }
  FUN_0000c2e4(&DAT_000177b4,(short *)&local_80);
  if (((short)local_80 != 0) && ((local_6c != '\x01' || (local_6a != 2)))) {
    if ((local_80._2_2_ != -0x7ffd) || (local_72 != '\x01')) {
      return 0;
    }
    FUN_00004788((longlong *)&DAT_000177b4,0x40,0);
    FUN_00004788(&local_80,0x22,0);
    local_54 = 0x80ffff01;
    local_34 = 2;
    param_1[0x1b] = 0;
    uVar1 = thunk_FUN_00009d84(param_1,(longlong)&local_58,(undefined4 *)&DAT_000177b4,0x40);
    param_1[0x1b] = 1;
    if (uVar1 != 0) {
      return uVar1;
    }
    FUN_0000c2e4(&DAT_000177b4,(short *)&local_80);
    if (((short)local_80 == 0) || (local_72 != '\x01')) {
      pcVar2 = "Failed in switching to high speed func\n";
    }
    else {
      if ((local_6c != '\x01') || (local_6a != 2)) {
        FUN_00006b2c(*param_1,1);
        FUN_00006c9c(*param_1,2);
        FUN_00003f30(1000);
        param_1[0x1e] = 1;
        FUN_0000b668(param_1,1);
        return 0;
      }
      pcVar2 = "Switch: High speed func is busy\n";
    }
    FUN_00004548(0x80000000,(byte *)pcVar2);
  }
  return 1;
}



undefined8 FUN_0000c2e4(byte *param_1,short *param_2)

{
  byte bVar1;
  short *psVar2;
  byte *pbVar3;
  byte *pbVar4;
  longlong lVar5;
  
  if (param_2 != (short *)0x0) {
    bVar1 = *param_1;
    *param_2 = (ushort)bVar1 << 8;
    *param_2 = CONCAT11(bVar1,param_1[1]);
    psVar2 = param_2 + 6;
    pbVar4 = param_1 + 3;
    for (lVar5 = 5; -1 < lVar5; lVar5 = lVar5 + -1) {
      bVar1 = pbVar4[-1];
      *psVar2 = (ushort)bVar1 << 8;
      *psVar2 = CONCAT11(bVar1,*pbVar4);
      psVar2 = psVar2 + -1;
      pbVar4 = pbVar4 + 2;
    }
    pbVar4 = (byte *)((longlong)param_2 + 0x13);
    pbVar3 = param_1 + 0xe;
    for (lVar5 = 0xe; lVar5 != 0x11; lVar5 = lVar5 + 1) {
      bVar1 = *pbVar3;
      *pbVar4 = bVar1 >> 4;
      pbVar4[-1] = bVar1 & 0xf;
      pbVar4 = pbVar4 + -2;
      pbVar3 = pbVar3 + 1;
    }
    *(byte *)(param_2 + 10) = param_1[0x11];
    pbVar4 = param_1 + 0x13;
    psVar2 = param_2 + 0x10;
    for (lVar5 = 5; -1 < lVar5; lVar5 = lVar5 + -1) {
      bVar1 = pbVar4[-1];
      *psVar2 = (ushort)bVar1 << 8;
      *psVar2 = CONCAT11(bVar1,*pbVar4);
      pbVar4 = pbVar4 + 2;
      psVar2 = psVar2 + -1;
    }
    return 1;
  }
  return 0;
}



void FUN_0000c3ac(uint *param_1)

{
  uint uVar1;
  byte abStack_30 [8];
  undefined1 local_28;
  
  FUN_00004788((longlong *)abStack_30,0x10,0);
  uVar1 = FUN_0000c044(param_1,abStack_30);
  if (uVar1 == 0) {
    *(undefined1 *)(param_1 + 0x1f) = local_28;
  }
  return;
}



uint FUN_0000c3f8(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint local_48;
  int local_44;
  undefined4 uStack_40;
  undefined4 local_2c;
  undefined4 local_24;
  
  local_2c = 0;
  uVar1 = *param_1;
  local_48 = 0x37;
  local_24 = 0;
  local_44 = (uint)(ushort)param_1[5] << 0x10;
  uStack_40 = 1;
  uVar2 = FUN_0000b868(param_1,&local_48);
  if (uVar2 == 0) {
    local_24 = 0;
    local_48 = 6;
    local_44 = 2;
    uVar2 = FUN_0000b868(param_1,&local_48);
    if (uVar2 == 0) {
      uVar2 = FUN_0000a3a4(uVar1,1);
    }
  }
  return uVar2;
}



undefined4 FUN_0000c478(undefined4 *param_1,longlong param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  uint uVar3;
  longlong lVar4;
  
  uVar1 = 0;
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    *(ushort *)(param_2 + 0x46) = (ushort)*(byte *)((longlong)param_1 + 3);
    *(short *)(param_2 + 0x48) = (short)((uint)*param_1 >> 8);
    *(char *)(param_2 + 0x4a) = (char)*param_1;
    uVar3 = param_1[1];
    puVar2 = (undefined1 *)(param_2 + 0x4e);
    lVar4 = 4;
    while (0 < lVar4) {
      *puVar2 = (char)uVar3;
      uVar3 = uVar3 >> 8;
      puVar2 = puVar2 + -1;
      lVar4 = lVar4 + -1;
    }
    *(undefined1 *)(param_2 + 0x4f) = 0;
    uVar1 = 1;
    *(undefined1 *)(param_2 + 0x51) = *(undefined1 *)((longlong)param_1 + 0xb);
    *(int *)(param_2 + 0x54) = (int)(CONCAT44(param_1[2],param_1[3]) >> 0x18);
  }
  return uVar1;
}



undefined8 FUN_0000c4e4(void)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 local_20;
  longlong local_18;
  
  local_20 = 0x41020;
  lVar1 = (**(code **)(DAT_00017260 + 0x140))(&DAT_000162c8,0,&local_18);
  if (lVar1 < 0) {
    FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
    FUN_0000464c();
  }
  DAT_000183f8 = (**(code **)(local_18 + 8))(local_18,&local_20,2);
  if (DAT_000183f8 == 0) {
    FUN_00004548(0x80000000,(byte *)"GPTListenerAllocMem: Failed memory allocation\n");
    uVar2 = 0x8000000000000009;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



longlong FUN_0000c5a0(longlong param_1)

{
  longlong lVar1;
  
  lVar1 = -0x7ffffffffffffffe;
  if ((param_1 != 0) && (*(longlong *)(param_1 + 8) != 0)) {
    if (DAT_000183f8 == 0) {
      FUN_00004548(0x80000000,(byte *)"GPTListenerInit: GPTListenerParams is NULL\n");
      lVar1 = -0x7ffffffffffffff7;
    }
    else if (*(int *)(DAT_000183f8 + 0x41000) == 1) {
      lVar1 = 0;
    }
    else {
      lVar1 = FUN_0000c6cc();
      if (lVar1 == 0) {
        if (**(int **)(param_1 + 8) == 0x726f6e73) {
          *(longlong *)(DAT_000183f8 + 0x41008) = param_1;
        }
        else if (**(int **)(param_1 + 8) == 0x20736675) {
          DAT_000183f0 = 1;
        }
        lVar1 = (**(code **)(*(longlong *)(DAT_000183f8 + 0x41010) + 0x20))
                          (*(longlong *)(DAT_000183f8 + 0x41010),0x2001,FUN_0000c710,
                           *(undefined8 *)(DAT_000183f8 + 0x41008),DAT_000183f8,0x41000);
        if (lVar1 == 0) {
          *(undefined4 *)(DAT_000183f8 + 0x41000) = 1;
        }
        lVar1 = FUN_0000c790();
        return lVar1;
      }
    }
  }
  return lVar1;
}



undefined8 FUN_0000c6cc(void)

{
  undefined8 uVar1;
  
  if (*(longlong *)(DAT_000183f8 + 0x41010) != 0) {
    return 0;
  }
                    // WARNING: Could not recover jumptable at 0x0000c70c. Too many branches
                    // WARNING: Treating indirect jump as call
  uVar1 = (**(code **)(DAT_00017260 + 0x140))(&DAT_00016238,0);
  return uVar1;
}



undefined8 FUN_0000c710(undefined8 param_1,longlong *param_2,uint param_3)

{
  if (0x1b < param_3) {
    switch((int)*param_2) {
    case 0x401:
      FUN_0000c814(param_2);
      break;
    case 0x402:
      FUN_0000ca20(param_2);
      break;
    case 0x403:
      FUN_0000cc1c(param_2);
      break;
    case 0x404:
      FUN_0000ce64(param_2);
      break;
    default:
      FUN_00004788(param_2,0xff,(char)param_3);
    }
  }
  return 0;
}



longlong FUN_0000c790(void)

{
  longlong lVar1;
  
  lVar1 = (**(code **)(DAT_00017260 + 0x170))(0x200,8,&LAB_0000d0cc,0,&DAT_000161b8,&DAT_000183e8);
  if (lVar1 < 0) {
    FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
    FUN_0000464c();
  }
  return lVar1;
}



void FUN_0000c814(undefined8 *param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  bool bVar3;
  longlong lVar4;
  int iVar5;
  undefined8 uVar6;
  int local_48;
  int local_44;
  uint local_40;
  undefined1 auStack_3c [20];
  longlong local_28;
  
  local_28 = _data;
  FUN_000047cc((undefined8 *)&local_48,param_1,0x1c);
  *(undefined1 *)((longlong)param_1 + 1) = 4;
  *(undefined1 *)param_1 = 1;
  *(undefined1 *)(param_1 + 1) = 0xff;
  *(undefined1 *)((longlong)param_1 + 3) = 0;
  *(undefined1 *)((longlong)param_1 + 2) = 0;
  *(undefined1 *)((longlong)param_1 + 9) = 0xff;
  *(undefined1 *)((longlong)param_1 + 0xb) = 0xff;
  *(undefined1 *)((longlong)param_1 + 10) = 0xff;
  if (local_48 == 0x401) {
    bVar3 = FUN_0000da98(local_44);
    if (bVar3) {
      puVar1 = (uint *)0x16e94;
      if (local_40 != 8) {
        puVar1 = &local_40;
      }
      iVar5 = 1;
      if (local_40 == 8) {
        iVar5 = 2;
      }
      lVar4 = FUN_0000cff0(puVar1,iVar5,auStack_3c,(undefined8 *)(DAT_000183f8 + 0x41008));
      if (lVar4 == 0) {
        iVar5 = *(int *)(*(longlong *)(*(longlong *)(DAT_000183f8 + 0x41008) + 8) + 0x18) + 1;
        *(char *)((longlong)param_1 + 0xc) = (char)iVar5;
        *(undefined1 *)(param_1 + 2) = 0;
        *(undefined1 *)(param_1 + 1) = 0;
        *(undefined1 *)((longlong)param_1 + 4) = 2;
        *(undefined1 *)((longlong)param_1 + 0xb) = 0;
        *(undefined1 *)((longlong)param_1 + 10) = 0;
        *(undefined1 *)((longlong)param_1 + 9) = 0;
        *(undefined1 *)((longlong)param_1 + 7) = 0;
        *(undefined1 *)((longlong)param_1 + 6) = 0;
        *(undefined1 *)((longlong)param_1 + 5) = 0;
        *(char *)((longlong)param_1 + 0xf) = (char)((uint)iVar5 >> 0x18);
        *(char *)((longlong)param_1 + 0xe) = (char)((uint)iVar5 >> 0x10);
        *(char *)((longlong)param_1 + 0xd) = (char)((uint)iVar5 >> 8);
        lVar4 = DAT_000183f8;
        *(undefined1 *)((longlong)param_1 + 0x13) = 0;
        *(undefined1 *)((longlong)param_1 + 0x12) = 4;
        *(undefined1 *)((longlong)param_1 + 0x11) = 0x10;
        uVar6 = *(undefined8 *)(lVar4 + 0x41008);
        *(char *)((longlong)param_1 + 0x14) = (char)uVar6;
        *(char *)((longlong)param_1 + 0x17) = (char)((ulonglong)uVar6 >> 0x18);
        *(char *)((longlong)param_1 + 0x16) = (char)((ulonglong)uVar6 >> 0x10);
        *(char *)((longlong)param_1 + 0x15) = (char)((ulonglong)uVar6 >> 8);
        uVar2 = *(undefined4 *)(*(longlong *)(*(longlong *)(lVar4 + 0x41008) + 8) + 0xc);
        *(char *)(param_1 + 3) = (char)uVar2;
        *(char *)((longlong)param_1 + 0x1b) = (char)((uint)uVar2 >> 0x18);
        *(char *)((longlong)param_1 + 0x1a) = (char)((uint)uVar2 >> 0x10);
        *(char *)((longlong)param_1 + 0x19) = (char)((uint)uVar2 >> 8);
      }
      else {
        *(undefined1 *)(param_1 + 1) = 0xfd;
        *(undefined1 *)((longlong)param_1 + 0xb) = 0xff;
        *(undefined1 *)((longlong)param_1 + 10) = 0xff;
        *(undefined1 *)((longlong)param_1 + 9) = 0xff;
      }
    }
    else {
      *(undefined1 *)(param_1 + 1) = 0xfb;
      *(undefined1 *)((longlong)param_1 + 0xb) = 0xff;
      *(undefined1 *)((longlong)param_1 + 10) = 0xff;
      *(undefined1 *)((longlong)param_1 + 9) = 0xff;
    }
  }
  else {
    *(undefined1 *)(param_1 + 1) = 0xfe;
    *(undefined1 *)((longlong)param_1 + 0xb) = 0xff;
    *(undefined1 *)((longlong)param_1 + 10) = 0xff;
    *(undefined1 *)((longlong)param_1 + 9) = 0xff;
  }
  if (_data == local_28) {
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_000010d8();
}



void FUN_0000ca20(undefined8 *param_1)

{
  int iVar1;
  int *piVar2;
  longlong lVar3;
  ulonglong uVar4;
  
  uVar4 = (ulonglong)(uint)(*(int *)(param_1 + 2) + *(int *)((longlong)param_1 + 0x14));
  piVar2 = (int *)FUN_0000404c(uVar4);
  if (piVar2 != (int *)0x0) {
    FUN_000047cc((undefined8 *)piVar2,param_1,uVar4);
    *(undefined1 *)((longlong)param_1 + 3) = 0;
    *(undefined1 *)((longlong)param_1 + 2) = 0;
    *(undefined1 *)((longlong)param_1 + 1) = 4;
    *(undefined1 *)param_1 = 2;
    *(undefined1 *)(param_1 + 1) = 0xff;
    *(undefined1 *)((longlong)param_1 + 9) = 0xff;
    *(undefined1 *)((longlong)param_1 + 0xb) = 0xff;
    *(undefined1 *)((longlong)param_1 + 10) = 0xff;
    *(undefined1 *)((longlong)param_1 + 0x11) = 0;
    *(undefined1 *)(param_1 + 2) = 0x14;
    *(undefined1 *)((longlong)param_1 + 0x13) = 0;
    *(undefined1 *)((longlong)param_1 + 0x12) = 0;
    if (*piVar2 == 0x402) {
      lVar3 = *(longlong *)(DAT_000183f8 + 0x41008);
      if (lVar3 != 0) {
        iVar1 = (*(undefined4 **)(lVar3 + 8))[3] * piVar2[3];
        lVar3 = (**(code **)(lVar3 + 0x18))
                          (lVar3,**(undefined4 **)(lVar3 + 8),piVar2[2],iVar1,
                           (longlong)param_1 + 0x14);
        lVar3 = FUN_0000da24(lVar3);
        *(char *)((longlong)param_1 + 0xc) = (char)iVar1;
        *(char *)(param_1 + 1) = (char)lVar3;
        *(char *)((longlong)param_1 + 9) = (char)((ulonglong)lVar3 >> 8);
        *(char *)((longlong)param_1 + 0xb) = (char)((ulonglong)lVar3 >> 0x18);
        *(char *)((longlong)param_1 + 10) = (char)((ulonglong)lVar3 >> 0x10);
        *(char *)((longlong)param_1 + 0xf) = (char)((uint)iVar1 >> 0x18);
        *(char *)((longlong)param_1 + 0xe) = (char)((uint)iVar1 >> 0x10);
        *(char *)((longlong)param_1 + 0xd) = (char)((uint)iVar1 >> 8);
      }
    }
    else {
      *(undefined1 *)(param_1 + 1) = 0xfe;
      *(undefined1 *)((longlong)param_1 + 0xb) = 0xff;
      *(undefined1 *)((longlong)param_1 + 10) = 0xff;
      *(undefined1 *)((longlong)param_1 + 9) = 0xff;
    }
    FUN_00004100();
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0xfa;
  *(undefined1 *)((longlong)param_1 + 0xb) = 0xff;
  *(undefined1 *)((longlong)param_1 + 10) = 0xff;
  *(undefined1 *)((longlong)param_1 + 9) = 0xff;
  FUN_00004548(0x80000000,(byte *)"GPTListenerReadSectors: Failed mem allocation. mTzSDGptRWReq\n");
  return;
}



void FUN_0000cc1c(undefined8 *param_1)

{
  int *piVar1;
  longlong lVar2;
  ulonglong uVar3;
  
  uVar3 = (ulonglong)(uint)(*(int *)(param_1 + 2) + *(int *)((longlong)param_1 + 0x14));
  piVar1 = (int *)FUN_0000404c(uVar3);
  if (piVar1 == (int *)0x0) {
    *(undefined1 *)(param_1 + 1) = 0xfa;
    *(undefined1 *)((longlong)param_1 + 0xb) = 0xff;
    *(undefined1 *)((longlong)param_1 + 10) = 0xff;
    *(undefined1 *)((longlong)param_1 + 9) = 0xff;
    FUN_00004548(0x80000000,
                 (byte *)"GPTListenerWriteSectors: Failed mem allocation. mTzSDGptRWReq\n");
    return;
  }
  FUN_000047cc((undefined8 *)piVar1,param_1,uVar3);
  *(undefined1 *)((longlong)param_1 + 3) = 0;
  *(undefined1 *)((longlong)param_1 + 2) = 0;
  *(undefined1 *)((longlong)param_1 + 1) = 4;
  *(undefined1 *)param_1 = 3;
  *(undefined1 *)(param_1 + 1) = 0xff;
  *(undefined1 *)((longlong)param_1 + 0xb) = 0xff;
  *(undefined1 *)((longlong)param_1 + 10) = 0xff;
  *(undefined1 *)((longlong)param_1 + 9) = 0xff;
  *(undefined1 *)((longlong)param_1 + 0x11) = 0;
  *(undefined1 *)(param_1 + 2) = 0x14;
  *(undefined1 *)((longlong)param_1 + 0x13) = 0;
  *(undefined1 *)((longlong)param_1 + 0x12) = 0;
  if (*(char *)(DAT_000183f8 + 0x41018) == '\0') {
    if (*piVar1 != 0x403) {
      *(undefined1 *)(param_1 + 1) = 0xfe;
      *(undefined1 *)((longlong)param_1 + 0xb) = 0xff;
      *(undefined1 *)((longlong)param_1 + 10) = 0xff;
      *(undefined1 *)((longlong)param_1 + 9) = 0xff;
      goto LAB_0000cd2c;
    }
    lVar2 = *(longlong *)(DAT_000183f8 + 0x41008);
    if (lVar2 == 0) goto LAB_0000cd2c;
    lVar2 = (**(code **)(lVar2 + 0x20))
                      (lVar2,**(undefined4 **)(lVar2 + 8),piVar1[2],
                       (*(undefined4 **)(lVar2 + 8))[3] * piVar1[3],
                       (ulonglong)(uint)piVar1[5] + (longlong)param_1);
    lVar2 = FUN_0000da24(lVar2);
    *(undefined1 *)((longlong)param_1 + 0xc) = 0;
    *(char *)(param_1 + 1) = (char)lVar2;
    *(char *)((longlong)param_1 + 9) = (char)((ulonglong)lVar2 >> 8);
    *(char *)((longlong)param_1 + 0xb) = (char)((ulonglong)lVar2 >> 0x18);
    *(char *)((longlong)param_1 + 10) = (char)((ulonglong)lVar2 >> 0x10);
  }
  else {
    lVar2 = FUN_0000da24(0);
    *(char *)(param_1 + 1) = (char)lVar2;
    *(undefined1 *)((longlong)param_1 + 0xc) = 0;
    *(char *)((longlong)param_1 + 0xb) = (char)((ulonglong)lVar2 >> 0x18);
    *(char *)((longlong)param_1 + 10) = (char)((ulonglong)lVar2 >> 0x10);
    *(char *)((longlong)param_1 + 9) = (char)((ulonglong)lVar2 >> 8);
  }
  *(undefined1 *)((longlong)param_1 + 0xf) = 0;
  *(undefined1 *)((longlong)param_1 + 0xe) = 0;
  *(undefined1 *)((longlong)param_1 + 0xd) = 0;
LAB_0000cd2c:
  FUN_00004100();
  return;
}



void FUN_0000ce64(undefined8 *param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  uint local_4c;
  int local_48;
  int local_44;
  int iStack_40;
  undefined8 auStack_3c [2];
  longlong local_28;
  
  local_28 = _data;
  local_4c = 0;
  FUN_000047cc((undefined8 *)&local_48,param_1,0x1c);
  *(undefined1 *)((longlong)param_1 + 3) = 0;
  *(undefined1 *)((longlong)param_1 + 1) = 4;
  *(undefined1 *)param_1 = 4;
  *(undefined1 *)((longlong)param_1 + 5) = 0xff;
  *(undefined1 *)((longlong)param_1 + 4) = 0xff;
  *(undefined1 *)((longlong)param_1 + 7) = 0xff;
  *(undefined1 *)((longlong)param_1 + 6) = 0xff;
  *(undefined1 *)((longlong)param_1 + 2) = 0;
  *(undefined1 *)((longlong)param_1 + 0xd) = 0;
  *(undefined1 *)((longlong)param_1 + 0xc) = 0x10;
  *(undefined1 *)((longlong)param_1 + 0xf) = 0;
  *(undefined1 *)((longlong)param_1 + 0xe) = 0;
  if (local_48 == 0x404) {
    lVar2 = FUN_00007344(iStack_40,auStack_3c,local_44,&local_4c,param_1 + 2,
                         *(longlong *)(*(longlong *)(DAT_000183f8 + 0x41008) + 8));
    *(char *)(param_1 + 1) = (char)local_4c;
    *(char *)((longlong)param_1 + 0xb) = (char)(local_4c >> 0x18);
    *(char *)((longlong)param_1 + 10) = (char)(local_4c >> 0x10);
    *(char *)((longlong)param_1 + 9) = (char)(local_4c >> 8);
    lVar2 = FUN_0000da24(lVar2);
    uVar1 = (undefined4)lVar2;
  }
  else {
    uVar1 = 0xfffffffe;
  }
  *(char *)((longlong)param_1 + 4) = (char)uVar1;
  *(char *)((longlong)param_1 + 7) = (char)((uint)uVar1 >> 0x18);
  *(char *)((longlong)param_1 + 6) = (char)((uint)uVar1 >> 0x10);
  *(char *)((longlong)param_1 + 5) = (char)((uint)uVar1 >> 8);
  if (_data == local_28) {
    return;
  }
                    // WARNING: Subroutine does not return
  FUN_000010d8();
}



undefined8 FUN_0000cf94(uint param_1,undefined8 *param_2)

{
  if (7 < param_1) {
    return 0x8000000000000007;
  }
  if (DAT_000183f0 == '\x01') {
    *param_2 = (&PTR_DAT_00014870)[(ulonglong)param_1 * 2];
    return 0;
  }
  *param_2 = (&PTR_DAT_00014960)[(ulonglong)param_1 * 2];
  return 0;
}



undefined8 FUN_0000cff0(uint *param_1,int param_2,undefined8 param_3,undefined8 *param_4)

{
  uint *puVar1;
  longlong lVar2;
  int iVar3;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined1 auStack_98 [8];
  undefined8 local_90;
  uint local_64;
  undefined8 local_58;
  
  local_64 = 2;
  iVar3 = param_2;
  do {
    while( true ) {
      param_2 = param_2 + -1;
      puVar1 = param_1 + 1;
      if (iVar3 == 0) {
        return 0x800000000000000c;
      }
      lVar2 = FUN_0000cf94(*param_1,&local_58);
      param_1 = puVar1;
      if (lVar2 == 0) break;
      iVar3 = iVar3 + -1;
    }
    uStack_a8 = 0;
    local_64 = 2;
    local_b8 = local_58;
    local_b0 = param_3;
    lVar2 = FUN_0000fd3c(0x116,&local_b8,(longlong)auStack_98,&local_64);
    iVar3 = param_2;
  } while ((lVar2 != 0) || (local_64 != 1));
  *param_4 = local_90;
  return 0;
}



undefined8 FUN_0000d0ec(void)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 local_20;
  longlong local_18;
  
  local_20 = 0x23020;
  lVar1 = (**(code **)(DAT_00017260 + 0x140))(&DAT_000162c8,0,&local_18);
  if (lVar1 < 0) {
    FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
    FUN_0000464c();
  }
  DAT_00018408 = (**(code **)(local_18 + 8))(local_18,&local_20,2);
  if (DAT_00018408 == 0) {
    FUN_00004548(0x80000000,(byte *)"RPMBListenerAllocMem: Failed memory allocation\n");
    uVar2 = 0x8000000000000009;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



longlong FUN_0000d1a4(int param_1)

{
  longlong lVar1;
  
  if (DAT_00018408 == 0) {
    FUN_00004548(0x80000000,(byte *)"RPMBListenerInit: RPMBListenerParams is NULL\n");
    lVar1 = -0x7ffffffffffffff7;
  }
  else if (*(int *)(DAT_00018408 + 0x23000) == 1) {
    lVar1 = 0;
  }
  else {
    lVar1 = FUN_0000d270();
    if (lVar1 == 0) {
      if (param_1 == 0x20736675) {
        DAT_00018404 = 1;
      }
      lVar1 = (**(code **)(*(longlong *)(DAT_00018408 + 0x23010) + 0x20))
                        (*(longlong *)(DAT_00018408 + 0x23010),0x2000,FUN_0000d30c,
                         *(undefined8 *)(DAT_00018408 + 0x23008),DAT_00018408,0x23000);
      if (lVar1 == 0) {
        *(undefined4 *)(DAT_00018408 + 0x23000) = 1;
      }
    }
  }
  return lVar1;
}



longlong FUN_0000d270(void)

{
  longlong lVar1;
  
  if ((*(longlong *)(DAT_00018408 + 0x23008) != 0) ||
     (lVar1 = (**(code **)(DAT_00017260 + 0x140))(&DAT_00016208,0), lVar1 == 0)) {
    if (*(longlong *)(DAT_00018408 + 0x23010) == 0) {
                    // WARNING: Could not recover jumptable at 0x0000d300. Too many branches
                    // WARNING: Treating indirect jump as call
      lVar1 = (**(code **)(DAT_00017260 + 0x140))(&DAT_00016238,0);
      return lVar1;
    }
    lVar1 = 0;
  }
  return lVar1;
}



undefined8 FUN_0000d30c(undefined8 param_1,longlong *param_2,uint param_3)

{
  if (7 < param_3) {
    switch((int)*param_2) {
    case 0x101:
      FUN_0000d38c(param_2);
      break;
    case 0x102:
      FUN_0000d4cc(param_2);
      break;
    case 0x103:
      FUN_0000d6f4(param_2);
      break;
    case 0x104:
      FUN_0000d920(param_2);
      break;
    default:
      FUN_00004788(param_2,0xff,(char)param_3);
    }
  }
  return 0;
}



void FUN_0000d38c(undefined8 *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  undefined1 uVar5;
  longlong lVar6;
  int local_18;
  int local_14;
  
  FUN_000047cc((undefined8 *)&local_18,param_1,8);
  *(undefined1 *)((longlong)param_1 + 3) = 0;
  *(undefined1 *)((longlong)param_1 + 2) = 0;
  *(undefined1 *)((longlong)param_1 + 1) = 1;
  *(undefined1 *)param_1 = 1;
  *(undefined1 *)((longlong)param_1 + 9) = 0xff;
  *(undefined1 *)(param_1 + 1) = 0xff;
  *(undefined1 *)((longlong)param_1 + 0xb) = 0xff;
  *(undefined1 *)((longlong)param_1 + 10) = 0xff;
  if (local_18 == 0x101) {
    bVar4 = FUN_0000da8c(local_14);
    if (bVar4) {
      lVar6 = *(longlong *)(DAT_00018408 + 0x23008);
      if (lVar6 != 0) {
        uVar1 = *(undefined4 *)(lVar6 + 8);
        uVar2 = *(uint *)(lVar6 + 0xc);
        DAT_00018400 = uVar1;
        *(undefined1 *)(param_1 + 1) = 0;
        *(char *)(param_1 + 2) = (char)uVar1;
        cVar3 = DAT_00018404;
        *(char *)((longlong)param_1 + 0xc) = (char)(uVar2 >> 9);
        *(undefined1 *)((longlong)param_1 + 0xb) = 0;
        *(undefined1 *)((longlong)param_1 + 10) = 0;
        *(byte *)((longlong)param_1 + 0xe) = (byte)(uVar2 >> 0x19);
        uVar5 = 9;
        if (cVar3 == '\0') {
          uVar5 = 3;
        }
        *(char *)((longlong)param_1 + 0xd) = (char)(uVar2 >> 0x11);
        *(undefined1 *)((longlong)param_1 + 9) = 0;
        *(undefined1 *)((longlong)param_1 + 0xf) = 0;
        *(undefined1 *)((longlong)param_1 + 0x15) = 0;
        *(char *)((longlong)param_1 + 0x13) = (char)((uint)uVar1 >> 0x18);
        *(char *)((longlong)param_1 + 0x12) = (char)((uint)uVar1 >> 0x10);
        *(char *)((longlong)param_1 + 0x11) = (char)((uint)uVar1 >> 8);
        *(undefined1 *)((longlong)param_1 + 0x14) = uVar5;
        *(undefined1 *)((longlong)param_1 + 0x17) = 0;
        *(undefined1 *)((longlong)param_1 + 0x16) = 0;
      }
    }
    else {
      *(undefined1 *)(param_1 + 1) = 0xfb;
      *(undefined1 *)((longlong)param_1 + 0xb) = 0xff;
      *(undefined1 *)((longlong)param_1 + 10) = 0xff;
      *(undefined1 *)((longlong)param_1 + 9) = 0xff;
    }
  }
  else {
    *(undefined1 *)(param_1 + 1) = 0xfe;
    *(undefined1 *)((longlong)param_1 + 0xb) = 0xff;
    *(undefined1 *)((longlong)param_1 + 10) = 0xff;
    *(undefined1 *)((longlong)param_1 + 9) = 0xff;
  }
  return;
}



void FUN_0000d4cc(undefined8 *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  longlong lVar5;
  char *pcVar6;
  ulonglong uVar7;
  uint *puVar8;
  
  if (param_1 == (undefined8 *)0x0) {
    pcVar6 = "RPMBListenerReadSectors: BufferPtr is NULL\n";
  }
  else {
    uVar7 = (ulonglong)(uint)(*(int *)(param_1 + 1) + *(int *)((longlong)param_1 + 0xc));
    piVar4 = (int *)FUN_0000404c(uVar7);
    if (piVar4 != (int *)0x0) {
      FUN_000047cc((undefined8 *)piVar4,param_1,uVar7);
      *(undefined1 *)((longlong)param_1 + 3) = 0;
      *(undefined1 *)((longlong)param_1 + 2) = 0;
      *(undefined1 *)((longlong)param_1 + 1) = 1;
      *(undefined1 *)param_1 = 2;
      *(undefined1 *)((longlong)param_1 + 4) = 0xff;
      *(undefined1 *)((longlong)param_1 + 5) = 0xff;
      *(undefined1 *)((longlong)param_1 + 7) = 0xff;
      *(undefined1 *)((longlong)param_1 + 6) = 0xff;
      *(undefined1 *)((longlong)param_1 + 0xd) = 0;
      *(undefined1 *)((longlong)param_1 + 0xc) = 0x14;
      *(undefined1 *)((longlong)param_1 + 0xf) = 0;
      *(undefined1 *)((longlong)param_1 + 0xe) = 0;
      if (*piVar4 == 0x102) {
        lVar5 = *(longlong *)(DAT_00018408 + 0x23008);
        if (lVar5 != 0) {
          puVar8 = (uint *)(piVar4 + 1);
          iVar3 = (**(code **)(lVar5 + 0x20))
                            (lVar5,(ulonglong)(uint)piVar4[3] + (longlong)piVar4,*puVar8,
                             (longlong)param_1 + 0x14);
          lVar5 = FUN_0000da24((longlong)iVar3);
          *(char *)((longlong)param_1 + 4) = (char)lVar5;
          *(char *)((longlong)param_1 + 7) = (char)((ulonglong)lVar5 >> 0x18);
          *(char *)((longlong)param_1 + 6) = (char)((ulonglong)lVar5 >> 0x10);
          *(char *)((longlong)param_1 + 5) = (char)((ulonglong)lVar5 >> 8);
          uVar2 = *puVar8;
          uVar1 = *puVar8;
          *(char *)((longlong)param_1 + 9) = (char)(ushort)uVar2 << 1;
          *(undefined1 *)(param_1 + 1) = 0;
          *(char *)((longlong)param_1 + 0xb) = (char)(uVar1 >> 0xf);
          *(char *)((longlong)param_1 + 10) = (char)((ushort)uVar2 >> 7);
        }
      }
      else {
        *(undefined1 *)((longlong)param_1 + 4) = 0xfe;
        *(undefined1 *)((longlong)param_1 + 7) = 0xff;
        *(undefined1 *)((longlong)param_1 + 6) = 0xff;
        *(undefined1 *)((longlong)param_1 + 5) = 0xff;
      }
      FUN_00004100();
      return;
    }
    pcVar6 = "RPMBListenerReadSectors: Failed mem allocation.\n";
    *(undefined1 *)((longlong)param_1 + 4) = 0xfa;
    *(undefined1 *)((longlong)param_1 + 7) = 0xff;
    *(undefined1 *)((longlong)param_1 + 6) = 0xff;
    *(undefined1 *)((longlong)param_1 + 5) = 0xff;
  }
  FUN_00004548(0x80000000,(byte *)pcVar6);
  return;
}



void FUN_0000d6f4(undefined8 *param_1)

{
  int iVar1;
  int *piVar2;
  longlong lVar3;
  char *pcVar4;
  ulonglong uVar5;
  
  if (param_1 == (undefined8 *)0x0) {
    pcVar4 = "RPMBListenerWriteSectors: BufferPtr is NULL\n";
  }
  else {
    uVar5 = (ulonglong)(uint)(*(int *)(param_1 + 1) + *(int *)((longlong)param_1 + 0xc));
    piVar2 = (int *)FUN_0000404c(uVar5);
    if (piVar2 != (int *)0x0) {
      FUN_000047cc((undefined8 *)piVar2,param_1,uVar5);
      *(undefined1 *)((longlong)param_1 + 3) = 0;
      *(undefined1 *)((longlong)param_1 + 2) = 0;
      *(undefined1 *)((longlong)param_1 + 1) = 1;
      *(undefined1 *)param_1 = 3;
      *(undefined1 *)((longlong)param_1 + 4) = 0xff;
      *(undefined1 *)((longlong)param_1 + 5) = 0xff;
      *(undefined1 *)((longlong)param_1 + 7) = 0xff;
      *(undefined1 *)((longlong)param_1 + 6) = 0xff;
      *(undefined1 *)((longlong)param_1 + 0xd) = 0;
      *(undefined1 *)((longlong)param_1 + 0xc) = 0x14;
      *(undefined1 *)((longlong)param_1 + 0xf) = 0;
      *(undefined1 *)((longlong)param_1 + 0xe) = 0;
      if (*piVar2 == 0x103) {
        lVar3 = *(longlong *)(DAT_00018408 + 0x23008);
        if (lVar3 != 0) {
          if (piVar2[3] == 0x18) {
            DAT_00018400 = piVar2[5];
          }
          iVar1 = (**(code **)(lVar3 + 0x28))
                            (lVar3,(ulonglong)(uint)piVar2[3] + (longlong)param_1,piVar2[1],
                             (longlong)param_1 + 0x14);
          lVar3 = FUN_0000da24((longlong)iVar1);
          *(char *)((longlong)param_1 + 4) = (char)lVar3;
          *(undefined1 *)(param_1 + 1) = 0;
          *(char *)((longlong)param_1 + 7) = (char)((ulonglong)lVar3 >> 0x18);
          *(char *)((longlong)param_1 + 6) = (char)((ulonglong)lVar3 >> 0x10);
          *(char *)((longlong)param_1 + 5) = (char)((ulonglong)lVar3 >> 8);
          *(undefined1 *)((longlong)param_1 + 0xb) = 0;
          *(undefined1 *)((longlong)param_1 + 10) = 0;
          *(undefined1 *)((longlong)param_1 + 9) = 2;
        }
      }
      else {
        *(undefined1 *)((longlong)param_1 + 4) = 0xfe;
        *(undefined1 *)((longlong)param_1 + 7) = 0xff;
        *(undefined1 *)((longlong)param_1 + 6) = 0xff;
        *(undefined1 *)((longlong)param_1 + 5) = 0xff;
      }
      FUN_00004100();
      return;
    }
    pcVar4 = "RPMBListenerWriteSectors: Failed mem allocation.\n";
    *(undefined1 *)((longlong)param_1 + 4) = 0xfa;
    *(undefined1 *)((longlong)param_1 + 7) = 0xff;
    *(undefined1 *)((longlong)param_1 + 6) = 0xff;
    *(undefined1 *)((longlong)param_1 + 5) = 0xff;
  }
  FUN_00004548(0x80000000,(byte *)pcVar4);
  return;
}



void FUN_0000d920(undefined8 *param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  int local_30;
  int local_2c;
  int local_28;
  uint local_14;
  
  local_14 = 0;
  FUN_000047cc((undefined8 *)&local_30,param_1,0xc);
  *(undefined1 *)((longlong)param_1 + 3) = 0;
  *(undefined1 *)((longlong)param_1 + 1) = 1;
  *(undefined1 *)param_1 = 4;
  *(undefined1 *)((longlong)param_1 + 5) = 0xff;
  *(undefined1 *)((longlong)param_1 + 4) = 0xff;
  *(undefined1 *)((longlong)param_1 + 7) = 0xff;
  *(undefined1 *)((longlong)param_1 + 6) = 0xff;
  *(undefined1 *)((longlong)param_1 + 2) = 0;
  *(undefined1 *)((longlong)param_1 + 0xd) = 0;
  *(undefined1 *)((longlong)param_1 + 0xc) = 0x10;
  *(undefined1 *)((longlong)param_1 + 0xf) = 0;
  *(undefined1 *)((longlong)param_1 + 0xe) = 0;
  if ((local_30 == 0x104) && (local_28 == 3)) {
    lVar2 = FUN_00007344(3,(undefined8 *)0x0,local_2c,&local_14,param_1 + 2,0);
    *(char *)(param_1 + 1) = (char)local_14;
    *(char *)((longlong)param_1 + 0xb) = (char)(local_14 >> 0x18);
    *(char *)((longlong)param_1 + 10) = (char)(local_14 >> 0x10);
    *(char *)((longlong)param_1 + 9) = (char)(local_14 >> 8);
    lVar2 = FUN_0000da24(lVar2);
    uVar1 = (undefined4)lVar2;
  }
  else {
    uVar1 = 0xfffffffe;
  }
  *(char *)((longlong)param_1 + 4) = (char)uVar1;
  *(char *)((longlong)param_1 + 7) = (char)((uint)uVar1 >> 0x18);
  *(char *)((longlong)param_1 + 6) = (char)((uint)uVar1 >> 0x10);
  *(char *)((longlong)param_1 + 5) = (char)((uint)uVar1 >> 8);
  return;
}



longlong FUN_0000da24(longlong param_1)

{
  if (param_1 != 0) {
    if (param_1 == -0x7ffffffffffffffd) {
      return 0xfffffff9;
    }
    if (param_1 == -0x7ffffffffffffff7) {
      return 0xfffffffa;
    }
    if (param_1 == -0x7ffffffffffffff4) {
      return 0xfffffffd;
    }
    if (param_1 == -0x7ffffffffffffffe) {
      return 0xfffffffe;
    }
    param_1 = 0xffffffff;
  }
  return param_1;
}



bool FUN_0000da8c(int param_1)

{
  return param_1 == 2;
}



bool FUN_0000da98(int param_1)

{
  return param_1 == 2;
}



void FUN_0000daa4(undefined1 *param_1,undefined1 param_2,longlong param_3)

{
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *param_1 = param_2;
    param_1 = param_1 + 1;
  }
  return;
}



// WARNING: Type propagation algorithm not settling

void FUN_0000dabc(longlong param_1,longlong param_2,ulonglong param_3)

{
  undefined8 *puVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  bool bVar16;
  undefined4 *puVar17;
  ulonglong uVar18;
  longlong lVar19;
  undefined4 *puVar20;
  undefined4 *puVar21;
  uint uVar22;
  longlong lVar23;
  ulonglong uVar24;
  longlong lVar25;
  ulonglong uVar26;
  ulonglong uVar27;
  longlong lVar28;
  undefined4 uVar29;
  ulonglong uVar30;
  longlong lVar31;
  
  lVar23 = 0;
  uVar26 = 2 - param_3;
  lVar25 = param_3 + 0xd;
  uVar27 = -param_3;
  lVar28 = param_3 + 0xe;
  uVar30 = -param_3;
  lVar31 = param_3 + 0xf;
  uVar18 = ~param_3;
  lVar19 = param_3 + 0x10;
  uVar24 = param_3;
  while( true ) {
    uVar27 = uVar27 + 1;
    puVar1 = (undefined8 *)(param_2 + lVar23);
    if ((uVar24 == 0) || (((ulonglong)puVar1 & 3) == 0)) break;
    uVar24 = uVar24 - 1;
    uVar26 = uVar26 + 1;
    lVar25 = lVar25 + -1;
    *(undefined1 *)(param_1 + lVar23) = *(undefined1 *)puVar1;
    lVar28 = lVar28 + -1;
    lVar23 = lVar23 + 1;
    uVar30 = uVar30 + 1;
    lVar31 = lVar31 + -1;
    uVar18 = uVar18 + 1;
    lVar19 = lVar19 + -1;
  }
  puVar2 = (undefined1 *)(param_1 + lVar23);
  uVar24 = param_3 - lVar23;
  if (((ulonglong)puVar2 & 3) == 0) {
    uVar26 = uVar18;
    if (uVar18 < 0xfffffffffffffff1) {
      uVar26 = 0xfffffffffffffff0;
    }
    lVar25 = 0;
    puVar20 = (undefined4 *)(param_1 + (uVar26 + lVar19 & 0xfffffffffffffff0) + lVar23);
    while (bVar16 = 0xf < uVar24, uVar24 = uVar24 - 0x10, bVar16) {
      puVar1 = (undefined8 *)(param_2 + lVar25 + lVar23);
      puVar17 = (undefined4 *)(param_1 + lVar25 + lVar23);
      uVar4 = puVar1[1];
      lVar25 = lVar25 + 0x10;
      uVar13 = *puVar1;
      puVar17[2] = (int)uVar4;
      puVar17[3] = (int)((ulonglong)uVar4 >> 0x20);
      *puVar17 = (int)uVar13;
      puVar17[1] = (int)((ulonglong)uVar13 >> 0x20);
    }
    uVar26 = uVar18;
    if (uVar18 < 0xfffffffffffffff1) {
      uVar26 = 0xfffffffffffffff0;
    }
    uVar22 = (uint)(param_3 - lVar23);
    if ((uVar22 >> 3 & 1) == 0) {
      puVar17 = (undefined4 *)(param_2 + (uVar26 + lVar19 & 0xfffffffffffffff0) + lVar23);
    }
    else {
      if (uVar18 < 0xfffffffffffffff1) {
        uVar18 = 0xfffffffffffffff0;
      }
      uVar26 = uVar18 + lVar19 & 0xfffffffffffffff0;
      puVar21 = (undefined4 *)(param_2 + uVar26 + lVar23);
      puVar3 = (undefined4 *)(param_1 + uVar26 + lVar23);
      uVar29 = puVar21[1];
      puVar20 = puVar3 + 2;
      puVar17 = puVar21 + 2;
      *puVar3 = *puVar21;
      puVar3[1] = uVar29;
    }
    if ((uVar22 >> 2 & 1) != 0) {
      *puVar20 = *puVar17;
      puVar17 = puVar17 + 1;
      puVar20 = puVar20 + 1;
    }
    puVar21 = puVar20;
    if ((uVar22 >> 1 & 1) != 0) {
      uVar11 = *(undefined1 *)puVar17;
      puVar21 = (undefined4 *)((longlong)puVar20 + 2);
      uVar12 = *(undefined1 *)((longlong)puVar17 + 1);
      puVar17 = (undefined4 *)((longlong)puVar17 + 2);
      *(undefined1 *)puVar20 = uVar11;
      *(undefined1 *)((longlong)puVar20 + 1) = uVar12;
    }
    if ((param_3 - lVar23 & 1) == 0) {
      return;
    }
    *(undefined1 *)puVar21 = *(undefined1 *)puVar17;
    return;
  }
  if (0x1f < uVar24) {
    uVar22 = (uint)puVar2 & 3;
    if (uVar22 == 1) {
      uVar11 = *(undefined1 *)((longlong)puVar1 + 2);
      uVar30 = uVar26;
      if (uVar26 < 0xfffffffffffffff0) {
        uVar30 = 0xffffffffffffffef;
      }
      uVar29 = *(undefined4 *)puVar1;
      puVar2[1] = *(undefined1 *)((longlong)puVar1 + 1);
      puVar2[2] = uVar11;
      *puVar2 = (char)uVar29;
      lVar28 = 0;
      puVar2 = (undefined1 *)(param_1 + (uVar30 + lVar25 & 0xfffffffffffffff0) + lVar23 + 3);
      for (uVar24 = uVar24 - 3; 0x10 < uVar24; uVar24 = uVar24 - 0x10) {
        lVar31 = param_2 + lVar28 + lVar23;
        lVar19 = param_1 + lVar28 + lVar23;
        uVar13 = *(undefined8 *)(lVar31 + 4);
        uVar14 = *(undefined8 *)(lVar31 + 8);
        lVar28 = lVar28 + 0x10;
        uVar4 = CONCAT44(*(undefined4 *)(lVar31 + 4),uVar29);
        uVar29 = *(undefined4 *)(lVar31 + 0x10);
        uVar15 = *(undefined8 *)(lVar31 + 0xc);
        *(int *)(lVar19 + 3) = (int)((ulonglong)uVar4 >> 0x18);
        *(int *)(lVar19 + 7) = (int)((ulonglong)uVar13 >> 0x18);
        *(int *)(lVar19 + 0xb) = (int)((ulonglong)uVar14 >> 0x18);
        *(int *)(lVar19 + 0xf) = (int)((ulonglong)uVar15 >> 0x18);
      }
      if (uVar26 < 0xfffffffffffffff0) {
        uVar26 = 0xffffffffffffffef;
      }
      uVar26 = uVar26 + lVar25 & 0xfffffffffffffff0;
      uVar24 = ((-3 - uVar26) + param_3) - lVar23;
      puVar1 = (undefined8 *)(param_2 + uVar26 + lVar23 + 3);
      uVar22 = (uint)uVar24;
      goto joined_r0x0000de24;
    }
    if (uVar22 == 2) {
      uVar29 = *(undefined4 *)puVar1;
      uVar11 = *(undefined1 *)((longlong)puVar1 + 1);
      uVar26 = uVar27;
      if (uVar27 < 0xffffffffffffffef) {
        uVar26 = 0xffffffffffffffee;
      }
      *puVar2 = (char)uVar29;
      puVar2[1] = uVar11;
      lVar25 = 0;
      puVar2 = (undefined1 *)(param_1 + (uVar26 + lVar28 & 0xfffffffffffffff0) + lVar23 + 2);
      for (uVar24 = uVar24 - 2; 0x11 < uVar24; uVar24 = uVar24 - 0x10) {
        lVar31 = param_2 + lVar25 + lVar23;
        lVar19 = param_1 + lVar25 + lVar23;
        uVar13 = *(undefined8 *)(lVar31 + 4);
        uVar14 = *(undefined8 *)(lVar31 + 8);
        lVar25 = lVar25 + 0x10;
        uVar4 = CONCAT44(*(undefined4 *)(lVar31 + 4),uVar29);
        uVar29 = *(undefined4 *)(lVar31 + 0x10);
        uVar15 = *(undefined8 *)(lVar31 + 0xc);
        *(int *)(lVar19 + 2) = (int)((ulonglong)uVar4 >> 0x10);
        *(int *)(lVar19 + 6) = (int)((ulonglong)uVar13 >> 0x10);
        *(int *)(lVar19 + 10) = (int)((ulonglong)uVar14 >> 0x10);
        *(int *)(lVar19 + 0xe) = (int)((ulonglong)uVar15 >> 0x10);
      }
      if (uVar27 < 0xffffffffffffffef) {
        uVar27 = 0xffffffffffffffee;
      }
      uVar26 = uVar27 + lVar28 & 0xfffffffffffffff0;
      uVar24 = ((-2 - uVar26) + param_3) - lVar23;
      puVar1 = (undefined8 *)(param_2 + uVar26 + lVar23 + 2);
      uVar22 = (uint)uVar24;
      goto joined_r0x0000de24;
    }
    if (uVar22 == 3) {
      uVar29 = *(undefined4 *)(param_2 + lVar23);
      uVar26 = uVar30;
      if (uVar30 < 0xffffffffffffffee) {
        uVar26 = 0xffffffffffffffed;
      }
      *(char *)(param_1 + lVar23) = (char)uVar29;
      lVar25 = 0;
      puVar2 = (undefined1 *)(param_1 + (uVar26 + lVar31 & 0xfffffffffffffff0) + lVar23 + 1);
      for (uVar24 = uVar24 - 1; 0x12 < uVar24; uVar24 = uVar24 - 0x10) {
        lVar28 = param_2 + lVar25 + lVar23;
        lVar19 = param_1 + lVar25 + lVar23;
        uVar13 = *(undefined8 *)(lVar28 + 4);
        uVar14 = *(undefined8 *)(lVar28 + 8);
        lVar25 = lVar25 + 0x10;
        uVar4 = CONCAT44(*(undefined4 *)(lVar28 + 4),uVar29);
        uVar29 = *(undefined4 *)(lVar28 + 0x10);
        uVar15 = *(undefined8 *)(lVar28 + 0xc);
        *(int *)(lVar19 + 1) = (int)((ulonglong)uVar4 >> 8);
        *(int *)(lVar19 + 5) = (int)((ulonglong)uVar13 >> 8);
        *(int *)(lVar19 + 9) = (int)((ulonglong)uVar14 >> 8);
        *(int *)(lVar19 + 0xd) = (int)((ulonglong)uVar15 >> 8);
      }
      if (uVar30 < 0xffffffffffffffee) {
        uVar30 = 0xffffffffffffffed;
      }
      uVar24 = ((~(uVar30 + lVar31) | 0xf) + param_3) - lVar23;
      puVar1 = (undefined8 *)(param_2 + (uVar30 + lVar31 & 0xfffffffffffffff0) + lVar23 + 1);
      uVar22 = (uint)uVar24;
      goto joined_r0x0000de24;
    }
  }
  uVar22 = (uint)uVar24;
joined_r0x0000de24:
  uVar29 = (undefined4)uVar24;
  if ((uVar22 >> 4 & 1) != 0) {
    uVar4 = *puVar1;
    uVar13 = *(undefined8 *)((longlong)puVar1 + 8);
    puVar1 = (undefined8 *)((longlong)puVar1 + 0x10);
    *puVar2 = (char)uVar4;
    *(char *)((longlong)puVar2 + 8) = (char)uVar13;
    *(char *)((longlong)puVar2 + 0xb) = (char)((ulonglong)uVar13 >> 0x18);
    *(char *)((longlong)puVar2 + 10) = (char)((ulonglong)uVar13 >> 0x10);
    *(char *)((longlong)puVar2 + 0xc) = (char)((ulonglong)uVar13 >> 0x20);
    *(char *)((longlong)puVar2 + 5) = (char)((ulonglong)uVar4 >> 0x28);
    *(char *)((longlong)puVar2 + 3) = (char)((ulonglong)uVar4 >> 0x18);
    *(char *)((longlong)puVar2 + 2) = (char)((ulonglong)uVar4 >> 0x10);
    *(char *)((longlong)puVar2 + 1) = (char)((ulonglong)uVar4 >> 8);
    *(char *)((longlong)puVar2 + 0xd) = (char)((ulonglong)uVar13 >> 0x28);
    *(char *)((longlong)puVar2 + 9) = (char)((ulonglong)uVar13 >> 8);
    *(char *)((longlong)puVar2 + 4) = (char)((ulonglong)uVar4 >> 0x20);
    *(char *)((longlong)puVar2 + 7) = (char)((ulonglong)uVar4 >> 0x38);
    *(char *)((longlong)puVar2 + 6) = (char)((ulonglong)uVar4 >> 0x30);
    *(char *)((longlong)puVar2 + 0xf) = (char)((ulonglong)uVar13 >> 0x38);
    *(char *)((longlong)puVar2 + 0xe) = (char)((ulonglong)uVar13 >> 0x30);
    puVar2 = (undefined1 *)((longlong)puVar2 + 0x10);
  }
  if (((uint)uVar29 >> 3 & 1) != 0) {
    uVar11 = *(undefined1 *)puVar1;
    uVar12 = *(undefined1 *)((longlong)puVar1 + 1);
    uVar9 = *(undefined1 *)((longlong)puVar1 + 2);
    uVar10 = *(undefined1 *)((longlong)puVar1 + 3);
    uVar5 = *(undefined1 *)((longlong)puVar1 + 4);
    uVar6 = *(undefined1 *)((longlong)puVar1 + 5);
    uVar7 = *(undefined1 *)((longlong)puVar1 + 6);
    uVar8 = *(undefined1 *)((longlong)puVar1 + 7);
    puVar1 = (undefined8 *)((longlong)puVar1 + 8);
    *puVar2 = uVar11;
    *(undefined1 *)((longlong)puVar2 + 1) = uVar12;
    *(undefined1 *)((longlong)puVar2 + 2) = uVar9;
    *(undefined1 *)((longlong)puVar2 + 3) = uVar10;
    *(undefined1 *)((longlong)puVar2 + 4) = uVar5;
    *(undefined1 *)((longlong)puVar2 + 5) = uVar6;
    *(undefined1 *)((longlong)puVar2 + 6) = uVar7;
    *(undefined1 *)((longlong)puVar2 + 7) = uVar8;
    puVar2 = (undefined1 *)((longlong)puVar2 + 8);
  }
  if (((uint)uVar29 >> 2 & 1) != 0) {
    uVar11 = *(undefined1 *)puVar1;
    uVar12 = *(undefined1 *)((longlong)puVar1 + 1);
    uVar9 = *(undefined1 *)((longlong)puVar1 + 2);
    uVar10 = *(undefined1 *)((longlong)puVar1 + 3);
    puVar1 = (undefined8 *)((longlong)puVar1 + 4);
    *puVar2 = uVar11;
    *(undefined1 *)((longlong)puVar2 + 1) = uVar12;
    *(undefined1 *)((longlong)puVar2 + 2) = uVar9;
    *(undefined1 *)((longlong)puVar2 + 3) = uVar10;
    puVar2 = (undefined1 *)((longlong)puVar2 + 4);
  }
  if (((uint)uVar29 >> 1 & 1) != 0) {
    uVar11 = *(undefined1 *)puVar1;
    uVar12 = *(undefined1 *)((longlong)puVar1 + 1);
    puVar1 = (undefined8 *)((longlong)puVar1 + 2);
    *puVar2 = uVar11;
    puVar2[1] = uVar12;
    puVar2 = puVar2 + 2;
  }
  if ((uVar24 & 1) != 0) {
    *puVar2 = *(undefined1 *)puVar1;
  }
  return;
}



// WARNING: Removing unreachable block (ram,0x0000e0d8)

undefined4 FUN_0000e0b0(void)

{
  FUN_00010698((undefined4 *)0xc264000,0);
  do {
  } while( true );
}



void FUN_0000e0e4(undefined1 *param_1,ulonglong param_2,byte *param_3,longlong *param_4)

{
  longlong local_30;
  longlong lStack_28;
  longlong local_20;
  longlong lStack_18;
  
  local_20 = param_4[2];
  lStack_18 = param_4[3];
  local_30 = *param_4;
  lStack_28 = param_4[1];
  FUN_0000e228(param_1,param_2,0,param_3,&local_30,(ulonglong *)0x0);
  return;
}



void FUN_0000e124(undefined1 *param_1,ulonglong param_2,byte *param_3)

{
  FUN_0000e0e4(param_1,param_2,param_3,(longlong *)&stack0xffffffffffffffa0);
  return;
}



void FUN_0000e19c(undefined1 *param_1,undefined1 *param_2,longlong param_3,undefined4 param_4,
                 longlong param_5)

{
  longlong lVar1;
  
  lVar1 = 0;
  for (; param_1 < param_2 && lVar1 < param_3; param_1 = param_1 + param_5) {
    *param_1 = (char)param_4;
    if (param_5 != 1) {
      param_1[1] = (char)((uint)param_4 >> 8);
    }
    lVar1 = lVar1 + 1;
  }
  return;
}



char * FUN_0000e1d0(char *param_1,ulonglong param_2,uint param_3)

{
  uint local_24;
  
  *param_1 = '\0';
  do {
    param_2 = FUN_00010900(param_2,param_3,(int *)&local_24);
    param_1 = param_1 + 1;
    *param_1 = "0123456789ABCDEFSuccess"[local_24];
  } while (param_2 != 0);
  return param_1;
}



// WARNING: Removing unreachable block (ram,0x0000e3b8)
// WARNING: Removing unreachable block (ram,0x0000e3c8)

ulonglong FUN_0000e228(undefined1 *param_1,ulonglong param_2,ulonglong param_3,byte *param_4,
                      longlong *param_5,ulonglong *param_6)

{
  byte *pbVar1;
  char cVar2;
  bool bVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  char *pcVar6;
  undefined1 *puVar7;
  int iVar8;
  char *pcVar9;
  ulonglong uVar10;
  uint uVar11;
  uint uVar12;
  ulonglong uVar13;
  int *piVar14;
  ulonglong uVar15;
  undefined2 *puVar16;
  ulonglong uVar17;
  ulonglong *puVar18;
  longlong lVar19;
  byte *pbVar20;
  ulonglong uVar21;
  undefined1 *local_108;
  ulonglong *local_f0;
  uint local_e0;
  ulonglong local_d8;
  ulonglong local_d0;
  ulonglong local_c8;
  int local_bc;
  undefined1 *local_b0;
  ulonglong local_a0;
  ulonglong local_98;
  ulonglong auStack_90 [5];
  longlong local_68;
  
  local_68 = _data;
  uVar12 = (uint)param_3;
  if (param_2 == 0) {
    if ((param_4 == (byte *)0x0) && ((uVar12 >> 0xd & 1) != 0)) goto LAB_0000e294;
  }
  else {
    if ((param_1 == (undefined1 *)0x0) && ((uVar12 >> 0xd & 1) == 0)) {
      FUN_0000464c();
      do {
                    // WARNING: Do nothing block with infinite loop
      } while( true );
    }
    if (param_4 == (byte *)0x0) {
LAB_0000e294:
      FUN_0000464c();
      do {
                    // WARNING: Do nothing block with infinite loop
      } while( true );
    }
  }
  if ((uVar12 >> 6 & 1) == 0) {
    uVar21 = 1;
    if (1000000 < param_2) {
      FUN_0000464c();
      do {
                    // WARNING: Do nothing block with infinite loop
      } while( true );
    }
  }
  else {
    uVar21 = 2;
    if (1000000 < param_2) {
      FUN_0000464c();
      do {
                    // WARNING: Do nothing block with infinite loop
      } while( true );
    }
  }
  if ((uVar12 >> 8 & 1) == 0) {
    uVar4 = FUN_00005148((char *)param_4,0xf4241);
    if (1000000 < uVar4) {
      FUN_0000464c();
      do {
                    // WARNING: Do nothing block with infinite loop
      } while( true );
    }
    uVar4 = FUN_00005148((char *)param_4,0xf4241);
    if (uVar4 < 0xf4241) {
      lVar19 = 1;
      local_d0 = 0xff;
LAB_0000e42c:
      if ((uVar12 >> 0xd & 1) == 0) {
        if (param_2 == 0) goto LAB_0000e438;
LAB_0000e444:
        local_108 = param_1;
        local_b0 = (undefined1 *)0x0;
        if (param_1 != (undefined1 *)0x0) {
          local_b0 = param_1 + uVar21 * (param_2 - 1);
        }
      }
      else {
        if (param_2 != 0) goto LAB_0000e444;
        local_108 = (undefined1 *)0x0;
        local_b0 = (undefined1 *)0x0;
      }
      if (lVar19 == 1) {
        uVar12 = 0;
      }
      else {
        uVar12 = (uint)param_4[1] << 8;
      }
      uVar4 = 0;
      uVar12 = uVar12 | *param_4;
      puVar7 = local_108;
      local_f0 = param_6;
      while( true ) {
        local_98 = local_d0 & (longlong)(int)uVar12;
        if ((local_98 == 0) || ((local_b0 <= puVar7 && (puVar7 != (undefined1 *)0x0)))) break;
        param_3 = param_3 & 0x2140;
        iVar8 = (int)local_98;
        if (iVar8 == 10) {
          pbVar20 = param_4 + lVar19;
          if (lVar19 == 1) {
            uVar12 = 0;
          }
          else {
            uVar12 = (uint)pbVar20[1] << 8;
          }
          local_98 = local_d0 & (uVar12 | *pbVar20);
          if (local_98 == 0xd) {
            local_d8 = 0;
            uVar5 = 0;
            local_bc = 0;
            bVar3 = false;
            local_c8 = 0;
            local_e0 = 0;
            pcVar6 = &UNK_0001533d;
            uVar10 = 1;
          }
          else {
            local_d8 = 0;
            uVar5 = 0;
            local_bc = 0;
            bVar3 = false;
            local_c8 = 0;
            local_e0 = 0;
            pcVar6 = &UNK_0001533d;
            uVar10 = 1;
            pbVar20 = param_4;
          }
        }
        else if (iVar8 == 0xd) {
          pbVar20 = param_4 + lVar19;
          if (lVar19 == 1) {
            uVar12 = 0;
          }
          else {
            uVar12 = (uint)pbVar20[1] << 8;
          }
          local_98 = local_d0 & (uVar12 | *pbVar20);
          if (local_98 == 10) {
            local_d8 = 0;
            uVar5 = 0;
            local_bc = 0;
            bVar3 = false;
            local_c8 = 0;
            local_e0 = 0;
            pcVar6 = &UNK_0001533d;
            uVar10 = 1;
          }
          else {
            local_d8 = 0;
            uVar5 = 0;
            local_bc = 0;
            bVar3 = false;
            local_c8 = 0;
            local_e0 = 0;
            pcVar6 = &UNK_00015340;
            uVar10 = 1;
            pbVar20 = param_4;
          }
        }
        else {
          if (iVar8 == 0x25) {
            local_d8 = 0;
            uVar5 = 0;
            uVar10 = 1;
            puVar18 = local_f0;
LAB_0000e4f4:
            bVar3 = true;
switchD_0000e630_caseD_2f:
            pbVar20 = param_4;
            if (bVar3) {
              param_4 = pbVar20 + lVar19;
              if (lVar19 == 1) {
                uVar12 = 0;
              }
              else {
                uVar12 = (uint)param_4[1] << 8;
              }
              goto LAB_0000e610;
            }
            uVar13 = param_3;
            local_f0 = puVar18;
            switch(local_98) {
            case 0x62:
            case 0x65:
            case 0x66:
            case 0x68:
            case 0x69:
            case 0x6a:
            case 0x6b:
            case 0x6c:
            case 0x6d:
            case 0x6e:
            case 0x6f:
            case 0x71:
            case 0x76:
            case 0x77:
              goto switchD_0000e780_caseD_62;
            case 99:
              if (puVar18 == (ulonglong *)0x0) {
                iVar8 = (int)param_5[3];
                if ((iVar8 < 0) && (*(int *)(param_5 + 3) = iVar8 + 8, iVar8 + 8 < 1)) {
                  puVar18 = (ulonglong *)(param_5[1] + (longlong)iVar8);
                }
                else {
                  puVar18 = (ulonglong *)*param_5;
                  *param_5 = (longlong)(puVar18 + 1);
                }
                local_f0 = (ulonglong *)0x0;
              }
              else {
                local_f0 = puVar18 + 1;
              }
              local_bc = 0;
              bVar3 = false;
              local_a0 = (ulonglong)(ushort)*puVar18;
              local_e0 = 0;
              local_c8 = 0;
              pcVar6 = (char *)&local_a0;
              param_3 = param_3 | 0x400;
              break;
            case 100:
              goto switchD_0000e780_caseD_64;
            case 0x67:
              if (puVar18 == (ulonglong *)0x0) {
                iVar8 = (int)param_5[3];
                if ((iVar8 < 0) && (*(int *)(param_5 + 3) = iVar8 + 8, iVar8 + 8 < 1)) {
                  puVar18 = (ulonglong *)(param_5[1] + (longlong)iVar8);
                }
                else {
                  puVar18 = (ulonglong *)*param_5;
                  *param_5 = (longlong)(puVar18 + 1);
                }
                local_f0 = (ulonglong *)0x0;
              }
              else {
                local_f0 = puVar18 + 1;
              }
              puVar16 = (undefined2 *)*puVar18;
              if (puVar16 != (undefined2 *)0x0) {
                FUN_00010adc(puVar16);
                FUN_00010a88(puVar16 + 2);
                FUN_00010a88(puVar16 + 3);
                FUN_0000f430();
                goto LAB_0000eebc;
              }
              local_bc = 0;
              bVar3 = false;
              local_c8 = 0;
              local_e0 = 0;
              pcVar6 = "<null guid>";
              break;
            case 0x70:
              param_3 = param_3 & 0xffffffffffffffc9 | 0x10;
LAB_0000e968:
              param_3 = param_3 | 0x20;
            case 0x78:
              param_3 = param_3 | 0x80;
switchD_0000e780_caseD_75:
              uVar13 = param_3 & 0xffffffffffffbffd | 0x4000;
              if ((param_3 & 0x80) != 0) {
                uVar13 = param_3;
              }
switchD_0000e780_caseD_64:
              uVar12 = (uint)uVar13;
              if ((uVar12 >> 4 & 1) == 0) {
                if (puVar18 != (ulonglong *)0x0) {
                  uVar5 = (ulonglong)(int)*puVar18;
                  goto LAB_0000e99c;
                }
                iVar8 = (int)param_5[3];
                if ((iVar8 < 0) && (*(int *)(param_5 + 3) = iVar8 + 8, iVar8 + 8 < 1)) {
                  piVar14 = (int *)(param_5[1] + (longlong)iVar8);
                }
                else {
                  piVar14 = (int *)*param_5;
                  *param_5 = (longlong)(piVar14 + 2);
                }
                uVar5 = (ulonglong)*piVar14;
LAB_0000ea20:
                local_f0 = (ulonglong *)0x0;
              }
              else {
                if (puVar18 == (ulonglong *)0x0) {
                  iVar8 = (int)param_5[3];
                  if ((iVar8 < 0) && (*(int *)(param_5 + 3) = iVar8 + 8, iVar8 + 8 < 1)) {
                    puVar18 = (ulonglong *)(param_5[1] + (longlong)iVar8);
                  }
                  else {
                    puVar18 = (ulonglong *)*param_5;
                    *param_5 = (longlong)(puVar18 + 1);
                  }
                  uVar5 = *puVar18;
                  goto LAB_0000ea20;
                }
                uVar5 = *puVar18;
LAB_0000e99c:
                local_f0 = puVar18 + 1;
              }
              local_bc = (uVar12 & 4) << 3;
              if ((uVar13 & 2) != 0) {
                local_bc = 0x2b;
              }
              if ((uVar12 >> 7 & 1) == 0) {
                local_e0 = (uint)(uVar13 >> 3) & 1;
                if ((uVar13 & 8) != 0) {
                  uVar10 = 1;
                  uVar13 = uVar13 & 0xffffffffffffffdf;
                }
                if (((uint)uVar13 >> 0xe == 0) && ((longlong)uVar5 < 0)) {
                  local_bc = 0x2d;
                  uVar15 = -uVar5;
                  uVar12 = 10;
                }
                else {
                  uVar15 = uVar5 & 0xffffffff;
                  if ((uVar13 & 0x4010) != 0x4000) {
                    uVar15 = uVar5;
                  }
                  uVar12 = 10;
                }
              }
              else {
                local_e0 = 0;
                uVar15 = uVar5 & 0xffffffff;
                if (-1 < (longlong)uVar5 || (uVar13 & 0x10) != 0) {
                  uVar15 = uVar5;
                }
                uVar12 = 0x10;
              }
              pcVar6 = FUN_0000e1d0((char *)auStack_90,uVar15,uVar12);
              if (uVar15 == 0 && uVar10 == 0) {
                uVar5 = 0;
                pcVar6 = (char *)auStack_90;
                local_c8 = 0;
              }
              else {
                uVar5 = (longlong)pcVar6 - (longlong)auStack_90;
                local_c8 = 0;
                if (uVar5 % 3 != 0) {
                  local_c8 = uVar5 % 3 ^ 3;
                }
                if ((local_e0 != 0) && (uVar5 != 0)) {
                  uVar5 = (uVar5 - 1) / 3 + uVar5;
                }
              }
              param_3 = uVar13 | 0x1000;
              bVar3 = true;
              if (local_bc != 0) {
                uVar10 = uVar10 + 1;
                uVar5 = uVar5 + 1;
              }
              if ((uVar13 & 0xa21) == 0x220) {
                uVar10 = local_d8;
              }
              break;
            case 0x72:
              if (puVar18 == (ulonglong *)0x0) {
                iVar8 = (int)param_5[3];
                if ((iVar8 < 0) && (*(int *)(param_5 + 3) = iVar8 + 8, iVar8 + 8 < 1)) {
                  puVar18 = (ulonglong *)(param_5[1] + (longlong)iVar8);
                }
                else {
                  puVar18 = (ulonglong *)*param_5;
                  *param_5 = (longlong)(puVar18 + 1);
                }
                local_f0 = (ulonglong *)0x0;
              }
              else {
                local_f0 = puVar18 + 1;
              }
              uVar13 = *puVar18;
              if ((longlong)uVar13 < 0) {
                if ((uVar13 & 0x7fffffffffffffff) - 1 < 0x21) {
                  uVar13 = (uVar13 & 0x7fffffffffffffff) + 5;
                  goto LAB_0000ef08;
                }
LAB_0000ef20:
                pcVar6 = (char *)auStack_90;
                FUN_0000f430();
              }
              else {
                if (5 < uVar13) goto LAB_0000ef20;
LAB_0000ef08:
                pcVar6 = (&PTR_s_Success_00015348)[uVar13];
                if ((ulonglong *)pcVar6 == auStack_90) goto LAB_0000ef20;
              }
              local_bc = 0;
              bVar3 = false;
              local_e0 = 0;
              local_c8 = 0;
              break;
            case 0x73:
switchD_0000e780_caseD_73:
              param_3 = param_3 | 0x400;
            case 0x61:
              if (puVar18 == (ulonglong *)0x0) {
                iVar8 = (int)param_5[3];
                if ((iVar8 < 0) && (*(int *)(param_5 + 3) = iVar8 + 8, iVar8 + 8 < 1)) {
                  puVar18 = (ulonglong *)(param_5[1] + (longlong)iVar8);
                }
                else {
                  puVar18 = (ulonglong *)*param_5;
                  *param_5 = (longlong)(puVar18 + 1);
                }
                local_f0 = (ulonglong *)0x0;
              }
              else {
                local_f0 = puVar18 + 1;
              }
              pcVar6 = "<null string>";
              uVar13 = param_3 & 0xfffffffffffffbff;
              if ((ulonglong *)*puVar18 != (ulonglong *)0x0) {
                pcVar6 = (char *)*puVar18;
                uVar13 = param_3;
              }
              param_3 = uVar13;
              if (((uint)param_3 >> 0xb & 1) == 0) {
                uVar10 = 0;
LAB_0000eec4:
                local_bc = 0;
                bVar3 = false;
                local_e0 = 0;
                local_c8 = 0;
              }
              else {
                local_bc = 0;
                bVar3 = false;
                local_e0 = 0;
                local_c8 = 0;
              }
              break;
            case 0x74:
              if (puVar18 == (ulonglong *)0x0) {
                iVar8 = (int)param_5[3];
                if ((iVar8 < 0) && (*(int *)(param_5 + 3) = iVar8 + 8, iVar8 + 8 < 1)) {
                  puVar18 = (ulonglong *)(param_5[1] + (longlong)iVar8);
                }
                else {
                  puVar18 = (ulonglong *)*param_5;
                  *param_5 = (longlong)(puVar18 + 1);
                }
                local_f0 = (ulonglong *)0x0;
              }
              else {
                local_f0 = puVar18 + 1;
              }
              if (*puVar18 != 0) {
                FUN_0000f430();
LAB_0000eebc:
                pcVar6 = (char *)auStack_90;
                goto LAB_0000eec4;
              }
              local_bc = 0;
              bVar3 = false;
              local_c8 = 0;
              local_e0 = 0;
              pcVar6 = "<null time>";
              break;
            case 0x75:
              goto switchD_0000e780_caseD_75;
            default:
              if (local_98 == 10) {
                pbVar1 = pbVar20 + lVar19;
                if (lVar19 == 1) {
                  uVar12 = 0;
                }
                else {
                  uVar12 = (uint)pbVar1[1] << 8;
                }
                local_98 = local_d0 & (uVar12 | *pbVar1);
                if (local_98 == 0xd) {
                  pbVar20 = pbVar1;
                }
                local_bc = 0;
                local_c8 = 0;
                pcVar6 = &UNK_0001533d;
                bVar3 = false;
                local_e0 = 0;
              }
              else if (local_98 == 0xd) {
                pbVar1 = pbVar20 + lVar19;
                if (lVar19 == 1) {
                  uVar12 = 0;
                }
                else {
                  uVar12 = (uint)pbVar1[1] << 8;
                }
                local_98 = local_d0 & (uVar12 | *pbVar1);
                if (local_98 == 10) {
                  pcVar6 = &UNK_0001533d;
                  pbVar20 = pbVar1;
                }
                else {
                  pcVar6 = &UNK_00015340;
                }
                local_bc = 0;
                local_c8 = 0;
                bVar3 = false;
                local_e0 = 0;
              }
              else {
                if (local_98 == 0x53) goto switchD_0000e780_caseD_73;
                if (local_98 == 0x58) goto LAB_0000e968;
switchD_0000e780_caseD_62:
                local_bc = 0;
                bVar3 = false;
                local_e0 = 0;
                local_c8 = 0;
                pcVar6 = (char *)&local_98;
                param_3 = param_3 | 0x400;
              }
            }
            goto LAB_0000ef84;
          }
          uVar5 = 0;
          local_d8 = 0;
          bVar3 = false;
          local_bc = 0;
          local_e0 = 0;
          local_c8 = 0;
          pcVar6 = (char *)&local_98;
          param_3 = param_3 | 0x400;
          uVar10 = 1;
          pbVar20 = param_4;
        }
LAB_0000ef84:
        uVar12 = 0xffff;
        if ((param_3 & 0x400) == 0) {
          uVar12 = 0xff;
        }
        uVar13 = param_3 >> 10 & 1;
        uVar11 = (uint)param_3;
        if ((uVar11 >> 0xc & 1) == 0) {
          uVar5 = 0;
          uVar13 = uVar13 + 1;
          pcVar9 = (char *)((longlong)pcVar6 + 1);
          do {
            if (pcVar9[-1] == '\0') {
              if ((param_3 & 0x400) == 0) goto LAB_0000f010;
              cVar2 = *pcVar9;
              if ((cVar2 == '\0') || ((param_3 & 0x800) != 0 && uVar10 <= uVar5)) goto LAB_0000f010;
            }
            else {
              if (((uVar11 >> 0xb & 1) != 0) && (uVar10 <= uVar5)) goto LAB_0000f010;
              cVar2 = *pcVar9;
            }
            if ((CONCAT11(cVar2,pcVar9[-1]) & uVar12) == 0) goto LAB_0000f010;
            uVar5 = uVar5 + 1;
            pcVar9 = pcVar9 + uVar13;
          } while( true );
        }
        uVar13 = ~uVar13;
LAB_0000f010:
        uVar15 = uVar5;
        if (uVar5 <= uVar10) {
          uVar15 = uVar10;
        }
        if ((param_3 & 0x201) == 0x200) {
          uVar4 = uVar4 + (local_d8 - uVar15) * uVar21;
          if ((puVar7 != (undefined1 *)0x0) && ((uVar11 >> 0xd & 1) == 0)) {
            puVar7 = (undefined1 *)FUN_0000e19c(puVar7,local_b0,local_d8 - uVar15,0x20,uVar21);
          }
        }
        if (bVar3) {
          if (((local_bc != 0) && (uVar4 = uVar4 + uVar21, (uVar11 >> 0xd & 1) == 0)) &&
             (puVar7 != (undefined1 *)0x0)) {
            puVar7 = (undefined1 *)FUN_0000e19c(puVar7,local_b0,1,local_bc,uVar21);
          }
          uVar4 = uVar4 + (uVar15 - uVar5) * uVar21;
          if (((uVar11 >> 0xd & 1) == 0) && (puVar7 != (undefined1 *)0x0)) {
            puVar7 = (undefined1 *)FUN_0000e19c(puVar7,local_b0,uVar15 - uVar5,0x30,uVar21);
          }
          if (local_bc != 0) goto LAB_0000f18c;
LAB_0000f194:
          uVar10 = 0;
        }
        else {
          if (((uVar11 >> 0xd & 1) == 0) && (puVar7 != (undefined1 *)0x0)) {
            puVar7 = (undefined1 *)FUN_0000e19c(puVar7,local_b0,uVar15 - uVar5,0x20,uVar21);
          }
          uVar4 = uVar4 + (uVar15 - uVar5) * uVar21;
          if (local_bc == 0) goto LAB_0000f194;
          uVar4 = uVar4 + uVar21;
          if (((uVar11 >> 0xd & 1) == 0) && (puVar7 != (undefined1 *)0x0)) {
            puVar7 = (undefined1 *)FUN_0000e19c(puVar7,local_b0,1,local_bc,uVar21);
          }
LAB_0000f18c:
          uVar10 = 1;
        }
        while ((uVar17 = uVar10, uVar17 < uVar5 &&
               (((char)*(ulonglong *)pcVar6 != '\0' ||
                ((1 < (longlong)uVar13 && (*(char *)((longlong)pcVar6 + 1) != '\0'))))))) {
          uVar4 = uVar4 + uVar21;
          if (((uVar11 >> 0xd & 1) == 0) && (puVar7 != (undefined1 *)0x0)) {
            puVar7 = (undefined1 *)
                     FUN_0000e19c(puVar7,local_b0,1,
                                  CONCAT11(*(char *)((longlong)pcVar6 + 1),
                                           (char)*(ulonglong *)pcVar6) & uVar12,uVar21);
          }
          pcVar6 = (char *)((longlong)pcVar6 + uVar13);
          uVar10 = uVar17 + 1;
          if ((local_e0 != 0) && (local_c8 = local_c8 + 1, local_c8 == 3)) {
            uVar10 = uVar17 + 2;
            local_c8 = 0;
            if (uVar10 < uVar5) {
              uVar4 = uVar21 + uVar4;
              local_c8 = 0;
              if (((uVar11 >> 0xd & 1) == 0) && (puVar7 != (undefined1 *)0x0)) {
                puVar7 = (undefined1 *)FUN_0000e19c(puVar7,local_b0,1,0x2c,uVar21);
                local_c8 = 0;
              }
            }
          }
        }
        if ((param_3 & 0x201) == 0x201) {
          uVar4 = uVar4 + (local_d8 - uVar15) * uVar21;
          if (((uVar11 >> 0xd & 1) == 0) && (puVar7 != (undefined1 *)0x0)) {
            puVar7 = (undefined1 *)FUN_0000e19c(puVar7,local_b0,local_d8 - uVar15,0x20,uVar21);
          }
        }
        param_4 = pbVar20 + lVar19;
        if (lVar19 == 1) {
          uVar12 = 0;
        }
        else {
          uVar12 = (uint)param_4[1] << 8;
        }
        uVar12 = uVar12 | *param_4;
      }
      if (((uint)param_3 >> 0xd & 1) == 0) {
        if (puVar7 == (undefined1 *)0x0) {
          FUN_0000464c();
          do {
                    // WARNING: Do nothing block with infinite loop
          } while( true );
        }
        FUN_0000e19c(puVar7,local_b0 + uVar21,1,0,uVar21);
        uVar5 = 0;
        if (uVar21 != 0) {
          uVar5 = ((longlong)puVar7 - (longlong)local_108) / (longlong)uVar21;
        }
      }
      else {
        uVar5 = 0;
        if (uVar21 != 0) {
          uVar5 = uVar4 / uVar21;
        }
      }
      goto LAB_0000f3dc;
    }
  }
  else {
    uVar4 = FUN_000050e0((short *)param_4,0xf4241);
    if (1000000 < uVar4) {
      FUN_0000464c();
      do {
                    // WARNING: Do nothing block with infinite loop
      } while( true );
    }
    uVar4 = FUN_000050e0((short *)param_4,0xf4241);
    if (uVar4 < 0xf4241) {
      lVar19 = 2;
      local_d0 = 0xffff;
      goto LAB_0000e42c;
    }
  }
LAB_0000e438:
  uVar5 = 0;
LAB_0000f3dc:
  if (_data == local_68) {
    return uVar5;
  }
                    // WARNING: Subroutine does not return
  FUN_000010d8();
LAB_0000e610:
  local_98 = local_d0 & (uVar12 | *param_4);
  iVar8 = (int)local_98;
  bVar3 = false;
  switch(iVar8) {
  case 0x2a:
    if (((uint)param_3 >> 0xb & 1) == 0) {
      param_3 = param_3 | 0x200;
      if (puVar18 != (ulonglong *)0x0) {
        local_d8 = *puVar18;
        puVar18 = puVar18 + 1;
        goto LAB_0000e4f4;
      }
      iVar8 = (int)param_5[3];
      if ((iVar8 < 0) && (*(int *)(param_5 + 3) = iVar8 + 8, iVar8 + 8 < 1)) {
        puVar18 = (ulonglong *)(param_5[1] + (longlong)iVar8);
      }
      else {
        puVar18 = (ulonglong *)*param_5;
        *param_5 = (longlong)(puVar18 + 1);
      }
      local_d8 = *puVar18;
      puVar18 = (ulonglong *)0x0;
      bVar3 = true;
    }
    else {
      if (puVar18 != (ulonglong *)0x0) {
        uVar10 = *puVar18;
        puVar18 = puVar18 + 1;
        goto LAB_0000e4f4;
      }
      iVar8 = (int)param_5[3];
      if ((iVar8 < 0) && (*(int *)(param_5 + 3) = iVar8 + 8, iVar8 + 8 < 1)) {
        puVar18 = (ulonglong *)(param_5[1] + (longlong)iVar8);
      }
      else {
        puVar18 = (ulonglong *)*param_5;
        *param_5 = (longlong)(puVar18 + 1);
      }
      uVar10 = *puVar18;
      puVar18 = (ulonglong *)0x0;
      bVar3 = true;
    }
    goto switchD_0000e630_caseD_2f;
  case 0x2b:
    break;
  case 0x2c:
    param_3 = param_3 | 8;
    goto LAB_0000e4f4;
  case 0x2d:
    param_3 = param_3 | 1;
    goto LAB_0000e4f4;
  case 0x2e:
    param_3 = param_3 | 0x800;
    goto LAB_0000e4f4;
  case 0x2f:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
  case 0x40:
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4a:
  case 0x4b:
    goto switchD_0000e630_caseD_2f;
  case 0x30:
    param_3 = (ulonglong)((uint)param_3 >> 6 ^ 0xffffffff) & 0x20 | param_3;
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
    uVar5 = 0;
    while (local_98 - 0x30 < 10) {
      uVar5 = (local_98 - 0x30) + uVar5 * 10;
      if (lVar19 == 1) {
        uVar12 = 0;
      }
      else {
        uVar12 = (uint)pbVar20[lVar19 * 2 + 1] << 8;
      }
      local_98 = local_d0 & (uVar12 | pbVar20[lVar19 * 2]);
      pbVar20 = pbVar20 + lVar19;
    }
    uVar13 = uVar5;
    if ((param_3 & 0x800) != 0) {
      uVar10 = uVar5;
      uVar13 = local_d8;
    }
    local_d8 = uVar13;
    param_3 = (param_3 & 0x800) >> 2 ^ 0x200 | param_3;
    bVar3 = true;
    param_4 = pbVar20;
    goto switchD_0000e630_caseD_2f;
  default:
    if (iVar8 == 0) {
      uVar10 = 0;
      bVar3 = false;
      param_4 = pbVar20;
      goto switchD_0000e630_caseD_2f;
    }
    if (iVar8 == 0x20) {
      param_3 = param_3 | 4;
      goto LAB_0000e4f4;
    }
    bVar3 = false;
    if (iVar8 != 0x6c) goto switchD_0000e630_caseD_2f;
  case 0x4c:
    param_3 = param_3 | 0x10;
    goto LAB_0000e4f4;
  }
  param_3 = param_3 | 2;
  goto LAB_0000e4f4;
}



void FUN_0000f430(void)

{
  undefined1 *in_x0;
  ulonglong in_x1;
  ulonglong in_x2;
  byte *in_x3;
  
  FUN_0000e228(in_x0,in_x1,in_x2,in_x3,(longlong *)&stack0xffffffffffffffb0,(ulonglong *)0x0);
  return;
}



undefined8 FUN_0000f4a0(void)

{
  longlong lVar1;
  undefined8 uVar2;
  
  lVar1 = FUN_000105d0();
  if (lVar1 != 0) {
                    // WARNING: Could not recover jumptable at 0x0000f4d0. Too many branches
                    // WARNING: Treating indirect jump as call
    uVar2 = (**(code **)(lVar1 + 0x10))("SerialPort Lib",0,&DAT_00018410);
    return uVar2;
  }
  return 0x8000000000000007;
}



undefined8 FUN_0000f4e0(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (DAT_00018410 == 0) {
    FUN_0000f4a0();
    if (DAT_00018410 == 0) {
      return 0;
    }
  }
                    // WARNING: Could not recover jumptable at 0x0000f528. Too many branches
                    // WARNING: Treating indirect jump as call
  uVar1 = (**(code **)(DAT_00018410 + 0x10))(param_1,param_2);
  return uVar1;
}



undefined8 FUN_0000f540(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  if (DAT_00018410 == 0) {
    FUN_0000f4a0();
    if (DAT_00018410 == 0) {
      return 0;
    }
  }
                    // WARNING: Could not recover jumptable at 0x0000f588. Too many branches
                    // WARNING: Treating indirect jump as call
  uVar1 = (**(code **)(DAT_00018410 + 0x30))(param_1,param_2);
  return uVar1;
}



undefined8 FUN_0000f5a0(void)

{
  undefined8 uVar1;
  
  if (DAT_00018410 == 0) {
    FUN_0000f4a0();
    if (DAT_00018410 == 0) {
      return 0;
    }
  }
                    // WARNING: Could not recover jumptable at 0x0000f5d0. Too many branches
                    // WARNING: Treating indirect jump as call
  uVar1 = (**(code **)(DAT_00018410 + 0x28))();
  return uVar1;
}



void FUN_0000f5e4(void)

{
  FUN_0000f540(3,1);
  return;
}



undefined8 FUN_0000f5f0(uint param_1)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  if ((((DAT_00018418 & 1) != 0) || (uVar2 = FUN_0000f690(), (int)uVar2 == 0)) &&
     (iVar1 = FUN_00003e88(param_1), iVar1 != 0)) {
    lVar3 = (**(code **)(DAT_00018420 + 0x10))
                      (DAT_00018420,*(undefined8 *)(&DAT_00016ea8 + (ulonglong)param_1 * 0x20));
    if (lVar3 == 0) {
      return 0;
    }
    if (lVar3 < 0) {
      FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
      FUN_0000464c();
    }
  }
  return 1;
}



undefined8 FUN_0000f690(void)

{
  int iVar1;
  longlong lVar2;
  undefined8 uVar3;
  uint uVar4;
  ulonglong uVar5;
  
  if (DAT_00018420 == 0) {
    lVar2 = (**(code **)(DAT_00017260 + 0x140))(&DAT_00016258,0,&DAT_00018420);
    if ((lVar2 == 0) && (DAT_00018420 != 0)) {
joined_r0x0000f724:
      if (DAT_00018420 != 0) goto LAB_0000f728;
    }
    else {
      DAT_00018420 = 0;
      if (lVar2 < 0) {
        FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
        FUN_0000464c();
        goto joined_r0x0000f724;
      }
    }
LAB_0000f804:
    uVar3 = 1;
  }
  else {
LAB_0000f728:
    uVar3 = FUN_00003f78();
    for (uVar4 = 0; (uVar4 & 0xff) < (uint)uVar3; uVar4 = uVar4 + 1) {
      uVar4 = uVar4 & 0xff;
      uVar5 = (ulonglong)uVar4;
      iVar1 = FUN_00003e88(uVar4);
      if (iVar1 != 0) {
        lVar2 = (**(code **)(DAT_00018420 + 8))
                          (DAT_00018420,(&PTR_s_gcc_sdcc1_apps_clk_00016ea0)[uVar5 * 4],
                           &DAT_00016ea8 + uVar5 * 0x20);
        if (lVar2 == 0) {
          lVar2 = (**(code **)(DAT_00018420 + 8))
                            (DAT_00018420,(&PTR_s_gcc_sdcc1_ahb_clk_00016eb0)[uVar5 * 4],
                             &DAT_00016eb8 + uVar5 * 0x20);
          if (lVar2 == 0) goto LAB_0000f78c;
          if (-1 < lVar2) goto LAB_0000f804;
          FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
        }
        else {
          if (-1 < lVar2) goto LAB_0000f804;
          FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
        }
        FUN_0000464c();
        goto LAB_0000f804;
      }
LAB_0000f78c:
    }
    uVar3 = 0;
    DAT_00018418 = 1;
  }
  return uVar3;
}



undefined8 FUN_0000f81c(uint param_1)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  if ((((DAT_00018418 & 1) != 0) || (uVar2 = FUN_0000f690(), (int)uVar2 == 0)) &&
     (iVar1 = FUN_00003e88(param_1), iVar1 != 0)) {
    lVar3 = (**(code **)(DAT_00018420 + 0x18))
                      (DAT_00018420,*(undefined8 *)(&DAT_00016ea8 + (ulonglong)param_1 * 0x20));
    if (lVar3 == 0) {
      return 0;
    }
    if (lVar3 < 0) {
      FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
      FUN_0000464c();
    }
  }
  return 1;
}



undefined8 FUN_0000f8bc(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined4 local_24;
  
  local_24 = 0;
  if ((((DAT_00018418 & 1) != 0) || (uVar2 = FUN_0000f690(), (int)uVar2 == 0)) &&
     (iVar1 = FUN_00003e88(param_1), iVar1 != 0)) {
    lVar3 = (**(code **)(DAT_00018420 + 0x30))
                      (DAT_00018420,*(undefined8 *)(&DAT_00016ea8 + (ulonglong)param_1 * 0x20),
                       param_2,1,&local_24);
    if (lVar3 == 0) {
      return 0;
    }
    if (lVar3 < 0) {
      FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
      FUN_0000464c();
    }
  }
  return 1;
}



undefined8 FUN_0000f978(uint param_1)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  if ((((DAT_00018418 & 1) != 0) || (uVar2 = FUN_0000f690(), (int)uVar2 == 0)) &&
     (iVar1 = FUN_00003e88(param_1), iVar1 != 0)) {
    uVar2 = *(undefined8 *)(&DAT_00016ea8 + (ulonglong)param_1 * 0x20);
    lVar3 = (**(code **)(DAT_00018420 + 0x18))(DAT_00018420,uVar2);
    if (lVar3 == 0) {
      FUN_00010c0c(100);
      lVar3 = (**(code **)(DAT_00018420 + 0x10))(DAT_00018420,uVar2);
      if (lVar3 == 0) {
        return 0;
      }
      if (-1 < lVar3) {
        return 1;
      }
      FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
    }
    else {
      if (-1 < lVar3) {
        return 1;
      }
      FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
    }
    FUN_0000464c();
  }
  return 1;
}



undefined8 FUN_0000fa64(uint param_1)

{
  int iVar1;
  undefined8 uVar2;
  longlong lVar3;
  
  if ((((DAT_00018418 & 1) != 0) || (uVar2 = FUN_0000f690(), (int)uVar2 == 0)) &&
     (iVar1 = FUN_00003e88(param_1), iVar1 != 0)) {
    lVar3 = (**(code **)(DAT_00018420 + 0x10))
                      (DAT_00018420,*(undefined8 *)(&DAT_00016eb8 + (ulonglong)param_1 * 0x20));
    if (lVar3 == 0) {
      return 0;
    }
    if (lVar3 < 0) {
      FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
      FUN_0000464c();
    }
  }
  return 1;
}



longlong FUN_0000fb04(longlong param_1,byte *param_2)

{
  byte bVar1;
  ushort uVar2;
  longlong lVar3;
  longlong lVar4;
  ushort *puVar5;
  uint uVar6;
  undefined8 local_50;
  longlong local_48;
  ushort auStack_40 [16];
  
  local_48 = 0;
  lVar3 = (**(code **)(param_1 + 8))(param_1,&local_48);
  if (lVar3 == 0) {
    local_50 = 0;
    lVar3 = (**(code **)(local_48 + 0x40))(local_48,&DAT_000160e8,&local_50,0);
    if (lVar3 == -0x7ffffffffffffffb) {
      lVar3 = FUN_0000404c(local_50);
      lVar4 = (**(code **)(local_48 + 0x40))(local_48,&DAT_000160e8,&local_50,lVar3);
      if (lVar4 == 0) {
        if (lVar3 != 0) {
          puVar5 = auStack_40;
          for (uVar6 = 0; uVar6 < 0xf; uVar6 = uVar6 + 1) {
            bVar1 = *param_2;
            if (bVar1 == 0) break;
            uVar2 = bVar1 - 0x20;
            if (0x19 < bVar1 - 0x61) {
              uVar2 = (ushort)bVar1;
            }
            param_2 = param_2 + 1;
            *puVar5 = uVar2;
            puVar5 = puVar5 + 1;
          }
          *puVar5 = 0;
          for (lVar4 = 0x12; (int)lVar4 - 0x12U < 0xf; lVar4 = lVar4 + 1) {
            uVar2 = *(ushort *)(lVar3 + lVar4 * 2);
            if (uVar2 == 0) break;
            if (uVar2 - 0x61 < 0x1a) {
              *(ushort *)(lVar3 + lVar4 * 2) = uVar2 - 0x20;
            }
          }
          lVar3 = FUN_00004dc4((ushort *)(lVar3 + 0x24),auStack_40,0x10);
          FUN_00004100();
          (**(code **)(local_48 + 0x10))();
          return (longlong)(int)lVar3;
        }
      }
      else {
        FUN_00004100();
      }
    }
  }
  return 1;
}



longlong FUN_0000fc54(ushort *param_1,ushort *param_2)

{
  uint uVar1;
  ushort uVar2;
  ushort uVar3;
  longlong lVar4;
  uint uVar5;
  
  lVar4 = -1;
  if ((param_1 != (ushort *)0x0) && (param_2 != (ushort *)0x0)) {
    lVar4 = FUN_00004d1c((short *)param_1);
    if (lVar4 == 0) {
      FUN_0000464c();
      do {
                    // WARNING: Do nothing block with infinite loop
      } while( true );
    }
    lVar4 = FUN_00004d1c((short *)param_2);
    if (lVar4 == 0) {
      FUN_0000464c();
      do {
                    // WARNING: Do nothing block with infinite loop
      } while( true );
    }
    lVar4 = FUN_00004d1c((short *)param_1);
    if ((lVar4 == 0) || (lVar4 = FUN_00004d1c((short *)param_2), lVar4 == 0)) {
      lVar4 = -1;
    }
    else {
      while( true ) {
        uVar2 = *param_1;
        uVar3 = *param_2;
        uVar5 = uVar3 - 0x20;
        uVar1 = uVar2 - 0x20;
        if (0x19 < uVar2 - 0x61) {
          uVar1 = (uint)uVar2;
        }
        if (0x19 < uVar3 - 0x61) {
          uVar5 = (uint)uVar3;
        }
        if ((uVar2 == 0) || (((uVar5 ^ uVar1) & 0xffff) != 0)) break;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
      }
      lVar4 = (longlong)(int)((uVar1 & 0xffff) - (uVar5 & 0xffff));
    }
  }
  return lVar4;
}



undefined8 FUN_0000fd3c(uint param_1,undefined8 *param_2,longlong param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  longlong lVar4;
  char *pcVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  ulonglong uVar9;
  char *pcVar10;
  ulonglong uVar11;
  char *pcVar12;
  uint local_a4;
  undefined1 auStack_a0 [8];
  longlong *local_98;
  longlong local_90;
  longlong local_88;
  char *local_80;
  ulonglong local_78;
  longlong local_70;
  longlong local_68;
  
  uVar7 = 0x8000000000000002;
  if ((param_3 != 0) && (param_4 != (uint *)0x0)) {
    uVar1 = param_1 | 3;
    if ((param_1 & 3) != 0) {
      uVar1 = param_1;
    }
    uVar2 = uVar1 | 0xc;
    if ((uVar1 & 0xc) != 0) {
      uVar2 = uVar1;
    }
    if ((uVar2 & 0x60) == 0) {
      puVar6 = &DAT_000161c8;
    }
    else {
      puVar6 = &DAT_00016268;
    }
    (**(code **)(DAT_00017260 + 0x138))(2,puVar6,0,&local_78,&local_70);
    local_a4 = 0;
    for (uVar11 = 0; uVar11 < local_78; uVar11 = uVar11 + 1) {
      lVar4 = (**(code **)(DAT_00017260 + 0x98))
                        (*(undefined8 *)(local_70 + uVar11 * 8),&DAT_000161c8,&local_68);
      if (lVar4 != -0x7ffffffffffffffd) {
        if (lVar4 < 0) {
          FUN_00004548(0x80000000,(byte *)"\nASSERT_EFI_ERROR (Status = %r)\n");
          FUN_0000464c();
        }
        uVar1 = uVar2;
        if (*(char *)(*(longlong *)(local_68 + 8) + 4) == '\0') {
          uVar1 = uVar2 >> 1;
        }
        if ((uVar1 & 1) != 0) {
          if ((uVar2 & 0x19c) == 0) {
            pcVar10 = (char *)0x0;
            goto joined_r0x0001008c;
          }
          lVar4 = (**(code **)(DAT_00017260 + 0x98))
                            (*(undefined8 *)(local_70 + uVar11 * 8),&DAT_000161e8,&local_80);
          pcVar10 = local_80;
          if (-1 < lVar4) {
            if ((uVar2 & 0x180) != 0) {
              if (param_2 == (undefined8 *)0x0) {
                return 0x8000000000000002;
              }
              if ((((*local_80 != '\x01') || (local_80[1] != '\x04')) ||
                  (*(short *)(local_80 + 2) != 0x14)) ||
                 (((longlong *)*param_2 != (longlong *)0x0 &&
                  (bVar3 = FUN_000106d8((longlong *)*param_2,(undefined8 *)(local_80 + 4)), !bVar3))
                 )) goto LAB_00010104;
            }
            uVar9 = 0;
            pcVar12 = pcVar10;
            while (bVar3 = FUN_00010b34(pcVar12), !bVar3) {
              uVar9 = uVar9 + 1;
              pcVar5 = (char *)FUN_00010bc0((longlong)pcVar12);
              pcVar10 = pcVar12;
              pcVar12 = pcVar5;
            }
            if ((((uVar2 >> 7 & 1) == 0) || (bVar3 = thunk_FUN_0001063c(), uVar9 < 2)) || (bVar3)) {
              if (((*pcVar10 == '\x04') && (pcVar10[1] == '\x01')) &&
                 (*(short *)(pcVar10 + 2) == 0x2a)) {
                if ((((uVar2 >> 2 & 1) != 0) || (pcVar10[0x28] != '\x02')) &&
                   (((uVar2 >> 3 & 1) != 0 || (pcVar10[0x28] != '\x01')))) {
                  if ((uVar2 >> 4 & 1) != 0) {
                    if (param_2 == (undefined8 *)0x0) {
                      return 0x8000000000000002;
                    }
                    if (param_2[1] == 0) {
                      return 0x8000000000000002;
                    }
                    lVar4 = (**(code **)(DAT_00017260 + 0x98))
                                      (*(undefined8 *)(local_70 + uVar11 * 8),param_2[1],auStack_a0)
                    ;
                    if ((lVar4 < 0) &&
                       ((lVar4 = (**(code **)(DAT_00017260 + 0x98))
                                           (*(undefined8 *)(local_70 + uVar11 * 8),&DAT_000160f8,
                                            &local_98), lVar4 != 0 ||
                        (bVar3 = FUN_000106d8(local_98,(undefined8 *)param_2[1]), !bVar3))))
                    goto LAB_00010104;
                  }
joined_r0x0001008c:
                  if ((uVar2 >> 5 & 1) != 0) {
                    lVar4 = (**(code **)(DAT_00017260 + 0x98))
                                      (*(undefined8 *)(local_70 + uVar11 * 8),&DAT_00016268,
                                       &local_88);
                    if (lVar4 != 0) goto LAB_00010104;
                    if ((uVar2 >> 6 & 1) != 0) {
                      if ((param_2 == (undefined8 *)0x0) || ((byte *)param_2[2] == (byte *)0x0)) {
                        return 0x8000000000000002;
                      }
                      lVar4 = FUN_0000fb04(local_88,(byte *)param_2[2]);
                      if (lVar4 != 0) goto LAB_00010104;
                    }
                  }
                  if ((uVar2 >> 9 & 1) == 0) {
LAB_0000ff50:
                    puVar8 = (undefined8 *)(param_3 + (ulonglong)local_a4 * 0x18);
                    local_a4 = local_a4 + 1;
                    *puVar8 = *(undefined8 *)(local_70 + uVar11 * 8);
                    puVar8[1] = local_68;
                    puVar8[2] = pcVar10;
                    if (*param_4 <= local_a4) break;
                  }
                  else {
                    lVar4 = (**(code **)(DAT_00017260 + 0x98))
                                      (*(undefined8 *)(local_70 + uVar11 * 8),&DAT_000162a8,
                                       &local_90);
                    if (lVar4 == 0) {
                      if ((uVar2 >> 10 & 1) == 0) {
                        lVar4 = FUN_00004d38((ushort *)(local_90 + 0x38),(ushort *)param_2[3]);
                      }
                      else {
                        lVar4 = FUN_0000fc54((ushort *)(local_90 + 0x38),(ushort *)param_2[3]);
                      }
                      if (lVar4 == 0) goto LAB_0000ff50;
                    }
                  }
                }
              }
              else if ((uVar2 >> 4 & 1) == 0) {
                pcVar10 = (char *)0x0;
                goto joined_r0x0001008c;
              }
            }
          }
        }
      }
LAB_00010104:
    }
    *param_4 = local_a4;
    if (local_70 != 0) {
      FUN_00004100();
    }
    uVar7 = 0;
  }
  return uVar7;
}



void FUN_0001015c(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  uVar3 = param_1[4];
  uVar4 = param_1[6];
  *param_1 = param_1[3];
  param_1[3] = uVar1;
  param_1[1] = param_1[2];
  param_1[2] = uVar2;
  param_1[4] = param_1[5];
  param_1[5] = uVar3;
  param_1[6] = param_1[7];
  param_1[7] = uVar4;
  return;
}



longlong FUN_000101a0(byte *param_1,longlong param_2,longlong *param_3,ulonglong param_4)

{
  byte bVar1;
  byte *pbVar2;
  longlong lVar3;
  longlong *plVar4;
  char cVar5;
  uint uVar6;
  byte *pbVar7;
  
  lVar3 = 0;
  if ((((param_1 != (byte *)0x0) && (param_2 != 0)) && (param_3 != (longlong *)0x0)) &&
     (param_4 != 0)) {
    FUN_00004788(param_3,param_4,0);
    lVar3 = 0;
    plVar4 = param_3;
    if (param_1 != (byte *)0x0) {
      do {
        while( true ) {
          if (param_2 == 0) {
            return lVar3;
          }
          if (param_4 == 0) {
            return lVar3;
          }
          if (plVar4 == (longlong *)0x0) {
            return lVar3;
          }
          bVar1 = *param_1;
          if ((bVar1 != 9) && (bVar1 != 0x20)) break;
          param_1 = param_1 + 1;
          param_2 = param_2 + -1;
          if (param_1 == (byte *)0x0) {
            return lVar3;
          }
        }
        uVar6 = (uint)bVar1;
        if (uVar6 == 0) {
          return lVar3;
        }
        pbVar2 = param_1;
        if (uVar6 - 0x30 < 10) {
          cVar5 = bVar1 - 0x30;
        }
        else if (uVar6 - 0x61 < 6) {
          cVar5 = bVar1 + 0xa9;
        }
        else if (uVar6 - 0x41 < 6) {
          cVar5 = bVar1 - 0x37;
        }
        else {
          cVar5 = '\0';
          param_1 = param_1 + 1;
          param_2 = param_2 + -1;
          pbVar2 = param_1;
        }
        do {
          pbVar7 = param_1;
          if (((param_1 == (byte *)0x0) || (param_2 == 0)) || (pbVar7 = pbVar2, *pbVar2 == 0))
          break;
          bVar1 = pbVar2[1];
          param_1 = param_1 + 1;
          param_2 = param_2 + -1;
          pbVar2 = pbVar2 + 1;
          pbVar7 = param_1;
        } while (bVar1 == 0x20 || bVar1 == 9);
        if ((pbVar7 == (byte *)0x0) || (param_2 == 0)) {
LAB_00010334:
          *(char *)((longlong)param_3 + lVar3) = cVar5;
          return lVar3 + 1;
        }
        bVar1 = *pbVar7;
        if (bVar1 == 0) goto LAB_00010334;
        cVar5 = cVar5 * '\x10';
        if (bVar1 - 0x30 < 10) {
          cVar5 = cVar5 + bVar1 + -0x30;
        }
        else if (bVar1 - 0x61 < 6) {
          cVar5 = cVar5 + bVar1 + -0x57;
        }
        else if (bVar1 - 0x41 < 6) {
          cVar5 = cVar5 + bVar1 + -0x37;
        }
        else {
          pbVar7 = pbVar7 + 1;
          *(char *)((longlong)param_3 + lVar3) = cVar5;
          param_2 = param_2 + -1;
        }
        param_2 = param_2 + -1;
        *(char *)((longlong)param_3 + lVar3) = cVar5;
        param_4 = param_4 - 1;
        param_1 = pbVar7 + 1;
        plVar4 = (longlong *)((longlong)plVar4 + 1);
        lVar3 = lVar3 + 1;
      } while (param_1 != (byte *)0x0);
    }
  }
  return lVar3;
}



longlong FUN_0001034c(ushort *param_1,undefined8 *param_2,undefined8 *param_3)

{
  bool bVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  ulonglong uVar5;
  undefined1 auStack_bc [4];
  undefined8 local_b8;
  ushort *local_b0;
  undefined1 auStack_a4 [4];
  undefined8 *local_a0;
  longlong local_98;
  undefined1 local_8c [4];
  ulonglong local_88;
  longlong local_80;
  undefined1 auStack_78 [16];
  longlong local_68;
  
  lVar4 = -0x7ffffffffffffffe;
  local_68 = _data;
  local_80 = 0;
  local_a0 = (undefined8 *)0x0;
  local_98 = 0;
  local_b0 = (ushort *)0x0;
  if (((param_1 != (ushort *)0x0) && (param_2 != (undefined8 *)0x0)) &&
     (param_3 != (undefined8 *)0x0)) {
    uVar2 = FUN_00004c80((short *)param_1);
    lVar4 = (**(code **)(DAT_00017260 + 0x138))(2,&DAT_00016288,0,&local_88,&local_80);
    bVar1 = false;
    if ((-1 < lVar4) && (local_80 != 0)) {
      for (uVar5 = 0; uVar5 < local_88; uVar5 = uVar5 + 1) {
        lVar4 = (**(code **)(DAT_00017260 + 0x98))
                          (*(undefined8 *)(local_80 + uVar5 * 8),&DAT_00016288,&local_98);
        if (-1 < lVar4) {
          lVar4 = (**(code **)(DAT_00017260 + 0x40))(4,*(undefined4 *)(local_98 + 0x30),&local_a0);
          if (lVar4 < 0) break;
          FUN_00004728(local_a0,(undefined1 *)(ulonglong)*(uint *)(local_98 + 0x30));
          local_8c[0] = 2;
          while (lVar3 = (**(code **)(local_98 + 0x28))
                                   (local_98,local_a0,local_8c,auStack_78,auStack_a4,&local_b8),
                -1 < lVar3) {
            local_b8 = 0;
            local_b0 = (ushort *)0x0;
            lVar4 = (**(code **)(local_98 + 0x18))
                              (local_98,auStack_78,0x15,0,&local_b0,&local_b8,auStack_bc);
            if (-1 < lVar4) {
              lVar3 = FUN_00004dc4(param_1,local_b0,uVar2);
              if (lVar3 == 0) {
                *param_2 = 0;
                *param_3 = 0;
                lVar4 = (**(code **)(local_98 + 0x18))
                                  (local_98,auStack_78,0x19,0,param_2,param_3,auStack_bc);
                bVar1 = true;
                goto LAB_00010538;
              }
              (**(code **)(DAT_00017260 + 0x48))(local_b0);
              local_b0 = (ushort *)0x0;
            }
          }
          (**(code **)(DAT_00017260 + 0x48))(local_a0);
          local_a0 = (undefined8 *)0x0;
        }
      }
      bVar1 = false;
    }
LAB_00010538:
    if (local_b0 != (ushort *)0x0) {
      (**(code **)(DAT_00017260 + 0x48))();
      local_b0 = (ushort *)0x0;
    }
    if (local_a0 != (undefined8 *)0x0) {
      (**(code **)(DAT_00017260 + 0x48))();
      local_a0 = (undefined8 *)0x0;
    }
    if (local_80 != 0) {
      (**(code **)(DAT_00017260 + 0x48))();
      local_80 = 0;
    }
    lVar3 = -0x7ffffffffffffff2;
    if (bVar1) {
      lVar3 = 0;
    }
    if (-1 < lVar4) {
      lVar4 = lVar3;
    }
  }
  if (_data != local_68) {
                    // WARNING: Subroutine does not return
    FUN_000010d8();
  }
  return lVar4;
}



longlong FUN_000105d0(void)

{
  longlong lVar1;
  
  lVar1 = FUN_00005f9c((longlong *)&DAT_00016118);
  if (lVar1 != 0) {
    lVar1 = *(longlong *)(lVar1 + 0x18);
  }
  return lVar1;
}



ulonglong FUN_000105f4(undefined8 *param_1,ulonglong param_2,undefined8 *param_3,ulonglong param_4)

{
  if (param_2 < param_4) {
    FUN_000047cc(param_1,param_3,param_2);
  }
  else {
    FUN_000047cc(param_1,param_3,param_4);
    param_2 = param_4;
  }
  return param_2;
}



bool FUN_0001063c(void)

{
  longlong lVar1;
  uint local_14;
  
  local_14 = 0x7fffffff;
  lVar1 = FUN_000043c4(&local_14);
  if (lVar1 != 0) {
    FUN_00004548(0x80000000,(byte *)"ERROR: Failed to Get Shared Imem Boot Device type \n");
  }
  return local_14 == 1 || local_14 == 6;
}



bool thunk_FUN_0001063c(void)

{
  longlong lVar1;
  uint uStack_14;
  
  uStack_14 = 0x7fffffff;
  lVar1 = FUN_000043c4(&uStack_14);
  if (lVar1 != 0) {
    FUN_00004548(0x80000000,(byte *)"ERROR: Failed to Get Shared Imem Boot Device type \n");
  }
  return uStack_14 == 1 || uStack_14 == 6;
}



undefined4 FUN_00010698(undefined4 *param_1,undefined4 param_2)

{
  if (((ulonglong)param_1 & 3) != 0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  *param_1 = param_2;
  return param_2;
}



bool FUN_000106d8(longlong *param_1,undefined8 *param_2)

{
  bool bVar1;
  
  if (param_1 == (longlong *)0x0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  if (param_2 != (undefined8 *)0x0) {
    bVar1 = FUN_000108e0(param_1,param_2);
    return bVar1;
  }
  FUN_0000464c();
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



longlong FUN_00010728(ulonglong *param_1,ulonglong *param_2,ulonglong param_3)

{
  ulonglong uVar1;
  bool bVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  
  if ((param_1 == param_2) || (param_3 == 0)) {
    return 0;
  }
  if (param_1 == (ulonglong *)0x0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  if (param_2 == (ulonglong *)0x0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  if (~(ulonglong)param_1 < param_3 - 1) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  if (~(ulonglong)param_2 < param_3 - 1) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  if ((((ulonglong)param_1 ^ (ulonglong)param_2) & 7) != 0) {
    lVar3 = param_3 - 1;
    do {
      uVar7 = *param_1;
      uVar4 = *param_2;
      bVar2 = lVar3 != 0;
      lVar3 = lVar3 + -1;
      param_1 = (ulonglong *)((longlong)param_1 + 1);
      param_2 = (ulonglong *)((longlong)param_2 + 1);
    } while (bVar2 && (byte)uVar7 == (byte)uVar4);
    return (ulonglong)(byte)uVar7 - (ulonglong)(byte)uVar4;
  }
  uVar7 = (ulonglong)param_1 & 7;
  if (uVar7 == 0) {
    uVar7 = param_3 + 7 >> 3;
    do {
      uVar4 = *param_1;
      uVar5 = *param_2;
LAB_00010824:
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
      uVar7 = uVar7 - 1;
      uVar6 = uVar4 ^ uVar5;
      uVar1 = uVar6;
      if (uVar7 == 0) {
        uVar1 = 0xffffffffffffffff;
      }
    } while (uVar1 == 0);
    if ((uVar7 == 0) && ((param_3 & 7) != 0)) {
      uVar7 = -1L << ((param_3 & 7) << 3);
      uVar4 = uVar4 & (uVar7 ^ 0xffffffffffffffff);
      uVar5 = uVar5 & (uVar7 ^ 0xffffffffffffffff);
      uVar6 = uVar6 | uVar7;
    }
    uVar7 = (uVar6 & 0xff00ff00ff00ff00) >> 8 | (uVar6 & 0xff00ff00ff00ff) << 8;
    uVar7 = (uVar7 & 0xffff0000ffff0000) >> 0x10 | (uVar7 & 0xffff0000ffff) << 0x10;
    uVar4 = (uVar4 & 0xff00ff00ff00ff00) >> 8 | (uVar4 & 0xff00ff00ff00ff) << 8;
    uVar4 = (uVar4 & 0xffff0000ffff0000) >> 0x10 | (uVar4 & 0xffff0000ffff) << 0x10;
    uVar5 = (uVar5 & 0xff00ff00ff00ff00) >> 8 | (uVar5 & 0xff00ff00ff00ff) << 8;
    uVar5 = (uVar5 & 0xffff0000ffff0000) >> 0x10 | (uVar5 & 0xffff0000ffff) << 0x10;
    uVar7 = LZCOUNT(uVar7 >> 0x20 | uVar7 << 0x20);
    return (((uVar4 >> 0x20 | uVar4 << 0x20) << (uVar7 & 0x3f)) >> 0x38) -
           (((uVar5 >> 0x20 | uVar5 << 0x20) << (uVar7 & 0x3f)) >> 0x38);
  }
  param_1 = (ulonglong *)((ulonglong)param_1 & 0xfffffffffffffff8);
  param_2 = (ulonglong *)((ulonglong)param_2 & 0xfffffffffffffff8);
  param_3 = param_3 + uVar7;
  uVar5 = 0xffffffffffffffff >> (uVar7 * -8 & 0x3f);
  uVar4 = *param_1 | uVar5;
  uVar5 = *param_2 | uVar5;
  uVar7 = param_3 + 7 >> 3;
  goto LAB_00010824;
}



bool FUN_000108e0(longlong *param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  longlong lVar2;
  
  lVar2 = 0;
  puVar1 = param_2;
  if (param_2 != (undefined8 *)0x0) {
    puVar1 = (undefined8 *)*param_2;
    lVar2 = param_2[1];
  }
  return puVar1 == (undefined8 *)*param_1 && lVar2 == param_1[1];
}



void FUN_00010900(ulonglong param_1,uint param_2,int *param_3)

{
  if (param_2 != 0) {
    FUN_0000545c(param_1,param_2,param_3);
    return;
  }
  FUN_0000464c();
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Removing unreachable block (ram,0x000109d4)

bool FUN_00010930(longlong *param_1)

{
  longlong *plVar1;
  ulonglong uVar2;
  
  if (param_1 == (longlong *)0x0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  plVar1 = (longlong *)*param_1;
  if (plVar1 == (longlong *)0x0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  if (param_1[1] == 0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  uVar2 = 1;
  for (; plVar1 != param_1 && uVar2 < 1000000; plVar1 = (longlong *)*plVar1) {
    uVar2 = uVar2 + 1;
  }
  return uVar2 < 1000000;
}



bool FUN_000109e0(longlong *param_1)

{
  bool bVar1;
  
  bVar1 = FUN_00010930(param_1);
  if (bVar1) {
    return (longlong *)*param_1 == param_1;
  }
  FUN_0000464c();
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



longlong FUN_00010a30(longlong *param_1)

{
  bool bVar1;
  
  bVar1 = FUN_000109e0(param_1);
  if (bVar1) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  *(longlong *)(*param_1 + 8) = param_1[1];
  *(longlong *)param_1[1] = *param_1;
  return *param_1;
}



undefined2 FUN_00010a88(undefined2 *param_1)

{
  if (param_1 != (undefined2 *)0x0) {
    return *param_1;
  }
  FUN_0000464c();
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



undefined4 FUN_00010adc(undefined2 *param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  if (param_1 != (undefined2 *)0x0) {
    uVar1 = FUN_00010a88(param_1);
    uVar2 = FUN_00010a88(param_1 + 1);
    return CONCAT22(uVar2,uVar1);
  }
  FUN_0000464c();
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



bool FUN_00010b34(char *param_1)

{
  if (param_1 == (char *)0x0) {
    FUN_0000464c();
    do {
                    // WARNING: Do nothing block with infinite loop
    } while( true );
  }
  if (*param_1 == '\x7f') {
    return param_1[1] == -1;
  }
  return false;
}



undefined2 FUN_00010b84(longlong param_1)

{
  undefined2 uVar1;
  
  if (param_1 != 0) {
    uVar1 = FUN_00010a88((undefined2 *)(param_1 + 2));
    return uVar1;
  }
  FUN_0000464c();
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



longlong FUN_00010bc0(longlong param_1)

{
  ushort uVar1;
  
  if (param_1 != 0) {
    uVar1 = FUN_00010b84(param_1);
    return param_1 + (ulonglong)uVar1;
  }
  FUN_0000464c();
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



undefined8 thunk_FUN_00011370(void)

{
  undefined8 uVar1;
  
  uVar1 = cntfrq_el0;
  return uVar1;
}



void FUN_00010c0c(uint param_1)

{
  if (DAT_00018430 != (int *)0x0) {
    do {
    } while ((uint)(*DAT_00018430 - *DAT_00018430) <
             (uint)(((ulonglong)DAT_00018428 * (ulonglong)param_1) / 1000000));
  }
  return;
}



ulonglong FUN_00010c50(char *param_1,uint param_2,undefined8 *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  byte *pbVar3;
  
  if ((param_1 != (char *)0x0) && (param_2 != 0)) {
    pbVar3 = (byte *)&DAT_00018494;
    for (uVar2 = 0; uVar2 < 4; uVar2 = uVar2 + 1) {
      if (pbVar3[-0x24] == 0) {
        *(char **)(pbVar3 + -0x54) = param_1;
        *(char **)(pbVar3 + -0x5c) = param_1;
        *(char **)(pbVar3 + -0x4c) = param_1 + param_2;
        pbVar3[-0x24] = 1;
        lVar1 = FUN_00004090(IMAGE_DOS_HEADER_00000000.e_program + 0x340);
        if (lVar1 == 0) {
          FUN_00010dbc(uVar2);
          return 0xffffffffffffffff;
        }
        *(longlong *)(pbVar3 + -0xc) = lVar1;
        *(longlong *)(pbVar3 + -0x44) = lVar1;
        *(longlong *)(pbVar3 + -0x34) = lVar1 + 0x200;
        *(longlong *)(pbVar3 + -0x2c) = lVar1 + 0x300;
        pbVar3[-0x1c] = 0;
        pbVar3[-0x1b] = 0;
        pbVar3[-0x1a] = 0;
        pbVar3[-0x19] = 0;
        pbVar3[-0x18] = 0;
        pbVar3[-0x17] = 0;
        pbVar3[-0x16] = 0;
        pbVar3[-0x15] = 0;
        pbVar3[-0x14] = 0;
        pbVar3[-0x13] = 0;
        pbVar3[-0x12] = 0;
        pbVar3[-0x11] = 0;
        pbVar3[-0x10] = 0;
        pbVar3[-0xf] = 0;
        pbVar3[-0xe] = 0;
        pbVar3[-0xd] = 0;
        *(longlong *)(pbVar3 + -0x3c) = lVar1 + 0x100;
        if (param_3 == (undefined8 *)0x0) {
          FUN_00004788((longlong *)(pbVar3 + -4),8,0);
          pbVar3[-4] = 0x23;
          pbVar3[0] = 0xd;
          pbVar3[1] = 0;
          pbVar3[2] = 0;
          pbVar3[3] = 0;
        }
        else {
          FUN_000047cc((undefined8 *)(pbVar3 + -4),param_3,8);
          if ((*pbVar3 & 1) == 0) {
            return uVar2;
          }
        }
        if (*param_1 != -0x11) {
          return uVar2;
        }
        if (param_1[1] != -0x45) {
          return uVar2;
        }
        if (param_1[2] == -0x41) {
          lVar1 = *(longlong *)(pbVar3 + -0x54) + 3;
          if (param_2 < 4) {
            lVar1 = *(longlong *)(pbVar3 + -0x4c);
          }
          *(longlong *)(pbVar3 + -0x54) = lVar1;
          return uVar2;
        }
        return uVar2;
      }
      pbVar3 = pbVar3 + 0x60;
    }
  }
  return 0xffffffffffffffff;
}



void FUN_00010dbc(ulonglong param_1)

{
  if (3 < param_1) {
    return;
  }
  FUN_00004788(&DAT_00018438 + param_1 * 0xc,0x60,0);
  return;
}



byte * FUN_00010de4(longlong param_1)

{
  byte *pbVar1;
  
  pbVar1 = FUN_0001126c(param_1);
  while( true ) {
    if (pbVar1 == (byte *)0x0) {
      return (byte *)0x0;
    }
    if (*(byte **)(param_1 + 0x10) <= pbVar1) break;
    if (*pbVar1 != *(byte *)(param_1 + 0x58)) {
      if (*pbVar1 == 0) {
        return (byte *)0x0;
      }
      return pbVar1;
    }
    pbVar1 = FUN_000112e0(param_1);
  }
  return (byte *)0x0;
}



void FUN_00010e3c(char *param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  
  if (((param_1 != (char *)0x0) && (param_2 != (char *)0x0)) && (param_3 != 0)) {
    pcVar1 = param_2 + 1;
    cVar3 = *param_2;
    do {
      pcVar2 = param_1;
      if (cVar3 == '\0') goto LAB_00010e88;
      param_3 = param_3 + -1;
      *pcVar2 = cVar3;
      cVar3 = *pcVar1;
    } while (((cVar3 != '\r') && (param_3 != 0)) &&
            (pcVar1 = pcVar1 + 1, param_1 = pcVar2 + 1, cVar3 != '\n'));
    if (param_3 != 0) {
      pcVar2 = pcVar2 + 1;
    }
LAB_00010e88:
    *pcVar2 = '\0';
  }
  return;
}



void FUN_00010e90(char *param_1,char *param_2,longlong param_3,longlong *param_4)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  if (((param_1 != (char *)0x0) && (param_2 != (char *)0x0)) && (pcVar2 = param_1, param_3 != 0)) {
    for (; (pcVar3 = pcVar2, param_2 != (char *)0x0 && (param_3 != 0)); param_3 = param_3 + -1) {
      cVar1 = *param_2;
      if ((cVar1 == '\0') || (cVar1 == ']')) goto LAB_00010ed4;
      *pcVar2 = cVar1;
      param_2 = param_2 + 1;
      pcVar2 = pcVar2 + 1;
    }
    pcVar3 = pcVar2 + -1;
    if (param_3 != 0) {
      pcVar3 = pcVar2;
    }
LAB_00010ed4:
    if (param_4 != (longlong *)0x0) {
      *param_4 = (longlong)pcVar3 - (longlong)param_1;
    }
    *pcVar3 = '\0';
  }
  return;
}



void FUN_00010ee8(longlong param_1)

{
  byte *pbVar1;
  
  pbVar1 = FUN_000112e0(param_1);
  if (pbVar1 != (byte *)0x0) {
    FUN_00010de4(param_1);
    return;
  }
  return;
}



undefined8
FUN_00010f1c(ulonglong param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4)

{
  byte *pbVar1;
  char *pcVar2;
  char *pcVar3;
  longlong extraout_x1;
  longlong lVar4;
  undefined1 *puVar5;
  longlong lVar6;
  longlong lStack_58;
  
  if (3 < param_1) {
    return 0xffffffffffffffff;
  }
  pcVar3 = (char *)(&DAT_00018438 + param_1 * 0xc);
  if ((&DAT_00018471)[param_1 * 0x60] == '\0') {
    puVar5 = (undefined1 *)(&DAT_00018450)[param_1 * 0xc];
    (&DAT_00018471)[param_1 * 0x60] = '\x01';
    *puVar5 = 0;
    pbVar1 = FUN_00010de4((longlong)pcVar3);
  }
  else {
    pbVar1 = (byte *)FUN_00010ee8((longlong)pcVar3);
  }
  lVar6 = -1;
  while( true ) {
    if (pbVar1 == (byte *)0x0) {
      return 0xffffffffffffffff;
    }
    if (*pbVar1 == 0) {
      return 0xffffffffffffffff;
    }
    FUN_00010e3c((char *)(&DAT_00018458)[param_1 * 0xc],(char *)(&DAT_00018440)[param_1 * 0xc],0x100
                );
    pcVar2 = (char *)(&DAT_00018458)[param_1 * 0xc];
    if (*pcVar2 != '[') break;
    FUN_00010e90((char *)(&DAT_00018450)[param_1 * 0xc],pcVar2 + 1,0x100,&lStack_58);
    pbVar1 = (byte *)FUN_00010ee8((longlong)pcVar3);
  }
  lVar4 = extraout_x1;
  if (pcVar2 != (char *)0x0) {
    if (*pcVar2 == '=') {
      lVar4 = 0;
      pcVar3 = pcVar2 + 1;
      lVar6 = 0xff;
      pcVar2 = (char *)0x0;
    }
    else {
      lVar6 = 0x100;
      for (lVar4 = 0; (lVar6 != 0 && (pcVar2[lVar4] != '\0')); lVar4 = lVar4 + 1) {
        if (pcVar2[lVar4] == '=') {
          lVar6 = 0xff - lVar4;
          pcVar3 = pcVar2 + lVar4 + 1;
          pcVar2[lVar4] = '\0';
          goto LAB_00011074;
        }
        lVar6 = lVar6 + -1;
      }
      pcVar3 = (char *)0x0;
      lVar6 = 0;
    }
  }
LAB_00011074:
  pcVar2 = FUN_000110bc(pcVar2,lVar4);
  pcVar3 = FUN_000110bc(pcVar3,lVar6);
  *param_3 = pcVar2;
  *param_4 = pcVar3;
  *param_2 = (&DAT_00018450)[param_1 * 0xc];
  return 0;
}



char * FUN_000110bc(char *param_1,longlong param_2)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  char *pcVar4;
  longlong lVar5;
  char *pcVar6;
  
  pcVar4 = (char *)0x0;
  if ((param_1 != (char *)0x0) && (param_2 != 0)) {
    lVar5 = -param_2;
    pcVar4 = param_1;
    for (; (pcVar4 != (char *)0x0 && (param_2 != 0)); param_2 = param_2 + -1) {
      cVar1 = *pcVar4;
      if (cVar1 != ' ' && cVar1 != '\t') goto joined_r0x000110f8;
      pcVar4 = pcVar4 + 1;
      lVar5 = lVar5 + 1;
    }
    if (pcVar4 == (char *)0x0) {
      return (char *)0x0;
    }
    cVar1 = *pcVar4;
joined_r0x000110f8:
    if ((param_2 == 0) || (cVar1 == '\0')) {
      return pcVar4;
    }
    bVar3 = cVar1 == '\"';
    if (bVar3) {
      pcVar4 = pcVar4 + 1;
    }
    pcVar6 = pcVar4;
    for (lVar5 = -lVar5 - (ulonglong)bVar3; (pcVar6 != (char *)0x0 && (lVar5 != 0));
        lVar5 = lVar5 + -1) {
      cVar2 = *pcVar6;
      if (cVar2 == ' ') {
        if (cVar1 != '\"') goto LAB_0001116c;
      }
      else {
        if (cVar2 == '\0') {
          return pcVar4;
        }
        if ((cVar2 == '\"') || (cVar2 == '\t' && !bVar3)) {
LAB_0001116c:
          *pcVar6 = '\0';
          return pcVar4;
        }
      }
      pcVar6 = pcVar6 + 1;
    }
  }
  return pcVar4;
}



undefined8 FUN_0001118c(ulonglong param_1,byte *param_2,undefined *param_3)

{
  byte *pbVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 local_48;
  undefined8 local_40;
  byte *local_38;
  
  local_40 = 0;
  local_38 = (byte *)0x0;
  local_48 = 0;
  uVar2 = 0xffffffffffffffff;
  if ((param_1 < 4) && (param_3 != (undefined *)0x0)) {
    while (lVar3 = FUN_00010f1c(param_1,&local_38,&local_40,&local_48), pbVar1 = local_38,
          lVar3 == 0) {
      if ((param_2 == (byte *)0x0) || (lVar3 = FUN_00004fdc(param_2,local_38), lVar3 == 0)) {
        (*(code *)param_3)(pbVar1,local_40,local_48);
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



undefined8 FUN_0001121c(ulonglong param_1)

{
  undefined8 uVar1;
  
  if (param_1 < 4) {
    FUN_00004100();
    FUN_00010dbc(param_1);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffffffffffff;
  }
  return uVar1;
}



byte * FUN_0001126c(longlong param_1)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pbVar2 = *(byte **)(param_1 + 8);
  do {
    if (pbVar2 == (byte *)0x0) {
      pbVar3 = *(byte **)(param_1 + 0x10);
      *(undefined8 *)(param_1 + 8) = 0;
LAB_000112d0:
      *(byte **)(param_1 + 8) = pbVar3;
      return (byte *)0x0;
    }
    bVar1 = *pbVar2;
    pbVar3 = *(byte **)(param_1 + 0x10);
    if ((((bVar1 == 0) || (pbVar3 <= pbVar2)) || (0x20 < bVar1)) ||
       ((1L << ((ulonglong)bVar1 & 0x3f) & 0x100002600U) == 0)) {
      *(byte **)(param_1 + 8) = pbVar2;
      if ((pbVar2 < pbVar3) && (*pbVar2 != 0)) {
        return pbVar2;
      }
      goto LAB_000112d0;
    }
    pbVar2 = pbVar2 + 1;
  } while( true );
}



byte * FUN_000112e0(longlong param_1)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = *(byte **)(param_1 + 8);
  do {
    if (pbVar2 == (byte *)0x0) {
      *(undefined8 *)(param_1 + 8) = 0;
LAB_00011358:
      *(undefined8 *)(param_1 + 8) = *(undefined8 *)(param_1 + 0x10);
      return (byte *)0x0;
    }
    bVar1 = *pbVar2;
    if ((bVar1 == 0) || (*(byte **)(param_1 + 0x10) <= pbVar2)) {
      *(byte **)(param_1 + 8) = pbVar2;
LAB_00011334:
      if ((pbVar2 < *(byte **)(param_1 + 0x10)) && (*pbVar2 != 0)) {
        return pbVar2;
      }
      goto LAB_00011358;
    }
    if (bVar1 == 10 || bVar1 == 0xd) {
      *(byte **)(param_1 + 8) = pbVar2;
      pbVar2 = FUN_0001126c(param_1);
      *(byte **)(param_1 + 8) = pbVar2;
      if (pbVar2 != (byte *)0x0) goto LAB_00011334;
      goto LAB_00011358;
    }
    pbVar2 = pbVar2 + 1;
  } while( true );
}



undefined8 FUN_00011370(void)

{
  undefined8 uVar1;
  
  uVar1 = cntfrq_el0;
  return uVar1;
}


