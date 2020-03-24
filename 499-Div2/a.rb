nk = gets.chomp.split(" ").map(&:to_i)
n = nk[0]
k = nk[1]

string = gets.chomp

arr = string.each_char.to_a.uniq.sort

if k > 26
  puts -1
  exit
end

weight = 0
i = 0
prevch = 'A'

def addto(char,no)
  return (char.ord+no).chr
end


len = arr.length
while k>0
  if i>=len
    puts -1
    exit
  end

  ch = arr[i]
  if ch<=addto(prevch,1)
    i+=1
    next
  end

  #p ch
  weight += ch.ord-'a'.ord+1
  k-=1
  i+=1
  prevch = ch
end

puts weight
