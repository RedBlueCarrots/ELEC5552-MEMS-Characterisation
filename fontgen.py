from PIL import Image, ImageDraw, ImageFont

width, height = 16, 32
# Create a 1-bit canvas (0 = background/off)
font = ImageFont.truetype("DejaVuSansMono.ttf", size=24)
f = open("font_lookup.h", "w")
for i in range(128):
    img = Image.new("1", (width, height), 0)
    draw = ImageDraw.Draw(img)

    # Render character
    draw.text((0, -2), chr(max(32, i)), fill=1, font=font)

    # Convert pixels to 1D byte list (0x00 for ON, 0xFF for OFF)
    pixels = img.load()
    if i == 109:
        img.show()
    byte_array = [0x00 if pixels[x, y] else 0xFF for y in range(height) for x in range(width)]

    # Print C array output
    f.write(f"const byte font_{i}_{width}x{height}[{len(byte_array)}] = {{\n")
    for r in range(height):
        row_bytes = byte_array[r * width : (r + 1) * width]
        f.write("    " + ", ".join(f"0x{b:02X}" for b in row_bytes) + ",\n")
    f.write("};\n\n")

f.write("const byte* font[128] = {")
for i in range(128):
    f.write(f"font_{i}_{width}x{height}")
    f.write(",")
f.write("};")
f.close()