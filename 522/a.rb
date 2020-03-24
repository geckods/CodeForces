nk = gets.chomp.split(" ")
n = nk[0].to_i
k = nk[1].to_i
arr = gets.chomp.split(" ").map(&:to_i)

hash = Hash.new(0)

uniqarr = arr.uniq
arr.each do |elem|
  hash[elem]+=1
end

max = hash.values.max
dishno = (max.to_f/k).ceil

count = 0

#every set of utensils is the same

hash.values.each do |z|
  count+= k*dishno-z
end

puts count

