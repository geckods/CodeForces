n = gets.to_i
str1 = gets.chomp
str2 = gets.chomp

#require 'Set'

count = 0

(0..(n/2)-1).each do |i|
  set = [str1[i],str2[i],str1[n-i-1],str2[n-i-1]]
  len = set.uniq.length

  if len == 2
    if set.count(set[0]) != 2
      count += 1
    end
  elsif len == 3
    count += 1
    if set[0] == set[2]
      count += 1
    end
  elsif len == 4
    count += 2
  end
end

if n%2==1
  if str1[n/2]!=str2[n/2]
    count += 1
  end
end

puts count
