#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Mar 21 10:41:16 2021

@author: jihongsayo
"""

from PIL import Image

def write_image(image, filename):
    height = image.height
    width = image.width

    f = open(filename, "wb")

    f.write(height.to_bytes(2, byteorder='big'))
    f.write(width.to_bytes(2, byteorder='big'))
    img_raster = []
    for i in range(height):
        for j in range(width):
            img_raster.extend(image.getpixel((j, i)))

    f.write(bytearray(img_raster))
    f.close()

def read_2bytes(f):
    bytes = f.read(2) # [int(f.read(1)), int(f.read(1))]
    return int.from_bytes(bytes, byteorder = 'big')


def read_image(filename):
    f = open(filename, "rb")
    height = read_2bytes(f)
    width = read_2bytes(f)
    image = Image.new("RGB", (width, height))
    bytes = f.read()
    for i in range(height):
        for j in range(width):
            image.putpixel((j, i), (bytes[3*(i*width + j)+0],
                                    bytes[3*(i*width + j)+1],
                                    bytes[3*(i*width + j)+2]))

    return image

def read_image_to_brightness(filename, fac):
    f = open(filename, "rb")
    height = read_2bytes(f)
    width = read_2bytes(f)
    image = Image.new("RGB", (width, height))
    bytes = f.read()
    for i in range(height):
        for j in range(width):
            image.putpixel((j, i), (min(int(bytes[3*(i*width + j)+0]*fac), 255),
                                    min(int(bytes[3*(i*width + j)+1]*fac), 255),
                                    min(int(bytes[3*(i*width + j)+2]*fac), 255)))

    return image

#Write a png image to bin
image = Image.open("/Users/jihongsayo/Documents/u_of_t_president.jpeg")
write_image(image, "/Users/jihongsayo/Documents/u_of_t_president.bin")
#image = Image.open("3x4.png")
#write_image(image, "3x4.bin")

#Read image from a bin file, save it to png
im2 = read_image("/Users/jihongsayo/Documents/u_of_t_president.bin")
im2.save("/Users/jihongsayo/Documents/u_of_t_president_hojicha.png")
#im3 = read_image("6x5_grad.bin")
#im3.save("grad.png")

# Write multiple images from bin to png
'''
for i in range(200):
    image = read_image("img%d.bin" % i)
    image.save("img%d.png" % i)
'''
'''
THIS IS FOR THE LAB
#To get multiple-brightness photos:
for i in range(6):
    image = read_image_to_brightness("/Users/jihongsayo/Documents/u_of_t_president.bin", i/2.5)
    image.save("/Users/jihongsayo/Documents/missing_my_cha_tra_mue%d.png" % i)
   
'''    
   
#Time to find the min-energy seam
energies = [[24,      22,      30,      15,      18,      19],
            [12,      23,      15,      23,      10,     15],
            [11,      13,      22,      13,      21,      14],
            [13,      15,      17,      28,      19,      21],
            [17,      17,      7,       27,      20,      19]]

def min_seam_energy(x, y, energy_list):
    if y == 0:
        return energy_list[0][x]
    if x == 0:
        return energy_list[y][x] + min(min_seam_energy(x+1, y - 1, energy_list), min_seam_energy(x, y - 1, energy_list))
    if x == 5:
        return energy_list[y][x] + min(min_seam_energy(x -1, y -1, energy_list), min_seam_energy(x, y - 1, energy_list))
    return energy_list[y][x] + min(min_seam_energy(x-1, y -1, energy_list), min_seam_energy(x, y - 1, energy_list), min_seam_energy(x+1, y -1, energy_list))
   
print(min_seam_energy(2, 4, energies))

true_min = 10000000
for i in range(6):
    if min_seam_energy(i, 4, energies) < true_min:
        true_min = min_seam_energy(i, 4, energies)
print(true_min)
    