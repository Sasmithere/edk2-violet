
f = open("adb_dump.txt","r")
read = f.readlines()
out = open("extract.txt","w+")
for i in read:
    if "[NVT-ts]" in i:
        out.write(i)

