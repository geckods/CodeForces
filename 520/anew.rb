n = gets.to_i
arr = gets.chomp.split(" ").map(&:to_i)

newarr = []

prev = [-1]

arr.each do |x|
  if x != prev.max+1
    newarr.push prev
    prev = [x]
  else
    prev.push x
  end
end
newarr.push prev
countarr = [0]

newarr.each do |z|
  len =  z.length
  next if len == 1

  if z.include?(1) or z.include?(1000)
    countarr.push len-1
  else
    countarr.push len-2
  end
end

#p newarr
puts countarr.max
