nla = gets.chomp.split(" ").map(&:to_i)

n = nla[0]
l = nla[1]
a = nla[2]

arr = []
n.times do
  arr.push gets.chomp.split(" ").map(&:to_i)
end

arr.sort_by{|x| x[0]}

if n==0
  puts l/a
  exit
end

first = arr[0][0]/a
last = (l-(arr[n-1][0]+arr[n-1][1]))/a

ans = 0

arr.each_with_index do |x,i|
  next if i==n-1
  ans += (arr[i+1][0]-(x[0]+x[1]))/a
end

ans += (first+last)
puts ans
