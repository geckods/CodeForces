n = gets.to_i
m = gets.to_i

arr = []
n.times {arr.push gets.to_i}

max = arr.max
sum = arr.inject(:+)

if n==1
   print "#{arr[0]+m} #{arr[0]+m}\n"
   exit
end


if max*n>(m+sum)
  print "#{max} "
else
  ans = max+(m-(max*n-sum))/n
  ans += 1 unless (m-(max*n-sum))%n==0
  printf "#{ans} "
end

puts arr.max+m
