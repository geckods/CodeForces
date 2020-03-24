nq = gets.chomp.split(" ").map(&:to_i)
n = nq[0]
q = nq[1]
qarr = []
treearr = gets.chomp.split(" ").map(&:to_i)
q.times {qarr.push gets.chomp.split(" ").map(&:to_i)}

hash = Hash.new([])

treearr.each_with_index do |x,i|
  hash[x] += [i+2]
end
#p treearr
p hash

def generateseq(hash,x,i)
  if i == 1
    return x
  end

  hash[x].each do |ch|
    co = childcount(hash,ch)
    if co>i
      i-=co
    else
      return generateseq(hash,ch,i-1)
    end
  end
  x
end

def childcount(hash,x)
  childno = 1
  hash[x].each do |child|
    childno += childcount(hash,child)
  end
  return childno
end


qarr.each do |x|
  u = x[0]
  k = x[1]
  #$ans = -1
  puts generateseq(hash,u,k)
  #puts $ans
end
