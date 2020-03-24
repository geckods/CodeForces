n = gets.to_i
a = gets.chomp
b = gets.chomp

azerocount = 0
bzerocount = 0

b.each_char.with_index do |c,i|
  if c=="0"
    if a[i] == "0"
      azerocount+=1
    end
    bzerocount += 1
  end
end

aone = a.count('1')

#p azerocount
#p bzerocount
#p aone
puts azerocount*aone+(bzerocount-azerocount)*(n-aone-azerocount)
