str1 = gets.chomp
str2 = gets.chomp

a = 0

while str1[-a-1] == str2[-a-1]
  a+=1
end

puts str1.length+str2.length-2*a
