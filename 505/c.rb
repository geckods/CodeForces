str = gets.chomp
len = str.length

def change(str,ind)
  return str[0..ind].reverse+str[ind+1..-1].reverse
end

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

max = score1(str,len)
(0..len-2).each do |changeind|
  newscore = score1(change(str,changeind),len)
  if newscore>max
    max = newscore
  end
end

puts max
