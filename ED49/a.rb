def palindrome(x)
  return x==x.reverse
end

t = gets.to_i

larr = []
arr = []

t.times do
  larr.push gets.to_i
  arr.push gets.to_s
end

t.times do |i|
  num = larr[i]
  string = arr[i]

#  if palindrome(string)
#    puts "YES"
#    next
#  end
  f = false

  (0..num/2-1).each do |c|
    asdf = (string[c].ord-string[num-c-1].ord).abs
    if !(asdf == 0 or asdf == 2)
#      puts (string[c].ord-string[num-c-1].ord).abs
      puts "NO"
      f = true
      break
    end
  end

  next if f

  puts "YES"
end
