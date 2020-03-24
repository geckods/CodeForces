nk =  gets.chomp.split(" ").map(&:to_f)
n = nk[0]
k = nk[1]
red = ((2*n)/k).ceil
green = ((5*n)/k).ceil
blue = ((8*n)/k).ceil

puts red+green+blue
