require 'set'

n = gets.to_i

arr = []

min = 1.0/0.0
minpair = []
n.times do 
  xy = gets.chomp.split(" ").map(&:to_i)
  if min>xy[0]+xy[1]
    min = xy[0]+xy[1]
    minpair = xy
  end
  arr.push xy
end

def factorize(n)
  ans = [n]
  (2..n**0.5).each do |x|
    if n%x==0
      ans.push x
      ans.push n/x
    end
  end

  return ans
end
#p minpair
initfactors = Set.new(factorize(minpair[0])+factorize(minpair[1]))
#p arr
arr.each do |ab|
  #p ab
  initfactors.each do |factor|
    unless (ab[0]%factor==0 or ab[1]%factor==0)
      initfactors.delete(factor)
    end
  end
end

if initfactors.empty?
  puts -1
else
  initfactors.each do |f|
    puts f
    exit
  end
end
