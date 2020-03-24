n = gets.to_i
arr = gets.chomp.split(" ").map(&:to_i)

puts n+1

def getdiff(elem,n,modn)
  k = elem/n
  req = k*n + modn
  if req<elem
    req += n
  end

  return req-elem
end


i = n-1
while(i>=0)
  toadd = getdiff(arr[i],n,i)
  j = 0
  while(j<=i)
    arr[j]+= toadd
    j = j+1
  end
  puts "1 #{i+1} #{toadd}"
  i = i-1
end

puts "2 #{n} #{n}"

=begin
(0..n-1).each do |i|
   arr[i] = arr[i]%n
end
p arr
=end
