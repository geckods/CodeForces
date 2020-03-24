str = gets.chomp

newstr = ""

len = str.length
while len > 0
  if len%2==0
    newstr = str[-1] + newstr
    str = str[0..-2]
  else
    newstr = str[0] + newstr
    str = str[1..-1]
  end
  len -= 1
end

puts newstr
