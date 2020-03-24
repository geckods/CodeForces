nk = gets.chomp.split(" ").map(&:to_i)
n = nk[0]
k = nk[1]

n = n.to_s(2)

mink = n.count("1")
maxk = 0
len = n.length

n.each_char.with_index do |ch,i|
  pos = len-i-1
  maxk += 2**pos if ch == "1"
end

if k < mink or k > maxk
  puts "NO"
  exit
end

def myprint(narr,k)
  sum = narr.inject(:+)
  while sum < k
    narr[0] -= 1
    narr[1] += 2
    sum += 1
    if narr[0] == 0
      narr.shift
    end
  end

  len = narr.length
  narr.each_with_index do |x,i|
    x.times do
      print 2**(len-i-1)
      print " "
    end
  end
end

puts "YES"
myprint(n.each_char.to_a.map(&:to_i),k)
puts
