nk = gets.chomp.split(" ").map(&:to_i)
str = gets.chomp
k = nk[1]

def splitof(str)
  a = str.length-2
  while a >=0
    break if str[0..a]==str[-1-a..-1]
    a-=1
  end

  if a==-1
    return [str,""]
  else 
    return [str[0..-2-a],str[-1-a..-1]]
  end
end

asd = splitof(str)
#p asd
k.times do
  print(asd[0])
end

print(asd[1])
puts
