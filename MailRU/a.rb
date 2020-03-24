xyzts = gets.chomp.split(" ").map(&:to_i)

x = xyzts[0]
y = xyzts[1]
z = xyzts[2]
t1 = xyzts[3]
t2 = xyzts[4]
t3 = xyzts[5]

st = (x-y).abs*t1
et = (x-z).abs*t2 + 3*t3 + (x-y).abs*t2

if et<=st
  puts "YES"
else
  puts "NO"
end
