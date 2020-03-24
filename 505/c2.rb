str = gets.chomp
len = str.length


fromleftarr = []
count = 0
prevch = ''
str.each_char.with_index do |ch,i|
  if ch!=prevch
    count+=1
  else
    count = 1
  end
  prevch = ch
  fromleftarr.push count
end


fromrightarr = []
count = 0
prevch = ''
str.reverse.each_char.with_index do |ch,i|
  if ch!=prevch
    count+=1
  else
    count = 1
  end
  prevch = ch
  fromrightarr.push count
end

#fromrightarr.reverse!

fromrightarr.reverse!

def score1(str,len)
  maxcount = 1
  count = 0
  prevch = ''
  str.each_char do |ch|
    if ch!=prevch
      count+=1
    else
      maxcount = count if count > maxcount
      count = 1
    end
    prevch = ch
  end

  maxcount = count if count>maxcount

  return maxcount
end

if str[0]==str[-1]
  puts score1(str,len)
else
  puts fromleftarr[-1]+fromrightarr[0]
end

=begin
max = 0
(0..len-2).each do |i|
  curr = fromrightarr[0]-fromrightarr[i]+fromleftarr[-1]-fromleftarr[i+1]
  max = curr if curr > max
end
#=end

puts max
=end
