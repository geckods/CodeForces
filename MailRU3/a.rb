n = gets.to_i
stops = []
arr = gets.chomp.split(" ").map(&:to_i)
arr.shift
(n-1).times do
  newarr = (gets.chomp.split(" ").map(&:to_i))
  newarr.shift
  arr = arr&newarr
end

arr.each do |x|
  print "#{x} "
end

puts
