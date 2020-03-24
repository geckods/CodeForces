n = gets.to_i
str = gets.chomp

newstr = ""


i = 0
(1..n).each do |x|
  newstr += str[i]
  i += x
  break if i>=str.length
end

puts newstr
